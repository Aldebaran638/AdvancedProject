#pragma once

#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/repair_report/RepairReportFeeDO.h"
#include "../../../domain/query/repair_report/RepairReportFeeQuery.h"
/**
 * RepairReportFee表数据库操作实现
 */
class RepairReportFeeDAO : public BaseDAO
{
private:
    //************************************
    // Method:      queryConditionBuilder
    // FullName:    RepairReportFeeDAO::queryConditionBuilder
    // Access:      private 
    // Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
    // Parameter:   const RepairReportFeeQuery::Wrapper& query 查询数据对象
    // Parameter:   SqlParams& params 存放查询数据的参数对象
    // Description: 查询条件构建器，根据RepairReportFeeQuery对象动态构建查询条件相关参数
    //************************************
    inline std::string queryConditionBuilder(const RepairReportFeeQuery::Wrapper& query, SqlParams& params);

public:
    // 统计
    uint64_t count(const RepairReportFeeQuery::Wrapper& query);

    // 分页查询
    std::list<RepairReportFeeDO> selectWithPage(const RepairReportFeeQuery::Wrapper& query);

    // 根据ID查询
    PtrRepairReportFeeDO selectById(std::string repairId);
};

#endif // !_REPAIR_REPORT_FEE_DAO_

