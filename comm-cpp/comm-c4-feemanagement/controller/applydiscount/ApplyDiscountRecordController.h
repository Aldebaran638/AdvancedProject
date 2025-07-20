#pragma once
#ifndef __APPLY_DISCOUNT_RECORD_CONTROLLER_H__
#define __APPLY_DISCOUNT_RECORD_CONTROLLER_H__

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/applydiscount/ApplyDiscountRecordVO.h"
#include "domain/dto/applydiscount/ApplyDiscountRecordDTO.h"
#include "domain/dto/applydiscount/ApplyDiscountStateDTO.h"
#include "domain/dto/applydiscount/ApplyDiscountDeleteDTO.h"
#include "domain/query/applydiscount/ApplyDiscountRecordQuery.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �Ż�������ټ�¼������
 */
class ApplyDiscountRecordController : public oatpp::web::server::api::ApiController // �̳п�����
{
	// ����������������
	API_ACCESS_DECLARE(ApplyDiscountRecordController);

	// ����ӿ�
public:
	// ������ټ�¼��ѯ�ӿ�����
	ENDPOINT_INFO(queryRecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("apply-discount.record.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplyDiscountRecordPageJsonVO);

		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "ard_id", ZH_WORDS_GETTER("apply-discount.record.ard-id"),"", true);
	}
	// ������ټ�¼��ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c4-applydiscount/query-record", queryRecord, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(applyDiscountRecordQuery, ApplyDiscountRecordQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryRecord(applyDiscountRecordQuery));
	}

	// ����ɾ���Ż�����ӿ�����
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("apply-discount.remove"), removeApplyDiscount, ListJsonVO<String>::Wrapper);
 	ENDPOINT_INFO(removeApplyDiscount) {
 		// ����ӿڱ���
 		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("apply-discount.remove"));
 		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
 		API_DEF_ADD_AUTH();
 		// ������Ӧ������ʽ
 		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
 	}
	// ����ɾ���Ż�����ӿڴ���
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/applydiscount/remove-apply-discount", removeApplyDiscount, BODY_DTO(ApplyDiscountDeleteDTO::Wrapper, id), execRemoveApplyDiscount(id));
	ENDPOINT(API_M_DEL, "/applydiscount/remove-apply-discount", removeApplyDiscount, BODY_DTO(ApplyDiscountDeleteDTO::Wrapper, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execRemoveApplyDiscount(id, authObject->getPayload()));
	}

	// �����Ż�����״̬�޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("apply-discount.state"), modifyApplyDiscountState, StringJsonVO::Wrapper);
	//ENDPOINT_INFO(modifyApplyDiscountState) {
	//	// ����ӿڱ���
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("apply-discount.state"));
	//	// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
	//	API_DEF_ADD_AUTH();
	//	// ������Ӧ������ʽ
	//	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//	// ����������ѯ��������
	//	API_DEF_ADD_QUERY_PARAMS(String, "ard_id", ZH_WORDS_GETTER("apply-discount.record.ard-id"), "", true);
	//}
	// �����Ż�����״̬�޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c4-applydiscount/modify-discount-state", modifyApplyDiscountState, BODY_DTO(ApplyDiscountStateDTO::Wrapper, dto), execModifyState(dto, authObject->getPayload()));

private:
	// ��ҳ��ѯ�Ż�������ټ�¼����
	ApplyDiscountRecordPageJsonVO::Wrapper execQueryRecord(const ApplyDiscountRecordQuery::Wrapper& query);
	//ɾ���Ż�����
	StringJsonVO::Wrapper execRemoveApplyDiscount(const ApplyDiscountDeleteDTO::Wrapper& id, const PayloadDTO& payload);
	//�޸��Ż�����״̬
	StringJsonVO::Wrapper execModifyState(const ApplyDiscountStateDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _APPLY_DISCOUNT_RECORD_CONTROLLER_H