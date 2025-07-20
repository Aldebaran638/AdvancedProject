#include "stdafx.h"
#include "MemberService.h"
#include "../../dao/member/MemberDAO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

//查
MemberPageDTO::Wrapper MemberService::listAll(const MemberQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MemberPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MemberDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<MemberDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (MemberDO sub : result)
	{
		auto dto = MemberDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,  name, Name,  sex, Sex,link, Link, id_card, Id_card,owner_type_cd, Owner_type_cd, address, Address, remark, Remark);
		pages->addData(dto);
	}
	return pages;
}

//增
std::string MemberService::saveData(const MemberAddDTO::Wrapper& dto)
{
	// 组装DO数据
	MemberDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name,Link, link,  Id_card, id_card,Sex, sex,  Owner_type_cd, owner_type_cd, Address, address, Remark, remark);
	// 生成member_id
	UuidFacade uf;
	std::string uuid = uf.genUuid();
	if (uuid.size() > 30)
	{
		uuid = uuid.substr(0, 30);
	}
	data.setMember_id(uuid);
	// 设置创建时间
	data.setCreateTime(SimpleDateTimeFormat::format());
	// 执行数据添加
	MemberDAO dao;
	return dao.insert(data) == 1 ? data.getMember_id() : "";
}

//改
bool MemberService::updateData(const MemberDTO::Wrapper& dto)
{
	// 组装DO数据
	MemberDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,  Name, name,Link, link,Id_card, id_card, Sex, sex,  Owner_type_cd, owner_type_cd, Address, address, Remark, remark,Member_id, member_id);
	// 执行数据修改
	MemberDAO dao;
	return dao.update(data) == 1;
}

//删
bool MemberService::removeData(const oatpp::List<oatpp::String>& ids)
{
	MemberDAO dao;
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
