package com.zeroone.star.project.j2.orgmanager;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.AddStaffDTO;
import com.zeroone.star.project.dto.j2.orgmanager.StaffDTO;
import com.zeroone.star.project.query.j2.orgmanager.StaffQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;


/**
 * <p>
 * 描述：关联员工组件接口
 * </p>
 * @author 瓜田里犯了错
 * @version 1.0
 */
public interface StaffApis {

    /**
     * 分页查询关联员工
     * @param query 查询数据对象
     * @return 查询结果
     */
    JsonVO<PageDTO<StaffDTO>> queryStaff(StaffQuery query);

    /**
     * 添加关联员工
     * @param addStaffDTO 添加关联员工数据对象
     * @return 添加结果
     */
    JsonVO<Integer> addStaff(AddStaffDTO addStaffDTO);

    /**
     * 删除关联员工
     * @param staffId 关联员工id
     * @return 删除结果
     */
    JsonVO<String> removeStaff(String staffId);
}
