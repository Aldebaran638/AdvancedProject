#include "stdafx.h"
#include "YyycDisTypesService.h"
#include "../../dao/discount_types/YyycDisTypesDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../../arch-demo/Macros.h"

bool YyycDisTypesService::updateData(const YyycDisTypesDTO::Wrapper& dto)
{
	// 组装DO数据
	YyycDisTypesDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Type_Name, type_name, Type_Desc, type_desc, Type_Id, type_id);
	//// 设置优惠类型
	//data.setType_Name(dto->type_name.getValue({}));
	//// 设置优惠描述
	//data.setType_Desc(dto->type_desc.getValue({}));
	// 执行数据修改
	YyycDisTypesDAO dao;
	return dao.update(data) == 1;
}

bool YyycDisTypesService::removeData(const oatpp::List<oatpp::String>& ids)
{
	YyycDisTypesDAO dao;
	// 开启事务
	dao.getSqlSession()->beginTransaction();
	// 循环删除
	int rows = 0;
	for (auto one : *ids.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// 判断是否全部删除成功
	if (rows == ids->size()) {
		// 提交事务
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// 回滚事务
	dao.getSqlSession()->rollbackTransaction();
	return false;
}
