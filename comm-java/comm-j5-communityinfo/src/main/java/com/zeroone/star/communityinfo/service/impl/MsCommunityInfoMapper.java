package com.zeroone.star.communityinfo.service.impl;

import com.zeroone.star.communityinfo.entity.SCommunity;
import com.zeroone.star.project.dto.j5.info.communityinfo.AddCommunityDTO;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityDTO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityInfoVO;
import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：小区信息 数据类型转换映射接口
 * </p>
 * @author yuezi & guoba
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsCommunityInfoMapper {
    /**
     * 将实体类转换为CommunityInfoVO
     * @param sCommunity 小区实体类
     * @return 转换结果
     */
    CommunityInfoVO sCommunityToVO(SCommunity sCommunity);

    /**
     * 将Add DTO转换为实体类
     * @param addDto Add DTO
     * @return 转换结果
     */
    SCommunity addDtoToDo(AddCommunityDTO addDto);

    /**
     * 将DTO转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    SCommunity dtoToDo(CommunityDTO dto);
}
