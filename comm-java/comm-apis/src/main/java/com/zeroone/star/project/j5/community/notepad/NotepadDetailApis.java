package com.zeroone.star.project.j5.community.notepad;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.notepad.*;
import com.zeroone.star.project.query.j5.community.notepad.ListNotepadDetailQuery;
import com.zeroone.star.project.query.j5.community.notepad.RepairTypeQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：业务受理接口
 *      灰灰：获取跟进进度列表（条件+分页），添加跟进进度、删除跟进进度、转报修单
 * </p>
 * @author 灰灰
 * @version 1.0.0
 */
public interface NotepadDetailApis {

    /**
     * 获取跟进进度列表（条件+分页）
     * @param notepadDTO 查询参数
     * @return 分页数据结果
     */
    JsonVO<PageDTO<NotepadDetailDTO>> query(ListNotepadDetailQuery notepadDTO);

    /**
     * 添加跟进进度
     * @param notepadDTO 新增数据传输对象
     * @return 操作结果
     */
    JsonVO<String> add(SaveNotepadDetailDTO notepadDTO);

    /**
     * 删除跟进进度
     * @param notepadDTO 删除数据传输对象
     * @return 操作结果
     */
    JsonVO<String> remove(DeleteNotepadDetailDTO notepadDTO);

    /**
     * 转报修单
     * @param repairDTO 转换参数
     * @return 操作结果
     */
    JsonVO<String> add(ChangeToRepairDTO repairDTO);

    /**
     * 查询可报修类型
     * @param repairDTO 转换参数
     * @return 操作结果
     */
    JsonVO<List<RepairTypeDTO>>  query(RepairTypeQuery repairDTO);

}
