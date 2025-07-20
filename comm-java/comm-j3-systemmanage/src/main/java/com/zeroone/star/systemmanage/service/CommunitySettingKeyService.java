package com.zeroone.star.systemmanage.service;

import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingKeyVo;

import java.util.List;

/**
 * 获取配置项列表
 */
public interface CommunitySettingKeyService {
    /**
     * 查询小区配置键值
     * @param communityId 小区ID
     * @return 配置键值列表
     */
    List<CommunitySettingKeyVo> queryCommunitySettingKeyList(String communityId);
}
