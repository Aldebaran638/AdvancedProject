package com.zeroone.star.dashboard.service;

import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;

import java.util.List;

/**
 * 开发中心服务接口
 */
public interface CenterService {
    /**
     * 获取常用功能
     */
     List<CommonMenuDTO> getCommonMenu();
}
