#include "stdafx.h"
#include "SupRecepitController.h"
#include "ExcelComponent.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "SimpleDateTimeFormat.h"
#include"service/reprint_vouchers/SupRecepitService.h"
#include <iostream>
#include <fstream>
#include<cmath>
#include "Macros.h"
#include "PdfComponent.h"
#include "gtest/gtest.h"
#include<algorithm>
#include<map>

std::string SupRecepitController::splitNum(std::string s) {

	// 如果传入的是空串则继续返回空串
	if ("" == s) {
		return "";
	}
	// 截取输入数字的整数部分
	string intOnly = s.substr(0, s.size() - 3);
	string intPart = BigChineseChange(1, intOnly);

	// 截取这个数的小数部分
	string smallOnly = s.substr(s.size() - 2, s.size());
	string smallPart = BigChineseChange(2, smallOnly);

	// 把转换好了的整数部分和小数部分重新拼凑一个新的字符串
	string newS = intPart + smallPart;

	return newS;
}

std::string SupRecepitController::BigChineseChange(int flag, std::string s) {
	int sLength = s.length();
	// 货币大写形式
	string bigLetter[] = { ZH_WORDS_GETTER("supplementrecepit.number.zero"), ZH_WORDS_GETTER("supplementrecepit.number.one"),
		ZH_WORDS_GETTER("supplementrecepit.number.two"), ZH_WORDS_GETTER("supplementrecepit.number.three"),
		ZH_WORDS_GETTER("supplementrecepit.number.four"), ZH_WORDS_GETTER("supplementrecepit.number.five"),
		ZH_WORDS_GETTER("supplementrecepit.number.six"), ZH_WORDS_GETTER("supplementrecepit.number.seven"),
		ZH_WORDS_GETTER("supplementrecepit.number.eight"), ZH_WORDS_GETTER("supplementrecepit.number.nine") };
	// 货币单位
	string unit[] = { ZH_WORDS_GETTER("supplementrecepit.number.yuan"), ZH_WORDS_GETTER("supplementrecepit.number.shi"),
		ZH_WORDS_GETTER("supplementrecepit.number.bai"), ZH_WORDS_GETTER("supplementrecepit.number.qian"),
		ZH_WORDS_GETTER("supplementrecepit.number.wan"),
		// 拾万位到仟万位
		ZH_WORDS_GETTER("supplementrecepit.number.shi"), ZH_WORDS_GETTER("supplementrecepit.number.bai"), ZH_WORDS_GETTER("supplementrecepit.number.qian"),
		// 亿位到万亿位
		ZH_WORDS_GETTER("supplementrecepit.number.yi"), ZH_WORDS_GETTER("supplementrecepit.number.shi"),
		ZH_WORDS_GETTER("supplementrecepit.number.bai"), ZH_WORDS_GETTER("supplementrecepit.number.qian"), ZH_WORDS_GETTER("supplementrecepit.number.wan") };
	std::string smalln[] = { ZH_WORDS_GETTER("supplementrecepit.number.fen"), ZH_WORDS_GETTER("supplementrecepit.number.jiao") };
	// 用来存放转换后的新字符串
	string newS = "";
	// 逐位替换为中文大写形式
	for (int i = 0; i < sLength; i++) {
		if (flag == 1) {
			// 转换整数部分为中文大写形式（带单位）
			newS = newS + bigLetter[s.at(i) - 48] + unit[sLength - i - 1];
		}
		else if (flag == 2) {
			// 转换小数部分（带单位）
			newS = newS + bigLetter[s.at(i) - 48] + smalln[sLength - i - 1];
		}
	}

	return newS;
}

std::string SupRecepitController::replaceAll(std::string src, std::string regex, std::string replacement) {
	int length = regex.length();
	while (src.find(regex) < src.length()) {
		// 替换 src 字符串中从第一个匹配 regex 的字符串索引开始的 length 个字符为 replacement 字符串		
		src.replace(src.find(regex), length, replacement);
	}
	return src;
}

std::string SupRecepitController::cleanZero(std::string s) {
	// 如果传入的是空串则继续返回空串
	if ("" == s) {
		return "";
	}
	// 字符串中存在多个'零'在一起的时候只读出一个'零'，并省略多余的单位
	string regex1[] = { ZH_WORDS_GETTER("supplementrecepit.regex.zeroqian"), ZH_WORDS_GETTER("supplementrecepit.regex.zerobai"), ZH_WORDS_GETTER("supplementrecepit.regex.zeroshi") };
	string regex2[] = { ZH_WORDS_GETTER("supplementrecepit.regex.zeroyi"), ZH_WORDS_GETTER("supplementrecepit.regex.zerowan"), ZH_WORDS_GETTER("supplementrecepit.regex.zeroyuan") };
	string regex3[] = { ZH_WORDS_GETTER("supplementrecepit.number.yi"), ZH_WORDS_GETTER("supplementrecepit.number.wan"), ZH_WORDS_GETTER("supplementrecepit.number.yuan") };
	string regex4[] = { ZH_WORDS_GETTER("supplementrecepit.regex.zerojiao"), ZH_WORDS_GETTER("supplementrecepit.regex.zeroyuan") };

	// 第一轮转换把 "零仟", 零佰","零拾"等字符串替换成一个"零"
	for (int i = 0; i < 3; i++) {
		s = replaceAll(s, regex1[i], ZH_WORDS_GETTER("supplementrecepit.number.zero"));
	}
	// 第二轮转换考虑 "零亿","零万","零元"等情况
	// "亿","万","元"这些单位有些情况是不能省的，需要保留下来
	for (int i = 0; i < 3; i++) {
		// 当第一轮转换过后有可能有很多个零叠在一起
		// 要把很多个重复的零变成一个零
		s = replaceAll(s, ZH_WORDS_GETTER("supplementrecepit.regex.threezero"), ZH_WORDS_GETTER("supplementrecepit.number.zero"));
		s = replaceAll(s, ZH_WORDS_GETTER("supplementrecepit.regex.doublezero"), ZH_WORDS_GETTER("supplementrecepit.number.zero"));
		s = replaceAll(s, regex2[i], regex3[i]);
	}
	// 第三轮转换把"零角","零分"字符串省略
	for (int i = 0; i < 2; i++) {
		s = replaceAll(s, regex4[i], "");
	}
	// 当"万"到"亿"之间全部是"零"的时候，忽略"亿万"单位，只保留一个"亿"
	s = replaceAll(s, ZH_WORDS_GETTER("supplementrecepit.regex.yiwan"), ZH_WORDS_GETTER("supplementrecepit.number.yi"));
	return s;

}

