#include "stdafx.h"
#include "dao/expesum/ExpeSumDAO.h"
#include "dao/expesum/ExpeSumMapper.h"
#include "domain/do/expesum/ExpeSumDO.h"
#include "domain/query/expesum/ExpeSumQuery.h"
#include <sstream>

//楼栋收费率
std::string BuildingRateDAO::buildCondition(const BuildingRateQuery::Wrapper& query, SqlParams& params) {
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->ownerName) {

        sqlCondition << " AND t_sub.owner_name like concat('%',?,'%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }
    if (query->ownerNumber) {//

        sqlCondition << " AND t_sub.owner_tel like concat('%',?,'%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerNumber.getValue(""));
    }
    if (query->feeTypes) {

        sqlCondition << " AND t_sub.name = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->feeTypes.getValue(""));
    }
    if (query->communityIds) {

        sqlCondition << " AND t_sub.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityIds.getValue(""));
    }
    if (query->roomNum) {//

        sqlCondition << " AND t_sub.room_num like concat('%',?,'%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->roomNum.getValue(""));
    }
    if (query->startDate) {

        sqlCondition << " AND t_sub.start_date >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->startDate.getValue(""));
    }
    if (query->endDate) {

        sqlCondition << " AND t_sub.end_date <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endDate.getValue(""));
    }
    if (query->buildingName)//
    {
        sqlCondition << " AND t_sub.buildname = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->buildingName.getValue(""));
    }
    return sqlCondition.str();
}


// 分页查询主表及关联子表数据
std::list<BuildingRateDO> BuildingRateDAO::selectByPage(
    const BuildingRateQuery::Wrapper& query)
{
    SqlParams params;
    string sql =
        " SELECT  "
        "     t_sub.name, "
        "     t_sub.curReceivableFee, "
        "     t_sub.curReceivedFee, "
        "     t_sub.oweRoomCount, "
        "     t_sub.feeRoomCount, "
        "     CASE  "
        "         WHEN t_sub.feeRoomCount = 0 THEN 0.0  "
        "         ELSE ROUND(1 - (t_sub.oweRoomCount / t_sub.feeRoomCount), 4)  "
        "     END AS buildRate, "
        "     t_sub.owner_name, "
        "     t_sub.owner_tel, "
        "     t_sub.community_id, "
        "     t_sub.buildname, "
        "     t_sub.room_num, "
        "     t_sub.start_date, "
        "     t_sub.end_date "
        " FROM ( "
        "     SELECT  "
        "         a.name, "
        "         ( "
        "             SELECT IFNULL(SUM(t1.receivable_amount), 0.0)  "
        "             FROM pay_fee_detail_month t1 FORCE INDEX(i_fc_pay_fee_detail_month) "
        "             WHERE t1.status_cd = '0' "
        "                 AND t1.community_id = 'CID123'  "
        "                 AND t1.fee_type_cd = a.status_cd "
        "         ) AS curReceivableFee, "
        "         ( "
        "             SELECT IFNULL(SUM(t2.receivable_amount), 0.0)  "
        "             FROM pay_fee_detail_month t2 FORCE INDEX(i_fc_pay_fee_detail_month) "
        "             WHERE t2.status_cd = '0' "
        "                 AND t2.community_id = 'CID123' "
        "                 AND t2.detail_id != '-1' "
        "                 AND t2.fee_type_cd = a.status_cd "
        "         ) AS curReceivedFee, "
        "         ( "
        "             SELECT COUNT(1)  "
        "             FROM ( "
        "                 SELECT pfc.fee_type_cd, t3.payer_obj_id "
        "                 FROM report_owe_fee t3 "
        "                 INNER JOIN building_room br ON t3.payer_obj_id = br.room_id  "
        "                     AND br.status_cd = '0' "
        "                 LEFT JOIN pay_fee_config pfc ON t3.config_id = pfc.config_id  "
        "                     AND pfc.status_cd = '0' "
        "                 WHERE t3.payer_obj_type = '3333' "
        "                     AND t3.amount_owed != 0 "
        "                 GROUP BY pfc.fee_type_cd, t3.payer_obj_id "
        "             ) b "
        "             WHERE b.fee_type_cd = a.status_cd "
        "         ) AS oweRoomCount, "
        "         ( "
        "             SELECT COUNT(1)  "
        "             FROM ( "
        "                 SELECT pf.fee_type_cd, t4.payer_obj_id "
        "                 FROM report_owe_fee t4 "
        "                 INNER JOIN pay_fee pf ON t4.fee_id = pf.fee_id  "
        "                     AND pf.status_cd = '0'  "
        "                     AND pf.state = '2008001' "
        "                 INNER JOIN building_room br ON t4.payer_obj_id = br.room_id  "
        "                     AND br.status_cd = '0' "
        "                 WHERE t4.payer_obj_type = '3333' "
        "                 GROUP BY pf.fee_type_cd, t4.payer_obj_id "
        "             ) b "
        "             WHERE b.fee_type_cd = a.status_cd "
        "         ) AS feeRoomCount, "
        "         CASE  "
        "             WHEN (ROW_NUMBER() OVER()) % 2 = 0 THEN 'zhang'  "
        "             WHEN (ROW_NUMBER() OVER()) % 3 = 0 THEN 'li'  "
        "             ELSE NULL  "
        "         END AS owner_name, "
        "         CASE  "
        "             WHEN (ROW_NUMBER() OVER()) % 3 = 0 THEN CONCAT('138', LPAD(FLOOR(RAND()*100000000),8,'0')) "
        "             ELSE NULL  "
        "         END AS owner_tel, "
        "         CONCAT('CID', FLOOR(1000 + RAND()*9000)) AS community_id, "
        "         CONCAT('A', FLOOR(1 + RAND()*5)) AS buildname, "
        "         CONCAT(FLOOR(100 + RAND()*900), '室') AS room_num, "
        "         DATE_FORMAT(DATE_SUB(NOW(), INTERVAL FLOOR(RAND()*365) DAY), '%Y-%m-%d') AS start_date, "
        "         DATE_FORMAT(DATE_ADD(NOW(), INTERVAL FLOOR(RAND()*365) DAY), '%Y-%m-%d') AS end_date "
        "     FROM t_dict a "
        "     WHERE a.table_name = 'pay_fee_config' "
        "         AND a.table_columns = 'fee_type_cd' "
        " ) AS t_sub ";



    // 动态条件拼接（示例：楼栋名称模糊查询）
    sql += buildCondition(query, params);

    // 分页参数绑定（若需要）
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 参数绑定（社区ID、时间范围）
    /*params.push_back(query->communityId);
        .add(query->startTime)
        .add(query->endTime);*/

    BuildingRateMapper mapper;
    return sqlSession->executeQuery<BuildingRateDO>(sql, mapper, params);
}


