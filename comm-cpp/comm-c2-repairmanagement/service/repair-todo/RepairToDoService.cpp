#include "stdafx.h"
#include "RepairToDoService.h"
#include "../../dao/repair-todo/RepairToDoDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include <string>
#include <FastDfsClient.h>
#include <iostream>
using namespace std;


RepairToDoPageDTO::Wrapper RepairToDoService::listAll(const RepairToDoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairToDoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	RepairToDoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RepairToDoDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RepairToDoDO sub : result)
	{
		auto dto = RepairToDoQueryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_id,RepairId,repair_obj_name, RepairObjName, repair_type_name, RepairTypeName, repair_name, RepairName, tel, Tel, appointment_time, AppointmentTime, state, State, pre_staff_id, PreStaffId, pre_staff_name, PreStaffName);		
		if (sub.getState() == "1100") dto->state_detail = ZH_WORDS_GETTER("repairtodo.query.state-1100");
		else if (sub.getState() == "1200") dto->state_detail = ZH_WORDS_GETTER("repairtodo.query.state-1200");
		else if (sub.getState() == "1300") dto->state_detail = ZH_WORDS_GETTER("repairtodo.query.state-1300");
		else if (sub.getState() == "2001") dto->state_detail = ZH_WORDS_GETTER("repairtodo.query.state-2001");

		pages->addData(dto);
	}
	return pages;
}

RepairToDoQueryAllRepairTypePageDTO::Wrapper RepairToDoService::listAllRepairType(const RepairToDoRepairTypeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairToDoQueryAllRepairTypePageDTO::createShared();
	RepairToDoDAO dao;

	list<RepairToDoDO> result = dao.selectAllRepairType(query);
	// 将DO转换成DTO
	for (RepairToDoDO sub : result)
	{
		auto dto = RepairToDoQueryAllRepairTypeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, repair_type_name, RepairTypeName,repair_type,RepairType);
		pages->addData(dto);
	}
	return pages;
}

RepairToDoQueryAllStaffPageDTO::Wrapper RepairToDoService::listAllStaffByStaffType(const RepairToDoStaffNameQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RepairToDoQueryAllStaffPageDTO::createShared();
	RepairToDoDAO dao;
	list<RepairToDoDO> result = dao.selectAllStaffByRepairType(query);
	// 将DO转换成DTO
	for (RepairToDoDO sub : result)
	{
		auto dto = RepairToDoQueryAllStaffDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,staff_name,StaffName,staff_id,RuStaffId);
		pages->addData(dto);
	}
	return pages;
}


