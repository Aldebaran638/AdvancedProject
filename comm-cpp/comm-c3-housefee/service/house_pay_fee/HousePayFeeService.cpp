#include "stdafx.h"
#include "HousePayFeeService.h"
#include "../../dao/HousePayFee/HousePayFeeDAO.h"
#include "../../lib-common/include/id/SnowFlake.h"

Int32JsonVO::Wrapper HousePayFeeService::addHousePayFee(const AddHouseFeeDTO::Wrapper& houseFee, const std::shared_ptr<PayloadDTO> payload)
{
	HousePayFeeDAO dao;
	//开启一个事务
	auto configId = houseFee->config_id.getValue({""});
	// 查询community_id
	cout << "In Find" << endl;
	auto xxx = dao.findCommunityId(houseFee->config_id.getValue({ "" }));
	
	cout << xxx.getCommunity() << endl;
	cout << xxx.getFeeTypeCd() << endl;
	auto resp = Int32JsonVO::createShared();
	std::string house_id = houseFee->house_id.getValue({ "" });
	
	std::vector<std::string> num(3);
	int idx = 0;
	//分割 house_id
	std::string sub_string;
	for (const auto& i : house_id)
	{
		if (i == '-')
		{
			num[idx] = sub_string;
			idx++;
			sub_string.clear();
		}
		else
			sub_string += i;
	}
	num[2] = sub_string;
	cout << num[0] << " " << num[1] << " " << num[2] << endl;
	std::string floor_num, unit_num, room_num;
	//查询房屋id 和 建筑面积等信息
	cout << "In HouseInfo" << endl;
	auto houseInfo = dao.searchHouseInfo(num[0], num[1], num[2], xxx.getCommunity());
	cout << houseInfo.getRoomId() << endl;
	
	//计算金额 传入community_id 和 config_id
	auto detail = CalcHousePayDTO::createShared();
	
	detail->charge_project = houseFee->charge_project;
	detail->room_area = houseInfo.getRoomArea();
	detail->built_up_area = houseInfo.getBuiltUpArea();
	detail->fee_type = xxx.getFeeTypeCd();
	detail->start_time = houseFee->start_time;
	detail->end_time = houseFee->end_time;

	cout << "In calcFee" << endl;
	auto amount = dao.calcHouseFee(detail);
	cout << "Out calcFee" << endl;
	//拼接数据
	auto payFeeDO = std::make_shared<AddPayFeeDO>();
	auto payFeeBatch = std::make_shared<AddPayFeeConfigDO>();
	//生成fee_id
	AddPayFeeDO x;

	SnowFlake sf(1, 1);
	payFeeDO->setCommunityCd(xxx.getCommunity());
	std::string id = std::to_string(sf.nextId());

	payFeeDO->setFeeId(id);

	// 生成b_id
	//std::to_string(sf.nextId())
	payFeeDO->setBId(id);

	//生成batch_id
	payFeeBatch->setBatchId(id);
	payFeeDO->setBatchId(id);

	payFeeDO->setFeeTypeCd(xxx.getFeeTypeCd());
	payFeeDO->setPayerObjId(houseInfo.getRoomId());

	payFeeDO->setIncomeObjId(payload->getId());

	payFeeDO->setStartTime(detail->start_time.getValue({ "" }));
	payFeeDO->setEndTime(detail->end_time.getValue({ "" }));
	
	payFeeDO->setAmount(amount->data.getValue({}));
	//设置status_cd
	payFeeDO->setStatusCd("1");
	payFeeBatch->setStatusCd("1");

	payFeeDO->setFeeFlag(xxx.getFeeFlag());
	payFeeDO->setUserId(payload->getId());
	payFeeDO->setConfigId(houseFee->config_id.getValue({ "" }));

	int res = checkDateRange(payFeeDO->getStartTime(), payFeeDO->getEndTime());

	if (res == 1)
	{
		payFeeDO->setState("2008001");
		payFeeBatch->setState("2008001");
	}
	else if (res == 2)
	{
		payFeeDO->setState("2007001");
		payFeeBatch->setState("2007001");
	}
	else
	{
		payFeeDO->setState("2009001");
		payFeeBatch->setState("2009001");
	}

	//
	payFeeDO->setPayerObjCd(houseFee->fee_type.getValue({""}));
	
	payFeeDO->setPayerObjId(payload->getId());

	//=======payFeeConfig
	payFeeBatch->setCommunityId(xxx.getCommunity());
	payFeeBatch->setCreateUserId(payload->getId());
	payFeeBatch->setCreateUserName(payload->getUsername());
	payFeeBatch->setMsg("NULL");
	payFeeBatch->setRemark("NULL");
	//create_time
	auto now = std::chrono::system_clock::now();
	std::time_t current_time = std::chrono::system_clock::to_time_t(now);

	// 转换为本地时间
	std::tm* local_time = std::localtime(&current_time);

	// 格式化时间字符串 (YYYY-MM-DD HH:MM:SS)
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);

	payFeeBatch->setCreateTime(std::string(buffer));
	payFeeDO->setCreateTime(std::string(buffer));
	// 插入数据库
	cout << "In HouseFee" << endl;
	resp = dao.insertHouseFee(*payFeeDO, *payFeeBatch);

	//关闭事务                                                                                                                                                                              
	return resp;
}

