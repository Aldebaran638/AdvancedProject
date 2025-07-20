#pragma once
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class CommunitySpaceMgrPageQuery : public PageQuery
{
	DTO_INIT(CommunitySpaceMgrPageQuery, PageQuery);
	//
	DTO_FIELD(String, space_id);
	DTO_FIELD_INFO(space_id) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.space_id");
	}
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.name");
	}
	
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.start_time");
	}
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(end_time) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.end_time");
	}
	DTO_FIELD(Float64, fee_money);
	DTO_FIELD_INFO(fee_money) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.fee_money");
	}
	DTO_FIELD(String, admin_name);
	DTO_FIELD_INFO(admin_name) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.admin_name");
	}
	DTO_FIELD(String, tel);
	DTO_FIELD_INFO(tel) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.tel");
	}
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.state");
	}
	//DTO_FIELD(String, community_id);
	//DTO_FIELD_INFO(community_id) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.community_id");
	//}
	//DTO_FIELD(String, venue_id);
	//DTO_FIELD_INFO(venue_id) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.venue_id");
	//}
	//DTO_FIELD(String, status_cd);
	//DTO_FIELD_INFO(status_cd) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.status_cd");
	//}
	////DTO_FIELD(String, create_time);
	////DTO_FIELD_INFO(create_time) {
	////	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.create_time");
	////}
	//DTO_FIELD(String, b_id);
	//DTO_FIELD_INFO(b_id) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.b_id");
	//}
};



class CommunitySpaceTimeMgrPageQuery : public PageQuery
{
	DTO_INIT(CommunitySpaceTimeMgrPageQuery, PageQuery);

	DTO_FIELD(String, space_id);
	DTO_FIELD_INFO(space_id) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.space_id");
	}
	DTO_FIELD(Int32, hours);
	DTO_FIELD_INFO(hours) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.hours");
	}
	DTO_FIELD(String, is_open);
	DTO_FIELD_INFO(is_open) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.is_open");
	}
	DTO_FIELD(String, time_id);
	DTO_FIELD_INFO(time_id) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.time_id");
	}
	//DTO_FIELD(String, b_id);
	//DTO_FIELD_INFO(b_id) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.b_id");
	//}
	//DTO_FIELD(String, status_cd);
	//DTO_FIELD_INFO(status_cd) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.status_cd");
	//}
	////DTO_FIELD(String, create_time);
	////DTO_FIELD_INFO(create_time) {
	////	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.create_time");
	////}
	//DTO_FIELD(String, community_id);
	//DTO_FIELD_INFO(community_id) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.community_id");
	//}
};


#include OATPP_CODEGEN_END(DTO)
