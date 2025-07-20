package com.zeroone.star.project.j5.community.notepad;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.notepad.AddNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.DelNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.ModifyNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.NotepadDTO;
import com.zeroone.star.project.query.j5.community.notepad.NotepadQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;

/**
 * <p>
 * 描述：业务受理接口
 *      人间理想：获取业主反馈列表（条件+分页）、添加业主反馈、修改业主反馈、删除业主反馈
 * </p>
 * @author 人间理想
 * @version 1.0.0
 */
public interface NotepadOwnerApis {

    /**
     * 获取业主反馈列表（条件+分页）
     * @param query 查询条件
     * @return 业主反馈列表
     */
    JsonVO<PageDTO<NotepadDTO>> listNotepad(NotepadQuery query);

    /**
     * 添加业主反馈
     * @param addNotepadDTO 添加业主反馈参数
     * @return 添加结果
     */
    JsonVO<String> addNotePad(AddNotepadDTO addNotepadDTO);

    /**
     * 修改业主反馈
     * @param modifyNotepadDTO 业主反馈dto
     * @return 修改结果
     */
    JsonVO<String> modifyNotePad(ModifyNotepadDTO modifyNotepadDTO);

    /**
     * 删除业主反馈
     * @param delNotepadDTO 反馈id和业主id
     * @return  删除结果
     */
    JsonVO<String> removeNotePad(DelNotepadDTO delNotepadDTO);
}
