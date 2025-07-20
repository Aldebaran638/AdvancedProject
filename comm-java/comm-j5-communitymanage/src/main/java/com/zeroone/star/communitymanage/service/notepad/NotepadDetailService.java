package com.zeroone.star.communitymanage.service.notepad;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.notepad.DeleteNotepadDetailDTO;
import com.zeroone.star.project.dto.j5.community.notepad.NotepadDetailDTO;
import com.zeroone.star.project.dto.j5.community.notepad.SaveNotepadDetailDTO;
import com.zeroone.star.project.query.j5.community.notepad.ListNotepadDetailQuery;

public interface NotepadDetailService {

    //获取跟进进度列表（条件+分页）
    PageDTO<NotepadDetailDTO> list(ListNotepadDetailQuery notepadQuery);

    //添加跟进进度
    void save(SaveNotepadDetailDTO notepadDTO);

    //删除跟进进度
    void remove(DeleteNotepadDetailDTO notepadDTO);
}
