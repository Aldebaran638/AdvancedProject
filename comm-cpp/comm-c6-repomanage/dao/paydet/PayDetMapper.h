#pragma once
#ifndef _PAYDET_MAPPER_
#define _PAYDET_MAPPER_
#include "Mapper.h"
#include "../../domain/do/paydet/PayDetDO.h"

/**
 * 缴费明细表字段匹配映射-创建智能指针对象
 */
class PayDetMapper : public Mapper<PayDetDO> {
public:
	PayDetDO mapper(ResultSet* resultSet) const override {
		PayDetDO data;

		data.setOrderNumber(resultSet->getString("orderNumber"));
		data.setHouseNumberPropertyOwner(resultSet->getString("houseNumberPropertyOwner"));
		data.setExpenseTypeItem(resultSet->getString("expenseTypeItem"));
		data.setExpenseStatus(resultSet->getString("expenseStatus"));
		data.setPaymentMethod(resultSet->getString("paymentMethod"));
		data.setPaymentPeriod(resultSet->getString("paymentPeriod"));
		data.setPaymentTime(resultSet->getString("paymentTime"));
		data.setCashier(resultSet->getString("cashier"));
		data.setDueReceiveAmount(resultSet->getDouble("dueReceiveAmount"));
		data.setAmountReceived(resultSet->getDouble("amountReceived"));
		data.setAccountDeduction(resultSet->getDouble("accountDeduction"));
		data.setDiscountWaiverAmount(resultSet->getDouble("discountWaiverAmount"));
		data.setGiftAmount(resultSet->getDouble("giftAmount"));
		data.setLatePaymentFee(resultSet->getDouble("latePaymentFee"));
		data.setArea(resultSet->getDouble("area"));
		data.setParkingSpace(resultSet->getString("parkingSpace"));
		data.setRemarks(resultSet->getString("remarks"));

		return data;
	}
};

#endif // !_PAYDET_MAPPER_