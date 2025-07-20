package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.UUser;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddEmployeeDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ModifyEmployeeDTO;
import com.zeroone.star.project.query.j4.orgmanager.employee.EmployeeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmpOrgAuthorityVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeBaseInfoVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeListVO;

public interface EmployeeService  extends IService<UUser> {
    String deleteEmployee(String userId);

    JsonVO<EmployeeBaseInfoVO> getEmployeeBaseInfo(String userId);

    JsonVO<EmpOrgAuthorityVO> getEmpOrgAuthority(String userId);

    String addEmployee(AddEmployeeDTO addEmployeeDTO);

    String modifyEmployee(ModifyEmployeeDTO modifyEmployeeDTO);

    String resetPassword(String userId);

    JsonVO<PageDTO<EmployeeListVO>> emplist(EmployeeQuery employeeQuery);
}
