#pragma once
#ifndef _WATERMETERQUERY_H_
#define _WATERMETERQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询水电抄表信息的数据传输模型
 */
class WaterMeterQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(WaterMeterQuery, PageQuery);
	// 表编号id
	DTO_FIELD(String, water_id);
	DTO_FIELD_INFO(water_id) {
		info->description = ZH_WORDS_GETTER("watermeter.meterid");
	}
	// 抄表类型
	DTO_FIELD(String, meter_type);
	DTO_FIELD_INFO(meter_type) {
		info->description = ZH_WORDS_GETTER("watermeter.metertype");
	}
	//楼栋-单元-房屋
	DTO_FIELD(String, obj_name);
	DTO_FIELD_INFO(obj_name) {
		info->description = ZH_WORDS_GETTER("watermeter.roomid");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WATERMETERQUERY_H_