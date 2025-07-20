#include "stdafx.h"
#include "TaskDetailService.h"
#include "../../dao/task-detail/TaskDetailDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"

TaskDetailGetDTO::Wrapper TaskDetailService::getById(std::string id)
{
	// 查询数据
	TaskDetailDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = TaskDetailGetDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, repairId, RepairId, repairType, RepairType, repairTypeTxt, RepairTypeTxt, repairName, RepairName, tel, Tel, repairObjName, RepairObjName, appointmentTime, AppointmentTime, state, State, stateTxt, StateTxt, context, Context, createTime, CreateTime);

	//组装超时时间
	{
		std::tm tm = {};
		std::istringstream ss(dto->appointmentTime ? dto->appointmentTime->c_str() : "");
		ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
		if (!ss.fail())
		{
			std::time_t t = std::mktime(&tm);
			t += 24 * 60 * 60;
			std::tm* timeout_tm = std::localtime(&t);
			char buf[20];
			std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeout_tm);
			dto->timeoutTime = buf;
		}
		else
		{
			dto->timeoutTime = "";
		}
	}

	// 组装提单时长
	{
		std::tm tm = {};
		std::istringstream ss(dto->createTime ? dto->createTime->c_str() : "");
		ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
		if (!ss.fail())
		{
			std::time_t create = std::mktime(&tm);
			std::time_t now = std::time(nullptr);
			long diff = static_cast<long>(difftime(now, create));
			dto->time = std::to_string(diff);
		}
		else
		{
			dto->time = "";
		}
	}

	return dto;
}

std::string TaskDetailService::saveData(const TaskDetailAddDTO::Wrapper& dto)
{
	// 组装DO数据
	TaskDetailDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RepairId, repair_id, StaffName, staff_name, Context, context);
	// 生成雪花ID
	SnowFlake sf(1, 1);
	data.setRuId("83" + std::to_string(sf.nextId() % 10000000000000000));
	data.setBId(std::to_string(sf.nextId() % 1000000000000000000));
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	TaskDetailDAO dao;
	return dao.insert_r_repair_user(data) == 1 ? data.getRepairId() : "";
}

TaskDetailExportDetailDTO::Wrapper TaskDetailService::getExportTaskDetail(const TaskDetailQuery::Wrapper& query)
{
	TaskDetailDAO dao;
	// 执行数据查询
	auto data = dao.selectExportTaskDetail_r_repair_pool(query);
	// 没有查询到数据
	if (!data)
	{
		return nullptr;
	}

	// DO数据转为DTO
	auto dto = TaskDetailExportDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, data, repair_id, RepairId, repair_name, RepairName, tel, Tel, repair_obj_name, RepairObjName,
		task_context, TaskContext, repair_type, RepairTypeName, maintenance_type, MaintenanceTypeName);
	return dto;
}

TaskDetailExportCirculationPageDTO::Wrapper TaskDetailService::getExportCirculate(const TaskDetailQuery::Wrapper& query)
{
	//构建返回对象
	auto result = TaskDetailExportCirculationPageDTO::createShared();

	// 查询数据总条数
	TaskDetailDAO dao;
	uint64_t count = dao.count_r_repair_user(query);
	if (count <= 0)
	{
		return result;
	}
	result->total = count;
	// 执行数据查询
	list<TaskDetailDO> data = dao.selectExportCirculate_r_repair_user(query);

	// DO数据转为DTO
	for (TaskDetailDO sub : data)
	{
		auto dto = TaskDetailExportCirculationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, staff_name, StaffName, state, State, start_time, StartTime, cost, Cost, user_context, UserContext);
		result->addData(dto);
	}
	return result;
}