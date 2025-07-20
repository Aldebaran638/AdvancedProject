package com.zeroone.star.orgmanager.service.serviceImpl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.orgmanager.entity.MMenuOrg;
import com.zeroone.star.orgmanager.entity.PPrivilegeGroup;
import com.zeroone.star.orgmanager.entity.PPrivilegeRel;
import com.zeroone.star.orgmanager.mapper.MMenuOrgMapper;
import com.zeroone.star.orgmanager.mapper.PPrivilegeGroupMapper;
import com.zeroone.star.orgmanager.mapper.PPrivilegeRelMapper;
import com.zeroone.star.orgmanager.service.MenuService;
import com.zeroone.star.project.query.j2.orgmanager.functionAuth.GetRolePermissionQuery;
import com.zeroone.star.project.query.j2.orgmanager.functionAuth.UpdateRolePermissionQuery;
import com.zeroone.star.project.vo.j2.orgmanager.functionAuth.GetRolePermissionVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.*;
import java.util.stream.Collectors;

@Service
@Slf4j
public class MenuServiceImpl implements MenuService {
    @Autowired
    private MMenuOrgMapper mMenuOrgMapper;
    @Autowired
    private PPrivilegeGroupMapper groupMapper;
    @Autowired
    private PPrivilegeRelMapper relMapper;
    // 状态代码常量
    private static final String STATUS_ENABLED = "0";  // 在用（勾选）
    private static final String STATUS_DISABLED = "1"; // 失效（取消勾选）

    @Transactional(readOnly = true)
    public List<MenuTreeVO> getMenuTree(String storeId, String roleType) {
        // 1. 查询权限组
        List<PPrivilegeGroup> groups = groupMapper.selectList(
                new QueryWrapper<PPrivilegeGroup>()
                        .eq("store_id", storeId)
                        .eq(roleType != null, "role_type", roleType)
        );
        if (groups.isEmpty()) return Collections.emptyList();
        List<String> pgIds = groups.stream().map(PPrivilegeGroup::getPgId).collect(Collectors.toList());

        // 2. 查询权限ID
        List<PPrivilegeRel> rels = relMapper.selectList(
                new QueryWrapper<PPrivilegeRel>().in("pg_id", pgIds)
        );
        if (rels.isEmpty()) return Collections.emptyList();
        List<String> pIds = rels.stream().map(PPrivilegeRel::getPId).distinct().collect(Collectors.toList());

        // 3. 查询菜单项
        List<MMenuOrg> menus = mMenuOrgMapper.selectList(
                new QueryWrapper<MMenuOrg>()
                        .eq("status_cd", "0")
                        .eq("is_show", "Y")
                        .in("p_id", pIds)
        );
        if (menus.isEmpty()) return Collections.emptyList();

        // 4. 构建菜单树
        return buildMenuTree(menus);
    }

    @Override
    public List<MenuTreeVO> getRolePermission(GetRolePermissionQuery getRolePermissionQuery) {
        // 1. 查询权限组
        QueryWrapper<PPrivilegeGroup> groupWrapper = new QueryWrapper<PPrivilegeGroup>()
                .eq("pg_id", getRolePermissionQuery.getPgId());
        if (StringUtils.isNotBlank(getRolePermissionQuery.getStoreId())) {
            groupWrapper.eq("store_id", getRolePermissionQuery.getStoreId());
        } else {
            groupWrapper.isNull("store_id"); // 显式处理 store_id 为 NULL 的情况
        }
        List<PPrivilegeGroup> groups = groupMapper.selectList(groupWrapper);
        if (groups.isEmpty()) return Collections.emptyList();

        // 2. 查询权限ID
        List<PPrivilegeRel> rels = relMapper.selectList(
                new QueryWrapper<PPrivilegeRel>()
                        .eq("pg_id", getRolePermissionQuery.getPgId())
        );
        if (rels.isEmpty()) {
            return Collections.emptyList();
        }
        List<String> pIds = rels.stream()
                .map(PPrivilegeRel::getPId)
                .distinct()
                .collect(Collectors.toList());

        // 3. 查询菜单项
        List<MMenuOrg> menus = mMenuOrgMapper.selectList(
                new QueryWrapper<MMenuOrg>()
                        .eq("status_cd", "0")
                        .eq("is_show", "Y")
                        .in("p_id", pIds)
        );
        if (menus.isEmpty()) {
            return Collections.emptyList();
        }

        // 4. 构建菜单树
        return buildMenuTree(menus);
    }

