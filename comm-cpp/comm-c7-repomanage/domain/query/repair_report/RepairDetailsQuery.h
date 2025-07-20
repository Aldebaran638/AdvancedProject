#pragma once

#ifndef _Repair_Statistics_QUERY_
#define _Repair_Statistics_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报修明细查询对象
 */
class RepairDetailsQuery : public PageQuery
{
	DTO_INIT(RepairDetailsQuery, PageQuery);

	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("alex.repair.community_id"));	//社区号

	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("alex.repair.start_time"));		// 开始时间
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("alex.repair.end_time"));			// 结束时间
	API_DTO_FIELD_DEFAULT(String, workOrderId, ZH_WORDS_GETTER("alex.repair.work_order_id"));	//工单号
	API_DTO_FIELD_DEFAULT(String, repairType, ZH_WORDS_GETTER("alex.repair.repair_type"));	//报修类型
	API_DTO_FIELD_DEFAULT(String, requesterName, ZH_WORDS_GETTER("alex.repair.requester_name"));	//报修人
	API_DTO_FIELD_DEFAULT(String, requestLocation, ZH_WORDS_GETTER("alex.repair.request_location"));	//报修位置
	API_DTO_FIELD_DEFAULT(String, requesterTelephone, ZH_WORDS_GETTER("alex.repair.requester_telephone"));	//报修电话
	API_DTO_FIELD_DEFAULT(String, workOrderStatus, ZH_WORDS_GETTER("alex.repair.work_order_status"));	//工单状态
	API_DTO_FIELD_DEFAULT(String, requestTime, ZH_WORDS_GETTER("alex.repair.request_time"));	//报修时间
	API_DTO_FIELD_DEFAULT(String, previousProcessor, ZH_WORDS_GETTER("alex.repair.previous_processor"));	//上一处理人
	API_DTO_FIELD_DEFAULT(String, currentProcessor, ZH_WORDS_GETTER("alex.repair.current_processor"));	//当前处理人
	API_DTO_FIELD_DEFAULT(String, dispatchingTime, ZH_WORDS_GETTER("alex.repair.dispatching_time"));	//派单时间
	API_DTO_FIELD_DEFAULT(String, handleTime, ZH_WORDS_GETTER("alex.repair.handle_time"));	//处理时间
	API_DTO_FIELD_DEFAULT(String, processorStatus, ZH_WORDS_GETTER("alex.repair.processor_status"));	//处理人状态
	API_DTO_FIELD_DEFAULT(String, requestContent, ZH_WORDS_GETTER("alex.repair.request_content"));	//报修内容

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_Repair_Statistics_QUERY_