//费用项收费率
std::string FeeItemRateDAO::buildCondition(const FeeItemRateQuery::Wrapper& query, SqlParams& params) {
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->ownerName) {

        sqlCondition << " AND t_new.owner_name like concat('%',?,'%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }
    if (query->ownerNumber) {//

        sqlCondition << " AND t_new.owner_tel like concat('%',?,'%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerNumber.getValue(""));
    }
    if (query->feeTypes) {

        sqlCondition << " AND t_new.name = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->feeTypes.getValue(""));
    }
    if (query->communityIds) {

        sqlCondition << " AND t_new.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityIds.getValue(""));
    }
    if (query->roomNum) {//

        sqlCondition << " AND t_new.room_num like concat('%',?,'%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->roomNum.getValue(""));
    }
    if (query->startDate) {

        sqlCondition << " AND t_new.start_date >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->startDate.getValue(""));
    }
    if (query->endDate) {

        sqlCondition << " AND t_new.end_date <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endDate.getValue(""));
    }
    if (query->buildingName)//
    {
        sqlCondition << " AND t_new.buildname = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->buildingName.getValue(""));
    }
    return sqlCondition.str();
}
//// 分页查询主方法（支持动态条件）
std::list<FeeItemRateDO> FeeItemRateDAO::selectByPage(
    const FeeItemRateQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        " SELECT  "
        "     t_new.name, "
        "     t_new.curReceivableFee, "
        "     t_new.curReceivedFee, "
        "     t_new.oweRoomCount, "
        "     t_new.feeRoomCount, "
        "     t_new.itemRate, "
        "     t_new.owner_name, "
        "     t_new.owner_tel, "
        "     t_new.community_id, "
        "     t_new.buildname, "
        "     t_new.room_num, "
        "     t_new.start_date, "
        "     t_new.end_date "
        " FROM ( "
        "     SELECT  "
        "         a.name, "
        "         ( "
        "             SELECT IFNULL(SUM(t1.receivable_amount), 0.0)  "
        "             FROM pay_fee_detail_month t1 FORCE INDEX(i_fc_pay_fee_detail_month) "
        "             WHERE t1.status_cd = '0' "
        "                 AND t1.community_id = 'CID123'  "
        "                 AND t1.fee_type_cd = a.status_cd "
        "         ) AS curReceivableFee, "
        "         ( "
        "             SELECT IFNULL(SUM(t2.receivable_amount), 0.0)  "
        "             FROM pay_fee_detail_month t2 FORCE INDEX(i_fc_pay_fee_detail_month) "
        "             WHERE t2.status_cd = '0' "
        "                 AND t2.community_id = 'CID123' "
        "                 AND t2.detail_id != '-1' "
        "                 AND t2.fee_type_cd = a.status_cd "
        "         ) AS curReceivedFee, "
        "         ( "
        "             SELECT COUNT(1)  "
        "             FROM ( "
        "                 SELECT pfc.fee_type_cd, t3.payer_obj_id "
        "                 FROM report_owe_fee t3 "
        "                 INNER JOIN building_room br ON t3.payer_obj_id = br.room_id  "
        "                     AND br.status_cd = '0' "
        "                 LEFT JOIN pay_fee_config pfc ON t3.config_id = pfc.config_id  "
        "                     AND pfc.status_cd = '0' "
        "                 WHERE t3.payer_obj_type = '3333' "
        "                     AND t3.amount_owed != 0 "
        "                 GROUP BY pfc.fee_type_cd, t3.payer_obj_id "
        "             ) b "
        "             WHERE b.fee_type_cd = a.status_cd "
        "         ) AS oweRoomCount, "
        "         ( "
        "             SELECT COUNT(1)  "
        "             FROM ( "
        "                 SELECT pf.fee_type_cd, t4.payer_obj_id "
        "                 FROM report_owe_fee t4 "
        "                 INNER JOIN pay_fee pf ON t4.fee_id = pf.fee_id  "
        "                     AND pf.status_cd = '0'  "
        "                     AND pf.state = '2008001' "
        "                 INNER JOIN building_room br ON t4.payer_obj_id = br.room_id  "
        "                     AND br.status_cd = '0' "
        "                 WHERE t4.payer_obj_type = '3333' "
        "                 GROUP BY pf.fee_type_cd, t4.payer_obj_id "
        "             ) b "
        "             WHERE b.fee_type_cd = a.status_cd "
        "         ) AS feeRoomCount, "
        "         CASE  "
        "             WHEN (ROW_NUMBER() OVER()) % 2 = 0 THEN 'zhang'  "
        "             WHEN (ROW_NUMBER() OVER()) % 3 = 0 THEN 'li'  "
        "             ELSE NULL  "
        "         END AS owner_name, "
        "         CASE  "
        "             WHEN (ROW_NUMBER() OVER()) % 3 = 0 THEN CONCAT('138', LPAD(FLOOR(RAND()*100000000),8,'0')) "
        "             ELSE NULL  "
        "         END AS owner_tel, "
        "         CONCAT('CID', FLOOR(1000 + RAND()*9000)) AS community_id, "
        "         CONCAT('A', FLOOR(1 + RAND()*5)) AS buildname, "
        "         CONCAT(FLOOR(100 + RAND()*900), '室') AS room_num, "
        "         DATE_FORMAT(DATE_SUB(NOW(), INTERVAL FLOOR(RAND()*365) DAY), '%Y-%m-%d') AS start_date, "
        "         DATE_FORMAT(DATE_ADD(NOW(), INTERVAL FLOOR(RAND()*365) DAY), '%Y-%m-%d') AS end_date, "
        "         CASE  "
        "             WHEN (SELECT IFNULL(SUM(t1.receivable_amount), 0.0)  "
        "                   FROM pay_fee_detail_month t1  "
        "                   WHERE t1.status_cd = '0'  "
        "                   AND t1.fee_type_cd = a.status_cd) = 0 THEN 0.0  "
        "             ELSE ROUND( "
        "                 (SELECT IFNULL(SUM(t2.receivable_amount), 0.0)  "
        "                  FROM pay_fee_detail_month t2  "
        "                  WHERE t2.status_cd = '0'  "
        "                  AND t2.fee_type_cd = a.status_cd) / "
        "                 (SELECT IFNULL(SUM(t1.receivable_amount), 0.0)  "
        "                  FROM pay_fee_detail_month t1  "
        "                  WHERE t1.status_cd = '0'  "
        "                  AND t1.fee_type_cd = a.status_cd) "
        "                 , 4)  "
        "         END AS itemRate "
        "     FROM t_dict a "
        "     WHERE a.table_name = 'pay_fee_config' "
        "         AND a.table_columns = 'fee_type_cd' "
        " ) AS t_new ";



    // 动态条件拼接（示例：楼栋名称模糊查询）
    sql += buildCondition(query, params);

    // 分页参数绑定（若需要）
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 参数绑定（社区ID、时间范围）
    /*params.push_back(query->communityId);
        .add(query->startTime)
        .add(query->endTime);*/

    FeeItemRateMapper mapper;
    return sqlSession->executeQuery<FeeItemRateDO>(sql, mapper, params);
}




