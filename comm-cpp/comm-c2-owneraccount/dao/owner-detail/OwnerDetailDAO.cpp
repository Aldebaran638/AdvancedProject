#pragma once
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
#include "OwnerDetailDAO.h"
#include "OwnerDetailMapper.h"
#include <sstream>

std::string OwnerDetailDAO::OwnerDetail_queryConditionBuilder_count(const OwnerDetailQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	// 账户编号
	if (query->acct_id) {

		sqlCondition << " AND account_detail.acct_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acct_id.getValue(""));
	}
	// detial_type_text获取
	sqlCondition << " AND account_detail.detail_type=t_dict.status_cd AND t_dict.table_name='account_detail' AND t_dict.table_columns='detail_type'";

	sqlCondition << " AND account_detail.acct_id=account.acct_id";
	return sqlCondition.str();
}

uint64_t OwnerDetailDAO::OwnerDetail_count(const OwnerDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM account_detail, account, t_dict";	
	// 构建查询条件
	sql += OwnerDetail_queryConditionBuilder_count(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::string OwnerDetailDAO::OwnerDetail_queryConditionBuilder_select(const OwnerDetailQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	// 账户编号
	if (query->acct_id) {

		sqlCondition << " AND account_detail.acct_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acct_id.getValue(""));
	}
	// detial_type_text获取
	sqlCondition << " AND account_detail.detail_type=t_dict.status_cd AND t_dict.table_name='account_detail' AND t_dict.table_columns='detail_type'";

	// 消除笛卡尔积
	sqlCondition << " AND account_detail.acct_id=account.acct_id";
	return sqlCondition.str();
}

std::list<OwnerDetailDO> OwnerDetailDAO::OwnerDetail_selectWithPage(const OwnerDetailQuery::Wrapper& query)
{
	//detail_type_text:626014-626015
	SqlParams params;
	string sql = 
		"SELECT account_detail.detail_id, account_detail.order_id, account.acct_name, account_detail.detail_type, account_detail.amount, account_detail.create_time,account_detail.remark,t_dict.name FROM account_detail, account, t_dict"
	;
	// 构建查询条件
	sql += OwnerDetail_queryConditionBuilder_select(query, params);
	// 构建排序语句
	sql += " ORDER BY account_detail.create_time DESC, account_detail.detail_id DESC ";
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	OwnerDetailMapper mapper;
	return sqlSession->executeQuery<OwnerDetailDO>(sql, mapper, params);
}

int OwnerDetailDAO::OwnerDetail_add_insert_account_detail(const OwnerDetailDO& iObj)
{
	//account_detail表
	string sql_account_detail = 
		"INSERT INTO `account_detail` (`detail_id`, `acct_id`, `detail_type`, `rel_acct_id`, `amount`, `obj_type`, `obj_id`, `order_id`, `b_id`, `remark`, `create_time`, `status_cd`) SELECT ? AS detail_id, acct_id, ? AS detail_type, ? AS rel_acct_id, ? AS amount, ? AS obj_type, obj_id, ? AS order_id, ? AS b_id, ? AS remark, ? AS create_time, ? AS status_cd FROM account WHERE link=? AND acct_name=?"
	;
	return sqlSession->executeUpdate(
		sql_account_detail, 
		"%s%s%s%d%s%s%s%s%s%s%s%s", 
		iObj.getDetailId(), iObj.getDetailType(), iObj.getRelAcctId(), iObj.getAmount(), iObj.getObjType(), iObj.getOrderId(), iObj.getBId(), iObj.getRemark(), iObj.getCreateTime(), iObj.getStatusCd(), iObj.getLink(), iObj.getOwnerName()
	);
}

int OwnerDetailDAO::OwnerDetail_add_insert_account_receipt(const OwnerDetailDO& iObj)
{
	//account_receipt表
	string sql_account_receipt =
		"INSERT INTO `account_receipt` (`ar_id`, `acct_id`, `community_id`, `link`, `owner_id`, `owner_name`, `prime_rate`, `receivable_amount`, `received_amount`, `create_time`, `status_cd`, `remark`) SELECT ? AS ar_id, acct_id, ? AS community_id, link, obj_id AS owner_id, acct_name AS owner_name, ? AS prime_rate, ? AS receivable_amount, ? AS receivable_amount, ? AS create_time, ? AS status_cd, ? AS remark FROM account WHERE link=? AND acct_name=?"
	;
	return sqlSession->executeUpdate(
		sql_account_receipt,
		"%s%s%s%d%d%s%s%s%s%s",
		iObj.getArId(), iObj.getCommunityId(), iObj.getPrimeRate(), iObj.getReceivableAmount(), iObj.getReceivedAmount(), iObj.getCreateTime(), iObj.getStatusCd(), iObj.getRemark(), iObj.getLink(), iObj.getOwnerName()
	);
}

int OwnerDetailDAO::OwnerDetail_add_update_account(const OwnerDetailDO& uObj)
{
	string sql = "UPDATE `account` a1 JOIN (SELECT acct_id FROM `account` WHERE link=? AND acct_name=?) a2 ON a1.acct_id=a2.acct_id SET a1.amount=a1.amount+?";
	return sqlSession->executeUpdate(sql,
		"%s%s%d", uObj.getLink(), uObj.getOwnerName(), uObj.getAmount()
	);
}

std::string OwnerDetailDAO::OwnerDetail_queryConditionBuilder_AccountName(const OwnerDetailAccountNameQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	// 账户编号
	if (query->link) {

		sqlCondition << " AND link=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
	}
	return sqlCondition.str();
}

std::list<OwnerDetailAccountNameDO> OwnerDetailDAO::OwnerDetail_add_get_account(const OwnerDetailAccountNameQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT acct_name FROM account";
	// 构建查询条件
	sql += OwnerDetail_queryConditionBuilder_AccountName(query, params);
	OwnerDetailAccountNameMapper mapper;
	return sqlSession->executeQuery<OwnerDetailAccountNameDO>(sql, mapper, params);

}



int OwnerDetailDAO::OwnerDetail_undo_update_account(const OwnerDetailDO& uObj)
{
	string sql = 
		"UPDATE account a JOIN (SELECT acct_id,amount FROM account_detail WHERE detail_id=?) d ON a.acct_id=d.acct_id SET a.amount=a.amount-d.amount WHERE a.acct_id=d.acct_id"
	;
	return sqlSession->executeUpdate(sql,
		"%s", uObj.getPreDetailId()
	);
}

int OwnerDetailDAO::OwnerDetail_undo_update_account_detail(const OwnerDetailDO& uObj)
{
	string sql =
		"UPDATE account_detail SET detail_type='3003' WHERE detail_id=?"
		;
	return sqlSession->executeUpdate(sql,
		"%s", uObj.getPreDetailId()
	);
}

int OwnerDetailDAO::OwnerDetail_undo_insert_account_detail(const OwnerDetailDO& iObj)
{
	//account_detail表
	string sql_account_detail =
		"INSERT INTO `account_detail` (`acct_id`, `amount`, `obj_id`, `obj_type`, `detail_id`,  `detail_type`, `rel_acct_id`, `order_id`, `b_id`, `remark`, `create_time`, `status_cd`) SELECT a.acct_id, a.amount, a.obj_id, a.obj_type, ? AS detail_id, ? AS detail_type, ? AS rel_acct_id, ? AS order_id, ? AS b_id, ? AS remark, ? AS create_time, ? AS status_cd FROM account_detail a WHERE (a.detail_id=? AND (SELECT amount FROM account WHERE acct_id=a.acct_id)>=a.amount)"
	;
	return sqlSession->executeUpdate(
		sql_account_detail,
		"%s%s%s%s%s%s%s%s%s",
		iObj.getDetailId(), iObj.getDetailType(), iObj.getRelAcctId(), iObj.getOrderId(), iObj.getBId(), iObj.getRemark(), iObj.getCreateTime(), iObj.getStatusCd(), iObj.getPreDetailId()
	);
}