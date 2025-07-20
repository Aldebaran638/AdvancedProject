#pragma once

#ifndef _SUMMFEEQUERY_H_
#define _SUMMFEEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SummfeeQuery : public PageQuery {

	DTO_INIT(SummfeeQuery, PageQuery);
	// Ê±¼ä
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("axing.summ.create_time"))

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_