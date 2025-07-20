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

#ifndef DATASTATDAO_H
#define DATASTATDAO_H

#include <BaseDAO.h>
#include <domain/dto/datastat/DataStatDTO.h>
#include <domain/query/datastat/DataStatQuery.h>
#include "../../domain/do/datastat/DataStatDO.h"
/*
 * 数据统计，工单统计，出入统计，其他统计的DAO层
 */
class DataStatDao : public BaseDAO {
public:
	// 查询数据统计数据
	ExpenseStatDTO::Wrapper queryExpense(const ExpenseStatQuery::Wrapper& query);

	// 查询工单统计数据
	WorkOrderStatDTO::Wrapper queryWorkOrder(const WorkOrderStatQuery::Wrapper& query);

	// 查询出入统计数据
	AccessStatDTO::Wrapper queryAccess(const AccessStatQuery::Wrapper& query);

	// 查询其他统计数据
	OtherStatDTO::Wrapper queryOther(const OtherStatQuery::Wrapper& query);


    /*  2  */
	// 查询条件构建器
	std::string queryConditionBuilder(const oatpp::Object<DataStatALLSearchQuery>& query, SqlParams& params);
	//总览查询 - 实收统计
	list<DataStatFinalCostDO> queryShishou(const oatpp::Object<DataStatALLSearchQuery>& query);

	//总览查询 - 实收统计（带分页）
	list<DataStatFinalCostDO> queryShishouWithPage(const oatpp::Object<DataStatALLSearchQuery>& query);

	//查询实收统计总数
	uint64_t countShishou(const oatpp::Object<DataStatALLSearchQuery>& query);
	//详细查询
	DataStatDetailCostDTO::Wrapper queryShiShouDetail(const oatpp::Object<DataStatDetailSearchQuery>& query);

	//实收明细分页查询
	list<DataStatDetailCostDO> queryShiShouDetailWithPage(const oatpp::Object<DataStatDetailSearchQuery>& query);

	//查询实收明细总数
	uint64_t countShiShouDetail(const oatpp::Object<DataStatDetailSearchQuery>& query);
	//方法查询
	DataStatMethodDTO::Wrapper queryMethod(const oatpp::Object<DataStatALLSearchQuery>& query);

	//欠费统计分页查询
	list<DataStatQianfeiDO> queryQianfeiWithPage(const oatpp::Object<DataStatALLSearchQuery>& query);

	//查询欠费统计总数
	uint64_t countQianfei(const oatpp::Object<DataStatALLSearchQuery>& query);

	//计算所有楼栋的总欠费
	double queryallqianfei(const oatpp::Object<DataStatALLSearchQuery>& query);


private:
	/*
	 * 数据统计
	 */

	// 实收金额
	double queryreceiveAmount(const ExpenseStatQuery::Wrapper& query);

	// 欠费金额
	double queryowingAmount(const ExpenseStatQuery::Wrapper& query);

	// 优惠金额
	double querydiscountAmount(const ExpenseStatQuery::Wrapper& query);

	// 滞纳金
	double querylateFeeAmount(const ExpenseStatQuery::Wrapper& query);

	// 账户预存
	double queryaccountPreAmount(const ExpenseStatQuery::Wrapper& query);

	// 账户扣款
	double queryaccountDeductAmount(const ExpenseStatQuery::Wrapper& query);

	// 临时车收入
	double querytempCarIncomeAmount(const ExpenseStatQuery::Wrapper& query);

	// 押金退款
	double querydepositRefundAmount(const ExpenseStatQuery::Wrapper& query);

	// 退款订单数
	double queryrefundOrderCount(const ExpenseStatQuery::Wrapper& query);

	// 退款金额
	double queryrefundAmount(const ExpenseStatQuery::Wrapper& query);

	// 充电金额
	double querychargeAmount(const ExpenseStatQuery::Wrapper& query);

	// 月卡实收
	double querymonthCardReceiveAmount(const ExpenseStatQuery::Wrapper& query);


	/*
	 * 工单统计
	 */

    // 投诉单
	double querycomplaintCount(const WorkOrderStatQuery::Wrapper& query);

    // 未完成投诉单
	double queryunfinishedComplaintCount(const WorkOrderStatQuery::Wrapper& query);

    // 完成投诉单
	double queryfinishedComplaintCount(const WorkOrderStatQuery::Wrapper& query);

    // 报修单
	double queryrepairCount(const WorkOrderStatQuery::Wrapper& query);

    // 未完成报修单
	double queryunfinishedRepairCount(const WorkOrderStatQuery::Wrapper& query);

    // 完成报修单
	double queryfinishedRepairCount(const WorkOrderStatQuery::Wrapper& query);

    // 巡检
	double queryinspectionCount(const WorkOrderStatQuery::Wrapper& query);

    // 未完成巡检
	double queryunfinishedInspectionCount(const WorkOrderStatQuery::Wrapper& query);

    // 完成巡检
	double queryfinishedInspectionCount(const WorkOrderStatQuery::Wrapper& query);

    // 保养
	double querymaintenanceCount(const WorkOrderStatQuery::Wrapper& query);

    // 未完成保养
	double queryunfinishedMaintenanceCount(const WorkOrderStatQuery::Wrapper& query);

    // 完成保养
	double queryfinishedMaintenanceCount(const WorkOrderStatQuery::Wrapper& query);

