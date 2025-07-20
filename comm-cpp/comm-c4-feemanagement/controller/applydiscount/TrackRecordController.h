#pragma once

#ifndef _TRACKRECORDCONTROLLER_H_
#define _TRACKRECORDCONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/applydiscount/TrackRecordDTO.h"
#include "domain/query/applydiscount/TrackRecordQuery.h"
#include "domain/vo/applydiscount/TrackRecordVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TrackRecordController : public oatpp::web::server::api::ApiController {
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TrackRecordController);
public: // 定义接口
	// 1.1 查看跟踪记录详情描述
	ENDPOINT_INFO(queryTrackRecordDetail) {
		// 接口描述
		info->summary = ZH_WORDS_GETTER("trackRecord.get.query");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 接口参数
		API_DEF_ADD_PAGE_PARAMS();
		// 接口返回参数
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "ardr_id", ZH_WORDS_GETTER("apply_room_discount_record.field.ardr_id"), "352024022005714746", true);
	}
	// 1.2 定义跟踪记录查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/c4-applydiscount/track-record-query", queryTrackRecordDetail, QUERY(String, ardr_id), execQueryTrackRecordDetail(ardr_id));

	// 2.1 添加跟踪记录描述
	ENDPOINT_INFO(addTrackRecord) {
		// 接口描述
		info->summary = ZH_WORDS_GETTER("trackRecord.post.add");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 接口参数
		API_DEF_ADD_PAGE_PARAMS();
		// 接口返回参数
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 2.2 定义跟踪记录添加接口处理
	ENDPOINT(API_M_POST, "/c4-applydiscount/track-record-add", addTrackRecord, BODY_DTO(TrackRecordADDDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddTrackRecord(dto, authObject->getPayload()));
	}

	// 3.1 删除跟踪记录描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("trackRecord.delete.del"), deleteTrackRecord, ListJsonVO<String>::Wrapper);
	// 3.2 定义跟踪记录删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/c4-applydiscount/track-record-delete", deleteTrackRecord, BODY_DTO(TrackRecordDeleteDTO::Wrapper, dto), execDeleteTrackRecord(dto, authObject->getPayload()));

private: // 定义接口执行函数
	// 1.查看跟踪记录详情
	TrackRecordJsonVO::Wrapper execQueryTrackRecordDetail(const String& ardr_id);
	// 2.添加跟踪记录
	StringJsonVO::Wrapper execAddTrackRecord(const TrackRecordADDDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.删除跟踪记录
	StringJsonVO::Wrapper execDeleteTrackRecord(const TrackRecordDeleteDTO::Wrapper& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController)


#endif // _TRACKRECORDCONTROLLER_H_