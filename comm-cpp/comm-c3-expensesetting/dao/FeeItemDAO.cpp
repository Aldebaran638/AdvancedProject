#include "stdafx.h"
#include "FeeItemDAO.h"
#include "mapper/FeeItemPostMapper.h"
#include "mapper/FeeItemGetMapper.h"
#include <sstream>
#include "oatpp/core/data/mapping/type/Any.hpp"
#include "oatpp/orm/Executor.hpp"
#include "oatpp/core/Types.hpp"
#define SQLPARAMS_PUSH(__PARAMS__, __PARAM_KEY__, __VAL_TYPE__, __VAL_VAL__) \
__PARAMS__.emplace_back(SqlParam(__PARAM_KEY__, std::make_shared<__VAL_TYPE__>(__VAL_VAL__)))
#define LOG_E(fmt, ...) printf("[ERROR] " fmt "\n", ##__VA_ARGS__)
#define LOG_D(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#define LOG_I(fmt, ...) printf("[INFO ] " fmt "\n", ##__VA_ARGS__)
std::string FeeItemDAO::queryConditionBuilder(const FeeItemQuery::Wrapper& query, SqlParams& params)
{
	std::stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";

	if (query->config_id && !query->config_id->empty()) {
    std::cout << "query->config_id = [" << query->config_id.getValue("") << "]" << std::endl;
    sqlCondition << " AND `config_id` = ?";
    SQLPARAMS_PUSH(params, "s", std::string, query->config_id.getValue(""));
}


	return sqlCondition.str();
}


uint64_t FeeItemDAO::count(const FeeItemQuery::Wrapper& query)
{
	std::cout << "[DAO] count called with config_id=" << (query->config_id ? query->config_id->c_str() : "null") << std::endl;
	SqlParams params;
	std::string sql = "SELECT COUNT(*) FROM business_pay_fee_config ";
	sql += queryConditionBuilder(query, params);
	uint64_t cnt = sqlSession->executeQueryNumerical(sql, params);

	std::cout << "[DAO] count result = " << cnt << std::endl;
	return cnt;
	//return sqlSession->executeQueryNumerical(sql, params);
}

std::list<FeeItemDO> FeeItemDAO::selectWithPage(const FeeItemQuery::Wrapper& query)
{
	SqlParams params;

	//std::string sql =
	//	"SELECT config_id,fee_type_cd,fee_name,fee_flag,payment_cd,payment_cycle,start_time,end_time,square_price,additional_amount,deduct_from,pay_online,scale,decimal_place,operate,community_id,create_time,user_id FROM business_pay_fee_config";
    std::string sql =
        "SELECT a.config_id, a.fee_type_cd, a.fee_name, a.fee_flag, a.payment_cd, a.payment_cycle, "
        "a.start_time, a.end_time, a.square_price, a.additional_amount, a.deduct_from, a.pay_online, "
        "a.scale, a.decimal_place, a.operate, a.community_id, a.create_time, a.user_id, "
        "u.name "
        "FROM business_pay_fee_config a "
        "LEFT JOIN u_user u ON a.user_id = u.user_id";

	sql += queryConditionBuilder(query, params);
	sql += " ORDER BY `create_time` DESC ";
	sql += " LIMIT " + std::to_string((query->pageIndex - 1) * query->pageSize) + "," + std::to_string(query->pageSize);

	FeeItemGetMapper mapper;
	std::list<FeeItemDO> result = sqlSession->executeQuery<FeeItemDO>(sql, mapper, params);
	std::cout << "[DAO] selectWithPage found " << result.size() << " records" << std::endl;

	return result;
	//return sqlSession->executeQuery<FeeItemDO>(sql, mapper, params);
}


