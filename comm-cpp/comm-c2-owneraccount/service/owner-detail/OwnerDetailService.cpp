#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "OwnerDetailService.h"
#include "../../dao/owner-detail/OwnerDetailDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"

OwnerDetailPageDTO::Wrapper OwnerDetailService::OwnerDetail_listAll(const OwnerDetailQuery::Wrapper& query)
{
	
	// 构建返回对象
	auto pages = OwnerDetailPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	OwnerDetailDAO dao;
	uint64_t count = dao.OwnerDetail_count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OwnerDetailDO> result = dao.OwnerDetail_selectWithPage(query);
	
	// 将DO转换成DTO
	for (OwnerDetailDO sub : result)
	{
		auto dto = OwnerDetailGetDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, detail_id, DetailId, detail_type, DetailType, order_id, OrderId, owner_name, OwnerName, amount, Amount, create_time, CreateTime, detail_type_text, DetailTypeText);
		// 说明
		if (sub.getRemark() == "") dto->remark = ZH_WORDS_GETTER("owneraccount.owner-detail.mapping-remark-null");
		else dto->remark = sub.getRemark();

		pages->addData(dto);
	}
	
	return pages;
	
}


std::string OwnerDetailService::OwnerDetail_add_saveData(const OwnerDetailAddDTO::Wrapper& dto)
{
	// 雪花算法生成ID
	SnowFlake sf(1, 1);

	// 执行account数据更改
	// 组装DO数据
	OwnerDetailDO data_a;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_a, dto, Link, link, OwnerName, owner_name);
	data_a.setAmount(dto->receivable_amount.getValue({}));
	// 执行数据修改
	OwnerDetailDAO dao_a;
	dao_a.OwnerDetail_add_update_account(data_a);

	// 对account_detail和account_receipt的新增数据
	// 组装DO数据
	// 获得数据方式：生成、获取、前端

	//account_detail表
	/*
	CREATE TABLE `account_detail` (
	生成  `detail_id` varchar(30) '明细ID',
	获取  `acct_id` varchar(30) '账户ID',
	生成  `detail_type` varchar(128) '类型，1001 转入 2002 转出',
	生成  `rel_acct_id` varchar(30) DEFAULT '-1' COMMENT '关联账户',
	前端  `amount` decimal(10,2) DEFAULT '0.00' COMMENT '金额',
	生成  `obj_type` varchar(12) COMMENT '对象类型，6006 个人 7007 商户',
	获取  `obj_id` varchar(30) '对象ID，从building_owner中获取',
	生成  `order_id` varchar(30) '交易单号',
	生成  `b_id` varchar(30) '业务Id，默认1',
	前端  `remark` varchar(1024) DEFAULT NULL COMMENT '备注',
	生成  `create_time` timestamp COMMENT '创建时间',
	生成  `status_cd` varchar(2) DEFAULT '0' COMMENT '数据状态，详细参考c_status表，S 保存，0, 在用 1失效',
	)
	*/
	// 前端
	OwnerDetailDO data_ad;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_ad, dto, Remark, remark, Amount, receivable_amount, ObjType, obj_type, OwnerName, owner_name, Link, link);

	// 生成
	// 雪花算法生成detail_id
	data_ad.setDetailId(std::to_string(sf.nextId()));
	//detail_type默认为1001
	data_ad.setDetailType("1001");
	//rel_acct_id默认为-1
	data_ad.setRelAcctId("-1");
	// 雪花算法生成order_id
	data_ad.setOrderId(std::to_string(sf.nextId()));
	// b_id默认为-1
	data_ad.setBId("-1");
	// status_cd默认为0
	data_ad.setStatusCd("0");

	//account_receipt表
	/*
	CREATE TABLE `account_receipt` (
	生成  `ar_id` varchar(30) COMMENT '收据Id',
	获取  `acct_id` varchar(30) COMMENT '账户ID',
	获取  `community_id` varchar(30) COMMENT '小区ID',
	前端  `link` varchar(11) COMMENT '账户手机号',
	获取  `owner_id` varchar(30) COMMENT '业主ID',
	前端  `owner_name` varchar(64) COMMENT '业主名称',
	前端  `prime_rate` varchar(12) COMMENT '支付方式',
	前端  `receivable_amount` decimal(10,2) COMMENT '应收金额',
	前端  `received_amount` decimal(10,2) COMMENT '实收金额',
	生成  `create_time` timestamp DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
	生成  `status_cd` varchar(2) DEFAULT '0' COMMENT '数据状态，详细参考c_status表，S 保存，0, 在用 1失效',
	前端  `remark` varchar(512) COMMENT '说明',
	);
	*/
	// 前端
	//account_receipt表
	OwnerDetailDO data_ar;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_ar, dto, CommunityId, community_id, Link, link, OwnerName, owner_name, PrimeRate, prime_rate, ReceivedAmount, receivable_amount, ReceivableAmount, receivable_amount, Remark, remark);

	// 生成
	// 雪花算法生成ar_id
	data_ar.setArId(std::to_string(sf.nextId()));
	// status_cd默认为0
	data_ar.setStatusCd("0");

	// 设置创建时间
	data_ad.setCreateTime(SimpleDateTimeFormat::format());
	data_ar.setCreateTime(SimpleDateTimeFormat::format());

	// 执行数据添加
	//account_detail表
	OwnerDetailDAO dao_ad;
	dao_ad.OwnerDetail_add_insert_account_detail(data_ad);
	//account_receipt表
	OwnerDetailDAO dao_ar;
	return dao_ar.OwnerDetail_add_insert_account_receipt(data_ar) == 1 ? data_ar.getArId() : "";
}

