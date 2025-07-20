package com.zeroone.star.project.j4.datamanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.datamanager.*;
import com.zeroone.star.project.query.j4.datamanager.CompanyQuery;
import com.zeroone.star.project.query.j4.datamanager.JoinCommunityQuery;
import com.zeroone.star.project.query.j4.datamanager.NoJoinCommunityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.datamanager.CommunityMenuGroup;
import com.zeroone.star.project.vo.j4.datamanager.CompanyVO;
import com.zeroone.star.project.vo.j4.datamanager.JoinCommunityVO;

import java.util.List;

/**
 * @Author: dashuai
 * @Description: 物业公司接口
 * 包含获取物业公司列表、添加物业公司、修改物业公司、删除物业公司、限制物业登录、重置物业密码、
 * 获取加入小区列表、加入小区、退出小区、修改小区功能
 * 负责人：
 * 慢慢升空、叶落孤城、玺朽
 */
public interface PropertyManagementApis {
    // 玺朽

    /**
     * 获取加入小区列表
     *
     * @param pageIndex
     * @param pageSize
     * @param query
     * @return 获取加入小区列表
     */
    JsonVO<PageDTO<JoinCommunityVO>> getJoinCommunityList(long pageIndex, long pageSize, JoinCommunityQuery query);

    /**
     * 获取未加入小区列表
     *
     * @param query
     * @return
     */
    JsonVO<List<String>> getNoJoinCommunityList(NoJoinCommunityQuery query);

    /**
<<<<<<< HEAD
     * 添加加入小区
=======
     * 成为加入小区
     *
>>>>>>> j4-PhoenixMao
     * @param dto
     * @return ok
     */

    JsonVO<String> addJoinCommunity(CommunityMenuGroupDTO dto);

    /**
     * 退出小区
<<<<<<< HEAD
     * @param communityId
=======
     *
     * @param dto
>>>>>>> j4-PhoenixMao
     * @return ok
     */
    JsonVO<String> quitJoinCommunity(String communityId);

    /**
     * 获取小区属性
     *
     * @param query
     * @return 小区属性
     */
    JsonVO<List<CommunityMenuGroup>> getCommunityMenuGroup(String query);

    /**
     * 修改小区属性
     *
     * @param dto
     * @return ok
     */
    JsonVO<String> updateCommunityMenuGroup(CommunityMenuGroupDTO dto);
    //玺朽

    // 慢慢升空
    /**
     * 获取物业公司列表（条件+分页接口）
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<CompanyVO>> getCompanyList(CompanyQuery query);


    /**
     * 新增物业公司
     *
     * @param dto
     * @return
     */
    JsonVO<String> addCompany(CompanyDTO dto);

    /**
     * 修改物业公司
     *
     * @param dto
     * @return
     */
    JsonVO<String> modifyCompany(String storeId, CompanyDTO dto);
    // 慢慢升空

    //叶落孤城

    /**
     * 删除物业公司
     *
     * @param String
     * @return
     */
    JsonVO<String> deleteCompany(String storeId);

    /**
     * 限制物业登录
     *
     * @param storeId,operate
     * @return
     */
    JsonVO<String> limitCompanyLogin(String storeId, String operate);

    /**
     * 重置物业密码
     *
     * @param storeId
     * @return
     */
    JsonVO<String> resetCompanyPassword(String storeId);
    //叶落孤城
}