int FeeItemDAO::insert(const FeeItemDO& iObj)
{
	// 插入 pay_fee_config 表
	std::string sql1 = "INSERT INTO `pay_fee_config` (`config_id`, `fee_type_cd`, `fee_flag`, `payment_cycle`, `fee_name`, `payment_cd`, `prepayment_period`, `start_time`, `end_time`, `units`, `deduct_from`, `pay_online`, `scale`, `decimal_place`, `computing_formula`, `square_price`, `additional_amount`, `community_id`, `b_id`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	int res1 = sqlSession->executeUpdate(sql1, "%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%s%s%s",
		iObj.getConfig_id(), iObj.getFee_type_cd(), iObj.getFee_flag(), iObj.getPayment_cycle(),
		iObj.getFee_name(), iObj.getPayment_cd(), iObj.getPrepayment_period(), iObj.getStart_time(),
		iObj.getEnd_time(), iObj.getUnits(), iObj.getDeduct_from(), iObj.getPay_online(),
		iObj.getScale(), iObj.getDecimal_place(), iObj.getComputing_formula(),
		iObj.getSquare_price(), iObj.getAdditional_amount(), iObj.getCommunity_id(), iObj.getB_id());

	// 插入 business 表（字段结构相同，这里先复制插入语句）
	std::string sql2 = "INSERT INTO `business_pay_fee_config` (`config_id`, `fee_type_cd`, `fee_flag`, `payment_cycle`, `fee_name`, `payment_cd`, `prepayment_period`, `start_time`, `end_time`, `units`, `deduct_from`, `pay_online`, `scale`, `decimal_place`, `computing_formula`, `square_price`, `additional_amount`, `community_id`, `b_id`, `operate`,`user_id`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	int res2 = sqlSession->executeUpdate(sql2, "%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%s%s%s%s%s",
		iObj.getConfig_id(), iObj.getFee_type_cd(), iObj.getFee_flag(), iObj.getPayment_cycle(),
		iObj.getFee_name(), iObj.getPayment_cd(), iObj.getPrepayment_period(), iObj.getStart_time(),
		iObj.getEnd_time(), iObj.getUnits(), iObj.getDeduct_from(), iObj.getPay_online(),
		iObj.getScale(), iObj.getDecimal_place(), iObj.getComputing_formula(),
		iObj.getSquare_price(), iObj.getAdditional_amount(), iObj.getCommunity_id(), iObj.getB_id(), iObj.getOperate(), iObj.getUser_Id());

	// 最终返回插入结果（都成功返回 1，否则 0）
	return (res1 == 1 && res2 == 1) ? 1 : 0;
}

/**
 * 修改 pay_fee_config 表中一条已存在的数据（正式表）
 */
int FeeItemDAO::update(const FeeItemDO& uObj)
{
    std::string sql = "UPDATE `pay_fee_config` SET "
        "`fee_type_cd`=?, `fee_flag`=?, `payment_cycle`=?, `fee_name`=?, `payment_cd`=?, "
        "`prepayment_period`=?, `start_time`=?, `end_time`=?, `units`=?, `deduct_from`=?, "
        "`pay_online`=?, `scale`=?, `decimal_place`=?, `computing_formula`=?, "
        "`square_price`=?, `additional_amount`=? WHERE `config_id`=?";

    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%s%s",
        uObj.getFee_type_cd(), uObj.getFee_flag(), uObj.getPayment_cycle(),
        uObj.getFee_name(), uObj.getPayment_cd(), uObj.getPrepayment_period(),
        uObj.getStart_time(), uObj.getEnd_time(), uObj.getUnits(), uObj.getDeduct_from(),
        uObj.getPay_online(), uObj.getScale(), uObj.getDecimal_place(),
        uObj.getComputing_formula(), uObj.getSquare_price(), uObj.getAdditional_amount(),
        uObj.getConfig_id());
}

/**
 * 修改业务表 business_pay_fee_config：复制旧数据插入DEL，再插入新数据为ADD
 */
