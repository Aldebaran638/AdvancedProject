#include "stdafx.h"
#include "RemitFeeService.h"
#include "../../dao/paysFee/RemitFeeDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

RemitFeePageDTO::Wrapper RemitFeeService::listAll(const RemitFeeQuery::Wrapper& query)
{
	auto pages = RemitFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	RemitFeeDAO dao; 
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}
	pages->total = count;
	pages->calcPages();
	list<RemitFeeDO> result = dao.selectWithPage(query);
	for (RemitFeeDO sub : result)
	{
		auto dto = RemitFeeDTO::createShared();
		try {
			ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, detail_id, DETAIL_ID, 
				receipt_id, RECEIPT_ID,
				pay_obj, PAY_OBJ, 
				cycle, CYCLE, 
				receive_received,RECEIVE_RECEIVED,
				pay_path, PAY_PATH, 
			
				pay_period,PAY_PERIOD,
				receive_id, RECEIVE_ID, 
				status_cd, STATUS_CD, 
				remark, REMARK,
				opt,OPT);
		}
		catch (const std::exception& e) {
			std::cerr << "Exception in ZO_STAR_DOMAIN_DO_TO_DTO: " << e.what() << std::endl;
		}
		pages->addData(dto);

	}
	return pages;
}