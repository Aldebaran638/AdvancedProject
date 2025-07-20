package com.zeroone.star.menumana.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.alibaba.excel.util.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.menumana.entity.MenuGroup;
import com.zeroone.star.menumana.mapper.MenuGroupMapper;
import com.zeroone.star.menumana.service.IMenuGroupService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menugroup.MenuGroupDTO;
import com.zeroone.star.project.dto.j1.menumana.menugroup.UpdateMenuGroupDTO;
import com.zeroone.star.project.query.j1.menumana.menugroup.MenuGroupQuery;
import com.zeroone.star.project.vo.j1.menumana.menugroup.MenuGroupNameVO;
import com.zeroone.star.project.vo.j1.menumana.menugroup.MenuGroupVO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class MenuGroupServiceImpl extends ServiceImpl<MenuGroupMapper, MenuGroup> implements IMenuGroupService {
    /**
     * 获取菜单组名称列表
     *
     * @param storeType
     * @return
     */
    @Override
    public List<MenuGroupNameVO> listMenuGroupName(String storeType) {
        List<MenuGroup> menuGroups = query().eq("store_type", storeType).list();
        if (menuGroups == null && menuGroups.isEmpty()) {
            return Collections.emptyList();
        }
        List<MenuGroupNameVO> menuGroupNameVOS = menuGroups.stream()
                .map((menuGroup -> BeanUtil.copyProperties(menuGroup, MenuGroupNameVO.class)))
                .collect(Collectors.toList());
        return menuGroupNameVOS;
    }

    /**
     * 获取菜单组列表
     *
     * @param query
     * @return
     */
    @Override
    public PageDTO<MenuGroupVO> listMenuGroup(MenuGroupQuery query) {
        LambdaQueryWrapper<MenuGroup> wrapper = new LambdaQueryWrapper<>();
        // 使用StringUtils.isNotBlank避免空字符串查询
        if (StringUtils.isNotBlank(query.getGid())) {
            wrapper.eq(MenuGroup::getGid, query.getGid());
        }
        if (StringUtils.isNotBlank(query.getName())) {
            wrapper.like(MenuGroup::getName, query.getName());
        }
        if (StringUtils.isNotBlank(query.getStoreType())) {
            wrapper.eq(MenuGroup::getStoreType, query.getStoreType());
        }
        Page<MenuGroup> page = page(new Page<>(query.getPageIndex(), query.getPageSize()), wrapper);
        return PageDTO.create(page,
                src -> {
                    MenuGroupVO vo = new MenuGroupVO();
                    BeanUtil.copyProperties(src, vo);
                    return vo;
                });
    }

    /**
     * 添加菜单组
     * @param menuGroupDTO
     */
    @Transactional(rollbackFor = Exception.class)
    @Override
    public boolean addMenuGroup(MenuGroupDTO menuGroupDTO) {
        MenuGroup menuGroup = new MenuGroup();
        BeanUtil.copyProperties(menuGroupDTO, menuGroup);
        return save(menuGroup);
    }

    /**
     * 修改菜单组
     * @param updateMenuGroupDTO
     * @return
     */
    @Transactional(rollbackFor = Exception.class)
    @Override
    public boolean updateMenuGroup(UpdateMenuGroupDTO updateMenuGroupDTO) {
        MenuGroup menuGroup = new MenuGroup();
        BeanUtil.copyProperties(updateMenuGroupDTO, menuGroup);
        return update(menuGroup, new LambdaQueryWrapper<MenuGroup>().eq(MenuGroup::getGid,updateMenuGroupDTO.getGid()));
    }

    /**
     * 删除菜单组
     *
     * @param gid 菜单组编号
     * @return 删除结果
     */
    @Override
    public boolean deleteMenuGroupById(String gid) {
        return removeById(gid);
    }
}