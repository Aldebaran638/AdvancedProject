#pragma once
#ifndef _CODE_DEV_HOUSE_PAY_FEE_CONTROLLER_H_
#define _CODE_DEV_HOUSE_PAY_FEE_CONTROLLER_H_

#include "ApiHelper.h"

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/GlobalInclude.h"
#include "../../domain/dto/HouseFeeDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
class HousePayFeeController :public oatpp::web::server::api::ApiController
{
	//设置授权处理器 + 序列化映射器
	API_ACCESS_DECLARE(HousePayFeeController);

public:
	ENDPOINT_INFO(addHouseFee) {
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house_fee.add.title"));
		//定义默认授权参数
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Int32JsonVO);

		////增加注释
		API_DEF_ADD_QUERY_PARAMS(String, "house_id", ZH_WORDS_GETTER("house_fee.add.house_id"), "001-001-01", true);
		API_DEF_ADD_QUERY_PARAMS(String, "fee_type", ZH_WORDS_GETTER("house_fee.add.fee_type"), ZH_WORDS_GETTER("house_fee.add.fee_type_default"), true);
		API_DEF_ADD_QUERY_PARAMS(String, "charge_project", ZH_WORDS_GETTER("house_fee.add.charge_project"), ZH_WORDS_GETTER("house_fee.add.charge_project_default"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("house_fee.add.start_time"), "2025-01-12", true);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("house_fee.add.end_time"), "2025-01-12", true);
		API_DEF_ADD_QUERY_PARAMS(Float64, "amount", ZH_WORDS_GETTER("house_fee.add.amount"), 100.0, false);
		API_DEF_ADD_QUERY_PARAMS(String, "config_id", ZH_WORDS_GETTER("house_fee.add.config_id"), "92202305221013595234000152", true);
	}
	/*eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdXRob3JpdGllcyI6WyJTVVBFUl9BRE1JTiJdLCJleHAiOjE3NDkxOTYyMjYsImlkIjoiMSIsInVzZXJfbmFtZSI6InJvdW1pb3UifQ.jSt8mooUq2LRukoGaAxq2bNXqQQJf6myBAo_yeLewbeYxXGOxhsG1ae-2nxDBed4TKHnGLB5W_-hQMe1rIdwpu_lrUFK1lAjzYSNYqr_EzSxDQYPCom8mKOiIwtLNv7UFtMRk91jHWXO7tNt4LzE3Hes6CGF0V9gOVS1T0H7F2FWOiG7_7o_5zaJ4EDK8L3hBeycwYTLqUAf8qFQ60-uDVRvwlt7w4MG69uJitRWt6O92KvKaOnnswmILN0QKU33160XZy9uGCCOCzX_x-_wvHCYL5K1VdHQji8K2vPxuMUSZYlgaZ0pA8PI4jxH9LFc7IhwkTtUI83sZ4n2W6Pohg*/
	ENDPOINT(API_M_POST, "/c3-housefeemgr/add-housefee", addHouseFee, BODY_DTO(AddHouseFeeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		auto vo = Int32JsonVO::createShared();
		vo->fail(0);

		bool flag = false;
		flag = true;
		auto payload = std::make_shared<PayloadDTO>(authObject->getPayload());
		//权限校验
		for (const auto& i : payload->getAuthorities())
		{
			if (i == "SUPER_ADMIN")
				flag = true;
		}


		
		if (flag)
		{
			execAddHouseFee(dto, payload);
			API_HANDLER_RESP_VO(execAddHouseFee(dto, payload));
		}
		API_HANDLER_RESP_VO(vo);
	}
	
	ENDPOINT_INFO(modifyHouseFee)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house_fee.modify.title"));
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Int32JsonVO);

		//
		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("house_fee.modify.fee_id"), "12238832129789792256", true);
		API_DEF_ADD_QUERY_PARAMS(String, "create_time", ZH_WORDS_GETTER("house_fee.modify.create_time"), "2025-05-21 00:00:00", true);
		API_DEF_ADD_QUERY_PARAMS(String, "start_time", ZH_WORDS_GETTER("house_fee.modify.start_time"), "2025-05-21 23:59:55", true);
		API_DEF_ADD_QUERY_PARAMS(String, "end_time", ZH_WORDS_GETTER("house_fee.modify.end_time"), "2025-05-21 23:59:59", true);

	}
	ENDPOINT(API_M_POST, "/c3-housefeemgr/modify-housefee", modifyHouseFee, BODY_DTO(ModifyHouseFeeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		auto vo = Int32JsonVO::createShared();
		auto payload = std::make_shared<PayloadDTO>(authObject->getPayload());
		API_HANDLER_RESP_VO(execModifyHouseFee(dto,payload));
	}


	ENDPOINT_INFO(delHouseFee)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house_fee.reduce.title"));
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Int32JsonVO);

		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("house_fee.modify.fee_id"), "902025052181251299", true);
	}
	ENDPOINT(API_M_DEL, "/c3-housefeemgr/delete-housefee", delHouseFee, BODY_DTO(HouseFeeIdDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		auto vo = Int32JsonVO::createShared();
		vo->fail(0);
		// 传入一个fee_id --> 不需要数据校验

		auto payload = std::make_shared<PayloadDTO>(authObject->getPayload());
		bool flag = false;

		//权限校验
		for (const auto& i : payload->getAuthorities())
		{
			if (i == "SUPER_ADMIN") 
				flag = true;
		}
		if (flag)
		{
			API_HANDLER_RESP_VO(execDelHouseFee(dto, payload));
		}

		vo->message = "数据校验失败";
		API_HANDLER_RESP_VO(vo);
	}


	ENDPOINT_INFO(PayHouseFee)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("house_fee.pay.title"));
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Int32JsonVO);

		API_DEF_ADD_QUERY_PARAMS(String, "fee_id", ZH_WORDS_GETTER("house_fee.modify.fee_id"), "902025052181251299", true);
		API_DEF_ADD_QUERY_PARAMS(Int32, "cycle", ZH_WORDS_GETTER("house_fee.pay.cycle"), 1, true);
		API_DEF_ADD_QUERY_PARAMS(Int32, "real_cycle", ZH_WORDS_GETTER("house_fee.pay.real_cycle"), 101, false);
		API_DEF_ADD_QUERY_PARAMS(String, "pay_fee_start_time", ZH_WORDS_GETTER("house_fee.pay.pay_fee_start_tim"), "2025-02-21", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pay_fee_end_time", ZH_WORDS_GETTER("house_fee.pay.pay_fee_end_time"), "2025-02-21", false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "amount_due", ZH_WORDS_GETTER("house_fee.pay.amount_due"), 110.0, true);
		API_DEF_ADD_QUERY_PARAMS(Float32, "pay_amount", ZH_WORDS_GETTER("house_fee.pay.pay_amount"), 110.0, true);
		API_DEF_ADD_QUERY_PARAMS(Float32, "amount", ZH_WORDS_GETTER("house_fee.pay.amount"), 110.0, true);
		API_DEF_ADD_QUERY_PARAMS(String, "remark", ZH_WORDS_GETTER("house_fee.pay.remark"), ZH_WORDS_GETTER("house_fee.pay.remark_default"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "community_id", ZH_WORDS_GETTER("house_fee.add.community_id"), "752023063035460053", true);
		API_DEF_ADD_QUERY_PARAMS(Boolean, "flag", ZH_WORDS_GETTER("house_fee.pay.flag"), false, true);
		API_DEF_ADD_QUERY_PARAMS(String, "account_type", ZH_WORDS_GETTER("account.info.type"), "752023063035460053", false);
		API_DEF_ADD_QUERY_PARAMS(String, "account_name", ZH_WORDS_GETTER("account.info.name"), "752023063035460053", false);
		API_DEF_ADD_QUERY_PARAMS(Float32, "account_amount", ZH_WORDS_GETTER("account.info.amount"), 110.0, false);
	}
	ENDPOINT(API_M_POST, "/c3-housefeemgr/pay-fee", PayHouseFee, BODY_DTO(PayFeeDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		
		auto vo = Int32JsonVO::createShared();
		vo->fail(0);
		// 传入一个fee_id --> 不需要数据校验

		auto payload = std::make_shared<PayloadDTO>(authObject->getPayload());
		bool flag = false;

		//权限校验
		for (const auto& i : payload->getAuthorities())
		{
			if (i == "SUPER_ADMIN")
				flag = true;
		}
		if (flag)
		{
			API_HANDLER_RESP_VO(execPayFee(dto, payload));
		}

		vo->message = u8"数据校验失败";
		API_HANDLER_RESP_VO(vo);
	}


	//增加費用
	Int32JsonVO::Wrapper execAddHouseFee(const AddHouseFeeDTO::Wrapper& houseFee, const std::shared_ptr<PayloadDTO> payload);

	//修改费用
	Int32JsonVO::Wrapper execModifyHouseFee(const ModifyHouseFeeDTO::Wrapper& modifyInfo, const std::shared_ptr<PayloadDTO> payload);

	Int32JsonVO::Wrapper execDelHouseFee(const HouseFeeIdDTO::Wrapper& delInfo, const std::shared_ptr<PayloadDTO> payload);

	Int32JsonVO::Wrapper execPayFee(const PayFeeDTO::Wrapper& pay, const std::shared_ptr<PayloadDTO> payload);
};
#include OATPP_CODEGEN_END(ApiController)
#endif 
