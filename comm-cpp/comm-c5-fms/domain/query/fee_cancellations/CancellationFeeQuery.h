#ifndef _CANCELLATIONFEE_QUERY_
#define _CANCELLATIONFEE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费用批次分页查询对象
 */
class CancellationFeeQuery : public PageQuery
{
	DTO_INIT(CancellationFeeQuery, PageQuery);
	//批次号
	API_DTO_FIELD_DEFAULT(String, batchId, ZH_WORDS_GETTER("cancellationfee.field.batchId"));
	//当前状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("cancellationfee.field.state"));
	//创建员工
	API_DTO_FIELD_DEFAULT(String, createUserName, ZH_WORDS_GETTER("cancellationfee.field.createUserName"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_