package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.RelatedUnitAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.RelatedUnitDTO;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.NoRelatedUnitQuery;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.RelatedUnitQuery;
import com.zeroone.star.project.vo.j2.orgmanager.dataPriviledge.RelatedUnitVO;
import org.apache.ibatis.annotations.*;

@Mapper
public interface RelatedUnitMapper {

    Page<RelatedUnitVO> queryRelatedUnitList(Page<RelatedUnitVO> page, @Param("query") RelatedUnitQuery query);

    @Insert("insert into data_privilege_unit(unit_id,floor_num,unit_num,floor_id,dp_id,status_cd,create_time,community_id,b_id,dp_unit_id)"+
            "values(#{unitId},#{floorNum},#{unitNum},#{floorId},#{dpId},#{statusCd},#{createTime},#{communityId},#{bId},#{dpUnitId})"
    )
    void addRelatedUnit(RelatedUnitDTO relatedUnitDTO);

    @Update("update data_privilege_unit set status_cd = '1' where dp_unit_id = #{dpUnitId}")
    void removeRelatedUnit(String dpUnitId);

    Page<RelatedUnitVO> queryNoRelatedUnitList(Page<RelatedUnitVO> page, @Param("query")NoRelatedUnitQuery query);

    @Select("select community_id from data_privilege where dp_id = #{dpId} and status_cd = #{statusCd}")
    String getCommunityIdBydpId(String dpId, String statusCd);

    String getUnitId(String unitNum, String floorNum,String communityId);

    String getFloorId(String unitNum, String floorNum,String communityId);
}
