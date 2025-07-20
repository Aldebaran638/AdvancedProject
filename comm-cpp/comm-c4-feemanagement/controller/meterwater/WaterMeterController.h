#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _WATERMETERCONTROLLER_H_
#define _WATERMETERCONTROLLER_H_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/meterwater/WaterMeterDO.h"
#include "domain/query/meterwater/WaterMeterQuery.h"
#include "domain/dto/meterwater/WaterMeterDTO.h"
#include "domain/vo/meterwater/WaterMeterVO.h"



// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ˮ�糭��������
 */
class WaterMeterController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(WaterMeterController);
	// ����ӿ�
public:
	// �����ѯˮ�糭���ӿ�����
	ENDPOINT_INFO(queryMeter) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("get.summary"), WaterMeterPageJsonVO::Wrapper);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "water_id", ZH_WORDS_GETTER("watermeter.meterid"), "102025051598760067", false);
		API_DEF_ADD_QUERY_PARAMS(String, "meter_type", ZH_WORDS_GETTER("watermeter.metertype"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "obj_name", ZH_WORDS_GETTER("watermeter.roomid"), "1-1-101", false);
	}
	// �����ҳ��ѯˮ�糭���ӿڴ���
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/c4-watermeter/query-page", queryMeter, WaterMeterQuery, executeQueryMeter(query));


	// ����ɾ��ˮ�糭���ӿ�����
	ENDPOINT_INFO(removeMeter) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("remove.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// ����ɾ��ˮ�糭���ӿڴ���
	ENDPOINT("DELETE", "/c4-watermeter/remove-meter", removeMeter, BODY_DTO(WaterMeterDeleteDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(executeRemoveMeter(dto, authObject->getPayload()));
	}

	// �����޸�ˮ�糭���ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("put.summary"), modifyMeter, StringJsonVO::Wrapper);
	// �����޸�ˮ�糭���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-watermeter/modify-meter", modifyMeter, BODY_DTO(WaterMeterDTO::Wrapper, dto), executeModifyMeter(dto, authObject->getPayload()));


	// ��������ˮ�糭���ӿ�����
	ENDPOINT_INFO(addMeter) {
		// ����ӿ�ͨ����Ϣ
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("add.summary"), StringJsonVO::Wrapper);
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
	}
	// ��������ˮ�糭���ӿڴ���
	ENDPOINT(API_M_POST, "/c4-watermeter/add-meter", addMeter, BODY_DTO(WaterMeterAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeAddMeter(dto, authObject->getPayload()));
	}


private:
	// ��ѯ����
	WaterMeterPageJsonVO::Wrapper executeQueryMeter(const WaterMeterQuery::Wrapper& query);
	// ɾ������
	StringJsonVO::Wrapper executeRemoveMeter(const WaterMeterDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
	// �޸ĳ���
	StringJsonVO::Wrapper executeModifyMeter(const WaterMeterDTO::Wrapper& dto, const PayloadDTO& payload);
	// ���ӳ���
	StringJsonVO::Wrapper executeAddMeter(const WaterMeterAddDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _WATERMETERCONTROLLER_H_