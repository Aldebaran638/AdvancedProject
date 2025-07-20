package com.zeroone.star.orgmanager.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.entity.DataPrivilegeStaff;
import com.zeroone.star.orgmanager.entity.Staff;
import com.zeroone.star.project.dto.j2.orgmanager.AddStaffDTO;
import com.zeroone.star.project.query.j2.orgmanager.StaffQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;


/**
 * <p>
 * 关联员工 Mapper 接口
 * </p>
 * @author 瓜田里犯了错
 */

@Mapper
public interface StaffMapper extends BaseMapper<DataPrivilegeStaff> {
    //分页查询
    Page<Staff> selectAll(Page<Staff> page, @Param("query")StaffQuery query);
    //新增关联员工
    int insertStaff(@Param("addStaffDTO") AddStaffDTO addStaffDTO,@Param("dpsId") Long dpsId);
}
