package com.zeroone.star.menumana.mapper.MenuPriviliegeTree;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.menumana.entity.MenuTree;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Service;

import java.util.List;

@Mapper
public interface MenuMapper extends BaseMapper<MenuTree> {
    //连表查询获取所有菜单组、菜单和权限信息
    List<MenuTree> getAllMenus();

    //根据菜单id获取菜单名称
    @Select("SELECT name FROM m_menu WHERE m_id = #{menuId}")
    String getMenuNameById(String menuId);

    //根据菜单id获取菜单顺序
    @Select("SELECT seq FROM m_menu WHERE m_id = #{menuId}")
    String getMenuSeqById(String menuId);
}