//转单操作
bool RepairToDoService::ModifyDataToTransferBill(const RepairToDoUpdateDTO::Wrapper& dto)
{
	// 组装修改DO数据
	RepairToDoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Context, context, RuStaffId, staff_id,RepairId,repair_id);
	// 执行数据查询和修改
	RepairToDoDAO dao;
	// 通过repair_id查询r_repair_user表中数据
	auto select_data = dao.selectByRepairId(data.getRepairId());
	// 通过staff_name查询staff_id
	auto select_staff_name = dao.selectStaffNameByStaffId(data.getRuStaffId());

	auto select_repair_pool = dao.select_repair_pool_modify(data.getRepairId());

	if (!select_data ||!select_staff_name ||!select_repair_pool)
		return false;
	data.setEndTime(SimpleDateTimeFormat::format());

	//组装新增数据
	RepairToDoDO insert_data, insert_data1,insert_data2;

	insert_data.setPreStaffId(select_data->getRuStaffId());
	insert_data.setPreStaffName(select_data->getRuStaffName());
	insert_data.setPreRuId(select_data->getRuId());
	insert_data.setCommunityId(select_data->getCommunityId());
	insert_data.setCreateTime(SimpleDateTimeFormat::format());
	insert_data.setStartTime(SimpleDateTimeFormat::format());
	insert_data.setRepairEvent("auditUser");
	insert_data.setRuState("10001");
	SnowFlake snowFlake(1,1);
	insert_data.setRuId(to_string(snowFlake.nextId()));
	insert_data.setRepairId(data.getRepairId());
	insert_data.setBId(to_string(snowFlake.nextId()));
	insert_data.setRuStatusCd("0");
	insert_data.setRuStaffId(data.getRuStaffId());	    //还要再查询
	insert_data.setRuStaffName(select_staff_name->getRuStaffName());
	insert_data1.setRuId(select_data->getRuId());
	insert_data1.setRepairId(data.getRepairId());
	insert_data1.setBId(select_data->getBId());
	insert_data1.setCommunityId(select_data->getCommunityId());
	insert_data1.setCreateTime(SimpleDateTimeFormat::format());
	insert_data1.setContext(data.getContext());
	insert_data1.setRuStaffId(select_data->getRuStaffId());
	insert_data1.setRuStaffName(select_data->getRuStaffName());
	insert_data1.setPreStaffId(select_data->getPreStaffId());
	insert_data1.setPreStaffName(select_data->getPreStaffName());
	insert_data1.setStartTime(select_data->getStartTime());
	insert_data1.setEndTime(SimpleDateTimeFormat::format());
	insert_data1.setPreRuId(select_data->getPreRuId());

	insert_data2.setRepairId(data.getRepairId());
	insert_data2.setBId(to_string(snowFlake.nextId()));
	insert_data2.setCommunityId(select_repair_pool->getCommunityId());
	insert_data2.setRepairType(select_repair_pool->getRepairType());
	insert_data2.setRepairName(select_repair_pool->getRepairName());
	insert_data2.setTel(select_repair_pool->getTel());
	insert_data2.setAppointmentTime(select_repair_pool->getAppointmentTime());
	insert_data2.setContext(select_repair_pool->getContext());
	insert_data2.setCreateTime(SimpleDateTimeFormat::format());
	insert_data2.setState(select_repair_pool->getState());
	insert_data2.setOperate("DEL");
	insert_data2.setRepairObjType(select_repair_pool->getRepairObjType());
	insert_data2.setRepairObjId(select_repair_pool->getRepairObjId());
	insert_data2.setRepairObjName(select_repair_pool->getRepairObjName());
	insert_data2.setMaintenanceType(select_repair_pool->getMaintenanceType());
	insert_data2.setRepairChannel(select_repair_pool->getRepairChannel());
	insert_data2.setRepairMaterials(select_repair_pool->getRepairMaterials());
	insert_data2.setRepairFee(select_repair_pool->getRepairFee());
	insert_data2.setPayType(select_repair_pool->getPayType());
	if (dao.insert_business_repair_user1_modify(insert_data1) != 1 ||
		dao.insert_business_repair_pool_modify(insert_data2) != 1)return false;
	insert_data2.setState("1300");
	insert_data2.setOperate("ADD");
	insert_data1.setRuId(to_string(snowFlake.nextId()));
	dao.update_repair_pool_modify(data);
	return dao.insert_business_repair_pool_modify(insert_data2)  &&dao.insert_business_repair_user2_modify(insert_data)==1  && dao.update_repair_user_modify(data) == 1 && dao.insert_repair_user_modify(insert_data) == 1;
}

