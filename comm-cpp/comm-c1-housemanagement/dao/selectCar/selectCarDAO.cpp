#include "stdafx.h"
#include "selectCarDAO.h"
#include "selectCarMapper.h"
#include <sstream>

std::string selectCarDAO::queryConditionBuilder(const CarQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->car_num) {
		sqlCondition << " AND owner_car.car_num=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->car_num.getValue(""));
	}
	/*if (query->num) {
		sqlCondition << " AND parking_space.num=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->num.getValue(""));
	}
	if (query->state)
	{
		sqlCondition << " AND owner_car.state=?";
		std::string state = query->state.getValue("");
		if (state == ZH_WORDS_GETTER("cardao.nocar"))
		{
			SQLPARAMS_PUSH(params, "s", std::string, "3003");
		}
		if (state == ZH_WORDS_GETTER("cardao.mstate"))
		{
			SQLPARAMS_PUSH(params, "s", std::string, "1001");
		}
		if (state == ZH_WORDS_GETTER("cardao.nstate"))
		{
			SQLPARAMS_PUSH(params, "s", std::string, "2002");
		}
	}
	if (query->lease_type)
	{
		std::string type = query->lease_type.getValue("");
		if (type == ZH_WORDS_GETTER("cardao.allcar")) 
		{
			sqlCondition << " AND owner_car.lease_type IN ('H', 'S', 'I', 'NM')";
			return sqlCondition.str();
		}
		sqlCondition << " AND owner_car.lease_type=?";
		if (type == ZH_WORDS_GETTER("cardao.H"))
		{
			SQLPARAMS_PUSH(params, "s", std::string, "H");
		}
		if (type == ZH_WORDS_GETTER("cardao.S"))
		{
			SQLPARAMS_PUSH(params, "s", std::string, "S");
		}
		if (type == ZH_WORDS_GETTER("cardao.I"))
		{
			SQLPARAMS_PUSH(params, "s", std::string, "I");
		}
		if (type == ZH_WORDS_GETTER("cardao.NM"))
		{
			SQLPARAMS_PUSH(params, "s", std::string, "NM");
		}
	}*/
	return sqlCondition.str();
}

uint64_t selectCarDAO::count(const CarQuery::Wrapper& query)
{
	SqlParams params;
	string sql = R"(SELECT COUNT(DISTINCT owner_car.car_id)
	FROM owner_car
	LEFT JOIN parking_space  ON owner_car.ps_id=parking_space.ps_id
	LEFT JOIN parking_area c ON c.pa_id=parking_space.pa_id
	LEFT JOIN building_owner d ON d.owner_id=owner_car.owner_id
	LEFT JOIN building_owner_room_rel x ON x.owner_id=owner_car.owner_id
	LEFT JOIN building_room ON building_room.room_id=x.room_id)";
	
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	//cout << sql << endl;
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CarDO> selectCarDAO::selectWithPage(const CarQuery::Wrapper& query)
{
	SqlParams params;
	string sql =  R"(SELECT DISTINCT
		owner_car.car_num,
		owner_car.lease_type,
		owner_car.car_type,
		owner_car.car_color,
		CONCAT(d.`name`,'(', d.link, ')') AS owner,
		c.num, 
		parking_space.num,
		CONCAT(owner_car.start_time, '-', owner_car.end_time) AS valid_time,
		owner_car.create_time
		FROM owner_car
		LEFT JOIN parking_space  ON owner_car.ps_id = parking_space.ps_id
		LEFT JOIN parking_area c ON c.pa_id = parking_space.pa_id
		LEFT JOIN building_owner d ON d.owner_id = owner_car.owner_id
		LEFT JOIN building_owner_room_rel x ON x.owner_id=owner_car.owner_id
	  LEFT JOIN building_room ON building_room.room_id=x.room_id)";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	
	// 构建排序语句
	sql += " ORDER BY owner_car.create_time DESC ";
	//cout << sql << endl;
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	selectCarMapper mapper;
	return sqlSession->executeQuery<CarDO>(sql, mapper, params);
}
