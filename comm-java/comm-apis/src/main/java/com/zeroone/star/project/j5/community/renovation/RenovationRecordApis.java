package com.zeroone.star.project.j5.community.renovation;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.renovation.AddRenovationRecordDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDetailDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationRecordDTO;
import com.zeroone.star.project.query.j5.community.renovation.RenovationDetailQuery;
import com.zeroone.star.project.query.j5.community.renovation.RenovationRecordQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：房屋装修接口
 *      天干勿躁：获取跟进记录列表（条件+分页）、查看跟进记录详情、添加跟进记录、删除跟进记录
 * </p>
 * @author 天干勿躁
 * @version 1.0.0
 */
public interface RenovationRecordApis {
    /**
     * 分页查询房屋装修记录
     * @param query 查询数据对象
     * @return 查询结果
     */
    JsonVO<PageDTO<RenovationRecordDTO>> queryRenovationRecord(RenovationRecordQuery query);

    /**
     * 添加房屋装修记录
     * @param dto 添加数据对象
     * @return 添加结果
     */
    JsonVO<String> addRenovationRecord(AddRenovationRecordDTO dto);
    /**
     * 删除房屋装修记录
     * @param recordId 删除数据对象
     * @return 删除结果
     */
    JsonVO<String> deleteRenovationRecord(String recordId,String communityId);
    /**
     * 查看房屋装修记录详情
     * @param query 查询数据对象id
     * @return 查询结果
     */
    JsonVO<PageDTO<RenovationDetailDTO>> queryRenovationRecordDetail(RenovationDetailQuery query);
}
