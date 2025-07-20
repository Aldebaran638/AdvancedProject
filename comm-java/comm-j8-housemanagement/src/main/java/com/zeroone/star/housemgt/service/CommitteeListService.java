package com.zeroone.star.housemgt.service;

import com.zeroone.star.housemgt.entity.gzx_OwnerCommittee;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeListDTO;
import com.zeroone.star.project.j8.housemgt.committee.query.CommitteeListQuery;
import com.zeroone.star.project.dto.PageDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author gzx
 * @since 2025-05-24
 */
public interface CommitteeListService extends IService<gzx_OwnerCommittee>{
    PageDTO<CommitteeListDTO> queryList(CommitteeListQuery query);
}
