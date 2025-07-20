#include "stdafx.h"
#include "RepairReportFeeService.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include <domain/do/repair_report/RepairReportFeeDO.h>
#include <dao/report_management/repair_report/RepairReportFeeDAO.h>

RepairReportFeePageDTO::Wrapper RepairReportFeeService::listAll(const RepairReportFeeQuery::Wrapper& query)
{
    // 构建返回对象
    auto pages = RepairReportFeePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    RepairReportFeeDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    list<RepairReportFeeDO> result = dao.selectWithPage(query);
    // 将DO转换成DTO
    for (RepairReportFeeDO sub : result)
    {
        auto dto = RepairReportFeeDTO::createShared();
        dto->repairId = sub.getRepairId();
        dto->name = sub.getRepairName();
        dto->telephone = sub.getTel();
        dto->date = sub.getCreateTime();
        dto->location = sub.getRepairLocation();
        dto->expectfee = sub.getRepairFee();
        dto->actualfee = (sub.getMaintenanceType() == "1001") ? sub.getRepairFee() : "0";
        pages->addData(dto);
    }
    return pages;
}

