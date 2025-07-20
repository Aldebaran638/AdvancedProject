#pragma once
#pragma once
#ifndef _EXPESUMDO_H_
#define _EXPESUMDO_H_
#include "../DoInclude.h"

// 楼栋收费率子模块
class BuildingRateDO {
    CC_SYNTHESIZE(double, curReceivableFee, CurReceivableFee); //实收总金额
    CC_SYNTHESIZE(double, curReceivedFee, CurReceivedFee);     //应收总金额
    CC_SYNTHESIZE(string, feeTypes, FeeTypes);               // 费率类型（0-固定单价 1-比例）
    CC_SYNTHESIZE(double, feeRoomCount, FeeRoomCount);       //有效收费房间数量
    CC_SYNTHESIZE(double, oweRoomCount, OweRoomCount);       //欠费房间数量 
    CC_SYNTHESIZE(double, buildRate, BuildRate);                //费用项收费率
    CC_SYNTHESIZE(string, buildingName, BuildingName);        // 楼栋唯一标识
    CC_SYNTHESIZE(string, startDate, StartDate);          // 起始日期
    CC_SYNTHESIZE(string, endDate, EndDate);              // 结束日期
    CC_SYNTHESIZE(string, ownerName, OwnerName);          // 业主名称
    CC_SYNTHESIZE(string, ownerNumber, OwnerNumber);      // 业主手机号
    CC_SYNTHESIZE(string, communityId, CommunityId);      // 小区号
    CC_SYNTHESIZE(string, roomNum, RoomNum);      // 房间号

public:
    BuildingRateDO() {
        buildingName = "";
        feeTypes = "";
        startDate = "";
        endDate = "";
        ownerName = "";
        ownerNumber = "";
        communityId = "";
        curReceivableFee = 0.0;
        curReceivedFee = 0.0;
        feeTypes = "";
        feeRoomCount = 0.0;
        oweRoomCount = 0.0;
        buildRate = 0.0;
        roomNum = "";
    }
};
typedef std::shared_ptr<BuildingRateDO> PtrBuildingRateDO;
// 费用项收费率子模块
class FeeItemRateDO {
    CC_SYNTHESIZE(double, curReceivableFee, CurReceivableFee); //实收总金额
    CC_SYNTHESIZE(double, curReceivedFee, CurReceivedFee);     //应收总金额
    CC_SYNTHESIZE(string, feeTypes, FeeTypes);               // 费率类型（0-固定单价 1-比例）
    CC_SYNTHESIZE(double, feeRoomCount, FeeRoomCount);       //有效收费房间数量
    CC_SYNTHESIZE(double, oweRoomCount, OweRoomCount);       //欠费房间数量 
    CC_SYNTHESIZE(double, itemRate, ItemRate);                //费用项收费率
    CC_SYNTHESIZE(string, buildingName, BuildingName);        // 楼栋唯一标识
    CC_SYNTHESIZE(string, startDate, StartDate);          // 起始日期
    CC_SYNTHESIZE(string, endDate, EndDate);              // 结束日期
    CC_SYNTHESIZE(string, ownerName, OwnerName);          // 业主名称
    CC_SYNTHESIZE(string, ownerNumber, OwnerNumber);      // 业主手机号
    CC_SYNTHESIZE(string, communityId, CommunityId);      // 小区号
    CC_SYNTHESIZE(string, roomNum, RoomNum);      // 小区号
public:
    FeeItemRateDO() {

        buildingName = "";
        feeTypes = "";
        startDate = "";
        endDate = "";
        ownerName = "";
        ownerNumber = "";
        communityId = "";
        curReceivableFee = 0.0;
        curReceivedFee = 0.0;
        feeTypes = "";
        feeRoomCount = 0.0;
        oweRoomCount = 0.0;
        itemRate = 0.0;
        roomNum = "";

    }
};
typedef std::shared_ptr<FeeItemRateDO> PtrFeeItemRateDO;


/*          费用汇总-2           */

/**
* 费用汇总表数据库实体类
*/
class ExpeSumDO
{

    // 总户数
    CC_SYNTHESIZE(int, totalRoomCount, TotalRoomCount);
    // 收费户数
    CC_SYNTHESIZE(int, feeRoomCount, FeeRoomCount);
    // 欠费户数
    CC_SYNTHESIZE(int, oweRoomCount, OweRoomCount);
    // 历史欠费
    CC_SYNTHESIZE(double, hisOweFee, HisOweFee);
    // 当前欠费
    CC_SYNTHESIZE(double, curOweFee, CurOweFee);
    // 当前应收
    CC_SYNTHESIZE(double, curReceivableFee, CurReceivableFee);
    // 当前实收
    CC_SYNTHESIZE(double, curReceivedFee, CurReceivedFee);
    // 历史实收
    CC_SYNTHESIZE(double, hisReceivedFee, HisReceivedFee);
    // 预收款
    CC_SYNTHESIZE(double, preReceivedFee, PreReceivedFee);
public:
    ExpeSumDO() {
        totalRoomCount = 0;
        feeRoomCount = 0;
        oweRoomCount = 0;
        hisOweFee = 0.0;
        curOweFee = 0.0;
        curReceivableFee = 0.0;
        curReceivedFee = 0.0;
        hisReceivedFee = 0.0;
        preReceivedFee = 0.0;
    }
};

// 给ExpeSumDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ExpeSumDO> PtrExpeSumDO;
#endif