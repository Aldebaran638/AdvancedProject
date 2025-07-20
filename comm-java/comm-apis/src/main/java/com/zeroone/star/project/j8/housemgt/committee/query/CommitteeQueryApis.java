package com.zeroone.star.project.j8.housemgt.committee.query;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.housemgt.committee.query.CommitteeListQuery;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeListDTO;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeDetailDTO;
import com.zeroone.star.project.vo.JsonVO;

public interface CommitteeQueryApis {
    /**
     * 获取业委会成员列表
     *
     * @param query 查询数据对象
     * @return 业委会成员列表
     */
    JsonVO<PageDTO<CommitteeListDTO>> queryCommitteeList(CommitteeListQuery query);

    /**
     * 获取业委会成员详情
     *
     * @param ocId 成员ID
     * @return 业委会成员详情
     */
    JsonVO<CommitteeDetailDTO> queryCommitteeDetail(String ocId);
}
