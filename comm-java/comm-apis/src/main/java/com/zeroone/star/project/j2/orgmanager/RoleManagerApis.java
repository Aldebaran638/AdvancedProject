package com.zeroone.star.project.j2.orgmanager;

import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 角色增删改查接口
 */
public interface RoleManagerApis {

    /**
     * 根据商户id查询角色列表（每个小区或商户可分配的角色不同）
     * @return 查询结果
     */
    JsonVO<List<RoleDTO>> queryAllRole();

    /**
     * 添加角色
     */
    JsonVO<String> addRole(RoleAddDTO addDTO);

    /**
     * 修改角色
     */
    JsonVO<String> modifyRole(RoleDTO dto);

    /**
     * 删除角色
     * @param pg_id 角色id
     * @return 删除结果
     */
    JsonVO<String> deleteRole(String pg_id);
}
