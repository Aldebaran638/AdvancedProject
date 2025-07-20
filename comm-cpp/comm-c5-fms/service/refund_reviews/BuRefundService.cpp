#include "BuRefundService.h"
#include "stdafx.h"
std::list<BuRefundDTO::Wrapper> BuRefundService::getDtoData()
{
	BuRefundDAO dao;
	//确保能导出多条数据 list作为返回值
	auto res = dao.getAll();

	//1.检查查询结果是否为空 , 
	if (res.empty()) {
		OATPP_LOGE("OweInformationService", "No data found in ba_qm_sta table");
		return {}; // 返回空列表
	}
	std::list<BuRefundDTO::Wrapper> dtoList;
	for (const auto& doo : res) {
		auto dto = BuRefundDTO::createShared();
		dto->return_fee_id = doo.getReturn_Fee_Id();
		dto->b_id = doo.getB_Id();
		dto->fee_type_cd = doo.getFee_Type_Cd();
		dto->fee_id = doo.getFee_Id();
		dto->cycles = doo.getCycles();
		dto->received_amount = doo.getReceived_Amount();
		dto->create_time = doo.getCreate_Time();
		dto->reason = doo.getReason();
		dto->apply_person_name = doo.getApply_Person_Name();
		dto->state = doo.getState();
		dto->audit_person_name = doo.getAudit_Person_Name();
		dto->status_cd = doo.getStatus_Cd();
		dtoList.push_back(dto); // 将 DTO 添加到列表中
	}
	//在service层返回dto传输对象
	return dtoList;
}

