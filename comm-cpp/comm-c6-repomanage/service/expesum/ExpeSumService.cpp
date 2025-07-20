#include "stdafx.h"
#include "ExpeSumService.h"
#include "../../dao/expesum/ExpeSumDAO.h"
#include "id/UuidFacade.h"
#include "domain/dto/expesum/ExpeSumDTO.h"
#include "domain/do/expesum/ExpeSumDO.h"

//------------------------ 楼栋费率服务实现 ------------------------
BuildingRatePageDTO::Wrapper BuildingRateService::listByPage(
    const BuildingRateQuery::Wrapper& query)
{
    // 构建返回对象
    auto pages = BuildingRatePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    BuildingRateDAO dao;


    pages->calcPages();
    list<BuildingRateDO> result = dao.selectByPage(query);
    // 将DO转换成DTO
    for (BuildingRateDO sub : result)
    {
        auto dto = BuildingRateDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, curReceivableFee, CurReceivableFee, curReceivedFee, CurReceivedFee, buildRate, BuildRate, ownerNumber, OwnerNumber, endDate, EndDate);
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingName, BuildingName, roomNum, RoomNum, communityId, CommunityId, feeTypes, FeeTypes, ownerName, OwnerName, startDate, StartDate);

        // ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

        pages->addData(dto);
    }
    return pages;
}


//------------------------ 费用项费率服务实现 ------------------------
FeeItemRatePageDTO::Wrapper FeeItemRateService::listByPage(
    const FeeItemRateQuery::Wrapper& query)
{
    // 构建返回对象
    auto pages = FeeItemRatePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    FeeItemRateDAO dao;


    pages->calcPages();
    list<FeeItemRateDO> result = dao.selectByPage(query);
    // 将DO转换成DTO
    for (FeeItemRateDO sub : result)
    {
        auto dto = FeeItemRateDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, curReceivableFee, CurReceivableFee, curReceivedFee, CurReceivedFee, itemRate, ItemRate, ownerNumber, OwnerNumber, endDate, EndDate);
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, buildingName, BuildingName, roomNum, RoomNum, communityId, CommunityId, feeTypes, FeeTypes, ownerName, OwnerName, startDate, StartDate);

        // ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, qunuan, Qunuan, weixiu, Weixiu, fuwu, Fuwu, qita, Qita, shuifei, Shuifei, dianfei, Dianfei, zujin, Zujin, gongtan, Gongtan);

        pages->addData(dto);
    }
    return pages;
}



/*          费用汇总-2          */
ExpeSumDTO::Wrapper ExpeSumService::listAll(const ExpeSumQuery::Wrapper& query)
{
    // 构建返回对象
    auto dto = ExpeSumDTO::createShared();

    // 创建 DAO 实例
    TotalRoomCountDAO totalRoomCountDAO;
    FeeRoomCountDAO feeRoomCountDAO;
    OweRoomCountDAO oweRoomCountDAO;
    HisOweFeeDAO hisOweFeeDAO;
    CurOweFeeDAO curOweFeeDAO;
    CurReceivableFeeDAO curReceivableFeeDAO;
    CurReceivedFeeDAO curReceivedFeeDAO;
    HisReceivedFeeDAO hisReceivedFeeDAO;
    PreReceivedFeeDAO preReceivedFeeDAO;

    // 调用 DAO 方法并填充 DTO
    dto->totalRoomCount = totalRoomCountDAO.selectTotalRoomCount(query);
    dto->feeRoomCount = feeRoomCountDAO.selectFeeRoomCount(query);
    dto->oweRoomCount = oweRoomCountDAO.selectOweRoomCount(query);
    dto->hisOweFee = hisOweFeeDAO.selectHisOweFee(query);
    dto->curOweFee = curOweFeeDAO.selectCurOweFee(query);
    dto->curReceivableFee = curReceivableFeeDAO.selectCurReceivableFee(query);
    dto->curReceivedFee = curReceivedFeeDAO.selectCurReceivedFee(query);
    dto->hisReceivedFee = hisReceivedFeeDAO.selectHisReceivedFee(query);
    dto->preReceivedFee = preReceivedFeeDAO.selectPreReceivedFee(query);

    return dto;
}