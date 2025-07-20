#include "stdafx.h"
#include "HousePayFeeDAO.h"

#include <iostream>

FindCommunityDO HousePayFeeDAO::findCommunityId(const string& config_id)
{
	string sql = "SELECT  community_id,fee_type_cd,fee_flag\
		FROM pay_fee_config \
		WHERE config_id = ?\
		AND status_cd = 1";
	auto mapper = std::make_shared<FindCommunityDOMapper>();
	return sqlSession->executeQueryOne<FindCommunityDO>(sql, *mapper, "%s", config_id);
}
HouseInfoDO HousePayFeeDAO::searchHouseInfo(const std::string& floor_num, const std::string& unit_num, const std::string& room_num, const std::string& community_id)
{
	std::string sql = "SELECT r.room_id, r.built_up_area, r.room_area \
		FROM f_floor f \
		JOIN building_unit u ON f.floor_id = u.floor_id \
		JOIN building_room r ON u.unit_id = r.unit_id AND f.community_id = r.community_id \
		WHERE f.community_id = ? \
		AND f.floor_num = ?  \
		AND u.unit_num = ? \
		AND r.room_num = ?";
	auto mapper = std::shared_ptr<HouseInfoDOMapper>() ;
	return sqlSession->executeQueryOne<HouseInfoDO>(sql, *mapper, "%s%s%s%s", community_id, floor_num, unit_num, room_num);
}

Int32JsonVO::Wrapper HousePayFeeDAO::deleteHouseFee(const std::string& id)
{
	std::string sql = "DELETE f, b \
		FROM pay_fee f \
		LEFT JOIN pay_fee_batch b ON f.batch_id = b.batch_id \
		WHERE f.fee_id = ?;";

	auto res = Int32JsonVO::createShared();
	res->data = sqlSession->executeUpdate(sql, "%s", id);
	return res;
	
}


