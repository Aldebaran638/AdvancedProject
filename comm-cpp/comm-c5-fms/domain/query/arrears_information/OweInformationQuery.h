#ifndef _OWEINFORMATIONQUERY_H_
#define _OWEINFORMATIONQUERY_H_

#include "../../GlobalInclude.h"
#include "../../../../lib-oatpp/include/domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class OweInformationQuery : public PageQuery
{
	DTO_INIT(OweInformationQuery, PageQuery);
	DTO_FIELD(String, b_id);
	DTO_FIELD_INFO(b_id) {
		info->description = ZH_WORDS_GETTER("owe.building");
	}
	DTO_FIELD(String, unit_num);
	DTO_FIELD_INFO(unit_num) {
		info->description = ZH_WORDS_GETTER("owe.unit");
	}
	DTO_FIELD(String, room_id);
	DTO_FIELD_INFO(room_id) {
		info->description = ZH_WORDS_GETTER("owe.home");
	}
	DTO_FIELD(String, b_type);
	DTO_FIELD_INFO(b_type) {
		info->description = ZH_WORDS_GETTER("owe.b_type");
	}
	DTO_FIELD(String, owner_name);
	DTO_FIELD_INFO(owner_name) {
		info->description = ZH_WORDS_GETTER("owe.owner_name");
	}
	DTO_FIELD(String, payer_obj_type);
	DTO_FIELD_INFO(payer_obj_type) {
		info->description = ZH_WORDS_GETTER("owe.payer_obj_type");
	}
	DTO_FIELD(String, fee_id);
	DTO_FIELD_INFO(fee_id) {
		info->description = ZH_WORDS_GETTER("owe.fee");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_OWEINFORMATIONQUERY_H_