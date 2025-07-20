#include "stdafx.h"
#include <sstream>
#include"SupRecepitDAO.h"
#include"SupRecepitMapper.h"
#include"SupRecepitForRoomMapper.h"

inline std::string SupRecepitDAO::queryConditionBuilder(const SupRecepitQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE DATE_SUB(curdate(),interval 30 DAY ) <= DATE(fr.create_time) AND fr.receipt_id = frd.receipt_id ";
	if (query->recepitId) {

		sqlCondition << " AND fr.receipt_id =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->recepitId.getValue(""));
	}
	if (query->message) {
		sqlCondition << " AND fr.obj_name =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->message.getValue(""));
	}
	if (query->feeTypeDetail) {
		sqlCondition << " AND fr.obj_type =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->feeTypeDetail.getValue({}));
	}
	if (query->startTime) {
		sqlCondition << " AND frd.start_time >=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->startTime.getValue({}));
	}
	if (query->endTime) {
		sqlCondition << " AND frd.end_time <=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->endTime.getValue({}));
	}
	return sqlCondition.str();
}

uint64_t SupRecepitDAO::count(const SupRecepitQuery::Wrapper& query) {
	string sql = "select count(*) from fee_receipt fr where date_sub(curdate(),interval 30 DAY ) <= date(fr.create_time);";
	return sqlSession->executeQueryNumerical(sql);
}

std::list<SupRecepitDO> SupRecepitDAO::selectWithPage(const SupRecepitQuery::Wrapper& query) {
	SqlParams params;
	string sql = "select fr.receipt_id,fr.receipt_code, fr.obj_type, ";
	sql += "frd.fee_name, if (fr.obj_type = 3333, fr.obj_name, fr.pay_obj_id) as obj_type_house,fr.pay_obj_name,";
	sql += "if (fr.obj_type = 3333, '-', fr.obj_name) as obj_type_car, fr.amount, fr.create_time from fee_receipt fr, fee_receipt_detail frd";
	sql += queryConditionBuilder(query, params);
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	SupRecepitMapper mapper;
	return sqlSession->executeQuery<SupRecepitDO>(sql, mapper, params);
}

std::list<SupRecepitForRoomDO> SupRecepitDAO::selectForRoom(std::string pay_id) {
	SqlParams params;
	string sql = "select distinct bf.name,bu.unit_num,bbr.room_num from building_owner_room_rel borr,business_building_room bbr,building_unit bu,business_floor bf";
	sql = sql + " where borr.owner_id = " + pay_id;
	sql += " and borr.room_id = bbr.room_id and bbr.unit_id = bu.unit_id and bu.floor_id = bf.floor_id";
	SupRecepitForRoomMapper mapper;
	return sqlSession->executeQuery<SupRecepitForRoomDO>(sql, mapper);
}

PtrReprintSupRecepitDO SupRecepitDAO::selectForReprint1(std::string id) {
	string sql = "select distinct fr.pay_obj_name, fr.obj_name,frd.fee_name,frd.start_time,frd.create_time,frd.end_time,pfd.payable_amount,";
	sql += " pfd.received_amount,fr.receipt_id,pfd.pay_order_id,pfd.cashier_name";
	sql += " from fee_receipt fr,fee_receipt_detail frd,pay_fee_detail pfd";
	sql += " where DATE_SUB(curdate(),interval 30 DAY ) <= DATE(pfd.create_time)";
	sql += " AND fr.receipt_id = frd.receipt_id";
	sql += " AND frd.detail_id = pfd.detail_id";
	sql = sql + " AND fr.receipt_id = " + id;
	PtrReprintSupRecepitMapper mapper;
	return sqlSession->executeQueryOne<PtrReprintSupRecepitDO>(sql, mapper);
}

PtrReprintSupRecepit2DO SupRecepitDAO::selectForReprint2(std::string id) {
	string sql = "select fr.receipt_code,pfd.pay_order_id,fr.obj_name,fr.pay_obj_name,fr.create_time,frd.fee_name, ";
	sql += "pfd.start_time,pfd.end_time,frd.square_price,frd.area,pfd.prime_rate,pfd.payable_amount,pfd.discount_amount, ";
	sql += "pfd.remark,pfd.received_amount,pfd.cashier_name ";
	sql += "from fee_receipt fr,fee_receipt_detail frd,pay_fee_detail pfd ";
	sql += "where DATE_SUB(curdate(),interval 30 DAY ) <= DATE(pfd.create_time) ";
	sql += "AND fr.receipt_id = frd.receipt_id ";
	sql += "AND frd.detail_id = pfd.detail_id ";
	sql = sql + "AND fr.receipt_id = " + id + ";";
	PtrReprintSupRecepit2Mapper mapper;
	return sqlSession->executeQueryOne<PtrReprintSupRecepit2DO>(sql, mapper);
}