package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.entity.UOrgStaffRel;
import com.zeroone.star.project.dto.j4.orgmanager.AssociatedStaffDTO;
import com.zeroone.star.project.dto.j4.orgmanager.OrgStaffDTO;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.AssociatedStaffQuery;
import com.zeroone.star.project.query.j4.orgmanager.orgmessage.OrgStaffQuery;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

/**
 * @Author: Altolia
 * @Description 与员工相关Mapper涉及多表查询
 */
public interface OrganizationStaffMapper extends BaseMapper<UOrgStaffRel> {
    //实体类还要定义,这里直接不遵循规范了,DTO定义的是和数据表里一样的
    /**
     * 获取组织员工列表（条件+分页）
     */
    Page<OrgStaffDTO> getOrgStaff(Page<OrgStaffDTO> page,@Param("query") OrgStaffQuery orgStaffQuery);


    Page<AssociatedStaffDTO> getAocStaff(Page<AssociatedStaffDTO> page,@Param("query") AssociatedStaffQuery associatedStaffQuery);

    @Update("UPDATE u_org_staff_rel SET status_cd = #{statusCd} " +
            "WHERE org_id = #{orgId} AND staff_id = #{staffId}")
    int updateStatus(@Param("orgId") String orgId,
                     @Param("staffId") String staffId,
                     @Param("statusCd") String statusCd);

}
