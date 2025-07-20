package com.zeroone.star.menumana.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.menumana.entity.UserMenu;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.AddCommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.MixMenuDTO;
import com.zeroone.star.project.query.j1.menumana.commonmenu.CommonMenuQuery;

import java.util.List;

public interface ICommonMenuService extends IService<UserMenu> {

    /**
     * 分页查询
     * @param query 查询条件
     * @return 查询结果
     * @throws Exception
     */
    PageDTO<CommonMenuDTO> listAllCommonMenu(CommonMenuQuery query);

    /**
     * 根据菜单组id查询
     * @param
     * @return
     */
    List<MixMenuDTO> listMixMenu() ;

    /**
     * 根据mu_id将状态码设置为1（删除）
     * @param muId
     * @return
     */
    String updateMuId(String muId);

    /**
     * 添加常用菜单
     * @param addCommonMenuDTO
     * @return
     */
    String addMenu(AddCommonMenuDTO addCommonMenuDTO);


}