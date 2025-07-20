#pragma once
#ifndef _DATASTAT_DO_
#define _DATASTAT_DO_
#include "../DoInclude.h"
/**
 * 实收统计数据实体类
 */
class DataStatFinalCostDO
{
    // 楼栋信息
    CC_SYNTHESIZE(string, house, House);
    // 业主数量
    CC_SYNTHESIZE(int, hostnum, Hostnum);
    // 收费户数
    CC_SYNTHESIZE(int, costnum, Costnum);
    // 物业费
    CC_SYNTHESIZE(double, wuye, Wuye);
    // 押金
    CC_SYNTHESIZE(double, yajin, Yajin);
    // 停车费
    CC_SYNTHESIZE(double, tingche, Tingche);
    // 煤气费
    CC_SYNTHESIZE(double, meiqi, Meiqi);
    // 取暖费
    CC_SYNTHESIZE(double, qunuan, Qunuan);
    // 维修费
    CC_SYNTHESIZE(double, weixiu, Weixiu);
    // 其他
    CC_SYNTHESIZE(double, qita, Qita);
    // 服务费
    CC_SYNTHESIZE(double, fuwu, Fuwu);
    // 水费
    CC_SYNTHESIZE(double, shuifei, Shuifei);
    // 电费
    CC_SYNTHESIZE(double, dianfei, Dianfei);
    // 租金
    CC_SYNTHESIZE(double, zujin, Zujin);
    // 公摊费
    CC_SYNTHESIZE(double, gongtan, Gongtan);
    // 实收总额
    CC_SYNTHESIZE(double, final, Final);
    // 总实收
    CC_SYNTHESIZE(double, allfinal, Allfinal);
public:
    DataStatFinalCostDO() {
        hostnum = 0;
        costnum = 0;
        wuye = 0.0;
        yajin = 0.0;
        tingche = 0.0;
        meiqi = 0.0;
        qunuan = 0.0;
        weixiu = 0.0;
        qita = 0.0;
        fuwu = 0.0;
        shuifei = 0.0;
        dianfei = 0.0;
        zujin = 0.0;
        gongtan = 0.0;
        final = 0.0;
        allfinal = 0.0;
    }
};
/**
 * 欠费统计数据对象
 */
class DataStatQianfeiDO {
public:
    // 楼栋
    CC_SYNTHESIZE(std::string, house, House);
    // 物业费欠费
    CC_SYNTHESIZE(double, wuye, Wuye);
    // 押金欠费
    CC_SYNTHESIZE(double, yajin, Yajin);
    // 停车费欠费
    CC_SYNTHESIZE(double, tingche, Tingche);
    // 煤气费欠费
    CC_SYNTHESIZE(double, meiqi, Meiqi);
    // 取暖费欠费
    CC_SYNTHESIZE(double, qunuan, Qunuan);
    // 维修费欠费
    CC_SYNTHESIZE(double, weixiu, Weixiu);
    // 其他费用欠费
    CC_SYNTHESIZE(double, qita, Qita);
    // 服务费欠费
    CC_SYNTHESIZE(double, fuwu, Fuwu);
    // 水费欠费
    CC_SYNTHESIZE(double, shuifei, Shuifei);
    // 电费欠费
    CC_SYNTHESIZE(double, dianfei, Dianfei);
    // 租金欠费
    CC_SYNTHESIZE(double, zujin, Zujin);
    // 公摊费欠费
    CC_SYNTHESIZE(double, gongtan, Gongtan);
    // 欠费总额
    CC_SYNTHESIZE(double, qianfei, Qianfei);
    // 总欠费（所有楼栋）
    CC_SYNTHESIZE(double, allqianfei, Allqianfei);

public:
    DataStatQianfeiDO() : wuye(0.0), yajin(0.0), tingche(0.0), meiqi(0.0),
        qunuan(0.0), weixiu(0.0), qita(0.0), fuwu(0.0),
        shuifei(0.0), dianfei(0.0), zujin(0.0), gongtan(0.0),
        qianfei(0.0), allqianfei(0.0) {}
};
/**
 * 实收明细数据对象 - 按房间查询
 */
