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
#include "PrintInfoController.h"
#include "../../service/PrintInfo/PrintInfoService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "PdfComponent.h"
#include "SimpleDateTimeFormat.h"

// 阿拉伯数字转中文
static std::string convertCn(const oatpp::String& oatppAmount) {
	// 处理空指针情况
	if (!oatppAmount || oatppAmount->empty()) {
		return u8"零";
	}

	std::string amount = *oatppAmount;

	// 清理输入 - 允许负号和小数点
	std::string cleanAmount;
	bool negative = false;

	for (char c : amount) {
		if (c == '-' && cleanAmount.empty()) {
			negative = true;
		}
		else if (c == '.' || c == ',') {
			// 遇到小数点或逗号停止处理
			break;
		}
		else if (c >= '0' && c <= '9') {
			cleanAmount += c;
		}
	}

	// 检查清理后的输入
	if (cleanAmount.empty()) {
		return u8"零";
	}

	// 特殊处理 "0"
	if (cleanAmount == "0") {
		return u8"零";
	}

	// 去除前导零
	size_t start = cleanAmount.find_first_not_of('0');
	if (start == std::string::npos) {
		return u8"零";
	}
	cleanAmount = cleanAmount.substr(start);

	// 使用 u8 前缀确保 UTF-8 编码
	const std::vector<std::string> unit{ u8"", u8"拾", u8"佰", u8"仟" };
	const std::vector<std::string> sectionUnits{ u8"", u8"万", u8"亿", u8"万亿" };
	const std::vector<std::string> digit{
		u8"零", u8"壹", u8"贰", u8"叁", u8"肆",
		u8"伍", u8"陆", u8"柒", u8"捌", u8"玖"
	};

	std::string res;
	int n = cleanAmount.size();
	bool needZero = false;

	// 分组处理：每4位一组
	for (int section = (n - 1) / 4; section >= 0; --section) {
		int startIdx = std::max(0, n - (section + 1) * 4);
		int endIdx = n - section * 4;

		// 边界安全检查
		if (startIdx >= n || endIdx > n || startIdx < 0) {
			continue;
		}

		int groupSize = endIdx - startIdx;
		if (groupSize <= 0) continue;

		std::string group = cleanAmount.substr(startIdx, groupSize);
		std::string groupRes;
		bool hasNonZero = false;
		bool lastIsZero = true;

		// 处理组内数字
		for (int i = 0; i < group.size(); ++i) {
			char c = group[i];
			if (c < '0' || c > '9') continue;

			int num = c - '0';
			int pos = group.size() - 1 - i;

			if (num != 0) {
				if (lastIsZero && !groupRes.empty()) {
					groupRes += digit[0]; // u8"零"
				}

				// 特殊处理 "壹拾" -> "拾"
				if (!(pos == 1 && num == 1 && groupRes.empty())) {
					groupRes += digit[num];
				}

				if (pos > 0) {
					groupRes += unit[pos];
				}

				hasNonZero = true;
				lastIsZero = false;
			}
			else {
				lastIsZero = true;
			}
		}

		if (hasNonZero) {
			if (needZero) {
				res += digit[0]; // u8"零"
				needZero = false;
			}

			if (section < static_cast<int>(sectionUnits.size())) {
				res += groupRes + sectionUnits[section];
			}
			else {
				res += groupRes;
			}
		}
		else if (!res.empty()) {
			needZero = true;
		}
	}

	if (res.empty()) {
		return u8"零";
	}

	// 添加负号
	if (negative) {
		res = std::string(u8"负") + res;
	}

	return res;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PrintInfoController::execExportPrintRpt(const PrintInfoQuery::Wrapper& query) {
	// 定义一个service
	PrintInfoService service;
	// 获取分页结果
	auto result = service.listAll(query);

	//注册渲染模板
	PdfComponent::registerTplRender("receipt", [](YAML::Node* node, PdfComponent* pdf, void* realData) {
		// 创建一个 A4大小的 横向显示的页面
		auto page = pdf->getNewPage(HPDF_PageSizes::HPDF_PAGE_SIZE_A4, HPDF_PageDirection::HPDF_PAGE_LANDSCAPE);

		// 注册静态标题
		auto top = (*node)["Rpt"]["top"];
		// 将realData转为从数据库查到的值
		auto dto = static_cast<PrintInfoPageDTO::Wrapper*>(realData);
		auto dto_stat = *(*dto)->rows;
		auto statItem = dto_stat.back();
		
		// 表格 y 的当前位置
		int curX = 15;
		// 表格 x 的当前位置
		int curY = 525;

		// 表格高度的偏移量
		const int excelHeightO = 30; 
		// 表格宽度的偏移量	
		const int excelWidthO = 100;

		// 静态消息
		auto content = (*node)["Rpt"]["content"];
		// 标题
		pdf->drawText(statItem->name + top["title"].as<std::string>(), 340, top["y"].as<int>(), page);
		
		// 设置当前页面的字体大小
		pdf->setCurrPageFontSize(10);
		// 单号
		pdf->drawText(content[0].as<std::string>() + statItem->ar_id, 10, 550, page);
		// 预存时间
		pdf->drawText(content[1].as<std::string>() + statItem->create_time, 690, 550, page);
		for (int i = 2, t = curX; i <= 9; ++i, t += excelWidthO) {
			if (i == 3) t -= 20;
			if (i == 4) t += 30;
			if (i == 5) t += 42;
			if (i == 6) t += 18;
			if (i == 7) t += 30;
			if (i == 9) t -= 10;
			// 编号 - 备注的打印
			pdf->drawText(content[i].as<std::string>(), t, curY, page);
		}
		curY -= excelHeightO;

		// 编号
		int num = 1;
		// 总计
		long long sumMoney = 0;
		// 表格 y 的位置
		int tableY = curY;
		for (auto item : *(*dto)->rows) {
			// 表格 x 的位置
			int tableX = curX+5;
			// 编号
			pdf->drawText(std::to_string(num), tableX, tableY, page), tableX = tableX + excelWidthO - 20;
			// 账户名称
			pdf->drawText(item->acct_name, tableX, tableY, page), tableX += excelWidthO + 10;
			// 账户类型
			pdf->drawText(item->acct_type, tableX, tableY, page), tableX += excelWidthO + 55;
			// 业主
			pdf->drawText(item->owner_name, tableX, tableY, page), tableX += excelWidthO + 15;
			// 预存金额			x = 615
			pdf->drawText(item->received_amount, tableX, tableY, page), tableX += excelWidthO + 35;
			// 预存方式
			pdf->drawText(item->prime_rate, tableX, tableY, page), tableX = tableX + excelWidthO - 5;
			// 当前余额
			pdf->drawText(item->amount, tableX, tableY, page), tableX = tableX + excelWidthO - 20;
			// 备注					x = 790
			pdf->drawText(item->remark, tableX, tableY, page), tableX += excelWidthO;

			// 金额总数
			sumMoney += std::stoi(item->received_amount);

			num++;
			tableY -= excelHeightO;
		}
		// 大写人名币（元）
		pdf->drawText(content[10].as<std::string>(), curX + 100, tableY, page);
		// 总计
		// 中文形式
		std::string ansCn = convertCn(std::to_string(sumMoney));
		// 确保设置了中文字体
		//pdf->getCnSFont("SimSun"); // 使用 "SimSun" 或 "SimHei"
		pdf->drawText(ansCn, 490, tableY, page);
		// 数字形式
		pdf->drawText(std::to_string(sumMoney), 790, tableY, page);
		// 部门负责人
		tableY -= excelHeightO;
		pdf->drawText(content[11].as<std::string>(), curX, tableY, page);
		// 经办人
		pdf->drawText(content[12].as<std::string>() + statItem->page_name, 245, tableY, page);
		// 财务收款
		pdf->drawText(content[13].as<std::string>(), 470, tableY, page);
		// 客户确认
		pdf->drawText(content[14].as<std::string>(), 670, tableY, page);

		// 表格的左上角起点的 x 值
		int startX = 0;
		// 表格的左上角起点的 y 值
		int startY = 575;
		// 表头高度
		int headerHeight = 30;
		// 表头宽度
		int headerWidth = 842;
		// 设置横向线条宽度为 1
		HPDF_Page_SetLineWidth(page, 1.0);
		// 设置线条的颜色为 纯黑色
		HPDF_Page_SetRGBStroke(page, 0, 0, 0);
		

		// 绘制表格
		// 水平线
		for (int i = num+2, j = 1; i >= 1; --i, ++j) {
			// 横线的起点坐标
			HPDF_Page_MoveTo(page, startX, startY - headerHeight * j);
			// 横线的终点坐标
			HPDF_Page_LineTo(page, startX + headerWidth, startY - headerHeight * j);
		}

		// 垂直线
		// 第一条垂线
		int headerSonWidth = 50;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// 第二条
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// 第三条
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 2));
		// 第四条
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// 第五条
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// 第六条
		headerSonWidth += 130;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 1));
		// 第七条
		headerSonWidth += 82;
		HPDF_Page_MoveTo(page, startX + headerSonWidth, startY - headerHeight);
		HPDF_Page_LineTo(page, startX + headerSonWidth, startY - headerHeight * (num + 2));

		// 将定义的表格绘制到pdf上
		HPDF_Page_Stroke(page);
		
		
		});

	// 测试绘制
	PdfComponent pdf;
	pdf.drawWithTemplate("tpl/test.yaml", "receipt", &result);
	// 保存到文件
	pdf.saveDocToFile("pdf-receipt.pdf");

	// 读取生成的 PDF 文件内容
	auto file = oatpp::String::loadFromFile("pdf-receipt.pdf");
	if (!file || file->empty()) {
		return createResponse(Status::CODE_404, "PDF文件未生成");
	}
	// 返回 PDF 文件内容作为响应
	auto response = createResponse(Status::CODE_200, file);
	response->putHeader("Content-Type", "application/pdf");
	response->putHeader("Content-Disposition", "attachment; filename=\"report.pdf\"");
	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> PrintInfoController::execExportPrintSlip(const PrintInfoQuery::Wrapper& query) {
	// 定义一个service
	PrintInfoService service;
	// 获取分页结果
	auto result = service.listAll(query);

	// 注册渲染模板
	PdfComponent::registerTplRender("prestore_fee", [](YAML::Node* node, PdfComponent* pdf, void* realData) {
		// 创建一个A4大小的 横向显示的页面
		auto page = pdf->getNewPage(HPDF_PageSizes::HPDF_PAGE_SIZE_A4, HPDF_PageDirection::HPDF_PAGE_LANDSCAPE);
		// 渲染静态标题
		auto top = (*node)["Slip"]["top"];
		pdf->drawTextCenterH(top["title"].as<std::string>(), top["y"].as<int>(), page);

		// 设置当前页面的字体大小
		pdf->setCurrPageFontSize(10);

		// 读取content数据
		auto content = (*node)["Slip"]["content"].as<std::vector<std::string>>();
		int starty = 550;
		// 将realData转到保存数据库查询结果的地址
		auto dto = static_cast<PrintInfoPageDTO::Wrapper*>(realData);
		auto hi = *(*dto)->rows;

		// 绘制静态内容
		auto statItem = hi.back();
		pdf->drawText(content[0], 0, starty, page);
		starty -= 15;
		// 单号
		pdf->drawText(content[1] + statItem->ar_id, 5, starty, page);		
		starty -= 15;
		// 时间
		pdf->drawText(content[2] + statItem->create_time, 5, starty, page);
		starty -= 15;
		pdf->drawText(content[3], 0, starty, page);

		// 小票的总金额
		long long sumMoney = 0;
		// 绘制pdf动态内容
		for (auto item : *(*dto)->rows) {
			// 账户名称
			starty -= 15;
			pdf->drawText(content[4] + item->acct_name, 5, starty, page);
			// 账户类型
			starty -= 15;
			pdf->drawText(content[5] + item->acct_type, 5, starty, page);
			starty -= 15;
			// 业主
			pdf->drawText(content[6] + item->owner_name, 5, starty, page);
			starty -= 15;
			// 预存金额
			pdf->drawText(content[7] + item->received_amount, 5, starty, page);
			starty -= 15;
			// 预存方式
			pdf->drawText(content[8] + item->prime_rate, 5, starty, page);
			starty -= 15;
			// 当前金额
			pdf->drawText(content[9] + item->amount, 5, starty, page);
			starty -= 15;
			// 备注
			pdf->drawText(content[10] + item->remark, 5, starty, page);	
			starty -= 15;			
			pdf->drawText(content[11], 0, starty, page);

			// 总金额量
			sumMoney += std::stoi(item->received_amount);
		}
		// 总计
		starty -= 15;
		pdf->drawText(content[12] + std::to_string(sumMoney), 5, starty, page);
		// 开票人
		starty -= 15;
		pdf->drawText(content[13] + statItem->page_name, 5, starty, page);
		starty -= 62;
		pdf->drawText(content[14], 0, starty, page);
		
		// 二维码保存位置
		std::string filepath = "QR_Code.jpg";
		// 生成二维码到文件
		std::string url = "https://ys.mihoyo.com/?utm_source=backup307&from_channel=backup307#/";
		int QRCode_Y = 145;
		// 设置二维码保存的地址以及二维码的长和宽
		bool success = PdfComponent::genPictureCodeToFile(filepath, 0,0, url, "QRCode");
		if (success)
		{
			// 加载图片文件
			HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf->getDoc(), filepath.c_str());
			// 绘制图片到PDF中 
			pdf->drawImage(image, 0, 180);
		}

		});

	// 测试绘制
	PdfComponent pdf;
	pdf.drawWithTemplate("tpl/test.yaml", "prestore_fee", &result);
	// 将二维码保存到文件
	pdf.saveDocToFile("pdf-slip.pdf");
	pdf.saveDocToFile("QR_Code.jpg");

	// 读取生成的 PDF 文件内容
	auto file = oatpp::String::loadFromFile("pdf-slip.pdf");
	if (!file || file->empty()) {
		return createResponse(Status::CODE_404, "PDF文件未生成");
	}
	// 返回 PDF 文件内容作为响应
	auto response = createResponse(Status::CODE_200, file);
	response->putHeader("Content-Type", "application/pdf");
	response->putHeader("Content-Disposition", "attachment; filename=\"report.pdf\"");
	return response;
}

