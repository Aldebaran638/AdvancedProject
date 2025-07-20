#pragma once
#ifndef _OWNERINFO_QUERY_
#define _OWNERINFO_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class IntoHouseQuery : public PageQuery
{
	DTO_INIT(IntoHouseQuery, PageQuery);

	// 主键 关系id
	API_DTO_FIELD_DEFAULT(String, rel_id, ZH_WORDS_GETTER("OwnerInfo.field.rel_id"));
	// 业主ID
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("OwnerInfo.field.owner_id"));
	// 房间ID
	API_DTO_FIELD_DEFAULT(String, room_id, ZH_WORDS_GETTER("OwnerInfo.field.room_id"));
	// 业务ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("OwnerInfo.field.b_id"));
	// 业务状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("OwnerInfo.field.state"));
	// 用户ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("OwnerInfo.field.user_id"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("OwnerInfo.field.remark"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("OwnerInfo.field.create"));
	// 数据状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("OwnerInfo.field.status"));
	// 起租时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("OwnerInfo.field.start_time"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("OwnerInfo.field.end_time"));
};


/**
 * 示例分页查询对象
 */
class OutHouseQuery : public PageQuery
{
	DTO_INIT(OutHouseQuery, PageQuery);
	// 主键 关系id
	API_DTO_FIELD_DEFAULT(String, rel_id, ZH_WORDS_GETTER("OwnerInfo.field.rel_id"));
	// 业主ID
	API_DTO_FIELD_DEFAULT(String, owner_id, ZH_WORDS_GETTER("OwnerInfo.field.owner_id"));
	// 房间ID
	API_DTO_FIELD_DEFAULT(String, room_id, ZH_WORDS_GETTER("OwnerInfo.field.room_id"));
	// 业务ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("OwnerInfo.field.b_id"));
	// 业务状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("OwnerInfo.field.state"));
	// 用户ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("OwnerInfo.field.user_id"));
	// 备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("OwnerInfo.field.remark"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("OwnerInfo.field.create"));
	// 数据状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("OwnerInfo.field.status"));
	// 起租时间
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("OwnerInfo.field.start_time"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("OwnerInfo.field.end_time"));
};

#include OATPP_CODEGEN_END(DTO)
#endif
