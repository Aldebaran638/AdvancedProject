#include "stdafx.h"
#include "ExRmremindersService.h"
#include "../../dao/arrears_reminders/ExRmremindersDAO.h"
#include "../../domain/dto/arrears_reminders/ExRmremindersDTO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
//导出数据
std::list<ExRmremindersDTO::Wrapper> ExRmremindersService::getData()
{
	ExRmremindersDAO dao;
	//确保能导出多条数据 list作为返回值
	auto res = dao.getAll();

	//1.检查查询结果是否为空 ,  很重要***
	if (res.empty()) {
		OATPP_LOGE("OweInformationService", "No data found in ba_qm_sta table");
		return {}; // 返回空列表
	}

	// 2. 将 DO 列表转换为 DTO 列表
	std::list<ExRmremindersDTO::Wrapper> dtoList;
	for (const auto& doo : res) {
		auto dto = ExRmremindersDTO::createShared();
		dto->ofc_id = doo.getOfc_id();
		dto->owner_name = doo.getOwner_name();
		dto->payer_obj_name = doo.getPayer_obj_name();
		dto->fee_name = doo.getFee_name();
		dto->amountd_owed = doo.getAmountd_owed();
		dto->callable_way = doo.getCallable_way();
		dto->start_time = doo.getStart_time();
		dto->staff_name = doo.getStaff_name();
		dto->state = doo.getState();
		dto->create_time = doo.getCreate_time();
		dto->remark = doo.getRemark();
		
		dtoList.push_back(dto); // 将 DTO 添加到列表中
	}
	//在service层返回dto传输对象
	return dtoList;
}
// 通过ofc_id删除数据
bool ExRmremindersService::removeData(const oatpp::List<oatpp::String>& ofc_id)
{
	ExRmremindersDAO dao;
	// 开启事务
	dao.getSqlSession()->beginTransaction();
	// 循环删除
	int rows = 0;
	for (auto one : *ofc_id.get())
	{
		rows += dao.deleteById(one.getValue({}));
	}
	// 判断是否全部删除成功
	if (rows == ofc_id->size()) {
		// 提交事务
		dao.getSqlSession()->commitTransaction();
		return true;
	}
	// 回滚事务
	dao.getSqlSession()->rollbackTransaction();
	return false;
}

