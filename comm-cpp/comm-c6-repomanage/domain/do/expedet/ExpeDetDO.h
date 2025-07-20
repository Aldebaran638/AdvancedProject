#pragma once
#ifndef _EXPEDET_DO_
#define _EXPEDET_DO_
#include "../DoInclude.h"

/**
 * 房屋费用明细数据库实体类
 */
class ExpedetBuildingFeeDetailDO
{
	// 房屋编号
	CC_SYNTHESIZE(string, room_name, Room_name);
	// 业主名称
	CC_SYNTHESIZE(string, name, Name);
	// 欠费
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	// 实收
	CC_SYNTHESIZE(int, shishou, Shishou);
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
	ExpedetBuildingFeeDetailDO() {
		room_name = "";
		name = "";
		qianfei = 0;
		shishou = 0;
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
typedef std::shared_ptr<ExpedetBuildingFeeDetailDO> PtrExpedetBuildingFeeDetailDO;


/**
 * 业主费用明细数据库实体类
 */
class ExpedetOwnerFeeDetailDO
{

	// 业主名称
	CC_SYNTHESIZE(string, name, Name);
	// 房屋编号
	CC_SYNTHESIZE(string, room_name, Room_name);
	// 欠费
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	// 实收
	CC_SYNTHESIZE(int, shishou, Shishou);
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
	ExpedetOwnerFeeDetailDO() {
		room_name = "";
		name = "";
		qianfei = 0;
		shishou = 0;
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
typedef std::shared_ptr<ExpedetOwnerFeeDetailDO> PtrExpedetOwnerFeeDetailDO;

/**
 * 合同费用明细数据库实体类
 */
class ExpedetContractFeeDetailDO
{
	//合同
	CC_SYNTHESIZE(string, contract_name, Contract_name);
	// 业主名称
	CC_SYNTHESIZE(string, name, Name);
	// 欠费
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	// 实收
	CC_SYNTHESIZE(int, shishou, Shishou);
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
	ExpedetContractFeeDetailDO() {
		contract_name = "";
		name = "";
		qianfei = 0;
		shishou = 0;
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
typedef std::shared_ptr<ExpedetContractFeeDetailDO> PtrExpedetContractFeeDetailDO;

/**
 * 车辆费用明细数据库实体类
 */
class ExpedetCarFeeDetailDO
{
	//车辆
	CC_SYNTHESIZE(string, car_num, Car_num);
	// 业主名称
	CC_SYNTHESIZE(string, name, Name);
	// 欠费
	CC_SYNTHESIZE(int, qianfei, Qianfei);
	// 实收
	CC_SYNTHESIZE(int, shishou, Shishou);
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
	ExpedetCarFeeDetailDO() {
		car_num = "";
		name = "";
		qianfei = 0;
		shishou = 0;
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
typedef std::shared_ptr<ExpedetCarFeeDetailDO> PtrExpedetCarFeeDetailDO;

#endif // !_SAMPLE_DO_
