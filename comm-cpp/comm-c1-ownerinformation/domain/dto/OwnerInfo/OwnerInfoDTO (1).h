#ifndef _OWNERINFO_DTO_
#define _OWNERINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 入住/退出房屋传输对象
*/
class OwnerInfoAddDTO : public oatpp::DTO
{
	DTO_INIT(OwnerInfoAddDTO, DTO);
	// 房屋编号
	API_DTO_FIELD_DEFAULT(String, room_num, ZH_WORDS_GETTER("OwnerInfo.field.room_num"));
	// 楼层
	API_DTO_FIELD_DEFAULT(String, layer, ZH_WORDS_GETTER("OwnerInfo.field.layer"));
	// 房屋id （主键）
	API_DTO_FIELD_DEFAULT(String, room_id, ZH_WORDS_GETTER("OwnerInfo.field.room_id"));
	// 建筑面积
	API_DTO_FIELD_DEFAULT(Float32, built_up_area, ZH_WORDS_GETTER("OwnerInfo.field.built_up_area"));
	// 户型
	API_DTO_FIELD_DEFAULT(String, apartment, ZH_WORDS_GETTER("OwnerInfo.field.apartment"));
	// 房间数
	API_DTO_FIELD_DEFAULT(Int32, section, ZH_WORDS_GETTER("OwnerInfo.field.section"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/**
 * 入住/退出房屋传输对象
 */
class OwnerInfoDTO : public oatpp::DTO
{
	DTO_INIT(OwnerInfoDTO, OwnerInfoAddDTO);

	// 房屋id （主键）
	API_DTO_FIELD_DEFAULT(String, room_id, ZH_WORDS_GETTER("OwnerInfo.field.room_id"));
};


/**
* 入住/退出房屋分页传输对象
*/
class OwnerInfoPageDTO : public PageDTO<OwnerInfoDTO::Wrapper>
{
	DTO_INIT(OwnerInfoPageDTO, PageDTO<OwnerInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif