package com.zeroone.star.orgmanager.service;

import com.zeroone.star.orgmanager.entity.PPrivilegeGroup;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleDTO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author SETTRA
 * @since 2025-05-30
 */
public interface RoleManageService extends IService<PPrivilegeGroup> {

    List<RoleDTO> listAllRoles();

    String saveRole(RoleAddDTO roleAddDTO);

    String updateRole(RoleDTO roleDTO);

    String deleteRole(String pg_id);
}
