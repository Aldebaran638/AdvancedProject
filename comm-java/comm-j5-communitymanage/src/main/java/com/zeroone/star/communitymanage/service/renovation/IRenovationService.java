package com.zeroone.star.communitymanage.service.renovation;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDTO;
import com.zeroone.star.project.query.j5.community.renovation.RenovationQuery;
import com.zeroone.star.communitymanage.entity.renovation.RoomRenovation;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author powfu
 * @since 2025-05-23
 */
public interface IRenovationService extends IService<RoomRenovation> {
    /**
     * 获取装修列表(分页+条件)
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<RenovationDTO> listAll(RenovationQuery query, String communityId);

    /**
     * 完成装修(更改status)
     * @param rId 更新对象rId
     * @return 更新结果
     */
    boolean updateByRId(String rId);

    /**
     * 审核装修(修改装修部分条件)
     * @param rId 装修对象的rId
     * @param state 3000-审核通过  2000-审核不通过
     * @param examineRemark 审核备注
     * @return 审核结果
     */
    boolean updateStatus(String rId, String state, String examineRemark);

    /**
     * 修改装修
     * @param entity 装修实体类
     * @return 修改结果
     */
    boolean updateRenoById(RoomRenovation entity);
}
