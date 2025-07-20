#pragma once
#ifndef _EXPESUM_SERVICE_H_
#define _EXPESUM_SERVICE_H_
#include "domain/dto/expesum/ExpeSumDTO.h"
#include "domain/query/expesum/ExpeSumQuery.h"

/**
 * 费用汇总服务接口（支持楼栋/费用项双维度费率管理）
 */
class BuildingRateService {
public:
    // 楼栋费率分页查询（支持多条件组合筛选）
    BuildingRatePageDTO::Wrapper listByPage(const BuildingRateQuery::Wrapper& query);

    //// 按ID获取楼栋费率详情
    //BuildingRateDTO::Wrapper getBuildingRateById(oatpp::String buildingId);

    //

    //// 批量更新楼栋费率（支持事务管理^[4]^）
    //oatpp::Boolean updateBuildingRates(const List<BuildingRateDTO::Wrapper>& dtos);


    //// 级联删除楼栋费率数据
    //oatpp::Boolean removeBuildingRates(const oatpp::List<oatpp::String>& buildingIds);

};
class FeeItemRateService {
public:
    // 费用项费率分页查询（支持多维度钻取分析^[9]^）
    FeeItemRatePageDTO::Wrapper listByPage(const FeeItemRateQuery::Wrapper& query);

    //// 按ID获取费用项费率详情
    //FeeItemRateDTO::Wrapper getFeeItemRateById(oatpp::String itemId);

    //// 批量更新费用项费率（含分层统计维度验证^[4]^）
    //oatpp::Boolean updateFeeItems(const List<FeeItemRateDTO::Wrapper>& dtos);

    //// 复合条件删除费用项费率
    //oatpp::Boolean removeFeeItems(const FeeItemRateQuery::Wrapper& query);
};





/*          费用汇总-2        */

class ExpeSumService
{
public:
    // 查询所有数据
    ExpeSumDTO::Wrapper listAll(const ExpeSumQuery::Wrapper& query);
};
#endif 