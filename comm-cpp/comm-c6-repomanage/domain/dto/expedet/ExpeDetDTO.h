#pragma once
#ifndef _EXPEDETDTO_H_
#define _EXPEDETDTO_H_


#include "domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)


//费用明细查询DTO




/**
 * 房屋明细数据传输对象
 */
class BuildingExpedetDTO : public oatpp::DTO
{
	DTO_INIT(BuildingExpedetDTO, DTO);

	//房屋
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("datastat.field.module1.house"));
	//业主
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.ow"));
	//实收
	API_DTO_FIELD_DEFAULT(Int32, shishou, ZH_WORDS_GETTER("datastat.field.module1.shishou"));
	//欠费
	API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
	//物业费
	API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
	//押金
	API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
	//停车费
	API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
	//煤气费
	API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
	//取暖费
	API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
	//维修费
	API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
	//服务费
	API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
	//其他
	API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
	//水费
	API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
	//电费
	API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
	//租金
	API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
	//公摊费
	API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));

};

/**
 * 房屋明细分页数据传输对象
 */
class BuildingExpedetPageDTO : public PageDTO<BuildingExpedetDTO::Wrapper>
{
	DTO_INIT(BuildingExpedetPageDTO, PageDTO<BuildingExpedetDTO::Wrapper>);
};


/**
 * 业主明细数据传输对象
 */
class OwnerExpedetDTO : public oatpp::DTO
{
	DTO_INIT(OwnerExpedetDTO, DTO);

	//业主
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.ow"));
	//房屋
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("datastat.field.module1.house"));
	//实收
	API_DTO_FIELD_DEFAULT(Int32, shishou, ZH_WORDS_GETTER("datastat.field.module1.shishou"));
	//欠费
	API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
	//物业费
	API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
	//押金
	API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
	//停车费
	API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
	//煤气费
	API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
	//取暖费
	API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
	//维修费
	API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
	//服务费
	API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
	//其他
	API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
	//水费
	API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
	//电费
	API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
	//租金
	API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
	//公摊费
	API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));

};

/**
 * 业主明细分页数据传输对象
 */
class OwnerExpedetPageDTO : public PageDTO<OwnerExpedetDTO::Wrapper>
{
	DTO_INIT(OwnerExpedetPageDTO, PageDTO<OwnerExpedetDTO::Wrapper>);
};

/**
 * 合同明细数据传输对象
 */
class ContractExpedetDTO : public oatpp::DTO
{
	DTO_INIT(ContractExpedetDTO, DTO);

	//合同
	API_DTO_FIELD_DEFAULT(String, contract_name, ZH_WORDS_GETTER("datastat.field.module1.hetong"));
	//业主
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.ow"));
	//实收
	API_DTO_FIELD_DEFAULT(Int32, shishou, ZH_WORDS_GETTER("datastat.field.module1.shishou"));
	//欠费
	API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
	//物业费
	API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
	//押金
	API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
	//停车费
	API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
	//煤气费
	API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
	//取暖费
	API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
	//维修费
	API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
	//服务费
	API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
	//其他
	API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
	//水费
	API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
	//电费
	API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
	//租金
	API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
	//公摊费
	API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));

};

/**
 * 合同明细分页数据传输对象
 */
class ContractExpedetPageDTO : public PageDTO<ContractExpedetDTO::Wrapper>
{
	DTO_INIT(ContractExpedetPageDTO, PageDTO<ContractExpedetDTO::Wrapper>);
};


/**
 * 车辆明细数据传输对象
 */
class CarExpedetDTO : public oatpp::DTO
{
	DTO_INIT(CarExpedetDTO, DTO);

	//车辆
	API_DTO_FIELD_DEFAULT(String, car_num, ZH_WORDS_GETTER("datastat.field.module1.car"));
	//业主
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.ow"));
	//实收
	API_DTO_FIELD_DEFAULT(Int32, shishou, ZH_WORDS_GETTER("datastat.field.module1.shishou"));
	//欠费
	API_DTO_FIELD_DEFAULT(Int32, qianfei, ZH_WORDS_GETTER("datastat.field.module1.qianfei"));
	//物业费
	API_DTO_FIELD_DEFAULT(Int32, wuye, ZH_WORDS_GETTER("datastat.field.module1.wuye"));
	//押金
	API_DTO_FIELD_DEFAULT(Int32, yajin, ZH_WORDS_GETTER("datastat.field.module1.yajin"));
	//停车费
	API_DTO_FIELD_DEFAULT(Int32, tingche, ZH_WORDS_GETTER("datastat.field.module1.tingche"));
	//煤气费
	API_DTO_FIELD_DEFAULT(Int32, meiqi, ZH_WORDS_GETTER("datastat.field.module1.meiqi"));
	//取暖费
	API_DTO_FIELD_DEFAULT(Int32, qunuan, ZH_WORDS_GETTER("datastat.field.module1.qunuan"));
	//维修费
	API_DTO_FIELD_DEFAULT(Int32, weixiu, ZH_WORDS_GETTER("datastat.field.module1.weixiu"));
	//服务费
	API_DTO_FIELD_DEFAULT(Int32, fuwu, ZH_WORDS_GETTER("datastat.field.module1.fuwu"));
	//其他
	API_DTO_FIELD_DEFAULT(Int32, qita, ZH_WORDS_GETTER("datastat.field.module1.qita"));
	//水费
	API_DTO_FIELD_DEFAULT(Int32, shuifei, ZH_WORDS_GETTER("datastat.field.module1.shuifei"));
	//电费
	API_DTO_FIELD_DEFAULT(Int32, dianfei, ZH_WORDS_GETTER("datastat.field.module1.dianfei"));
	//租金
	API_DTO_FIELD_DEFAULT(Int32, zujin, ZH_WORDS_GETTER("datastat.field.module1.zujin"));
	//公摊费
	API_DTO_FIELD_DEFAULT(Int32, gongtan, ZH_WORDS_GETTER("datastat.field.module1.gongtan"));

};

/**
 * 车辆明细分页数据传输对象
 */
class CarExpedetPageDTO : public PageDTO<CarExpedetDTO::Wrapper>
{
	DTO_INIT(CarExpedetPageDTO, PageDTO<CarExpedetDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif
