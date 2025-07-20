package com.zeroone.star.menumana.service;

import com.zeroone.star.menumana.entity.GroupCatalog;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogAddDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogDelDTO;
import com.zeroone.star.project.query.j1.menumana.menudir.GroupCatalogQuery;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogAddVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogDelVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogQueryVO;

import java.util.List;

public interface IGroupCatalogService {
    /**
     * 查询对应菜单组
     */
    PageDTO<GroupCatalogQueryVO> listMenuCatalogGroup(GroupCatalogQuery groupCatalogQuery);
    /**
     * 添加对应菜单组
     */
    GroupCatalogAddVO saveMenuCatalogGroup(GroupCatalogAddDTO groupCatalogAddDTO);
    /**
     * 删除对应菜单组
     */
    GroupCatalogDelVO removeMenuCatalogGroup(GroupCatalogDelDTO groupCatalogDelDTO);
}
