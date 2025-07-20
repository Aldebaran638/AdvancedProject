package com.zeroone.star.communitymanage.service.mycommunity;

import com.baomidou.mybatisplus.extension.service.IService;

import com.zeroone.star.communitymanage.entity.mycommunity.SCommunity;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.mycommunity.MyCommunityDTO;
import com.zeroone.star.project.query.j5.community.mycommunity.AllMyCommunityQuery;
import com.zeroone.star.project.query.j5.community.mycommunity.MyCommunityQuery;
import com.zeroone.star.project.vo.j5.community.mycommunity.AllMyCommunityVO;
import com.zeroone.star.project.vo.j5.community.mycommunity.MyCommunityVO;

public interface MyCommunityService extends IService<SCommunity> {
    /**
     * 根据小区id查询我的小区信息
     * @param query 查询条件
     * @return 我的小区数据展示模型
     */
    PageDTO<MyCommunityVO> getMyCommunity(MyCommunityQuery query);

    /**
     * 修改入驻小区
     * @param myCommunityDTO 修改我的小区数据模型
     * @return 修改结果
     */
    boolean updateMyCommunity(MyCommunityDTO myCommunityDTO);

    /**
     * 根据当前登录用户查询所有我的小区信息
     * @param query 查询我的所有小区信息的参数
     * @return 我的所有小区数据展示模型
     */
    PageDTO<AllMyCommunityVO> listMyCommunity(AllMyCommunityQuery query);
}
