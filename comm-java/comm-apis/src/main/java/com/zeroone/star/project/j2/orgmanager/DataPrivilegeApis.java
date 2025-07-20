package com.zeroone.star.project.j2.orgmanager;


import com.zeroone.star.project.dto.j2.orgmanager.DataPrivilegeAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.DataPrivilegeDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 数据权限接口
 */
public interface DataPrivilegeApis {

    /**
     * 获取数据权限列表
     * @param communityId 小区id
     * @return 查询结果
     */
    JsonVO<List<DataPrivilegeDTO>> queryAll(String communityId);


    /**
     * 添加数据权限
     * @param addDTO 添加对象
     * @return 添加结果
     */
    JsonVO<String> addDataPrivilege(DataPrivilegeAddDTO addDTO);


    /**
     * 根据id查询数据权限信息
     * @param dpId 主键
     * @return 查询结果
     */
    //JsonVO<DataPrivilegeDTO> queryDataPrivilege(String dpId);


    /**
     * 修改数据权限
     * @param dto 数据权限传输对象
     * @return 修改结果
     */
    JsonVO<String> modifyDataPrivilege(DataPrivilegeDTO dto);

    /**
     * 删除数据权限
     * @param dpId 主键
     * @return 删除结果
     */
    JsonVO<String> deleteDataPrivilege(String dpId);
}
