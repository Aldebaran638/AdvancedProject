package com.zeroone.star.housemgt.service.impl;

import cn.hutool.core.util.IdUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.housemgt.entity.ycl_OwnerCommittee;
import com.zeroone.star.housemgt.entity.ycl_OwnerCommitteeContact;
import com.zeroone.star.housemgt.mapper.ycl_OwnerCommitteeContactMapper;
import com.zeroone.star.housemgt.mapper.ycl_OwnerCommitteeMapper;
import com.zeroone.star.housemgt.service.CommitteeService;
import com.zeroone.star.project.j8.housemgt.committee.dto.AddCommitteeDTO;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeDTO;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeContactDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.sql.Timestamp;
import java.time.LocalDateTime;

@Service
public class CommitteeServiceImpl implements CommitteeService {

    @Autowired
    private ycl_OwnerCommitteeMapper committeeMapper;

    @Autowired
    private ycl_OwnerCommitteeContactMapper contactMapper;

    @Override
    public JsonVO<String> addCommittee(AddCommitteeDTO dto) {
        // 主表：先生成 ocId，再把 DTO放到实体，最后 insert
        String ocId = IdUtil.getSnowflake(1,1).nextIdStr();
        ycl_OwnerCommittee committee = new ycl_OwnerCommittee();
        // 拷贝DTO里同名的字段
        BeanUtils.copyProperties(dto, committee);
        // 手动把communityId从 DTO 赋给实体，免得insert时community_id是null
        committee.setCommunityId(dto.getCommunityId());
        // 把生成的 ocId 和其他字段补上
        committee.setOcId(ocId);
        committee.setCreateTime(Timestamp.valueOf(LocalDateTime.now()));
        committee.setStatusCd("0");
        committeeMapper.insert(committee);

        // 联系人表：如果前端传了就循环插入，每条都要填 ocId、communityId
        if (dto.getContacts() != null) {
            for (CommitteeContactDTO c : dto.getContacts()) {
                ycl_OwnerCommitteeContact contact = new ycl_OwnerCommitteeContact();
                BeanUtils.copyProperties(c, contact);
                // 生成联系人主键
                contact.setContractId(IdUtil.getSnowflake(1,1).nextIdStr());
                // 关联回主表的 ocId
                contact.setOcId(ocId);
                // 同样填communityId
                contact.setCommunityId(dto.getCommunityId());
                contact.setCreateTime(Timestamp.valueOf(LocalDateTime.now()));
                contact.setStatusCd("0");
                contactMapper.insert(contact);
            }
        }
        // 返回主表刚插入的 ocId
        return JsonVO.success(ocId);
    }

    @Override
    public JsonVO<String> modifyCommittee(CommitteeDTO dto) {
        // 1. 先从数据库查出旧的记录，取communityId
        ycl_OwnerCommittee oldRecord = committeeMapper.selectById(dto.getOcId());
        if (oldRecord == null) {
            // 如果库里不存在这条记录，返回错误
            return JsonVO.create(null, 404, "记录不存在，找不到对应所在社区");
        }
        // 更新主表：把 DTO 里其它字段拷贝到一个新的实体对象里
        ycl_OwnerCommittee committee = new ycl_OwnerCommittee();
        BeanUtils.copyProperties(dto, committee);
        //付给实体
        //committee.setCommunityId(dto.getCommunityId());

        // 把旧记录里的 communityId 赋给新实体，防止为空
        committee.setCommunityId(oldRecord.getCommunityId());

        int cnt = committeeMapper.updateById(committee);
        if (cnt == 0) {
            return JsonVO.create(null, 500, "失败");
        }

        String ocId = dto.getOcId();
        //清空联系人再查一遍
        contactMapper.delete(new QueryWrapper<ycl_OwnerCommitteeContact>().eq("oc_id", ocId));
        if (dto.getContacts() != null) {
            for (CommitteeContactDTO c : dto.getContacts()) {
                ycl_OwnerCommitteeContact contact = new ycl_OwnerCommitteeContact();
                BeanUtils.copyProperties(c, contact);
                contact.setContractId(IdUtil.getSnowflake(1,1).nextIdStr());
                contact.setOcId(ocId);
                // communityId 赋给联系人实体，用旧的
                contact.setCommunityId(oldRecord.getCommunityId());
                contact.setCreateTime(Timestamp.valueOf(LocalDateTime.now()));
                contact.setStatusCd("0");
                contactMapper.insert(contact);
            }
        }
        return JsonVO.success("修改成功");
    }

    @Override
    public JsonVO<String> removeCommittee(String committeeId) {
        // 删除联系人：先把联系人表中跟该 ocId 相关的记录都删掉
        contactMapper.delete(new QueryWrapper<ycl_OwnerCommitteeContact>().eq("oc_id", committeeId));
        // 再删除主表
        int del = committeeMapper.deleteById(committeeId);
        if (del > 0) {
            return JsonVO.success("删除成功");
        }
        return JsonVO.create(null, 404, "记录不存在");
    }
}
