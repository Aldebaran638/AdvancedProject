#include "stdafx.h"
#include "listCarService.h"
#include "../../dao/selectCar/selectCarDAO.h"

CarPageDTO::Wrapper listCarService::listAll(const CarQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CarPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	selectCarDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CarDO> result = dao.selectWithPage(query);
	

	for (CarDO sub : result)
	{
		auto dto = CarDTO::createShared();
		/*if (sub.getState() == "zc")
		{
			sub.setState(ZH_WORDS_GETTER("cardao.mstate"));
		}
		else if (sub.getState() == "dq")
		{
			sub.setState(ZH_WORDS_GETTER("cardao.nstate"));
		}
		if (sub.getLease_type() == "H")
		{
			sub.setLease_type(ZH_WORDS_GETTER("cardao.H"));
		}
		else if (sub.getLease_type() == "S")
		{
			sub.setLease_type(ZH_WORDS_GETTER("cardao.S"));
		}
		else if (sub.getLease_type() == "I")
		{
			sub.setLease_type(ZH_WORDS_GETTER("cardao.I"));
		}
		else if (sub.getLease_type() == "NM")
		{
			sub.setLease_type(ZH_WORDS_GETTER("cardao.NM"));
		}
		if (sub.getCar_type() == "9901")
		{
			sub.setCar_type(ZH_WORDS_GETTER("cardao.J"));
		}
		else if (sub.getCar_type() == "9902")
		{
			sub.setCar_type(ZH_WORDS_GETTER("cardao.K"));
		}
		else if (sub.getCar_type() == "9903")
		{
			sub.setCar_type(ZH_WORDS_GETTER("cardao.D"));
		}*/
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, car_num,Car_num, lease_type,Lease_type,car_type,Car_type,car_color,Car_color,name,Name,num,Num, valid_time,Valid_time);
		pages->addData(dto);
	}
	return pages;
}