SupRecepitPageJsonVO::Wrapper SupRecepitController::execQuerySupRecepit(const SupRecepitQuery::Wrapper& query) {
	auto jvo = SupRecepitPageJsonVO::createShared();
	SupRecepitService service;
	auto result = service.SupRecepitListAll(query);
	jvo->success(result);
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> SupRecepitController::execExportSupRecepit(const String& id) {
	SupRecepitService service;
	if (!id)
	{
		return nullptr;
	}
	auto res = service.ReprintRecepit(id.getValue({}));
	PdfComponent pdf;
	auto page0 = pdf.getNewPage();
	if (res == nullptr) {
		auto buff = pdf.saveDocToMem();
		const char* charData = reinterpret_cast<const char*>(buff.data());
		auto fstring = String(charData, buff.size());

		auto response = createResponse(Status::CODE_200, fstring);
		std::string filename = "rp-recepit-" + SimpleDateTimeFormat::format() + ".pdf";
		response->putHeader("Content-Disposition", "attachment; filename=" + filename);

		return response;
	}
	pdf.drawTextCenterH(res->objName.getValue({}), pdf.getCurrPageHeight() - 20, page0);
	pdf.drawText(res->ownerName.getValue({}), 10, pdf.getCurrPageHeight() - 20, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint.objname"), 40, pdf.getCurrPageHeight() - 60, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint.message"), 200, pdf.getCurrPageHeight() - 60, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint.latefee"), 360, pdf.getCurrPageHeight() - 60, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint.amount"), 520, pdf.getCurrPageHeight() - 60, page0);
	pdf.setCurrPageFontSize(12);
	pdf.drawText(res->feeName.getValue(""), 40, pdf.getCurrPageHeight() - 90, page0);
	pdf.drawText(res->startTime.getValue("").substr(0, 10) + ZH_WORDS_GETTER("supplementrecepit.reprint.zhi"), 200, pdf.getCurrPageHeight() - 90, page0);
	pdf.drawText(res->endTime.getValue("").substr(0, 10), 200, pdf.getCurrPageHeight() - 100, page0);
	std::string strfloat = std::to_string(res->needPay.getValue({}));
	std::string strfloat2 = strfloat.substr(0, strfloat.find('.') + 3);
	pdf.drawText(strfloat2, 520, pdf.getCurrPageHeight() - 90, page0);
	std::string tobigChinese = splitNum(strfloat2);
	tobigChinese = cleanZero(tobigChinese);
	pdf.drawText(tobigChinese, 200, pdf.getCurrPageHeight() - 120, page0);
	pdf.drawText(":", 380, pdf.getCurrPageHeight() - 120, page0);
	strfloat = std::to_string(res->pay.getValue({}));
	strfloat2 = strfloat.substr(0, strfloat.find('.') + 3);
	pdf.drawText(strfloat2, 520, pdf.getCurrPageHeight() - 120, page0);
	pdf.drawText(res->createTime.getValue({}), 320, pdf.getCurrPageHeight() - 150, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint.odd"), 200, pdf.getCurrPageHeight() - 180, page0);
	pdf.drawText(res->recepitId.getValue("") + "(" + res->recepitPayId.getValue("") + ")", 280, pdf.getCurrPageHeight() - 180, page0);
	pdf.drawText(res->cashierName.getValue(""), 320, pdf.getCurrPageHeight() - 200, page0);

	auto buff = pdf.saveDocToMem();
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	auto response = createResponse(Status::CODE_200, fstring);
	std::string filename = "rp-recepit-" + SimpleDateTimeFormat::format() + ".pdf";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);

	return response;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> SupRecepitController::execExportSupRecepit2(const String& id) {
	SupRecepitService service;
	if (!id)
	{
		return nullptr;
	}
	auto res = service.ReprintRecepit2(id.getValue({}));
	PdfComponent pdf;
	auto page0 = pdf.getNewPage();
	if (res == nullptr) {
		auto buff = pdf.saveDocToMem();
		const char* charData = reinterpret_cast<const char*>(buff.data());
		auto fstring = String(charData, buff.size());

		auto response = createResponse(Status::CODE_200, fstring);
		std::string filename = "rp-recepit-" + SimpleDateTimeFormat::format() + ".pdf";
		response->putHeader("Content-Disposition", "attachment; filename=" + filename);

		return response;
	}
	pdf.drawTextCenterH(ZH_WORDS_GETTER("supplementrecepit.reprint2.title"), pdf.getCurrPageHeight() - 20, page0);
	pdf.setCurrPageFontSize(12);
	pdf.drawText("**************************", 10, pdf.getCurrPageHeight() - 40, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line1") + res->recepitCode.getValue(""), 10, pdf.getCurrPageHeight() - 50, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line2") + res->payOrderId.getValue(""), 10, pdf.getCurrPageHeight() - 60, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line3") + res->objName.getValue(""), 10, pdf.getCurrPageHeight() - 70, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line4") + res->payObjName.getValue(""), 10, pdf.getCurrPageHeight() - 80, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line5") + res->createTime.getValue(""), 10, pdf.getCurrPageHeight() - 90, page0);
	pdf.drawText("**************************", 10, pdf.getCurrPageHeight() - 100, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line6") + res->feeName.getValue(""), 10, pdf.getCurrPageHeight() - 110, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line7") + res->startTime.getValue("").substr(0, 10) + ZH_WORDS_GETTER("supplementrecepit.reprint.zhi") + res->endTime.getValue("").substr(0, 10)
		, 10, pdf.getCurrPageHeight() - 120, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line8") + res->squarePrice.getValue(""), 10, pdf.getCurrPageHeight() - 130, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line9") + res->area.getValue(""), 10, pdf.getCurrPageHeight() - 140, page0);
	std::string strfloat = std::to_string(res->primeRate.getValue({}));
	std::string strfloat2 = strfloat.substr(0, strfloat.find('.') + 3);
	std::map<std::string, std::string> imap;
	imap.insert(std::make_pair<std::string, std::string>("1.00", ZH_WORDS_GETTER("supplementrecepit.reprint2.func1")));
	imap.insert(std::make_pair<std::string, std::string>("2.00", ZH_WORDS_GETTER("supplementrecepit.reprint2.func2")));
	imap.insert(std::make_pair<std::string, std::string>("3.00", ZH_WORDS_GETTER("supplementrecepit.reprint2.func3")));
	imap.insert(std::make_pair<std::string, std::string>("4.00", ZH_WORDS_GETTER("supplementrecepit.reprint2.func4")));
	imap.insert(std::make_pair<std::string, std::string>("5.00", ZH_WORDS_GETTER("supplementrecepit.reprint2.func5")));
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line10") + imap[strfloat2], 10, pdf.getCurrPageHeight() - 150, page0);
	strfloat = std::to_string(res->payableAmount.getValue({}));
	strfloat2 = strfloat.substr(0, strfloat.find('.') + 3);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line11") + strfloat2, 10, pdf.getCurrPageHeight() - 160, page0);
	strfloat = std::to_string(res->discountAmount.getValue({}));
	strfloat2 = strfloat.substr(0, strfloat.find('.') + 3);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line12") + strfloat2, 10, pdf.getCurrPageHeight() - 170, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line13") + res->remark.getValue(""), 10, pdf.getCurrPageHeight() - 180, page0);
	pdf.drawText("**************************", 10, pdf.getCurrPageHeight() - 190, page0);
	strfloat = std::to_string(res->receivedAmount.getValue({}));
	strfloat2 = strfloat.substr(0, strfloat.find('.') + 3);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line14") + strfloat2, 10, pdf.getCurrPageHeight() - 200, page0);
	pdf.drawText(ZH_WORDS_GETTER("supplementrecepit.reprint2.line15") + res->cashierName.getValue({}), 10, pdf.getCurrPageHeight() - 210, page0);

	pdf.drawText("**************************", 10, pdf.getCurrPageHeight() - 320, page0);

	auto buff = pdf.saveDocToMem();
	const char* charData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(charData, buff.size());

	auto response = createResponse(Status::CODE_200, fstring);
	std::string filename = "rp-recepit2-" + SimpleDateTimeFormat::format() + ".pdf";
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);

	return response;
}