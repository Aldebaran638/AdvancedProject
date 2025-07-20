package com.zeroone.star.dashboard.service.impl;

import com.zeroone.star.dashboard.mapper.CommonmenuMapper;
import com.zeroone.star.dashboard.service.CenterService;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * 获取常用菜单实现类
 */
@Service
public class CenterServiceImpl implements CenterService {
    @Autowired
    private CommonmenuMapper commonmenuMapper;

    /**
     * 目前的写法可以有返回，但是最好是复用获取常用菜单的接口
     * TODO：复用获取常用菜单的接口
     * @return
     */
    @Override
    public List<CommonMenuDTO> getCommonMenu() {
        String menuGroupid= commonmenuMapper.getcommonmenuId("菜单");
        if (menuGroupid!=null){
            return commonmenuMapper.selectCommonmenuAll(menuGroupid);
        }
        return null;
    }
}
