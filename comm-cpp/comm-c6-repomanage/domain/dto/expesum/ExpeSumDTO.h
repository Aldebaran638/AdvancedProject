#pragma once
#ifndef _FEERATEDTO_H_
#define _FEERATEDTO_H_

#include "../../GlobalInclude.h"
#include "../lib-oatpp/include/domain/dto/PageDTO.h"
#include "../lib-oatpp/include/ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

//--------------- 楼栋收费率模型 ---------------
/**
 * 楼栋收费率基础模型
 */
class BuildingRateDTO : public oatpp::DTO
{
	DTO_INIT(BuildingRateDTO, DTO);
	// 费用类型（可扩展为枚举：物业费=1, 车位费=2...）
	API_DTO_FIELD_DEFAULT(String, feeTypes, ZH_WORDS_GETTER("fee-summary.feeTypes"));

	// 业主名字（可扩展为枚举：物业费=1, 车位费=2...）
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("fee-summary.ownerName"));

	// 业主电话
	API_DTO_FIELD_DEFAULT(String, ownerNumber, ZH_WORDS_GETTER("fee-summary.ownerNumber"));

	// 小区唯一标识（关联物业管理系统楼栋ID）
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("fee-summary.buildingIds"));

	// 收费率（百分比，如98.5表示98.5%）
	API_DTO_FIELD_DEFAULT(Float32, buildRate, ZH_WORDS_GETTER("fee-summary.buildRate"));

	// 房间号
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("fee-summary.roomNum"));

	// 统计周期（格式：YYYY-MM）
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("fee-summary.startDate"));

	// 统计周期（格式：YYYY-MM）
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("fee-summary.endDate"));

	// 应收总金额（单位：元）
	API_DTO_FIELD_DEFAULT(Float32, curReceivableFee, ZH_WORDS_GETTER("fee-summary.curReceivableFee"));

	// 实收总金额（单位：元） 
	API_DTO_FIELD_DEFAULT(Float32, curReceivedFee, ZH_WORDS_GETTER("fee-summary.curReceivedFee"));

	// 业主名字（可扩展为枚举：物业费=1, 车位费=2...）
	API_DTO_FIELD_DEFAULT(String, buildingName, ZH_WORDS_GETTER("fee-summary.buildingName"));
};
/**
 * 楼栋分页模型（支持按楼栋维度分页查询）
 */
class BuildingRatePageDTO : public PageDTO<BuildingRateDTO::Wrapper>
{
	DTO_INIT(BuildingRatePageDTO, PageDTO<BuildingRateDTO::Wrapper>);
};




// -------------- - 费用项收费率模型-------------- -
/**
 * 费用项分类模型（支持水电费、物业费等20+类型）
 */
class FeeItemRateDTO : public oatpp::DTO
{
	DTO_INIT(FeeItemRateDTO, DTO);

	// 费用类型（可扩展为枚举：物业费=1, 车位费=2...）
	API_DTO_FIELD_DEFAULT(String, feeTypes, ZH_WORDS_GETTER("fee-summary.feeTypes"));

	// 业主名字（可扩展为枚举：物业费=1, 车位费=2...）
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("fee-summary.ownerName"));

	// 业主电话
	API_DTO_FIELD_DEFAULT(String, ownerNumber, ZH_WORDS_GETTER("fee-summary.ownerNumber"));

	// 小区唯一标识（关联物业管理系统楼栋ID）
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("fee-summary.buildingIds"));

	// 收费率（百分比，如98.5表示98.5%）
	API_DTO_FIELD_DEFAULT(Float32, itemRate, ZH_WORDS_GETTER("fee-summary.itemRate"));

	// 房间号
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("fee-summary.roomNum"));

	// 统计周期（格式：YYYY-MM）
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("fee-summary.startDate"));

	// 统计周期（格式：YYYY-MM）
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("fee-summary.endDate"));

	// 应收总金额（单位：元）
	API_DTO_FIELD_DEFAULT(Float32, curReceivableFee, ZH_WORDS_GETTER("fee-summary.curReceivableFee"));

	// 实收总金额（单位：元） 
	API_DTO_FIELD_DEFAULT(Float32, curReceivedFee, ZH_WORDS_GETTER("fee-summary.curReceivedFee"));

	// 业主名字（可扩展为枚举：物业费=1, 车位费=2...）
	API_DTO_FIELD_DEFAULT(String, buildingName, ZH_WORDS_GETTER("fee-summary.buildingName"));
};

/**
 * 费用项分页模型（支持多维度钻取分析^[9]^）
 */
class FeeItemRatePageDTO : public PageDTO<FeeItemRateDTO::Wrapper>
{
	DTO_INIT(FeeItemRatePageDTO, PageDTO<FeeItemRateDTO::Wrapper>);
};


/////////////
// ==================== 费用汇总记录 DTO ====================
class ExpeSumDTO : public oatpp::DTO {

	DTO_INIT(ExpeSumDTO, DTO);

	API_DTO_FIELD_DEFAULT(Int32, totalRoomCount, "expesum.totalRoomCount");
	API_DTO_FIELD_DEFAULT(Int32, feeRoomCount, "expesum.feeRoomCount");
	API_DTO_FIELD_DEFAULT(Int32, oweRoomCount, "expesum.oweRoomCount");
	API_DTO_FIELD_DEFAULT(Float64, hisOweFee, "expesum.hisOweFee");
	API_DTO_FIELD_DEFAULT(Float64, curOweFee, "expesum.curOweFee");
	API_DTO_FIELD_DEFAULT(Float64, curReceivableFee, "expesum.curReceivableFee");
	API_DTO_FIELD_DEFAULT(Float64, curReceivedFee, "expesum.curReceivedFee");
	API_DTO_FIELD_DEFAULT(Float64, hisReceivedFee, "expesum.hisReceivedFee");
	API_DTO_FIELD_DEFAULT(Float64, preReceivedFee, "expesum.preReceivedFee");
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FEERATEDTO_H_