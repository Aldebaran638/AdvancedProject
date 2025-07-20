package com.zeroone.star.project.j5.info.communityinfo;

import com.zeroone.star.project.dto.j5.info.communityinfo.AddCommunityDTO;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：小区信息接口
 *      锅巴：添加小区、修改小区、删除小区
 * </p>
 * @author 锅巴
 * @version 1.0.0
 */
public interface CommunityInfoUpdateApis {
    /**
     * 添加小区
     * @param addCommunityDTO 添加小区数据传输模型
     * @return 添加结果
     */
    JsonVO<String> addCommunity(AddCommunityDTO addCommunityDTO);

    /**
     * 修改小区
     * @param communityDTO 修改小区数据传输模型
     * @return 修改结果
     */
    JsonVO<String> modifyCommunity(CommunityDTO communityDTO);

    /**
     * 删除小区
     * @param communityId 小区ID
     * @return 删除结果
     */
    JsonVO<String> removeCommunity(String communityId);
}
