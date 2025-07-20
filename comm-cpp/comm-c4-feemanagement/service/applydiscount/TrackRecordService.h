#pragma once

#ifndef TRACKRECORDSERVICE_H_
#define TRACKRECORDSERVICE_H_


#include "domain/dto/applydiscount/TrackRecordDTO.h"
#include "domain/query/applydiscount/TrackRecordQuery.h"
#include "domain/vo/applydiscount/TrackRecordVO.h"

// 服务实现
class TrackRecordService {
public:
	// 通过ID查询单个数据
	TrackRecordDTO::Wrapper getById(std::string id);
	// 保存数据
	std::string saveData(const TrackRecordADDDTO::Wrapper& dto);
	// 通过ID删除单个数据
	bool deleteData(const oatpp::List<oatpp::String>& ids);
	// 通过ID删除数据
	int removeData(const TrackRecordDeleteDTO::Wrapper& dto, const PayloadDTO& payload);
};


#endif // !TRACKRECORDSERVICE_H_
