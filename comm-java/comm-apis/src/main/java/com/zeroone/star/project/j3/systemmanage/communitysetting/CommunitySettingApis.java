package com.zeroone.star.project.j3.systemmanage.communitysetting;

import com.zeroone.star.project.dto.j3.systemmanage.communitysetting.UpdateCommunitySettingDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingKeyVo;
import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingVo;

import java.util.List;

public interface CommunitySettingApis {
    /**
     * 获取配置项列表
     * @param communityId 小区ID（必填）
     * @return 配置项列表
     */
    JsonVO<List<CommunitySettingKeyVo>> queryCommunitySettingKeyList(String communityId);

    /**
     * 获取配置项数据
     * @param communityId 小区ID（必填）
     * @param settingType 设置类型（可选）
     * @return 配置项数据列表
     */
    JsonVO<List<CommunitySettingVo>> queryCommunitySettingList(String communityId, String settingType);

    /**
     * 提交配置项修改
     * @param updateCommunitySettingDTO 更新参数
     * @return 处理结果，成功返回修改成功，失败返回错误信息
     */
    JsonVO<String> modifyCommunitySetting(UpdateCommunitySettingDTO updateCommunitySettingDTO);
}
