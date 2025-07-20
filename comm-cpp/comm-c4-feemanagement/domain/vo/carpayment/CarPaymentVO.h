#pragma once

#ifndef _CarPaymentVO_H_
#define _CarPaymentVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/carpayment/CarPaymentDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个用户信息显示JsonVO对象，用于响应给客户端
 */
class CarPaymentJsonVO : public JsonVO<CarPaymentDTO::Wrapper>
{
	DTO_INIT(CarPaymentJsonVO, JsonVO<CarPaymentDTO::Wrapper>);
};

/**
 * 定义一个用户信息分页显示JsonVO对象，用于响应给客户端
 */
class CarPaymentPageJsonVO : public JsonVO<CarPaymentPageDTO::Wrapper>
{
	DTO_INIT(CarPaymentPageJsonVO, JsonVO<CarPaymentPageDTO::Wrapper>);
};
/**
 * 车辆费用信息显示JsonVO对象，用于响应给客户端
 */
class GetVehicleFeeJsonVO : public JsonVO<GetVehicleFeeDTO::Wrapper>
{
    DTO_INIT(GetVehicleFeeJsonVO, JsonVO<GetVehicleFeeDTO::Wrapper>);
};

/**
 * 获取缴费记录分页显示JsonVO对象，用于响应给客户端
 */
class GetPaymentRecordsPageJsonVO : public JsonVO<GetPaymentRecordsPageDTO::Wrapper>
{
    DTO_INIT(GetPaymentRecordsPageJsonVO, JsonVO<GetPaymentRecordsPageDTO::Wrapper>);
};

/**
 * 车辆缴费记录详情显示JsonVO对象，用于响应给客户端
 */
class GetPaymentDetailedRecordJsonVO : public JsonVO<GetPaymentDetailedRecordDTO::Wrapper>
{
    DTO_INIT(GetPaymentDetailedRecordJsonVO, JsonVO<GetPaymentDetailedRecordDTO::Wrapper>);
};

/**
 * 费用配置修改记录分页显示JsonVO对象，用于响应给客户端
 */
class GetFeeModificationRecordsPageJsonVO : public JsonVO<GetFeeModificationRecordsPageDTO::Wrapper>
{
    DTO_INIT(GetFeeModificationRecordsPageJsonVO, JsonVO<GetFeeModificationRecordsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 