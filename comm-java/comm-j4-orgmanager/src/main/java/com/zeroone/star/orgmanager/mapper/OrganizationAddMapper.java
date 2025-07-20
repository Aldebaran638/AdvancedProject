package com.zeroone.star.orgmanager.mapper;

import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Options;
import org.apache.ibatis.annotations.Param;
/**
 * @Author: Alisa
 * @Description : 添加组织
 */
@Mapper
public interface OrganizationAddMapper {

    /**
     * 添加组织信息
     * @param orgName 组织名称
     * @param parentOrgId 上级组织ID
     * @param description 描述
     * @return 插入结果，1表示成功，0表示失败
     */
    @Insert("INSERT INTO u_org (org_name, parent_org_id, description) VALUES(#{orgName}, #{parentOrgId}, #{description})")
    @Options(useGeneratedKeys = true, keyProperty = "id")
    int addOrganization(@Param("orgName") String orgName, @Param("parentOrgId") String parentOrgId, @Param("description") String description);

}
