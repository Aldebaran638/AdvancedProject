package com.zeroone.star.menumana.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.menumana.entity.MenuCatalog;
import com.zeroone.star.menumana.mapper.IMenuCatalogMapper;
import com.zeroone.star.menumana.mapper.MsMenuCatalogMapper;
import com.zeroone.star.menumana.service.IMenuCatalogService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.*;
import com.zeroone.star.project.query.j1.menumana.menudir.MenuCatalogQuery;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class MenuCatalogServiceImpl extends ServiceImpl<IMenuCatalogMapper, MenuCatalog> implements IMenuCatalogService {

    @Resource
    MsMenuCatalogMapper ms;

    @Override
    public PageDTO<MenuCatalogDTO> listMenuCatalogPage(Page<MenuCatalog> page,MenuCatalogQuery query) throws Exception{
        QueryWrapper<MenuCatalog> wrapper = new QueryWrapper<>();

        wrapper.lambda()
                .eq(query.getName() != null && !query.getName().isEmpty(), MenuCatalog::getName, query.getName())
                .eq(query.getStoreType() != null && !query.getStoreType().isEmpty(), MenuCatalog::getStoreType, query.getStoreType())
                .eq(query.getIsShow() != null && !query.getIsShow().isEmpty(), MenuCatalog::getIsShow, query.getIsShow())
                .orderByAsc(MenuCatalog::getSeq);

        Page<MenuCatalog> pageResult = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(pageResult, src -> ms.MenuCatalogToDto(src));
    }

    @Override
    public Boolean saveMenuCatalog(MenuCatalog menuCatalog) throws Exception{
        return save(menuCatalog);
    }

    @Override
    public Boolean updateMenuCatalog(UpdateMenuCatalogDTO updateMenuCatalogDTO)throws Exception {
          return updateById(ms.updateDtoToDo(updateMenuCatalogDTO));
    }

    @Override
    public Boolean removeMenuCatalog(String caId) throws Exception{
        return removeById(caId);
    }
}