    // 业主反馈
	double queryownerFeedbackCount(const WorkOrderStatQuery::Wrapper& query);

    // 充电订单
	double querychargeOrderCount(const WorkOrderStatQuery::Wrapper& query);

	/*
	 * 出入类统计
	 */

    // 进场车辆数
    double queryvehicleEntryCount(const AccessStatQuery::Wrapper& query);

    // 出场车辆数
    double queryvehicleExitCount(const AccessStatQuery::Wrapper& query);

    // 进场人员数
    double querypersonEntryCount(const AccessStatQuery::Wrapper& query);

    // 人脸同步数
    double queryfaceSyncCount(const AccessStatQuery::Wrapper& query);

    // 采购入库数
    double querypurchaseInboundCount(const AccessStatQuery::Wrapper& query);

    // 领用出库数
    double querylendOutboundCount(const AccessStatQuery::Wrapper& query);

    // 采购入库金额
    double querypurchaseInboundAmount(const AccessStatQuery::Wrapper& query);

	// 完成巡检
	double queryfinishedInspectionCount(const AccessStatQuery::Wrapper& query);

    // 调拨数量
    double querytransferCount(const AccessStatQuery::Wrapper& query);

    // 房屋装修数
    double queryhouseDecorationCount(const AccessStatQuery::Wrapper& query);

    // 物品放行
    double queryitemReleaseCount(const AccessStatQuery::Wrapper& query);
	 
    // 交房数量
	double queryhouseDeliveryCount(const AccessStatQuery::Wrapper& query);

    // 退房数量
    double queryhouseReturnCount(const AccessStatQuery::Wrapper& query);

    // 业主绑定
    double queryownerBindingCount(const AccessStatQuery::Wrapper& query);

    // 未考勤数
    double queryabsenceCount(const AccessStatQuery::Wrapper& query);


	/*
	 * 其他统计
	 */

    // 场地预约数
    double queryplaceReservationCount(const OtherStatQuery::Wrapper& query);

    // 合同数
    double querycontractCount(const OtherStatQuery::Wrapper& query);

    // 合同资产变更数
    double querycontractAssetChangeCount(const OtherStatQuery::Wrapper& query);

    // 租期变更数
    double queryleaseTermChangeCount(const OtherStatQuery::Wrapper& query);

    // 主体变更数
    double querysubjectChangeCount(const OtherStatQuery::Wrapper& query);

    // 到期合同数
    double queryexpiredContractCount(const OtherStatQuery::Wrapper& query);

    // 车辆数
    double queryvehicleCount(const OtherStatQuery::Wrapper& query);

    // 车位申请数
    double queryparkingSpaceApplicationCount(const OtherStatQuery::Wrapper& query);

    // 停车券购买数
    double queryparkingTicketPurchaseCount(const OtherStatQuery::Wrapper& query);

    // 停车券核销数
    double queryparkingTicketVerificationCount(const OtherStatQuery::Wrapper& query);

    // 赠送优惠券数
    double querycouponGiftCount(const OtherStatQuery::Wrapper& query);

    // 使用优惠券数
    double querycouponUseCount(const OtherStatQuery::Wrapper& query);

    // 退房数量
    double queryhouseReturnCount(const OtherStatQuery::Wrapper& query);

    // 使用积分
    double queryintegralUseCount(const OtherStatQuery::Wrapper& query);

	/*             2         */
	//方法统计
	double querycash(const oatpp::Object<DataStatALLSearchQuery>& query);
	double querywecht(const oatpp::Object<DataStatALLSearchQuery>& query);
	double queryzhifubao(const oatpp::Object<DataStatALLSearchQuery>& query);
	double queryPOS(const oatpp::Object<DataStatALLSearchQuery>& query);
	double queryTransfer(const oatpp::Object<DataStatALLSearchQuery>& query);
	double queryrefund(const oatpp::Object<DataStatALLSearchQuery>& query);
};

/*              数据统计-3            */
/**
 * 欠费明细数据库操作实现
 */
class DatastatFeeDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const DatastatFeeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const DatastatFeeDetailQuery::Wrapper& query);
	// 分页查询数据
	std::list<DatastatFeeDetailDO> selectWithPage(const DatastatFeeDetailQuery::Wrapper& query);
};

/**
 * 欠费明细数据库操作实现
 */
class DatastatChargeDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const DatastatChargeDetailQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const DatastatChargeDetailQuery::Wrapper& query);
	// 分页查询数据
	std::list<DatastatChargeDetailDO> selectWithPage(const DatastatChargeDetailQuery::Wrapper& query);
};


/**
 * 月实收明细数据库操作实现
 */
class DatastatMonthDetailDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const DatastatMonthDetailQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const DatastatMonthDetailQuery::Wrapper& query);
	// 分页查询数据
	std::list<DatastatMonthDetailDO> selectWithPage(const DatastatMonthDetailQuery::Wrapper& query);
};


/**
 * 月欠费明细数据库操作实现
 */
class DatastatMonthFeeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const DatastatMonthFeeQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const DatastatMonthFeeQuery::Wrapper& query);
	// 分页查询数据
	std::list<DatastatMonthFeeDO> selectWithPage(const DatastatMonthFeeQuery::Wrapper& query);
};

#endif // !DATASTATDAO_H