double HousePayFeeDAO::calcTimeDiff(const std::string& start_time, const std::string& end_time)
{
	std::tm start_tm = { 0 };
	std::istringstream ss_start(start_time);
	ss_start >> std::get_time(&start_tm, "%Y-%m-%d");
	if (ss_start.fail()) {
		throw std::invalid_argument("Invalid start_time format. Expected format: YYYY-MM-DD");
	}

	// 解析结束时间
	std::tm end_tm = { 0 };
	std::istringstream ss_end(end_time);
	ss_end >> std::get_time(&end_tm, "%Y-%m-%d");
	if (ss_end.fail()) {
		throw std::invalid_argument("Invalid end_time format. Expected format: YYYY-MM-DD");
	}

	// 转换为time_t类型
	std::time_t start = std::mktime(const_cast<std::tm*>(&start_tm));
	std::time_t end = std::mktime(const_cast<std::tm*>(&end_tm));

	// 计算秒数差
	long seconds_diff = std::difftime(end, start);

	// 将秒数差转换为天数差，并返回四舍五入后的结果
	return std::round(static_cast<double>(seconds_diff) / (60 * 60 * 24));
}
DoubleJsonVO::Wrapper HousePayFeeDAO::calcHouseFee(const CalcHousePayDTO::Wrapper& detail)
{
	//计算无折扣的金额
	//计算费用类型
	//detail->fee_type
	auto fee_type_cd = detail->fee_type;
	//得到费用数据
	cout << "In GetCalcInfo" << endl;
	auto data = this->getHouseFeeCalcInfo(detail->community_id.getValue({ "" }), detail->config_id.getValue({""}), fee_type_cd);
	cout << data.getAdditionalAmount() << endl;
	cout << "Out GetCalcInfo" << endl;
	auto amount = DoubleJsonVO::createShared();

	//拆解公式 

	// 得到金额
	// 传入时间 - 结束时间 * square_price   * square
	
	auto start_time = detail->start_time.getValue({ "" });
	auto end_time = detail->end_time.getValue({ "" });
	cout << start_time << " " << end_time << endl;
	double time = calcTimeDiff(start_time,end_time);
	amount->data = data.getAdditionalAmount() + data.getSquarePrice() * (detail->built_up_area) *(time);
	
	//折扣计算 fee_discount fee_discount_spec
	
	auto info = CalcDiscountDTO::createShared();
	info->amount = amount->data;
	info->community_id = detail->community_id;
	info->fee_type = detail->fee_type;

	amount = calcDiscount(info);
	int scale = data.getScale();
	switch (scale) {

	case 2:
		amount->data = double(int(std::round(amount->data) * 10) / 10);
	case 3:
		amount->data = std::floor(amount->data);
		break;
	case 4:
		amount->data = std::ceil(amount->data);
		break;
	case 5:
		amount->data = int(std::round(amount->data));
	default:
		amount->data = double(int(std::round(amount->data) * 100) / 100);
	}

	return amount;
}
DoubleJsonVO::Wrapper HousePayFeeDAO::calcDiscount(const CalcDiscountDTO::Wrapper& info)
{
	auto resp = DoubleJsonVO::createShared();
	resp->data = info->amount;
	std::string sql = "SELECT fdr.discount_small_type, fdr.rule_name, fdrs.spec_id FROM fee_discount fd INNER JOIN fee_discount_rule fdr ON fd.rule_id = fdr.rule_id \
		INNER JOIN fee_discount_rule_spec fdrs ON fdr.rule_id = fdrs.rule_id \
		WHERE \
		fd.community_id = ? \
		AND fd.status_cd = 1 \
		AND fd.discount_name LIKE CONCAT('%', ? , '%')";
	auto mapper = std::make_shared<DiscountDOMapper>();
	auto lists = sqlSession->executeQuery<DiscountDO>(sql, *mapper, "%s%s", info->community_id, info->fee_type);
	
	//没有打折规则
	if (lists.size() == 0)
	{
		return resp;
	}
	double val;
	for (const auto& i : lists)
	{
		if (i.getDiscountSmallType() == 1 || i.getDiscountSmallType() == 4)
		{
			val = info->amount * i.getSpecValue();
		}
		else if (i.getDiscountSmallType() == 2 || i.getDiscountSmallType() == 5)
		{
			val = info->amount - i.getSpecValue();
		}
	}

	resp->data = val;
	return resp;

}
FeeTypeIdDO HousePayFeeDAO::getFeeTypeCd(const std::string type)
{
	//查询费用id
	std::string sql = "SELECT `status_cd` FROM `t_dict` WHERE `name`=?";
	auto mapper = std::make_shared<FeeTypeIdDOMapper>();
	return sqlSession->executeQueryOne<FeeTypeIdDO>(sql, *mapper, "%s", type);
}

CalcHouseFeeDO HousePayFeeDAO::getHouseFeeCalcInfo(const std::string& community_id, const std::string& config_id, const std::string& fee_type)
{
	std::string sql = "SELECT \
		pfc.square_price,\
		pfc.additional_amount, \
		pfc.scale, \
		pfc.units, \
		fff.formula_value \
		FROM \
		pay_fee_config pfc \
		INNER JOIN fee_formula fff ON pfc.computing_formula = fff.formula_type AND pfc.community_id = fff.community_id \
		WHERE \
		pfc.config_id = ? \
		AND pfc.community_id = ? \
		AND pfc.fee_type_cd = ? ";
	auto mapper = std::make_shared<CalcHouseFeeDOMapper>();
	return sqlSession->executeQueryOne<CalcHouseFeeDO>(sql, *mapper, "%s%s%s", community_id, config_id, fee_type);
	
}


