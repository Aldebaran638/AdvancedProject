package com.zeroone.star.oauth2.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.oauth2.entity.Store;

import java.util.List;

public interface IStoreService extends IService<Store> {
    /**
     * 通过用户编号获取角色列表
     * @param userId 用户编号
     * @return 角色列表
     */
    List<Store> listRoleByUserId(int userId);

    /**
     * 获取指定菜单路径有访问权限的角色
     * @param path 指定菜单路径
     * @return 角色列表
     */
    List<Store> listRoleByMenuPath(String path);
}
