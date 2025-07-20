package com.zeroone.star.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface CommonmenuMapper extends BaseMapper<CommonMenuDTO> {

    List<CommonMenuDTO> selectCommonmenuAll(String menuGroupId);
@Select("SELECT g_id FROM m_menu_group WHERE name = #{menuname}")
    String getcommonmenuId(String menuname);
}
