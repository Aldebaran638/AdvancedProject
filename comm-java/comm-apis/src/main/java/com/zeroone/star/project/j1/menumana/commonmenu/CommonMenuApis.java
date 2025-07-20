package com.zeroone.star.project.j1.menumana.commonmenu;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.AddCommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.MixMenuDTO;
import com.zeroone.star.project.query.j1.menumana.commonmenu.CommonMenuQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface CommonMenuApis {
    /**
     * 分页查询菜单
     * @param query 查询常用菜单数据对象
     * @return 查询结果
     */
    JsonVO<PageDTO<CommonMenuDTO>> queryCommonMenuList(CommonMenuQuery query) ;

    /**
     * 查询所有菜单组-菜单名称
     * @return
     */
    JsonVO<List<MixMenuDTO>> queryMixMenu();

    /**
     * 添加常用菜单
     * @param addCommonMenuDTO 添加常用菜单数据对象
     * @return 添加结果
     */
    JsonVO<String> addCommonMenu(AddCommonMenuDTO addCommonMenuDTO);

    /**
     * 删除常用菜单
     * @param muId 菜单编号
     * @return
     */
    JsonVO<String> removeCommonMenu(String muId);
}
