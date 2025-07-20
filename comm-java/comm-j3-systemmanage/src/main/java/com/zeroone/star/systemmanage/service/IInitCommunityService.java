package com.zeroone.star.systemmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.systemmanage.initcommunity.InitializedCommunityDTO;
import com.zeroone.star.project.query.j3.systemmanage.initcommunity.InitializedCommunityPageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanage.entity.SCommunityDO;

public interface IInitCommunityService extends IService<SCommunityDO> {

    /**
     * 查询小区列表
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<InitializedCommunityDTO>> listAll(InitializedCommunityPageQuery query);

    /**
     * 格式化小区数据
     * @param communityId
     * @param password
     * @return
     */
    JsonVO<String> removeData(String communityId, String password);
}