    @Override
    public String updateRolePermission(UpdateRolePermissionQuery updateRolePermissionQuery) {
        // 1. 校验权限组是否存在
        QueryWrapper<PPrivilegeGroup> groupWrapper = new QueryWrapper<PPrivilegeGroup>()
                .eq("pg_id", updateRolePermissionQuery.getPgId());
        if (org.springframework.util.StringUtils.hasText(updateRolePermissionQuery.getStoreId())) {
            groupWrapper.eq("store_id", updateRolePermissionQuery.getStoreId());
        } else {
            groupWrapper.isNull("store_id");
        }
        PPrivilegeGroup group = groupMapper.selectOne(groupWrapper);
        if (group == null) {
            log.warn("权限组不存在: pgId={}, storeId={}",
                    updateRolePermissionQuery.getPgId(), updateRolePermissionQuery.getStoreId());
            return "权限组不存在";
        }

        // 2. 验证权限ID是否有效
        QueryWrapper<MMenuOrg> menuWrapper = new QueryWrapper<MMenuOrg>()
                .eq("p_id", updateRolePermissionQuery.getPId())
                .eq("status_cd", STATUS_ENABLED)
                .eq("is_show", "Y");
        MMenuOrg menu = mMenuOrgMapper.selectOne(menuWrapper);
        if (menu == null) {
            log.warn("权限不存在: pId={}", updateRolePermissionQuery.getPId());
            return "权限不存在";
        }

        // 3. 校验状态代码
        String statusCd = updateRolePermissionQuery.getStatusCd();
        if (!STATUS_ENABLED.equals(statusCd) && !STATUS_DISABLED.equals(statusCd)) {
            log.warn("无效的状态代码: statusCd={}", statusCd);
            return "状态代码无效，必须为 0（在用）或 1（失效）";
        }

        // 4. 检查权限关系是否存在
        QueryWrapper<PPrivilegeRel> relWrapper = new QueryWrapper<PPrivilegeRel>()
                .eq("pg_id", updateRolePermissionQuery.getPgId())
                .eq("p_id", updateRolePermissionQuery.getPId());
        PPrivilegeRel existingRel = relMapper.selectOne(relWrapper);

        // 5. 更新或插入权限状态
        if (existingRel == null) {
            // 插入新记录
            PPrivilegeRel newRel = new PPrivilegeRel();
            newRel.setPgId(updateRolePermissionQuery.getPgId());
            newRel.setPId(updateRolePermissionQuery.getPId());
            newRel.setStatusCd(statusCd);
            int inserted = relMapper.insert(newRel);
            if (inserted > 0) {
                log.info("权限状态插入成功: pgId={}, pId={}, statusCd={}",
                        updateRolePermissionQuery.getPgId(), updateRolePermissionQuery.getPId(), statusCd);
                return "权限状态更新成功";
            } else {
                log.error("权限状态插入失败: pgId={}, pId={}",
                        updateRolePermissionQuery.getPgId(), updateRolePermissionQuery.getPId());
                return "权限状态更新失败";
            }
        } else {
            // 更新现有记录
            UpdateWrapper<PPrivilegeRel> updateWrapper = new UpdateWrapper<PPrivilegeRel>()
                    .eq("pg_id", updateRolePermissionQuery.getPgId())
                    .eq("p_id", updateRolePermissionQuery.getPId())
                    .set("status_cd", statusCd);
            int updated = relMapper.update(null, updateWrapper);
            if (updated > 0) {
                log.info("权限状态更新成功: pgId={}, pId={}, statusCd={}",
                        updateRolePermissionQuery.getPgId(), updateRolePermissionQuery.getPId(), statusCd);
                return "权限状态更新成功";
            } else {
                log.error("权限状态更新失败: pgId={}, pId={}",
                        updateRolePermissionQuery.getPgId(), updateRolePermissionQuery.getPId());
                return "权限状态更新失败";
            }
        }
    }

