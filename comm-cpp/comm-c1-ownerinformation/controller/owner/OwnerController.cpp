#include "stdafx.h"
#include "OwnerController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"
#include "../../service/Owner/OwnerService.h"

// ʵ��ѡ��ҵ���б��ӿ�
OwnerPageJsonVO::Wrapper OwnerController::execSelectOwnerList(const OwnerListQuery::Wrapper& query)
{

	// ����һ��Service
	OwnerService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = OwnerPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

StringJsonVO::Wrapper OwnerController::execAddOwner(const OwnerAddDTO::Wrapper& dto, const PayloadDTO& payload)
{

	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	// ��ʱ�����зǿ�У�飬��Ϊ��������ʱ����Ҫָ��unit_id �� b_id
		// �ǿ�У��
	//if (!dto->unit_id || !dto->b_id)
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	//	// ��ЧֵУ��
	//if (dto->unit_id->empty() || dto->b_id->empty())
	//{
	//	jvo->init(nullptr, RS_PARAMS_INVALID);
	//	return jvo;
	//}
	
	// ����һ��Service
	OwnerService service;
	// ִ����������
	dto->setPayload(&payload);
	std::string id = service.saveData(dto);
	if (id != "") {
		jvo->success(id);
	}
	else
	{
		jvo->fail("");
	}
	//��Ӧ���
	return jvo;
}

StringJsonVO::Wrapper OwnerController::execModifyOwner(const OwnerDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();
	// ����У��
	if (!dto->owner_id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	OwnerService service;
	// ִ�������޸�
	dto->setPayload(&payload);
	if (service.updateData(dto)) {
		jvo->success(dto->owner_id);
	}
	else
	{
		jvo->fail(dto->owner_id);
	}
	// ��Ӧ���
	return jvo;
}

ListJsonVO<String>::Wrapper OwnerController::execRemoveOwner(const List<String>& ids)
{

	// ���巵�����ݶ���
	auto jvo = ListJsonVO<String>::createShared();
	// ����У��
	if (ids->empty())
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	OwnerService service;
	// ִ������ɾ��
	if (service.removeData(ids)) {
		jvo->success(ids);
	}
	else
	{
		jvo->fail(nullptr);
	}
	// ��Ӧ���
	return jvo;
}