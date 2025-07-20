package com.zeroone.star.housemgt.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.housemgt.entity.gzx_OwnerCommittee;
import com.zeroone.star.housemgt.entity.gzx_OwnerCommitteeContact;
import com.zeroone.star.housemgt.mapper.CommitteeContactMapper;
import com.zeroone.star.housemgt.mapper.CommitteeListMapper;
import com.zeroone.star.housemgt.service.CommitteDetailService;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeContactDTO;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeDetailDTO;
import java.util.ArrayList;
import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

/**
 * <p>
 * 业委会成员详情服务实现类
 * </p>
 *
 * @author yuanzijie
 * @since 2025-05-24
 */
@Service
public class CommitteeDetailServiceImpl extends ServiceImpl<CommitteeContactMapper, gzx_OwnerCommitteeContact> implements CommitteDetailService {

    @Autowired
    private CommitteeListMapper committeeListMapper;

    @Override
    public CommitteeDetailDTO queryDetailById(String ocId) {
        // 参数校验
        if (!StringUtils.hasText(ocId)) {
            return null;
        }

        // String转Long进行查询
        Long id;
        try {
            id = Long.valueOf(ocId);
        } catch (NumberFormatException e) {
            System.out.println("无效的ID格式: " + ocId);
            return null;
        }

        // 1. 查询业委会成员基本信息
        gzx_OwnerCommittee committee = committeeListMapper.selectById(id);
        if (committee == null) {
            System.out.println("未找到业委会成员，ID: " + id);
            return null;
        }

        System.out.println("找到业委会成员: " + committee.getName() + ", 状态: " + committee.getStatusCd());

        // 2. 查询该成员的所有联系人信息
        LambdaQueryWrapper<gzx_OwnerCommitteeContact> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(gzx_OwnerCommitteeContact::getOcId, id)
                .eq(gzx_OwnerCommitteeContact::getStatusCd, "0")
                .orderByDesc(gzx_OwnerCommitteeContact::getCreateTime);

        List<gzx_OwnerCommitteeContact> contactList = this.list(wrapper);
        System.out.println("找到联系人数量: " + (contactList != null ? contactList.size() : 0));

        // 3. 转换为DTO
        return convertToDetailDTO(committee, contactList);
    }

    private CommitteeDetailDTO convertToDetailDTO(gzx_OwnerCommittee committee, List<gzx_OwnerCommitteeContact> contactList) {
        CommitteeDetailDTO dto = new CommitteeDetailDTO();

        // 设置业委会成员基本信息（不包含编号）
        dto.setName(committee.getName());
        // 性别转换：B->男，G->女
        String sexDesc = convertSexToDesc(committee.getSex());
        dto.setSex(sexDesc);
        dto.setLink(committee.getLink());
        dto.setIdCard(committee.getIdCard()); // 添加身份证号
        dto.setAddress(committee.getAddress());
        dto.setPosition(committee.getPosition());
        dto.setPost(committee.getPost()); // 添加岗位
        dto.setPostDesc(committee.getPostDesc()); // 添加岗位描述
        dto.setAppointTime(committee.getAppointTime()); // 添加届期
        dto.setCurTime(committee.getCurTime()); // 添加任期
        dto.setRemark(committee.getRemark()); // 添加备注
//        dto.setCommunityId(committee.getCommunityId()); // 添加小区ID
//        dto.setCreateTime(committee.getCreateTime()); // 添加创建时间

        // 状态转换：1000->在职，2000->离职
        String stateDesc = convertStateToDesc(committee.getState());
        dto.setStateDesc(stateDesc);

        // 转换联系人列表
        List<CommitteeContactDTO> contacts = new ArrayList<>();

        if (contactList != null && !contactList.isEmpty()) {
            for (gzx_OwnerCommitteeContact contact : contactList) {
                CommitteeContactDTO contactDTO = new CommitteeContactDTO();
                contactDTO.setName(contact.getName());
                contactDTO.setRelName(contact.getRelName());
                contactDTO.setLink(contact.getLink());
                contactDTO.setAddress(contact.getAddress());
                contacts.add(contactDTO);
            }
            System.out.println("转换了 " + contacts.size() + " 个联系人");
        } else {
            // 如果没有专门的联系人，添加成员本人作为联系人
            CommitteeContactDTO selfContact = new CommitteeContactDTO();
            selfContact.setName(committee.getName());
            selfContact.setRelName("本人");
            selfContact.setLink(committee.getLink());
            selfContact.setAddress(committee.getAddress());
            contacts.add(selfContact);
            System.out.println("使用成员本人信息作为联系人");
        }

        dto.setContacts(contacts);
        return dto;
    }

    /**
     * 状态码转换为描述
     * @param state 状态码
     * @return 状态描述
     */
    private String convertStateToDesc(String state) {
        if ("1000".equals(state)) {
            return "在职";
        } else if ("2000".equals(state)) {
            return "离职";
        } else {
            return "未知状态";
        }
    }

    /**
     * 性别码转换为描述
     * @param sex 性别码
     * @return 性别描述
     */
    private String convertSexToDesc(String sex) {
        if ("B".equals(sex)) {
            return "男";
        } else if ("G".equals(sex)) {
            return "女";
        } else {
            return "未知";
        }
    }
}