package com.zeroone.star.menumana.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.menumana.entity.EasyMenu;
import com.zeroone.star.menumana.entity.UserMenu;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;


@Mapper
public interface ICommonMenuMapper extends BaseMapper<UserMenu> {

    @Select("select name from m_menu_group where g_id=#{gId}")
    String selectGroupName(String gId);

    @Select("select name from m_menu where m_id = #{mId}")
    String selectName(String mId);

    @Select("select url from m_menu where m_id = #{mId}")
    String selectUrl(String mId);

    @Select("select m_id,name,g_id from m_menu where url like '%dev%'")
    List<EasyMenu> selectByUrl(String url);

    @Select("select url from m_menu_user where staff_id = #{staffId}")
    List<String> pIdSelectUrl(String staffId);

}
