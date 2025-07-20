#pragma once
#ifndef _REPAIRSETTINGVO_H_
#define _REPAIRSETTINGVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/repair-setting-type/RepairSettingTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个获取详细报修设置类型列表的数据的JsonVO对象，用于响应给客户端
 */
class DetailRepairSettingGetJsonVO : public JsonVO<RepairSettingGetDTO::Wrapper>
{
	DTO_INIT(DetailRepairSettingGetJsonVO, JsonVO<RepairSettingGetDTO::Wrapper>);
};

/**
 * 定义一个获取报修设置类型列表的数据的分页显示JsonVO对象，用于响应给客户端
 */
class RepairSettingGetPageJsonVO : public JsonVO<RepairSettingGetPageDTO::Wrapper>
{
	DTO_INIT(RepairSettingGetPageJsonVO, JsonVO<RepairSettingGetPageDTO::Wrapper>);
};

/**
 * 定义一个添加报修设置的JsonVO对象，用于响应给客户端
 */
class RepairSettingAddJsonVo : public JsonVO<RepairSettingAddDTO::Wrapper>
{
	DTO_INIT(RepairSettingAddJsonVo, JsonVO<RepairSettingAddDTO::Wrapper>);
};

/**
 * 定义一个添加报修设置的分页显示JsonVO对象，用于响应给客户端
 */
class RepairSettingPageAddJsonVo : public JsonVO<RepairSettingAddPageDTO::Wrapper>
{
	DTO_INIT(RepairSettingPageAddJsonVo, JsonVO<RepairSettingAddPageDTO::Wrapper>);
};

/**
 * 定义一个修改报修设置JsonVO对象，用于响应给客户端
 */
class RepairSettingModifyJsonVO : public JsonVO<RepairSettingModifyDTO::Wrapper>
{
	DTO_INIT(RepairSettingModifyJsonVO, JsonVO<RepairSettingModifyDTO::Wrapper>);
};

/**
 * 定义一个修改报修设置分页显示JsonVO对象，用于响应给客户端
 */
class RepairSettingModifyPageJsonVo : public JsonVO<RepairSettingModifyPageDTO::Wrapper>
{
	DTO_INIT(RepairSettingModifyPageJsonVo, JsonVO<RepairSettingModifyPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _REPAIRSETTINGVO_H_