OwnerDetailAccountNamePageDTO::Wrapper OwnerDetailService::listAllAccountNameByLink(const OwnerDetailAccountNameQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = OwnerDetailAccountNamePageDTO::createShared();
	OwnerDetailDAO dao;
	list<OwnerDetailAccountNameDO> result = dao.OwnerDetail_add_get_account(query);
	// 将DO转换成DTO
	for (OwnerDetailAccountNameDO sub : result)
	{
		auto dto = OwnerDetailAccountNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, owner_name, OwnerName);
		pages->addData(dto);
	}
	return pages;
}



std::string OwnerDetailService::OwnerDetail_undo_saveData(const OwnerDetailUndoDTO::Wrapper& dto)
{
	//运行结果
	std::string new_detail_id;

	// 雪花算法生成ID
	SnowFlake sf(1, 1);

	/*
	CREATE TABLE `account_detail` (
	生成  `detail_id` varchar(30) '明细ID',
	复制  `acct_id` varchar(30) '账户ID',
	生成  `detail_type` varchar(128) '类型，1001 转入 2002 转出',
	生成  `rel_acct_id` varchar(30) DEFAULT '-1' COMMENT '关联账户',
	复制  `amount` decimal(10,2) DEFAULT '0.00' COMMENT '金额',
	生成  `obj_type` varchar(12) COMMENT '对象类型，6006 个人 7007 商户',
	复制  `obj_id` varchar(30) '对象ID，从building_owner中获取',
	生成  `order_id` varchar(30) '交易单号',
	生成  `b_id` varchar(30) '业务Id，默认1',
	生成  `remark` varchar(1024) DEFAULT NULL COMMENT '备注',
	生成  `create_time` timestamp COMMENT '创建时间',
	生成  `status_cd` varchar(2) DEFAULT '0' COMMENT '数据状态，详细参考c_status表，S 保存，0, 在用 1失效',
	)
	*/

	// 对account_detail的新增数据
	// 组装DO数据
	OwnerDetailDO data_ad;
	ZO_STAR_DOMAIN_DTO_TO_DO(data_ad, dto, PreDetailId, pre_detail_id);
	// 重写remark
	std::string new_remark = ZH_WORDS_GETTER("owneraccount.owner-detail.mingxi");
	new_remark += dto->pre_detail_id.getValue({});
	new_remark += ZH_WORDS_GETTER("owneraccount.owner-detail.yuanyin");
	new_remark += dto->remark.getValue({});
	data_ad.setRemark(new_remark);
	// 雪花算法生成detail_id
	data_ad.setDetailId(std::to_string(sf.nextId()));
	// 雪花算法生成order_id
	data_ad.setOrderId(std::to_string(sf.nextId()));
	//detail_type默认为2002
	data_ad.setDetailType("2002");
	//rel_acct_id默认为-1
	data_ad.setRelAcctId("-1");
	// b_id默认为-1
	data_ad.setBId("-1");
	// status_cd默认为0
	data_ad.setStatusCd("0");
	// 生成create_time
	data_ad.setCreateTime(SimpleDateTimeFormat::format());

	// 执行
	// account_detail表添加
	OwnerDetailDAO dao_ad;
	//dao_ad.OwnerDetail_undo_insert_account_detail(data_ad) == 1 ? data_ad.getDetailId() : "";
	if (dao_ad.OwnerDetail_undo_insert_account_detail(data_ad) == 1) {
		new_detail_id = data_ad.getDetailId();
	}
	else {
		new_detail_id = "";
		return new_detail_id;
	}
	//account_detail表修改
	OwnerDetailDAO dao_ad_u;
	dao_ad_u.OwnerDetail_undo_update_account_detail(data_ad);

	// account表
	OwnerDetailDAO dao_a;
	dao_a.OwnerDetail_undo_update_account(data_ad);

	//返回运行结果（新id）
	return new_detail_id;
}