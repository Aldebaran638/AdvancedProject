#pragma once
#ifndef _REPAIR_REPORT_SUMMARY_DO_
#define _REPAIR_REPORT_SUMMARY_DO_
#include "../DoInclude.h"

/**
 * 报修汇总表数据库实体类
 */
class RepairReportSummaryDO
{
	//报修编号 自增类型
	CC_SYNTHESIZE(int, summaryId, SummaryId);
	//员工ID   r_repair_user表 staff_id字段
	CC_SYNTHESIZE(string, staffId, StaffId);
	//员工姓名   r_repair_user表 staff_name字段
	CC_SYNTHESIZE(string, staffName, StaffName);
	//处理中(条)
	CC_SYNTHESIZE(int, deal, Deal);
	//派单(条)
	CC_SYNTHESIZE(int, sendList, SendList);
	//转单(条)   work_event表 pre_staff_id字段
	CC_SYNTHESIZE(int, transferList, TransferList);
	//退单(条)
	CC_SYNTHESIZE(int, chargeback, Chargeback);
	//已回访(条)  r_repair_return_visit表 visit_person_id字段
	CC_SYNTHESIZE(int, returnVisit, ReturnVisit);
	//已完结(条)
	CC_SYNTHESIZE(int, finish, Finish);
	//员工评分   examine_staff_value表 examine_value字段
	CC_SYNTHESIZE(string, examineValue, ExamineValue);
	//数据状态 包含:处理中(条)、派单(条)、转单(条)、退单(条)、已回访(条)、已完结(条) r_repair_user表 status_cd字段
	CC_SYNTHESIZE(string, statusCd, StatusCd);
	//小区名称
	CC_SYNTHESIZE(string, communityName, CommunityName);
public:
	RepairReportSummaryDO() {
		summaryId = 0;
		staffId = "";
		staffName = "";
		deal = 0;
		sendList = 0;
		transferList = 0;
		chargeback = 0;
		returnVisit = 0;
		finish = 0;
		examineValue = "";
		statusCd = "";
	}
	
};

// 给RepairReportSummaryDO智能指针设定一个别名方便使用
typedef std::shared_ptr<RepairReportSummaryDO> PtrRepairReportSummaryDO;
#endif // !_REPAIR_REPORT_SUMMARY_DO_

