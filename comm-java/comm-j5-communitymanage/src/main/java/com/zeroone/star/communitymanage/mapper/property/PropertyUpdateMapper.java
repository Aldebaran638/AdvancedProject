package com.zeroone.star.communitymanage.mapper.property;

import com.zeroone.star.communitymanage.entity.property.*;
import org.apache.ibatis.annotations.*;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author Jungle
 * @since 2025-05-24
 */
@Mapper
public interface PropertyUpdateMapper  {

    /**
     * 添加产权登记
     */
    @Insert("insert into property_right_registration(prr_id,room_id,name,link,id_card,address,status_cd,community_id,create_user,state)" +
            "values(#{prrId},#{roomId},#{name},#{link},#{idCard},#{address},#{statusCd},#{communityId},#{createUser},#{state})")
    void insertPrr(PropertyRightRegistration prr);

    /**
    添加产权详情
     */
    @Insert("insert into property_right_registration_detail(prrd_id,prr_id,securities,is_true,create_user,status_cd)"+
            "values(#{prrdId},#{prrId},'001',-1,#{createUser},#{statusCd})," +
            "(#{prrdId},#{prrId},'002',-1,#{createUser},#{statusCd})," +
            "(#{prrdId},#{prrId},'003',#{fundIsPaid},#{createUser},#{statusCd})," +
            "(#{prrdId},#{prrId},'004',#{taxIsPaid},#{createUser},#{statusCd})")
    @Options(useGeneratedKeys = true, keyProperty = "prrdId")
    void insertPrrd(PropertyRightRegistrationDetail prrd);


    /**
    添加产权登记业务
     */
    @Insert("insert into business_property_right_registration(prr_id,b_id,room_id,name,link,id_card,address,status_cd,community_id,create_user,operate,state)" +
            "values(#{prrId},#{bId},#{roomId},#{name},#{link},#{idCard},#{address},#{statusCd},#{communityId},#{createUser},#{operate},#{state})")
    void insertBPrr(BusinessPropertyRightRegistration bprr);

    /**
     * 添加业务详情
     */
    @Insert("insert into business_property_right_registration_detail(prrd_id,prr_id,securities,create_user,operate,is_true)" +
            "values(#{prrdId},#{prrId},'001',#{createUser},#{operate},-1)," +
            "(#{prrdId},#{prrId},'002',#{createUser},#{operate},-1)," +
            "(#{prrdId},#{prrId},'003',#{createUser},#{operate},#{fundIsPaid})," +
            "(#{prrdId},#{prrId},'004',#{createUser},#{operate},#{taxIsPaid})")
    void insertBPrrd(BusinessPropertyRightRegistrationDetail bprrd);


    @Insert("insert into file_rel(file_rel_id,b_id,rel_type_cd,save_way,obj_id,file_real_name,file_save_name,status_cd)" +
            "values(#{fileRelId},#{bId},#{relTypeCd},#{saveWay},#{objId},#{fileRealName},#{fileSaveName},#{statusCd})")
    void insertFileRel(FileRel fileRel);




    /**
     * 删除产权登记
     */
    @Delete(("delete from property_right_registration" +
            " where prr_id=#{prrId}"))
    void deletePrrByprrId(String prrId);

    @Delete(("delete from property_right_registration_detail" +
            " where prr_id=#{prrId}"))
    void deletePrrdByprrId(String prrId);



    /**
     * 审核产权
     */
    @Update("update property_right_registration" +
            " set state=#{state}," +
            " remark=#{remark}" +
            " where prr_id=#{prrId}")
    int checkPrr(String prrId, String state, String remark);



    /**
     * 修改产权登记
     */
    @Update("update property_right_registration set " +
            "name=#{prr.name}, " +
            "link=#{prr.link}, " +
            "address=#{prr.address}, " +
            "id_card=#{prr.idCard}" +
            " where prr_id=#{prr.prrId} and room_id=#{roomId}")
    void updatePrr(PropertyRightRegistration prr, String roomId);

    /**
     * 修改附件项
     *
     * @return
     */
    @Update("update property_right_registration_detail set " +
            "is_true=#{isTrue}" +
            " where prrd_id=#{prrdId} and securities=#{securities}")
    int updateprrd(PropertyRightRegistrationDetail prrd);




    /**
     * 获取roomId相关查询
     */
    @Select("select floor_id from f_floor" +
            " where name=#{floorName} and community_id=#{communityId}")
    String selectFloorId(String floorName,String communityId);


    @Select("select  unit_id from building_unit" +
            " where floor_id=#{floorId} and unit_num=#{unitNum}")
    String selectUnitId(String floorId,String unitNum);


    @Select("select room_id from building_room" +
            " where room_num=#{roomNum} and unit_id=#{unitId}")
    String selectRoomId(String roomNum,String unitId);

    @Select("select * from property_right_registration" +
            " where prr_id=#{prrId} and community_id=#{communityId}")
    PropertyRightRegistration selectPropertyById(String prrId,String communityId);


    //获取产权登记业务数据和业务详情数据
    @Select("select * from business_property_right_registration" +
            " where prr_id =#{prrId}")
    BusinessPropertyRightRegistration selectBprr(String prrId);
    @Select("select * from business_property_right_registration_detail" +
            " where prr_id =#{prrId}")
    BusinessPropertyRightRegistrationDetail selectBprrd(String prrId);


}