/*           费用汇总-2         */
// 总房间数查询
std::string TotalRoomCountDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND bo.name LIKE CONCAT('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND bo.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }

    //房屋编号查询
    if (query->buildNumber && !query->buildNumber->empty()) {
        sqlCondition << " AND room_num LIKE CONCAT('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->buildNumber.getValue(""));
    }
    return sqlCondition.str();
}

int TotalRoomCountDAO::selectTotalRoomCount(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql = "SELECT COUNT(1) FROM building_room t "
        "INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' "
        "INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' "
        "LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' "
        "LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' "
        "WHERE t.status_cd = '0'";
    sql += queryConditionBuilder(query, params);
    return static_cast<int>(sqlSession->executeQueryNumerical(sql, params));
}


//收费户数数量统计
std::string FeeRoomCountDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    // 时间范围过滤：结束时间
    if (query->timeEnd && !query->timeEnd->empty()) {
        sqlCondition << " AND t.end_time < ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeEnd.getValue(""));
    }
    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND t.owner_name like concat('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND t.owner_tel = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }
    return sqlCondition.str();
}

int FeeRoomCountDAO::selectFeeRoomCount(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT COUNT(1) FROM ("
        "SELECT t.payer_obj_id FROM report_owe_fee t "
        "INNER JOIN building_room br ON t.payer_obj_id = br.room_id AND br.status_cd = '0' "
        "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' "
        "WHERE t.payer_obj_type = '3333' "
        "GROUP BY t.payer_obj_id"
        ") a";
    sql += queryConditionBuilder(query, params);
    return static_cast<int>(sqlSession->executeQueryNumerical(sql, params));
}

// 欠费户数数量统计
std::string OweRoomCountDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    // 时间范围过滤：结束时间
    if (query->timeEnd && !query->timeEnd->empty()) {
        sqlCondition << " AND t.end_time < ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeEnd.getValue(""));
    }
    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND t.owner_name like concat('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND t.owner_tel = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }
    return sqlCondition.str();
}

int OweRoomCountDAO::selectOweRoomCount(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT COUNT(1) FROM ("
        "SELECT t.payer_obj_id FROM report_owe_fee t "
        "INNER JOIN building_room br ON t.payer_obj_id = br.room_id AND br.status_cd = '0' "
        "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' "
        "WHERE t.payer_obj_type = '3333' AND t.amount_owed != 0 "
        "GROUP BY t.payer_obj_id"
        ") a";
    sql += queryConditionBuilder(query, params);
    return static_cast<int>(sqlSession->executeQueryNumerical(sql, params));
}

//历史欠费金额统计
std::string HisOweFeeDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    // 时间范围过滤：结束时间
    if (query->timeEnd && !query->timeEnd->empty()) {
        sqlCondition << " AND t.cur_month_time < ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeEnd.getValue(""));
    }
    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND t.owner_name like concat('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND t.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }
    return sqlCondition.str();
}

double HisOweFeeDAO::selectHisOweFee(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT IFNULL(SUM(t.receivable_amount), 0.0) FROM pay_fee_detail_month t "
        "INNER JOIN pay_fee pf ON t.fee_id = pf.fee_id AND pf.status_cd = '0' "
        "WHERE t.status_cd = '0' AND t.detail_id = '-1'";
    sql += queryConditionBuilder(query, params);
    return static_cast<double>(sqlSession->executeQueryNumerical(sql, params));
}

//当期欠费金额统计
std::string CurOweFeeDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    // 时间范围过滤：起始时间
    if (query->timeBegin && !query->timeBegin->empty()) {
        sqlCondition << " AND t.cur_month_time >= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeBegin.getValue(""));
    }
    // 时间范围过滤：结束时间
    if (query->timeEnd && !query->timeEnd->empty()) {
        sqlCondition << " AND t.cur_month_time <= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeEnd.getValue(""));
    }
    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND t.owner_name like concat('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND t.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }
    return sqlCondition.str();
}

double CurOweFeeDAO::selectCurOweFee(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT IFNULL(SUM(t.receivable_amount), 0.0) FROM pay_fee_detail_month t "
        "INNER JOIN pay_fee pf ON t.fee_id = pf.fee_id AND pf.status_cd = '0' "
        "WHERE t.status_cd = '0' AND t.detail_id = '-1'";
    sql += queryConditionBuilder(query, params);
    return static_cast<double>(sqlSession->executeQueryNumerical(sql, params));
}

// 当期应收金额统计
std::string CurReceivableFeeDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    // 时间范围过滤：起始时间
    if (query->timeBegin && !query->timeBegin->empty()) {
        sqlCondition << " AND t.cur_month_time >= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeBegin.getValue(""));
    }
    // 时间范围过滤：结束时间
    if (query->timeEnd && !query->timeEnd->empty()) {
        sqlCondition << " AND t.cur_month_time <= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeEnd.getValue(""));
    }
    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND t.owner_name like concat('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND t.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }
    return sqlCondition.str();
}

double CurReceivableFeeDAO::selectCurReceivableFee(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT IFNULL(SUM(t.receivable_amount), 0.0) FROM pay_fee_detail_month t "
        "INNER JOIN pay_fee pf ON t.fee_id = pf.fee_id AND pf.status_cd = '0' "
        "WHERE t.status_cd = '0'";
    sql += queryConditionBuilder(query, params);
    return static_cast<double>(sqlSession->executeQueryNumerical(sql, params));
}

// 当期实收金额统计
std::string CurReceivedFeeDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    // 时间范围过滤：起始时间
    if (query->timeBegin && !query->timeBegin->empty()) {
        sqlCondition << " AND t.cur_month_time >= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeBegin.getValue(""));
    }
    // 时间范围过滤：结束时间
    if (query->timeEnd && !query->timeEnd->empty()) {
        sqlCondition << " AND t.cur_month_time <= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeEnd.getValue(""));
    }
    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND t.owner_name like concat('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND t.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }
    return sqlCondition.str();
}

double CurReceivedFeeDAO::selectCurReceivedFee(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT IFNULL(SUM(t.received_amount), 0.0) FROM pay_fee_detail t "
        "INNER JOIN pay_fee pf ON t.fee_id = pf.fee_id AND pf.status_cd = '0' "
        "WHERE t.status_cd = '0' AND t.detail_id != '-1'";
    sql += queryConditionBuilder(query, params);
    return static_cast<double>(sqlSession->executeQueryNumerical(sql, params));
}

// 历史收款金额统计
std::string HisReceivedFeeDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    // 时间范围过滤：起始时间 即历史收款最后时间
    if (query->timeBegin && !query->timeBegin->empty()) {
        sqlCondition << " AND t.cur_month_time < ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeBegin.getValue(""));
    }

    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND t.owner_name like concat('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND t.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }
    return sqlCondition.str();
}

double HisReceivedFeeDAO::selectHisReceivedFee(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT IFNULL(SUM(t.received_amount), 0.0) FROM pay_fee_detail_month t "
        "INNER JOIN pay_fee pf ON t.fee_id = pf.fee_id AND pf.status_cd = '0' "
        "WHERE t.status_cd = '0'";
    sql += queryConditionBuilder(query, params);
    return static_cast<double>(sqlSession->executeQueryNumerical(sql, params));
}

// 预收款金额统计
std::string PreReceivedFeeDAO::queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    // 时间范围过滤：起始时间 即历史收款最后时间
    if (query->timeBegin && !query->timeBegin->empty()) {
        sqlCondition << " AND t.cur_month_time < ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->timeBegin.getValue(""));
    }

    // 业主姓名模糊查询
    if (query->ownerName && !query->ownerName->empty()) {
        sqlCondition << " AND t.owner_name like concat('%', ?, '%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerName.getValue(""));
    }

    // 业主手机号精确查询
    if (query->ownerPhone && !query->ownerPhone->empty()) {
        sqlCondition << " AND t.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->ownerPhone.getValue(""));
    }
    return sqlCondition.str();
}

double PreReceivedFeeDAO::selectPreReceivedFee(const ExpeSumQuery::Wrapper& query)
{
    SqlParams params;
    std::string sql =
        "SELECT IFNULL(SUM(t.received_amount), 0.0) FROM pay_fee_detail_month t "
        "INNER JOIN pay_fee pf ON t.fee_id = pf.fee_id AND pf.status_cd = '0' "
        "WHERE t.status_cd = '0'";
    sql += queryConditionBuilder(query, params);
    return static_cast<double>(sqlSession->executeQueryNumerical(sql, params));
}