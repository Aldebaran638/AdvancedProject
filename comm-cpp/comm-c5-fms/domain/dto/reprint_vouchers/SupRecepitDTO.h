#pragma once
#ifndef _SUP_RECEPIT_DTO_
#define _SUP_RECEPIT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SupRecepitDTO : public oatpp::DTO
{
	DTO_INIT(SupRecepitDTO, DTO);
	//收据id
	DTO_FIELD(String, recepitId);
	DTO_FIELD_INFO(recepitId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitid");
	}
	//收据编号
	DTO_FIELD(String, recepitCode);
	DTO_FIELD_INFO(recepitCode) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitcode");
	}
	//费用类型
	DTO_FIELD(String, objType);
	DTO_FIELD_INFO(objType) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.objType");
	}
	//费用项
	DTO_FIELD(String, feeName);
	DTO_FIELD_INFO(feeName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.feename");
	}
	//房屋
	DTO_FIELD(String, roomName);
	DTO_FIELD_INFO(roomName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.roomName");
	}
	//业主
	DTO_FIELD(String, ownerName);
	DTO_FIELD_INFO(ownerName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.ownername");
	}
	//车位
	DTO_FIELD(String, carPark);
	DTO_FIELD_INFO(carPark) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.carpark");
	}
	//总金额
	DTO_FIELD(Float32, receviableAmount);
	DTO_FIELD_INFO(receviableAmount) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.receviableamount");
	}
	//创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.createtime");
	}
};

class SupRecepitPageDTO : public PageDTO<SupRecepitDTO::Wrapper>
{
	DTO_INIT(SupRecepitPageDTO, PageDTO<SupRecepitDTO::Wrapper>);
};

class ReprintSupRecepitDTO : public oatpp::DTO
{
	DTO_INIT(ReprintSupRecepitDTO, DTO);

	//业主
	DTO_FIELD(String, ownerName);
	DTO_FIELD_INFO(ownerName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.ownername");
	}
	//对象名称
	DTO_FIELD(String, objName);
	DTO_FIELD_INFO(objName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.ownername");
	}
	//费用项
	DTO_FIELD(String, feeName);
	DTO_FIELD_INFO(feeName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.feename");
	}
	//开始时间
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.starttime");
	}
	//创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.createtime");
	}
	//结束时间
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.endtime");
	}
	//应收
	DTO_FIELD(Float32, needPay);
	DTO_FIELD_INFO(needPay) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.needpay");
	}
	//实收
	DTO_FIELD(Float32, pay);
	DTO_FIELD_INFO(pay) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.pay");
	}
	//收据id
	DTO_FIELD(String, recepitId);
	DTO_FIELD_INFO(recepitId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitid");
	}
	//支付订单id
	DTO_FIELD(String, recepitPayId);
	DTO_FIELD_INFO(recepitPayId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitPayId");
	}
	//收银员
	DTO_FIELD(String, cashierName);
	DTO_FIELD_INFO(cashierName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.cashierName");
	}
};

class ReprintSupRecepit2DTO : public oatpp::DTO {
	DTO_INIT(ReprintSupRecepit2DTO, DTO);

	//收据编号
	DTO_FIELD(String, recepitCode);
	DTO_FIELD_INFO(recepitCode) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitcode");
	}
	//支付订单id
	DTO_FIELD(String, payOrderId);
	DTO_FIELD_INFO(payOrderId) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.recepitPayId");
	}
	//对象名称
	DTO_FIELD(String, objName);
	DTO_FIELD_INFO(objName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.objname");
	}
	//付费人名称
	DTO_FIELD(String, payObjName);
	DTO_FIELD_INFO(payObjName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.ownername");
	}
	//创建时间
	DTO_FIELD(String, createTime);
	DTO_FIELD_INFO(createTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.createtime");
	}
	//费用名称
	DTO_FIELD(String, feeName);
	DTO_FIELD_INFO(feeName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.feename");
	}
	//开始时间
	DTO_FIELD(String, startTime);
	DTO_FIELD_INFO(startTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.starttime");
	}
	//结束时间
	DTO_FIELD(String, endTime);
	DTO_FIELD_INFO(endTime) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.endtime");
	}
	//单价/固定费
	DTO_FIELD(String, squarePrice);
	DTO_FIELD_INFO(squarePrice) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.squareprice");
	}
	//面积
	DTO_FIELD(String, area);
	DTO_FIELD_INFO(area) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.area");
	}
	//支付方式
	DTO_FIELD(Float32, primeRate);
	DTO_FIELD_INFO(primeRate) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.primerate");
	}
	//应缴金额
	DTO_FIELD(Float32, payableAmount);
	DTO_FIELD_INFO(payableAmount) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.payableamount");
	}
	//优惠金额
	DTO_FIELD(Float32, discountAmount);
	DTO_FIELD_INFO(discountAmount) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.discountamount");
	}
	//备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.remark");
	}
	//应收金额
	DTO_FIELD(Float32, receivedAmount);
	DTO_FIELD_INFO(receivedAmount) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.needpay");
	}
	//收银员
	DTO_FIELD(String, cashierName);
	DTO_FIELD_INFO(cashierName) {
		info->description = ZH_WORDS_GETTER("supplementrecepit.filed.cashierName");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
