#pragma once

#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例新增数据传输对象
 */
class CommunitySpaceMgrAddDTO : public oatpp::DTO
{
	DTO_INIT(CommunitySpaceMgrAddDTO, DTO);
	// 场地id
	DTO_FIELD(String, space_id);
	DTO_FIELD_INFO(space_id) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.space_id");
	}
	// 场地名称
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
	DTO_FIELD(Int32, fee_money);
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
	
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
/**
 * 示例传输对象
 */
class CommunitySpaceMgrDTO : public CommunitySpaceMgrAddDTO
{
	DTO_INIT(CommunitySpaceMgrDTO, CommunitySpaceMgrAddDTO);
	// 编号
	//DTO_FIELD(String, b_id);
	//DTO_FIELD_INFO(b_id) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.b_id");
	//}
	//DTO_FIELD(String, community_id);	
	//DTO_FIELD_INFO(community_id) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.community_id");
	//}

	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.state");
	}
	
	//DTO_FIELD(String, status_cd);
	//DTO_FIELD_INFO(status_cd) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.status_cd");
	//}
    //DTO_FIELD(String, venue_id);
	//DTO_FIELD_INFO(venue_id) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.venue_id");
	//}
	//DTO_FIELD(String, create_time);
	//DTO_FIELD_INFO(create_time) {
	//	info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.create_time");
	//}
	
};
/**
 * 示例分页传输对象
 */
class CommunitySpaceMgrPageDTO : public PageDTO<CommunitySpaceMgrDTO::Wrapper>
{
	DTO_INIT(CommunitySpaceMgrPageDTO, PageDTO<CommunitySpaceMgrDTO::Wrapper>);
};




//----------------------------------------------------------------------------------------------------------




/**
 * 示例新增数据传输对象
 */
class CommunitySpaceTimeMgrAddDTO : public oatpp::DTO
{
	DTO_INIT(CommunitySpaceTimeMgrAddDTO, DTO);
	// 场地名称
	
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
	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 示例传输对象
 */
class CommunitySpaceTimeMgrDTO : public CommunitySpaceTimeMgrAddDTO
{
	DTO_INIT(CommunitySpaceTimeMgrDTO, CommunitySpaceTimeMgrAddDTO);

	DTO_FIELD(String, time_id);
	DTO_FIELD_INFO(time_id) {
		info->description = ZH_WORDS_GETTER("CommunitySpaceMgr.field.time_id");
	}
};

/**
 * 示例分页传输对象
 */
class CommunitySpaceTimeMgrPageDTO : public PageDTO<CommunitySpaceTimeMgrDTO::Wrapper>
{
	DTO_INIT(CommunitySpaceTimeMgrPageDTO, PageDTO<CommunitySpaceTimeMgrDTO::Wrapper>);
	
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
