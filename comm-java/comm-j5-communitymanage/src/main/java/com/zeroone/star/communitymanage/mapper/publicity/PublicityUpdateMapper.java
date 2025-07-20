package com.zeroone.star.communitymanage.mapper.publicity;

import com.zeroone.star.project.dto.j5.community.publicity.DeletePublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.UpdatePublicityDTO;
import com.zeroone.star.communitymanage.entity.publicity.CommunityPublicity;
import org.apache.ibatis.annotations.*;

/**
 * @description: 小区公示的持久层
 * @author: yu
 * @date: 2025年05月23日 09:36
 */
@Mapper
public interface PublicityUpdateMapper {
    /**
     * @description: 添加小区公示
     * @title: save
     * @param: [addPublicityDTO]
     */
    @Insert("insert into community_publicity(pub_id, title, pub_type, header_img, context, community_id, create_user_id, create_user_name) " +
            "values " +
            "(#{pubId}, #{title}, #{pubType}, #{headerImg}, #{context}, #{communityId}, #{createUserId}, #{createUserName})")
    int save(CommunityPublicity communityPublicity);

    /**
     * @description: 修改小区公示
     * @title: update
     * @param: [updatePublicityDTO]
     */
    @Update("update community_publicity " +
            "set title=#{title}, pub_type=#{pubType}, header_img=#{headerImg}, context=#{context} " +
            "where pub_id = #{pubId} AND community_id = #{communityId} AND status_cd = 0")
    int update(UpdatePublicityDTO updatePublicityDTO);

    /**
     * @description: 逻辑删除小区公示
     * @title: remove
     * @param: [deletePublicityDTO]
     */
    @Select("SELECT pub_id, community_id, status_cd " +
            "FROM community_publicity " +
            "WHERE pub_id = #{pubId} AND community_id = #{communityId};")
    CommunityPublicity selectByPubIdAndCommunityId(@Param("pubId") String pubId,
                                                   @Param("communityId") String communityId);

    @Update("UPDATE community_publicity " +
            "SET status_cd = 1 " +
            "WHERE pub_id = #{pubId} AND community_id = #{communityId} AND status_cd = 0")
    int remove(DeletePublicityDTO deletePublicityDTO);

}
