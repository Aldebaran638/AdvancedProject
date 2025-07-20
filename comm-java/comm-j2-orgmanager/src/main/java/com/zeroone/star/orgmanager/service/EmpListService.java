package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.UUserDO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AddEmpListDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.EmpListDTO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.EmpListQuery;
import com.zeroone.star.project.vo.ResultStatus;

import java.util.List;

/**
 * 服务类
 */
public interface EmpListService extends IService<UUserDO> {
    PageDTO<EmpListDTO> listAllEmp(EmpListQuery query);

    int removeEmpList(String pId, String pgId);

    ResultStatus saveEmpList(AddEmpListDTO addEmpListDTO);
}
