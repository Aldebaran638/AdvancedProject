package com.zeroone.star.menumana.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.menumana.entity.MenuItem;
import com.zeroone.star.project.dto.j1.menumana.menuitem.AddMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.DeleteMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.ModifyMenuItemDTO;
import com.zeroone.star.project.query.j1.menumana.menuitem.MenuItemQuery;
import org.apache.ibatis.annotations.*;


import java.util.List;

/**
 * @Description
 * @Author eu
 * @Date 2025/5/25
 */
@Mapper
public interface MenuItemMapper extends BaseMapper<MenuItem> {
//    @Select("")
//    List<MenuItemDTO> selectMenuItem(MenuItemQuery query);
//
//    @Insert("")
//    Integer insertMenuItem(AddMenuItemDTO addMenuItemDTO);
//
//    @Delete("")
//    Integer deleteMenuItem(DeleteMenuItemDTO deleteMenuItemDTO);
//
//    @Update("")
//    Integer updateMenuItem(ModifyMenuItemDTO modifyMenuItemDTO);
      @Select("select * from m_menu where name = #{name}")
      MenuItem selectByName(String name);

      @Select("SELECT m.name AS menuName,mg.name AS groupName,m_id,st.name AS storeType,url,m.seq,m.is_show " +
              "FROM m_menu m " +
              "JOIN m_menu_group mg ON m.g_id = mg.g_id " +
              "JOIN store_type st ON mg.store_type = st.store_type_cd "+
              "where mg.name=#{groupName} and m.name like CONCAT('%',#{menuName},'%') "+
              "ORDER BY m.seq ASC"
      )
      Page<MenuItem> pageQuery(Page<?>page,String groupName, String menuName);
}
