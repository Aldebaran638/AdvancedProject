package com.zeroone.star.project.j8.patrolmgt.detail;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.detail.dto.DetailDTO;
import com.zeroone.star.project.j8.patrolmgt.detail.query.DetailQuery;
import com.zeroone.star.project.j8.patrolmgt.detail.vo.DetailVO;
import com.zeroone.star.project.vo.JsonVO;

public interface DetailApis {

    /**
     * 获取巡检明细
     *
     * @param query 查询数据对象
     * @return 巡检明细
     */
    JsonVO<PageDTO<DetailDTO>> queryDetail(DetailQuery query);
}
