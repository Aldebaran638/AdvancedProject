#pragma once
#ifndef _FEERATEQUERY_H_
#define _FEERATEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"  // 分页基类
#include "../lib-oatpp/include/ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//--------------- 楼栋收费率查询条件 ---------------
class BuildingRateQuery : public PageQuery
{
	DTO_INIT(BuildingRateQuery, PageQuery);

	// 楼栋ID（支持多选，格式："A1,B2,C3"）
	API_DTO_FIELD_DEFAULT(String, buildingName, ZH_WORDS_GETTER("fee-summary.buildingIds"));

	// 统计周期结束时间
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("fee-summary.startDate"));

	// 统计周期结束时间
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("fee-summary.endDate"));

	// 新增字段：业主名称（支持模糊匹配，格式："张*"或"王%"）
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("fee-summary.ownerName"));

	// 新增字段：业主手机号（精确匹配）
	API_DTO_FIELD_DEFAULT(String, ownerNumber, ZH_WORDS_GETTER("fee-summary.ownerNumber"));

	// 新增字段：小区ID（支持多选，格式："1001,1002"）
	API_DTO_FIELD_DEFAULT(String, communityIds, ZH_WORDS_GETTER("fee-summary.communityIds"));

	// 新增字段：费用类型（多选，格式："电费,燃气费,物业费"）
	API_DTO_FIELD_DEFAULT(String, feeTypes, ZH_WORDS_GETTER("fee-summary.feeTypes"));

	// 房间ID（支持多选，格式："A1,B2,C3"）
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("fee-summary.roomNum"));

};





//--------------- 费用项收费率查询条件 ---------------
class FeeItemRateQuery : public PageQuery
{
	DTO_INIT(FeeItemRateQuery, PageQuery);

	// 楼栋ID（支持多选，格式："A1,B2,C3"）
	API_DTO_FIELD_DEFAULT(String, buildingName, ZH_WORDS_GETTER("fee-summary.buildingIds"));

	// 统计周期结束时间
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("fee-summary.startDate"));

	// 统计周期结束时间
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("fee-summary.endDate"));

	// 新增字段：业主名称（支持模糊匹配，格式："张*"或"王%"）
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("fee-summary.ownerName"));

	// 新增字段：业主手机号（精确匹配）
	API_DTO_FIELD_DEFAULT(String, ownerNumber, ZH_WORDS_GETTER("fee-summary.ownerNumber"));

	// 新增字段：小区ID（支持多选，格式："1001,1002"）
	API_DTO_FIELD_DEFAULT(String, communityIds, ZH_WORDS_GETTER("fee-summary.communityIds"));

	// 新增字段：费用类型（多选，格式："电费,燃气费,物业费"）
	API_DTO_FIELD_DEFAULT(String, feeTypes, ZH_WORDS_GETTER("fee-summary.feeTypes"));

	// 房间ID（支持多选，格式："A1,B2,C3"）
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("fee-summary.roomNum"));
};

/////////////
//分页查询对象
class ExpeSumQuery :public oatpp::DTO
{
	DTO_INIT(ExpeSumQuery, DTO);
	//时间
	API_DTO_FIELD_DEFAULT(String, timeBegin, ZH_WORDS_GETTER("expesum.timebegin"));
	API_DTO_FIELD_DEFAULT(String, timeEnd, ZH_WORDS_GETTER("expesum.timeend"));

	//业主名字
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("expesum.ownerName"));
	//房屋编号	
	API_DTO_FIELD_DEFAULT(String, buildNumber, ZH_WORDS_GETTER("expesum.buildNumber"));
	//业主手机号
	API_DTO_FIELD_DEFAULT(String, ownerPhone, ZH_WORDS_GETTER("expesum.ownerPhone"));

};


#include OATPP_CODEGEN_END(DTO)

#endif // !_FEERATEQUERY_H_