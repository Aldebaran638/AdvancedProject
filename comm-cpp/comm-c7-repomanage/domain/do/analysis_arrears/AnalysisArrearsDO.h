#pragma once

#ifndef _ANALYSIS_ARREARS_DO_H_
#define _ANALYSIS_ARREARS_DO_H_
#include "../DoInclude.h"
/**
 * 欠费分析数据库实体类
 */
class AnalysisArrearsDO 
{
	/**
	* 只有字段注释表示该字段为查询所需要的字段
	*/

	// 费用类型 fee_type_cd
	CC_SYNTHESIZE(std::string, feeType, FeeType);
	
	// 费用类型 fee_type_name
	CC_SYNTHESIZE(std::string, feeTypeName, FeeTypeName);
	
	// 楼栋id floor_id
	CC_SYNTHESIZE(std::string, buildingId, BuildingId);

	/**
	 *	building_room表
	 */
	// 小区号 community_id

	// 楼栋号 floor_num
	CC_SYNTHESIZE(std::string, buildingNum, BuildingNum);

	// 房间号 room_num
	CC_SYNTHESIZE(std::string, roomNum, RoomNum);

	// 面积 room_area
	CC_SYNTHESIZE(double, roomArea, RoomArea);

	/*
	**	building_unit表
	*/
	// status_cd 数据状态，确保该单元数据有效

	/*
	**	f_floor表
	*/
	// status_cd 数据状态，确保该楼栋数据有效

	/*
	**	report_owe_fee表，该表用于催收未缴金额，并用于统计未收情况表
	*/
	// 该项未收金额 amount_owned
	CC_SYNTHESIZE(double, amountOwned, AmountOwned);

	/*
	**	pay_fee表
	*/
	// 费用类型 fee_type_cd

	// 总金额 amount，用于统计费用

	// 费用开始时间 start_time
	CC_SYNTHESIZE(std::string, feeStartTime, FeeStartTime);

	// 费用截止时间 end_time
	CC_SYNTHESIZE(std::string, feeEndTime, FeeEndTime);

	/*
	**	pay_fee_detail_month表，该表用于统计当月收费情况，并用于统计未收明细表和当月收费情况表
	*/
	// 当月该项未收金额 receivable_amount
	CC_SYNTHESIZE(double, receivableAmount, ReceivableAmount);

	/*
	**	未收情况表
	*/
	// 楼栋号，building_room表floor_num字段

	// 总未收金额
	CC_SYNTHESIZE(double, totalArrear, TotalArrear);

	// 本年度未收金额
	CC_SYNTHESIZE(double, thisYearTotalArrear, ThisYearTotalArrear);
	
	// 之前未收金额
	CC_SYNTHESIZE(double, beforeTotalArrear, BeforeTotalArrear);

	/*
	**	未收明细表
	*/
	// 房号roomNum，building_room表room_num字段

	// 面积roomArea，building_room表room_area字段

	// 费用名称
	CC_SYNTHESIZE(std::string, feeName, FeeName);

	// 费用开始时间feeStartTime，pay_fee表start_time字段
	
	// 费用结束时间feeEndTime，pay_fee表end_time字段
	
	// 总未收金额，与未收情况表共用
	// CC_SYNTHESIZE(double, totalArrear, TotalArrear);

	// 本年度未收金额，与未收情况表共用
	// CC_SYNTHESIZE(double, thisYearTotalArrear, ThisYearTotalArrear);

	// 之前未收金额，与未收情况表共用
	// CC_SYNTHESIZE(double, beforeTotalArrear, BeforeTotalArrear);

	/*
	**	当月收费情况表
	*/
	// 楼栋号，building_room表floor_num字段

	// 每月应收金额
	CC_SYNTHESIZE(double, everyMonthArrear, EveryMonthArrear);

	// 本月实收金额
	CC_SYNTHESIZE(double, thisMonthCollect, ThisMonthCollect);

	// 本月实收中属于之前月部分
	CC_SYNTHESIZE(double, thisMonthCollectForThisYear, ThisMonthCollectForThisYear);

	// 本月实收中属于本月部分
	CC_SYNTHESIZE(double, thisMonthCollectForThisMonth, ThisMonthCollectForThisMonth);

	// 本月实收中属于下一月部分
	CC_SYNTHESIZE(double, thisMonthCollectForNextMonth, ThisMonthCollectForNextMonth);

	// 本月实收中属于之前年部分
	CC_SYNTHESIZE(double, thisMonthCollectForBefore, ThisMonthCollectForBefore);

public:
	AnalysisArrearsDO() {
		buildingNum = "";
		roomNum = "";
		roomArea = 0;
		amountOwned = 0;
		feeStartTime = "";
		feeEndTime = "";
		receivableAmount = 0;
		totalArrear = 0;
		thisYearTotalArrear = 0;
		beforeTotalArrear = 0;
		feeName = "";
		everyMonthArrear = 0;
		thisMonthCollect = 0;
		thisMonthCollectForThisYear = 0;
		thisMonthCollectForThisMonth = 0;
		thisMonthCollectForNextMonth = 0;
		thisMonthCollectForBefore = 0;
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<AnalysisArrearsDO> PtrAnalysisArrearsDO;

#endif // !_ANALYSIS_ARREARS_DO_H_
