package com.zeroone.star.systemmanage.service;

import com.zeroone.star.project.dto.j3.systemmanage.communitysetting.UpdateCommunitySettingItemDTO;
import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingVo;

import java.util.List;

/**
 * 小区配置服务实现类
 */
public interface CommunitySettingService {
    /**
     * 查询小区配置列表
     *
     * @param communityId 小区ID
     * @param settingType 设置类型
     * @return 小区配置列表
     */
    List<CommunitySettingVo> queryCommunitySettingList(String communityId, String settingType);

    /**
     * 更新小区配置
     *
     * @param dto 更新参数DTO
     * @return 成功返回"success"，失败返回错误信息
     */
    String updateCommunitySetting(List<UpdateCommunitySettingItemDTO> dto);
}
