#include "stdafx.h"
#include "FeeItemService.h"
#include "../../dao/FeeItemDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "id/SnowFlake.h"
#include "id/UuidFacade.h"
#include <iostream> // 方便打印

FeeItemPageDTO::Wrapper FeeItemService::listAll(const FeeItemQuery::Wrapper& query)
{
	std::cout << "[Service] listAll called with pageIndex=" << query->pageIndex
		<< ", pageSize=" << query->pageSize
		<< ", config_id=" << (query->config_id ? query->config_id->c_str() : "null") << std::endl;

	auto pages = FeeItemPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	FeeItemDAO dao;
	uint64_t count = dao.count(query);

	std::cout << "[Service] total count from dao.count = " << count << std::endl;

	if (count == 0) {
		std::cout << "[Service] No data found, return empty pages" << std::endl;
		return pages;
	}

	pages->total = count;
	pages->calcPages();

	auto result = dao.selectWithPage(query);

	std::cout << "[Service] dao.selectWithPage returned " << result.size() << " records" << std::endl;

	auto dataList = oatpp::List<FeeItemDTO::Wrapper>::createShared();


	for (const auto& sub : result)
	{
		auto dto = FeeItemDTO::createShared();
		dto->config_id = sub.getConfig_id();
		dto->fee_type_cd = sub.getFee_type_cd();
		dto->fee_flag = sub.getFee_flag();
		dto->payment_cycle = sub.getPayment_cycle();
		dto->fee_name = sub.getFee_name();
		dto->payment_cd = sub.getPayment_cd();
		dto->prepayment_period = sub.getPrepayment_period();
		dto->start_time = sub.getStart_time();
		dto->end_time = sub.getEnd_time();
		dto->units = sub.getUnits();
		dto->deduct_from = sub.getDeduct_from();
		dto->pay_online = sub.getPay_online();
		dto->scale = sub.getScale();
		dto->decimal_place = sub.getDecimal_place();
		dto->computing_formula = sub.getComputing_formula();
		dto->square_price = sub.getSquare_price();
		dto->additional_amount = sub.getAdditional_amount();
		dto->community_id = sub.getCommunity_id();
		dto->operation_Time = sub.getCreate_Time();  // 用 DO 中 createTime 填充 DTO 中 operationTime
		dto->user_name = sub.getName();
		// 这里你可以打印下每条数据的主要字段
		std::cout << "[Service] Mapping DO to DTO config_id=" << dto->config_id->c_str() << std::endl;


		dataList->push_back(dto);
	}

	pages->rows = dataList;

	std::cout << "[Service] Returning pages with total=" << pages->total << std::endl;

	return pages;
}
std::string FeeItemService::saveData(const FeeItemAddDTO::Wrapper& dto) {
	// 1. 生成 config_id 和 b_id
	SnowFlake sf1(1, 1);
	SnowFlake sf2(1, 2); // 改变 workerId 或 datacenterId
	std::string configId = std::to_string(sf1.nextId());
	std::string bId = std::to_string(sf2.nextId());

	// 2. 创建并填充 DO 对象
	FeeItemDO data;
	// 生成ID
	//UuidFacade uf;
	//data.setUser_Id(uf.genUuid());
	data.setConfig_id(configId);
	data.setB_id(bId);
	data.setFee_type_cd(dto->fee_type_cd.getValue(""));
	data.setFee_flag(dto->fee_flag.getValue(""));
	data.setPayment_cycle(dto->payment_cycle.getValue(""));
	data.setFee_name(dto->fee_name.getValue(""));
	data.setPayment_cd(dto->payment_cd.getValue(""));
	data.setPrepayment_period(dto->prepayment_period.getValue(""));
	data.setStart_time(dto->start_time.getValue(""));
	data.setEnd_time(dto->end_time.getValue(""));
	data.setUnits(dto->units.getValue(""));
	data.setDeduct_from(dto->deduct_from.getValue(""));
	data.setPay_online(dto->pay_online.getValue(""));
	data.setScale(dto->scale.getValue(""));
	data.setDecimal_place(dto->decimal_place.getValue(4));
	data.setComputing_formula(dto->computing_formula.getValue(""));
	data.setSquare_price(dto->square_price.getValue(""));
	data.setAdditional_amount(dto->additional_amount.getValue(""));
	data.setCommunity_id(dto->community_id.getValue(""));
	// 设置创建人
	data.setUser_Id(dto->getPayload()->getId());
	// 3. 日志输出
	OATPP_LOGD("FeeItemService", "准备插入数据 config_id=%s, b_id=%s, community_id=%s",
		configId.c_str(), bId.c_str(), data.getCommunity_id().c_str());

	// 4. 插入数据库
	int ret = FeeItemDAO().insert(data);
	if (ret != 1) {
		OATPP_LOGE("FeeItemService", "插入失败 config_id=%s", configId.c_str());
		return "";
	}

	OATPP_LOGI("FeeItemService", "插入成功 config_id=%s", configId.c_str());
	return configId;
}

bool FeeItemService::updateData(const FeeItemModifyDTO::Wrapper& dto)
{
	FeeItemDO data;
	data.setConfig_id(dto->config_id.getValue({}));
	data.setFee_type_cd(dto->fee_type_cd.getValue({}));
	data.setFee_flag(dto->fee_flag.getValue({}));
	data.setPayment_cycle(dto->payment_cycle.getValue({}));
	data.setFee_name(dto->fee_name.getValue({}));
	data.setPayment_cd(dto->payment_cd.getValue({}));
	data.setPrepayment_period(dto->prepayment_period.getValue({}));
	data.setStart_time(dto->start_time.getValue({}));
	data.setEnd_time(dto->end_time.getValue({}));
	data.setUnits(dto->units.getValue({}));
	data.setDeduct_from(dto->deduct_from.getValue({}));
	data.setPay_online(dto->pay_online.getValue({}));
	data.setScale(dto->scale.getValue({}));
	data.setDecimal_place(dto->decimal_place.getValue(0));
	data.setComputing_formula(dto->computing_formula.getValue({}));
	data.setSquare_price(dto->square_price.getValue({}));
	data.setAdditional_amount(dto->additional_amount.getValue({}));
	data.setUser_Id(dto->getPayload()->getId());

	FeeItemDAO dao;
	bool res = dao.update(data) == 1;
	if (res) {
		dao.modifyBusiness(data); // 更新业务表，或插入一条操作记录
	}
	return res;
}

bool FeeItemService::removeData(const FeeItemDeleteDTO::Wrapper& dto)
{
	FeeItemDO data;
	data.setConfig_id(dto->config_id.getValue({}));

	FeeItemDAO dao;

	// 先执行 modifyBusiness，插入 DEL 记录（但不插入 ADD）
	dao.deleteBusiness(data); // 只插入 DEL，ADD 可以省略或在里面判断是否是删除操作
	//data.setUser_Id(dto->getPayload()->getId());
	// 然后执行真正的删除
	return dao.deleteById(data) == 1;
}
