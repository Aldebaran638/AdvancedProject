package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.notepad.NotepadService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.notepad.AddNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.DelNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.ModifyNotepadDTO;
import com.zeroone.star.project.dto.j5.community.notepad.NotepadDTO;
import com.zeroone.star.project.j5.community.notepad.NotepadOwnerApis;
import com.zeroone.star.project.query.j5.community.notepad.NotepadQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：业务受理中业主相关的控制器
 * </p>
 * @author 人间理想
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/notepad/owner")
@Api(tags = "业务受理")
public class NotepadOwnerController implements NotepadOwnerApis {

    @Resource
    private NotepadService notepadService;
    @ApiOperation("获取业主反馈列表（条件+分页）")
    @GetMapping("query-page")
    @Override
    public JsonVO<PageDTO<NotepadDTO>> listNotepad(NotepadQuery query) {
        return JsonVO.success(notepadService.list(query));
    }

    @ApiOperation("添加业主反馈")
    @PostMapping("add-notepad")
    @Override
    public JsonVO<String> addNotePad(@RequestBody @Validated AddNotepadDTO addNotepadDTO) {
        notepadService.saveNotePad(addNotepadDTO);
        return JsonVO.success("添加成功");
    }

    @ApiOperation("修改业主反馈")
    @PutMapping("modify-notepad")
    @Override
    public JsonVO<String> modifyNotePad(@RequestBody @Validated ModifyNotepadDTO modifyNotepadDTO) {
        notepadService.updateNotePad(modifyNotepadDTO);
        return JsonVO.success("修改成功");
    }

    @ApiOperation("删除业主反馈")
    @DeleteMapping("remove-notepad-by-id")
    @Override
    public JsonVO<String> removeNotePad(@RequestBody @Validated DelNotepadDTO delNotepadDTO) {
        notepadService.removeNotePad(delNotepadDTO);
        return JsonVO.success("删除成功");
    }
}
