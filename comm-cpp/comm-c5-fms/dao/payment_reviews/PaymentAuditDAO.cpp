/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/23 18:00:01

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
#include "PaymentAuditDAO.h"
#include "PaymentAuditMapper.h"
#include <sstream>

std::string PaymentAuditDAO::buildListConditions(const PaymentAuditListQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";

	// 付费对象
	if (query->payer_obj_type) {
		sqlCondition << " AND pf.payer_obj_type = ?";
		SQLPARAMS_PUSH(params, "s", string, query->payer_obj_type.getValue(""));
	}

	// 审核状态
	if (query->state) {
		sqlCondition << " AND pfau.state = ?";
		SQLPARAMS_PUSH(params, "s", string, query->state.getValue(""));
	}

	// 房屋
	if (query->value) {
		sqlCondition << " AND pfa.value = ?";
		SQLPARAMS_PUSH(params, "s", string, query->value.getValue(""));
	}

	return sqlCondition.str();
}

std::string PaymentAuditDAO::buildHistoryConditions(const PaymentAuditHistoryQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	//fee_id条件
	if (query->fee_id) {
		sqlCondition << " AND pf.fee_id = ?";
		SQLPARAMS_PUSH(params, "s", string, query->fee_id.getValue(""));
	}

	// 时间范围处理
	if (query->start_time || query->end_time) {
		// 两者都存在
		if (query->start_time && query->end_time) {
			sqlCondition << " AND pfd.create_time BETWEEN ? AND ?";
			SQLPARAMS_PUSH(params, "s", string, query->start_time.getValue(""));
			SQLPARAMS_PUSH(params, "s", string, query->end_time.getValue(""));
		}
		// 仅开始时间
		else if (query->start_time) {
			sqlCondition << " AND pfd.create_time >= ?";
			SQLPARAMS_PUSH(params, "s", string, query->start_time.getValue(""));
		}
		// 仅结束时间
		else if (query->end_time) {
			sqlCondition << " AND pfd.create_time <= ?";
			SQLPARAMS_PUSH(params, "s", string, query->end_time.getValue(""));
		}
	}

	return sqlCondition.str();
}

std::list<PaymentAuditListDO> PaymentAuditDAO::selectPaymentAuditList(const PaymentAuditListQuery::Wrapper& query)
{
	SqlParams params;
	string sql= R"(
        SELECT 
            pfa.value AS obj_name,
            pfc.fee_name,
            pfd.cycles,
            pf.start_time,
            pf.end_time,
            pfd.receivable_amount,
            pfd.received_amount,
            pfd.cashier_name,
            pfd.create_time,
            pfau.state,
            pfau.message,
            pfd.remark
        FROM pay_fee pf
        JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id
        JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id
        JOIN report_owner_pay_fee ropf ON pf.fee_id = ropf.fee_id 
        JOIN pay_fee_attrs pfa ON pf.fee_id = pfa.fee_id  
        LEFT JOIN pay_fee_audit pfau ON pf.fee_id = pfau.fee_id 
        LEFT JOIN t_dict audit_dict ON pfau.state = audit_dict.status_cd 
            AND audit_dict.table_name = 'pay_fee_audit' 
            AND audit_dict.table_columns = 'state'
        LEFT JOIN t_dict dict_type ON pfc.fee_type_cd = dict_type.status_cd 
            AND dict_type.table_name = 'pay_fee_config' 
            AND dict_type.table_columns = 'fee_type_cd'
        LEFT JOIN t_dict dict_flag ON pfc.fee_flag = dict_flag.status_cd 
            AND dict_flag.table_name = 'pay_fee_config' 
            AND dict_flag.table_columns = 'fee_flag'
    )";
	sql += buildListConditions(query, params);

	sql += " ORDER BY pfd.create_time DESC";
	// 分页
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	PaymentAuditListMapper mapper;
	return sqlSession->executeQuery<PaymentAuditListDO>(sql, mapper, params);
}

