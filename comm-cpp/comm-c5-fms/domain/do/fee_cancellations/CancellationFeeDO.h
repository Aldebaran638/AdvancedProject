#ifndef _CANCELLATIONFEE_DO_
#define _CANCELLATIONFEE_DO_
#include "../DoInclude.h"
#include "domain/dto/fee_cancellations/CancellationFeeDTO.h"
/**
 * pay_fee_batch数据库实体类
 */
class CancellationFeeDO
{
	// 批次id
	CC_SYNTHESIZE(string, batchId,BatchId);
	//小区id
	CC_SYNTHESIZE(string, communityId, CommunityId);
	//创建人id
	CC_SYNTHESIZE(string, createUserId, CreateUserId);
	//创建人姓名
	CC_SYNTHESIZE(string, createUserName, CreateUserName);
	//创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
	//数据状态:'S'保存，'0'在用，'1'失效
	CC_SYNTHESIZE(string, statusCd, StatusCd);
	//审核状态:STATE_NORMAL 正常 STATE_APPLY 待审核 STATE_SUCCESS 审核通过 STATE_FAIL 审核失败
	CC_SYNTHESIZE(string, state, State);
	//取消原因
	CC_SYNTHESIZE(string, msg, Msg);
	//审核意见
	CC_SYNTHESIZE(string, remark, Remark);
	public:
		CancellationFeeDO()
		{
			batchId = "";
			state = "";
			communityId = "";
			createUserId = "";
			createUserName = "";
			createTime = "";
			statusCd = "";
			state = "";
			msg = "";
			remark = "";
		}
};

// 给CancellationFeeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CancellationFeeDO> PtrCancellationFeeDO;
#endif