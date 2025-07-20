package com.zeroone.star.communitymanage.service.notepad.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.communitymanage.entity.notepad.RepairPool;
import com.zeroone.star.communitymanage.mapper.notepad.ToRepairMapper;
import com.zeroone.star.communitymanage.service.notepad.NotepadService;
import com.zeroone.star.communitymanage.service.notepad.ToRepairService;
import com.zeroone.star.project.dto.j5.community.notepad.ChangeToRepairDTO;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;

@Service
@Slf4j
public class ToRepairServiceImpl extends ServiceImpl<ToRepairMapper, RepairPool> implements ToRepairService {

    @Autowired
    NotepadService notepadService;

    /**
     * 反馈业务类型转报修单
     * @param repairDTO
     */
    @SneakyThrows
    @Override
    @Transactional
    public void save(ChangeToRepairDTO repairDTO) {
        log.info("Service 开始转报修单");


        RepairPool target = new RepairPool();
        // 1.封装Insert所需参数
        // 1.1 B_Id
        String BID = IdWorker.getIdStr();
        target.setBId(BID);
        // 1.2 实体类copy
        BeanUtil.copyProperties(repairDTO,target);
        // 1.3 其余字段赋值
        target.setStatusCd(String.valueOf(0));
        target.setState(String.valueOf(1000));
        target.setCreateTime(LocalDateTime.now());
        target.setRepairObjType("004");
        // TODO 其余四个字段为空

        // 2.执行SQL
        int count = baseMapper.insert(target);

        // 3.异常判断
        if (count != 1){
            throw new RuntimeException("Save 报修业务未成功,受影响行数为 0 ");
        }
    }
}
