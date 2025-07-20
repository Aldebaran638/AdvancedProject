package com.zeroone.star.project.j3.systemmanage.initcommunity;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.systemmanage.initcommunity.InitializedCommunityDTO;
import com.zeroone.star.project.query.j3.systemmanage.initcommunity.InitializedCommunityPageQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 初始化小区相关接口
 */
public interface InitCommunityApis {
    /**
     * 分页查询小区数据
     * @param query
     * @return
     */
    public JsonVO<PageDTO<InitializedCommunityDTO>> queryCommunities(InitializedCommunityPageQuery query);

    /**
     * 格式化小区及其相关数据
     * @param communityId
     * @param password
     * @return
     */
    public JsonVO<String> removeData(String communityId, String password);
}
