#pragma once

#ifndef TRACKRECORDDAO_H_
#define TRACKRECORDDAO_H_


#include "BaseDAO.h"
#include "../../domain/do/applydiscount/TrackRecordDO.h"
#include "../../domain/query/applydiscount/TrackRecordQuery.h"

// 数据库操作实现
class TrackRecordDAO : public BaseDAO {
public:
	// 通过ID查询数据
	PtrTrackRecordDO getTrackRecordDetailById(std::string ardr_id);
	// 插入数据
	int insert(const TrackRecordDO& iObj);
	// 通过ID删除数据(多个删除）
	int deleteTrackRecordById(std::string ardr_id);
	// 通过ID删除数据(单个删除)
	int deleteTrackRecordById(const TrackRecordDO& dObj);
};


#endif // !TRACKRECORDDAO_H_
