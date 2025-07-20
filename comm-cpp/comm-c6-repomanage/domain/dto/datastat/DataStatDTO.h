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

#ifndef DATASTATDTO_H
#define DATASTATDTO_H

#include <domain/GlobalInclude.h>

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 费用类统计DTO
 */
 /*
  * 费用类统计DTO
  */
class ExpenseStatDTO final : public oatpp::DTO {
    DTO_INIT(ExpenseStatDTO, DTO);

    // 实收金额
    DTO_FIELD(Float64, receiveAmount);
    DTO_FIELD_INFO(receiveAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.receiveAmount");
    }

    // 欠费金额
    DTO_FIELD(Float64, owingAmount);
    DTO_FIELD_INFO(owingAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.owingAmount");
    }

    // 优惠金额
    DTO_FIELD(Float64, discountAmount);
    DTO_FIELD_INFO(discountAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.discountAmount");
    }

    // 滞纳金
    DTO_FIELD(Float64, penaltyAmount);
    DTO_FIELD_INFO(penaltyAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.penaltyAmount");
    }


    // 账户预存
    DTO_FIELD(Float64, accountDeposit);
    DTO_FIELD_INFO(accountDeposit) {
        info->description = ZH_WORDS_GETTER("datastat.costs.accountDeposit");
    }

    // 账户扣款
    DTO_FIELD(Float64, accountDeduction);
    DTO_FIELD_INFO(accountDeduction) {
        info->description = ZH_WORDS_GETTER("datastat.costs.accountDeduction");
    }

    // 临时车收入
    DTO_FIELD(Float64, tmpCarIncome);
    DTO_FIELD_INFO(tmpCarIncome) {
        info->description = ZH_WORDS_GETTER("datastat.costs.tmpCarIncome");
    }

    // 押金退款
    DTO_FIELD(Float64, depositRefund);
    DTO_FIELD_INFO(depositRefund) {
        info->description = ZH_WORDS_GETTER("datastat.costs.depositRefund");
    }


    // 退款订单数
    DTO_FIELD(Float64, refundOrderCount);
    DTO_FIELD_INFO(refundOrderCount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.refundOrderCount");
    }

    // 退款金额
    DTO_FIELD(Float64, refundAmount);
    DTO_FIELD_INFO(refundAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.refundAmount");
    }

    // 充电金额
    DTO_FIELD(Float64, chargingAmount);
    DTO_FIELD_INFO(chargingAmount) {
        info->description = ZH_WORDS_GETTER("datastat.costs.chargingAmount");
    }

    // 月卡实收
    DTO_FIELD(Float64, monthlyCardIncome);
    DTO_FIELD_INFO(monthlyCardIncome) {
        info->description = ZH_WORDS_GETTER("datastat.costs.monthlyCardIncome");
    }
};

/*
 * 工单类统计DTO
 */
class WorkOrderStatDTO final : public oatpp::DTO {
    DTO_INIT(WorkOrderStatDTO, DTO);

    // 投诉单
    DTO_FIELD(Int32, complaintCount);
    DTO_FIELD_INFO(complaintCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.complaintCount");
    }

    // 未完成投诉单
    DTO_FIELD(Int32, unfinishedComplaintCount);
    DTO_FIELD_INFO(unfinishedComplaintCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.unfinishedComplaintCount");
    }

    // 完成投诉单
    DTO_FIELD(Int32, finishedComplaintCount);
    DTO_FIELD_INFO(finishedComplaintCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.finishedComplaintCount");
    }

    // 报修单
    DTO_FIELD(Int32, repairCount);
    DTO_FIELD_INFO(repairCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.repairCount");
    }

    // 未完成报修单
    DTO_FIELD(Int32, unfinishedRepairCount);
    DTO_FIELD_INFO(unfinishedRepairCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.unfinishedRepairCount");
    }

    // 完成报修单
    DTO_FIELD(Int32, finishedRepairCount);
    DTO_FIELD_INFO(finishedRepairCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.finishedRepairCount");
    }

    // 巡检
    DTO_FIELD(Int32, inspectionCount);
    DTO_FIELD_INFO(inspectionCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.inspectionCount");
    }

    // 未完成巡检
    DTO_FIELD(Int32, unfinishedInspectionCount);
    DTO_FIELD_INFO(unfinishedInspectionCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.unfinishedInspectionCount");
    }

    // 完成巡检
    DTO_FIELD(Int32, finishedInspectionCount);
    DTO_FIELD_INFO(finishedInspectionCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.finishedInspectionCount");
    }

    // 保养
    DTO_FIELD(Int32, maintenanceCount);
    DTO_FIELD_INFO(maintenanceCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.maintenanceCount");
    }

    // 未完成保养
    DTO_FIELD(Int32, unfinishedMaintenanceCount);
    DTO_FIELD_INFO(unfinishedMaintenanceCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.unfinishedMaintenanceCount");
    }

    // 完成保养
    DTO_FIELD(Int32, finishedMaintenanceCount);
    DTO_FIELD_INFO(finishedMaintenanceCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.finishedMaintenanceCount");
    }

    // 业主反馈
    DTO_FIELD(Int32, ownerFeedbackCount);
    DTO_FIELD_INFO(ownerFeedbackCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.ownerFeedbackCount");
    }

    // 充电订单
    DTO_FIELD(Int32, chargingOrderCount);
    DTO_FIELD_INFO(chargingOrderCount) {
        info->description = ZH_WORDS_GETTER("datastat.workOrder.chargingOrderCount");
    }
};

/**
 * 出入类统计DTO
 */
class AccessStatDTO final : public oatpp::DTO {
    DTO_INIT(AccessStatDTO, DTO);

    // 进场车辆数
    DTO_FIELD(Int32, vehicleEntryCount);
    DTO_FIELD_INFO(vehicleEntryCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.vehicleEntryCount");
    }

    // 出场车辆数
    DTO_FIELD(Int32, vehicleExitCount);
    DTO_FIELD_INFO(vehicleExitCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.vehicleExitCount");
    }

    // 进场人员数
    DTO_FIELD(Int32, personnelEntryCount);
    DTO_FIELD_INFO(personnelEntryCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.personnelEntryCount");
    }

    // 人脸同步数
    DTO_FIELD(Int32, faceSyncCount);
    DTO_FIELD_INFO(faceSyncCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.faceSyncCount");
    }

    // 采购入库数
    DTO_FIELD(Int32, purchaseInboundCount);
    DTO_FIELD_INFO(purchaseInboundCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.purchaseInboundCount");
    }

    // 领用出库数
    DTO_FIELD(Int32, requisitionOutboundCount);
    DTO_FIELD_INFO(requisitionOutboundCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.requisitionOutboundCount");
    }

    // 采购入库金额
    DTO_FIELD(Float64, purchaseInboundAmount);
    DTO_FIELD_INFO(purchaseInboundAmount) {
        info->description = ZH_WORDS_GETTER("datastat.access.purchaseInboundAmount");
    }

    // 完成巡检
    DTO_FIELD(Int32, completedInspectionCount);
    DTO_FIELD_INFO(completedInspectionCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.completedInspectionCount");
    }

    // 调拨数量
    DTO_FIELD(Int32, allocationCount);
    DTO_FIELD_INFO(allocationCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.allocationCount");
    }

    // 房屋装修数
    DTO_FIELD(Int32, houseDecorationCount);
    DTO_FIELD_INFO(houseDecorationCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.houseDecorationCount");
    }

    // 物品放行
    DTO_FIELD(Int32, itemReleaseCount);
    DTO_FIELD_INFO(itemReleaseCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.itemReleaseCount");
    }

    // 交房数量
    DTO_FIELD(Int32, houseDeliveryCount);
    DTO_FIELD_INFO(houseDeliveryCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.houseDeliveryCount");
    }

    // 退房数量
    DTO_FIELD(Int32, houseReturnCount);
    DTO_FIELD_INFO(houseReturnCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.houseReturnCount");
    }

    // 业主绑定
    DTO_FIELD(Int32, ownerBindingCount);
    DTO_FIELD_INFO(ownerBindingCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.ownerBindingCount");
    }

    // 未考勤数
    DTO_FIELD(Int32, absenteeismCount);
    DTO_FIELD_INFO(absenteeismCount) {
        info->description = ZH_WORDS_GETTER("datastat.access.absenteeismCount");
    }
};

/**
 * 其他类统计DTO
 */
class OtherStatDTO final : public oatpp::DTO {
    DTO_INIT(OtherStatDTO, DTO);

    // 场地预约数
    DTO_FIELD(Int32, venueReservationCount);
    DTO_FIELD_INFO(venueReservationCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.venueReservationCount");
    }

    // 合同数
    DTO_FIELD(Int32, contractCount);
    DTO_FIELD_INFO(contractCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.contractCount");
    }

    // 合同资产变更数
    DTO_FIELD(Int32, contractAssetChangeCount);
    DTO_FIELD_INFO(contractAssetChangeCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.contractAssetChangeCount");
    }

    // 租期变更数
    DTO_FIELD(Int32, leaseTermChangeCount);
    DTO_FIELD_INFO(leaseTermChangeCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.leaseTermChangeCount");
    }

    // 主体变更数
    DTO_FIELD(Int32, entityChangeCount);
    DTO_FIELD_INFO(entityChangeCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.entityChangeCount");
    }

    // 到期合同数
    DTO_FIELD(Int32, expiringContractCount);
    DTO_FIELD_INFO(expiringContractCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.expiringContractCount");
    }

    // 车辆数
    DTO_FIELD(Int32, vehicleCount);
    DTO_FIELD_INFO(vehicleCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.vehicleCount");
    }

    // 车位申请数
    DTO_FIELD(Int32, parkingSpaceApplicationCount);
    DTO_FIELD_INFO(parkingSpaceApplicationCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.parkingSpaceApplicationCount");
    }

    // 停车券购买数
    DTO_FIELD(Int32, parkingTicketPurchaseCount);
    DTO_FIELD_INFO(parkingTicketPurchaseCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.parkingTicketPurchaseCount");
    }

    // 停车券核销数
    DTO_FIELD(Int32, parkingTicketVerificationCount);
    DTO_FIELD_INFO(parkingTicketVerificationCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.parkingTicketVerificationCount");
    }

    // 赠送优惠券数
    DTO_FIELD(Int32, giftCouponCount);
    DTO_FIELD_INFO(giftCouponCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.giftCouponCount");
    }

    // 使用优惠券数
    DTO_FIELD(Int32, usedCouponCount);
    DTO_FIELD_INFO(usedCouponCount) {
        info->description = ZH_WORDS_GETTER("datastat.other.usedCouponCount");
    }

    // 退房数量
    DTO_FIELD(Int32, houseReturnCount);
    DTO_FIELD_INFO(houseReturnCount) {
        info->description = ZH_WORDS_GETTER("datastat.field.houseReturnCount");
    }

    // 使用积分
    DTO_FIELD(Int32, pointsUsed);
    DTO_FIELD_INFO(pointsUsed) {
        info->description = ZH_WORDS_GETTER("datastat.field.pointsUsed");
    }
};

/*
 * 费用统计分页DTO
 */
class ExpenseStatPageDTO final : public PageDTO<ExpenseStatDTO::Wrapper> {
    DTO_INIT(ExpenseStatPageDTO, PageDTO<ExpenseStatDTO::Wrapper>);
};

/*
 * 工单统计分页DTO
 */
class WorkOrderStatPageDTO final : public PageDTO<WorkOrderStatDTO::Wrapper> {
    DTO_INIT(WorkOrderStatPageDTO, PageDTO<WorkOrderStatDTO::Wrapper>);
};

/*
 * 出入统计分页DTO
 */
class AccessStatPageDTO final : public PageDTO<AccessStatDTO::Wrapper> {
    DTO_INIT(AccessStatPageDTO, PageDTO<AccessStatDTO::Wrapper>);
};

/*
 * 其他统计分页DTO
 */
class OtherStatPageDTO final : public PageDTO<OtherStatDTO::Wrapper> {
    DTO_INIT(OtherStatPageDTO, PageDTO<OtherStatDTO::Wrapper>);
};



/**
 * 定义一个费用统计（不含欠费以及实收的所有费用传输）类数据传输模型
 */
class DataStatCostDTO : public oatpp::DTO
{
    DTO_INIT(DataStatCostDTO, DTO);
    // 物业
    API_DTO_FIELD_DEFAULT(Float64, wuye, ZH_WORDS_GETTER("datastat.field.cost.wuye"));
    // 押金
    API_DTO_FIELD_DEFAULT(Float64, yajin, ZH_WORDS_GETTER("datastat.field.cost.yajin"));
    // 停车费
    API_DTO_FIELD_DEFAULT(Float64, tingche, ZH_WORDS_GETTER("datastat.field.cost.tingche"));
    // 煤气费
    API_DTO_FIELD_DEFAULT(Float64, meiqi, ZH_WORDS_GETTER("datastat.field.cost.meiqi"));
    // 取暖费
    API_DTO_FIELD_DEFAULT(Float64, qunuan, ZH_WORDS_GETTER("datastat.field.cost.qunuan"));
    // 维修费
    API_DTO_FIELD_DEFAULT(Float64, weixiu, ZH_WORDS_GETTER("datastat.field.cost.weixiu"));
    // 其他
    API_DTO_FIELD_DEFAULT(Float64, qita, ZH_WORDS_GETTER("datastat.field.cost.qita"));
    // 服务费
    API_DTO_FIELD_DEFAULT(Float64, fuwu, ZH_WORDS_GETTER("datastat.field.cost.fuwu"));
    //水费
    API_DTO_FIELD_DEFAULT(Float64, shuifei, ZH_WORDS_GETTER("datastat.field.cost.shuifei"));
    //电费
    API_DTO_FIELD_DEFAULT(Float64, dianfei, ZH_WORDS_GETTER("datastat.field.cost.dianfei"));
    //租金
    API_DTO_FIELD_DEFAULT(Float64, zujin, ZH_WORDS_GETTER("datastat.field.cost.zujin"));
    // 公摊费
    API_DTO_FIELD_DEFAULT(Float64, gongtan, ZH_WORDS_GETTER("datastat.field.cost.gongtan"));
};

//定义实收统计对象继承费用类
class DataStatFinalCostDTO : public DataStatCostDTO
{
    DTO_INIT(DataStatFinalCostDTO, DataStatCostDTO);
    //楼栋
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.house"));
    //户数
    API_DTO_FIELD_DEFAULT(Int32, hostnum, ZH_WORDS_GETTER("datastat.field.host-num"));
    //收费户数
    API_DTO_FIELD_DEFAULT(Int32, costnum, ZH_WORDS_GETTER("datastat.field.cost-num"));
    //实收
    API_DTO_FIELD_DEFAULT(Float64, final, ZH_WORDS_GETTER("datastat.field.cost.final"));
    API_DTO_FIELD_DEFAULT(Float64, allfinal, ZH_WORDS_GETTER("datastat.field.cost.allfinal"));

};

//定义实收明细对象继承费用类
class DataStatDetailCostDTO : public DataStatCostDTO {

    DTO_INIT(DataStatDetailCostDTO, DataStatCostDTO);

    //实收
    API_DTO_FIELD_DEFAULT(Float64, final, ZH_WORDS_GETTER("datastat.field.cost.final"));
    //楼栋
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.house"));
    //业主
    API_DTO_FIELD_DEFAULT(String, host, ZH_WORDS_GETTER("datastat.field.host"));
    //总实收
    API_DTO_FIELD_DEFAULT(Float64, allfinal, ZH_WORDS_GETTER("datastat.field.cost.allfinal"));

};

//定义一个支付方式类
class DataStatMethodDTO : public oatpp::DTO {
    DTO_INIT(DataStatMethodDTO, DTO);

    API_DTO_FIELD_DEFAULT(Float64, cash, ZH_WORDS_GETTER("datastat.field.method.cash"));

    API_DTO_FIELD_DEFAULT(Float64, wechat, ZH_WORDS_GETTER("datastat.field.method.wechat"));

    API_DTO_FIELD_DEFAULT(Float64, zhifubao, ZH_WORDS_GETTER("datastat.field.method.zhifubao"));

    API_DTO_FIELD_DEFAULT(Float64, POS, ZH_WORDS_GETTER("datastat.field.method.POS"));

    API_DTO_FIELD_DEFAULT(Float64, Transfer, ZH_WORDS_GETTER("datastat.field.method.transfer"));

    API_DTO_FIELD_DEFAULT(Float64, refund, ZH_WORDS_GETTER("datastat.field.method.refund"));
};

//定义一个欠费统计类继承费用类
class DataStatQianfeiDTO : public DataStatCostDTO {
    DTO_INIT(DataStatQianfeiDTO, DataStatCostDTO);

    //楼栋
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.house"));

    //欠费
    API_DTO_FIELD_DEFAULT(Float64, qianfei, ZH_WORDS_GETTER("datastat.field.cost.qianfei"));

    //总欠费
    API_DTO_FIELD_DEFAULT(Float64, allqianfei, ZH_WORDS_GETTER("datastat.field.cost.allqianfei"));
};

class DataStatShishouPageDTO : public PageDTO<DataStatFinalCostDTO::Wrapper> {
    DTO_INIT(DataStatShishouPageDTO, PageDTO<DataStatFinalCostDTO::Wrapper>);
};
class DataStatShishouDetailPageDTO : public PageDTO<DataStatDetailCostDTO::Wrapper> {
    DTO_INIT(DataStatShishouDetailPageDTO, PageDTO<DataStatDetailCostDTO::Wrapper>);
};
class DataStatMethodPageDTO : public PageDTO<DataStatMethodDTO::Wrapper> {
    DTO_INIT(DataStatMethodPageDTO, PageDTO<DataStatMethodDTO::Wrapper>);
};
class DataStatQianfeiPageDTO : public PageDTO<DataStatQianfeiDTO::Wrapper> {
    DTO_INIT(DataStatQianfeiPageDTO, PageDTO<DataStatQianfeiDTO::Wrapper>);
};


/*              数据统计-3            */
/**
 * 欠费明细数据传输对象
 */
class DatastatFeeDetailDTO : public oatpp::DTO
{
    DTO_INIT(DatastatFeeDetailDTO, DTO);

    //房屋
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.module1.house"));
    //业主
    API_DTO_FIELD_DEFAULT(String, ow, ZH_WORDS_GETTER("datastat.field.module1.ow"));
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
 * 欠费明细分页数据传输对象
 */
class DatastatFeeDetailPageDTO : public PageDTO<DatastatFeeDetailDTO::Wrapper>
{
    DTO_INIT(DatastatFeeDetailPageDTO, PageDTO<DatastatFeeDetailDTO::Wrapper>);
};

/**
 * 收缴情况数据传输对象
 */
class DatastatChargeDetailDTO : public oatpp::DTO
{
    DTO_INIT(DatastatChargeDetailDTO, DTO);


    //楼栋
    API_DTO_FIELD_DEFAULT(String, building, ZH_WORDS_GETTER("datastat.field.module2.building"));
    //户数
    API_DTO_FIELD_DEFAULT(Int32, num_for_house, ZH_WORDS_GETTER("datastat.field.module2.num_for_house"));
    //收费户
    API_DTO_FIELD_DEFAULT(Int32, num_for_chargeable_house, ZH_WORDS_GETTER("datastat.field.module2.num_for_chargeable_house"));
    //历史欠费
    API_DTO_FIELD_DEFAULT(Int32, arrears_history, ZH_WORDS_GETTER("datastat.field.module2.arrears_history"));
    //总欠费
    API_DTO_FIELD_DEFAULT(Int32, all_arrears, ZH_WORDS_GETTER("datastat.field.module2.all_arrears"));
    //本日已交户数
    API_DTO_FIELD_DEFAULT(Int32, num_for_paid_house_today, ZH_WORDS_GETTER("datastat.field.module2.num_for_paid_house_today"));
    //本日已交金额
    API_DTO_FIELD_DEFAULT(Int32, cost_for_paid_today, ZH_WORDS_GETTER("datastat.field.module2.cost_for_paid_today"));
    //历史欠费清缴户
    API_DTO_FIELD_DEFAULT(Int32, num_for_notpaid_house_history, ZH_WORDS_GETTER("datastat.field.module2.num_for_notpaid_house_history"));
    //历史欠费清缴金额
    API_DTO_FIELD_DEFAULT(Int32, cost_for_arrears_history, ZH_WORDS_GETTER("datastat.field.module2.cost_for_arrears_history"));
    //本月已收户数
    API_DTO_FIELD_DEFAULT(Int32, num_for_paid_house_month, ZH_WORDS_GETTER("datastat.field.module2.num_for_paid_house_month"));
    //剩余户数
    API_DTO_FIELD_DEFAULT(Int32, num_for_last_house, ZH_WORDS_GETTER("datastat.field.module2.num_for_last_house"));
    //已收户占比
    API_DTO_FIELD_DEFAULT(Int32, percentage_for_paid_house, ZH_WORDS_GETTER("datastat.field.module2.percentage_for_paid_house"));
    //当月已收金额
    API_DTO_FIELD_DEFAULT(Int32, fees_for_received_month, ZH_WORDS_GETTER("datastat.field.module2.fees_for_received_month"));
    //当月剩余未收
    API_DTO_FIELD_DEFAULT(Int32, fees_for_notreceived_month, ZH_WORDS_GETTER("datastat.field.module2.fees_for_notreceived_month"));
    //收费率
    API_DTO_FIELD_DEFAULT(Float32, charge_rate, ZH_WORDS_GETTER("datastat.field.module2.charge_rate"));
};

/**
 * 收缴情况分页数据传输对象
 */
class DatastatChargeDetailPageDTO : public PageDTO<DatastatChargeDetailDTO::Wrapper>
{
    DTO_INIT(DatastatChargeDetailPageDTO, PageDTO<DatastatChargeDetailDTO::Wrapper>);
};

/**
 * 月实收明细数据传输对象
 */
class DatastatMonthDetailDTO : public oatpp::DTO
{
    DTO_INIT(DatastatMonthDetailDTO, DTO);

    //房屋编号
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.module3.house"));
    //业主
    API_DTO_FIELD_DEFAULT(String, ow, ZH_WORDS_GETTER("datastat.field.module3.ow"));
    //实收
    API_DTO_FIELD_DEFAULT(Int32, final, ZH_WORDS_GETTER("datastat.field.module3.final"));
    //费用名称
    API_DTO_FIELD_DEFAULT(String, name_fee, ZH_WORDS_GETTER("datastat.field.module3.name_fee"));
    //实收时间段
    API_DTO_FIELD_DEFAULT(String, time_income, ZH_WORDS_GETTER("datastat.field.module3.time_income"));
    //收银员
    API_DTO_FIELD_DEFAULT(String, cashier, ZH_WORDS_GETTER("datastat.field.module3.cashier"));
    //交费时间
    API_DTO_FIELD_DEFAULT(String, time_pay, ZH_WORDS_GETTER("datastat.field.module3.time_pay"));

};

/**
 * 月实收明细分页数据传输对象
 */
class DatastatMonthDetailPageDTO : public PageDTO<DatastatMonthDetailDTO::Wrapper>
{
    DTO_INIT(DatastatMonthDetailPageDTO, PageDTO<DatastatMonthDetailDTO::Wrapper>);
};

/**
 * 月欠费明细数据传输对象
 */
class DatastatMonthFeeDTO : public oatpp::DTO
{
    DTO_INIT(DatastatMonthFeeDTO, DTO);


    //房屋
    API_DTO_FIELD_DEFAULT(String, house, ZH_WORDS_GETTER("datastat.field.module3.house"));
    //业主
    API_DTO_FIELD_DEFAULT(String, ow, ZH_WORDS_GETTER("datastat.field.module3.builowding"));
    //费用名称
    API_DTO_FIELD_DEFAULT(String, arrears_name, ZH_WORDS_GETTER("datastat.field.module3.arrears_name"));
    //欠费时间段
    API_DTO_FIELD_DEFAULT(String, arrears_time, ZH_WORDS_GETTER("datastat.field.module3.arrears_time"));
    //欠费金额
    API_DTO_FIELD_DEFAULT(Int32, arrears_num, ZH_WORDS_GETTER("datastat.field.module3.arrears_num"));
};


/**
 * 月欠费明细分页数据传输对象
 */
class DatastatMonthFeePageDTO : public PageDTO<DatastatMonthFeeDTO::Wrapper>
{
    DTO_INIT(DatastatMonthFeePageDTO, PageDTO<DatastatMonthFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !DATASTATDTO_H