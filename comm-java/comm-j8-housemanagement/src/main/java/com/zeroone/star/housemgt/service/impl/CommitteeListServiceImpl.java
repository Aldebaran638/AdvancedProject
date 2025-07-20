package com.zeroone.star.housemgt.service.impl;

import com.zeroone.star.housemgt.entity.gzx_OwnerCommittee;
import com.zeroone.star.housemgt.mapper.CommitteeListMapper;
import com.zeroone.star.housemgt.service.CommitteeListService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import org.springframework.util.StringUtils;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeListDTO;
import com.zeroone.star.project.j8.housemgt.committee.query.CommitteeListQuery;

/**
 * <p>
 * 服务实现类
 * </p>
 *
 * @author yuanzijie
 * @since 2025-05-24
 */
@Service
public class CommitteeListServiceImpl extends ServiceImpl<CommitteeListMapper, gzx_OwnerCommittee> implements CommitteeListService {

    @Override
    public PageDTO<CommitteeListDTO> queryList(CommitteeListQuery query) {
        // 设置分页参数默认值（防止为0的情况）
        if (query.getPageIndex() <= 0) {
            query.setPageIndex(1);
        }
        if (query.getPageSize() <= 0) {
            query.setPageSize(10);
        }

        // 构建查询条件
        LambdaQueryWrapper<gzx_OwnerCommittee> wrapper = new LambdaQueryWrapper<>();

        // 根据业委会名称模糊查询
        if (StringUtils.hasText(query.getName())) {
            wrapper.like(gzx_OwnerCommittee::getName, query.getName());
        }

        // 根据联系电话模糊查询
        if (StringUtils.hasText(query.getLink())) {
            wrapper.like(gzx_OwnerCommittee::getLink, query.getLink());
        }

        // 根据状态精确查询（必填字段）
        if (StringUtils.hasText(query.getState())) {
            wrapper.eq(gzx_OwnerCommittee::getState, query.getState());
        }

        // 只查询有效数据（statusCd = "0"）
        wrapper.eq(gzx_OwnerCommittee::getStatusCd, "0");

        // 按创建时间倒序排列
        wrapper.orderByDesc(gzx_OwnerCommittee::getCreateTime);

        // 执行分页查询
        Page<gzx_OwnerCommittee> page = new Page<>(query.getPageIndex(), query.getPageSize());
        Page<gzx_OwnerCommittee> result = this.page(page, wrapper);

        // 手动转换，处理ID类型转换
        return PageDTO.create(result, entity -> {
            CommitteeListDTO dto = new CommitteeListDTO();
            // Long转String，避免前端精度丢失
            dto.setOcId(String.valueOf(entity.getOcId()));
            dto.setName(entity.getName());
            dto.setSex(convertSexToDesc(entity.getSex()));
            dto.setLink(entity.getLink());
            dto.setIdCard(entity.getIdCard());
            dto.setAddress(entity.getAddress());
            dto.setPosition(entity.getPosition());
            dto.setPost(entity.getPost());
            dto.setAppointTime(entity.getAppointTime());
            dto.setCurTime(entity.getCurTime());
            dto.setState(entity.getState());
            return dto;
        });
    }

    /**
     * 性别码转换为描述
     * @param sex 性别码
     * @return 性别描述
     */
    private String convertSexToDesc(String sex) {
        if ("B".equals(sex)) {
            return "男";
        } else if ("G".equals(sex)) {
            return "女";
        } else {
            return "未知";
        }
    }
}

