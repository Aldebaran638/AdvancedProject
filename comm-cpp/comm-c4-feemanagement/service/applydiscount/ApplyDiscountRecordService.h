#pragma once
#ifndef _APPLY_DISCOUNT_RECORD_SERVICE_
#define _APPLY_DISCOUNT_RECORD_SERVICE_
#include "domain/vo/applydiscount/ApplyDiscountRecordVO.h"
#include "domain/query/applydiscount/ApplyDiscountRecordQuery.h"
#include "domain/dto/applydiscount/ApplyDiscountStateDTO.h"
#include "domain/dto/applydiscount/ApplyDiscountRecordDTO.h"
#include "domain/dto/applydiscount/ApplyDiscountDeleteDTO.h"


class ApplyDiscountRecordService
{
public:
	// ��ҳ��ѯ��������
	ApplyDiscountRecordPageDTO::Wrapper listRecord(const ApplyDiscountRecordQuery::Wrapper& query);
	// �޸��Ż�����״̬
	bool updateState(const ApplyDiscountStateDTO::Wrapper& dto);
	// ͨ��IDɾ���Ż�������
	bool removeData(const ApplyDiscountDeleteDTO::Wrapper& id, const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_

