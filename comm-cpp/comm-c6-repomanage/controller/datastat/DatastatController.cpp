/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2025/5/20

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

#include <stdafx.h>
#include "DatastatController.h"
#include <ExcelComponent.h>
#include <SimpleDateTimeFormat.h>
#include <service/datastat/DataStatService.h>
#include <controller/ApiDeclarativeServicesHelper.h>

#include "../../service/datastat/DataStatService.h"
#include "../../domain/vo/datastat/DataStatVO.h"
#include "../../domain/dto/datastat/DataStatDTO.h"
#include "../../domain/query/datastat/DataStatQuery.h"

#include <regex>
#include <chrono>
#include <sstream>

bool validateDateFormat(const std::string& date);
bool validateCommunityId(const std::string& communityId);
bool validateCommunityName(const std::string& communityName);
std::string cleanExcelSheetTitle(const std::string& title);

ExpenseStatPageJsonVO::Wrapper DatastatController::execQueryExpenseStat(const ExpenseStatQuery::Wrapper& query) {
    auto jvo = ExpenseStatPageJsonVO::createShared();
    // 校验参数
    std::string startDate = query->startDate.getValue("");
    std::string endDate = query->endDate.getValue("");
    std::string communityId = query->communityId.getValue("");
    std::string communityName = query->communityName.getValue("");

    // 日期参数
    if (!validateDateFormat(startDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The start date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    if (!validateDateFormat(endDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The end date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    // 社区ID校验
    if (!validateCommunityId(communityId)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community ID format is incorrect.Only letters, numbers, underscores, and hyphens are allowed.The length cannot exceed 50 characters.";
        return jvo;
    }

    // 社区名称校验
    if (!validateCommunityName(communityName)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community name format is incorrect. The length cannot exceed 100 characters. Special characters are not allowed.";
        return jvo;
    }

    // 实际查询
    DataStatService service;
    auto result = service.getExpenseData(query);

    // 返回结果
    jvo->success(result);
    return jvo;
}

WorkOrderStatPageJsonVO::Wrapper DatastatController::execQueryWorkOrderStat(const WorkOrderStatQuery::Wrapper& query) {
    auto jvo = WorkOrderStatPageJsonVO::createShared();
    // 校验参数
    std::string startDate = query->startDate.getValue("");
    std::string endDate = query->endDate.getValue("");
    std::string communityId = query->communityId.getValue("");
    std::string communityName = query->communityName.getValue("");

    // 日期参数
    if (!validateDateFormat(startDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The start date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    if (!validateDateFormat(endDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The end date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    // 社区ID校验
    if (!validateCommunityId(communityId)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community ID format is incorrect.Only letters, numbers, underscores, and hyphens are allowed.The length cannot exceed 50 characters.";
        return jvo;
    }

    // 社区名称校验
    if (!validateCommunityName(communityName)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community name format is incorrect. The length cannot exceed 100 characters. Special characters are not allowed.";
        return jvo;
    }

    // 实际查询
    DataStatService service;
    auto result = service.getWorkOrderData(query);

    // 返回结果
    jvo->success(result);
    return jvo;
}

AccessStatPageJsonVO::Wrapper DatastatController::execQueryAccessStat(const AccessStatQuery::Wrapper& query) {
    auto jvo = AccessStatPageJsonVO::createShared();
    // 校验参数
    std::string startDate = query->startDate.getValue("");
    std::string endDate = query->endDate.getValue("");
    std::string communityId = query->communityId.getValue("");
    std::string communityName = query->communityName.getValue("");

    // 日期参数
    if (!validateDateFormat(startDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The start date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    if (!validateDateFormat(endDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The end date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    // 社区ID校验
    if (!validateCommunityId(communityId)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community ID format is incorrect.Only letters, numbers, underscores, and hyphens are allowed.The length cannot exceed 50 characters.";
        return jvo;
    }

    // 社区名称校验
    if (!validateCommunityName(communityName)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community name format is incorrect. The length cannot exceed 100 characters. Special characters are not allowed.";
        return jvo;
    }

    // 实际查询
    DataStatService service;
    auto result = service.getAccessData(query);

    // 返回结果
    jvo->success(result);
    return jvo;
}

OtherStatPageJsonVO::Wrapper DatastatController::execQueryOtherStat(const OtherStatQuery::Wrapper& query) {
    auto jvo = OtherStatPageJsonVO::createShared();
    // 校验参数
    std::string startDate = query->startDate.getValue("");
    std::string endDate = query->endDate.getValue("");
    std::string communityId = query->communityId.getValue("");
    std::string communityName = query->communityName.getValue("");

    // 日期参数
    if (!validateDateFormat(startDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The start date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    if (!validateDateFormat(endDate)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The end date format is incorrect, please use yyyy-MM-dd format.";
        return jvo;
    }

    // 社区ID校验
    if (!validateCommunityId(communityId)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community ID format is incorrect.Only letters, numbers, underscores, and hyphens are allowed.The length cannot exceed 50 characters.";
        return jvo;
    }

    // 社区名称校验
    if (!validateCommunityName(communityName)) {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        jvo->message = "The community name format is incorrect. The length cannot exceed 100 characters. Special characters are not allowed.";
        return jvo;
    }

    // 实际查询
    DataStatService service;
    auto result = service.getOtherData(query);

    // 返回结果
    jvo->success(result);
    return jvo;
}
//
DataStatMethodVO::Wrapper DatastatController::executeQueryMethod(const oatpp::Object<DataStatALLSearchQuery>& query) {
    DataStatService serve;
    auto jvo = DataStatMethodVO::createShared();
    auto res = serve.listAllMethod(query);
    jvo->success(res);
    return jvo;
}

DataStatQianfeiPageVO::Wrapper DatastatController::executeQueryQianfei(const oatpp::Object<DataStatALLSearchQuery>& query) {
    // 创建Service对象
    DataStatService service;

    // 创建返回的VO对象
    auto jvo = DataStatQianfeiPageVO::createShared();

    // 调用Service层获取分页欠费统计数据
    auto pageDto = service.listQianfeiWithPage(query);

    // 设置成功响应
    jvo->success(pageDto);

    return jvo;
}
DataStatShishouDetailPageVO::Wrapper DatastatController::executeQueryShishouDetail(const DataStatDetailSearchQuery::Wrapper& query) {
    // 创建Service对象
    DataStatService service;

    // 创建返回的VO对象
    auto jvo = DataStatShishouDetailPageVO::createShared();

    // 调用Service层获取分页实收明细数据
    auto pageDto = service.listShishouDetailWithPage(query);

    // 设置成功响应
    jvo->success(pageDto);

    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::executeExportShishouDetail(const DataStatDetailSearchQuery::Wrapper& query)
{
    // 定义一个Service
    DataStatService service;
    // 查询数据
    auto result = service.listShishouDetailWithPage(query);
    // 将数据写入到Excel中
    auto buff = ExcelComponent().writeVectorToBuff("shishou-detail",
        [result](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.house"),
                ZH_WORDS_GETTER("datastat.field.host"),
                ZH_WORDS_GETTER("datastat.field.cost.wuye"),
                ZH_WORDS_GETTER("datastat.field.cost.yajin"),
                ZH_WORDS_GETTER("datastat.field.cost.tingche"),
                ZH_WORDS_GETTER("datastat.field.cost.meiqi"),
                ZH_WORDS_GETTER("datastat.field.cost.qunuan"),
                ZH_WORDS_GETTER("datastat.field.cost.weixiu"),
                ZH_WORDS_GETTER("datastat.field.cost.qita"),
                ZH_WORDS_GETTER("datastat.field.cost.fuwu"),
                ZH_WORDS_GETTER("datastat.field.cost.shuifei"),
                ZH_WORDS_GETTER("datastat.field.cost.dianfei"),
                ZH_WORDS_GETTER("datastat.field.cost.zujin"),
                ZH_WORDS_GETTER("datastat.field.cost.gongtan"),
                ZH_WORDS_GETTER("datastat.field.cost.final")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, item->host);
                ex->setCellValue(row, col++, std::to_string(item->wuye));
                ex->setCellValue(row, col++, std::to_string(item->yajin));
                ex->setCellValue(row, col++, std::to_string(item->tingche));
                ex->setCellValue(row, col++, std::to_string(item->meiqi));
                ex->setCellValue(row, col++, std::to_string(item->qunuan));
                ex->setCellValue(row, col++, std::to_string(item->weixiu));
                ex->setCellValue(row, col++, std::to_string(item->qita));
                ex->setCellValue(row, col++, std::to_string(item->fuwu));
                ex->setCellValue(row, col++, std::to_string(item->shuifei));
                ex->setCellValue(row, col++, std::to_string(item->dianfei));
                ex->setCellValue(row, col++, std::to_string(item->zujin));
                ex->setCellValue(row, col++, std::to_string(item->gongtan));
                ex->setCellValue(row, col, std::to_string(item->final));
                ex->setRowProperties(row++);
            }
        });
    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);
    // 设置响应头信息
    std::string filename = "rp-shishou-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    // 返回成功结果
    return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::executeExportShishou(const DataStatALLSearchQuery::Wrapper& query)
{
    // 定义一个Service
    DataStatService service;
    // 查询数据
    auto result = service.listShishouWithPage(query);
    // 将数据写入到Excel中
    auto buff = ExcelComponent().writeVectorToBuff("shishou",
        [result](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.house"),
                ZH_WORDS_GETTER("datastat.field.hostnum"),
                ZH_WORDS_GETTER("datastat.field.costnum"),
                ZH_WORDS_GETTER("datastat.field.cost.wuye"),
                ZH_WORDS_GETTER("datastat.field.cost.yajin"),
                ZH_WORDS_GETTER("datastat.field.cost.tingche"),
                ZH_WORDS_GETTER("datastat.field.cost.meiqi"),
                ZH_WORDS_GETTER("datastat.field.cost.qunuan"),
                ZH_WORDS_GETTER("datastat.field.cost.weixiu"),
                ZH_WORDS_GETTER("datastat.field.cost.qita"),
                ZH_WORDS_GETTER("datastat.field.cost.fuwu"),
                ZH_WORDS_GETTER("datastat.field.cost.shuifei"),
                ZH_WORDS_GETTER("datastat.field.cost.dianfei"),
                ZH_WORDS_GETTER("datastat.field.cost.zujin"),
                ZH_WORDS_GETTER("datastat.field.cost.gongtan"),
                ZH_WORDS_GETTER("datastat.field.cost.final"),
                ZH_WORDS_GETTER("datastat.field.cost.allfinal")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, std::to_string(item->hostnum));
                ex->setCellValue(row, col++, std::to_string(item->costnum));
                ex->setCellValue(row, col++, std::to_string(item->wuye));
                ex->setCellValue(row, col++, std::to_string(item->yajin));
                ex->setCellValue(row, col++, std::to_string(item->tingche));
                ex->setCellValue(row, col++, std::to_string(item->meiqi));
                ex->setCellValue(row, col++, std::to_string(item->qunuan));
                ex->setCellValue(row, col++, std::to_string(item->weixiu));
                ex->setCellValue(row, col++, std::to_string(item->qita));
                ex->setCellValue(row, col++, std::to_string(item->fuwu));
                ex->setCellValue(row, col++, std::to_string(item->shuifei));
                ex->setCellValue(row, col++, std::to_string(item->dianfei));
                ex->setCellValue(row, col++, std::to_string(item->zujin));
                ex->setCellValue(row, col++, std::to_string(item->gongtan));
                ex->setCellValue(row, col++, std::to_string(item->final));
                ex->setCellValue(row, col, std::to_string(item->allfinal));
                ex->setRowProperties(row++);
            }
        });
    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);
    // 设置响应头信息
    std::string filename = "rp-shishou-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    // 返回成功结果
    return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::executeExportMethod(const DataStatALLSearchQuery::Wrapper& query)
{
    // 定义一个Service
    DataStatService service;
    // 查询数据
    auto result = service.listAllMethod(query);
    // 将数据写入到Excel中
    auto buff = ExcelComponent().writeVectorToBuff("method",
        [result](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.method.cash"),
                ZH_WORDS_GETTER("datastat.field.method.wechat"),
                ZH_WORDS_GETTER("datastat.field.method.zhifubao"),
                ZH_WORDS_GETTER("datastat.field.method.transfer"),
                ZH_WORDS_GETTER("datastat.field.method.refund"),
                ZH_WORDS_GETTER("datastat.field.method.pos")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            col = 1;
            ex->setCellValue(row, col++, std::to_string(result->cash));
            ex->setCellValue(row, col++, std::to_string(result->wechat));
            ex->setCellValue(row, col++, std::to_string(result->zhifubao));
            ex->setCellValue(row, col++, std::to_string(result->Transfer));
            ex->setCellValue(row, col++, std::to_string(result->refund));
            ex->setCellValue(row, col, std::to_string(result->POS));
            ex->setRowProperties(row++);
        });
    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);
    // 设置响应头信息
    std::string filename = "rp-method-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    // 返回成功结果
    return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::executeExportQianfei(const DataStatALLSearchQuery::Wrapper& query)
{
    // 定义一个Service
    DataStatService service;
    // 查询数据
    auto result = service.listQianfeiWithPage(query);
    // 将数据写入到Excel中
    auto buff = ExcelComponent().writeVectorToBuff("qianfei",
        [result](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.house"),
                ZH_WORDS_GETTER("datastat.field.cost.wuye"),
                ZH_WORDS_GETTER("datastat.field.cost.yajin"),
                ZH_WORDS_GETTER("datastat.field.cost.tingche"),
                ZH_WORDS_GETTER("datastat.field.cost.meiqi"),
                ZH_WORDS_GETTER("datastat.field.cost.qunuan"),
                ZH_WORDS_GETTER("datastat.field.cost.weixiu"),
                ZH_WORDS_GETTER("datastat.field.cost.qita"),
                ZH_WORDS_GETTER("datastat.field.cost.fuwu"),
                ZH_WORDS_GETTER("datastat.field.cost.shuifei"),
                ZH_WORDS_GETTER("datastat.field.cost.dianfei"),
                ZH_WORDS_GETTER("datastat.field.cost.zujin"),
                ZH_WORDS_GETTER("datastat.field.cost.gongtan"),
                ZH_WORDS_GETTER("datastat.field.cost.qianfei"),
                ZH_WORDS_GETTER("datastat.field.cost.allqianfei")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, std::to_string(item->wuye));
                ex->setCellValue(row, col++, std::to_string(item->yajin));
                ex->setCellValue(row, col++, std::to_string(item->tingche));
                ex->setCellValue(row, col++, std::to_string(item->meiqi));
                ex->setCellValue(row, col++, std::to_string(item->qunuan));
                ex->setCellValue(row, col++, std::to_string(item->weixiu));
                ex->setCellValue(row, col++, std::to_string(item->qita));
                ex->setCellValue(row, col++, std::to_string(item->fuwu));
                ex->setCellValue(row, col++, std::to_string(item->shuifei));
                ex->setCellValue(row, col++, std::to_string(item->dianfei));
                ex->setCellValue(row, col++, std::to_string(item->zujin));
                ex->setCellValue(row, col++, std::to_string(item->gongtan));
                ex->setCellValue(row, col++, std::to_string(item->qianfei));
                ex->setCellValue(row, col, std::to_string(item->allqianfei));
                ex->setRowProperties(row++);
            }
        });
    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);
    // 设置响应头信息
    std::string filename = "rp-qianfei-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
    // 返回成功结果
    return response;
}

DataStatShishouPageVO::Wrapper DatastatController::executeQueryShishou(const oatpp::Object<DataStatALLSearchQuery>& query)
{
    // 创建Service对象
    DataStatService service;

    // 创建返回的VO对象
    auto jvo = DataStatShishouPageVO::createShared();

    // 调用Service层获取分页数据
    auto pageDto = service.listShishouWithPage(query);

    // 设置成功响应
    jvo->success(pageDto);

    return jvo;
}


/*              数据统计-3            */
DataStatFeeDetailPageJsonVO::Wrapper DatastatController::executeQueryFeeDetaile(const oatpp::Object<DatastatFeeDetailQuery>& query)
{
    // 定义一个Service
    DatastatFeeDetailService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = DataStatFeeDetailPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::execExportFeeDetaile(const DatastatFeeDetailQuery::Wrapper& query)
{
    // 定义一个Service
    DatastatFeeDetailService service;
    // 查询数据
    auto result = service.listAll(query);

    // 将数据写入到Excel中
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("datastat.field.module1.module_name"),
        [result](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.module1.room_name") ,
                ZH_WORDS_GETTER("datastat.field.module1.name") ,
                ZH_WORDS_GETTER("datastat.field.module1.qianfei") ,
                ZH_WORDS_GETTER("datastat.field.module1.wuye") ,
                ZH_WORDS_GETTER("datastat.field.module1.yajin") ,
                ZH_WORDS_GETTER("datastat.field.module1.tingche") ,
                ZH_WORDS_GETTER("datastat.field.module1.meiqi") ,
                ZH_WORDS_GETTER("datastat.field.module1.qunuan") ,
                ZH_WORDS_GETTER("datastat.field.module1.weixiu") ,
                ZH_WORDS_GETTER("datastat.field.module1.fuwu") ,
                ZH_WORDS_GETTER("datastat.field.module1.qita") ,
                ZH_WORDS_GETTER("datastat.field.module1.shuifei") ,
                ZH_WORDS_GETTER("datastat.field.module1.dianfei") ,
                ZH_WORDS_GETTER("datastat.field.module1.zujin") ,
                ZH_WORDS_GETTER("datastat.field.module1.gongtan")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, item->ow);
                ex->setCellValue(row, col++, std::to_string(item->qianfei));
                ex->setCellValue(row, col++, std::to_string(item->wuye));
                ex->setCellValue(row, col++, std::to_string(item->yajin));
                ex->setCellValue(row, col++, std::to_string(item->tingche));
                ex->setCellValue(row, col++, std::to_string(item->meiqi));
                ex->setCellValue(row, col++, std::to_string(item->qunuan));
                ex->setCellValue(row, col++, std::to_string(item->weixiu));
                ex->setCellValue(row, col++, std::to_string(item->fuwu));
                ex->setCellValue(row, col++, std::to_string(item->qita));
                ex->setCellValue(row, col++, std::to_string(item->shuifei));
                ex->setCellValue(row, col++, std::to_string(item->dianfei));
                ex->setCellValue(row, col++, std::to_string(item->zujin));
                ex->setCellValue(row, col++, std::to_string(item->gongtan));

                ex->setRowProperties(row++);
            }
        });

    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    std::string filename = "rp-datastat-fee-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // 影响成功结果
    return response;
}



DatastatChargeDetailPageJsonVO::Wrapper DatastatController::executeQueryChargeDetaile(const oatpp::Object<DatastatChargeDetailQuery>& query)
{
    // 定义一个Service
    DatastatChargeDetailService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = DatastatChargeDetailPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::execExportChargeDetaile(const DatastatChargeDetailQuery::Wrapper& query)
{
    // 定义一个Service
    DatastatChargeDetailService service;
    // 查询数据
    auto result = service.listAll(query);

    // 将数据写入到Excel中(表中有个字段来源于query而非dto,所以lambda表达式要捕获query)
    // 因为这个表格要用到query里的费用类型作为sheetname的一部分，所以lambda表达式需要捕获query进去
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("datastat.field.module2.module_name") + query->fee_name,
        [result, query](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.module2.building") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_house") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_chargeable_house") ,
                ZH_WORDS_GETTER("datastat.field.module2.arrears_history") ,
                ZH_WORDS_GETTER("datastat.field.module2.all_arrears") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_paid_house_today") ,
                ZH_WORDS_GETTER("datastat.field.module2.cost_for_paid_today") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_notpaid_house_history") ,
                ZH_WORDS_GETTER("datastat.field.module2.cost_for_arrears_history") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_paid_house_month") ,
                ZH_WORDS_GETTER("datastat.field.module2.num_for_last_house") ,
                ZH_WORDS_GETTER("datastat.field.module2.percentage_for_paid_house") ,
                ZH_WORDS_GETTER("datastat.field.module2.fees_for_received_month") ,
                ZH_WORDS_GETTER("datastat.field.module2.fees_for_notreceived_month"),
                ZH_WORDS_GETTER("datastat.field.module2.charge_rate")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->building);
                ex->setCellValue(row, col++, std::to_string(item->num_for_house));
                ex->setCellValue(row, col++, std::to_string(item->num_for_chargeable_house));
                ex->setCellValue(row, col++, std::to_string(item->arrears_history));
                ex->setCellValue(row, col++, std::to_string(item->all_arrears));
                ex->setCellValue(row, col++, std::to_string(item->num_for_paid_house_today));
                ex->setCellValue(row, col++, std::to_string(item->cost_for_paid_today));
                ex->setCellValue(row, col++, std::to_string(item->num_for_notpaid_house_history));
                ex->setCellValue(row, col++, std::to_string(item->cost_for_arrears_history));
                ex->setCellValue(row, col++, std::to_string(item->num_for_paid_house_month));
                ex->setCellValue(row, col++, std::to_string(item->num_for_last_house));
                ex->setCellValue(row, col++, std::to_string(item->percentage_for_paid_house));
                ex->setCellValue(row, col++, std::to_string(item->fees_for_received_month));
                ex->setCellValue(row, col++, std::to_string(item->fees_for_notreceived_month));
                ex->setCellValue(row, col++, std::to_string(item->charge_rate));

                ex->setRowProperties(row++);
            }
        });

    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    std::string filename = "rp-datastat-charge-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // 影响成功结果
    return response;
}




DatastatMonthDetailPageJsonVO::Wrapper DatastatController::executeQueryMonthDetaile(const oatpp::Object<DatastatMonthDetailQuery>& query)
{
    // 定义一个Service
    DatastatMonthDetailService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = DatastatMonthDetailPageJsonVO::createShared();

    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::execExportMonthDetaile(const DatastatMonthDetailQuery::Wrapper& query)
{
    // 定义一个Service
    DatastatMonthDetailService service;
    // 查询数据
    auto result = service.listAll(query);

    // 将数据写入到Excel中
    // 因为这个表格要用到query里的费用类型作为sheetname的一部分，所以lambda表达式需要捕获query进去
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("datastat.field.module3.module_name") + query->fee_name,
        [result, query](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.module3.house") ,
                ZH_WORDS_GETTER("datastat.field.module3.ow") ,
                ZH_WORDS_GETTER("datastat.field.module3.final") ,
                ZH_WORDS_GETTER("datastat.field.module3.name_fee") ,
                ZH_WORDS_GETTER("datastat.field.module3.time_income") ,
                ZH_WORDS_GETTER("datastat.field.module3.cashier") ,
                ZH_WORDS_GETTER("datastat.field.module3.time_pay")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, item->ow);
                ex->setCellValue(row, col++, std::to_string(item->final));
                ex->setCellValue(row, col++, item->name_fee);
                ex->setCellValue(row, col++, item->time_income);
                ex->setCellValue(row, col++, item->cashier);
                ex->setCellValue(row, col++, item->time_pay);


                ex->setRowProperties(row++);
            }
        });

    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    std::string filename = "rp-datastat-month-detail-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // 影响成功结果
    return response;
}






DatastatMonthFeePageJsonVO::Wrapper DatastatController::executeQueryMonthFee(const oatpp::Object<DatastatMonthFeeQuery>& query)
{
    // 定义一个Service
    DatastatMonthFeeService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = DatastatMonthFeePageJsonVO::createShared();

    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DatastatController::execExportMonthFee(const DatastatMonthFeeQuery::Wrapper& query)
{
    // 定义一个Service
    DatastatMonthFeeService service;
    // 查询数据
    auto result = service.listAll(query);

    // 将数据写入到Excel中
    // 因为这个表格要用到query里的费用类型作为sheetname的一部分，所以lambda表达式需要捕获query进去
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("datastat.field.module4.module_name") + query->fee_name,
        [result, query](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("datastat.field.module4.house") ,
                ZH_WORDS_GETTER("datastat.field.module4.ow") ,
                ZH_WORDS_GETTER("datastat.field.module4.arrears_name") ,
                ZH_WORDS_GETTER("datastat.field.module4.arrears_time") ,
                ZH_WORDS_GETTER("datastat.field.module4.arrears_num")
                });
            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->house);
                ex->setCellValue(row, col++, item->ow);
                ex->setCellValue(row, col++, item->arrears_name);
                ex->setCellValue(row, col++, item->arrears_time);
                ex->setCellValue(row, col++, std::to_string(item->arrears_num));


                ex->setRowProperties(row++);
            }
        });

    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    std::string filename = "rp-datastat-month-fee-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // 影响成功结果
    return response;
}





