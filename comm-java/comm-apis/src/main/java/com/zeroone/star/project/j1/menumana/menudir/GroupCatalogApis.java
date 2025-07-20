package com.zeroone.star.project.j1.menumana.menudir;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogAddDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogDelDTO;
import com.zeroone.star.project.query.j1.menumana.menudir.GroupCatalogQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogAddVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogDelVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogQueryVO;
import org.springframework.validation.BindingResult;

import java.util.List;

/**
 * 菜单组目录API
 */
public interface GroupCatalogApis {
    /**
     * 获取对应菜单组列表(条件+分页)
     * @param groupCatalogQuery 查询请求参数
     * @return 查询响应参数
     */
    JsonVO<PageDTO<GroupCatalogQueryVO>> queryGroupCatalog(GroupCatalogQuery groupCatalogQuery, BindingResult bindingResult);
    /**
     * 添加对应菜单组
     * @param groupCatalogAddDTO 添加请求参数
     * @return 添加响应参数
     */
    JsonVO<GroupCatalogAddVO> addGroupCatalog(GroupCatalogAddDTO groupCatalogAddDTO,BindingResult bindingResult);
    /**
     * 删除对应菜单组
     * @param groupCatalogDelDTO 删除请求参数
     * @return 删除响应参数
     */
    JsonVO<GroupCatalogDelVO> removeGroupCatalog(GroupCatalogDelDTO groupCatalogDelDTO,BindingResult bindingResult);
}
