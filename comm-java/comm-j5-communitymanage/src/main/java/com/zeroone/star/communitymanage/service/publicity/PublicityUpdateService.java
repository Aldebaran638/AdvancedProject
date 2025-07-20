package com.zeroone.star.communitymanage.service.publicity;

import com.zeroone.star.project.dto.j5.community.publicity.AddPublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.DeletePublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.UpdatePublicityDTO;

/**
 * @description: 小区公示的服务层接口
 * @author: yu
 * @date: 2025年05月23日 09:36
 */
public interface PublicityUpdateService {
    /**
     * @description: 添加公示
     * @title: add
     * @param: [addPublicityDTO]
     */
    void add(AddPublicityDTO addPublicityDTO);

    /**
     * @description: 修改公示
     * @title: update
     * @param: [updatePublicityDTO]
     */
    void update(UpdatePublicityDTO updatePublicityDTO);

    /**
     * @description: 删除公示
     * @title: remove
     * @param: [deletePublicityDTO]
     */
    void remove(DeletePublicityDTO deletePublicityDTO);
}
