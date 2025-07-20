#include "stdafx.h"
#include "HouseFileController.h"
#include <iostream>

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"




StringJsonVO::Wrapper HouseFileController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "file", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "nickname", -1);
	//API_MULTIPART_CONFIG_MEMO(reader, "age", -1);

	// 3 读取数据
	request->transferBody(&reader);
	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 解析数据
	/* TODO: 解析的数据具体逻辑，需要根据你的业务需求来，下面是使用示例而已。 */
	/* 获取表单数据 */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "nickname", nickname);
	API_MULTIPART_PARSE_FORM_FIELD_NUM(container, "age", Int32, age, stoi);
	/* 打印表单数据 */
	if (nickname) OATPP_LOGD("Multipart", "nickname='%s'", nickname.getValue({}).c_str());
	if (age) OATPP_LOGD("Multipart", "age=%d", age.getValue({}));
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
		/* 测试将文件保存到磁盘上面 */
		/*string fullPath = "public/static/file/" + filename;
		file.saveToFile(fullPath.c_str());*/


		/* 测试上传到FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
	}

	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->success("inport success");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> HouseFileController::execDownloadFile(const String& filename)
{
	// 构建文件全路径
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}

