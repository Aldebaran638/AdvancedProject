#include "stdafx.h"
#include "CancellationFeeService.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

inline std::string CancellationFeeService::mapperState(const std::string& state)
{
	if (state == "2006001")	return ZH_WORDS_GETTER("cancellationfee.state.2006001");
	else if (state == "2007001")	return ZH_WORDS_GETTER("cancellationfee.state.2007001");
	else if (state == "2008001")	return ZH_WORDS_GETTER("cancellationfee.state.2008001");
	else if (state == "2009001")	return ZH_WORDS_GETTER("cancellationfee.state.2009001");
	return "error";
}

CancellationFeePageDTO::Wrapper CancellationFeeService::listAll(const CancellationFeeQuery::Wrapper& query)
{
	//构建返回对象
	auto pages = CancellationFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	CancellationFeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CancellationFeeDO> result = dao.selectWithPage(query);
	for (CancellationFeeDO sub : result)
	{
		auto dto = CancellationFeeDTO::createShared();
		sub.setState(mapperState(sub.getState()));
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, batchId, BatchId,  createUserName, CreateUserName, createTime, CreateTime, msg, Msg, state, State, remark, Remark);
		pages->addData(dto);
	}
	
	return pages;
}

bool CancellationFeeService::applyCancel(const CancellationFeeApplyDTO::Wrapper& dto)
{
	//组装DO数据
	CancellationFeeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,BatchId,batchId,Msg,msg);
	//将状态设置为待审核状态
	data.setState(STATE_APPLY);
	//将审核意见设置为待审核
	data.setRemark(ZH_WORDS_GETTER("cancellationfee.post.apply_state"));
	//执行数据修改
	CancellationFeeDAO dao;
	return dao.update(data) == 1;
}

bool CancellationFeeService::auditCancel(const CancellationFeeAuditDTO::Wrapper& dto)
{
	//组装DO数据
	CancellationFeeDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,BatchId,batchId,Remark,remark,State,state);
	//审核失败,要在审核意见前加上“拒绝：”
	if (data.getState() == ZH_WORDS_GETTER("cancellationfee.post.audit_refuse"))
	{
		string temp = data.getRemark();
		temp.insert(0, ZH_WORDS_GETTER("cancellationfee.post.audit_refuse")+":");
		data.setRemark(temp);
		//审核状态设置为STATE_FAIL
		data.setState(STATE_FAIL);
		//数据状态设置为在用(0)
		data.setStatusCd("0");
	}
	//审核成功，则将数据状态置为失效(1)
	else if (data.getState() == ZH_WORDS_GETTER("cancellationfee.post.audit_approve"))
	{
		//审核状态设置为STATE_SUCCESS
		data.setState(STATE_SUCCESS);
		data.setStatusCd("1");
	}
	//执行数据修改
	CancellationFeeDAO dao;
	return dao.update(data) == 1;
}
