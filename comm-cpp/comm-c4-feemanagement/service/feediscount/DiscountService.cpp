#include "stdafx.h"
#include "service/feediscount/DiscountService.h"

#include "../../domain/do/feediscount/DiscountDo.h"
#include "../../domain/query/feediscount/DiscountQuery.h"
 
#include "id/UuidFacade.h"


string DiscountService::saveData(const DiscountAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	DiscountDo data;
	UuidFacade uuid;

	string discountId = uuid.genUuid().substr(0,30);
	string commuId = uuid.genUuid().substr(0, 30);

	//获得 oatpp::Vector与长度
	oatpp::Vector<oatpp::String> specName = dto->spec_name;
	oatpp::Vector<oatpp::String> specValue = dto->spec_value;
	int Specsize = specName->size();

	//生成specId 和 discountSpecId
	vector<string> specId;
	for (int i = 1;i <= Specsize;i++) {
		specId.push_back(uuid.genUuid().substr(0, 30));
	}

	vector<string> discountSpecId;
	for (int i = 1;i <= Specsize;i++) {
		discountSpecId.push_back(uuid.genUuid().substr(0, 30));
	}

	// oatp::Vector<oatpp::String> 转为 std::Vector<string>
	std::vector<string> newSpecName;
	for (const auto& item : *specName) {
		const char* cstr = item->c_str();
		string va(cstr);
		newSpecName.push_back(va);
	}

	std::vector<string> newSpecValue;
	for (const auto& item : *specValue) {
		const char* cstr = item->c_str();
		string va(cstr);
		newSpecValue.push_back(va);
	}
	
	//赋值
	data.setDiscountId(discountId);
	data.setCommunityId(commuId);
	data.setDiscountSpecId(discountSpecId);
	data.setSpecId(specId);
	data.setSpecName(newSpecName);
	data.setSpecValue(newSpecValue);

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		DiscountType, discount_type,
		DiscountName, discount_name,
		DiscountDesc, discount_desc,
		RuleId,rule_id)
		string rec;
	if (dao.insert(data) == 1) {
		rec = discountId;
	}
	else {
		rec = "";
	}

	return rec;
}

int DiscountService::deleteDate(const DiscountDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
	DiscountDo data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		DiscountId, discount_id);
	return dao.delete_(data);
}

string DiscountService::updateData(const DiscountChangeDTO::Wrapper& dto, const PayloadDTO& payload) {
	DiscountDo deledata;
	DiscountDo data;
	string discountId = dto->discount_id.getValue({});
	deledata.setDiscountId(discountId);
	dao.delete_(deledata);

	UuidFacade uuid;
	string commuId = uuid.genUuid().substr(0, 30);

	//获得 oatpp::Vector与长度
	oatpp::Vector<oatpp::String> specName = dto->spec_name;
	oatpp::Vector<oatpp::String> specValue = dto->spec_value;
	int Specsize = specName->size();

	//生成specId 和 discountSpecId
	vector<string> specId;
	for (int i = 1;i <= Specsize;i++) {
		specId.push_back(uuid.genUuid().substr(0, 30));
	}

	vector<string> discountSpecId;
	for (int i = 1;i <= Specsize;i++) {
		discountSpecId.push_back(uuid.genUuid().substr(0, 30));
	}

	// oatp::Vector<oatpp::String> 转为 std::Vector<string>
	std::vector<string> newSpecName;
	for (const auto& item : *specName) {
		const char* cstr = item->c_str();
		string va(cstr);
		newSpecName.push_back(va);
	}

	std::vector<string> newSpecValue;
	for (const auto& item : *specValue) {
		const char* cstr = item->c_str();
		string va(cstr);
		newSpecValue.push_back(va);
	}

	//赋值
	data.setDiscountId(discountId);
	data.setCommunityId(commuId);
	data.setDiscountSpecId(discountSpecId);
	data.setSpecId(specId);
	data.setSpecName(newSpecName);
	data.setSpecValue(newSpecValue);

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		DiscountType, discount_type,
		DiscountName, discount_name,
		DiscountDesc, discount_desc,
		RuleId, rule_id)
		string rec;
	if (dao.insert(data) == 1) {
		rec = discountId;
	}
	else {
		rec = "";
	}

	return rec;
}

DiscountPageDTO::Wrapper DiscountService::listAll(const DiscountQuery::Wrapper& query) {
	auto pages = DiscountPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	DiscountDAO dao;
	int count = dao.count();
	if (count <= 0) {
		return pages;
	}

	pages->total = count;
	pages->calcPages();
	vector<DiscountDo> res = dao.selectWithPage(query);
	for (DiscountDo i : res) {
		auto dto = DiscountPageShowDTO::createShared();
		dto->discount_id = i.getDiscountId();
		dto->discount_name = i.getDiscountName();
		dto->discount_type = i.getDiscountType();
		dto->rule_name = i.getRuleName();
		dto->rule_id = i.getRuleId();
		dto->create_time = i.getCreateTime();
		auto oldSpecName = i.getSpecName();
		auto specName = oatpp::Vector<oatpp::String>::createShared();
		specName->reserve(oldSpecName.size());
		for (const auto& item : oldSpecName) {
			specName->push_back(oatpp::String(item));
		}
		dto->spec_name = specName;

		auto oldSpecValue = i.getSpecValue();
		auto specValue = oatpp::Vector<oatpp::String>::createShared();
		specValue->reserve(oldSpecValue.size());
		for (const auto& item : oldSpecValue) {
			specValue->push_back(oatpp::String(item));
		}
		dto->spec_value = specValue;
		pages->addData(dto);
	}
	return pages;
}