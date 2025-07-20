package com.zeroone.star.datamanager.service;


import com.zeroone.star.datamanager.entity.SStore;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.datamanager.CommunityMenuGroupDTO;
import com.zeroone.star.project.dto.j4.datamanager.CompanyDTO;
import com.zeroone.star.project.query.j4.datamanager.CompanyQuery;
import com.zeroone.star.project.query.j4.datamanager.JoinCommunityQuery;
import com.zeroone.star.project.query.j4.datamanager.NoJoinCommunityQuery;
import com.zeroone.star.project.vo.j4.datamanager.CommunityMenuGroup;
import com.zeroone.star.project.vo.j4.datamanager.CompanyVO;
import com.zeroone.star.project.vo.j4.datamanager.JoinCommunityVO;

import java.util.List;

public interface PropertyManagementService {

    /**
     * 获取物业公司（条件+分页接口）
     *
     * @param query
     * @return
     */
    PageDTO<CompanyVO> getCompanyList(CompanyQuery query);


    /**
     * 分页查询物业公司
     *
     * @param dto
     * @return
     */
    void addCompany(CompanyDTO dto) throws Exception;


    /**
     * 修改物业公司
     *
     * @param dto
     * @return
     */
    SStore modifyCompany(CompanyDTO dto, String storeId) throws Exception;

    /**
     * 分页查询加入小区列表
     *
     * @param query
     * @return
     */
    PageDTO<JoinCommunityVO> queryJoinCommunityList(Long pageNum, Long pageSize, JoinCommunityQuery query);

    /**
     * 查询加入未小区列表
     * @param query
     * @return
     */
    List<String> queryNoJoinCommunityList(NoJoinCommunityQuery query);

    /**
     * 添加小区
     * @param dto
     */
    void becomeJoinCommunity(CommunityMenuGroupDTO dto);

    /**
     * 退出小区
     *
     * @param communityId
     */

    void quitJoinCommunity(String communityId);

    /**
     * 获取小区功能
     * @param query
     * @return
     */
    List<CommunityMenuGroup> getCommunityMenuGroup(String query);

    /**
     * 修改小区功能
     * @param dto
     */
    void updateCommunityMenuGroup(CommunityMenuGroupDTO dto);
    /**
     * 删除物业公司
     *
     * @param storeId
     * @return
     */
    void deleteCompany(String storeId);

    /**
     * 限制物业登录
     *
     * @param storeId
     * @return
     */
    void limitCompanyLogin(String storeId,String operate);

    /**
     * 重置物业公司密码
     *
     * @param storeId
     * @return
     */
    String resetCompanyPassword(String storeId);
}