//暂停操作
bool RepairToDoService::ModifyDataToSuspend(const RepairToDoUpdateToSuspendDTO::Wrapper& dto)
{
	// 组装修改DO数据
	RepairToDoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Context, context, RepairId, repair_id);
	// 执行数据查询和修改
	RepairToDoDAO dao;
	// 通过repair_id查询r_repair_user表中数据
	auto select_data = dao.selectByRepairId(data.getRepairId());
	if (!select_data)
		return false;
	data.setEndTime(SimpleDateTimeFormat::format());

	//组装新增数据
	RepairToDoDO insert_data;
	SnowFlake snowFlake(1, 1);
	insert_data.setRuId(to_string(snowFlake.nextId()));
	insert_data.setRepairId(data.getRepairId());
	insert_data.setCommunityId(select_data->getCommunityId());
	insert_data.setBId(to_string(snowFlake.nextId()));
	insert_data.setContext(data.getContext());
	insert_data.setRuStaffId(select_data->getRuStaffId());
	insert_data.setRuStaffName(select_data->getRuStaffName());

	insert_data.setPreStaffId(select_data->getRuStaffId());
	insert_data.setPreStaffName(select_data->getRuStaffName());
	insert_data.setPreRuId(select_data->getPreRuId());

	insert_data.setCreateTime(SimpleDateTimeFormat::format());
	insert_data.setStartTime(SimpleDateTimeFormat::format());
	insert_data.setEndTime(SimpleDateTimeFormat::format());

	dao.update_repair_pool_suspend(data);
	return dao.insert_repair_user_suspend(insert_data) == 1;
}
//退单操作
bool RepairToDoService::ModifyDataToRemove(const RepairToDoUpdateToRemoveDTO::Wrapper& dto)
{
	// 组装修改DO数据
	RepairToDoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Context, context, RepairId, repair_id);
	// 执行数据查询和修改
	RepairToDoDAO dao;
	// 通过repair_id查询r_repair_user表中数据
	auto select_data = dao.selectRemoveData(data.getRepairId());
	// 通过staff_name查询staff_id
	auto select_repair_pool = dao.select_repair_pool_modify(data.getRepairId());
	if (!select_data || select_data->getPreStaffId() == "-1")
		return false;
	data.setEndTime(SimpleDateTimeFormat::format());

	//组装新增数据
	RepairToDoDO insert_data, insert_data1, insert_data2;
	SnowFlake snowFlake(1, 1);
	insert_data.setRuId(to_string(snowFlake.nextId()));
	insert_data.setBId(to_string(snowFlake.nextId()));
	insert_data.setCommunityId(select_data->getCommunityId());
	insert_data.setCreateTime(SimpleDateTimeFormat::format());
	insert_data.setStartTime(SimpleDateTimeFormat::format());
	insert_data.setRuState("10001");
	insert_data.setRuStatusCd("0");
	insert_data.setRepairId(data.getRepairId());
	insert_data.setRuStaffId(select_data->getPreStaffId());
	insert_data.setRuStaffName(select_data->getPreStaffName());
	insert_data.setPreStaffId(select_data->getRuStaffId());
	insert_data.setPreStaffName(select_data->getRuStaffName());
	insert_data.setRepairEvent("auditUser");
	insert_data.setPreRuId(select_data->getRuId());

	insert_data1.setRuId(select_data->getRuId());
	insert_data1.setRepairId(data.getRepairId());
	insert_data1.setBId(select_data->getBId());
	insert_data1.setCommunityId(select_data->getCommunityId());
	insert_data1.setCreateTime(SimpleDateTimeFormat::format());
	insert_data1.setState("10003");
	insert_data1.setContext(data.getContext());
	insert_data1.setOperate("ADD");
	insert_data1.setRuStaffId(select_data->getRuStaffId());
	insert_data1.setRuStaffName(select_data->getRuStaffName());
	insert_data1.setPreStaffId(select_data->getPreStaffId());
	insert_data1.setPreStaffName(select_data->getPreStaffName());
	insert_data1.setStartTime(select_data->getStartTime());
	insert_data1.setEndTime(SimpleDateTimeFormat::format());
	insert_data1.setRepairEvent("auditUser");
	insert_data1.setPreRuId(select_data->getPreRuId());

	insert_data2.setRepairId(data.getRepairId());
	insert_data2.setBId(to_string(snowFlake.nextId()));
	insert_data2.setCommunityId(select_repair_pool->getCommunityId());
	insert_data2.setRepairType(select_repair_pool->getRepairType());
	insert_data2.setRepairName(select_repair_pool->getRepairName());
	insert_data2.setTel(select_repair_pool->getTel());
	insert_data2.setAppointmentTime(select_repair_pool->getAppointmentTime());
	insert_data2.setContext(select_repair_pool->getContext());
	insert_data2.setCreateTime(SimpleDateTimeFormat::format());
	insert_data2.setState(select_repair_pool->getState());
	insert_data2.setOperate("DEL");
	insert_data2.setRepairObjType(select_repair_pool->getRepairObjType());
	insert_data2.setRepairObjId(select_repair_pool->getRepairObjId());
	insert_data2.setRepairObjName(select_repair_pool->getRepairObjName());
	insert_data2.setMaintenanceType(select_repair_pool->getMaintenanceType());
	insert_data2.setRepairChannel(select_repair_pool->getRepairChannel());
	insert_data2.setRepairMaterials(select_repair_pool->getRepairMaterials());
	insert_data2.setRepairFee(select_repair_pool->getRepairFee());
	insert_data2.setPayType(select_repair_pool->getPayType());
	dao.update_repair_pool_remove(data);
	if(dao.update_repair_user_remove(data) != 1)return false;
	dao.insert_business_repair_user_remove(insert_data1);
	dao.insert_business_repair_pool_remove(insert_data2);

	insert_data1.setRuId(to_string(snowFlake.nextId()));
	insert_data1.setState("10001");

	insert_data1.setRuStaffId(select_data->getPreStaffId());
	insert_data1.setRuStaffName(select_data->getPreStaffName());
	insert_data1.setPreStaffId(select_data->getRuStaffId());
	insert_data1.setPreStaffName(select_data->getRuStaffName());

	insert_data1.setPreRuId(select_data->getRuId());
	insert_data2.setState("1200");
	insert_data2.setOperate("ADD");

	return 	dao.insert_business_repair_pool_remove(insert_data2)==1 && dao.insert_business_repair_user2_remove(insert_data1) ==1  && dao.insert_repair_user_remove(insert_data) == 1;
}

