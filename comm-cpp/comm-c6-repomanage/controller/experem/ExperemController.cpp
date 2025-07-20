/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "ExperemController.h"
#include "../ApiDeclarativeServicesHelper.h"

#include "../../service/experem/ExpeRemService.h"

#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"

#include "oatpp/web/protocol/http/outgoing/Response.hpp"
#include "oatpp/web/server/api/ApiController.hpp"

std::chrono::system_clock::time_point stringToTimePoint(const std::string& dateStr);
long long daysDifference(const std::string& startDate);

ExpeRemPageJsonVO::Wrapper ExperemController::execQueryAll(const ExpeRemQuery::Wrapper& query)
{
    ExpeRemService service;
    auto result = service.listAll(query);
    auto jvo = ExpeRemPageJsonVO::createShared();
    jvo->success(result);
    return jvo;

    //return {};
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExperemController::execExportAll(const ExpeRemQuery::Wrapper& query)
{
    // 定义一个Service
    ExpeRemService service;
    // 查询数据
    auto result = service.listAll(query);

    // 将数据写入到Excel中
    auto buff = ExcelComponent().writeVectorToBuff("experem",
        [result](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("experem.field.seq") ,
                ZH_WORDS_GETTER("experem.field.assets") ,
                ZH_WORDS_GETTER("experem.field.item") ,
                ZH_WORDS_GETTER("experem.field.createTime") ,
                ZH_WORDS_GETTER("experem.field.daysToStart")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->feeId);
                ex->setCellValue(row, col++, item->payerObjType);
                ex->setCellValue(row, col++, item->feeName);
                ex->setCellValue(row, col++, item->startTime);

                // 计算距离开始时间的天数
                try {
                    // 假设item->startTime是字符串类型，格式为"YYYY-MM-DD"
                    std::string startTimeStr = *item->startTime;
                    long long days = daysDifference(startTimeStr);
                    ex->setCellValue(row, col, std::to_string(days));
                }
                catch (const std::exception& e) {
                    // 处理异常，比如日期格式错误
                    ex->setCellValue(row, col, "N/A");
                }

                ex->setRowProperties(row++);
            }
        });

    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    std::string filename = "pre-experem-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // 返回成功结果
    return response;
}









/*  工具函数   */

// 将日期字符串转换为时间点
std::chrono::system_clock::time_point stringToTimePoint(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);

    // 解析日期字符串，格式为 "YYYY-MM-DD"
    ss >> std::get_time(&tm, "%Y-%m-%d");

    if (ss.fail()) {
        throw std::invalid_argument("Invalid date format. Use YYYY-MM-DD.");
    }

    // 转换为time_t
    std::time_t time = std::mktime(&tm);

    // 转换为system_clock::time_point
    return std::chrono::system_clock::from_time_t(time);
}

// 计算从开始日期到现在的天数差
long long daysDifference(const std::string& startDate) {
    try {
        // 转换开始日期为时间点
        auto startTime = stringToTimePoint(startDate);

        // 获取当前时间
        auto now = std::chrono::system_clock::now();

        // 计算时间差（以天为单位）
        auto duration = std::chrono::duration_cast<std::chrono::hours>(now - startTime);
        return duration.count() / 24;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1; // 返回-1表示出错
    }
}



//////////////////////
overExpeRemPageJsonVO::Wrapper overExperemController::execQuery(const overExpeRemQuery::Wrapper& query)
{
    overExpeRemService service;
    auto result = service.listAll(query);
    auto jvo = overExpeRemPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::protocol::http::outgoing::Response> overExperemController::execExportExperem(const overExpeRemQuery::Wrapper& query)
{
    // 定义一个Service
    overExpeRemService service;
    // 查询数据
    auto result = service.listAll(query);
    // 将数据写入到Excel中
    auto buff = ExcelComponent().writeVectorToBuff("sample",
        [result](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("experem.field.Feeid") ,
                ZH_WORDS_GETTER("experem.field.BuildingNo") ,
                ZH_WORDS_GETTER("experem.field.Expenses") ,
                ZH_WORDS_GETTER("experem.field.EndTime") ,
                ZH_WORDS_GETTER("experem.field.RemainingTime") ,
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->Feeid);
                ex->setCellValue(row, col++, item->BuildingNo);
                ex->setCellValue(row, col++, item->Expenses);
                ex->setCellValue(row, col++, item->EndTime);
                ex->setCellValue(row, col, item->RemainingTime);
                ex->setRowProperties(row++);
            }
        });
    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    std::string filename = query->FileName + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // 影响成功结果
    return response;
}








