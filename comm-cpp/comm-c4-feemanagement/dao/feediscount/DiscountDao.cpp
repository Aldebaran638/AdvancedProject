#include "stdafx.h"
#include "DiscountDao.h"

#include "../../domain/do/feediscount/DiscountDo.h"
#include "../../domain/query/feediscount/DiscountQuery.h"
#include "DiscountMapper.h"

//************************************
std::string DiscountDAO::queryConditionBuilder(const DiscountQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << "WHERE 1=1 ";
	if (query->discount_id) {
		sqlCondition << "AND discount_id = ? ";
		SQLPARAMS_PUSH(params,"s",std::string,query->discount_id.getValue(""));
	}

	if (query->discount_name) {
		sqlCondition << "AND discount_name = ？ ";
		SQLPARAMS_PUSH(params,"s",std::string,query->discount_name.getValue(""));
	}

	if (query->discount_type) {
		sqlCondition << "AND discount_type = ？ ";
		SQLPARAMS_PUSH(params, "s", std::string, query->discount_type.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t DiscountDAO::insert(const DiscountDo& iObj) {
	SqlParams params;
	string sql_fee_discount = "INSERT INTO fee_discount VALUES(?,?,?,?,?,?, NOW() ,'0') ";
	uint64_t RE_fee_discount= sqlSession->executeUpdate(sql_fee_discount,"%s%s%s%s%s%s" //6个
		,iObj.getDiscountId(),iObj.getCommunityId(),iObj.getDiscountType(),iObj.getDiscountName(),
		iObj.getDiscountDesc(), iObj.getRuleId()/*,iObj.getCreateTime())*/);
	if (RE_fee_discount == 0) {
		return -1;
	}

	std::vector<string> discountspecid = iObj.getDiscountSpecId();
	std::vector<string> specid = iObj.getSpecId();
	std::vector<string> specname = iObj.getSpecName();
	std::vector<string> specvalue = iObj.getSpecValue();
	int len = specid.size();

	string sql_fee_discount_spec = "INSERT INTO fee_discount_spec VALUES(?,?,?,?,?,?, NOW() ,'0' ) ";


	for (int i = 0;i < len;i++) {
		uint64_t RE_fee_discount_spec = sqlSession->executeUpdate(sql_fee_discount_spec, "%s%s%s%s%s%s",	//6个
			discountspecid[i], iObj.getDiscountId(), iObj.getCommunityId(), specid[i], specname[i], specvalue[i]/*,iObj.getCreateTime()*/);
		if (RE_fee_discount_spec == 0) {
			return -1;
		}
	}
	return 1;
}
uint64_t DiscountDAO::update(const DiscountDo& uObj) {
	return 1;
}

int DiscountDAO::count() {
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM fee_discount ";
	return sqlSession->executeQueryNumerical(sql,params);
}

uint64_t DiscountDAO::delete_(const DiscountDo& dObj) {
	string id = dObj.getDiscountId();

	string sql1 = "DELETE FROM fee_discount WHERE discount_id = ? ";
	string sql2 = "DELETE FROM fee_discount_spec WHERE discount_id = ? ";
	int re1 = sqlSession->executeUpdate(sql1,"%s", id);
	int re2 = sqlSession->executeUpdate(sql2,"%s", id);
	return 1;
}

// 分页查询数据
vector<DiscountDo> DiscountDAO::selectWithPage(const DiscountQuery::Wrapper& query) {
	SqlParams params;
	vector<DiscountDo> res;
	string sql = "SELECT fd.discount_id , fd.discount_name , fd.discount_type , fdr.rule_name , fd.create_time , fd.rule_id FROM fee_discount fd LEFT JOIN fee_discount_rule fdr ON fd.rule_id = fdr.rule_id ";
	sql += "LIMIT " + std::to_string((query->pageIndex - 1) * query->pageSize) + "," + std::to_string(query->pageSize);
	DiscountPageMapper mapper;
	list<DiscountPageDo> mre = sqlSession->executeQuery<DiscountPageDo>(sql,mapper,params);
	int len = mre.size();
	for (DiscountPageDo i : mre) {
		string id = i.getDiscountId();
		string sql2 = "SELECT spec_name,spec_value FROM fee_discount_spec WHERE discount_id = '" + id + "' ";
		DiscountSpecPageMapper mapper2;
		list<DiscountSpecPageDo> fre = sqlSession->executeQuery<DiscountSpecPageDo>(sql2, mapper2, params);
		
		vector<string> specName;
		vector<string> specValue;
		for (DiscountSpecPageDo s : fre) {
			specName.push_back(s.getSpecName());
			specValue.push_back(s.getSpecValue());
		}

		//组装
		DiscountDo data;
		data.setDiscountId(i.getDiscountId());
		data.setDiscountName(i.getDiscountName());
		data.setDiscountType(i.getDiscountType());
		data.setRuleName(i.getRuleName());
		data.setCreateTime(i.getCreateTime());
		data.setSpecName(specName);
		data.setSpecValue(specValue);
		data.setRuleId(i.getRuleId());
		res.push_back(data);
	}
	return res;
}
