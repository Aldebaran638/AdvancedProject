#pragma once
#pragma once
#ifndef _EXPESUMDAO_H_
#define _EXPESUMDAO_H_
#include "BaseDAO.h"
#include "domain/query/expesum/ExpeSumQuery.h"
#include "domain/do/expesum/ExpeSumDO.h"



/*-------------楼栋收费率-------------*/
class BuildingRateDAO : public BaseDAO {
public:
    // 分页动态查询（支持多条件组合）
    std::list<BuildingRateDO> selectByPage(const BuildingRateQuery::Wrapper& query);



    // 动态构建WHERE条件（复用代码）
    std::string buildCondition(const BuildingRateQuery::Wrapper& query, SqlParams& params);
};




class FeeItemRateDAO : public BaseDAO {
public:
    std::list<FeeItemRateDO> selectByPage(const FeeItemRateQuery::Wrapper& query);
    // 动态构建WHERE条件（复用代码）
    std::string buildCondition(const FeeItemRateQuery::Wrapper& query, SqlParams& params);
};



/*           费用汇总-2         */
/**
 * 费用汇总表数据库
 */

 // 总户数
class TotalRoomCountDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    int selectTotalRoomCount(const ExpeSumQuery::Wrapper& query);
};

// 收费户数
class FeeRoomCountDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    int selectFeeRoomCount(const ExpeSumQuery::Wrapper& query);
};

//欠费户数
class OweRoomCountDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    int selectOweRoomCount(const ExpeSumQuery::Wrapper& query);
};

//历史欠费金额统计
class HisOweFeeDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectHisOweFee(const ExpeSumQuery::Wrapper& query);
};

//当期欠费金额统计
class CurOweFeeDAO : public BaseDAO
{
private:

    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectCurOweFee(const ExpeSumQuery::Wrapper& query);
};

// 当期应收金额统计
class CurReceivableFeeDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectCurReceivableFee(const ExpeSumQuery::Wrapper& query);
};

// 当期实收金额统计
class CurReceivedFeeDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectCurReceivedFee(const ExpeSumQuery::Wrapper& query);
};

// 历史收款金额统计
class HisReceivedFeeDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectHisReceivedFee(const ExpeSumQuery::Wrapper& query);
};

//预收款金额统计
class PreReceivedFeeDAO : public BaseDAO
{
private:
    inline std::string queryConditionBuilder(const ExpeSumQuery::Wrapper& query, SqlParams& params);
public:
    double selectPreReceivedFee(const ExpeSumQuery::Wrapper& query);
};
#endif