#include "stdafx.h"
#include "PaydetController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "../../service/paydet/PaydetService.h"

PayDetPageJsonVO::Wrapper PaydetController::execQueryGetPaydet(const oatpp::Object<GetPaydetQuery>& query)
{
    // 定义一个Service
    PayDetService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = PayDetPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PaydetController::execExportPaydet(const GetPaydetQuery::Wrapper& query)
{
    // 定义一个Service
    PayDetService service;
    // 查询数据
    auto result = service.listAll(query);

    // 将数据写入到Excel中
    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("paydet.list2"),
        [result](ExcelComponent* ex) {
            // 写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("paydet.orderNumber"),               // 订单号
                ZH_WORDS_GETTER("paydet.houseNumberPropertyOwner"),  // 序号/业主
                ZH_WORDS_GETTER("paydet.expenseTypeItem"),           // 费用类型->费用项
                ZH_WORDS_GETTER("paydet.expenseType.expenseStatus"), // 费用状态
                ZH_WORDS_GETTER("paydet.payMethod.method"),          // 支付方式
                ZH_WORDS_GETTER("paydet.paymentPeriod"),             // 缴费时间段
                ZH_WORDS_GETTER("paydet.paymentTime"),               // 缴费时间
                ZH_WORDS_GETTER("paydet.cashier"),                   // 收银员
                ZH_WORDS_GETTER("paydet.ducReceiveAmount"),          // 应缴/应收金额（元）
                ZH_WORDS_GETTER("paydet.annountReceived"),           // 实收金额（元）
                ZH_WORDS_GETTER("paydet.accountDeduction"),          // 账户抵扣（元）
                ZH_WORDS_GETTER("paydet.discountWaiverAmount"),      // 优惠/减免金额（元）
                ZH_WORDS_GETTER("paydet.giftAmount"),                // 赠送金额（元）
                ZH_WORDS_GETTER("paydet.latePaymentFee"),            // 滞纳金（元）
                ZH_WORDS_GETTER("paydet.area"),                      // 面积（平方米）
                ZH_WORDS_GETTER("paydet.parkingSpace"),              // 车位
                ZH_WORDS_GETTER("paydet.remarks")                    // 说明
                });

            // 写入数据
            int row = 2;
            int col = 1;
            for (auto item : *(result->rows.get())) {
                col = 1;
                ex->setCellValue(row, col++, item->on);       // 订单号
                ex->setCellValue(row, col++, item->hnpo);     // 序号/业主
                ex->setCellValue(row, col++, item->eti);      // 费用类型->费用项
                ex->setCellValue(row, col++, item->etatus);   // 费用状态
                ex->setCellValue(row, col++, item->pm);       // 支付方式
                ex->setCellValue(row, col++, item->pps);      // 缴费时间段
                ex->setCellValue(row, col++, item->payt);     // 缴费时间
                ex->setCellValue(row, col++, item->chier);    // 收银员
                ex->setCellValue(row, col++, std::to_string(item->dra));  // 应缴/应收金额
                ex->setCellValue(row, col++, std::to_string(item->ard));  // 实收金额
                ex->setCellValue(row, col++, std::to_string(item->ad));   // 账户抵扣
                ex->setCellValue(row, col++, std::to_string(item->dwa));  // 优惠/减免金额
                ex->setCellValue(row, col++, std::to_string(item->ga));   // 赠送金额
                ex->setCellValue(row, col++, std::to_string(item->lpf));  // 滞纳金
                ex->setCellValue(row, col++, std::to_string(item->ar));   // 面积
                ex->setCellValue(row, col++, item->ps);       // 车位
                ex->setCellValue(row, col++, item->rem);      // 说明

                ex->setRowProperties(row++);
            }
        });

    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    std::string filename = "rp-paydet" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, " application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    // 影响成功结果
    return response;
}
