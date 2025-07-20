package com.zeroone.star.communitymanage.service.notepad.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.communitymanage.entity.notepad.NotePadDetail;
import com.zeroone.star.communitymanage.mapper.notepad.NotepadDetailMapper;
import com.zeroone.star.communitymanage.service.notepad.NotepadDetailService;
import com.zeroone.star.communitymanage.service.notepad.NotepadService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.notepad.DeleteNotepadDetailDTO;
import com.zeroone.star.project.dto.j5.community.notepad.NotepadDetailDTO;
import com.zeroone.star.project.dto.j5.community.notepad.SaveNotepadDetailDTO;
import com.zeroone.star.project.query.j5.community.notepad.ListNotepadDetailQuery;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import java.util.List;

@Slf4j
@Service
public class NotepadDetailServiceImpl extends ServiceImpl<NotepadDetailMapper, NotePadDetail> implements NotepadDetailService {

    @Autowired
    NotepadService notepadService;

    @Override
    public PageDTO<NotepadDetailDTO> list(ListNotepadDetailQuery notepadQuery) {
        log.info("Service开始获取跟进列表");

        // 1.参数校验
        if (notepadQuery.getPageIndex() <= 0 || notepadQuery.getPageSize() <= 0){
            throw new RuntimeException("分页参数有误");
        }

        // 2.构建分页查询条件
        Page<NotePadDetail> page = new Page<>(notepadQuery.getPageIndex(), notepadQuery.getPageSize());
        QueryWrapper<NotePadDetail> wrapper = new QueryWrapper<>();
        wrapper.eq("note_id", notepadQuery.getNoteId());
        wrapper.eq("status_cd" , 0);
        wrapper.orderByAsc("create_time");

        // 3.执行分页查询
        page = baseMapper.selectPage(page, wrapper);

        // 4.封装DTO
        List<NotepadDetailDTO> list = BeanUtil.copyToList(page.getRecords(), NotepadDetailDTO.class);

        // 5.封装结果
        PageDTO<NotepadDetailDTO> result = new PageDTO<>();
        result.setRows(list);
        result.setTotal(page.getTotal());
        result.setPageIndex(page.getCurrent());
        result.setPageSize(page.getSize());

        // 6.响应结果
        return result;
    }


    @Override
    @Transactional
    public void save(SaveNotepadDetailDTO notepadDTO) {
        log.info("开始Save跟进进度....");

        // 1.直接Save
        NotePadDetail detail = BeanUtil.copyProperties(notepadDTO, NotePadDetail.class);
        detail.setStatusCd(String.valueOf(0));
        int count = baseMapper.insert(detail);

        // 2.检查业务是否受理完成
        if (notepadDTO.getState().equals("W")){

        }

        // 2.判断是否成功
        if (count == 0) {
            throw new RuntimeException("跟进进度失败");
        }
    }


    @Override
    @Transactional
    public void remove(DeleteNotepadDetailDTO notepadDTO) {
        log.info("开始删除跟进进度....");

        // 1.Id数据校验
        NotePadDetail detail = baseMapper.selectById(notepadDTO.getDetailId());
        String noteId = detail.getNoteId();
        if (!notepadDTO.getNoteId().equals(noteId)){
            throw new RuntimeException("反馈业务Id参数有误");
        }

        // 2.封装逻辑删除条件  Id + statuCd
        NotePadDetail notepad = new NotePadDetail();
        notepad.setDetailId(notepadDTO.getDetailId());
        notepad.setStatusCd(String.valueOf(1));

        // 3.执行逻辑删除
        int count = baseMapper.updateById(notepad);

        // 3.判断是否删除成功
        if (count == 0){
            log.error("删除跟进进度失败");
            throw new RuntimeException("删除跟进进度失败,没有此跟进数据");
        }
    }
}
