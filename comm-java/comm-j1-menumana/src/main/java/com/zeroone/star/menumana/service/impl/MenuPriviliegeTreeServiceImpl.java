package com.zeroone.star.menumana.service.impl;

import com.zeroone.star.menumana.entity.MenuTree;
import com.zeroone.star.menumana.mapper.MenuPriviliegeTree.MenuMapper;
import com.zeroone.star.menumana.service.MenuPriviliegeTreeService;
import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuPrivilegeTreeDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.*;

@Service
public class MenuPriviliegeTreeServiceImpl implements MenuPriviliegeTreeService {
    @Autowired
    private MenuMapper menuMapper;

    @Override
    public List<MenuPrivilegeTreeDTO> getMenuPrivilegeTree() {
        // 获取所有菜单信息
        List<MenuTree> allMenuInfo = menuMapper.getAllMenus();

        Map<String, MenuPrivilegeTreeDTO> menuGroupMap = new HashMap<>();
        Map<String, List<MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO>> menuPrivilegeMap = new HashMap<>();

        for (MenuTree menuTree : allMenuInfo) {
            String menuGroupId = menuTree.getMenuGroupId() != null ? menuTree.getMenuGroupId() : "";
            String menuGroupName = menuTree.getMenuGroupName() != null ? menuTree.getMenuGroupName() : "";
            Integer menuGroupSeq = menuTree.getMgseq() != null ? menuTree.getMgseq() : 0;
            String menuId = menuTree.getMenuId() != null ? menuTree.getMenuId() : "";
            String privilegeId = menuTree.getPrivilegeId() != null ? menuTree.getPrivilegeId() : "";
            String privilegeName = menuTree.getPrivilegeName() != null ? menuTree.getPrivilegeName() : "";

            // 处理菜单组信息
            if (!menuGroupMap.containsKey(menuGroupId)) {
                MenuPrivilegeTreeDTO menuGroupDTO = new MenuPrivilegeTreeDTO();
                menuGroupDTO.setMenuGroupId(menuGroupId);
                menuGroupDTO.setMenuGroupName(menuGroupName);
                menuGroupDTO.setGroupSeq(menuGroupSeq);
                menuGroupMap.put(menuGroupId, menuGroupDTO); // 确保将菜单组 DTO 添加到 map 中
            }

            // 处理菜单和权限
            if (!menuId.isEmpty()) {
                if (!menuPrivilegeMap.containsKey(menuId)) {
                    menuPrivilegeMap.put(menuId, new ArrayList<>());
                }
                if (!privilegeId.isEmpty()) {
                    MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO privilegeDTO = new MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO();
                    privilegeDTO.setPrivilegeId(privilegeId);
                    privilegeDTO.setPrivilegeName(privilegeName);
                    menuPrivilegeMap.get(menuId).add(privilegeDTO);
                }
            }
        }
        // 构建树形结构
        List<MenuPrivilegeTreeDTO> tree = new ArrayList<>();
        for (MenuPrivilegeTreeDTO menuGroupDTO : menuGroupMap.values()) {
            List<MenuPrivilegeTreeDTO.MenuItemDTO> menuItems = new ArrayList<>();
            for (Map.Entry<String, List<MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO>> entry : menuPrivilegeMap.entrySet()) {
                String menuId = entry.getKey();
                List<MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO> privileges = entry.getValue();
                String menuName = menuMapper.getMenuNameById(menuId);
                String menuSeqStr = menuMapper.getMenuSeqById(menuId);
                Integer menuSeq = menuSeqStr != null ? Integer.parseInt(menuSeqStr) : 0;

                MenuPrivilegeTreeDTO.MenuItemDTO menuItemDTO = new MenuPrivilegeTreeDTO.MenuItemDTO();
                menuItemDTO.setMenuId(menuId);
                menuItemDTO.setMenuName(menuName);
                menuItemDTO.setMenuSeq(menuSeq);
                menuItemDTO.setPrivileges(privileges);
                menuItems.add(menuItemDTO);
            }
            menuGroupDTO.setChildren(menuItems);
            tree.add(menuGroupDTO);
        }
        return tree;
    }
}

//public class MenuPriviliegeTreeServiceImpl implements MenuPriviliegeTreeService {
//    @Autowired
//    private MenuMapper menuMapper;
//    @Override
//    public List<MenuPrivilegeTreeDTO> getMenuPrivilegeTree() {
//        //  获取所有菜单信息
//        List<MenuTree> allMenuInfo=  menuMapper.getAllMenus();
//
//        Map<String, MenuPrivilegeTreeDTO> menuGroupMap=new HashMap<>();
//        Map<String,List< MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO>> menuPrivilegeMap=new HashMap<>();
//        for (MenuTree objects : allMenuInfo) {
//            String menuGroupId = objects.getMenuGroupId()!=null ? objects.getMenuGroupId() : "";
//           String menuGroupName = objects.getMenuGroupName()!=null ? objects.getMenuGroupName() : "";
//           Integer menuGroupSeq = objects.getMgseq()!=null ? objects.getMgseq() : 0;
//           String menuId = objects.getMenuId()!=null ? objects.getMenuId() : "";
//           String privilegeId = objects.getPrivilegeId()!=null ? objects.getPrivilegeId() : "";
//           String privilegeName = objects.getPrivilegeName()!=null ? objects.getPrivilegeName() : "";
//
//            //处理菜单组信息
//            if(!menuGroupMap.containsKey(menuGroupId)){
//                MenuPrivilegeTreeDTO menuGroupDTO=new MenuPrivilegeTreeDTO();
//                menuGroupDTO.setMenuGroupId(menuGroupId);
//                menuGroupDTO.setMenuGroupName(menuGroupName);
//                menuGroupDTO.setGroupSeq(menuGroupSeq);
//            }
//            //处理菜单和权限
//            if(!menuId.isEmpty()){
//                if(!menuPrivilegeMap.containsKey(menuId)){
//                    menuPrivilegeMap.put(menuId,new ArrayList<>());
//                }
//                if(!privilegeId.isEmpty()){
//                    MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO privilegeDTO=new MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO();
//                    privilegeDTO.setPrivilegeId(privilegeId);
//                    privilegeDTO.setPrivilegeName(privilegeName);
//                    menuPrivilegeMap.get(menuId).add(privilegeDTO);
//                }
//            }
//
//        }
//        //构建树形结构
//        List<MenuPrivilegeTreeDTO> tree=new ArrayList<>();
//        for(MenuPrivilegeTreeDTO menuGroupDTO:menuGroupMap.values()){
//            List<MenuPrivilegeTreeDTO.MenuItemDTO> menuItems=new ArrayList<>();
//            for(Map.Entry<String,List<MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO>> entry :  menuPrivilegeMap.entrySet()){
//                String menuId = entry.getKey();
//                List<MenuPrivilegeTreeDTO.MenuItemDTO.PrivilegeDTO> privileges = entry.getValue();
//                String menuName = menuMapper.getMenuNameById(menuId);
//                String menuSeq = menuMapper.getMenuSeqById(menuId);
//                MenuPrivilegeTreeDTO.MenuItemDTO menuItemDTO=new MenuPrivilegeTreeDTO.MenuItemDTO();
//                menuItemDTO.setMenuId(menuId);
//                menuItemDTO.setMenuName(menuName);
//                menuItemDTO.setMenuSeq(Integer.parseInt(menuSeq));
//                menuItemDTO.setPrivileges(privileges);
//                menuItems.add(menuItemDTO);
//            }
//            menuGroupDTO.setChildren(menuItems);
//            tree.add(menuGroupDTO);
//
//        }
//        return tree;
//    }
//}