#include"stdafx.h"
#include "ExpesumController.h"
#include "../../service/expesum/ExpeSumService.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
//============== 楼栋收费率分页查询实现 ==============
BuildingRatePageJsonVO::Wrapper FeeRateController::execQueryBuildingRates(const BuildingRateQuery::Wrapper& query)
{

    // 定义一个Service
    BuildingRateService service;
    // 查询数据
    auto result = service.listByPage(query);
    // 响应结果
    auto jvo = BuildingRatePageJsonVO::createShared();
    jvo->success(result);
    return jvo;

}

//============== 费用项收费率分页查询实现 ==============
FeeItemRatePageJsonVO::Wrapper FeeRateController::execQueryFeeItemRates(const FeeItemRateQuery::Wrapper& query)
{
    // 定义一个Service
    FeeItemRateService service;
    // 查询数据
    auto result = service.listByPage(query);
    // 响应结果
    auto jvo = FeeItemRatePageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}


/*           费用汇总-2         */
ExpeSumJsonVO::Wrapper ExpeSumController::execQueryExpeSum(const ExpeSumQuery::Wrapper& query)
{
    //定义一个service
    ExpeSumService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = ExpeSumJsonVO::createShared();
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExpeSumController::execExportExpeSum(const ExpeSumQuery::Wrapper& query)
{
    //定义一个service
    ExpeSumService service;
    auto result = service.listAll(query);

    auto buff = ExcelComponent().writeVectorToBuff(ZH_WORDS_GETTER("expesum.export"), [result](ExcelComponent* ex)
        {
            //写入表头
            ex->addHeader({
                ZH_WORDS_GETTER("expesum.totalRoomCount"),
                ZH_WORDS_GETTER("expesum.feeRoomCount"),
                ZH_WORDS_GETTER("expesum.oweRoomCount"),
                ZH_WORDS_GETTER("expesum.hisOweFee"),
                 ZH_WORDS_GETTER("expesum.curOweFee"),
                ZH_WORDS_GETTER("expesum.curReceivableFee"),
                ZH_WORDS_GETTER("expesum.curReceivedFee"),
                ZH_WORDS_GETTER("expesum.hisReceivedFee"),
                ZH_WORDS_GETTER("expesum.preReceivedFee")
                });

            // 写入数据（数据只有一行，按字段顺序写入）
            int row = 2, col = 1;
            ex->setCellValue(row, col++, std::to_string(result->totalRoomCount));
            ex->setCellValue(row, col++, std::to_string(result->feeRoomCount));
            ex->setCellValue(row, col++, std::to_string(result->oweRoomCount));
            ex->setCellValue(row, col++, std::to_string(result->hisOweFee));
            ex->setCellValue(row, col++, std::to_string(result->curOweFee));
            ex->setCellValue(row, col++, std::to_string(result->curReceivableFee));
            ex->setCellValue(row, col++, std::to_string(result->curReceivedFee));
            ex->setCellValue(row, col++, std::to_string(result->hisReceivedFee));
            ex->setCellValue(row, col, std::to_string(result->preReceivedFee));
            ex->setRowProperties(row);
        }
    );

    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    std::string filename = "expesum-" + SimpleDateTimeFormat::format() + ".xlsx";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");

    return response;
}
