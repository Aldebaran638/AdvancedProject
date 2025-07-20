package com.zeroone.star.project.j1.dashboard.center;

import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 首页面板：开发中心：常用功能
 */
public interface CenterCommonMenuApis {
    /**
     * 首页面板：开发中心：常用功能
     * @return
     */
    JsonVO<List<CommonMenuDTO>> getCenterCommonMenu();
}
