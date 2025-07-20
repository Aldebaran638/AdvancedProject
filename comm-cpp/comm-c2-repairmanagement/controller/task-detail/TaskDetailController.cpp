#include "stdafx.h"
#include "TaskDetailController.h"
#include "../../service/task-detail/TaskDetailService.h"
#include "SimpleDateTimeFormat.h"
#include "PdfComponent.h"
#include "haru/win/hpdf.h"
#include "haru/linux/hpdf.h"

/**
* 工单详情打印PDF
*/
struct PdfTaskDetailData {
    //工单详情
    TaskDetailExportDetailDTO::Wrapper detail;
    //工单流转
    std::vector<TaskDetailExportCirculationDTO::Wrapper> circulation;
};

// PDF画线
void drawLine(HPDF_Page page, float x1, float y1, float x2, float y2) {
    HPDF_Page_SetLineWidth(page, 1.0);
    HPDF_Page_MoveTo(page, x1, y1);
    HPDF_Page_LineTo(page, x2, y2);
    HPDF_Page_Stroke(page);
}

// 定义工单打印数据函数
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> TaskDetailController::execExportTaskDetail(const TaskDetailQuery::Wrapper& query)
{
    // 定义一个Service
    TaskDetailService service;
    // 查询工单详情数据
    auto ret1 = service.getExportTaskDetail(query);
    if (!ret1) {
        auto error = String("Task not found or has been deleted");
        auto response = createResponse(Status::CODE_404, error);
        return response;
    }

    // 工单编号不存在
    if (ret1->repair_id.getValue("").empty()) {
        auto error = String("repair_id is null");
        auto response = createResponse(Status::CODE_404, error);
        return response;
    }

    // 查询工单流转数据
    auto ret2 = service.getExportCirculate(query);


    // 组装PDF数据
    PdfTaskDetailData pdfData;
    pdfData.detail = ret1;
    for (auto item : *(ret2->rows.get())) {
        pdfData.circulation.push_back(item);
    }

    PdfComponent::registerTplRender("task-detail", [](YAML::Node* node, PdfComponent* pdf, void* realData) {
        // 取出数据
        PdfTaskDetailData* data = static_cast<PdfTaskDetailData*>(realData);
        auto& detail = data->detail;
        auto& circulation = data->circulation;
        auto print_time = SimpleDateTimeFormat::format();

        // 创建一个横向页面
        auto page = pdf->getNewPage(pdf->getCnSFont("SimSun"), 12, HPDF_PageSizes::HPDF_PAGE_SIZE_A4, HPDF_PageDirection::HPDF_PAGE_LANDSCAPE);

        int y = pdf->getCurrPageHeight() - 40;

        // 顶部
        pdf->drawText((*node)["repair-id"].as<std::string>() + detail->repair_id, 30, y, page);
        pdf->drawText((*node)["print-time"].as<std::string>() + print_time, 620, y, page);

        int curlation_size = circulation.size();
        // 左右竖线
        drawLine(page, 20, y - 10, 20, y - 40); // 左
        drawLine(page, 820, y - 10, 820, y - 40); // 右
        int size1 = curlation_size + 7;
        int tableY1 = y - 40;
        while (size1--)
        {
            tableY1 -= 30;
            drawLine(page, 20, y - 10, 20, tableY1); // 左
            drawLine(page, 820, y - 10, 820, tableY1); // 右
        }
        // 报修信息竖线
        drawLine(page, 260, y - 40, 260, y - 100);
        drawLine(page, 560, y - 40, 560, y - 100);
        // 工单流转竖线
        drawLine(page, 60, y - 130, 60, y - 160 - 30 * (curlation_size + 1));
        drawLine(page, 230, y - 130, 230, y - 160 - 30 * curlation_size);
        drawLine(page, 300, y - 130, 300, y - 160 - 30 * curlation_size);
        drawLine(page, 520, y - 130, 520, y - 160 - 30 * curlation_size);
        drawLine(page, 600, y - 130, 600, y - 160 - 30 * curlation_size);
        // 签名区竖线
        drawLine(page, 120, y - 160 - 30 * (curlation_size + 1), 120, y - 160 - 30 * (curlation_size + 3));
        drawLine(page, 520, y - 160 - 30 * (curlation_size + 1), 520, y - 160 - 30 * (curlation_size + 3));
        drawLine(page, 600, y - 160 - 30 * (curlation_size + 1), 600, y - 160 - 30 * (curlation_size + 3));

        // 横线
        drawLine(page, 20, y - 10, 820, y - 10); // 上
        int size2 = curlation_size + 8;
        int tableY2 = y - 10;
        while (size2--)
        {
            tableY2 -= 30;
            drawLine(page, 20, tableY2, 820, tableY2);
        }

        // 报修信息
        y -= 30;
        pdf->drawTextCenterH((*node)["summary-task-detail"].as<std::string>(), y, page);

        y -= 30;
        pdf->drawText((*node)["repair-name"].as<std::string>() + detail->repair_name, 30, y, page);
        pdf->drawText((*node)["tel"].as<std::string>() + detail->tel, 360, y, page);
        pdf->drawText((*node)["repair-obj-name"].as<std::string>() + detail->repair_obj_name, 630, y, page);

        y -= 30;
        pdf->drawText((*node)["task-context"].as<std::string>() + detail->task_context, 30, y, page);
        pdf->drawText((*node)["repair-type"].as<std::string>() + detail->repair_type, 360, y, page);
        pdf->drawText((*node)["maintenance-type"].as<std::string>() + detail->maintenance_type, 630, y, page);

        // 工单流转表头
        y -= 30;
        pdf->drawTextCenterH((*node)["summary-task-circulation"].as<std::string>(), y, page);
        y -= 30;
        pdf->drawText((*node)["number"].as<std::string>(), 30, y, page);
        pdf->drawText((*node)["staff-name"].as<std::string>(), 110, y, page);
        pdf->drawText((*node)["state"].as<std::string>(), 250, y, page);
        pdf->drawTextCenterH((*node)["start-time"].as<std::string>(), y, page);
        pdf->drawText((*node)["cost"].as<std::string>(), 550, y, page);
        pdf->drawText((*node)["user-context"].as<std::string>(), 700, y, page);

        // 工单流转内容
        int idx = 1;
        for (const auto& row : circulation) {
            y -= 30;
            pdf->drawText(std::to_string(idx), 35, y, page);
            pdf->drawText(row->staff_name, 110, y, page);
            pdf->drawText(row->state, 250, y, page);
            pdf->drawTextCenterH(row->start_time, y, page);
            pdf->drawText(row->cost, 550, y, page);
            pdf->drawText(row->user_context, 630, y, page);
            idx++;
        }

        // 备注
        y -= 30;
        pdf->drawText((*node)["remark"].as<std::string>(), 30, y, page);

        // 签名区
        y -= 30;
        pdf->drawText((*node)["staff-name-signature"].as<std::string>(), 30, y, page);
        pdf->drawText((*node)["time"].as<std::string>(), 550, y, page);
        y -= 30;
        pdf->drawText((*node)["repair-name-signature"].as<std::string>(), 30, y, page);
        pdf->drawText((*node)["time"].as<std::string>(), 550, y, page);
        });


    // 绘制	
    PdfComponent pdf;
    pdf.drawWithTemplate("tpl/task-detail.yaml", "task-detail", &pdfData);
    auto buff = pdf.saveDocToMem();

    // 组装下发数据
    const char* charData = reinterpret_cast<const char*>(buff.data());
    auto fstring = String(charData, buff.size());
    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);
    // 设置响应头信息
    std::string filename = "task-detail-" + SimpleDateTimeFormat::format() + ".pdf";
    response->putHeader("Content-Disposition", "attachment; filename=" + filename);
    response->putHeader(Header::CONTENT_TYPE, "application/pdf");
    return response;

}

// 定义派单数据函数
TaskDetailAddJsonVO::Wrapper TaskDetailController::execAddTaskDetail(const TaskDetailAddDTO::Wrapper& dto)
{
    // 定义返回数据对象
    auto jvo = TaskDetailAddJsonVO::createShared();
    // 参数校验
    // 非空校验
    if (dto->repair_id->empty() || dto->staff_name->empty() || dto->context->empty())
    {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    // 定义一个Service
    TaskDetailService service;
    // 执行数据新增
    std::string id = service.saveData(dto);
    if (id != "") {
        auto resultDto = TaskDetailGetIdDTO::createShared();
        resultDto->repair_id = id;
        jvo->success(resultDto);
    }
    else
    {
        jvo->fail(nullptr);
    }
    //响应结果
    return jvo;
}
// 定义获取工单详情数据函数
TaskDetailGetJsonVO::Wrapper TaskDetailController::execQueryTaskDetailById(const String& repair_id)
{
    // 定义返回数据对象
    auto jvo = TaskDetailGetJsonVO::createShared();

    // 参数校验
    // 非空校验
    if (!repair_id)
    {
        jvo->init(nullptr, RS_PARAMS_INVALID);
        return jvo;
    }

    // 定义一个Service
    TaskDetailService service;
    // 执行数据查询
    auto res = service.getById(repair_id.getValue({}));
    jvo->success(res);

    // 响应结果
    return jvo;
}
