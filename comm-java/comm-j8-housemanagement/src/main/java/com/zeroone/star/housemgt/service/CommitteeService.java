package com.zeroone.star.housemgt.service;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.j8.housemgt.committee.dto.AddCommitteeDTO;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeDTO;

/**
 * 业委会模块业务接口
 */
public interface CommitteeService {

    /**
     * 新增一条业委会记录（含紧急联系人）
     *
     * @param dto 新增所需字段封装对象
     * @return 操作结果（200 OK / 错误信息）
     */
    JsonVO<String> addCommittee(AddCommitteeDTO dto);

    /**
     * 修改一条已存在的业委会记录（先删后增联系人）
     *
     * @param dto 修改所需字段封装对象，必须包含 committeeId
     * @return 操作结果
     */
    JsonVO<String> modifyCommittee(CommitteeDTO dto);

    /**
     * 删除一条业委会记录及其所有紧急联系人
     *
     * @param committeeId 要删除的业委会主键
     * @return 操作结果
     */
    JsonVO<String> removeCommittee(String committeeId);
}
