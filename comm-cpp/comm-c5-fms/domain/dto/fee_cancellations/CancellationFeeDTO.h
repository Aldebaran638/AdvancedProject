#ifndef _CANCELLATIONFEE_DTO_
#define _CANCELLATIONFEE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

const std::string STATE_NORMAL = "2006001";//正常
const std::string STATE_APPLY = "2007001";//申请取消
const std::string STATE_SUCCESS = "2008001";//审核通过
const std::string STATE_FAIL = "2009001";//审核失败

//映射表
const std::unordered_map<std::string, const std::string>STATE_MAP = {
	{"正常",STATE_NORMAL},
	{"申请取消",STATE_APPLY},
	{"审核通过",STATE_SUCCESS},
	{"审核失败",STATE_FAIL}
};

/**
 * 分页传输对象
 */
class CancellationFeeDTO :public oatpp::DTO
{
	DTO_INIT(CancellationFeeDTO, DTO);
	// 批次id
	API_DTO_FIELD_DEFAULT(String, batchId, ZH_WORDS_GETTER("cancellationfee.field.batchId"));

	////小区id
	//API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("cancellationfee.field.communityId"));

	////创建人id
	//API_DTO_FIELD_DEFAULT(String, createUserId, ZH_WORDS_GETTER("cancellationfee.field.createUserId"));

	//创建人姓名
	API_DTO_FIELD_DEFAULT(String, createUserName, ZH_WORDS_GETTER("cancellationfee.field.createUserName"));

	//创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("cancellationfee.field.createTime"));

	////数据状态:'S'保存，'0'在用，'1'失效
	//API_DTO_FIELD_DEFAULT(String, statusCd, ZH_WORDS_GETTER("cancellationfee.field.statusCd"));

	//取消原因
	API_DTO_FIELD_DEFAULT(String, msg, ZH_WORDS_GETTER("cancellationfee.field.msg"));

	//审核状态:STATE_NORMAL 正常 STATE_APPLY 待审核 STATE_SUCCESS 审核通过 STATE_FAIL 审核失败
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("cancellationfee.field.state"));

	//审核意见
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("cancellationfee.field.remark"));
};

/*
*取消费用列表传输对象
*/
class CancellationFeePageDTO : public PageDTO<CancellationFeeDTO::Wrapper>
{
	DTO_INIT(CancellationFeePageDTO, PageDTO<CancellationFeeDTO::Wrapper>);

};

/*
*	申请取消传输对象
*/
class CancellationFeeApplyDTO : public oatpp::DTO
{
	DTO_INIT(CancellationFeeApplyDTO, DTO);

	// 批次id
	API_DTO_FIELD_DEFAULT(String, batchId, ZH_WORDS_GETTER("cancellationfee.field.batchId"));

	//审核说明
	API_DTO_FIELD_DEFAULT(String, msg, ZH_WORDS_GETTER("cancellationfee.field.msg"));

};

/*
*	审核取消传输对象
*/
class CancellationFeeAuditDTO : public oatpp::DTO
{
	DTO_INIT(CancellationFeeAuditDTO, DTO);
	
	// 批次id
	API_DTO_FIELD_DEFAULT(String, batchId, ZH_WORDS_GETTER("cancellationfee.field.batchId"));

	//审核状态:STATE_SUCCESS 审核通过  STATE_FAIL 审核失败
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("cancellationfee.field.state"));

	//审核意见
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("cancellationfee.field.remark"));

};
#include OATPP_CODEGEN_END(DTO)
#endif 