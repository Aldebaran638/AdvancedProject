package com.zeroone.star.menumana.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.menumana.entity.MenuGroup;
import com.zeroone.star.menumana.entity.MenuItem;
import com.zeroone.star.menumana.entity.Privilege;
import com.zeroone.star.menumana.entity.StoreType;
import com.zeroone.star.menumana.mapper.*;
import com.zeroone.star.menumana.service.IMenuItemService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.AddMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.DeleteMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.ModifyMenuItemDTO;
import com.zeroone.star.project.query.j1.menumana.menuitem.MenuItemQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.Date;
import java.util.List;

/**
 * @Description
 * @Author eu
 * @Date 2025/5/25
 */
@Service
public class MenuItemServiceImpl  implements IMenuItemService {

    @Autowired
    MSMenuItemMapper ms;

    @Resource
    MenuItemMapper mapper;
    @Resource
    MenuGroupMapper menuGroupMapper;
    @Resource
    StoreTypeMapper storeTypeMapper;
    @Resource
    PrivilegeMapper privilegeMapper;
    @Override
    public PageDTO<MenuItemDTO> listAllMenuItemsPage(MenuItemQuery query) {
        //获取分页对象
        Page<MenuItem> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //执行查询
        Page<MenuItem> pageResult = mapper.pageQuery(page, query.getGroupName(), query.getMenuName());
        return PageDTO.create(pageResult, src -> ms.doToDTO(src));
    }

    @Override
    @Transactional
    public JsonVO<String> addMenuItem(AddMenuItemDTO addMenuItemDTO) {

        //判断存在
        MenuItem exist = mapper.selectByName(addMenuItemDTO.getMenuName());
        if (exist != null) {
            return JsonVO.fail("该菜单项已存在");
        }
        //构造m_menu_group实体
        MenuGroup menuGroup = new MenuGroup();
        menuGroup.setName(addMenuItemDTO.getGroupName());
        menuGroup.setIcon(addMenuItemDTO.getIcon());
        menuGroup.setLabel(addMenuItemDTO.getLabel());
        menuGroup.setSeq(addMenuItemDTO.getGSeq());
        menuGroup.setGroupType(addMenuItemDTO.getGroupType());
        menuGroup.setDescription(addMenuItemDTO.getGDescription());
        //转换name->cd
        String storeTypeCd = storeTypeMapper.getStoreTypeCdByName(addMenuItemDTO.getStoreTypeName());
        if(storeTypeCd==null){
            return JsonVO.fail("商户类型不存在");
        }
        menuGroup.setStoreType(storeTypeCd);
        int gr =menuGroupMapper.insert(menuGroup);
        if (gr <= 0) {
            throw new RuntimeException("添加菜单组失败");
        }
        //构造privilege实体
        Privilege privilege = new Privilege();
        privilege.setName(addMenuItemDTO.getPriName());
        privilege.setResource(addMenuItemDTO.getPUrl());
        privilege.setDescription(addMenuItemDTO.getDescription());
        int pr =privilegeMapper.insert(privilege);
        if (pr <= 0) {
            throw new RuntimeException("添加权限失败");
        }
        //构造m_menu实体
       MenuItem menuItem = new MenuItem();
        menuItem.setName(addMenuItemDTO.getMenuName());
        menuItem.setUrl(addMenuItemDTO.getMUrl());
        menuItem.setSeq(addMenuItemDTO.getMSeq());
        menuItem.setIsShow(addMenuItemDTO.getIsShow());
        menuItem.setDescription(addMenuItemDTO.getMDescription());
        menuItem.setCreateTime(new Date());
        menuItem.setGid(menuGroup.getGid());
        menuItem.setPid(privilege.getPId());
    int mr =mapper.insert(menuItem);
        if (mr <= 0) {
            throw new RuntimeException("添加菜单项失败");
        }
        return  JsonVO.success("添加成功");
    }

    @Override
    public JsonVO<String> deleteMenuItem(DeleteMenuItemDTO deleteMenuItemDTO) {
        //单个删除
        //只删主表
        //获得要删除的菜单项的id
        String id = deleteMenuItemDTO.getMid();
        //判断是否存在
        MenuItem exist = mapper.selectById(id);
        if (exist == null) {
            return JsonVO.fail("该菜单项不存在");
        }
         //如果有菜单项ID，删除
        int row = mapper.deleteById(id);
        return row > 0 ? JsonVO.success("删除成功"):JsonVO.fail("删除失败");
    }

    @Override
    public JsonVO<String> modifyMenuItem(ModifyMenuItemDTO modifyMenuItemDTO) {
        //获取do
        MenuItem menuItem = ms.modifyDtoTODo(modifyMenuItemDTO);
        //判断是否存在
        MenuItem exist = mapper.selectByName(menuItem.getName());
        if (exist == null ) {
            return JsonVO.fail("该菜单项不存在");
        }
        //执行修改
        int rows = mapper.updateById(menuItem);
        return rows > 0 ?JsonVO.success("修改成功"):JsonVO.fail("修改失败");
    }
}