int FeeItemDAO::modifyBusiness(const FeeItemDO& newObj)
{
    FeeItemPostMapper mapper;

    // 1. 查询 operate='ADD' 的旧数据
    std::string sqlSelect = "SELECT * FROM business_pay_fee_config WHERE config_id=? AND operate='ADD'ORDER BY create_time DESC LIMIT 1";
    SqlParams params;
    SQLPARAMS_PUSH(params, "s", std::string, newObj.getConfig_id());

    list<FeeItemDO> resultList = sqlSession->executeQuery<FeeItemDO>(sqlSelect, mapper, params);
    if (resultList.empty()) {
        LOG_E("modifyBusiness: no original data found for config_id=%s", newObj.getConfig_id().c_str());
        return -1; // 没有找到旧数据
    }

    FeeItemDO oldObj = resultList.front();
    // 打印旧对象中各字段的值，便于排查 bug
    LOG_D("【旧数据打印】config_id=%s", oldObj.getConfig_id().c_str());
    LOG_D("【旧数据打印】b_id=%s", oldObj.getB_id().c_str());
    LOG_D("【旧数据打印】community_id=%s", oldObj.getCommunity_id().c_str());
    LOG_D("【旧数据打印】fee_type_cd=%s", oldObj.getFee_type_cd().c_str());
    LOG_D("【旧数据打印】square_price=%s", oldObj.getSquare_price().c_str());
    LOG_D("【旧数据打印】additional_amount=%s", oldObj.getAdditional_amount().c_str());
    LOG_D("【旧数据打印】is_default=%s", oldObj.getIs_default().c_str());
    LOG_D("【旧数据打印】start_time=%s", oldObj.getStart_time().c_str());
    LOG_D("【旧数据打印】end_time=%s", oldObj.getEnd_time().c_str());
    LOG_D("【旧数据打印】fee_flag=%s", oldObj.getFee_flag().c_str());
    LOG_D("【旧数据打印】fee_name=%s", oldObj.getFee_name().c_str());
    LOG_D("【旧数据打印】computing_formula=%s", oldObj.getComputing_formula().c_str());
    LOG_D("【旧数据打印】bill_type=%s", oldObj.getBill_type().c_str());
    LOG_D("【旧数据打印】payment_cycle=%s", oldObj.getPayment_cycle().c_str());
    LOG_D("【旧数据打印】payment_cd=%s", oldObj.getPayment_cd().c_str());
    LOG_D("【旧数据打印】computing_formula_text=%s", oldObj.getComputing_formula_text().c_str());
    LOG_D("【旧数据打印】deduct_from=%s", oldObj.getDeduct_from().c_str());
    LOG_D("【旧数据打印】units=%s", oldObj.getUnits().c_str());
    LOG_D("【旧数据打印】decimal_place=%d", oldObj.getDecimal_place());
    LOG_D("【旧数据打印】scale=%s", oldObj.getScale().c_str());
    LOG_D("【旧数据打印】pay_online=%s", oldObj.getPay_online().c_str());
    LOG_D("【旧数据打印】prepayment_period=%s", oldObj.getPrepayment_period().c_str());
    LOG_D("【旧数据打印】user_id=%s", oldObj.getUser_Id().c_str());
    // 2. 构造新的 b_id = 原始 b_id + 2
    uint64_t oldBid = std::stoull(oldObj.getB_id()); // ✅ 不会溢出
    uint64_t newBid = oldBid + 2;
    std::string newBidStr = std::to_string(newBid);



    string operateType = "DEL";
    // 3. 插入 DEL 数据（记录旧数据变更前的状态）
   /* std::string sqlDel =
        "INSERT INTO business_pay_fee_config "
        "(config_id, fee_type_cd, fee_flag, payment_cycle, fee_name, payment_cd, prepayment_period, "
        "start_time, end_time, units, deduct_from, pay_online, scale, decimal_place, computing_formula, "
        "square_price, additional_amount, community_id, b_id, operate) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";*/
         //std::string sqlDel =
         //"INSERT INTO business_pay_fee_config "
         //"(config_id, b_id,community_id,fee_type_cd, square_price,additional_amount,operate,start_time, end_time, fee_flag, fee_name,computing_formula,payment_cycle, payment_cd, prepayment_period, "
         // units, deduct_from, pay_online, scale, decimal_place, computing_formula, "
         //", ,  operate) "
         //"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    std::string sqlDel =
        "INSERT INTO business_pay_fee_config "
        "(config_id, b_id, community_id, fee_type_cd, square_price, additional_amount, operate, "
        "is_default, start_time, end_time, fee_flag, fee_name, computing_formula, bill_type, payment_cycle, "
        "payment_cd, computing_formula_text, deduct_from,units,decimal_place, scale, pay_online, prepayment_period, user_id) "//24
        "VALUES (? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?, ?)";//24
    LOG_D("check-param: config_id=%s", oldObj.getConfig_id().c_str());
    LOG_D("check-param: fee_type_cd=%s", oldObj.getFee_type_cd().c_str());
    LOG_D("check-param: fee_flag=%s", oldObj.getFee_flag().c_str());
    LOG_D("check-param: payment_cycle=%s", oldObj.getPayment_cycle().c_str());
    LOG_D("check-param: fee_name=%s", oldObj.getFee_name().c_str());
    LOG_D("check-param: payment_cd=%s", oldObj.getPayment_cd().c_str());
    LOG_D("check-param: prepayment_period=%s", oldObj.getPrepayment_period().c_str());
    LOG_D("check-param: start_time=%s", oldObj.getStart_time().c_str());
    LOG_D("check-param: end_time=%s", oldObj.getEnd_time().c_str());
    LOG_D("check-param: units=%s", oldObj.getUnits().c_str());
    LOG_D("check-param: deduct_from=%s", oldObj.getDeduct_from().c_str());
    LOG_D("check-param: pay_online=%s", oldObj.getPay_online().c_str());
    LOG_D("check-param: scale=%s", oldObj.getScale().c_str());
    LOG_D("check-param: decimal_place=%d", oldObj.getDecimal_place()); // int 类型
    LOG_D("check-param: computing_formula=%s", oldObj.getComputing_formula().c_str());
    LOG_D("check-param: square_price=%s", oldObj.getSquare_price().c_str());
    LOG_D("check-param: additional_amount=%s", oldObj.getAdditional_amount().c_str());
    LOG_D("check-param: community_id=%s", oldObj.getCommunity_id().c_str());
    LOG_D("check-param: b_id=%s", newBidStr.c_str());
    LOG_D("check-param: operate=%s", operateType.c_str());
    LOG_D("check-param: user_id=%s", oldObj.getUser_Id().c_str());
    int delResult = sqlSession->executeUpdate(sqlDel,
        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%s%s",
        oldObj.getConfig_id(),
        newBidStr,                           // b_id 修改为新值
        oldObj.getCommunity_id(),
        oldObj.getFee_type_cd(),
        oldObj.getSquare_price(),
        oldObj.getAdditional_amount(),
        //oldObj.getCreate_time(),
        operateType,                      // operate 记录变更状态
        oldObj.getIs_default(),
        oldObj.getStart_time(),
        oldObj.getEnd_time(),
        oldObj.getFee_flag(),
        oldObj.getFee_name(),
        oldObj.getComputing_formula(),
        oldObj.getBill_type(),
        oldObj.getPayment_cycle(),
        oldObj.getPayment_cd(),
        oldObj.getComputing_formula_text(),
        oldObj.getDeduct_from(),
        oldObj.getUnits(),
        oldObj.getDecimal_place(),
        oldObj.getScale(),
        oldObj.getPay_online(),
        oldObj.getPrepayment_period(),
        oldObj.getUser_Id()
    );

    if (delResult <= 0) {
        LOG_E("modifyBusiness: failed to insert DEL row for config_id=%s", newObj.getConfig_id().c_str());
        return -2;
    }

    // 4. 插入 ADD 数据（记录新的数据）
    std::string sqlAdd =
        "INSERT INTO business_pay_fee_config "
        "(config_id, fee_type_cd, fee_flag, payment_cycle, fee_name, payment_cd, prepayment_period, "
        "start_time, end_time, units, deduct_from, pay_online, scale, decimal_place, computing_formula, "
        "square_price, additional_amount, community_id, b_id,user_id,operate) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, 'ADD')";

    int addResult = sqlSession->executeUpdate(sqlAdd, "%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%s%s%s%s",
        newObj.getConfig_id(), newObj.getFee_type_cd(), newObj.getFee_flag(), newObj.getPayment_cycle(),
        newObj.getFee_name(), newObj.getPayment_cd(), newObj.getPrepayment_period(),
        newObj.getStart_time(), newObj.getEnd_time(), newObj.getUnits(), newObj.getDeduct_from(),
        newObj.getPay_online(), newObj.getScale(), newObj.getDecimal_place(),
        newObj.getComputing_formula(), newObj.getSquare_price(), newObj.getAdditional_amount(),
        oldObj.getCommunity_id(),newBidStr, newObj.getUser_Id());

    if (addResult <= 0) {
        LOG_E("modifyBusiness: failed to insert ADD row for config_id=%s", newObj.getConfig_id().c_str());
        return -3;
    }

    LOG_D("modifyBusiness: successfully modified config_id=%s with new b_id=%s",
        newObj.getConfig_id().c_str(), newBidStr.c_str());
    return 1;
}





