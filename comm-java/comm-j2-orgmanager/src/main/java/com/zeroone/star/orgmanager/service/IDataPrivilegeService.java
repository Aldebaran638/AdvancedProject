package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.DataPrivilege;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.DataPrivilegeDTO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hubery
 * @since 2025-05-19
 */
public interface IDataPrivilegeService extends IService<DataPrivilege> {

    // 获取数据权限列表
    List<DataPrivilegeDTO> listAll(String communityId);



}