#pragma once

#ifndef _REPAIRREPORTFEE_DO_
#define _REPAIRREPORTFEE_DO_
#include "../DoInclude.h"

/**
 * 报修收费数据库实体类
 */
class RepairReportFeeDO
{
	// 报修编号
	CC_SYNTHESIZE(string, repairId, RepairId);
	// 报修人
	CC_SYNTHESIZE(string, repairName, RepairName);
	// 报修电话
	CC_SYNTHESIZE(string, tel, Tel);
	// 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	// 修改时间
	CC_SYNTHESIZE(string, repairLocation, RepairLocation);
	// 维修类型
	CC_SYNTHESIZE(string, maintenanceType, MaintenanceType);//在Mapper里第5列取出来的就是 repair_obj_type，然后装到 repairLocation
	// 费用明细
	CC_SYNTHESIZE(string, repairFee, RepairFee);
public:
	RepairReportFeeDO() {
		repairId = "";
		repairName = "";
		tel = "";
		createTime = "";
		repairLocation = "";
		maintenanceType = "";
		repairFee = "";
	}
};

// 给RepairReportFeeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairReportFeeDO> PtrRepairReportFeeDO;
#endif 
