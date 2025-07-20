#include "stdafx.h"
#include "RepairStatisticsDAO.h"
#include "RepairStatisticsMapper.h"
#include <sstream>

std::list<RepairStatisticsDO> RepairStatisticsDAO::getRepairStatistics(const QueryRepairStatisticsQuery::Wrapper& query) {
	std::list<RepairStatisticsDO> statisticsList;

		std::string sql = "select "
			"    a.public_area_total, "
			"    b.non_public_area_total, "
			"    c.dispatched_orders, "
			"    d.return_visits, "
			"    e.unreturned_visits, "
			"    f.public_area_unfinished, "
			"    g.non_public_area_unfinished, "
			"    h.repair_receivable, "
			"    i.repair_received, "
			"    (10 - g.non_public_area_unfinished / b.non_public_area_total * 10) as non_public_completion_rate, "
			"    (10 - f.public_area_unfinished / a.public_area_total * 10) as public_completion_rate "
			"from "
			"    ( "
			"        select count(1) as public_area_total "
			"        from r_repair_pool t "
			"        inner join r_repair_setting rs on t.repair_type = rs.repair_type and rs.public_area = 'T' "
			"        where t.community_id = ? AND t.create_time BETWEEN ? AND ? "
			"    ) a, "
			"    ( "
			"        select count(1) as non_public_area_total "
			"        from r_repair_pool t "
			"        inner join r_repair_setting rs on t.repair_type = rs.repair_type and rs.public_area = 'F' "
			"        where t.community_id = ? AND t.create_time BETWEEN ? AND ? "
			"    ) b, "
			"    ( "
			"        select count(1) as dispatched_orders "
			"        from r_repair_pool t "
			"        where t.community_id = ? AND t.create_time BETWEEN ? AND ? "
			"        and t.state in (1100, 1200, 1300, 1400, 1500, 1700, 1800, 1900, 2000) "
			"    ) c, "
			"    ( "
			"        select count(1) as return_visits "
			"        from r_repair_pool t "
			"        inner join r_repair_setting rs on t.repair_type = rs.repair_type and rs.status_cd = '0' "
			"        left join r_repair_return_visit rrv on t.repair_id = rrv.repair_id and rrv.status_cd = '0' "
			"        where t.community_id = ? AND t.create_time BETWEEN ? AND ? "
			"        and rs.return_visit_flag = '003' "
			"        and rrv.visit_id is not null "
			"    ) d, "
			"    ( "
			"        select count(1) as unreturned_visits "
			"        from r_repair_pool t "
			"        inner join r_repair_setting rs on t.repair_type = rs.repair_type and rs.status_cd = '0' "
			"        left join r_repair_return_visit rrv on t.repair_id = rrv.repair_id and rrv.status_cd = '0' "
			"        where t.community_id = ? "
			"        and rs.return_visit_flag = '003' "
			"        and t.state in (1800, 1900) "
			"        and rrv.visit_id is null AND t.create_time BETWEEN ? AND ? "
			"    ) e, "
			"    ( "
			"        select count(1) as public_area_unfinished "
			"        from r_repair_pool t "
			"        inner join r_repair_setting rs on t.repair_type = rs.repair_type and rs.public_area = 'T' "
			"        where t.community_id = ? AND t.create_time BETWEEN ? AND ? "
			"        and t.state in (1000, 1100, 1200, 1300, 1400, 1500) "
			"    ) f, "
			"    ( "
			"        select count(1) as non_public_area_unfinished "
			"        from r_repair_pool t "
			"        inner join r_repair_setting rs on t.repair_type = rs.repair_type and rs.public_area = 'F' "
			"        where t.community_id = ? AND t.create_time BETWEEN ? AND ? "
			"        and t.state in (1000, 1100, 1200, 1300, 1400, 1500) "
			"    ) g, "
			"    ( "
			"        select ifnull(SUM(pf.amount), 0) as repair_receivable "
			"        from r_repair_pool t "
			"        inner join pay_fee_attrs pfa on t.repair_id = pfa.value and pfa.spec_cd = '390001' and pfa.status_cd = '0' "
			"        inner join pay_fee pf on pfa.fee_id = pf.fee_id and pf.status_cd = '0' "
			"        where t.community_id = ? AND t.create_time BETWEEN ? AND ? "
			"    ) h, "
			"    ( "
			"        select ifnull(SUM(pfd.received_amount), 0) as repair_received "
			"        from r_repair_pool t "
			"        inner join pay_fee_attrs pfa on t.repair_id = pfa.value and pfa.spec_cd = '390001' and pfa.status_cd = '0' "
			"        inner join pay_fee pf on pfa.fee_id = pf.fee_id and pf.status_cd = '0' "
			"        inner join pay_fee_detail pfd on pf.fee_id = pfd.fee_id and pfd.status_cd = '0' "
			"        where t.community_id = ? AND t.create_time BETWEEN ? AND ? "
			"    ) i";

		//填充上面的问号？
		SqlParams params;
		for (int i = 0; i < 9; i++)
		{
			// 添加日期条件参数
			std::string start_time = query->start_time.getValue("");
			std::string end_time = query->end_time.getValue("");
			SQLPARAMS_PUSH(params, "s", std::string, query->community_id.getValue(""));
			SQLPARAMS_PUSH(params, "s", std::string, start_time.empty() ? "1-1-1" : start_time);
			SQLPARAMS_PUSH(params, "s", std::string, end_time.empty() ? "9999-12-31" : end_time);
		}

		RepairStatisticsMapper mapper;
		return sqlSession->executeQuery<RepairStatisticsDO>(sql, mapper, params);
}



