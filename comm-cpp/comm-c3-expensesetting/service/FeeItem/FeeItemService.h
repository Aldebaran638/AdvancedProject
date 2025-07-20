#pragma once
#ifndef _FEEITEM_SERVICE_
#define _FEEITEM_SERVICE_

#include "../../domain/vo/FeeItemlogVO.h"
#include "../../domain/query/FeeItemQuery.h"
#include "../../domain/dto/FeeItemDTO.h"

/**
 * 费用项服务类
 */
class FeeItemService
{
public:
	// 分页查询所有数据
	FeeItemPageDTO::Wrapper listAll(const FeeItemQuery::Wrapper& query);

	//// 保存数据
	std::string saveData(const FeeItemAddDTO::Wrapper& dto);

	//// 修改数据
	bool updateData(const FeeItemModifyDTO::Wrapper& dto);

	//// 通过 ID 删除数据
	bool removeData(const FeeItemDeleteDTO::Wrapper& dto);
};

#endif // !_FEEITEM_SERVICE_
