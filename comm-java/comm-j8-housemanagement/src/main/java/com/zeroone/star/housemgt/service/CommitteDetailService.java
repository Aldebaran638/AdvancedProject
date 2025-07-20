package com.zeroone.star.housemgt.service;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.housemgt.entity.gzx_OwnerCommitteeContact;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeDetailDTO;

public interface CommitteDetailService extends IService<gzx_OwnerCommitteeContact> {
    /**
     * 根据成员ID查询业委会成员详情（包含扩展信息）
     * @param ocId 业委会成员编号
     * @return 业委会成员详情（包含更多字段信息）
     */
    CommitteeDetailDTO queryDetailById(String ocId);
}