int FeeItemDAO::deleteById(const FeeItemDO& uObj)
{
	std::string sql = "UPDATE `pay_fee_config` SET `status_cd`=1 WHERE `config_id`=?";
	return sqlSession->executeUpdate(sql, "%s",
		uObj.getConfig_id());
}
int FeeItemDAO::deleteBusiness(const FeeItemDO& newObj)
{
    FeeItemPostMapper mapper;

    // 1. 查询 config_id 下 operate='ADD' 的最新数据（你可以根据实际场景加排序限制）
    std::string sqlSelect = "SELECT * FROM business_pay_fee_config WHERE config_id=? AND operate='ADD' ORDER BY b_id DESC LIMIT 1";
    SqlParams params;
    SQLPARAMS_PUSH(params, "s", std::string, newObj.getConfig_id());

    list<FeeItemDO> resultList = sqlSession->executeQuery<FeeItemDO>(sqlSelect, mapper, params);
    if (resultList.empty()) {
        LOG_E("duplicateAddAndDelByConfigId: no ADD data found for config_id=%s", newObj.getConfig_id().c_str());
        return -1;
    }

    FeeItemDO oldObj = resultList.front();

    // 2. 生成新的 b_id = 原始 b_id + 2
    uint64_t oldBid = std::stoull(oldObj.getB_id());
    uint64_t newBid = oldBid + 2;
    std::string newBidStr = std::to_string(newBid);

    std::string operateDel = "DEL";
    std::string operateAdd = "ADD";

    // 3. 插入 DEL 数据（记录旧数据，b_id = 新的）
    std::string sqlInsert =
        "INSERT INTO business_pay_fee_config "
        "(config_id, b_id, community_id, fee_type_cd, square_price, additional_amount, operate, "
        "is_default, start_time, end_time, fee_flag, fee_name, computing_formula, bill_type, payment_cycle, "
        "payment_cd, computing_formula_text, deduct_from, units, decimal_place, scale, pay_online, prepayment_period, user_id) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    int delResult = sqlSession->executeUpdate(sqlInsert,
        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%s%s",
        oldObj.getConfig_id(),
        newBidStr,                           // b_id 为新生成
        oldObj.getCommunity_id(),
        oldObj.getFee_type_cd(),
        oldObj.getSquare_price(),
        oldObj.getAdditional_amount(),
        operateDel,                          // 标记为 DEL
        oldObj.getIs_default(),
        oldObj.getStart_time(),
        oldObj.getEnd_time(),
        oldObj.getFee_flag(),
        oldObj.getFee_name(),
        oldObj.getComputing_formula(),
        oldObj.getBill_type(),
        oldObj.getPayment_cycle(),
        oldObj.getPayment_cd(),
        oldObj.getComputing_formula_text(),
        oldObj.getDeduct_from(),
        oldObj.getUnits(),
        oldObj.getDecimal_place(),
        oldObj.getScale(),
        oldObj.getPay_online(),
        oldObj.getPrepayment_period(),
        oldObj.getUser_Id()
    );

    if (delResult <= 0) {
        LOG_E("duplicateAddAndDelByConfigId: failed to insert DEL row for config_id=%s", newObj.getConfig_id().c_str());
        return -2;
    }

    // 4. 插入 ADD 数据（复制数据但 b_id 更新）
    int addResult = sqlSession->executeUpdate(sqlInsert,
        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%i%s%s%s%s",
        oldObj.getConfig_id(),
        newBidStr,                           // 与 DEL 相同的新 b_id
        oldObj.getCommunity_id(),
        oldObj.getFee_type_cd(),
        oldObj.getSquare_price(),
        oldObj.getAdditional_amount(),
        operateAdd,                          // 标记为 ADD
        oldObj.getIs_default(),
        oldObj.getStart_time(),
        oldObj.getEnd_time(),
        oldObj.getFee_flag(),
        oldObj.getFee_name(),
        oldObj.getComputing_formula(),
        oldObj.getBill_type(),
        oldObj.getPayment_cycle(),
        oldObj.getPayment_cd(),
        oldObj.getComputing_formula_text(),
        oldObj.getDeduct_from(),
        oldObj.getUnits(),
        oldObj.getDecimal_place(),
        oldObj.getScale(),
        oldObj.getPay_online(),
        oldObj.getPrepayment_period(),
        oldObj.getUser_Id()
    );

    if (addResult <= 0) {
        LOG_E("duplicateAddAndDelByConfigId: failed to insert ADD row for config_id=%s", newObj.getConfig_id().c_str());
        return -3;
    }

    LOG_D("duplicateAddAndDelByConfigId: successfully duplicated config_id with new b_id");
    return 1;
}