int  HousePayFeeService::checkDateRange(const std::string& date1, const std::string& date2) {
	// 将字符串日期转换为time_t（午夜时间戳）
	auto strToTimeT = [](const std::string& dateStr) -> time_t {
		std::tm tm = {};
		std::istringstream ss(dateStr);
		ss >> std::get_time(&tm, "%Y-%m-%d");
		tm.tm_isdst = -1; // 自动处理夏令时
		return std::mktime(&tm);
		};

	// 获取当前日期的午夜时间戳
	time_t now = time(nullptr);
	std::tm* now_tm = std::localtime(&now);
	now_tm->tm_hour = 0;
	now_tm->tm_min = 0;
	now_tm->tm_sec = 0;
	now_tm->tm_isdst = -1;
	time_t now_midnight = std::mktime(now_tm);

	// 转换输入日期
	time_t t1 = strToTimeT(date1);
	time_t t2 = strToTimeT(date2);

	// 确定最早和最晚日期
	time_t early = (t1 < t2) ? t1 : t2;
	time_t late = (t1 > t2) ? t1 : t2;

	// 检查当前日期位置
	if (now_midnight < early) {
		return 2; // 当前日期早于最早日期
	}
	else if (now_midnight > late) {
		return 0; // 当前日期晚于最晚日期
	}
	return 1; // 当前日期在区间内（包含边界）
}

 Int32JsonVO::Wrapper HousePayFeeService::removeHousePayFee(const HouseFeeIdDTO::Wrapper& delInfo)
{
	
	HousePayFeeDAO dao;
	auto res = dao.deleteHouseFee(delInfo->fee_id.getValue({ "" }));
	return res;
}


 Int32JsonVO::Wrapper HousePayFeeService::modifyHousePayFee(const ModifyHouseFeeDTO::Wrapper& modifyInfo)
 {
	 HousePayFeeDAO dao ;
	 cout << "In SearchModifyInfo " << endl;
	 auto info = dao.searchModifyInfo(modifyInfo->fee_id.getValue({ "" }));
	 cout << "Out SearchModifyInfo " << endl;

	 //计算时间差
	double diff =  dao.calcTimeDiff(modifyInfo->start_time.getValue({ "" }), modifyInfo->end_time.getValue({ "" }));
	 Float64 amount;
	 amount = info.getAdditionalPrice() + info.getBuildUpArea()* info.getSquarePrice() * diff;

	 auto dto = CalcDiscountDTO::createShared() ;
	 dto->community_id = info.getCommunityId();
	 dto->fee_type = info.getFeeType();
	 dto->amount = amount;
	 // 计算折扣费用
	 cout << "In calcDiscount " << endl;
	 amount = dao.calcDiscount(dto)->data;
	 cout << "OutcalcDiscount " << endl;
	 
	 return dao.modifyHoueFee(modifyInfo,amount);

 }

 std::string getCurrentTimeString() {
	 // 获取当前系统时间
	 auto now = std::chrono::system_clock::now();
	 std::time_t current_time = std::chrono::system_clock::to_time_t(now);

	 // 转换为本地时间
	 std::tm* local_time = std::localtime(&current_time);

	 // 格式化时间字符串 (YYYY-MM-DD HH:MM:SS)
	 char buffer[80];
	 std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);

	 return std::string(buffer);
 }
 Int32JsonVO::Wrapper HousePayFeeService::payHouseFee(const PayFeeDTO::Wrapper& pay, const std::shared_ptr<PayloadDTO> payload)
 {
	 HousePayFeeDAO dao;
	 PaymentInfoDO data;
	
	 //雪花算法生成id
	 SnowFlake sf(1, 1);
	 data.setDetailId(std::to_string(sf.nextId()));

	// 批次b_id
	 SnowFlake sf1(1, 2);
	 data.setBId(std::to_string(sf1.nextId()));
	// fee_id
	 data.setFeeId(pay->fee_id.getValue({ "" }));
	 // community_id
	 data.setCommunityId(pay->community_id.getValue({ "" }));
	 // cycles
	 if (pay->real_cycle != 0)
	 {

	 }
	 data.setCycles(pay->cycle.getValue({ }));

	 // receivable_amount
	 data.setReceivableAmount(pay->amount_due);
	 //received_amount
	 data.setReceivedAmount(pay->pay_amount);
	 //pay->pay_fee_way.getValue({""})
	 int way = 1;
	 if (pay->pay_fee_way.getValue({ "" }) == u8"微信")
	 {
		 way = 1;
	 }
	 else if (pay->pay_fee_way.getValue({ "" }) == u8"现金")
	 {
		 way = 2;
	 }
	 else if (pay->pay_fee_way.getValue({ "" }) == u8"账户抵扣")
	 {
		 way = 3;
	 }
	 //prime_rate
	 data.setPrimeRate(way);
	 //  remark
	 data.setRemark(pay->remark.getValue({ "" }));
	 // create_time
	 data.setCreateTime(getCurrentTimeString());
	 
	 
	 StatusTimeDO timeDO = dao.searchFeeState(pay->fee_id.getValue({ "" }));

	 //status_cd
	 data.setStatusCd("1");
	 data.setState("1");
	 data.setStartTime(getCurrentTimeString());
	 data.setEndTime(getCurrentTimeString());

	 data.setStatusCd(timeDO.getStatusCd());
	 data.setState(timeDO.getState());
	 data.setStartTime(timeDO.getStartTime());
	 data.setEndTime(timeDO.getEndTime());

	 cout << data.getStatusCd() << " " << data.getState() << " " << data.getStartTime() << " " << data.getEndTime() << endl;

	 //payable_amount
	 data.setPayableAmount(pay->amount);

	 //pay_order_id
	 SnowFlake sf2(2, 2);
	 data.setPayOrderId(std::to_string(sf2.nextId()));
	 
	 //cashier_id
	
	 data.setCashierId(payload->getId());
	 data.setCashierName(payload->getUsername());

	 // open_invoice
	 data.setOpenInvoice(false);
	 data.setAcctAmount(0);

	 auto info = dao.searchFeeDiscount(timeDO.getConfigId());

	 data.setDiscountAmount(0), data.setDeductionAmount(0), data.setLateAmount(0);
	 for (const auto& i : info)
	 {
		 if (i.getDiscountType() == "1001")
		 {
			 if (i.getSpecValue() < 1)
			 {
				 data.setDiscountAmount(data.getAcctAmount() * i.getSpecValue());
			 }
			 else
			 {
				 data.setDeductionAmount(data.getAcctAmount() + i.getSpecValue());
			 }
		 }
		 else
		 {
			 data.setLateAmount(i.getSpecValue());
		 }
	 }
	 //赠送金额
	 data.setGiftAmount(0);

	 
	 return dao.insertPayFee(data);
 }
