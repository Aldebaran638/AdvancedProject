package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgmanager.entity.PPrivilegeRel;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AddEmpListDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface PPrivilegeRelMapper extends BaseMapper<PPrivilegeRel> {
    /**
     * 批量插入权限关系数据
     */
    int InsertPrivilegeRel(@Param("dto") AddEmpListDTO addEmpListDTO);

    /**
     * userId 去 p_privilege_user 表中查出对应的 pId 列表
     * @param userIds
     * @return
     */
    List<String> selectByPgId(@Param("userIds") List<String> userIds);
}
