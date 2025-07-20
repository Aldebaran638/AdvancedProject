package com.zeroone.star.communitymanage.mapper.notepad;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.communitymanage.entity.notepad.NotePadDetail;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Update;

@Mapper
public interface NotepadDetailMapper extends BaseMapper<NotePadDetail> {

    @Update("update notepad_detail set status_cd = '1' where note_id = #{noteId} and status_cd = 0")
    void updateByNoteId(@Param("noteId") String notepadId);
}
