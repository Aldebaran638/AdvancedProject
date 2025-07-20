#pragma once
#ifndef _FORCEBACKSERVICE_H_
#define _FORCEBACKSERVICE_H_
#include "domain/dto/force-back/ForceBackDTO.h"
#include "domain/query/force-back/ForceBackQuery.h"
#include "domain/vo/force-back/ForceBackVO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ForceBackService
{
public:
	// 分页查询所有数据
	ForceBackPageDTO::Wrapper ForceBack_listAll(const ForceBackQuery::Wrapper& query);
	// 保存数据 
	std::string ForceBacak_saveData(const ForceBackAddDTO::Wrapper& dto);
	// 修改数据 
	bool ForceBack_updateData(const ForceBackModifyDTO::Wrapper& dto);
};

#endif // !_FORCEBACKSERVICE_H_