#include "stdafx.h"
#include "selectOwnerDAO.h"
#include "selectOwnerMapper.h"
#include <sstream>

std::string selectOwnerDAO::queryConditionBuilder(const OwnerQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->owner_id) {
		sqlCondition << " AND building_owner.owner_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->owner_id.getValue(""));
	}
	if (query->name) {
		sqlCondition << " AND building_owner.name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->room_num)
	{
		sqlCondition << " AND building_room.room_num=?";	//房屋编号
		SQLPARAMS_PUSH(params, "s", std::string, query->room_num.getValue(""));
	}
	if (query->link) {
		sqlCondition << " AND building_owner.link=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	if (query->id_card) {
		sqlCondition << " AND building_owner.id_card=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue(""));
	}
	if (query->member_name)
	{
		sqlCondition << " AND member.name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->member_name.getValue(""));
	}
	if (query->member_link)
	{
		sqlCondition << " AND member.link=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->member_link.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t selectOwnerDAO::count(const OwnerQuery::Wrapper& query)
{
	SqlParams params;
	string sql = " SELECT COUNT(DISTINCT building_owner.owner_id)  ";
	sql += " FROM building_owner ";
	sql += " LEFT JOIN building_owner_room_rel ON building_owner_room_rel.owner_id = building_owner.owner_id ";
	sql += " LEFT JOIN building_room ON building_room.room_id=building_owner_room_rel.room_id ";
	sql += " LEFT JOIN file_rel file ON file.obj_id = building_owner.owner_id ";
	sql += " LEFT JOIN (SELECT repair_name, COUNT(*) AS repair_num FROM r_repair_pool GROUP BY repair_name) rep ON rep.repair_name=building_owner.name ";
	sql += " LEFT JOIN bill_owe_fee  fee ON fee.owner_id=building_owner.owner_id ";
	sql += " LEFT JOIN access_control_white acw ON acw.id_card = building_owner.id_card ";
	sql += " LEFT JOIN ( SELECT  owner_id, COUNT(*) AS house_num,  COUNT(*) AS contract_num   FROM contract_room GROUP BY owner_id) rc ON rc.owner_id = building_owner.owner_id";
	sql += " LEFT JOIN ( SELECT owner_id, COUNT(*) AS car_number  FROM owner_car  GROUP BY owner_id) car ON car.owner_id = building_owner.owner_id ";
	sql += " LEFT JOIN ( SELECT owner_id, COUNT(*) AS complaint_num FROM complaint  GROUP BY owner_id) com ON com.owner_id = building_owner.owner_id ";
	sql += " LEFT JOIN ( SELECT main.owner_id, mem.name, mem.link, COUNT(mem.member_id) AS member_num  FROM building_owner main LEFT JOIN building_owner mem ON main.owner_id = mem.member_id AND mem.status_cd = '0' WHERE main.owner_type_cd = '1001' AND main.status_cd = '0' GROUP BY main.owner_id) member ON member.owner_id = building_owner.owner_id ";

	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<OwnerDO> selectOwnerDAO::selectWithPage(const OwnerQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT DISTINCT building_owner.owner_id,building_owner.name,file.file_real_name, building_owner.sex,building_owner.id_card,building_owner.link,building_owner.address, ";
	sql += " COALESCE(rc.house_num, 0) AS house_num, COALESCE(member.member_num, 0) AS member_num, COALESCE(car.car_number, 0) AS car_number,COALESCE(com.complaint_num, 0) AS complaint_num,";
	sql += " (SELECT COUNT(*) FROM r_repair_pool rep WHERE rep.repair_name=building_owner.name) AS repair_num,";
	sql += " fee.amount_owed, COALESCE(rc.contract_num, 0) AS contract_num, acw.access_control_key ,building_owner.create_time";
	sql += " FROM building_owner ";
	sql += " LEFT JOIN building_owner_room_rel ON building_owner_room_rel.owner_id=building_owner.owner_id ";
	sql += " LEFT JOIN building_room ON building_room.room_id=building_owner_room_rel.room_id ";
	sql += " LEFT JOIN file_rel file ON file.obj_id = building_owner.owner_id ";
	sql += " LEFT JOIN bill_owe_fee  fee ON fee.owner_id=building_owner.owner_id ";
	sql += " LEFT JOIN access_control_white acw ON acw.id_card = building_owner.id_card ";
	sql += " LEFT JOIN ( SELECT  owner_id, COUNT(*) AS house_num,  COUNT(*) AS contract_num   FROM contract_room GROUP BY owner_id) rc ON rc.owner_id = building_owner.owner_id";
	sql += " LEFT JOIN ( SELECT owner_id, COUNT(*) AS car_number  FROM owner_car  GROUP BY owner_id) car ON car.owner_id = building_owner.owner_id ";
	sql += " LEFT JOIN ( SELECT owner_id, COUNT(*) AS complaint_num FROM complaint  GROUP BY owner_id) com ON com.owner_id = building_owner.owner_id ";
	sql += " LEFT JOIN ( SELECT main.owner_id, mem.name,mem.link, COUNT(mem.member_id) AS member_num  FROM building_owner main LEFT JOIN building_owner mem ON main.owner_id = mem.member_id AND mem.status_cd = '0' WHERE main.owner_type_cd = '1001' AND main.status_cd = '0' GROUP BY main.owner_id) member ON member.owner_id = building_owner.owner_id ";

	sql += queryConditionBuilder(query, params);
	
	sql += " ORDER BY  building_owner.create_time DESC";

	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	
	selectOwnerMapper mapper;
	return sqlSession->executeQuery<OwnerDO>(sql, mapper, params);
}
std::list<OwnerDO> selectOwnerDAO::selectByName(const string& name)
{
	SqlParams params;
	string sql = " SELECT own.owner_id, own.name, file.file_real_name, own.sex, own.id_card, own.link, own.address, acc.access_control_key, fee.amount_owed, ";
	sql += "COALESCE(rom.house_num, 0) AS house_num, COALESCE(car.car_number, 0) AS car_number, COALESCE(member.member_num, 0) AS member_num, COALESCE(com.complaint_num, 0) AS complaint_num, COALESCE(rep.repair_num, 0) AS repair_num, COALESCE(tra.contract_num, 0) AS contract_num ";
	sql += " FROM building_owner own ";
	//房屋数
	sql += " LEFT JOIN (SELECT bo.owner_id, COUNT(*) AS house_num FROM building_owner bo INNER JOIN contract_room a ON bo.owner_id=a.owner_id GROUP BY bo.owner_id) rom ON rom.owner_id=own.owner_id ";
	//业主人脸
	sql += " LEFT JOIN file_rel file ON own.owner_id = file.obj_id ";
	//门禁钥匙
	sql += " LEFT JOIN access_control_white acc ON own.id_card=acc.id_card";
	//欠费
	sql += " LEFT JOIN bill_owe_fee fee ON own.owner_id=fee.owner_id";
	//报修
	sql += " LEFT JOIN (SELECT bo.owner_id, bo.name, COUNT(*) AS repair_num FROM building_owner bo LEFT JOIN r_repair_pool b ON bo.name=b.repair_name GROUP BY bo.owner_id, bo.name) rep ON rep.owner_id=own.owner_id";
	//车辆数
	sql += " LEFT JOIN (SELECT bo.owner_id, COUNT(*) AS car_number FROM building_owner bo LEFT JOIN owner_car c ON bo.owner_id=c.owner_id GROUP BY bo.owner_id) car ON car.owner_id=own.owner_id ";
	//投诉数
	sql += " LEFT JOIN (SELECT bo.owner_id, COUNT(*) AS complaint_num FROM building_owner bo LEFT JOIN complaint d  ON bo.owner_id=d.owner_id GROUP BY bo.owner_id) com ON com.owner_id=own.owner_id";
	//合同数
	sql += " LEFT JOIN (SELECT bo.owner_id, COUNT(*) AS contract_num FROM building_owner bo LEFT JOIN contract_room e ON bo.owner_id=e.owner_id GROUP BY bo.owner_id) tra ON tra.owner_id=own.owner_id";
	//业主成员
	sql += " LEFT JOIN (SELECT main.owner_id, COUNT(mem.member_id) AS member_num FROM building_owner main LEFT JOIN building_owner mem ON main.owner_id=mem.member_id  AND mem.status_cd = '0' WHERE main.owner_type_cd='1001' AND main.status_cd='0' GROUP BY main.owner_id) member ON member.owner_id=own.owner_id";
	
	sql += " WHERE own.name LIKE CONCAT('%',?,'%')";
	selectOwnerMapper mapper;
	return sqlSession->executeQuery<OwnerDO>(sql, mapper, "%s", name);
}