Int32JsonVO::Wrapper HousePayFeeDAO::insertHouseFee(const AddPayFeeDO& payFee, const AddPayFeeConfigDO& payFeeConfig)
{
	auto val = Int32JsonVO::createShared();
	sqlSession->beginTransaction();
	std::string sql = "INSERT INTO pay_fee (fee_id, b_id, fee_type_cd, community_id, \
	payer_obj_id, income_obj_id, start_time, end_time, amount,\
 user_id, create_time, status_cd, fee_flag, state,\
 config_id, payer_obj_type, batch_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	auto res = sqlSession->executeUpdate(sql,"%s%s%s%s%s%s%s%s%d%s%s%s%s%s%s%s%s",\
		payFee.getFeeId(),payFee.getBId(), payFee.getFeeTypeCd(), payFee.getCommunityCd(),
		payFee.getPayerObjId(),payFee.getIncomeObjId(),payFee.getStartTime(),payFee.getEndTime(),payFee.getAmount(),\
		payFee.getUserId(),payFee.getStartTime(),payFee.getStatusCd(), payFee.getFeeFlag(), payFee.getState(), \
		payFee.getConfigId(),payFee.getPayerObjCd(), payFee.getBatchId());

	cout << payFee.getStatusCd() << endl;

	std::string sql_ = "INSERT INTO pay_fee_batch  (batch_id, community_id, create_user_id, \
	create_user_name, create_time, status_cd, \
 state, msg, remark) VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? )";

	auto ans = sqlSession->executeUpdate(sql_, "%s%s%s \
		%s%s%s \
		%s%s%s", \
//"1", "1", "1", "1", "1", "1", "1", "1", "1");
		payFeeConfig.getBatchId(), payFeeConfig.getCommunityId(), payFeeConfig.getCreateUserId(),\
		payFeeConfig.getCreateUserName(), payFeeConfig.getCreateTime(), payFeeConfig.getStatusCd(), \
		payFeeConfig.getState(), payFeeConfig.getMsg(), payFeeConfig.getRemark());

	sqlSession->commitTransaction();
	if (res && ans)
	{
		val->success(1);
		return val;
	}
	else
	{
		val->fail(0);
		return val;
	}
}
ModifyFeeInfoDO HousePayFeeDAO::searchModifyInfo(const std::string& fee_id)
{
	std::string sql = "SELECT \
		ff.formula_value,\
		pfc.square_price,\
		pfc.additional_amount,\
		br.built_up_area,\
		pf.community_id,\
		pf.fee_type_cd\
		FROM\
		pay_fee pf \
		JOIN \
		pay_fee_config pfc \
		ON pf.community_id = pfc.community_id \
		AND pf.config_id = pfc.config_id \
		AND pf.fee_type_cd = pfc.fee_type_cd \
		AND pfc.status_cd = 1 \
		JOIN \
		fee_formula ff \
		ON pfc.computing_formula = ff.formula_id \
 		AND ff.status_cd = 1 \
		JOIN \
		building_room br \
		ON pf.payer_obj_id = br.room_id \
		AND br.status_cd = 1 \
		WHERE \
		pf.fee_id = ? \
		AND pf.status_cd = 1";

	auto mapper = std::make_shared<MoidfyFeeInfoDOMapper>();
	return sqlSession->executeQueryOne<ModifyFeeInfoDO>(sql, *mapper, "%s", fee_id);
}
Int32JsonVO::Wrapper HousePayFeeDAO::modifyHoueFee(const  ModifyHouseFeeDTO::Wrapper& modifyInfo, const Float64& amount)
{
	// 
	
	// 更新费用 : start_time end_time amount
	string sql = "UPDATE pay_fee\
		SET start_time = ? ,\
		end_time = ? ,\
		amount = ?\
		WHERE fee_id = ? ";
	auto resp = Int32JsonVO::createShared();
	int line = sqlSession->executeUpdate(sql, "%s%s%d%s", modifyInfo->start_time.getValue({ "" }), modifyInfo->end_time.getValue({ "" }), amount.getValue({}), modifyInfo->fee_id.getValue({ "" }));
	cout << "line : " << line << endl;
	if (line > 0)
	{
		resp->success(line);
		resp->message = u8"更改成功";
		cout << "succsess" << endl;
	}
	else
	{
		resp->fail(line);
		resp->message = u8"更改失败";
		cout << "fail" << endl;
	}
	return resp;
}