//办结操作
bool RepairToDoService::ModifyDataToFinish(const RepairToDoUpdateToFinishDTO::Wrapper& dto)
{
	SnowFlake snowFlake(1, 1);
	// 组装修改DO数据
	RepairToDoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, RepairId, repair_id, PayType, pay_type, IsMaterial, is_material, TotalPrice, total_price, Context, context, RoomId, room_id);
	// 获取维修前照片路径列表
	auto photoPaths = dto->repair_before_photo_path;
	// 获取维修后照片路径列表
	auto photoAfterPaths = dto->repair_after_photo_path;
	if (photoPaths->size() == 0 || photoAfterPaths->size() == 0)return false;
	// 初始化FastDFS客户端
	FastDfsClient dfsClient("39.103.62.65");
	// 存储上传后的路径
	vector<string> fileBeforeNames;
	// 存储上传后的路径
	vector<string> fileAfterNames;
	// 查找报修对象类型
	RepairToDoDAO dao;
	// 新增数据
	RepairToDoDO insert_data1, insert_data2, insert_data3;

	auto repair_obj_type = dao.select_repair_obj_type_by_repair_id(data.getRepairId());
	data.setEndTime(SimpleDateTimeFormat::format());
	auto select_data = dao.selectRemoveData(data.getRepairId());
	auto select_repair_pool = dao.select_repair_pool_modify(data.getRepairId());
	if (!select_data || !select_repair_pool)
		return false;
	data.setUserId(select_data->getRuStaffId());

	auto& materialList = *dto->materials;


	// 依次上传文件
	for (const auto& oatppPath : *photoPaths) {
		try {
			std::string filePath = oatppPath;
			std::string dfsPath = dfsClient.uploadFile(filePath);
			fileBeforeNames.push_back(dfsPath);
			OATPP_LOGI("Upload", "Uploaded to: %s", dfsPath.c_str());
		}
		catch (const std::exception& e) {
			OATPP_LOGE("Upload", "Failed to upload file: %s", e.what());
		}
	}

	for (const auto& oatppPath : *photoAfterPaths) {
		try {
			std::string filePath = oatppPath;
			std::string dfsPath = dfsClient.uploadFile(filePath);
			fileAfterNames.push_back(dfsPath);
			OATPP_LOGI("Upload", "Uploaded to: %s", dfsPath.c_str());
		}
		catch (const std::exception& e) {
			OATPP_LOGE("Upload", "Failed to upload file: %s", e.what());
		}
	}
	//如果是房屋报修
	if (repair_obj_type.getRepairObjType() == "004") {
		if (dto->is_material=="1") {
			data.setMaintenanceType("1001");
			string repair_materials, repair_fee;
			for (const auto& item : materialList) {
				repair_materials += item->material_name + "*" + to_string(item->material_count) + ";";
				repair_fee += to_string(item->material_price) + "*" + to_string(item->material_count) + ";";
			}
			data.setRepairMaterials(repair_materials);
			data.setRepairFee(repair_fee);

			for (const auto& item : materialList) {
				auto select_resource = dao.select_resource_by_res_id_user_id(item->res_id, data.getUserId());

				if (item->material_count > stoi(select_resource.getStock())) {
					return false;
				}
				data.setRsurId(to_string(snowFlake.nextId()));

				data.setResId(item->res_id);
				data.setStock(to_string(stoi(select_resource.getStock()) - item->material_count));
				data.setStoreId(select_resource.getStoreId());
				data.setBId("-1");
				data.setCommunityId(select_data->getCommunityId());
				data.setQuantity(to_string(item->material_count));
				data.setStatusCd("0");
				data.setCreateUserId(select_data->getRuStaffId());
				data.setCreateUserName(select_data->getRuStaffName());
				data.setCreateTime(SimpleDateTimeFormat::format());
				data.setRemark(data.getContext());
				data.setResourceStoreName(item->material_name);
				data.setRecordState("2002");
				data.setUnitPrice(to_string(item->material_price));

				dao.insert_resource_store_use_record2_finish(data);
				dao.update_user_storehouse_finish(data);
			}
		}
		else data.setMaintenanceType("1002");
		insert_data1.setRuId(select_data->getRuId());
		insert_data1.setRepairId(data.getRepairId());
		insert_data1.setBId(to_string(snowFlake.nextId()));
		insert_data1.setCommunityId(select_data->getCommunityId());
		insert_data1.setCreateTime(SimpleDateTimeFormat::format());
		insert_data1.setState("10002");
		insert_data1.setContext(data.getContext());
		insert_data1.setOperate("ADD");
		insert_data1.setRuStaffId(select_data->getRuStaffId());
		insert_data1.setRuStaffName(select_data->getRuStaffName());
		insert_data1.setPreStaffId(select_data->getPreStaffId());
		insert_data1.setPreStaffName(select_data->getPreStaffName());
		insert_data1.setStartTime(select_data->getStartTime());
		insert_data1.setEndTime(SimpleDateTimeFormat::format());
		insert_data1.setRepairEvent("auditUser");
		insert_data1.setPreRuId(select_data->getPreRuId());

		insert_data2.setRepairId(data.getRepairId());
		insert_data2.setBId(to_string(snowFlake.nextId()));
		insert_data2.setCommunityId(select_repair_pool->getCommunityId());
		insert_data2.setRepairType(select_repair_pool->getRepairType());
		insert_data2.setRepairName(select_repair_pool->getRepairName());
		insert_data2.setTel(select_repair_pool->getTel());
		insert_data2.setAppointmentTime(select_repair_pool->getAppointmentTime());
		insert_data2.setContext(select_repair_pool->getContext());
		insert_data2.setCreateTime(SimpleDateTimeFormat::format());
		insert_data2.setState(select_repair_pool->getState());
		insert_data2.setOperate("DEL");
		insert_data2.setRepairObjType(select_repair_pool->getRepairObjType());
		insert_data2.setRepairObjId(select_repair_pool->getRepairObjId());
		insert_data2.setRepairObjName(select_repair_pool->getRepairObjName());
		insert_data2.setMaintenanceType(select_repair_pool->getMaintenanceType());
		insert_data2.setRepairChannel(select_repair_pool->getRepairChannel());
		insert_data2.setRepairMaterials(select_repair_pool->getRepairMaterials());
		insert_data2.setRepairFee(select_repair_pool->getRepairFee());
		insert_data2.setPayType(select_repair_pool->getPayType());

		//pay_fee插入数据

		//查找物业ID
		auto select_property_id = dao.select_property_id_by_staff_id(select_data->getRuStaffId());
		//查找费用项ID
		auto select_config_id = dao.select_config_id_by_communit_id(select_data->getCommunityId());

		auto FeeId = to_string(snowFlake.nextId());
		auto BId = to_string(snowFlake.nextId());
		insert_data3.setFeeId(FeeId);
		insert_data3.setBId(BId);
		insert_data3.setFeeTypeCd("888800010012");
		insert_data3.setCommunityId(select_data->getCommunityId());
		insert_data3.setPayerObjId(data.getRoomId());
		insert_data3.setIncomeObjId(select_property_id.getStoreId()); //物业ID
		insert_data3.setStartTime(SimpleDateTimeFormat::format());
		insert_data3.setEndTime(SimpleDateTimeFormat::format());
		insert_data3.setAmount(data.getTotalPrice());
		insert_data3.setUserId(select_data->getRuStaffId());
		insert_data3.setCreateTime(SimpleDateTimeFormat::format());
		insert_data3.setStatusCd("0");
		insert_data3.setFeeFlag("2006012");
		insert_data3.setState("2009001");
		insert_data3.setConfigId(select_config_id.getConfigId());
		insert_data3.setPayerObjType("3333");
		insert_data3.setBatchId("-1");
		insert_data3.setOperate("ADD");


		dao.insert_pay_fee_finish(insert_data3);
		dao.insert_business_pay_fee_finish(insert_data3);



		dao.noroom_update_repair_user_finish(data);


		if (data.getPayType() == ZH_WORDS_GETTER("repairtodo.pay.type1")) {
			data.setPayType("1");
		}
		else if (data.getPayType() == ZH_WORDS_GETTER("repairtodo.pay.type2")) {
			data.setPayType("2");
		}
		else if (data.getPayType() == ZH_WORDS_GETTER("repairtodo.pay.type3")) {
			data.setPayType("3");
		}
		else if (data.getPayType() == ZH_WORDS_GETTER("repairtodo.pay.type4")) {
			data.setPayType("4");
		}
		if (dto->is_material == "1")data.setState("1400");
		else data.setState("1800");
		dao.room_update_repair_pool_finish(data);
		dao.noroom_insert_business_repair_user_finish(insert_data1);


		insert_data1.setRuId(to_string(snowFlake.nextId()));

		insert_data1.setBId(to_string(snowFlake.nextId()));
		insert_data1.setRuState("10009");
		string TotalPrice;
		if (dto->is_material == "1") {

			TotalPrice += ZH_WORDS_GETTER("repairtodo.pay.discribe1") + dto->total_price + ZH_WORDS_GETTER("repairtodo.pay.discribe2");
		}
		insert_data1.setContext(TotalPrice);
		auto select_owner_id = dao.select_owner_id_by_room_id(data.getRoomId());
		if (!select_owner_id)return false;
		auto select_owner_name = dao.select_owner_name_by_owner_id(select_owner_id->getOwnerId());
		insert_data1.setRuStaffId(select_owner_id->getOwnerId());
		insert_data1.setRuStaffName(select_owner_name.getOwnerName());
		insert_data1.setPreStaffId(select_data->getRuStaffId());
		insert_data1.setPreStaffName(select_data->getRuStaffName());
		insert_data1.setPreRuId(select_data->getRuId());

		dao.insert_repair_user_modify(insert_data1);

		dao.noroom_insert_business_repair_user_finish(insert_data1);

		dao.noroom_insert_business_repair_pool_finish(insert_data2);
		insert_data2.setMaintenanceType(data.getMaintenanceType());
		insert_data2.setRepairMaterials(data.getRepairMaterials());
		if(dto->is_material=="1")insert_data2.setState("1400");
		else insert_data2.setState("1800");
		insert_data2.setOperate("ADD");
		insert_data2.setPayType(data.getPayType());
		insert_data2.setRepairFee(data.getRepairFee());
		dao.noroom_insert_business_repair_pool_finish(insert_data2);


		for (auto& file : fileBeforeNames) {
			data.setFileRelId(to_string(snowFlake.nextId()));
			data.setBId("-1");
			data.setRelTypeCd("23000");
			data.setSaveWay("fastdfs");
			data.setObjId(data.getRepairId());
			data.setFileRealName(file);
			data.setFileSaveName(file);
			data.setStatusCd("0");
			dao.insert_file_rel_finish(data);
		}
		for (auto& file : fileAfterNames) {
			data.setFileRelId(to_string(snowFlake.nextId()));
			data.setBId("-1");
			data.setRelTypeCd("24000");
			data.setSaveWay("fastdfs");
			data.setObjId(data.getRepairId());
			data.setFileRealName(file);
			data.setFileSaveName(file);
			data.setStatusCd("0");
			dao.insert_file_rel_finish(data);
		}
		return true;
	}
	else {
		if (dto->is_material == "1") {
			data.setMaintenanceType("1003");
			string repair_materials;
			for (const auto& item : materialList) {
				repair_materials += item->material_name + "*" + to_string(item->material_count) + ";";
			}
			data.setRepairMaterials(repair_materials);

			for (const auto& item : materialList) {
				auto select_resource = dao.select_resource_by_res_id_user_id(item->res_id, data.getUserId());

				if (item->material_count > stoi(select_resource.getStock())) {
					return false;
				}
				data.setRsurId(to_string(snowFlake.nextId()));

				data.setResId(item->res_id);
				data.setStock(to_string(stoi(select_resource.getStock()) - item->material_count));
				data.setStoreId(select_resource.getStoreId());
				data.setBId("-1");
				data.setCommunityId(select_data->getCommunityId());
				data.setQuantity(to_string(item->material_count));
				data.setStatusCd("0");
				data.setCreateUserId(select_data->getRuStaffId());
				data.setCreateUserName(select_data->getRuStaffName());
				data.setCreateTime(SimpleDateTimeFormat::format());
				data.setRemark(data.getContext());
				data.setResourceStoreName(item->material_name);
				data.setRecordState("2002");

				dao.insert_resource_store_use_record_finish(data);


				dao.update_user_storehouse_finish(data);
			}

		}
		else data.setMaintenanceType("1004");
		RepairToDoDO insert_data1, insert_data2;
		insert_data1.setRuId(select_data->getRuId());
		insert_data1.setRepairId(data.getRepairId());
		insert_data1.setBId(to_string(snowFlake.nextId()));
		insert_data1.setCommunityId(select_data->getCommunityId());
		insert_data1.setCreateTime(SimpleDateTimeFormat::format());
		insert_data1.setState("10002");
		insert_data1.setContext(data.getContext());
		insert_data1.setOperate("ADD");
		insert_data1.setRuStaffId(select_data->getRuStaffId());
		insert_data1.setRuStaffName(select_data->getRuStaffName());
		insert_data1.setPreStaffId(select_data->getPreStaffId());
		insert_data1.setPreStaffName(select_data->getPreStaffName());
		insert_data1.setStartTime(select_data->getStartTime());
		insert_data1.setEndTime(SimpleDateTimeFormat::format());
		insert_data1.setRepairEvent("auditUser");
		insert_data1.setPreRuId(select_data->getPreRuId());

		insert_data2.setRepairId(data.getRepairId());
		insert_data2.setBId(to_string(snowFlake.nextId()));
		insert_data2.setCommunityId(select_repair_pool->getCommunityId());
		insert_data2.setRepairType(select_repair_pool->getRepairType());
		insert_data2.setRepairName(select_repair_pool->getRepairName());
		insert_data2.setTel(select_repair_pool->getTel());
		insert_data2.setAppointmentTime(select_repair_pool->getAppointmentTime());
		insert_data2.setContext(select_repair_pool->getContext());
		insert_data2.setCreateTime(SimpleDateTimeFormat::format());
		insert_data2.setState(select_repair_pool->getState());
		insert_data2.setOperate("DEL");
		insert_data2.setRepairObjType(select_repair_pool->getRepairObjType());
		insert_data2.setRepairObjId(select_repair_pool->getRepairObjId());
		insert_data2.setRepairObjName(select_repair_pool->getRepairObjName());
		insert_data2.setMaintenanceType(select_repair_pool->getMaintenanceType());
		insert_data2.setRepairChannel(select_repair_pool->getRepairChannel());
		insert_data2.setRepairMaterials(select_repair_pool->getRepairMaterials());
		insert_data2.setRepairFee(select_repair_pool->getRepairFee());
		insert_data2.setPayType(select_repair_pool->getPayType());

		dao.noroom_update_repair_user_finish(data);
		dao.noroom_update_repair_pool_finish(data);
		dao.noroom_insert_business_repair_user_finish(insert_data1);

		dao.noroom_insert_business_repair_pool_finish(insert_data2);
		insert_data2.setMaintenanceType(data.getAppointmentTime());
		insert_data2.setRepairMaterials(data.getRepairMaterials());
		insert_data2.setState("1800");
		insert_data2.setOperate("ADD");
		dao.noroom_insert_business_repair_pool_finish(insert_data2);


		for (auto& file : fileBeforeNames) {
			data.setFileRelId(to_string(snowFlake.nextId()));
			data.setBId("-1");
			data.setRelTypeCd("23000");
			data.setSaveWay("fastdfs");
			data.setObjId(data.getRepairId());
			data.setFileRealName(file);
			data.setFileSaveName(file);
			data.setStatusCd("0");
			dao.insert_file_rel_finish(data);
		}
		for (auto& file : fileAfterNames) {
			data.setFileRelId(to_string(snowFlake.nextId()));
			data.setBId("-1");
			data.setRelTypeCd("24000");
			data.setSaveWay("fastdfs");
			data.setObjId(data.getRepairId());
			data.setFileRealName(file);
			data.setFileSaveName(file);
			data.setStatusCd("0");
			dao.insert_file_rel_finish(data);
		}
		return true;
	}
	return false;
}
