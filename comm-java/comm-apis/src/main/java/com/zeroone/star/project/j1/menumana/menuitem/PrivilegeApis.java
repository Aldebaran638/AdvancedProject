package com.zeroone.star.project.j1.menumana.menuitem;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeAddDTO;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeDTO;
import com.zeroone.star.project.query.j1.menumana.privilege.PrivilegeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.menumana.privilege.PrivilegeQueryVO;

/**
 * \* @author cv
 * \* Time: 2025/5/20 + 15:19
 * \* Description:
 * \
 */
public interface PrivilegeApis {

    /*
    * 添加权限
    * @Param privilegeAddDTO 新增数据
    * @Return 添加结果
    * */
    JsonVO<String> addPrivilege(PrivilegeAddDTO privilegeAddDTO);

    /*
     * 修改权限
     * @Param privilegeDTO 修改数据
     * @Return 修改结果
     * */
    JsonVO<String> modifyPrivilege(PrivilegeDTO privilegeDTO);

    /*
     * 分页查询权限
     * @Param condition 查询条件
     * @Return 查询结果
     * */
    JsonVO<PageDTO<PrivilegeQueryVO>> queryAll (PrivilegeQuery condition);

    /*
     * 根据编号删除权限
     * @Param id
     * @Return 删除结果
     * */
    JsonVO<String> deletePrivilege (PrivilegeDTO privilegeDTO);







}
