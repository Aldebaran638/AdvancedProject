#pragma
#ifndef _FLOOR_DTO_H_
#define _FLOOR_DTO_H_


#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 定义一个新增数据传输对象
 */

class FloorAddDTO :public oatpp::DTO {
	DTO_INIT(FloorAddDTO, DTO);
	//楼ID
	API_DTO_FIELD_DEFAULT(String, floor_id, ZH_WORDS_GETTER("floor.field.floor_id"));
	//业务ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("floor.field.b_id"));
	//楼编号
	API_DTO_FIELD_DEFAULT(String, floor_num, ZH_WORDS_GETTER("floor.field.floor_num"));
	//小区楼名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("floor.field.name"));
	//用户ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("floor.field.user_id"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("floor.field.remark"));
	//创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("floor.field.create_time"));
	//小区ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("floor.field.community_id"));
	//数据状态，详细参考c_status表，S保存，0在用，1失效
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("floor.field.status_cd"));
	//建筑面积
	API_DTO_FIELD_DEFAULT(String, floor_area, ZH_WORDS_GETTER("floor.field.floor_area"));
	//楼栋加入顺序
	API_DTO_FIELD_DEFAULT(Int32, seq, ZH_WORDS_GETTER("floor.field.seq"));


	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};
/*
 * 定义一个修改楼栋信息的数据传输模型
 */
class FloorDTO :public oatpp::DTO {
	DTO_INIT(FloorDTO, DTO);
	//楼ID
	API_DTO_FIELD_DEFAULT(String, floor_id, ZH_WORDS_GETTER("floor.field.floor_id"));
	//业务ID
	API_DTO_FIELD_DEFAULT(String, b_id, ZH_WORDS_GETTER("floor.field.b_id"));
	//楼编号
	API_DTO_FIELD_DEFAULT(String, floor_num, ZH_WORDS_GETTER("floor.field.floor_num"));
	//小区楼名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("floor.field.name"));
	//用户ID
	API_DTO_FIELD_DEFAULT(String, user_id, ZH_WORDS_GETTER("floor.field.user_id"));
	//备注
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("floor.field.remark"));
	//创建时间
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("floor.field.create_time"));
	//小区ID
	API_DTO_FIELD_DEFAULT(String, community_id, ZH_WORDS_GETTER("floor.field.community_id"));
	//数据状态，详细参考c_status表，S保存，0在用，1失效
	API_DTO_FIELD_DEFAULT(String, status_cd, ZH_WORDS_GETTER("floor.field.status_cd"));
	//建筑面积
	API_DTO_FIELD_DEFAULT(String, floor_area, ZH_WORDS_GETTER("floor.field.floor_area"));
	//楼栋加入顺序
	API_DTO_FIELD_DEFAULT(Int32, seq, ZH_WORDS_GETTER("floor.field.seq"));

	// 关联一个PayloadDTO负载数据对象
	CC_SYNTHESIZE(const PayloadDTO*, _payload, Payload);
};

/*
 * 定义一个修改楼栋信息分页的数据传输模型
 */
class FloorPageDTO : public PageDTO<FloorDTO::Wrapper>
{
	DTO_INIT(FloorPageDTO, PageDTO<FloorDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)


#endif