class DataStatDetailCostDO {
public:
    // 房间ID
    CC_SYNTHESIZE(std::string, roomId, RoomId);
    // 楼栋信息
    CC_SYNTHESIZE(std::string, house, House);
    // 房间号
    CC_SYNTHESIZE(std::string, roomNum, RoomNum);
    // 业主姓名
    CC_SYNTHESIZE(std::string, host, Host);
    // 业主电话
    CC_SYNTHESIZE(std::string, phone, Phone);
    // 物业费
    CC_SYNTHESIZE(double, wuye, Wuye);
    // 押金
    CC_SYNTHESIZE(double, yajin, Yajin);
    // 停车费
    CC_SYNTHESIZE(double, tingche, Tingche);
    // 煤气费
    CC_SYNTHESIZE(double, meiqi, Meiqi);
    // 取暖费
    CC_SYNTHESIZE(double, qunuan, Qunuan);
    // 维修费
    CC_SYNTHESIZE(double, weixiu, Weixiu);
    // 其他
    CC_SYNTHESIZE(double, qita, Qita);
    // 服务费
    CC_SYNTHESIZE(double, fuwu, Fuwu);
    // 水费
    CC_SYNTHESIZE(double, shuifei, Shuifei);
    // 电费
    CC_SYNTHESIZE(double, dianfei, Dianfei);
    // 租金
    CC_SYNTHESIZE(double, zujin, Zujin);
    // 公摊费
    CC_SYNTHESIZE(double, gongtan, Gongtan);
    // 实收总额
    CC_SYNTHESIZE(double, final, Final);
public:
    DataStatDetailCostDO() : wuye(0.0), yajin(0.0), tingche(0.0), meiqi(0.0),
        qunuan(0.0), weixiu(0.0), qita(0.0), fuwu(0.0),
        shuifei(0.0), dianfei(0.0), zujin(0.0), gongtan(0.0),
        final(0.0) {}
};


/*              数据统计-3            */
/**
 * 欠费明细数据库实体类
 */
class DatastatFeeDetailDO
{
	// 房屋编号
	CC_SYNTHESIZE(string, room_name, Room_name);
	// 业主名称
	CC_SYNTHESIZE(string, name, Name);
	// 欠费
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	//物业费
	CC_SYNTHESIZE(int, wuye, Wuye);
	//押金
	CC_SYNTHESIZE(int, yajin, Yajin);
	//停车费
	CC_SYNTHESIZE(int, tingche, Tingche);
	//煤气费
	CC_SYNTHESIZE(int, meiqi, Meiqi);
	//取暖费
	CC_SYNTHESIZE(int, qunuan, Qunuan);
	//维修费
	CC_SYNTHESIZE(int, weixiu, Weixiu);
	//服务费
	CC_SYNTHESIZE(int, fuwu, Fuwu);
	//其他	
	CC_SYNTHESIZE(int, qita, Qita);
	//水费
	CC_SYNTHESIZE(int, shuifei, Shuifei);
	//电费
	CC_SYNTHESIZE(int, dianfei, Dianfei);
	//租金
	CC_SYNTHESIZE(int, zujin, Zujin);
	//公摊费
	CC_SYNTHESIZE(int, gongtan, Gongtan);
public:
	DatastatFeeDetailDO() {
		room_name = "";
		name = "";
		qianfei = 0;

		wuye = 0;
		yajin = 0;
		tingche = 0;
		meiqi = 0;
		qunuan = 0;
		weixiu = 0;
		fuwu = 0;
		qita = 0;
		shuifei = 0;
		dianfei = 0;
		zujin = 0;
		gongtan = 0;
	}
};

// 给DatastatFeeDetailDO智能指针设定一个别名方便使用
typedef std::shared_ptr<DatastatFeeDetailDO> PtrDatastatFeeDetailDO;


/**
 * 收缴情况数据库实体类
 */
