/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

		https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "TaskDetailDAO.h"
#include "TaskDetailMapper.h"
#include <sstream>
#include "id/SnowFlake.h"

int TaskDetailDAO::insert_r_repair_user(const TaskDetailDO& iObj)
{
    // 1. 查 r_repair_pool
    string sqlPool = "SELECT repair_type, community_id FROM r_repair_pool WHERE repair_id=? AND status_cd='0'";
    RepairPoolMapper repairPoolMapper;
    auto pool = sqlSession->executeQueryOne<TaskDetailDO>(sqlPool, repairPoolMapper, "%s", iObj.getRepairId());
    if (pool.getRepairType().empty() || pool.getCommunityId().empty()) return -1;

    string repair_type = pool.getRepairType();
    string community_id = pool.getCommunityId();

    // 2. 查 r_repair_type_user
    string sqlTypeUser = "SELECT staff_id, staff_name FROM r_repair_type_user WHERE repair_type=? AND staff_name=? AND status_cd='0'";
    RepairTypeUserMapper repairTypeUserMapper;
    auto type_user = sqlSession->executeQueryOne<TaskDetailDO>(sqlTypeUser, repairTypeUserMapper, "%s%s", repair_type, iObj.getStaffName());
    if (type_user.getStaffId().empty() || type_user.getStaffName().empty()) return -1;

    string staff_id = type_user.getStaffId();
    string staff_name = type_user.getStaffName();

    // 3. 查 r_repair_user 上一节点
    string sqlPreUser = "SELECT ru_id, staff_id, staff_name FROM r_repair_user WHERE repair_id=? AND status_cd='0'";
    RepairUserMapper preUserMapper;
    auto pre_user = sqlSession->executeQueryOne<TaskDetailDO>(sqlPreUser, preUserMapper, "%s", iObj.getRepairId());
    if (pre_user.getRuId().empty() || pre_user.getStaffId().empty() || pre_user.getStaffName().empty()) return -1;

    string pre_ru_id = pre_user.getRuId();
    string pre_staff_id = pre_user.getStaffId();
    string pre_staff_name = pre_user.getStaffName();

    // 4. 插入第一条
    string sql1 = "INSERT INTO r_repair_user (ru_id, repair_id, b_id, community_id, create_time, state, context, status_cd, staff_id, staff_name, pre_staff_id, pre_staff_name, start_time, end_time, repair_event, pre_ru_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    int ret1 = sqlSession->executeUpdate(sql1, "%s%s%s%s%s%cs%s%cs%s%s%s%s%s%s%cs%s",
        iObj.getRuId(), iObj.getRepairId(), iObj.getBId(), community_id,
        iObj.getCreateTime(), "10006", iObj.getContext(), "0",
        pre_staff_id, pre_staff_name, pre_staff_id, pre_staff_name,
        iObj.getCreateTime(), iObj.getCreateTime(), "auditUser", pre_ru_id);

    if (ret1 == 1)
    {
        // 5. 插入第二条
        string new_ru_id = "83" + std::to_string(SnowFlake(1, 1).nextId() % 10000000000000000);
        string new_b_id = std::to_string(SnowFlake(1, 1).nextId() % 1000000000000000000);
        string sql2 = "INSERT INTO r_repair_user (ru_id, repair_id, b_id, community_id, create_time, state, context, status_cd, staff_id, staff_name, pre_staff_id, pre_staff_name, start_time, repair_event, pre_ru_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

        int ret2 = sqlSession->executeUpdate(sql2, "%s%s%s%s%s%cs%cs%cs%s%s%s%s%s%cs%s",
            new_ru_id, iObj.getRepairId(), new_b_id, community_id,
            iObj.getCreateTime(), "10001", "", "0",
            staff_id, staff_name, pre_staff_id, pre_staff_name,
            iObj.getCreateTime(), "auditUser", iObj.getRuId());

        if (ret2 == 1)
        {
            // 6. 更新r_repair_pool数据为接单
            string sql = "UPDATE r_repair_pool SET state = '1100' WHERE repair_id = ? ";
            return sqlSession->executeUpdate(sql, "%s", iObj.getRepairId());
        }
    }
    return 0;
}


PtrTaskDetailDO TaskDetailDAO::selectExportTaskDetail_r_repair_pool(const TaskDetailQuery::Wrapper& query)
{
    string sql = R"(
        SELECT
            pool.repair_id,
            pool.repair_name,
            pool.tel,
            pool.repair_obj_name,
            pool.context,
            setting.repair_type_name,
            dict.name AS maintenance_type_name
        FROM
            r_repair_pool pool
        LEFT JOIN r_repair_setting setting
            ON pool.repair_type = setting.repair_type
        LEFT JOIN t_dict dict
            ON dict.table_columns = 'maintenance_type'
            AND dict.status_cd = pool.maintenance_type
        WHERE
            pool.repair_id = ? AND pool.status_cd='0'
    )";
    PtrExportTaskDetailMapper mapper;
    return sqlSession->executeQueryOne<PtrTaskDetailDO>(sql, mapper, "%s", query->repair_id.getValue(""));
}

uint64_t TaskDetailDAO::count_r_repair_user(const TaskDetailQuery::Wrapper& query)
{
    string sql = "SELECT COUNT(*) FROM r_repair_user WHERE repair_id = ? AND status_cd='0'";
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, "%s", query->repair_id.getValue(""));
}

std::list<TaskDetailDO> TaskDetailDAO::selectExportCirculate_r_repair_user(const TaskDetailQuery::Wrapper& query)
{
    string sql = R"(
        SELECT
            user.staff_name,
            dict.name AS state,
            user.start_time,
            CONCAT(
                 FLOOR(TIMESTAMPDIFF(SECOND, user.start_time, IFNULL(user.end_time, NOW())) / 3600), ':',
                 LPAD(FLOOR(MOD(TIMESTAMPDIFF(SECOND, user.start_time, IFNULL(user.end_time, NOW())), 3600) / 60), 2, '0')
            ) AS cost,
            user.context
        FROM
            r_repair_user user
        LEFT JOIN t_dict dict
            ON dict.table_name = 'r_repair_user'
            AND dict.status_cd = user.state
        WHERE
            user.repair_id = ? AND user.status_cd='0'
    )";

    ExportCirculateMapper mapper;
    return sqlSession->executeQuery<TaskDetailDO>(sql, mapper, "%s", query->repair_id.getValue(""));
}



PtrTaskDetailGetDO TaskDetailDAO::selectById(std::string id)
{
	string sql = R"(
		SELECT 
			rp.repair_id,
			rp.repair_type,
			(SELECT name FROM t_dict WHERE table_name = 'r_repair_pool' AND table_columns = 'repair_type' AND status_cd = rp.repair_type) AS repair_type_txt,
			rp.repair_name,
			rp.tel,
			rp.repair_obj_name,
			rp.appointment_time,
			rp.state,
			(SELECT name FROM t_dict WHERE table_name = 'r_repair_pool' AND table_columns = 'state' AND status_cd = rp.state) AS state_txt,
			rp.context,
			rp.create_time
		FROM r_repair_pool rp
		WHERE rp.repair_id = ?
	)";
	PtrTaskDetailGetMapper mapper;
	return sqlSession->executeQueryOne<PtrTaskDetailGetDO>(sql, mapper, "%s", id);
}


