package com.zeroone.star.project.j4.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddEmployeeDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ModifyEmployeeDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ScheduleClassesDTO;
import com.zeroone.star.project.query.j4.orgmanager.employee.EmployeeQuery;
import com.zeroone.star.project.query.j4.orgmanager.employee.EmployeeSchedulingInfoQuery;
import com.zeroone.star.project.vo.j4.orgmanager.EmpOrgAuthorityVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeBaseInfoVO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeListVO;

import java.util.List;

/**
 * @Author: dashuai
 * @Description:
 * 包含添加员工、修改员工、重置密码、删除员工、获取员工基础信息、获取员工组织权限信息、
 * 获取员工排班信息、获取员工考核信息、获取员工列表
 *
 * 负责人：
 * 阿莫西林•胶囊、Heavydrink、龙
 */
public interface EmployeeApis {
    /**
     * 删除员工接口
     * @param userId 员工的user_id字段
     * @return 执行结果 true or false
     */
    JsonVO<String> deleteEmployee(String userId);

    /**
     * 获取员工基础信息
     * @param userId 员工的user_id字段
     * @return 响应基础信息
     */
    JsonVO<EmployeeBaseInfoVO> getEmployeeBaseInfo(String userId);

    /**
     * 获取员工组织权限信息
     * @param userId 员工id
     * @return 员工组织权限信息
     */
    JsonVO<EmpOrgAuthorityVO> getEmpOrgAuthority(String userId);

    /**
     * 添加员工
     * @param addEmployeeDTO 添加员工信息
     * @return 相应数据
     */
    JsonVO<String> addEmployee(AddEmployeeDTO addEmployeeDTO);

    /**
     * 修改员工
     * @param modifyEmployeeDTO 修改员工信息
     * @return 响应数据
     */
    JsonVO<String> modifyEmployee(ModifyEmployeeDTO modifyEmployeeDTO);

    /**
     * 重置密码
     * @param userId 员工id
     * @return 新密码
     */
    JsonVO<String> resetPassword(String userId);

    /**
     * 获取员工列表
     * @param employeeQuery  查询信息
     * @return 员工列表
     */
    JsonVO<PageDTO<EmployeeListVO>> getEmployeeList(EmployeeQuery employeeQuery);

    /**
     * 获得员工排班信息
     * @param employeeSchedulingInfoQuery  员工id+查询时间
     * @return 员工排班信息
     */
    JsonVO<ScheduleClassesDTO> getEmployeeSchedulingInfo(EmployeeSchedulingInfoQuery employeeSchedulingInfoQuery);
}
