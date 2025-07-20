package com.zeroone.star.orgmanager.service.serviceImpl;

import cn.hutool.core.util.IdUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.DataPrivilegeStaff;
import com.zeroone.star.orgmanager.entity.Staff;
import com.zeroone.star.orgmanager.mapper.StaffMapper;
import com.zeroone.star.orgmanager.service.lStaffService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.AddStaffDTO;
import com.zeroone.star.project.dto.j2.orgmanager.StaffDTO;
import com.zeroone.star.project.query.j2.orgmanager.StaffQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;

/**
 * <p>
 * 关联员工 service 实现类
 * </p>
 *
 * @author 瓜田里犯了错
 */

@Service
public class StaffServiceImpl extends ServiceImpl<StaffMapper, DataPrivilegeStaff> implements lStaffService{

    @Resource
    MsStaffMapper ms;

    @Resource
    private StaffMapper staffMapper;

    @Override
    public PageDTO<StaffDTO> listAll(StaffQuery query) {
        // 构建分页查询对象
        Page<Staff> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //查询数据
        Page<Staff> pageResult = staffMapper.selectAll(page, query);
        return PageDTO.create(pageResult, src -> ms.staffToDto(src));
    }

    @Override
    public JsonVO<Integer> saveStaff(AddStaffDTO addStaffDTO) {
        long dpsId = IdUtil.getSnowflakeNextId();
        int result = staffMapper.insertStaff(addStaffDTO,dpsId);
        return result > 0 ? JsonVO.success(result) : JsonVO.fail(0);
    }

    @Override
    public JsonVO<String> removeStaff(String staffId) {
        if (StringUtils.isEmpty(staffId)) {
            return JsonVO.fail("员工ID不能为空");
        }

        boolean result = remove(new QueryWrapper<DataPrivilegeStaff>().eq("staff_id", staffId));
        return result ? JsonVO.success("删除成功") : JsonVO.fail("删除失败");
    }
}
