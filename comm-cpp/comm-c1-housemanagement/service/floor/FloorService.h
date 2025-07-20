#pragma

#ifndef _FLOOR_SERVICE_
#define _FLOOR_SERVICE_

#include "domain/vo/floor/FloorVO.h"
#include "domain/query/floor/FloorQuery.h"
#include "domain/dto/floor/FloorDTO.h"


class FloorService {
public:
	//分页查询数据
	FloorPageDTO::Wrapper listAll(const FloorQuery::Wrapper& query);
	//通过楼ID查询单个数据
	FloorDTO::Wrapper getById(std::string floor_id);
	//插入楼栋数据
	bool insert(const FloorAddDTO& dto);
	// 保存数据
	std::string saveData(const FloorAddDTO::Wrapper& dto);
	// 修改楼栋数据
	bool update(const FloorDTO& dto);
	// 修改数据
	bool updateData(const FloorDTO::Wrapper& dto);
	// 通过ID删除楼栋数据
	bool removeDate(std::string id);




};



#endif