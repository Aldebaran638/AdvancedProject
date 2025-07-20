#pragma once
#ifndef _VENUERESERVATIONMGRDAO_H_
#define _VENUERESERVATIONMGRDAO_H_
#include "BaseDAO.h"
#include  "../comm-c3-venuereservations/domain/do/VenueReservationMgrDo.h"
#include "../comm-c3-venuereservations/domain/query/VenueReservationMgrQuery.h"
/**
 * 查询场地预约列表在数据库操作实现
 */
class VenueReservationMgrDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryVenueReservationMgrConditionBuilder
	// FullName:    VenueReservationMgrDAO::queryRepairWorkNameConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	// 构建查询条件
	inline std::string queryVenueReservationMgrConditionBuilder(const VenueReservationMgrQuery::Wrapper& query, SqlParams& params);
public:

	// 分页查询数据
	std::list<VenueReservationMgrDO> selectWithPage(const VenueReservationMgrQuery::Wrapper& query);

	// 取消预约
	int cancelReservation(const string& cspId);
	// 插入数据
	int insert(const VenueReservationMgrDO& iObj);
	
	
};
#endif // _ VENUERESERVATIONMGRDAO_H_