package com.zeroone.star.project.j4.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AssociatedStaffDTO;
import java.util.List;
import com.zeroone.star.project.dto.j4.orgmanager.ClassOrganizationDTO;
import com.zeroone.star.project.dto.j4.orgmanager.OrgStaffDTO;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.AssociatedStaffQuery;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.OrgStaffQuery;
import com.zeroone.star.project.dto.j4.orgmanager.AddOrganizationDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AssociatedStaffDTO;
import java.util.List;
import com.zeroone.star.project.dto.j4.orgmanager.ModifyOrganizationDTO;
import com.zeroone.star.project.dto.j4.orgmanager.OrgStaffDTO;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.AssociatedStaffQuery;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.OrgStaffQuery;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.OrganizationQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.ClassOrganizationVO;

/**
 * @Author: dashuai
 * @Description:
 * 组织信息相关接口
 * 包含获取组织名称树、添加、修改、删除组织
 * 获取组织员工列表（条件+分页）、关联员工
 *
 * 负责人：Alisa、Altolia Pandragong
 */

public interface OrganizationApis {
    /**
     * @return 包括组织ID、层级和父组织ID的DTO列表
     */
    JsonVO<List<ClassOrganizationVO>> getOrganizationTree() throws Exception;


    /**
     * 添加组织
     * @param addOrganizationDTO  包含组织ID、层级和父组织ID等信息的DTO对象
     * @return 保存后组织的VO对象，包含组织ID、层级和父组织ID
     */
    JsonVO<String> addOrganization(AddOrganizationDTO addOrganizationDTO);

    /**
     * 修改组织
     * 根据给定的组织ID，更新数据库中对应的组织信息，并返回更新后的组织信息
     * @param modifyOrganizationDTO 要修改的组织信息
     * @return 修改后组织的组织名称，上级组织，描述，如果组织ID不存在则返回null
     */
    JsonVO<String> modifyOrganization(ModifyOrganizationDTO modifyOrganizationDTO);

    /**
     * 根据组织id删除组织
     * @param orgId
     * @return 返回String “删除成功” "删除失败" 等字段
     */
    JsonVO<String> removeOrganization(String orgId);

    /**
     * 分页查询组织员工信息
     * @param orgStaffQuery
     * @return 组织员工列表
     */
    JsonVO<PageDTO<OrgStaffDTO>> queryOrgStaff(OrgStaffQuery orgStaffQuery);

    /**
     * 点击关联员工时，根据组织id获取相应组织下可添加的员工信息
     * 同时也有通过名称查询，所以这里封装query对象
     * @param associatedStaffQuery
     * @return 组织员工列表 字段与上面不同
     */
    JsonVO<PageDTO<AssociatedStaffDTO>>  queryAllStaffs(AssociatedStaffQuery associatedStaffQuery);

    /**
     * 点击关联员工后,选择员工列表
     * @param orgId
     * @param userIds
     * @return
     */
    JsonVO<String> addStaffs(String orgId,List<String> userIds);
}