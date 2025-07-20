#ifndef _UNREPAIRDTO_H_
#define _UNREPAIRDTO_H_

#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 报修未完成的数据类型
*/
class UnrepairDTO :public oatpp::DTO {
	DTO_INIT(UnrepairDTO, DTO);

	//订单号
	API_DTO_FIELD_DEFAULT(String, repairId, ZH_WORDS_GETTER("Unrepair.repairId"));

	//报修开始日期
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("Unrepair.createTime"));

	//报修人
	API_DTO_FIELD_DEFAULT(String, repairName, ZH_WORDS_GETTER("Unrepair.repairName"));

	//报修电话
	API_DTO_FIELD_DEFAULT(String, tel, ZH_WORDS_GETTER("Unrepair.tel"));

	//报修位置
	API_DTO_FIELD_DEFAULT(String, repairObjName, ZH_WORDS_GETTER("Unrepair.repairObjName"));

	//当前处理人
	API_DTO_FIELD_DEFAULT(String, staffName, ZH_WORDS_GETTER("Unrepair.staffName"));

	//结单时间
	API_DTO_FIELD_DEFAULT(String, endTime, ZH_WORDS_GETTER("Unrepair.endTime"));

	//订单状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("Unrepair.state"));
};

/*
* 示例分页对象
*/
class UnrepairPageDTO :public PageDTO<UnrepairDTO::Wrapper>
{
	DTO_INIT(UnrepairPageDTO,PageDTO<UnrepairDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif