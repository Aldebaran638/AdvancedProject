/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2024/5/24

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

#include <stdafx.h>

#include "DataStatDAO.h"
#include "DataStatMapper.h"

#include <sstream>
#include <iostream>
#include <list>
// Add missing SQL includes
#include "SqlSession.h"
#include "BaseDAO.h"
// Add DTO includes
#include "../../domain/dto/datastat/DataStatDTO.h"

using namespace std;

ExpenseStatDTO::Wrapper DataStatDao::queryExpense(const ExpenseStatQuery::Wrapper& query) {
    auto expenStatDTO = ExpenseStatDTO::createShared();

    expenStatDTO->receiveAmount = queryreceiveAmount(query);
	expenStatDTO->owingAmount = queryowingAmount(query);
	expenStatDTO->discountAmount = querydiscountAmount(query);
	expenStatDTO->penaltyAmount = querylateFeeAmount(query);
	expenStatDTO->accountDeposit = queryaccountPreAmount(query);
	expenStatDTO->accountDeduction = queryaccountDeductAmount(query);
	expenStatDTO->tmpCarIncome = querytempCarIncomeAmount(query);
	expenStatDTO->depositRefund = querydepositRefundAmount(query);
	expenStatDTO->refundOrderCount = queryrefundOrderCount(query);
	expenStatDTO->refundAmount = queryrefundAmount(query);
	expenStatDTO->chargingAmount = querychargeAmount(query);
	expenStatDTO->monthlyCardIncome = querymonthCardReceiveAmount(query);

    return expenStatDTO;
}

WorkOrderStatDTO::Wrapper DataStatDao::queryWorkOrder(const WorkOrderStatQuery::Wrapper& query) {
	auto workOrderStatDTO = WorkOrderStatDTO::createShared();

	workOrderStatDTO->complaintCount = querycomplaintCount(query);
	workOrderStatDTO->unfinishedComplaintCount = queryunfinishedComplaintCount(query);
	workOrderStatDTO->finishedComplaintCount = queryfinishedComplaintCount(query);
	workOrderStatDTO->repairCount = queryrepairCount(query);
	workOrderStatDTO->unfinishedRepairCount = queryunfinishedRepairCount(query);
	workOrderStatDTO->finishedRepairCount = queryfinishedRepairCount(query);
	workOrderStatDTO->inspectionCount = queryinspectionCount(query);
	workOrderStatDTO->unfinishedInspectionCount = queryunfinishedInspectionCount(query);
	workOrderStatDTO->finishedInspectionCount = queryfinishedInspectionCount(query);
	workOrderStatDTO->maintenanceCount = querymaintenanceCount(query);
	workOrderStatDTO->unfinishedMaintenanceCount = queryunfinishedMaintenanceCount(query);
	workOrderStatDTO->finishedMaintenanceCount = queryfinishedMaintenanceCount(query);
	workOrderStatDTO->ownerFeedbackCount = queryownerFeedbackCount(query);
	workOrderStatDTO->chargingOrderCount = querychargeOrderCount(query);

	return workOrderStatDTO;
}

AccessStatDTO::Wrapper DataStatDao::queryAccess(const AccessStatQuery::Wrapper& query) {
    auto accessStatDTO = AccessStatDTO::createShared();

    accessStatDTO->vehicleEntryCount = queryvehicleEntryCount(query);
    accessStatDTO->vehicleExitCount = queryvehicleExitCount(query);
    accessStatDTO->personnelEntryCount = querypersonEntryCount(query);
    accessStatDTO->faceSyncCount = queryfaceSyncCount(query);
    accessStatDTO->purchaseInboundCount = querypurchaseInboundCount(query);
    accessStatDTO->requisitionOutboundCount = querylendOutboundCount(query);
    accessStatDTO->purchaseInboundAmount = querypurchaseInboundAmount(query);
    accessStatDTO->completedInspectionCount = queryfinishedInspectionCount(query);
    accessStatDTO->allocationCount = querytransferCount(query);
    accessStatDTO->houseDecorationCount = queryhouseDecorationCount(query);
    accessStatDTO->itemReleaseCount = queryitemReleaseCount(query);
    accessStatDTO->houseDeliveryCount = queryhouseDeliveryCount(query);
    accessStatDTO->houseReturnCount = queryhouseReturnCount(query);
    accessStatDTO->ownerBindingCount = queryownerBindingCount(query);
    accessStatDTO->absenteeismCount = queryabsenceCount(query);

    return accessStatDTO;
}

OtherStatDTO::Wrapper DataStatDao::queryOther(const OtherStatQuery::Wrapper& query) {
    auto otherStatDTO = OtherStatDTO::createShared();

    otherStatDTO->venueReservationCount = queryplaceReservationCount(query);
    otherStatDTO->contractCount = querycontractCount(query);
    otherStatDTO->contractAssetChangeCount = querycontractAssetChangeCount(query);
    otherStatDTO->leaseTermChangeCount = queryleaseTermChangeCount(query);
    otherStatDTO->entityChangeCount = querysubjectChangeCount(query);
    otherStatDTO->expiringContractCount = queryexpiredContractCount(query);
    otherStatDTO->vehicleCount = queryvehicleCount(query);
    otherStatDTO->parkingSpaceApplicationCount = queryparkingSpaceApplicationCount(query);
    otherStatDTO->parkingTicketPurchaseCount = queryparkingTicketPurchaseCount(query);
    otherStatDTO->parkingTicketVerificationCount = queryparkingTicketVerificationCount(query);
    otherStatDTO->giftCouponCount = querycouponGiftCount(query);
    otherStatDTO->usedCouponCount = querycouponUseCount(query);
    otherStatDTO->houseReturnCount = queryhouseReturnCount(query);
    otherStatDTO->pointsUsed = queryintegralUseCount(query);

    return otherStatDTO;
}





// 实收金额
double DataStatDao::queryreceiveAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;

    std::string querycondition = " WHERE 1=1";

    // 社区ID
    if (query->communityId) {
        querycondition += " AND community_id=?";
    }

    // 为每个子查询绑定社区ID参数
    if (query->communityId) {
        for (int i = 0; i < 10; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    // 构建SQL
    std::string sql = R"(
        SELECT COALESCE(SUM(total_received), 0.0) as total_amount FROM (
            -- 账户收据表
            SELECT SUM(received_amount) as total_received 
            FROM account_receipt 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 费用收据表
            SELECT SUM(amount) as total_received 
            FROM fee_receipt 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 停车券订单表
            SELECT SUM(received_amount) as total_received 
            FROM parking_coupon_order 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 预约商品订单表
            SELECT SUM(received_amount) as total_received 
            FROM reserve_goods_order 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 充电月卡订单表
            SELECT SUM(received_amount) as total_received 
            FROM charge_month_order 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 场地预约表
            SELECT SUM(received_amount) as total_received 
            FROM community_space_person 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 停车缴费表
            SELECT SUM(CAST(real_charge AS DECIMAL(10,2))) as total_received 
            FROM car_inout_payment 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 减去业务退费表
            SELECT -SUM(received_amount) as total_received 
            FROM business_return_pay_fee 
            )" + querycondition + R"( AND state = '1001'
            
            UNION ALL
            
            -- 减去普通退费表
            SELECT -SUM(received_amount) as total_received 
            FROM return_pay_fee 
            )" + querycondition + R"( AND state = '1001' AND status_cd = '0'
        ) AS combined_amounts
    )";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql, mapper, params);

    return result;
}

// 欠费金额
double DataStatDao::queryowingAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;

    std::string querycondition = " WHERE 1=1";

    // 社区ID
    if (query->communityId) {
        querycondition += " AND community_id=?";
    }

    // 为每个子查询绑定社区ID参数
    if (query->communityId) {
        for (int i = 0; i < 4; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    // 构建SQL
    std::string sql = R"(
        SELECT COALESCE(SUM(total_owed), 0.0) as total_amount FROM (
            -- 账单欠费表
            SELECT SUM(amount_owed) as total_owed 
            FROM bill_owe_fee 
            )" + querycondition + R"( AND state = '1000'
            
            UNION ALL
            
            -- 催缴明细表中的欠费
            SELECT SUM(owe_amount) as total_owed 
            FROM fee_collection_detail 
            )" + querycondition + R"( AND status_cd = '0' AND state != 'F'
            
            UNION ALL
            
            -- 费用月统计表中的欠费
            SELECT SUM(owe_amount) as total_owed 
            FROM report_fee_month_statistics 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 欠费报表
            SELECT SUM(amount_owed) as total_owed 
            FROM report_owe_fee 
            )" + querycondition + R"(
        ) AS combined_amounts
    )";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql, mapper, params);

    return result;
}

// 优惠金额
double DataStatDao::querydiscountAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;

    std::string querycondition = " WHERE 1=1";

    // 只添加社区ID条件
    if (query->communityId) {
        querycondition += " AND community_id=?";
    }

    // 为每个子查询绑定社区ID参数
    if (query->communityId) {
        for (int i = 0; i < 5; i++) {  // 5个子查询
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    // 构建SQL
    std::string sql = R"(
        SELECT COALESCE(SUM(total_discount), 0.0) as total_amount FROM (
            -- 缴费明细表中的优惠金额
            SELECT SUM(discount_amount) as total_discount 
            FROM pay_fee_detail 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 月度缴费明细表中的优惠金额
            SELECT SUM(discount_amount) as total_discount 
            FROM pay_fee_detail_month 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 缴费明细折扣表
            SELECT SUM(discount_price) as total_discount 
            FROM pay_fee_detail_discount 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 业务缴费明细表中的优惠金额
            SELECT SUM(discount_amount) as total_discount 
            FROM business_pay_fee_detail 
            )" + querycondition + R"(
            
            UNION ALL
            
            -- 业务缴费明细折扣表
            SELECT SUM(discount_price) as total_discount 
            FROM business_pay_fee_detail_discount 
            )" + querycondition + R"(
        ) AS combined_amounts
    )";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql, mapper, params);

    return result;
}

// 滞纳金
double DataStatDao::querylateFeeAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        for (int i = 0; i < 2; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(total_late), 0.0) as total_amount FROM (
            -- 缴费明细表中的滞纳金
            SELECT SUM(late_amount) as total_late 
            FROM pay_fee_detail 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 业务缴费明细表中的滞纳金
            SELECT SUM(late_amount) as total_late 
            FROM business_pay_fee_detail 
            )" + querycondition + R"(
        ) AS combined_amounts
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 账户预存
double DataStatDao::queryaccountPreAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND obj_id IN (SELECT owner_id FROM building_owner WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(amount), 0.0) as total_amount 
        FROM account_detail 
        )" + querycondition + R"( AND status_cd = '0' AND detail_type = '1001'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 账户扣款
double DataStatDao::queryaccountDeductAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        for (int i = 0; i < 2; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(total_acct), 0.0) as total_amount FROM (
            -- 缴费明细表中的账户抵扣金额
            SELECT SUM(acct_amount) as total_acct 
            FROM pay_fee_detail 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 业务缴费明细表中的账户抵扣金额
            SELECT SUM(acct_amount) as total_acct 
            FROM business_pay_fee_detail 
            )" + querycondition + R"(
        ) AS combined_amounts
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 临时车收入
double DataStatDao::querytempCarIncomeAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND cip.community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(CAST(cip.real_charge AS DECIMAL(10,2))), 0.0) as total_amount 
        FROM car_inout_payment cip 
        JOIN car_inout_detail cid ON cip.inout_id = cid.inout_id 
        )" + querycondition + R"( AND cip.status_cd = '0' AND cid.car_type = '1003'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 押金退款，这个没找到表
double DataStatDao::querydepositRefundAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        // 通过obj_id关联到店铺，再关联到community_id
        querycondition += " AND obj_id IN (SELECT store_id FROM s_store WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(received_amount), 0.0) as total_amount 
        FROM account_bond_obj_detail 
        )" + querycondition + R"( AND status_cd = '0' AND state = '3309'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 退款订单数
double DataStatDao::queryrefundOrderCount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM online_pay_refund 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'CT'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 退款金额
double DataStatDao::queryrefundAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(refund_fee), 0.0) as total_amount 
        FROM online_pay_refund 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'CT'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 充电金额
double DataStatDao::querychargeAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(received_amount), 0.0) as total_amount 
        FROM charge_month_order 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 月卡实收
double DataStatDao::querymonthCardReceiveAmount(const ExpenseStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(received_amount), 0.0) as total_amount 
        FROM charge_month_order 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}




// 投诉单
double DataStatDao::querycomplaintCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM complaint 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 未完成投诉单
double DataStatDao::queryunfinishedComplaintCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM complaint 
        )" + querycondition + R"( AND status_cd = '0' AND state != 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 完成投诉单
double DataStatDao::queryfinishedComplaintCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM complaint 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 报修单
double DataStatDao::queryrepairCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 未完成报修单
double DataStatDao::queryunfinishedRepairCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND state != 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 完成报修单
double DataStatDao::queryfinishedRepairCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 巡检
double DataStatDao::queryinspectionCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM inspection_task 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 未完成巡检
double DataStatDao::queryunfinishedInspectionCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM inspection_task 
        )" + querycondition + R"( AND status_cd = '0' AND state != '20200407'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 完成巡检
double DataStatDao::queryfinishedInspectionCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM inspection_task 
        )" + querycondition + R"( AND status_cd = '0' AND state = '20200407'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 保养
double DataStatDao::querymaintenanceCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND maintenance_type = '1002'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 未完成保养
double DataStatDao::queryunfinishedMaintenanceCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND maintenance_type = '1002' AND state != 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 完成保养
double DataStatDao::queryfinishedMaintenanceCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM r_repair_pool 
        )" + querycondition + R"( AND status_cd = '0' AND maintenance_type = '1002' AND state = 'COMPLETED'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 业主反馈
double DataStatDao::queryownerFeedbackCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM complaint 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 充电订单
double DataStatDao::querychargeOrderCount(const WorkOrderStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        for (int i = 0; i < 2; i++) {
            SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
        }
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(total_orders), 0) as total_amount FROM (
            -- 充电设备订单
            SELECT COUNT(*) as total_orders 
            FROM charge_machine_order 
            )" + querycondition + R"( AND status_cd = '0'
            
            UNION ALL
            
            -- 充电月卡订单
            SELECT COUNT(*) as total_orders 
            FROM charge_month_order 
            )" + querycondition + R"( AND status_cd = '0'
        ) AS combined_orders
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}





// 车辆进出数量
double DataStatDao::queryvehicleEntryCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM car_inout_detail 
        )" + querycondition + R"( AND car_inout = '3306' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 车辆出场数量
double DataStatDao::queryvehicleExitCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM car_inout_detail 
        )" + querycondition + R"( AND car_inout = '3307' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 人员进入数量
double DataStatDao::querypersonEntryCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM access_control_white 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 人脸同步数量
double DataStatDao::queryfaceSyncCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM access_control_white 
        )" + querycondition + R"( AND status_cd = '0' AND third_id IS NOT NULL
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 采购入库数量
double DataStatDao::querypurchaseInboundCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM purchase_apply 
        )" + querycondition + R"( AND res_order_type = '10000' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 借用出库数量
double DataStatDao::querylendOutboundCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM purchase_apply 
        )" + querycondition + R"( AND res_order_type = '20000' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 采购入库金额
double DataStatDao::querypurchaseInboundAmount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND pa.community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(SUM(pad.price * CAST(pad.purchase_quantity AS DECIMAL(10,2))), 0.0) as total_amount 
        FROM purchase_apply_detail pad 
        JOIN purchase_apply pa ON pad.apply_order_id = pa.apply_order_id 
        )" + querycondition + R"( AND pa.res_order_type = '10000' AND pa.status_cd = '0' AND pad.status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 完成巡检
double DataStatDao::queryfinishedInspectionCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COALESCE(COUNT(*), 0) as total_amount 
        FROM inspection_task 
        )" + querycondition + R"( AND status_cd = '0' AND state = '20200407'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 调拨数量
double DataStatDao::querytransferCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM allocation_storehouse 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 房屋装修数量
double DataStatDao::queryhouseDecorationCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM room_renovation 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 物品发放数量
double DataStatDao::queryitemReleaseCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM item_release 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 房屋交付数量
double DataStatDao::queryhouseDeliveryCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM owner_settled_apply 
        )" + querycondition + R"( AND state = 'C' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 退房数量
double DataStatDao::queryhouseReturnCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM return_pay_fee 
        )" + querycondition + R"( AND state = '1001' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 业主绑定数量
double DataStatDao::queryownerBindingCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM owner_app_user 
        )" + querycondition + R"( AND state = '12000' AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 未到场数量
double DataStatDao::queryabsenceCount(const AccessStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        // 通过store_id关联到community_id，因为attendance_log表没有community_id字段
        querycondition += " AND store_id IN (SELECT store_id FROM s_store WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    // 统计今天应该打卡但没有打卡记录的员工数量
    std::string sql = R"(
        SELECT COUNT(DISTINCT staff_id) as total_count 
        FROM (
            SELECT staff_id FROM s_staff 
            )" + querycondition + R"( AND status_cd = '0'
            AND staff_id NOT IN (
                SELECT DISTINCT staff_id FROM attendance_log 
                WHERE DATE(clock_time) = CURDATE() AND status_cd = '0'
            )
        ) AS absent_staff
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}




// 场地预约数
double DataStatDao::queryplaceReservationCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM community_space_person 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 合同数
double DataStatDao::querycontractCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        // 通过store_id关联到community_id
        querycondition += " AND store_id IN (SELECT store_id FROM s_store WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 合同资产变更数
double DataStatDao::querycontractAssetChangeCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND contract_id IN (SELECT contract_id FROM contract WHERE store_id IN (SELECT store_id FROM s_store WHERE community_id=?))";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract_change_plan 
        )" + querycondition + R"( AND status_cd = '0' AND plan_type = '3003'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 租期变更数
double DataStatDao::queryleaseTermChangeCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND contract_id IN (SELECT contract_id FROM contract WHERE store_id IN (SELECT store_id FROM s_store WHERE community_id=?))";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    // 修复：使用plan_type字段，2002表示租期调整
    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract_change_plan 
        )" + querycondition + R"( AND status_cd = '0' AND plan_type = '2002'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 主体变更数
double DataStatDao::querysubjectChangeCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND contract_id IN (SELECT contract_id FROM contract WHERE store_id IN (SELECT store_id FROM s_store WHERE community_id=?))";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    // 修复：使用plan_type字段，1001表示主体变更
    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract_change_plan 
        )" + querycondition + R"( AND status_cd = '0' AND plan_type = '1001'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 到期合同数
double DataStatDao::queryexpiredContractCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND store_id IN (SELECT store_id FROM s_store WHERE community_id=?)";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM contract 
        )" + querycondition + R"( AND status_cd = '0' AND end_time < NOW()
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 车辆数
double DataStatDao::queryvehicleCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM owner_car 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 车位申请数
double DataStatDao::queryparkingSpaceApplicationCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM parking_space_apply 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 停车券购买数
double DataStatDao::queryparkingTicketPurchaseCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM parking_coupon_order 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 停车券核销数
double DataStatDao::queryparkingTicketVerificationCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM community_space_person_time 
        )" + querycondition + R"( AND status_cd = '0' AND state = 'C'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 赠送优惠券数
double DataStatDao::querycouponGiftCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM coupon_property_user 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 使用优惠券数
double DataStatDao::querycouponUseCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM coupon_property_user_detail 
        )" + querycondition + R"( AND status_cd = '0' AND detail_type = 'USE'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 退房数量
double DataStatDao::queryhouseReturnCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT COUNT(*) as total_count 
        FROM coupon_property_user_detail 
        )" + querycondition + R"( AND status_cd = '0' AND detail_type = 'USE'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

// 使用积分
double DataStatDao::queryintegralUseCount(const OtherStatQuery::Wrapper& query) {
    SqlParams params;
    std::string querycondition = " WHERE 1=1";

    if (query->communityId) {
        querycondition += " AND community_id=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId);
    }

    std::string sql = R"(
        SELECT SUM(use_quantity) as total_count 
        FROM integral_user_detail 
        )" + querycondition + R"( AND status_cd = '0'
    )";

    DoubleMapper mapper;
    return sqlSession->executeQueryOne<double>(sql, mapper, params);
}

/*                                            22222222222222222222222           2                                               */
// 查询条件构建器
std::string DataStatDao::queryConditionBuilder(const oatpp::Object<DataStatALLSearchQuery>& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    if (query->communityId) {
        sqlCondition << " AND community_id = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    if (query->begintime) {
        sqlCondition << " AND create_time >= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    if (query->endtime) {
        sqlCondition << " AND create_time <= ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    return sqlCondition.str();
}

list<DataStatFinalCostDO> DataStatDao::queryShishou(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // 先执行一个简单的测试查询，看看是否有楼栋数据
    stringstream testSql;
    testSql << "SELECT COUNT(*) FROM f_floor WHERE status_cd = '0'";
    if (query->communityId) {
        testSql << " AND community_id = ?";
        SqlParams testParams;
        SQLPARAMS_PUSH(testParams, "s", std::string, query->communityId.getValue(""));
        auto count = sqlSession->executeQueryNumerical(testSql.str(), testParams);
        cout << "Total floors in community: " << count << endl;
    }
    else {
        auto count = sqlSession->executeQueryNumerical(testSql.str());
        cout << "Total floors: " << count << endl;
    }

    // 按楼栋分组统计各项费用实收情况
    sql << "SELECT ";
    sql << "CONCAT(f.floor_num, '栋') as house, ";
    // 业主数量 - 统计该楼栋下的业主数
    sql << "COUNT(DISTINCT br.owner_id) as hostnum, ";
    // 缴费户数 - 统计该楼栋下有缴费记录的房屋数
    sql << "COUNT(DISTINCT CASE WHEN pfd.detail_id IS NOT NULL THEN br.room_id END) as costnum, ";

    // 各费用类型的实收金额统计 - 基于TT.sql的正确费用类型编码
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010001' THEN pfd.received_amount ELSE 0 END), 0) as wuye, ";      // 物业费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010006' THEN pfd.received_amount ELSE 0 END), 0) as yajin, ";     // 押金
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010008' THEN pfd.received_amount ELSE 0 END), 0) as tingche, ";   // 停车费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010009' THEN pfd.received_amount ELSE 0 END), 0) as meiqi, ";     // 煤气费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010011' THEN pfd.received_amount ELSE 0 END), 0) as qunuan, ";    // 取暖费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010012' THEN pfd.received_amount ELSE 0 END), 0) as weixiu, ";    // 维修费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010014' THEN pfd.received_amount ELSE 0 END), 0) as qita, ";      // 其他费用
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010013' THEN pfd.received_amount ELSE 0 END), 0) as fuwu, ";     // 服务费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010015' THEN pfd.received_amount ELSE 0 END), 0) as shuifei, ";  // 水费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010016' THEN pfd.received_amount ELSE 0 END), 0) as dianfei, ";  // 电费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010018' THEN pfd.received_amount ELSE 0 END), 0) as zujin, ";    // 租金
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010017' THEN pfd.received_amount ELSE 0 END), 0) as gongtan, ";  // 公摊费

    // 实收总额
    sql << "IFNULL(SUM(pfd.received_amount), 0) as final, ";

    // 全社区实收总额
    sql << "(SELECT IFNULL(SUM(pfd2.received_amount), 0) ";
    sql << "FROM pay_fee_detail pfd2 ";
    sql << "INNER JOIN pay_fee pf2 ON pfd2.fee_id = pf2.fee_id AND pf2.status_cd = '0' ";
    sql << "WHERE pfd2.status_cd = '0' ";
    if (query->communityId) {
        sql << "AND pfd2.community_id = ? ";
    }
    if (query->begintime) {
        sql << "AND pfd2.create_time >= ? ";
    }
    if (query->endtime) {
        sql << "AND pfd2.create_time <= ? ";
    }
    sql << ") as allfinal ";

    // 关联表查询 - 使用LEFT JOIN确保即使没有房间或缴费记录也能显示楼栋
    sql << "FROM f_floor f ";
    sql << "LEFT JOIN building_unit bu ON f.floor_id = bu.floor_id AND bu.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON bu.unit_id = br.unit_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN pay_fee pf ON br.room_id = pf.payer_obj_id AND pf.payer_obj_type = '3333' AND pf.status_cd = '0' ";
    sql << "LEFT JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' ";

    // 基础条件 - 只过滤楼栋的状态
    sql << "WHERE f.status_cd = '0' ";

    // 社区ID条件
    if (query->communityId) {
        sql << "AND f.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 时间条件 - 作为LEFT JOIN的附加条件
    if (query->begintime || query->endtime) {
        sql << "AND (pfd.detail_id IS NULL OR (1=1 ";
        if (query->begintime) {
            sql << "AND pfd.create_time >= ? ";
            SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
        }
        if (query->endtime) {
            sql << "AND pfd.create_time <= ? ";
            SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
        }
        sql << ")) ";
    }

    // 按楼栋分组
    sql << "GROUP BY f.floor_id, f.floor_num ";
    sql << "ORDER BY f.floor_num";

    // 为allfinal子查询添加参数
    if (query->communityId) {
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    // 调试输出SQL
    cout << "Generated SQL: " << sql.str() << endl;

    // 执行查询
    DataStatFinalCostMapper mapper;
    return sqlSession->executeQuery<DataStatFinalCostDO, DataStatFinalCostMapper>(sql.str(), mapper, params);
}

DataStatDetailCostDTO::Wrapper DataStatDao::queryShiShouDetail(const oatpp::Object<DataStatDetailSearchQuery>& query)
{
    return DataStatDetailCostDTO::createShared();
}

DataStatMethodDTO::Wrapper DataStatDao::queryMethod(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    auto method = DataStatMethodDTO::createShared();
    method->cash = querycash(query);
    method->wechat = querywecht(query);
    method->zhifubao = queryzhifubao(query);
    method->Transfer = queryTransfer(query);
    method->refund = queryrefund(query);
    method->POS = queryPOS(query);
    return method;
}


double DataStatDao::querycash(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // 统计所有表中的现金支付总额
    sql << "SELECT IFNULL(SUM(total_cash), 0.0) as total_amount FROM ( ";

    // 1. car_inout_payment表 - 停车缴费记录（现金）
    sql << "SELECT SUM(CAST(real_charge AS DECIMAL(10,2))) as total_cash ";
    sql << "FROM car_inout_payment ";
    sql << "WHERE status_cd = '0' AND pay_type = '1' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 2. reserve_goods_order表 - 预约商品订单（现金）
    sql << "SELECT SUM(received_amount) as total_cash ";
    sql << "FROM reserve_goods_order ";
    sql << "WHERE status_cd = '0' AND pay_way = '1' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 3. community_space_person表 - 场地预约（现金）
    sql << "SELECT SUM(received_amount) as total_cash ";
    sql << "FROM community_space_person ";
    sql << "WHERE status_cd = '0' AND pay_way = '1' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 4. parking_coupon_order表 - 停车券订单（现金）
    sql << "SELECT SUM(received_amount) as total_cash ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type = '1' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_cash";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "现金支付总额: " << result << endl;
    return result;
}

double DataStatDao::querywecht(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // 统计所有表中的微信支付总额
    sql << "SELECT IFNULL(SUM(total_wechat), 0.0) as total_amount FROM ( ";

    // 1. car_inout_payment表 - 停车缴费记录（微信）
    sql << "SELECT SUM(CAST(real_charge AS DECIMAL(10,2))) as total_wechat ";
    sql << "FROM car_inout_payment ";
    sql << "WHERE status_cd = '0' AND pay_type = '2' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 2. reserve_goods_order表 - 预约商品订单（微信）
    sql << "SELECT SUM(received_amount) as total_wechat ";
    sql << "FROM reserve_goods_order ";
    sql << "WHERE status_cd = '0' AND pay_way = '2' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 3. community_space_person表 - 场地预约（微信）
    sql << "SELECT SUM(received_amount) as total_wechat ";
    sql << "FROM community_space_person ";
    sql << "WHERE status_cd = '0' AND pay_way = '2' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 4. parking_coupon_order表 - 停车券订单（微信相关：2-POS刷卡，3-微信二维码，5-微信公众号，6-微信小程序）
    sql << "SELECT SUM(received_amount) as total_wechat ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type IN ('3', '5', '6') ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_wechat";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "微信支付总额: " << result << endl;
    return result;
}

double DataStatDao::queryzhifubao(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // 统计所有表中的支付宝支付总额
    sql << "SELECT IFNULL(SUM(total_alipay), 0.0) as total_amount FROM ( ";

    // 1. car_inout_payment表 - 停车缴费记录（支付宝）
    sql << "SELECT SUM(CAST(real_charge AS DECIMAL(10,2))) as total_alipay ";
    sql << "FROM car_inout_payment ";
    sql << "WHERE status_cd = '0' AND pay_type = '3' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 2. reserve_goods_order表 - 预约商品订单（支付宝）
    sql << "SELECT SUM(received_amount) as total_alipay ";
    sql << "FROM reserve_goods_order ";
    sql << "WHERE status_cd = '0' AND pay_way = '3' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 3. community_space_person表 - 场地预约（支付宝）
    sql << "SELECT SUM(received_amount) as total_alipay ";
    sql << "FROM community_space_person ";
    sql << "WHERE status_cd = '0' AND pay_way = '3' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 4. parking_coupon_order表 - 停车券订单（支付宝）
    sql << "SELECT SUM(received_amount) as total_alipay ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type = '4' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_alipay";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "支付宝支付总额: " << result << endl;
    return result;
}

double DataStatDao::queryTransfer(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // 统计转账支付总额
    sql << "SELECT IFNULL(SUM(total_transfer), 0.0) as total_amount FROM ( ";

    // 1. parking_coupon_order表 - 停车券订单（转账）
    sql << "SELECT SUM(received_amount) as total_transfer ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type = '7' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_transfer";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "转账支付总额: " << result << endl;
    return result;
}

double DataStatDao::queryPOS(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // 统计POS支付总额
    sql << "SELECT IFNULL(SUM(total_pos), 0.0) as total_amount FROM ( ";

    // 1. parking_coupon_order表 - 停车券订单（POS刷卡）
    sql << "SELECT SUM(received_amount) as total_pos ";
    sql << "FROM parking_coupon_order ";
    sql << "WHERE status_cd = '0' AND pay_type = '2' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_pos";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "POS支付总额: " << result << endl;
    return result;
}

double DataStatDao::queryrefund(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    std::stringstream sql;

    // 统计退款总额
    sql << "SELECT IFNULL(SUM(total_refund), 0.0) as total_amount FROM ( ";

    // 1. return_pay_fee表 - 普通退费记录
    sql << "SELECT SUM(received_amount) as total_refund ";
    sql << "FROM return_pay_fee ";
    sql << "WHERE status_cd = '0' AND state = '1100' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "UNION ALL ";

    // 2. business_return_pay_fee表 - 业务退费记录
    sql << "SELECT SUM(received_amount) as total_refund ";
    sql << "FROM business_return_pay_fee ";
    sql << "WHERE status_cd = '0' AND state = '1100' ";
    if (query->communityId) {
        sql << "AND community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        sql << "AND create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        sql << "AND create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") AS combined_refund";

    // 执行查询
    DoubleMapper mapper;
    double result = sqlSession->executeQueryOne<double>(sql.str(), mapper, params);
    cout << "退款总额: " << result << endl;
    return result;
}


//统计欠费总额
double DataStatDao::queryallqianfei(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // 基于report_owe_fee表计算所有楼栋的总欠费
    sql << "SELECT IFNULL(SUM(t.amount_owed), 0) as total_qianfei ";
    sql << "FROM report_owe_fee t ";
    sql << "WHERE t.amount_owed > 0 ";

    // 社区ID条件
    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 时间条件 - 使用end_time字段
    if (query->endtime) {
        sql << "AND t.end_time < ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    // 执行查询
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}


list<DataStatFinalCostDO> DataStatDao::queryShishouWithPage(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // 完全按照抓包SQL的结构来构建查询
    sql << "SELECT ";
    sql << "a.floor_id floorId, ";
    sql << "a.floor_num floorNum, ";
    sql << "a.name floorName, ";
    sql << "td.status_cd feeTypeCd, ";

    // 房间总数统计 - 与抓包SQL完全一致
    sql << "(SELECT COUNT(1) ";
    sql << "FROM building_room br ";
    sql << "LEFT JOIN building_unit bu ON bu.unit_id = br.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE 1 = 1 ";
    sql << "AND a.status_cd = '0' ";
    sql << "AND br.status_cd = '0' ";
    sql << "AND bu.floor_id = a.floor_id) roomCount, ";

    // 缴费房间数统计 - 与抓包SQL完全一致
    sql << "(SELECT COUNT(1) ";
    sql << "FROM ( ";
    sql << "SELECT bu.floor_id, br.room_id ";
    sql << "FROM pay_fee_detail t ";
    sql << "INNER JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.payer_obj_type = '3333' AND pf1.status_cd = '0' ";
    sql << "INNER JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE 1 = 1 ";
    sql << "AND t.status_cd = '0' ";

    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    if (query->begintime) {
        sql << "AND t.create_time > ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    if (query->endtime) {
        sql << "AND t.create_time < ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "GROUP BY bu.floor_id, br.room_id ";
    sql << ") b ";
    sql << "WHERE b.floor_id = a.floor_id) feeRoomCount, ";

    // 实收金额统计 - 与抓包SQL完全一致
    sql << "(SELECT IFNULL(SUM(t.received_amount), 0.0) receivedFee ";
    sql << "FROM pay_fee_detail t ";
    sql << "INNER JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.payer_obj_type = '3333' AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE 1 = 1 ";
    sql << "AND bu.floor_id = a.floor_id ";
    sql << "AND t.status_cd = '0' ";

    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    if (query->begintime) {
        sql << "AND t.create_time > ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    if (query->endtime) {
        sql << "AND t.create_time < ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << "AND pf1.fee_type_cd = td.status_cd) receivedFee ";

    // 主表连接 - 与抓包SQL完全一致
    sql << "FROM f_floor a ";
    sql << "LEFT JOIN t_dict td ON td.table_name = 'pay_fee_config' AND td.table_columns = 'fee_type_cd_show' ";
    sql << "WHERE 1 = 1 ";
    sql << "AND a.status_cd = '0' ";

    if (query->communityId) {
        sql << "AND a.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 排序
    sql << "ORDER BY a.seq ";

    // 分页
    if (query->pageIndex && query->pageSize) {
        uint64_t offset = static_cast<uint64_t>((query->pageIndex.getValue(1) - 1)) * query->pageSize.getValue(10);
        sql << " LIMIT " << offset << ", " << query->pageSize.getValue(10);
    }

    string sqlStr = sql.str();
    cout << "Generated Shishou SQL: " << sqlStr << endl;

    DataStatPageMapper mapper;
    return sqlSession->executeQuery<DataStatFinalCostDO, DataStatPageMapper>(sqlStr, mapper, params);
}

uint64_t DataStatDao::countShishou(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // 统计有实收记录的楼栋数量
    sql << "SELECT COUNT(DISTINCT f.floor_id) ";
    sql << "FROM f_floor f ";
    sql << "LEFT JOIN building_unit bu ON f.floor_id = bu.floor_id AND bu.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON bu.unit_id = br.unit_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN pay_fee pf ON br.room_id = pf.payer_obj_id AND pf.payer_obj_type = '3333' AND pf.status_cd = '0' ";
    sql << "LEFT JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' ";

    sql << "WHERE f.status_cd = '0' ";

    if (query->communityId) {
        sql << "AND f.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 如果有时间范围条件，也加入
    if (query->begintime || query->endtime) {
        sql << "AND (pfd.detail_id IS NOT NULL AND 1=1 ";
        if (query->begintime) {
            sql << "AND pfd.create_time >= ? ";
            SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
        }
        if (query->endtime) {
            sql << "AND pfd.create_time <= ? ";
            SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
        }
        sql << ") ";
    }

    // 确保该楼栋有实际收款记录
    sql << "AND pfd.received_amount > 0 ";

    string sqlStr = sql.str();
    cout << "Generated countShishou SQL: " << sqlStr << endl;

    return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<DataStatQianfeiDO> DataStatDao::queryQianfeiWithPage(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    sql << "SELECT ";
    sql << "CONCAT(a.floor_num, '栋') as house, ";

    // 物业费 - 888800010001 (基于抓包SQL的逻辑)
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010001'), 0.0) as wuye, ";

    // 押金 - 888800010006
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010006'), 0.0) as yajin, ";

    // 停车费 - 888800010008
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010008'), 0.0) as tingche, ";

    // 煤气费 - 888800010009
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010009'), 0.0) as meiqi, ";

    // 取暖费 - 888800010011
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010011'), 0.0) as qunuan, ";

    // 维修费 - 888800010012
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010012'), 0.0) as weixiu, ";

    // 其他费用 - 888800010014
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010014'), 0.0) as qita, ";

    // 服务费 - 888800010013
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010013'), 0.0) as fuwu, ";

    // 水费 - 888800010015
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010015'), 0.0) as shuifei, ";

    // 电费 - 888800010016
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010016'), 0.0) as dianfei, ";

    // 租金 - 888800010018
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010018'), 0.0) as zujin, ";

    // 公摊费 - 888800010017
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0 AND pf1.fee_type_cd = '888800010017'), 0.0) as gongtan, ";

    // 该楼栋总欠费 (按照抓包SQL的逻辑：通过pay_fee.payer_obj_id关联房间)
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "WHERE bu.floor_id = a.floor_id AND t.community_id = ? AND t.amount_owed > 0), 0.0) as qianfei, ";

    // 全社区总欠费
    sql << "IFNULL((SELECT SUM(t.amount_owed) FROM report_owe_fee t ";
    sql << "WHERE t.community_id = ? AND t.amount_owed > 0), 0.0) as allqianfei ";

    // 主表查询
    sql << "FROM f_floor a ";
    sql << "WHERE 1=1 ";

    if (query->communityId) {
        sql << "AND a.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    sql << "AND a.status_cd = '0' ";

    // 添加时间条件
    if (query->endtime) {
        // 所有子查询都需要加时间条件
        // 这里需要调整SQL结构，因为时间条件是在子查询中
    }

    sql << "ORDER BY a.seq ";

    if (query->pageIndex && query->pageSize) {
        uint64_t offset = static_cast<uint64_t>((query->pageIndex.getValue(1) - 1)) * query->pageSize.getValue(10);
        sql << " LIMIT " << offset << ", " << query->pageSize.getValue(10);
    }

    // 为allfinal子查询添加参数
    if (query->communityId) {
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }
    if (query->begintime) {
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }
    if (query->endtime) {
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    cout << "Generated Qianfei SQL: " << sql.str() << endl;

    DataStatQianfeiMapper mapper;
    return sqlSession->executeQuery<DataStatQianfeiDO, DataStatQianfeiMapper>(sql.str(), mapper, params);
}

uint64_t DataStatDao::countQianfei(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // 统计有欠费记录的楼栋数量（基于report_owe_fee表）
    sql << "SELECT COUNT(DISTINCT f.floor_id) ";
    sql << "FROM f_floor f ";
    sql << "WHERE f.status_cd = '0' ";  // 修复：去掉多余的 \\ 转义符号
    sql << "AND EXISTS ( ";
    sql << "    SELECT 1 FROM report_owe_fee t ";
    sql << "    LEFT JOIN pay_fee pf1 ON t.fee_id = pf1.fee_id AND pf1.status_cd = '0' ";
    sql << "    LEFT JOIN building_room br ON pf1.payer_obj_id = br.room_id AND br.status_cd = '0' ";
    sql << "    LEFT JOIN building_unit bu ON br.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "    WHERE bu.floor_id = f.floor_id ";
    sql << "    AND t.amount_owed > 0 ";

    // 社区ID条件
    if (query->communityId) {
        sql << "    AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 时间条件
    if (query->endtime) {
        sql << "    AND t.end_time < ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    sql << ") ";

    // 社区ID条件（主查询）
    if (query->communityId) {
        sql << "AND f.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 执行计数查询
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 实收明细分页查询 - 基于抓包SQL逻辑
list<DataStatDetailCostDO> DataStatDao::queryShiShouDetailWithPage(const oatpp::Object<DataStatDetailSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // 基于抓包SQL的逻辑构建查询 - 返回15个字段
    sql << "SELECT ";
    // 基本信息字段（但只有house和host会被DTO使用）
    sql << "CONCAT(f.floor_num, '栋', bu.unit_num, '单元', t.room_num, '室') as house, ";
    sql << "IFNULL(bo.name, '') as host, ";

    // 各费用类型实收金额统计 - 12个费用字段
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010001' THEN pfd.received_amount ELSE 0 END), 0) as wuye, ";      // 物业费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010006' THEN pfd.received_amount ELSE 0 END), 0) as yajin, ";     // 押金
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010008' THEN pfd.received_amount ELSE 0 END), 0) as tingche, ";   // 停车费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010009' THEN pfd.received_amount ELSE 0 END), 0) as meiqi, ";     // 煤气费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010011' THEN pfd.received_amount ELSE 0 END), 0) as qunuan, ";    // 取暖费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010012' THEN pfd.received_amount ELSE 0 END), 0) as weixiu, ";    // 维修费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010014' THEN pfd.received_amount ELSE 0 END), 0) as qita, ";      // 其他费用
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010013' THEN pfd.received_amount ELSE 0 END), 0) as fuwu, ";     // 服务费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010015' THEN pfd.received_amount ELSE 0 END), 0) as shuifei, ";  // 水费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010016' THEN pfd.received_amount ELSE 0 END), 0) as dianfei, ";  // 电费
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010018' THEN pfd.received_amount ELSE 0 END), 0) as zujin, ";    // 租金
    sql << "IFNULL(SUM(CASE WHEN pf.fee_type_cd = '888800010017' THEN pfd.received_amount ELSE 0 END), 0) as gongtan, ";  // 公摊费

    // 实收总额
    sql << "IFNULL(SUM(pfd.received_amount), 0) as final ";  // 实收总额

    // 表关联 - 完全按照抓包SQL的结构
    sql << "FROM building_room t ";
    sql << "INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' ";
    sql << "LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' ";
    sql << "LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' ";
    sql << "INNER JOIN pay_fee pf ON t.room_id = pf.payer_obj_id AND pf.payer_obj_type = '3333' AND pf.status_cd = '0' ";
    sql << "INNER JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' ";

    // 查询条件 - 对应抓包SQL的6个查询参数
    sql << "WHERE 1=1 ";

    // 1. 开始时间条件：pfd.create_time >= ?
    if (query->begintime) {
        sql << "AND pfd.create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    // 2. 结束时间条件：pfd.create_time <= ?
    if (query->endtime) {
        sql << "AND pfd.create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    // 基本条件
    sql << "AND t.status_cd = '0' ";

    // 3. 房间号模糊查询：t.room_num like concat('%',?,'%')
    if (query->house && !query->house.getValue("").empty()) {
        sql << "AND t.room_num LIKE CONCAT('%', ?, '%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->house.getValue(""));
    }

    // 4. 社区ID条件：t.community_id = ?
    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 5. 业主姓名模糊查询：bo.`name` like concat('%',?,'%')
    if (query->host && !query->host.getValue("").empty()) {
        sql << "AND bo.name LIKE CONCAT('%', ?, '%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->host.getValue(""));
    }

    // 6. 业主电话精确查询：bo.link = ?
    if (query->phone && !query->phone.getValue("").empty()) {
        sql << "AND bo.link = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->phone.getValue(""));
    }

    // 按房间分组 - 对应抓包SQL的 group by t.room_id
    sql << "GROUP BY t.room_id ";

    // 排序
    sql << "ORDER BY f.seq, bu.unit_num, t.room_num ";

    // 分页
    if (query->pageIndex && query->pageSize) {
        uint64_t offset = static_cast<uint64_t>((query->pageIndex.getValue(1) - 1)) * query->pageSize.getValue(10);
        sql << " LIMIT " << offset << ", " << query->pageSize.getValue(10);
    }

    string sqlStr = sql.str();
    cout << "Generated ShiShouDetail SQL: " << sqlStr << endl;

    DataStatDetailCostMapper mapper;
    return sqlSession->executeQuery<DataStatDetailCostDO, DataStatDetailCostMapper>(sqlStr, mapper, params);
}

// 实收明细总数查询 - 基于抓包SQL逻辑
uint64_t DataStatDao::countShiShouDetail(const oatpp::Object<DataStatDetailSearchQuery>& query)
{
    SqlParams params;
    stringstream sql;

    // 基于抓包SQL计数逻辑 - 对应抓包SQL的count结构
    sql << "SELECT COUNT(1) as count FROM ( ";
    sql << "SELECT t.room_id ";
    sql << "FROM building_room t ";
    sql << "INNER JOIN building_unit bu ON t.unit_id = bu.unit_id AND bu.status_cd = '0' ";
    sql << "INNER JOIN f_floor f ON bu.floor_id = f.floor_id AND f.status_cd = '0' ";
    sql << "LEFT JOIN building_owner_room_rel borr ON t.room_id = borr.room_id AND borr.status_cd = '0' ";
    sql << "LEFT JOIN building_owner bo ON borr.owner_id = bo.member_id AND bo.status_cd = '0' ";
    sql << "INNER JOIN pay_fee pf ON t.room_id = pf.payer_obj_id AND pf.payer_obj_type = '3333' AND pf.status_cd = '0' ";
    sql << "INNER JOIN pay_fee_detail pfd ON pf.fee_id = pfd.fee_id AND pfd.status_cd = '0' ";
    sql << "WHERE 1=1 ";

    // 查询条件 - 完全对应抓包SQL的6个查询参数

    // 1. 开始时间条件：pfd.create_time >= ?
    if (query->begintime) {
        sql << "AND pfd.create_time >= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->begintime.getValue(""));
    }

    // 2. 结束时间条件：pfd.create_time <= ?
    if (query->endtime) {
        sql << "AND pfd.create_time <= ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->endtime.getValue(""));
    }

    // 基本条件
    sql << "AND t.status_cd = '0' ";

    // 3. 房间号模糊查询：t.room_num like concat('%',?,'%')
    if (query->house && !query->house.getValue("").empty()) {
        sql << "AND t.room_num LIKE CONCAT('%', ?, '%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->house.getValue(""));
    }

    // 4. 社区ID条件：t.community_id = ?
    if (query->communityId) {
        sql << "AND t.community_id = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
    }

    // 5. 业主姓名模糊查询：bo.`name` like concat('%',?,'%')
    if (query->host && !query->host.getValue("").empty()) {
        sql << "AND bo.name LIKE CONCAT('%', ?, '%') ";
        SQLPARAMS_PUSH(params, "s", std::string, query->host.getValue(""));
    }

    // 6. 业主电话精确查询：bo.link = ?
    if (query->phone && !query->phone.getValue("").empty()) {
        sql << "AND bo.link = ? ";
        SQLPARAMS_PUSH(params, "s", std::string, query->phone.getValue(""));
    }

    // 按房间分组 - 对应抓包SQL的 group by t.room_id
    sql << "GROUP BY t.room_id ";
    sql << ") a";

    string sqlStr = sql.str();
    cout << "Generated countShiShouDetail SQL: " << sqlStr << endl;

    return sqlSession->executeQueryNumerical(sqlStr, params);
}


/*              数据统计-3            */
//欠费明细实现--------------------
std::string DatastatFeeDetailDAO::queryConditionBuilder(const DatastatFeeDetailQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    if (query->room_name) {

        sqlCondition << " AND t.room_num like concat('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->room_name.getValue(""));
    }
    if (query->name) {

        sqlCondition << " AND bo.`name` like concat('%',?,'%')";
        SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
    }
    if (query->link) {

        sqlCondition << " AND bo.link = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->link.getValue(""));
    }
    return sqlCondition.str();
}

uint64_t DatastatFeeDetailDAO::count(const DatastatFeeDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "select count(1) count "
        " from "
        " (select t.room_id "
        " from building_room t "
        " inner join building_unit bu on t.unit_id = bu.unit_id and bu.status_cd = '0' "
        " inner join f_floor f on bu.floor_id = f.floor_id and f.status_cd = '0' "
        " left join building_owner_room_rel borr on t.room_id = borr.room_id and borr.status_cd = '0' "
        " left join building_owner bo on borr.owner_id = bo.member_id and bo.status_cd = '0' "
        " inner join report_owe_fee rof on t.room_id = rof.payer_obj_id and rof.payer_obj_type = '3333' ";





    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 补全sql
    sql += " group by t.room_id ) a ";

    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DatastatFeeDetailDO> DatastatFeeDetailDAO::selectWithPage(const DatastatFeeDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = " SELECT "
        " t.room_num, "
        " bo.name, "
        " rof.amount_owed "
        " FROM building_room t "
        " LEFT JOIN building_owner_room_rel borr "
        " ON t.room_id = borr.room_id AND borr.status_cd = '0' "
        " LEFT JOIN building_owner bo "
        " ON borr.owner_id = bo.member_id AND bo.status_cd = '0' "
        " INNER JOIN report_owe_fee rof "
        " ON t.room_id = rof.payer_obj_id "
        " AND rof.payer_obj_type = '3333' "
        " AND rof.amount_owed > 0 ";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);

    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    DatastatFeeDetailMapper mapper;
    return sqlSession->executeQuery<DatastatFeeDetailDO>(sql, mapper, params);
}



//收缴情况实现--------------------
std::string DatastatChargeDetailDAO::queryConditionBuilder(const DatastatChargeDetailQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    if (query->fee_name) {

        sqlCondition << " AND pfdm.fee_type_cd = ? ";
        sqlCondition << " AND pfdm.status_cd = '0'";

        string fee_type_cd = "888800010001";
        if (query->fee_name.getValue("") == "物业费") fee_type_cd = "888800010001";
        SQLPARAMS_PUSH(params, "s", std::string, fee_type_cd);
    }

    return sqlCondition.str();
}

uint64_t DatastatChargeDetailDAO::count(const DatastatChargeDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT\
		COUNT(DISTINCT bu.floor_id) AS total_count\
		FROM building_room br\
		INNER JOIN building_unit bu\
		ON br.unit_id = bu.unit_id\
		AND br.status_cd = '0' \
		AND bu.status_cd = '0' \
		LEFT JOIN pay_fee_detail_month pfdm\
		ON br.room_id = pfdm.obj_id\
";





    // 构建查询条件
    sql += queryConditionBuilder(query, params);

    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DatastatChargeDetailDO> DatastatChargeDetailDAO::selectWithPage(const DatastatChargeDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT\
		bf.name ,\
		COUNT(DISTINCT br.room_id) as num_for_house,\
		COUNT(DISTINCT CASE WHEN pfdm.state = 'C' THEN br.room_id END) as num_for_chargeable_house \
		FROM building_room br\
		INNER JOIN building_unit bu\
		ON br.unit_id = bu.unit_id\
		AND br.status_cd = '0'  \
		AND bu.status_cd = '0'  \
		INNER JOIN business_floor bf  \
		ON bu.floor_id = bf.floor_id  \
		LEFT JOIN pay_fee_detail_month pfdm\
		ON br.room_id = pfdm.obj_id\
";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);

    //构建分组
    sql += " GROUP BY bf.name, bu.floor_id ";

    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    DatastatChargeDetailMapper mapper;
    return sqlSession->executeQuery<DatastatChargeDetailDO>(sql, mapper, params);
}


//月实收明细实现--------------------
std::string DatastatMonthDetailDAO::queryConditionBuilder(const DatastatMonthDetailQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1 ";
    return sqlCondition.str();
}

uint64_t DatastatMonthDetailDAO::count(const DatastatMonthDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "select count(1) count \
		from \
		(select t.room_id \
			from building_room t \
			inner join building_unit bu on t.unit_id = bu.unit_id and bu.status_cd = '0' \
			inner join f_floor f on bu.floor_id = f.floor_id and f.status_cd = '0' \
			left join building_owner_room_rel borr on t.room_id = borr.room_id and borr.status_cd = '0' \
			left join building_owner bo on borr.owner_id = bo.member_id and bo.status_cd = '0' \
			where 1 = 1 \
			AND t.status_cd = '0' \
			group by t.room_id \
		) a";






    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DatastatMonthDetailDO> DatastatMonthDetailDAO::selectWithPage(const DatastatMonthDetailQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT\
		t.room_num,\
		bo.name\
		FROM building_room t\
		LEFT JOIN building_owner_room_rel borr\
		ON t.room_id = borr.room_id AND borr.status_cd = '0'\
		LEFT JOIN building_owner bo\
		ON borr.owner_id = bo.member_id AND bo.status_cd = '0'\
";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);

    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    DatastatMonthDetailMapper mapper;
    return sqlSession->executeQuery<DatastatMonthDetailDO>(sql, mapper, params);
}

//月欠费明细实现--------------------
std::string DatastatMonthFeeDAO::queryConditionBuilder(const DatastatMonthFeeQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1 ";
    return sqlCondition.str();
}

uint64_t DatastatMonthFeeDAO::count(const DatastatMonthFeeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "select count(1) count \
		from \
		(select t.room_id \
			from building_room t \
			inner join building_unit bu on t.unit_id = bu.unit_id and bu.status_cd = '0' \
			inner join f_floor f on bu.floor_id = f.floor_id and f.status_cd = '0' \
			left join building_owner_room_rel borr on t.room_id = borr.room_id and borr.status_cd = '0' \
			left join building_owner bo on borr.owner_id = bo.member_id and bo.status_cd = '0' \
			where 1 = 1 \
			AND t.status_cd = '0' \
			group by t.room_id \
		) a";






    return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DatastatMonthFeeDO> DatastatMonthFeeDAO::selectWithPage(const DatastatMonthFeeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT\
		t.room_num,\
		bo.name\
		FROM building_room t\
		LEFT JOIN building_owner_room_rel borr\
		ON t.room_id = borr.room_id AND borr.status_cd = '0'\
		LEFT JOIN building_owner bo\
		ON borr.owner_id = bo.member_id AND bo.status_cd = '0'\
";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);

    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    DatastatMonthFeeMapper mapper;
    return sqlSession->executeQuery<DatastatMonthFeeDO>(sql, mapper, params);
}