class DatastatChargeDetailDO
{
	//楼栋
	CC_SYNTHESIZE(string, building, Building);
	//户数
	CC_SYNTHESIZE(int, num_for_house, Num_for_house);
	//收费户
	CC_SYNTHESIZE(int, num_for_chargeable_house, Num_for_chargeable_house);
	//历史欠费
	CC_SYNTHESIZE(int, arrears_history, Arrears_history);
	//总欠费
	CC_SYNTHESIZE(int, all_arrears, All_arrears);
	//本日已交户数
	CC_SYNTHESIZE(int, num_for_paid_house_today, Num_for_paid_house_today);
	//本日已交金额	
	CC_SYNTHESIZE(int, cost_for_paid_today, Cost_for_paid_today);
	//历史欠费清缴户
	CC_SYNTHESIZE(int, num_for_notpaid_house_history, Num_for_notpaid_house_history);
	//历史欠费清缴金额
	CC_SYNTHESIZE(int, cost_for_arrears_history, Cost_for_arrears_history);
	//本月已收户数
	CC_SYNTHESIZE(int, num_for_paid_house_month, Num_for_paid_house_month);
	//剩余户数	
	CC_SYNTHESIZE(int, num_for_last_house, Num_for_last_house);
	//已收户占比
	CC_SYNTHESIZE(double, percentage_for_paid_house, Percentage_for_paid_house);
	//当月已收金额
	CC_SYNTHESIZE(int, fees_for_received_month, Fees_for_received_month);
	//当月剩余未收	
	CC_SYNTHESIZE(int, fees_for_notreceived_month, Fees_for_notreceived_month);
	//收费率
	CC_SYNTHESIZE(double, charge_rate, Charge_rate);
public:
	DatastatChargeDetailDO() {
		building = "";
		num_for_house = 0;
		num_for_chargeable_house = 0;
		arrears_history = 0;
		all_arrears = 0;
		num_for_paid_house_today = 0;
		cost_for_paid_today = 0;
		num_for_notpaid_house_history = 0;
		cost_for_arrears_history = 0;
		num_for_paid_house_month = 0;
		num_for_last_house = 0;
		percentage_for_paid_house = 0;
		fees_for_received_month = 0;
		fees_for_notreceived_month = 0;
		charge_rate = 0;
	}
};

// 给DatastatChargeDetailDO智能指针设定一个别名方便使用
typedef std::shared_ptr<DatastatChargeDetailDO> PtrDatastatChargeDetailDO;

/**
 * 月实收明细数据库实体类
 */
class DatastatMonthDetailDO
{


	//房屋
	CC_SYNTHESIZE(string, house, House);
	//业主
	CC_SYNTHESIZE(string, ow, Ow);
	//实收
	CC_SYNTHESIZE(int, final, Final);
	//费用名称
	CC_SYNTHESIZE(string, name_fee, Name_fee);
	//实收时间段
	CC_SYNTHESIZE(string, time_income, Time_income);
	//收银员	
	CC_SYNTHESIZE(string, cashier, Cashier);
	// 交费时间
	CC_SYNTHESIZE(string, time_pay, Time_pay);
public:
	DatastatMonthDetailDO() {
		house = "";
		ow = "";
		final = 0;
		name_fee = "";
		time_income = "";
		cashier = "";
		time_pay = "";
	}
};

// 给DatastatMonthDetailDO智能指针设定一个别名方便使用
typedef std::shared_ptr<DatastatMonthDetailDO> PtrDatastatMonthDetailDO;

/**
 * 月欠费明细数据库实体类
 */
class DatastatMonthFeeDO
{


	//房屋
	CC_SYNTHESIZE(string, house, House);
	//业主
	CC_SYNTHESIZE(string, ow, Ow);
	//费用名称
	CC_SYNTHESIZE(string, arrears_name, Arrears_name);
	//欠费时间段
	CC_SYNTHESIZE(string, arrears_time, Arrears_time);
	//欠费金额
	CC_SYNTHESIZE(int, arrears_num, Arrears_num);


public:
	DatastatMonthFeeDO() {
		house = "";
		ow = "";
		arrears_name = "";
		arrears_time = "";
		arrears_num = 0;
	}
};

// 给DatastatMonthFeeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<DatastatMonthFeeDO> PtrDatastatMonthFeeDO;


#endif // !_DATASTAT_DO_ 