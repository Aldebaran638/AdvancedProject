package com.zeroone.star.menumana.service;


import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.menumana.entity.Privilege;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeAddDTO;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeDTO;
import com.zeroone.star.project.query.j1.menumana.privilege.PrivilegeQuery;

/**
* @author cv
* @description 针对表【p_privilege】的数据库操作Service
* @createDate 2025-05-20 17:05:06
*/
public interface IPrivilegeService extends IService<Privilege> {

    /*
    * 根据查询条件查询
    * @Param query 查询条件
    * @return 查询结果
    * */
    Page<PrivilegeDTO> listByCondition(PrivilegeQuery query);


    /*
    *
    * 实现添加代码
    * */
    String addPrivilege(PrivilegeAddDTO privilegeAddDTO);

    /*
    * 实现修改方法
    * */
    boolean modifyPrivilege(PrivilegeDTO privilegeDTO);

    /*
    * 实现删除方法
    * */
    boolean deletePrivilege(String id);
}
