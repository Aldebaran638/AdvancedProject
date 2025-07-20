#pragma once
#ifndef _REPAIRTODOVO_H_
#define _REPAIRTODOVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/repair-todo/RepairToDoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义报修待办显示JsonVO对象，用于响应给客户端
 */
class RepairToDoJsonVO : public JsonVO<RepairToDoDTO::Wrapper>
{
	DTO_INIT(RepairToDoJsonVO, JsonVO<RepairToDoDTO::Wrapper>);
};

/**
 * 定义报修待办分页显示JsonVO对象，用于响应给客户端
 */
class RepairToDoPageJsonVO : public JsonVO<RepairToDoPageDTO::Wrapper>
{
	DTO_INIT(RepairToDoPageJsonVO, JsonVO<RepairToDoPageDTO::Wrapper>);
};


/**
 * 定义报修待办分页显示JsonVO对象，用于响应给客户端
 */
class RepairToDoQueryAllRepairTypePageJsonVO : public JsonVO<RepairToDoQueryAllRepairTypePageDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllRepairTypePageJsonVO, JsonVO<RepairToDoQueryAllRepairTypePageDTO::Wrapper>);
};

/**
 * 定义报修师傅分页显示JsonVO对象，用于响应给客户端
 */
class RepairToDoQueryAllStaffPageJsonVO : public JsonVO<RepairToDoQueryAllStaffPageDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllStaffPageJsonVO, JsonVO<RepairToDoQueryAllStaffPageDTO::Wrapper>);
};

/**
 * 定义报修师傅分页显示JsonVO对象，用于响应给客户端
 */
class RepairToDoQueryAllStaffJsonVO : public JsonVO<RepairToDoQueryAllStaffDTO::Wrapper>
{
	DTO_INIT(RepairToDoQueryAllStaffJsonVO, JsonVO<RepairToDoQueryAllStaffDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // ! _REPAIRTODOVO_H_