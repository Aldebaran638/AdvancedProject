package com.zeroone.star.communitymanage.service.renovation.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.communitymanage.exception.ResourceNotFoundException;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDTO;
import com.zeroone.star.project.query.j5.community.renovation.RenovationQuery;
import com.zeroone.star.communitymanage.entity.renovation.RoomRenovation;
import com.zeroone.star.communitymanage.mapper.renovation.RenovationMapper;
import com.zeroone.star.communitymanage.service.renovation.IRenovationService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author powfu
 * @since 2025-05-23
 */
@Service
public class RenovationServiceImpl extends ServiceImpl<RenovationMapper, RoomRenovation> implements IRenovationService {

    @Resource
    MsRenovationMapper ms;

    @Resource
    RenovationMapper rm;

    @Override
    public PageDTO<RenovationDTO> listAll(RenovationQuery query, String communityId) {
        // 校验communityId必传
        if (StringUtils.isEmpty(communityId)) {
            throw new IllegalArgumentException("社区ID不能为空");
        }

        // 创建查询wrapper检查communityId是否存在
        QueryWrapper<RoomRenovation> checkWrapper = new QueryWrapper<>();
        checkWrapper.eq("community_id", communityId);
        // 只需要查询count即可，不需要完整实体
        long count = this.count(checkWrapper);
        if (count == 0) {
            throw new ResourceNotFoundException("社区ID不存在");
        }

        // 构建分页查询对象
        Page<RoomRenovation> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<RoomRenovation> wrapper = new QueryWrapper<>();
        // 添加 communityId 条件（使用函数参数，而非 query 对象）
        wrapper.eq(!StringUtils.isEmpty(communityId), "community_id", communityId);
        wrapper.like(!StringUtils.isEmpty(query.getRoomName()), "room_name", query.getRoomName());
        wrapper.like(!StringUtils.isEmpty(query.getPersonName()), "person_name", query.getPersonName());
        wrapper.like(!StringUtils.isEmpty(query.getPersonTel()), "person_tel", query.getPersonTel());
        wrapper.eq(!StringUtils.isEmpty(query.getState()), "state", query.getState());
        wrapper.eq(!StringUtils.isEmpty(query.getIsPostpone()), "is_postpone", query.getIsPostpone());
        wrapper.eq(!StringUtils.isEmpty(query.getStartTime()), "start_time", query.getStartTime());
        wrapper.eq(!StringUtils.isEmpty(query.getEndTime()), "end_time", query.getEndTime());
        // renovationTime 查询逻辑
        LocalDateTime renovationTime = query.getRenovationTime();
        wrapper.le(renovationTime != null, "start_time", renovationTime)
                .ge(renovationTime != null, "end_time", renovationTime);

        wrapper.orderBy(true, false, "create_time");
        wrapper.orderBy(true, false, "r_id");
        // 查询数据
        Page<RoomRenovation> pageResult = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(pageResult, this::convertToDTO);
//        return PageDTO.create(pageResult, src -> ms.renovationToDTO(src));
    }

    @Override
    public boolean removeById(Serializable id) {
        // 首先查询记录是否存在
        RoomRenovation entity = getById(id);
        if (entity == null) {
            throw new ResourceNotFoundException("rId不存在");
        }
        // 调用父类删除方法
        return super.removeById(id);
    }

    @Override
    public boolean updateRenoById(RoomRenovation entity) {
        String isViolation = entity.getIsViolation();
        switch (isViolation){
            case "是":
                entity.setIsViolation("Y");
                break;
            case "否":
                entity.setIsViolation("N");
                break;
        }
        String isPostpone = entity.getIsPostpone();
        switch (isPostpone){
            case "是":
                entity.setIsPostpone("Y");
                break;
            case "否":
                entity.setIsPostpone("N");
                break;
        }
        String state = entity.getState();
        switch (state){
            case "待审核":
                entity.setState("1000");
                break;
            case "审核不通过":
                entity.setState("2000");
                break;
            case "装修中":
                entity.setState("3000");
                break;
            case "待验收":
                entity.setState("4000");
                break;
            case "验收成功":
                entity.setState("5000");
                break;
            case "验收失败":
                entity.setState("6000");
                break;
        }

        return rm.updateRenoById(entity);
    }

    @Override
    public boolean updateByRId(String rId) {
        // 首先查询记录是否存在
        RoomRenovation entity = getById(rId);
        if (entity == null) {
            throw new ResourceNotFoundException("rId不存在");
        }
        // 调用删除方法
        return rm.updateByRId(rId);
    }

    @Override
    public boolean updateStatus(String rId, String state, String examineRemark) {
        switch (state){
            case "审核通过":
                state = "3000";
                break;
            case "审核不通过":
                state = "2000";
                break;
            default:
                break;
        }
        // 查询记录是否存在
        RoomRenovation entity = getById(rId);
        if (entity == null) {
            throw new ResourceNotFoundException("rId不存在");
        }
        return rm.updateStatus(rId, state, examineRemark);
    }

    /**
     * 将实体转换为DTO并处理状态转换
     * @param entity 实体类
     * @return 返回DTO
     */
    private RenovationDTO convertToDTO(RoomRenovation entity) {
        // 1. 使用MapStruct进行基本字段映射
        RenovationDTO dto = ms.renovationToDTO(entity);

        // 2. 处理状态转换（替换状态码为中文状态名）
        String stateCode = entity.getState();
        String stateName = convertStateCodeToName(stateCode);
        String isViolationCode = entity.getIsViolation();
        String isViolationName = convertIsViolationCodeToName(isViolationCode);
        String isPostponeCode = entity.getIsPostpone();
        String isPostponeName = convertIsPostponeCodeToName(isPostponeCode);

        // 3. 设置状态名到DTO
        dto.setState(stateName);
        dto.setIsViolation(isViolationName);
        dto.setIsPostpone(isPostponeName);
        dto.setCreateTime(entity.getCreateTime());

        return dto;
    }

    /**
     * state状态码转中文描述
     * @param stateCode state
     * @return 中文描述
     */
    private String convertStateCodeToName(String stateCode) {
        if (StringUtils.isEmpty(stateCode)) return "";

        switch (stateCode) {
            case "1000":
                return "待审核";
            case "2000":
                return "审核不通过";
            case "3000":
                return "装修中";
            case "4000":
                return "待验收";
            case "5000":
                return "验收成功";
            case "6000":
                return "验收失败";
            default:
                return "未知状态";
        }
    }

    /**
     * 是否违规状态码转中文描述
     * @param isViolationCode Y或者N
     * @return 中文描述
     */
    private String convertIsViolationCodeToName(String isViolationCode) {
        if (StringUtils.isEmpty(isViolationCode)) return "";

        switch (isViolationCode) {
            case "Y":
                return "违规";
            case "N":
                return "正常";
            default:
                return "未知状态";
        }
    }

    /**
     * 是否延期状态码转中文描述
     * @param isPostponeCode Y或者N
     * @return 中文描述
     */
    private String convertIsPostponeCodeToName(String isPostponeCode) {
        if (StringUtils.isEmpty(isPostponeCode)) return "";

        switch (isPostponeCode) {
            case "Y":
                return "延期";
            case "N":
                return "正常";
            default:
                return "未知状态";
        }
    }
}
