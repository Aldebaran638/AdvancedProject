#ifndef _REPAIRSETTINGSERVICE_H_
#define _REPAIRSETTINGSERVICE_H_
#include "domain/vo/repair-setting-type/RepairSettingTypeVO.h"
#include "domain/query/repair-setting-type/RepairSettingTypeQuery.h"
#include "domain/dto/repair-setting-type/RepairSettingTypeDTO.h"

/**
 * 报修类型设置的查询，添加，修改的实现
 */
class RepairSettingService
{
public:
	// 分页查询所有数据
	RepairSettingGetPageDTO::Wrapper RepairSettingTypeListAll(const RepairSettingGetQuery::Wrapper& query);
	// 添加数据
	std::string RepairSettingTypeAddData(const RepairSettingAddDTO::Wrapper& dto);
	// 修改数据
	bool RepairSettingTypeModifyData(const RepairSettingModifyDTO::Wrapper& dto);
	// 通过ID删除数据
	bool RepairSettingTypeDeleteData(const oatpp::List<oatpp::String>& ids);
};

#endif // !_REPAIRSETTINGSERVICE_H_

