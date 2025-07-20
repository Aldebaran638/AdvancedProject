package com.zeroone.star.project.j2.orgmanager.rolepermission;



import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AddEmpListDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.EmpListDTO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.EmpListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;

import java.util.List;


/**
 * 员工关联接口
 */
public interface EmpListApis {
    /**
     * 员工分页查询
     * @param query 查询数据对象
     * @return  查询结果
     */
    JsonVO<PageDTO<EmpListDTO>> queryEmpList(EmpListQuery query);

    /**
     * 新增关联
     * @return
     */
    JsonVO<Boolean> addEmpList(AddEmpListDTO addEmpListDTO);

    /**
     * 删除关联
     *
     * @param pId
     * @param pgId
     * @return
     */
    JsonVO<String> removeEmpList(String pId, String pgId);
}
