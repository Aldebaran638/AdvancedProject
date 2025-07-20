/*
 Copyright Zero One Star. All rights reserved.

 @Author: ����Ҳ����
 @Date: 2025/05/17 20:01:50

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
#include "ArredetController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/ArredetServeice.h"
#include "../../domain/do/arredet/ArreDetDO.h"
#include "../../domain/dto/arredet/ArreDetDTO.h"
#include "ExcelComponent.h"
#include "Macros.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

ArredetPageJsonVO::Wrapper ArredetController::execQueryAll(const ArredetQuery::Wrapper& query)
{
	return{};
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>ArredetController::execDownloadFile(const String& filename)
{
	//// ����Service
	//ArredetService service;
	//auto query = ArredetQuery::createShared();
	//auto dtoList = service.QueryAll(query);

	//// ���DTO�Ƿ�Ϊ��
	//if (dtoList.empty()) {
	//	return createResponse(Status::CODE_404, "Failed to generate report: DTO is null");
	//}
	//// ת��Ϊ��ά����
	//std::vector<std::vector<std::string>> data;
	//std::vector<std::string> header = {
	//	ZH_WORDS_GETTER("qcd.id"),
	//	ZH_WORDS_GETTER("qcd.create_name"),
	//	ZH_WORDS_GETTER("qcd.create_by"),
	//	ZH_WORDS_GETTER("qcd.create_date"),
	//	ZH_WORDS_GETTER("qcd.update_name"),
	//	ZH_WORDS_GETTER("qcd.update_by"),
	//	ZH_WORDS_GETTER("qcd.update_date"),
	//	ZH_WORDS_GETTER("qcd.sys_org_code"),
	//	ZH_WORDS_GETTER("qcd.sys_company_code"),
	//	ZH_WORDS_GETTER("qcd.qm_qa_code"),
	//	ZH_WORDS_GETTER("qcd.qm_qa_name")
	//};

	//data.push_back(header);

	//// ��DTO������䵽��ά������
	//for (const auto& dto : dtoList) {
	//	std::vector<std::string> row;
	//	row.push_back(dto->id);
	//	row.push_back(dto->room);
	//	row.push_back(dto->ow);
	//	row.push_back(dto->owt);
	//	row.push_back(dto->area);
	//	row.push_back(dto->ei);
	//	row.push_back(dto->st);
	//	row.push_back(dto->ad);
	//	row.push_back(dto->aa);
	//	data.push_back(row);
	//}

	//// д��Excel�ļ�
	//ExcelComponent excle;
	//auto buff = excle.writeVectorToBuff(ZH_WORDS_GETTER("qcd.name"), data);
	//// ����Excel�ļ�
	//const char* tsData = reinterpret_cast<const char*>(buff.data());
	//auto fstring = String(tsData, buff.size());
	//// �ж��Ƿ�ɹ�
	//if (!fstring)
	//{
	//	std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
	//	return createResponse(Status::CODE_404, "File Not Found");
	//}

	//// ������Ӧͷ
	//auto response = createResponse(Status::CODE_200, fstring);
	//std::time_t now = std::time(0);
	//std::tm* localTime = std::localtime(&now);

	//// �ֶ���ʽ��������
	//char buffer[9];  // �洢��ʽ������ַ���
	//std::strftime(buffer, sizeof(buffer), "%Y%m%d", localTime);

	//response->putHeader("Content-Type", "application/vnd.ms-excel");
	//response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue("") + "_" + buffer + ".xlsx");

	//// Ӱ��ɹ����
	//return response;
	return{};
}

