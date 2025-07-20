#ifndef _CANCELLATIONFEESERVICE_H_
#define _CANCELLATIONFEESERVICE_H_
#include"domain/vo/fee_cancellations/CancellationFeeVO.h"
#include"domain/dto/fee_cancellations/CancellationFeeDTO.h"
#include"domain/query/fee_cancellations/CancellationFeeQuery.h"
#include "Macros.h"
#include"domain/do/fee_cancellations/CancellationFeeDO.h"
#include"dao/fee_cancellations/CancellationFeeDAO.h"
#include"dao/fee_cancellations/CancellationFeeMapper.h"
class CancellationFeeService
{
	private:
	//将状态从状态码映射为中文描述
		inline std::string mapperState(const std::string& state);
	public:
	//分页查询所有数据
		CancellationFeePageDTO::Wrapper listAll(const CancellationFeeQuery::Wrapper& query);
	//申请取消
		bool applyCancel(const CancellationFeeApplyDTO::Wrapper & dto);
	//审核取消
		bool auditCancel(const CancellationFeeAuditDTO::Wrapper& dto);
};
#endif