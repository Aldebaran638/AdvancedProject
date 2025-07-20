package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.project.dto.j4.orgmanager.ModifyOrganizationDTO;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Update;

/**
 * @Author: Alisa
 * @Description : 组织树修改的mapper接口
 */
public interface OrganizationModifyMapper {
    /**
     * 更新组织信息
     * @param modifyOrganizationDTO 包含更新信息的DTO
     * @return 影响的行数，1表示成功，0表示失败
     */
    @Update("UPDATE t_dict SET org_name = #{orgname}, pid = COALESCE(#{parentOrgId}, pid), description = COALESCE(#{description}, description) WHERE org_name = #{orgname}")
    int modifyOrganization(@Param("modifyOrganizationDTO") ModifyOrganizationDTO modifyOrganizationDTO);


}
