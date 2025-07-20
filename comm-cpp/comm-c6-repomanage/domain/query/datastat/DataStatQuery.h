/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2025/5/20

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef DATASTATQUERY_H
#define DATASTATQUERY_H

#include <domain/GlobalInclude.h>
#include <domain/query/PageQuery.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费用统计查询对象
 */
class ExpenseStatQuery : public PageQuery {
	DTO_INIT(ExpenseStatQuery, PageQuery);

	// 开始日期，格式：yyyy-MM-dd
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.startDate");
	}

	// 结束日期，格式：yyyy-MM-dd
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.endDate");
	}

	// 社区ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityId");
	}

	// 社区名称
	DTO_FIELD(String, communityName);
	DTO_FIELD_INFO(communityName) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityName");
	}
};

/**
 * 工单统计查询对象
 */
class WorkOrderStatQuery : public PageQuery {
	DTO_INIT(WorkOrderStatQuery, PageQuery);

	// 开始日期，格式：yyyy-MM-dd
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.startDate");
	}

	// 结束日期，格式：yyyy-MM-dd
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.endDate");
	}

	// 社区ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityId");
	}

	// 社区名称
	DTO_FIELD(String, communityName);
	DTO_FIELD_INFO(communityName) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityName");
	}
};

/**
 * 出入统计查询对象
 */
class AccessStatQuery : public PageQuery {
	DTO_INIT(AccessStatQuery, PageQuery);

	// 开始日期，格式：yyyy-MM-dd
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.startDate");
	}

	// 结束日期，格式：yyyy-MM-dd
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.endDate");
	}

	// 社区ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityId");
	}

	// 社区名称
	DTO_FIELD(String, communityName);
	DTO_FIELD_INFO(communityName) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityName");
	}
};

/**
 * 其他统计查询对象
 */
class OtherStatQuery : public PageQuery {
	DTO_INIT(OtherStatQuery, PageQuery);

	// 开始日期，格式：yyyy-MM-dd
	DTO_FIELD(String, startDate);
	DTO_FIELD_INFO(startDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.startDate");
	}

	// 结束日期，格式：yyyy-MM-dd
	DTO_FIELD(String, endDate);
	DTO_FIELD_INFO(endDate) {
		info->description = ZH_WORDS_GETTER("datastat.field.endDate");
	}

	// 社区ID
	DTO_FIELD(String, communityId);
	DTO_FIELD_INFO(communityId) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityId");
	}

	// 社区名称
	DTO_FIELD(String, communityName);
	DTO_FIELD_INFO(communityName) {
		info->description = ZH_WORDS_GETTER("datastat.field.communityName");
	}
};

//定义一个宏观查询对象（也就是数据统计界面的查询时间，以及小区）
class DataStatALLSearchQuery : public PageQuery {

	DTO_INIT(DataStatALLSearchQuery, PageQuery);
	//开始时间
	API_DTO_FIELD_DEFAULT(String, begintime, ZH_WORDS_GETTER("datastat.field.begintime"));

	//结束时间
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("datastat.field.endtime"));

	//小区
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("datastat.field.community"));
};

//定义一个明细查询对象 （也就是下方明细的查询传输对象）
class DataStatDetailSearchQuery : public PageQuery {

	DTO_INIT(DataStatDetailSearchQuery, PageQuery);
	//开始时间
	API_DTO_FIELD_DEFAULT(String, begintime, ZH_WORDS_GETTER("datastat.field.begintime"));

	//结束时间
	API_DTO_FIELD_DEFAULT(String, endtime, ZH_WORDS_GETTER("datastat.field.endtime"));

	//小区
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("datastat.field.community"));

	//楼栋可选
	API_DTO_FIELD(String, house, ZH_WORDS_GETTER("datastat.field.house"), false, {});

	//业主可选
	API_DTO_FIELD(String, host, ZH_WORDS_GETTER("datastat.field.host"), false, {});

	//手机号可选
	API_DTO_FIELD(String, phone, ZH_WORDS_GETTER("datastat.field.phone"), false, {});
};


/*              数据统计-3            */
/**
 * 欠费明细查询对象
 */
class DatastatFeeDetailQuery : public PageQuery
{
	DTO_INIT(DatastatFeeDetailQuery, PageQuery);

	//房屋编号
	API_DTO_FIELD_DEFAULT(String, room_name, ZH_WORDS_GETTER("datastat.field.module1.room_name"));
	//业主名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("datastat.field.module1.name"));
	//手机号
	API_DTO_FIELD_DEFAULT(String, link, ZH_WORDS_GETTER("datastat.field.module1.link"));

};


/**
 * 收缴情况查询对象
 */
class DatastatChargeDetailQuery : public PageQuery
{
	DTO_INIT(DatastatChargeDetailQuery, PageQuery);

	//收费类型
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("datastat.field.module2.fee_name"));

};

/**
 * 月实收明细查询对象
 */
class DatastatMonthDetailQuery : public PageQuery
{
	DTO_INIT(DatastatMonthDetailQuery, PageQuery);

	//收费类型
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("datastat.field.module3.fee_name"));
	//楼栋
	API_DTO_FIELD_DEFAULT(String, building, ZH_WORDS_GETTER("datastat.field.module3.building"));
	//开始日期
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("datastat.field.module3.start_time"));
	//结束日期
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("datastat.field.module3.end_time"));
};

/**
 * 月欠费明细查询对象
 */
class DatastatMonthFeeQuery : public PageQuery
{
	DTO_INIT(DatastatMonthFeeQuery, PageQuery);

	//收费类型
	API_DTO_FIELD_DEFAULT(String, fee_name, ZH_WORDS_GETTER("datastat.field.module3.fee_name"));
	//楼栋
	API_DTO_FIELD_DEFAULT(String, building, ZH_WORDS_GETTER("datastat.field.module3.building"));
	//开始日期
	API_DTO_FIELD_DEFAULT(String, start_time, ZH_WORDS_GETTER("datastat.field.module3.start_time"));
	//结束日期
	API_DTO_FIELD_DEFAULT(String, end_time, ZH_WORDS_GETTER("datastat.field.module3.end_time"));
};




#include OATPP_CODEGEN_END(DTO)

#endif // !DATASTATQUERY_H
