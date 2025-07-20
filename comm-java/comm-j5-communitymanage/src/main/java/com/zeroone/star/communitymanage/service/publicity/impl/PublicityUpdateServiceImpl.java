package com.zeroone.star.communitymanage.service.publicity.impl;

import com.zeroone.star.communitymanage.mapper.publicity.PublicityUpdateMapper;
import com.zeroone.star.communitymanage.service.publicity.PublicityUpdateService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j5.community.publicity.AddPublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.DeletePublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.PublicityBaseDTO;
import com.zeroone.star.project.dto.j5.community.publicity.UpdatePublicityDTO;
import com.zeroone.star.communitymanage.entity.publicity.CommunityPublicity;
import com.zeroone.star.communitymanage.utils.IdUtil;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

/**
 * 小区公示服务实现类
 * 提供添加、修改、删除公示的功能
 *
 * @author yu
 * @date 2025-05-23
 */
@Service
public class PublicityUpdateServiceImpl implements PublicityUpdateService {

    @Resource
    private PublicityUpdateMapper publicityUpdateMapper;

    @Resource
    private UserHolder userHolder;

    /**
     * 添加公示
     *
     * @param addPublicityDTO 添加公示数据传输对象
     */
    @Transactional(rollbackFor = Exception.class)
    @Override
    public void add(AddPublicityDTO addPublicityDTO) {
        try {
            // 获取当前用户信息
            UserDTO user = userHolder.getCurrentUser();
            if (user == null) {
                throw new RuntimeException("当前用户未登录，无法添加公示信息");
            }

            // 生成公示ID
            String pubId = IdUtil.getSnowflakeId();

            // 设置DTO中的用户字段
            addPublicityDTO.setCreateUserId(String.valueOf(user.getId()));
            addPublicityDTO.setCreateUserName(user.getUsername());

            // 转换实体并插入数据库
            CommunityPublicity communityPublicity = new CommunityPublicity();
            communityPublicity.setPubId(pubId);
            BeanUtils.copyProperties(addPublicityDTO, communityPublicity);
            int rows = publicityUpdateMapper.save(communityPublicity);
            if (rows == 0) {
                throw new RuntimeException("添加失败：数据库未插入任何记录");
            }
        } catch (Exception e) {
            throw new RuntimeException("获取当前用户失败，无法完成添加操作", e);
        }
    }

    /**
     * 修改公示
     *
     * @param updatePublicityDTO 修改公示数据传输对象
     */
    @Transactional(rollbackFor = Exception.class)
    @Override
    public void update(UpdatePublicityDTO updatePublicityDTO) {
        // 校验是否存在该数据
        CommunityPublicity publicity = publicityUpdateMapper.
                selectByPubIdAndCommunityId(updatePublicityDTO.getPubId(), updatePublicityDTO.getCommunityId());

        if (publicity == null) {
            throw new RuntimeException("该公示信息不存在");
        }

        if (Integer.parseInt(publicity.getStatusCd()) != 0) {
            throw new RuntimeException("该公示信息已被删除");
        }

        int rows = publicityUpdateMapper.update(updatePublicityDTO);
        if (rows == 0) {
            throw new RuntimeException("数据库操作未成功");
        }
    }

    /**
     * 删除公示（逻辑删除）
     *
     * @param deletePublicityDTO 删除公示数据传输对象
     */
    @Transactional(rollbackFor = Exception.class)
    @Override
    public void remove(DeletePublicityDTO deletePublicityDTO) {
        // 校验是否存在未被删除的数据
        CommunityPublicity publicity = publicityUpdateMapper.
                selectByPubIdAndCommunityId(deletePublicityDTO.getPubId(), deletePublicityDTO.getCommunityId());

        if (publicity == null) {
            throw new RuntimeException("该公示信息不存在");
        }

        if (Integer.parseInt(publicity.getStatusCd()) != 0) {
            throw new RuntimeException("该公示信息已被删除");
        }

        // 执行逻辑删除
        int rows = publicityUpdateMapper.remove(deletePublicityDTO);
        if (rows == 0) {
            throw new RuntimeException("数据库操作未成功");
        }
    }

}
