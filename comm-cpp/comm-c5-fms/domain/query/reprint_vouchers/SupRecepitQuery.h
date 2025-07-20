#pragma once
#ifndef _SUP_RECEPIT_QUERY_
#define _SUP_RECEPIT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SupRecepitQuery : public PageQuery {
	DTO_INIT(SupRecepitQuery, PageQuery);
	//收据id
	DTO_FIELD(String, recepitId);
	DTO_FIELD_INFO(recepitId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.recepitid");
	}
	//车位或房屋信息
	DTO_FIELD(String, message);
	DTO_FIELD_INFO(message) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.message");
	}
	// 房屋费/车位费
	DTO_FIELD(String, feeTypeDetail);
	DTO_FIELD_INFO(feeTypeDetail) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.feetypedetail");
	}
	//开始时间
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.starttime");
	}
	//结束时间
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.field.endtime");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