StatusTimeDO HousePayFeeDAO::searchFeeState(const string& fee_id)
{
	string sql = "SELECT\
		status_cd,\
		state,\
		start_time,\
		end_time,\
		config_id\
		FROM\
		pay_fee\
		WHERE\
		fee_id = ? ";
	auto mapper = std::make_shared<StatusTimeDOMapper>();
	return sqlSession->executeQueryOne<StatusTimeDO >(sql, *mapper, "%s", fee_id);
}

std::list<DiscountInfoDO> HousePayFeeDAO::searchFeeDiscount(const string& config_id)
{
	string sql = "SELECT \
		fd.discount_type,\
		fds.spec_value\
		FROM\
		pay_fee_config_discount pfc\
		INNER JOIN\
		fee_discount fd ON pfc.discount_id = fd.discount_id\
		INNER JOIN\
		fee_discount_spec fds ON pfc.discount_id = fds.discount_id\
		WHERE\
		pfc.config_id = ? \
		AND fd.status_cd = 1;";

	auto mapper = std::make_shared<DiscountInfoDOMapper>();
	return sqlSession->executeQuery<DiscountInfoDO>(sql,*mapper,"%s",config_id);
}

Int32JsonVO::Wrapper HousePayFeeDAO::insertPayFee(const PaymentInfoDO& pay)
{
	auto vo = Int32JsonVO::createShared();
	string sql = "INSERT INTO pay_fee_detail (detail_id, b_id, fee_id, community_id, cycles,\
 receivable_amount, received_amount, prime_rate, remark, create_time, \
status_cd,  state, start_time, end_time, payable_amount,\
pay_order_id, cashier_id, cashier_name, open_invoice, acct_amount,\
 discount_amount, deduction_amount, late_amount,gift_amount) \
VALUES (?, ?, ?, ?, ?, \
?, ?, ?, ?, ?,\
 ?, ?, ?, ?, ?,\
 ?, ?, ?, ?, ?, \
?, ?, ?,?)";

	// 赋值变量
	auto detailId = pay.getDetailId();
	auto bId = pay.getBId();
	auto feeId = pay.getFeeId();
	auto communityId = pay.getCommunityId();
	auto cycles = pay.getCycles();

	auto receivableAmount = pay.getReceivableAmount();
	auto receivedAmount = pay.getReceivedAmount();
	auto primeRate = pay.getPrimeRate();
	auto remark = pay.getRemark();
	auto createTime = pay.getCreateTime();

	auto statusCd = pay.getStatusCd();
	string state = "1400";
	auto startTime = pay.getStartTime();
	auto endTime = pay.getEndTime();
	auto payableAmount = pay.getPayableAmount();

	auto payOrderId = pay.getPayOrderId();
	auto cashierId = pay.getCashierId();
	auto cashierName = pay.getCashierName();
	auto openInvoice = pay.getOpenInvoice();
	auto acctAmount = pay.getAcctAmount();

	auto discountAmount = pay.getDiscountAmount();
	auto deductionAmount = pay.getDeductionAmount();
	auto lateAmount = pay.getLateAmount();
	auto giftAmount = pay.getGiftAmount();

	// 使用变量进行输出
	

 	int line =  sqlSession->executeUpdate(sql,
		"%s%s%s%s%d%d%d%d%s%s%s%s%s%s%d%s%s%s%b%d%d%d%d%d",
		detailId,bId,feeId,communityId,cycles,
		receivableAmount,receivedAmount, primeRate, remark,createTime,
		statusCd,state, startTime, endTime, payableAmount,
		payOrderId,cashierId,cashierName, openInvoice,acctAmount,
		discountAmount,deductionAmount,lateAmount,giftAmount);

	
	sql = "UPDATE pay_fee SET state = 2009001 WHERE fee_id = ?";

	int kk = sqlSession->executeUpdate(sql, "%s", pay.getFeeId());
	cout << "kk = " << kk << endl;
	if (kk >= 1 && line >= 1)
	{
		vo->success(1);
		vo->message = u8"缴费成功";
	}
	else
	{
		vo->fail(1);
		vo->message = u8"缴费失败";
	}

	return vo;
}
