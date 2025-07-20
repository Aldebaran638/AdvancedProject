package com.zeroone.star.communitymanage.service.notepad.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.communitymanage.entity.notepad.RepairType;
import com.zeroone.star.communitymanage.mapper.notepad.RepairTypeMapper;
import com.zeroone.star.communitymanage.service.notepad.RepairTypeService;
import com.zeroone.star.project.dto.j5.community.notepad.RepairTypeDTO;
import com.zeroone.star.project.query.j5.community.notepad.RepairTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.stream.Collectors;

@Service
@Slf4j
public class RepairTypeServiceImpl extends ServiceImpl<RepairTypeMapper, RepairType> implements RepairTypeService {


    /**
     * 查询报修类型
     * @param repairQuery
     * @return
     */

    @Override
    public JsonVO<List<RepairTypeDTO>> queryRepairType(RepairTypeQuery repairQuery) {
        log.info("Service 开始查询报修类型");
        // 1.分页参数校验
        if (repairQuery.getPageIndex() <= 0 || repairQuery.getPageSize() <= 0){
            throw new RuntimeException("分页参数有误");
        }

        // 2.构建查询参数
        QueryWrapper<RepairType> wrapper = new QueryWrapper<>();
        wrapper.eq("community_id", repairQuery.getCommunityId());
        wrapper.eq("public_area" , repairQuery.getPublicArea());

        // 3.构建分页参数
        Page<RepairType> page = new Page<>(repairQuery.getPageIndex(), repairQuery.getPageSize());

        // 4.查询
        Page<RepairType> pageRes = baseMapper.selectPage(page, wrapper);

        //  5.封装DTO
        List<RepairTypeDTO> Types = pageRes.getRecords().stream().map(repairType -> {
            RepairTypeDTO repairTypeDTO = new RepairTypeDTO();
            BeanUtil.copyProperties(repairType, repairTypeDTO);
            return repairTypeDTO;
        }).collect(Collectors.toList());

        // 6.响应结果
        return JsonVO.success(Types);
    }

}
