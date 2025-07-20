package com.zeroone.star.communitymanage.mapper.renovation;

import com.zeroone.star.communitymanage.entity.renovation.RoomRenovation;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author powfu
 * @since 2025-05-23
 */
@Mapper
public interface RenovationMapper extends BaseMapper<RoomRenovation> {

    /**
     * 完成装修
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