    private List<MenuTreeVO> buildMenuTree(List<MMenuOrg> menus) {
        Map<String, MenuTreeVO> menuMap = new HashMap<>();

        // 构建 MenuTreeVO 节点
        for (MMenuOrg menu : menus) {
            MenuTreeVO vo = new MenuTreeVO();
            // 设置 TreeNode 字段
            vo.setTnId(menu.getMId()); // 唯一ID
            vo.setTnPid(menu.getPId()); // 父节点ID（权限ID）
            vo.setTnDepth(0); // 初始深度，后续计算

            // 设置 MenuTreeVO 字段
            vo.setId(convertToInteger(menu.getMId())); // 菜单ID 转换为整数
            vo.setText(menu.getName());
            vo.setHref(menu.getUrl());
            vo.setPid(convertToInteger(menu.getPId())); // 父级菜单编号（权限ID 转换为整数）

            menuMap.put(menu.getMId(), vo);
        }

        // 构建树形结构
        List<MenuTreeVO> rootMenus = new ArrayList<>();
        for (MMenuOrg menu : menus) {
            MenuTreeVO vo = menuMap.get(menu.getMId());
            Integer pId = vo.getPid(); // 使用 pid 确定父子关系
            String pIdStr = menu.getPId(); // 权限ID（String）

            // 计算节点深度
            vo.setTnDepth(calculateDepth(vo, menuMap));

            if (pId == null || pId == 0 || !menuMap.containsKey(pIdStr)) {
                rootMenus.add(vo);
            } else {
                MenuTreeVO parent = menuMap.get(pIdStr);
                if (parent != null) {
                    parent.addChild(vo);
                }
            }
        }

        // 按 id 排序
        rootMenus.sort(Comparator.comparingInt(MenuTreeVO::getId));
        return rootMenus;
    }

    private Integer convertToInteger(String value) {
        if (value == null || value.isEmpty()) {
            return 0;
        }
        try {
            return Integer.parseInt(value);
        } catch (NumberFormatException e) {
            return 0; // 转换失败时返回 0
        }
    }

    private Integer calculateDepth(MenuTreeVO node, Map<String, MenuTreeVO> menuMap) {
        int depth = 0;
        MenuTreeVO current = node;
        while (current.getPid() != null && menuMap.containsKey(current.getPid())) {
            current = menuMap.get(current.getPid());
            depth++;
        }
        return depth;
    }
    private List<GetRolePermissionVO> buildRolePermissionTree(List<MMenuOrg> menus) {
        Map<String,GetRolePermissionVO> map=new HashMap<>();
        //转换为GetRolePermissionVO
        List<GetRolePermissionVO> voList=menus.stream().map(menu->{
            GetRolePermissionVO vo=new GetRolePermissionVO();
            BeanUtils.copyProperties(menu,vo);
            vo.setStatusCd(menu.getStatusCd());
            vo.setChildren(new ArrayList<>());
            map.put(vo.getMId(),vo);
            return vo;
        }).collect(Collectors.toList());
        //构建树形结构
        List<GetRolePermissionVO> rootList=new ArrayList<>();
        for (GetRolePermissionVO vo : voList) {
            String parentId=vo.getGId();
            if (StringUtils.isBlank(parentId)||!map.containsKey(parentId)){
                rootList.add(vo);
            }else{
                map.get(parentId).getChildren().add(vo);
            }
        }
        return rootList;
    }
}
