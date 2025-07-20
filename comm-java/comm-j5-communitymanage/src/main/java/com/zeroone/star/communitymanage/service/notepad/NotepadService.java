package com.zeroone.star.communitymanage.service.notepad;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.notepad.AddNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.DelNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.ModifyNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.NotepadDTO;
import com.zeroone.star.project.query.j5.community.notepad.NotepadQuery;

public interface NotepadService {
    PageDTO<NotepadDTO> list(NotepadQuery query);

    void saveNotePad(AddNotepadDTO addNotepadDTO);

    void updateNotePad(ModifyNotepadDTO modifyNotepadDTO);

    void removeNotePad(DelNotepadDTO delNotepadDTO);
}
