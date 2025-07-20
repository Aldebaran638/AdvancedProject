#include "stdafx.h"
#include "AnalysisArrearsDAO.h"
#include "AnalysisArrearsMapper.h"
#include <sstream>

std::string AnalysisArrearsDAO::getCurrentTime(void) {
	// 获取当前时间
	std::time_t now = std::time(nullptr);
	std::tm* local_time = std::localtime(&now);

	// 格式化为字符串
	std::ostringstream oss;
	oss << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");
	std::string time_str = oss.str();
	return time_str;
	// return "2025-05-28 00:00:00";
}

std::string AnalysisArrearsDAO::queryConditionBuilder(const AnalysisArrearsQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	if (query->communityId) {
		sqlCondition << " AND f.community_id = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	}
	if (query->buildingNum) {
		sqlCondition << " AND f.floor_num = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->buildingNum.getValue(""));
	}
	return sqlCondition.str();
}

std::list<AnalysisArrearsDO> AnalysisArrearsDAO::selectFeeType(void)
{
	SqlParams params;
	string sql = "SELECT name, fee_type_cd FROM store_fee_type";
	// 执行查询
	AnalysisArrearsFeeTypeMapper mapper;
	cout << sql << endl;
	return sqlSession->executeQuery<AnalysisArrearsDO>(sql, mapper, params);
}

std::list<AnalysisArrearsDO> AnalysisArrearsDAO::selectBuildingNum(const AnalysisArrearsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT floor_num, floor_id FROM f_floor WHERE 1 = 1 ";
	if (query->communityId) {
		sql += "AND community_id = ? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->communityId.getValue(""));
	}
	// 执行查询
	AnalysisArrearsBuildingNumMapper mapper;
	cout << sql << endl;
	return sqlSession->executeQuery<AnalysisArrearsDO>(sql, mapper, params);
}