///////// 1
// 日期格式校验 (yyyy-MM-dd) - 不使用正则表达式
bool validateDateFormat(const std::string& date) {
    if (date.empty()) {
        return true;
    }

    // 检查长度
    if (date.length() != 10) {
        return false;
    }

    // 检查格式：yyyy-MM-dd
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    // 检查年月日是否都是数字
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) {
            return false;
        }
    }

    // 提取年月日
    try {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));

        // 基本范围校验
        if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
            return false;
        }

        // 简单的月份天数校验
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            return false;
        }
        if (month == 2 && day > 29) {
            return false;
        }

        return true;
    }
    catch (const std::exception&) {
        return false;
    }
}

// 社区ID校验
bool validateCommunityId(const std::string& communityId) {
    if (communityId.empty()) {
        return true;
    }

    // 校验长度
    if (communityId.length() > 50) {
        return false;
    }

    // 检查每个字符是否合法
    for (char c : communityId) {
        if (!std::isalnum(c) && c != '_' && c != '-') {
            return false;
        }
    }

    return true;
}

// 社区名称校验
bool validateCommunityName(const std::string& communityName) {
    if (communityName.empty()) {
        return true;
    }

    // 校验长度
    if (communityName.length() > 100) {
        return false;
    }

    // 检查是否包含危险字符
    std::string dangerousChars = "';\"\\<>|&$`(){}[]";
    for (char c : dangerousChars) {
        if (communityName.find(c) != std::string::npos) {
            return false;
        }
    }

    return true;
}

// 清理Excel工作表名称的辅助函数
std::string cleanExcelSheetTitle(const std::string& title) {
    // 定义Excel工作表名称中的非法字符
    const std::string invalidChars = R"([\]/?*:")";

    // 移除非法字符
    std::string cleanTitle;
    std::copy_if(title.begin(), title.end(),
        std::back_inserter(cleanTitle),
        [&invalidChars](char c) {
            return invalidChars.find(c) == std::string::npos;
        });

    // 截断过长的名称（Excel限制为31个字符）
    if (cleanTitle.length() > 31) {
        cleanTitle = cleanTitle.substr(0, 31);
    }

    // 移除首尾的单引号
    if (!cleanTitle.empty() && cleanTitle.front() == '\'') {
        cleanTitle.erase(0, 1);
    }
    if (!cleanTitle.empty() && cleanTitle.back() == '\'') {
        cleanTitle.pop_back();
    }

    return cleanTitle;
}