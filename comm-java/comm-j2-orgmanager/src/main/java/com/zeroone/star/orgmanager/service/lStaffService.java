package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.orgmanager.entity.DataPrivilegeStaff;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.AddStaffDTO;
import com.zeroone.star.project.dto.j2.orgmanager.StaffDTO;
import com.zeroone.star.project.query.j2.orgmanager.StaffQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 关联员工 service 接口
 * </p>
 *
 * @author 瓜田里犯了错
 */

public interface lStaffService extends IService<DataPrivilegeStaff> {
    /**
     * 分页查询
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<StaffDTO> listAll(StaffQuery query);
    /**
     * 新增关联员工
     * @param addStaffDTO 参数
     * @return 新增结果
     */
    JsonVO<Integer> saveStaff(AddStaffDTO addStaffDTO);
    /**
     * 分页查询
     * @param staffId 删除条件
     * @return 删除结果
     */
    JsonVO<String> removeStaff(String staffId);
}
