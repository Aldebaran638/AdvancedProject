#include "stdafx.h"
#include "InspectionPointStatisticService.h"
#include "dao/report_management/inspection_report/InspectionPointStatisticDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include<list>



InspectionPointStatisticPageDTO::Wrapper InspectionPointStatisticService::listAll(const InspectionPointStatisticQuery::Wrapper& query)
{
    auto pages = InspectionPointStatisticPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    InspectionPointStatisticDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0) return pages;

    pages->total = count;
    pages->calcPages();
    list<InspectionPointStatisticDO> result = dao.selectWithPage(query);
    //调试日志
    //for(const auto &it:result)
    //{
    //   
    //    cout << "sql查询后do领域模型的结果是" << endl;
    //    cout << it.getInspectionPointName()<<" "<< it.getPointObjName()<<" "<< it.getStaffName()<<" "<< it.getInspectEd()<<" "<< it.getUnInspection()<<' ' << it.getState() << endl;//乱码了
    //}
    // 使用map优化分组逻辑
    std::map<std::string, InspectionPointStatisticDTO::Wrapper> pointMap;
    std::map<std::pair<std::string, std::string>, bool> staffSet; // 复合键: (pointName, staffName)

    for (const InspectionPointStatisticDO& item : result)
    {
        const std::string& pointName = item.getInspectionPointName();
        const std::string& staffName = item.getStaffName();

        // 初始化巡检点DTO
        if (pointMap.find(pointName) == pointMap.end())
        {
            auto dto = InspectionPointStatisticDTO::createShared();
            dto->inspectionPointName = pointName;
            dto->staffs = oatpp::List<MaintenanceMasterDTO::Wrapper>::createShared(); 
            pointMap[pointName] = dto;
        }

        // 初始化职工DTO（避免重复）
        auto staffKey = std::make_pair(pointName, staffName);
        if (staffSet.find(staffKey) == staffSet.end())
        {
            auto staffDto = MaintenanceMasterDTO::createShared();
            staffDto->staffName = staffName;
            staffDto->inspectEd = v_int64(0);  // 初始化值
            staffDto->unInspection = v_int64(0); // 初始化值

            pointMap[pointName]->staffs->push_back(staffDto);
            staffSet.insert({ staffKey, true });
        }
    }

    // 填充统计数据
    for (const InspectionPointStatisticDO& item : result)
    {
        const std::string& pointName = item.getInspectionPointName();
        for (auto& staff : *pointMap[pointName]->staffs)
        {
            if (staff->staffName == item.getStaffName())
            {
                // 累加统计值
                staff->inspectEd = *staff->inspectEd + item.getInspectEd();
                staff->unInspection = *staff->unInspection + item.getUnInspection();
                break;
            }
        }
    }

    // 组装分页数据
    for (auto& [_, dto] : pointMap) {
        // 不再重置staffs列表，保留已经填充的数据
        pages->addData(dto);
    }
    return pages;
}
oatpp::List<InspectionPointStatisticDTO::Wrapper>
InspectionPointStatisticService::listAllExport(const InspectionPointStatisticQuery::Wrapper& query)
{
    // 复用分页查询逻辑获取原始数据
    auto pages = listAll(query);
    auto exportList = oatpp::List<InspectionPointStatisticDTO::Wrapper>::createShared();

    // 直接返回已分组的数据结构
    for (const auto& item : *pages->rows) {
        exportList->push_back(item);
    }
    return exportList;
}
