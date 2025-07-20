package com.zeroone.star.orgmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddAssociatedPersonnelDTO;
import com.zeroone.star.project.query.j4.orgmanager.PersonnelScheduleQuery;
import com.zeroone.star.project.vo.j4.orgmanager.PersonnelSchedulingVO;

public interface AssociatedPersonnelService {
    /**
     * 添加关联人员设置
     * @param associatedPersonnelDTO
     */
    void addAssociatedPersonnel(AddAssociatedPersonnelDTO associatedPersonnelDTO);
    /**
     * 删除关联人员设置
     * @param staffId,scheduleId
     * @return
     */
    boolean deleteAssociatedPersonnel(String staffId, String scheduleId);
    /**
     * 获取人员排班列表（条件+分页）
     * @return
     */
    PageDTO<PersonnelSchedulingVO> listPersonnelScheduling(PersonnelScheduleQuery query);
}
