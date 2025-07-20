#pragma once
#ifndef _REPAIRSETTINGDTO_H_
#define _REPAIRSETTINGDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个获取报修设置类型列表的数据传输模型
 */
class RepairSettingGetDTO : public oatpp::DTO
{
	DTO_INIT(RepairSettingGetDTO, DTO);
	// 类型名称
	API_DTO_FIELD_DEFAULT(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypename"));

	// 报修类型设置(yaml没加)(新)
	API_DTO_FIELD_DEFAULT(String, repair_setting_type, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypesetting"));

	// 派单方式 100 抢单 200 指派 300 轮训
	API_DTO_FIELD_DEFAULT(String, repair_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.rway"));

	// 区域
	API_DTO_FIELD_DEFAULT(String, public_area, ZH_WORDS_GETTER("repairsetting.repair-mysql.cid"));

	// 业主段展示（新）
	API_DTO_FIELD_DEFAULT(String, is_show, ZH_WORDS_GETTER("repairsetting.repair-mysql.ishow"));

	// 通知方式（新）
	API_DTO_FIELD_DEFAULT(String, notify_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.nway"));

	// 是否回访 回访标识 001 都不回访 002 已评价不回访 003 都回访
	API_DTO_FIELD_DEFAULT(String, return_visit_flag, ZH_WORDS_GETTER("repairsetting.repair-mysql.rvisitflag"));

	// 创建时间（新）
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("repairsetting.repair-mysql.ctime"));

};

class RepairSettingGetPageDTO : public PageDTO<RepairSettingGetDTO::Wrapper>
{
	DTO_INIT(RepairSettingGetPageDTO, PageDTO<RepairSettingGetDTO::Wrapper>);
};

/**
 * 定义一个添加报修设置类型的数据传输模型
 */
class RepairSettingAddDTO : public oatpp::DTO
{
	DTO_INIT(RepairSettingAddDTO, DTO);
	// 类型名称
	API_DTO_FIELD(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypename"), true, ZH_WORDS_GETTER("repairsetting.repair-default.rtname"));
	// 报修类型设置 维修单200
	API_DTO_FIELD(String, repair_setting_type, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypesetting"), true, "200");
	// 派单方式 100 抢单 200 指派 300 轮训
	API_DTO_FIELD(String, repair_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.rway"), true, "200");
	// 公共区域(public_area)
	API_DTO_FIELD(String, public_area, ZH_WORDS_GETTER("repairsetting.repair-mysql.parea"), true, "F");
	// 业主端展示 Y 是  N 否
	API_DTO_FIELD(String, is_show, ZH_WORDS_GETTER("repairsetting.repair-mysql.ishow"), true, "Y");
	// 通知方式，SMS 短信 WECHAT 微信
	API_DTO_FIELD(String, notify_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.nway"), true, "WECHAT");
	// 是否回访 回访标识 001 都不回访 002 已评价不回访 003 都回访
	API_DTO_FIELD(String, return_visit_flag, ZH_WORDS_GETTER("repairsetting.repair-mysql.rvisitflag"), true, "003");
	// 社区id
	API_DTO_FIELD(String, community_id, ZH_WORDS_GETTER("repairsetting.repair-mysql.cid"), true, "2024022154856948");
	// 说明(新)
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repairsetting.repair-mysql.remark"), false, ZH_WORDS_GETTER("repairsetting.repair-default.remark"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 定义一个添加报修设置类型分页传输对象
 */
class RepairSettingAddPageDTO : public PageDTO<RepairSettingAddDTO::Wrapper>
{
	DTO_INIT(RepairSettingAddPageDTO, PageDTO<RepairSettingAddDTO::Wrapper>);
};

/**
 * 定义一个修改报修类型的数据传输模型
 */
class RepairSettingModifyDTO : public oatpp::DTO
{
	DTO_INIT(RepairSettingModifyDTO, DTO);

	// 唯一标识 工单设置ID
	API_DTO_FIELD(String, setting_id, ZH_WORDS_GETTER("repairsetting.repair-mysql.sid"), true, ZH_WORDS_GETTER("repairsetting.repair-default.sid"));
	// 类型名称
	API_DTO_FIELD(String, repair_type_name, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypename"), true, ZH_WORDS_GETTER("repairsetting.repair-default.rtname"));
	// 报修类型设置 维修单200
	API_DTO_FIELD(String, repair_setting_type, ZH_WORDS_GETTER("repairsetting.repair-mysql.retypesetting"), true, "200");
	// 派单方式 100 抢单 200 指派 300 轮训
	API_DTO_FIELD(String, repair_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.rway"), true, "200");
	// 公共区域(public_area)
	API_DTO_FIELD(String, public_area, ZH_WORDS_GETTER("repairsetting.repair-mysql.parea"), true, "F");
	// 业主端展示 Y 是  N 否
	API_DTO_FIELD(String, is_show, ZH_WORDS_GETTER("repairsetting.repair-mysql.ishow"), true, "Y");
	// 通知方式，SMS 短信 WECHAT 微信
	API_DTO_FIELD(String, notify_way, ZH_WORDS_GETTER("repairsetting.repair-mysql.nway"), true, "WECHAT");
	// 是否回访 回访标识 001 都不回访 002 已评价不回访 003 都回访
	API_DTO_FIELD(String, return_visit_flag, ZH_WORDS_GETTER("repairsetting.repair-mysql.rvisitflag"), true, "003");
	// 说明(新)
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("repairsetting.repair-mysql.remark"), false, ZH_WORDS_GETTER("repairsetting.repair-default.remark"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 定义一个修改报修类型的分页传输对象
 */
class RepairSettingModifyPageDTO : public PageDTO<RepairSettingModifyDTO::Wrapper>
{
	DTO_INIT(RepairSettingModifyPageDTO, PageDTO<RepairSettingModifyDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRSETTINGDTO_H_