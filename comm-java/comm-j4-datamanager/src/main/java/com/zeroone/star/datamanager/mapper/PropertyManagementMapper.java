package com.zeroone.star.datamanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.datamanager.entity.MMenuGroupCommunity;
import com.zeroone.star.datamanager.entity.SStore;
import com.zeroone.star.project.query.j4.datamanager.CompanyQuery;
import com.zeroone.star.project.query.j4.datamanager.JoinCommunityQuery;
import com.zeroone.star.project.query.j4.datamanager.NoJoinCommunityQuery;
import com.zeroone.star.project.vo.j4.datamanager.CommunityMenuGroup;
import com.zeroone.star.project.vo.j4.datamanager.CompanyVO;
import com.zeroone.star.project.vo.j4.datamanager.JoinCommunityVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;
import java.util.Map;

@Mapper
public interface PropertyManagementMapper extends BaseMapper<MMenuGroupCommunity> {

    Long countCompanies(@Param("query") CompanyQuery query);
    List<CompanyVO> getCompanyList(@Param("query") CompanyQuery query,
                                   @Param("offset") Long offset,
                                   @Param("pageSize") Long pageSize);

    void insert(SStore sStore);

    MMenuGroupCommunity selectByCommunityNameAndId(@Param("communityName") String communityName);

    int updateByStoreId(Map<String, Object> params);


    List<JoinCommunityVO> queryJoinCommunityList(
            @Param("pageIndex") Long pageIndex,
            @Param("pageSize") Long pageSize,
            @Param("query")  JoinCommunityQuery query);

    @Select("select name from s_community left join s_community_member on " +
            "s_community_member.community_id = s_community.community_id " +
            "where s_community_member.community_member_id = #{query.communityMemberId}" +
            " and s_community.status_cd = '1'")
    List<String> queryNoJoinCommunityList(@Param("query") NoJoinCommunityQuery query);

    @Update("update s_community set status_cd = '0' " +
            "where community_id = #{communityId}")
    void updateJoinCommunity(String communityId);



    @Update("update s_community set status_cd = '1' " +
            "where community_id = #{communityId}")
    void updateQuitJoinCommunity(String communityId);

    List<CommunityMenuGroup> selectCommunityMenuGroup(@Param("communityId") String communityId);


    void insertMenuGroupCommunity( List<MMenuGroupCommunity> mMenuGroupCommunityList);
    void deleteByStoreId(@Param("storeId") String storeId);

    void limitCompanyLogin(@Param("storeId") String storeI, String operate);

    void resetCompanyPassword(@Param("storeId") String storeId, String password);
    SStore selectByStoreId(String storeId);

    List<String> selectExistFunctions(@Param("functionNames") List<String> functionNames);
}
