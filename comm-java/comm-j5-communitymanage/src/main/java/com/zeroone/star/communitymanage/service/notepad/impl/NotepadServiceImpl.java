package com.zeroone.star.communitymanage.service.notepad.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.communitymanage.entity.notepad.NotePad;
import com.zeroone.star.communitymanage.entity.notepad.NotePadDetail;
import com.zeroone.star.communitymanage.mapper.notepad.NotepadDetailMapper;
import com.zeroone.star.communitymanage.mapper.notepad.NotepadMapper;
import com.zeroone.star.communitymanage.service.notepad.NotepadService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.notepad.AddNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.DelNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.ModifyNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.NotepadDTO;
import com.zeroone.star.project.query.j5.community.notepad.NotepadQuery;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang.StringUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;


import javax.annotation.Resource;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Service
@Slf4j
public class NotepadServiceImpl extends ServiceImpl<NotepadMapper, NotePad> implements NotepadService {

    @Resource
    NotepadDetailMapper notepadDetailMapper;
    /**
     * 分页查询业主反馈
     * @param query 分页查询参数
     * @return 返回分页查询的结果
     */
    @Override
    public PageDTO<NotepadDTO> list(NotepadQuery query) {
        String objId = query.getObjId();
        if(StringUtils.isBlank(objId)){
            throw new RuntimeException("请先选择房屋");
        }
        log.info("分页查询成功");
        if(query.getPageIndex() <= 0 || query.getPageSize() <= 0){
            throw new RuntimeException("分页查询参数有误");
        }
        Page<NotePad> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //分页查询结果
        Page<NotePad> result = this.lambdaQuery()
                .select(NotePad::getNoteId, NotePad::getRoomId, NotePad::getRoomName, NotePad::getObjName, NotePad::getLink, NotePad::getNoteType,
                        NotePad::getTitle, NotePad::getCreateUserName, NotePad::getState, NotePad::getCreateTime,NotePad::getThridId)
                .like(StringUtils.isNotBlank(query.getObjName()), NotePad::getObjName, query.getObjName())
                .like(StringUtils.isNotBlank(query.getObjId()), NotePad::getObjId, query.getObjId())
                .eq(StringUtils.isNotBlank(query.getState()), NotePad::getState, query.getState())
                .eq(StringUtils.isNotBlank(query.getNoteType()), NotePad::getNoteType, query.getNoteType())
                .eq(StringUtils.isNotBlank(query.getCreateUserName()), NotePad::getCreateUserName, query.getCreateUserName())
                .eq(NotePad::getObjId, query.getObjId())
                .eq(NotePad::getStatusCd, "0")
                .orderByDesc(NotePad::getCreateTime)
                .page(page);
        List<NotePad> records = result.getRecords();
        //map<id,title>
        Map<String, String> notepadMap = records.stream().collect(Collectors.toMap(NotePad::getNoteId, NotePad::getTitle));
        //将数据集合转换为dto
        List<NotepadDTO> list = BeanUtil.copyToList(records, NotepadDTO.class);
        list = list.stream().map(dto->{
            String content = notepadMap.get(dto.getNoteId());
            dto.setNoteTypeValue(dto.getNoteType().equals("1")? "其他" : "报修");
            dto.setContent(content);
            return dto;
        }).collect(Collectors.toList());
        //封装返回
        PageDTO<NotepadDTO> pageDTO = new PageDTO<>();
        pageDTO.setPageIndex(result.getCurrent());
        pageDTO.setPageSize(result.getSize());
        pageDTO.setRows(list);
        pageDTO.setTotal(result.getTotal());
        return pageDTO;
    }

    /**
     * 增加业主反馈
     * @param addNotepadDTO 添加业主反馈参数
     */
    @Override
    public void saveNotePad(AddNotepadDTO addNotepadDTO) {
        log.info("开始新增业主反馈：{}",addNotepadDTO);
        //属性复制
        NotePad notepad = BeanUtil.copyProperties(addNotepadDTO, NotePad.class);
        notepad.setTitle(addNotepadDTO.getContent());
        notepad.setState("W");
        //保存
        boolean flag = save(notepad);
        if(!flag){
            throw new RuntimeException("保存失败");
        }
    }

    /**
     * 更新业主反馈
     * @param modifyNotepadDTO 已经修改的参数
     */
    @Override
    public void updateNotePad(ModifyNotepadDTO modifyNotepadDTO) {
        //查询在数据库的状态
        NotePad one = lambdaQuery().select(NotePad::getStatusCd)
                .eq(NotePad::getNoteId, modifyNotepadDTO.getNoteId()).one();
        if(!one.getStatusCd().equals("0")){
            throw  new RuntimeException("该数据已删除");
        }
        //属性复制
        NotePad notePad = BeanUtil.copyProperties(modifyNotepadDTO, NotePad.class);
        notePad.setTitle(modifyNotepadDTO.getContent());
        //将状态设为进行中
        notePad.setState("W");
        //更新
        boolean flag = updateById(notePad);
        if (!flag){
            throw new RuntimeException("修改失败");
        }
    }

    /**
     * 根据id删除业主反馈
     * @param delNotepadDTO 反馈id和业主id
     */
    @Transactional
    @Override
    @SneakyThrows
    public void removeNotePad(DelNotepadDTO delNotepadDTO)     {
        String notepadId = delNotepadDTO.getNoteId();
        String objId=  delNotepadDTO.getObjId();
        if(StringUtils.isBlank(notepadId) || StringUtils.isBlank(objId)){
            throw new RuntimeException("业主id和反馈id不能为空");
        }
        log.info("删除业主反馈,删除的id是:{}",notepadId);
        NotePad notePad = lambdaQuery()
                .eq(NotePad::getNoteId, notepadId)
                .eq(NotePad::getObjId, objId)
                .one();
        if(notePad  == null){
            throw new RuntimeException("不存在该业主反馈");
        }
        //首先删除业主反馈表的相关信息
        notePad.setStatusCd("1");
        //逻辑删除
        boolean flag = this.updateById(notePad);
        if(!flag){
            throw new RuntimeException("删除失败");
        }
        //查询是否存在跟进进度
        List<NotePadDetail> list = notepadDetailMapper.selectList(new QueryWrapper<NotePadDetail>()
                .eq("note_id", notepadId)
                .eq("status_cd", "0")
        );
        if(list == null || list.isEmpty()){
            return ;
        }
        //删除细节表的相关信息
        notepadDetailMapper.updateByNoteId(notepadId);
        log.info("删除业主反馈成功");
    }
}
