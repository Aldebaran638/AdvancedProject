package com.zeroone.star.communityinfo.service;

import com.zeroone.star.communityinfo.entity.SCommunity;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j5.info.communityinfo.AddCommunityDTO;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author j5-guoba
 * @since 2025-05-23
 */
public interface CommunityInfoUpdateService extends IService<SCommunity> {

    String saveCommunity(AddCommunityDTO addCommunityDTO);

    String updateCommunity(CommunityDTO communityDTO);

    String removeCommunity(String communityId);
}
