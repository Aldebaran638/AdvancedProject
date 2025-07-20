#pragma once

#ifndef _EXPEREM_DO_
#define _EXPEREM_DO_
#include "../DoInclude.h"
class ExpeRemDO {
private:

    // 房屋编号/合同名称
    CC_SYNTHESIZE(string, objName, ObjName);
    // 业主名称
    CC_SYNTHESIZE(string, ownerName, OwnerName);
    // 业主手机号
    CC_SYNTHESIZE(string, link, Link);
    // 费用项
    CC_SYNTHESIZE(string, feeName, FeeName);
    // 费用id
    CC_SYNTHESIZE(string, feeId, FeeId);
    // 付费对象类型 3333 房屋 6666 是车位
    CC_SYNTHESIZE(std::string, payerObjType, PayerObjType);
    // 费用开始时间
    CC_SYNTHESIZE(string, startTime, StartTime);
    // 结束时间
    CC_SYNTHESIZE(int, endTime, EndTime);
public:
    ExpeRemDO() {
        feeName = "";
        objName = "";
        link = "";
        ownerName = "";
        startTime = "";
        feeId = "";
        endTime = 0;
        payerObjType = "";
    }
};

typedef std::shared_ptr<ExpeRemDO> PtrExpeRemDO;



/////////////////////////////


/**
 * 示例数据库实体类
 */
class overExpeRemDO
{
    // 费用编号
    CC_SYNTHESIZE(string, feeid, Feeid);
    // 房号/车辆/合同
    CC_SYNTHESIZE(string, buildno, Buildno);
    // 费用项
    CC_SYNTHESIZE(string, expense, Expense);
    // 费用结束时间
    CC_SYNTHESIZE(string, endtime, Endtime);
    // 距离费用结束时间
    CC_SYNTHESIZE(string, remainingtime, Remainingtime);
public:
    overExpeRemDO() {
        feeid = "";
        buildno = "";
        expense = "";
        endtime = "";
        remainingtime = "";
    }
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<overExpeRemDO> PtroverExpeRemDO;
#endif // !_EXPEREM_DO_
