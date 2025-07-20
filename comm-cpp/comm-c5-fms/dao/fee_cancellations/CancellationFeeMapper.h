#ifndef _CANCELLATIONFEE_MAPPER_
#define CANCELLATIONFEE_MAPPER_
#include "Mapper.h"
#include "../../domain/do/fee_cancellations/CancellationFeeDO.h"
class CancellationFeeMapper : public Mapper<CancellationFeeDO>
{
public:
	CancellationFeeDO mapper(ResultSet* resultSet) const override
	{
		CancellationFeeDO data;
		data.setBatchId(resultSet->getString(1));
		data.setCommunityId(resultSet->getString(2));
		data.setCreateUserId(resultSet->getString(3));
		data.setCreateUserName(resultSet->getString(4));
		data.setCreateTime(resultSet->getString(5));
		data.setStatusCd(resultSet->getString(6));
		data.setState(resultSet->getString(7));
		data.setMsg(resultSet->getString(8));
		data.setRemark(resultSet->getString(9));
		return data;
	}
};
#endif