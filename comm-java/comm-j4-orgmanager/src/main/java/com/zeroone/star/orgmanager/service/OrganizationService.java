package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.constant.OrganizationDeleteStatus;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AssociatedStaffDTO;
import com.zeroone.star.project.dto.j4.orgmanager.OrgStaffDTO;
import com.zeroone.star.project.dto.j4.orgmanager.OrganizationDTO;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.AssociatedStaffQuery;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.OrgStaffQuery;

import java.util.List;

public interface OrganizationService {
    /**
     * 删除组织接口
     * @param orgId
     * @return
     */
    OrganizationDeleteStatus removeOrganization(String orgId);


    /**
     * 获取组织员工列表(分页加条件)
     * @param orgStaffQuery
     * @return
     */
    PageDTO<OrgStaffDTO> listOrganizationStaff(OrgStaffQuery orgStaffQuery);

    /**
     * 关联员工之前查询(分页加条件)
     * @param associatedStaffQuery
     * @return
     */
    PageDTO<AssociatedStaffDTO> listAssociatedStaff(AssociatedStaffQuery associatedStaffQuery);

    /**
     *
     * @param orgId
     * @param userId
     * @return
     */
    String addAssociatedStaff(String orgId,List<String> userId);

}
