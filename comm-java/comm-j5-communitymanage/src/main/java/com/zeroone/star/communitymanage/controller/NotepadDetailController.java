package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.notepad.NotepadDetailService;
import com.zeroone.star.communitymanage.service.notepad.RepairTypeService;
import com.zeroone.star.communitymanage.service.notepad.ToRepairService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.notepad.*;
import com.zeroone.star.project.j5.community.notepad.NotepadDetailApis;
import com.zeroone.star.project.query.j5.community.notepad.ListNotepadDetailQuery;
import com.zeroone.star.project.query.j5.community.notepad.RepairTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import javax.validation.Valid;
import java.util.List;

/**
 * <p>
 * 描述：业务受理跟进记录的控制器
 * </p>
 * @author 灰灰
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/notepad/detail")
@Api(tags = "业务受理")
public class NotepadDetailController implements NotepadDetailApis {

    @Autowired
    NotepadDetailService detailService;

    @Autowired
    RepairTypeService repairTypeService;

    @Autowired
    ToRepairService toRepair;
    /**
     * 获取跟进进度列表（条件+分页）
     *
     * @param notepadQuery 查询参数
     * @return 分页数据结果
     */
    @Override
    @GetMapping("/query-notepad")
    @ApiOperation("获取跟进进度列表（条件+分页）")
    public JsonVO<PageDTO<NotepadDetailDTO>> query(@Valid @ModelAttribute ListNotepadDetailQuery notepadQuery) {
        return JsonVO.success(detailService.list(notepadQuery));
    }
    /**
     * 添加跟进进度
     * @param notepadDTO 新增数据传输对象
     * @return 操作结果
     */
    @Override
    @PostMapping("/add-notepad")
    @ApiOperation("添加跟进进度")
    public JsonVO<String> add(@Valid @RequestBody SaveNotepadDetailDTO notepadDTO) {
        detailService.save(notepadDTO);
        return JsonVO.success("跟进进度成功");
    }
    /**
     * 删除跟进进度
     * @param notepadDTO 删除数据传输对象
     * @return 操作结果
     */
    @Override
    @DeleteMapping("/remove-notepad")
    @ApiOperation("删除跟进进度")
    public JsonVO<String> remove(@Valid @RequestBody DeleteNotepadDetailDTO notepadDTO) {
        detailService.remove(notepadDTO);
        return  JsonVO.success("删除跟进进度成功");
    }
    /**
     * 转报修单
     * @param repairDTO 转换参数
     * @return 操作结果
     */
    @Override
    @PostMapping("/add-repair")
    @ApiOperation("转报修单")
    public JsonVO<String> add(@Valid @RequestBody ChangeToRepairDTO repairDTO) {
        toRepair.save(repairDTO);
        return JsonVO.success("业务已成功转报修单");
    }
    /**
     * 查询可报修类型
     * @param repairQuery 转换参数
     * @return 操作结果
     */
    @Override
    @GetMapping("/query-repair")
    @ApiOperation("查询可报修类型")
    public JsonVO<List<RepairTypeDTO>> query(@Valid @ModelAttribute RepairTypeQuery repairQuery) {
        return repairTypeService.queryRepairType(repairQuery);
    }
}
