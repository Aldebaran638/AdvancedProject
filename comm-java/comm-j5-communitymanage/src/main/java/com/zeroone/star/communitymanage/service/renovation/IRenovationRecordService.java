package com.zeroone.star.communitymanage.service.renovation;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.renovation.AddRenovationRecordDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDetailDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationRecordDTO;
import com.zeroone.star.project.query.j5.community.renovation.RenovationDetailQuery;
import com.zeroone.star.project.query.j5.community.renovation.RenovationRecordQuery;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.communitymanage.entity.renovation.RoomRenovationRecord;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author tianganwuzao
 * @since 2025-05-23
 */
public interface IRenovationRecordService extends IService<RoomRenovationRecord> {

    /**
     * 获取房屋装修记录列表（条件+分页）
     * @param query 查询参数
     * @return 房屋装修记录列表
     */
    PageDTO<RenovationRecordDTO> listRenovationRecord(RenovationRecordQuery query);

    /**
     * 删除房屋装修记录
     * @param recordId 房屋装修记录id
     * @return 是否删除成功
     */
    Boolean removeRenovationRecord(String recordId);

    /**
     * 获取房屋装修记录详情列表（条件+分页）
     * @param query 查询参数
     * @return 房屋装修记录详情列表
     */
    PageDTO<RenovationDetailDTO> listRenovationRecordDetail(RenovationDetailQuery query);

    /**
     * 添加房屋装修记录
     * @param dto 添加房屋装修记录参数
     * @return 是否添加成功
     */
    boolean saveRenovationRecord(AddRenovationRecordDTO dto);
}
