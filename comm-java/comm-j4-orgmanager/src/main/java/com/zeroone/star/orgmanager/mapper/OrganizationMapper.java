package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgmanager.entity.UOrg;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

/**
 * @Author: Altolia
 * @Description : 组织树修改的mapper接口
 */

public interface OrganizationMapper extends BaseMapper<UOrg> {

    /**
     * 查询当前组织是否有子节点,有子节点无法删除
     * @param orgId
     * @return
     */
    @Select("select count(*) from u_org where parent_org_id = #{orgId} and status_cd = '0'")
    int countChildren(@Param("orgId") String orgId);


    UOrg selectById(@Param("orgId") String orgId);
}