uint64_t PaymentAuditDAO::countAuditList(const PaymentAuditListQuery::Wrapper& query)
{
	SqlParams params;
	string sql = R"(
        SELECT COUNT(DISTINCT pf.fee_id) 
        FROM pay_fee pf
        JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id
        JOIN pay_fee_config pfc ON pf.config_id = pfc.config_id
        JOIN report_owner_pay_fee ropf ON pf.fee_id = ropf.fee_id 
        JOIN pay_fee_attrs pfa ON pf.fee_id = pfa.fee_id  
        LEFT JOIN pay_fee_audit pfau ON pf.fee_id = pfau.fee_id 
        LEFT JOIN t_dict audit_dict ON pfau.state = audit_dict.status_cd 
            AND audit_dict.table_name = 'pay_fee_audit' 
            AND audit_dict.table_columns = 'state'
        LEFT JOIN t_dict dict_type ON pfc.fee_type_cd = dict_type.status_cd 
            AND dict_type.table_name = 'pay_fee_config' 
            AND dict_type.table_columns = 'fee_type_cd'
        LEFT JOIN t_dict dict_flag ON pfc.fee_flag = dict_flag.status_cd 
            AND dict_flag.table_name = 'pay_fee_config' 
            AND dict_flag.table_columns = 'fee_flag'
    )";
	// 构建查询条件
	sql += buildListConditions(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

PtrPaymentAuditDetailDO PaymentAuditDAO::selectAuditDetail(const std::string& id)
{
	string sql = R"(
			SELECT 
				pf.fee_id,
				dict_flag.name AS fee_flag,
				dict_type.name AS fee_type_cd,
				pfa.value AS payer_obj_name,
				pfc.fee_name,
				dict_state.name AS fee_state,
				pfd.create_time,
				pf.start_time,
				pf.end_time,
				pf.batch_id,
				br.built_up_area AS area,
				pfc.square_price,
				pfc.additional_amount AS fee_addition
			FROM 
				pay_fee pf
			JOIN 
				pay_fee_detail pfd ON pf.fee_id = pfd.fee_id
			JOIN 
				pay_fee_config pfc ON pf.config_id = pfc.config_id
			JOIN 
				pay_fee_attrs pfa ON pf.fee_id = pfa.fee_id AND pfa.spec_cd =390012
			LEFT JOIN 
				building_room br ON pf.payer_obj_id = br.room_id
			LEFT JOIN 
				t_dict dict_flag 
				ON pfc.fee_flag = dict_flag.status_cd 
				AND dict_flag.table_name = 'pay_fee_config' 
				AND dict_flag.table_columns = 'fee_flag'
			LEFT JOIN 
				t_dict dict_type 
				ON pfc.fee_type_cd = dict_type.status_cd 
				AND dict_type.table_name = 'pay_fee_config' 
				AND dict_type.table_columns = 'fee_type_cd'
			LEFT JOIN 
				t_dict dict_state 
				ON pf.state = dict_state.status_cd  
				AND dict_state.table_name = 'pay_fee' 
				AND dict_state.table_columns = 'state'
			WHERE 
				pf.fee_id = ?
			)";
	PtrPaymentAuditDetailMapper mapper;
	return sqlSession->executeQueryOne<PtrPaymentAuditDetailDO>(sql, mapper, "%s", id);
}

std::list<PaymentAuditHistoryDO> PaymentAuditDAO::selectPaymentAuditHistory(const PaymentAuditHistoryQuery::Wrapper& query)
{
	SqlParams params;
	string sql = R"(
        SELECT 
            pfd.detail_id AS detailid,
            pfd.cycles AS cycles,
            pfd.prime_rate AS primerate,
            pfd.receivable_amount,
            pfd.received_amount,
            DATE_FORMAT(pfd.create_time, '%Y-%m-%d %H:%i:%s') AS createtime,
            DATE_FORMAT(pf.start_time, '%Y-%m-%d') AS starttime,
            DATE_FORMAT(pf.end_time, '%Y-%m-%d') AS endtime,
            pfd.cashier_name AS cashiername,
            pfd.status_cd AS statuscd,
            pfd.remark AS remark
        FROM pay_fee_detail pfd
        JOIN pay_fee pf ON pfd.fee_id = pf.fee_id
        LEFT JOIN pay_fee_audit pfa ON pfd.detail_id = pfa.fee_detail_id
    )";
	sql += buildHistoryConditions(query, params);
	sql += " ORDER BY pfd.create_time DESC";
	// 分页
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	PaymentAuditHistoryMapper mapper;
	return sqlSession->executeQuery<PaymentAuditHistoryDO>(sql, mapper, params);
}

uint64_t PaymentAuditDAO::countAuditHistory(const PaymentAuditHistoryQuery::Wrapper& query)
{
	SqlParams params;
	string sql = R"(
        SELECT COUNT(DISTINCT pfd.detail_id)  
        FROM pay_fee_detail pfd
        JOIN pay_fee pf ON pfd.fee_id = pf.fee_id
        LEFT JOIN pay_fee_audit pfa ON pfd.detail_id = pfa.fee_detail_id
    )";
	// 构建查询条件
	sql += buildHistoryConditions(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
