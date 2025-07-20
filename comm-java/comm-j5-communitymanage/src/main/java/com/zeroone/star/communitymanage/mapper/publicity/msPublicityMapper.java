package com.zeroone.star.communitymanage.mapper.publicity;

import com.zeroone.star.project.dto.j5.community.publicity.PublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityDetailDTO;

import com.zeroone.star.communitymanage.entity.publicity.CommunityPublicity;
import org.mapstruct.Mapper;


/**
 * ClassName: msPublicityMapper
 * Package: com.zeroone.star.publicity.mapper
 * Description:
 *
 * @Author wuguanfengyue
 * @Create 2025/5/26 21:43
 * @Version 1.0
 */
@Mapper(componentModel = "spring")
public interface msPublicityMapper {

    /**
     * 公示实体entity 变成 列表展示DTO
     * @param publicity 公示实体
     * @return 公示DTO
     */
    PublicityDTO publicityToDTO(CommunityPublicity publicity);

    /**
     * 公示实体entity 变成 详情展示DTO
     * @param publicity 公示实体
     * @return 公示详情DTO
     */
    PublicityDetailDTO publicityToDetailDTO(CommunityPublicity publicity);


}
