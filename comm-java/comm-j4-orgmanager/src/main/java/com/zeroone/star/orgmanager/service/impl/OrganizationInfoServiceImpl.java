package com.zeroone.star.orgmanager.service.impl;

import com.zeroone.star.orgmanager.entity.UOrg;
import com.zeroone.star.orgmanager.mapper.OrganizationInfoMapper;
import com.zeroone.star.orgmanager.service.OrganizationInfoService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.vo.j4.orgmanager.ClassOrganizationVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Service
public class OrganizationInfoServiceImpl implements OrganizationInfoService {

    @Resource
    private UserHolder userHolder;

    @Resource
    private OrganizationInfoMapper organizationInfoMapper;

    public List<ClassOrganizationVO> getOrganizationTree() throws Exception {
        //  获取当前用户的userid
        String userId = String.valueOf(userHolder.getCurrentUser().getId());
        // 根据orgId查询组织树信息
        List<UOrg> organizationList = organizationInfoMapper.selectOrganizationTreeByOrgId(userId);
        if (organizationList == null || organizationList.isEmpty()) {
            return new ArrayList<>();
        }
        List<ClassOrganizationVO> results = list2Tree(organizationList);
        return results;
    }

    private List<ClassOrganizationVO> list2Tree(List<UOrg> organizationList) {
        // Step 1: 将UOrg列表转换成ClassOrganizationVO列表
        List<ClassOrganizationVO> nodeList = organizationList.stream()
                .map(this::convertToVO)
                .collect(Collectors.toList());

        // Step 2: 创建ID到节点的映射
        Map<String, ClassOrganizationVO> nodeMap = new HashMap<>();
        nodeList.forEach(node -> nodeMap.put(node.getOrgId(), node));

        // Step 3: 构建树形结构
        List<ClassOrganizationVO> tree = new ArrayList<>();
        for (ClassOrganizationVO node : nodeList) {
            String parentId = node.getParentOrgId();
            String selfId = node.getOrgId();

            // 判断是否为根节点（父ID等于自身ID）
            if (parentId.equals(selfId)) {
                tree.add(node);
            } else {
                // 找到父节点并添加到其children列表
                ClassOrganizationVO parent = nodeMap.get(parentId);
                if (parent != null) {
                    if (parent.getChildren() == null) {
                        parent.setChildren(new ArrayList<>());
                    }
                    parent.getChildren().add(node);
                }
            }
        }
        return tree;
    }

    // 转换方法：UOrg -> ClassOrganizationVO
    private ClassOrganizationVO convertToVO(UOrg uOrg) {
        ClassOrganizationVO vo = new ClassOrganizationVO();
        vo.setOrgId(uOrg.getOrgId());
        vo.setParentOrgId(uOrg.getParentOrgId());
        vo.setOrgName(uOrg.getOrgName());
        vo.setOrgLevel(uOrg.getOrgLevel());
        // children属性在构建树时动态设置
        return vo;
    }
}
