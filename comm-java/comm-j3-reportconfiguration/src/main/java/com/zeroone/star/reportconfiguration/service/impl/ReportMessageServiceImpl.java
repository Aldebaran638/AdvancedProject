package com.zeroone.star.reportconfiguration.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.MessageAddDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.message.MessageQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.MessageVo;
import com.zeroone.star.reportconfiguration.entity.Message;
import com.zeroone.star.reportconfiguration.mapper.MessageMapper;
import com.zeroone.star.reportconfiguration.service.ReportMessageService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class ReportMessageServiceImpl extends ServiceImpl<MessageMapper, Message> implements ReportMessageService {

    @Resource
    private MsMessageMapper msMessageMapper;
    @Resource
    private ReportMessageService reportMessageService;
    @Resource
    MessageMapper messageMapper;

    @Resource
    MsMessageMapper ms;
    @Override
    public PageDTO<MessageVo> listAll(MessageQuery query) {

        Page<Message> page = new Page<>(query.getPageIndex(), query.getPageSize());
        if (query.getCustomId() != null) {
            page.setSearchCount(false);
        }
//         Page<Message> pageResult = baseMapper.list(page, wrapper);
        Page<MessageVo> pageResult = messageMapper.selectWithGroup(page, query);
        return PageDTO.create(pageResult);
    }

    @Override
    public boolean saveMessage(Message message) {

        // 校验传入的 message 是否为空
        if (BeanUtil.isEmpty(message)) {
            return false;
        }

        // 校验 groupId 是否存在
        if (!existsByGroupId(message.getGroupId())) {
            throw new IllegalArgumentException("无效的 groupId：" + message.getGroupId());
        }

        message.setStatusCd("0");
        // 保存数据
        return reportMessageService.save(message);
    }

    /**
     * 根据 groupId 查询是否存在
     *
     * @param groupId groupId
     * @return 是否存在
     */
    @Override
    public boolean existsByGroupId(String groupId) {
        return messageMapper.existsByGroupId(groupId);
    }

}
