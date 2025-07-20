package com.zeroone.star.project.j5.community.renovation;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationAddDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDTO;
import com.zeroone.star.project.query.j5.community.renovation.RenovationQuery;
import com.zeroone.star.project.vo.JsonVO;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：房屋装修接口
 *      西班牙馅饼：获取装修列表（条件+分页）、添加装修、修改装修、删除装修、审核装修、完成装修
 * </p>
 * @author 西班牙馅饼
 * @version 1.0.0
 */
public interface RenovationApis {
    /**
     * 获取装修列表(条件+分页)
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<RenovationDTO>> queryRenovation(RenovationQuery query, String communityId);

    /**
     * 添加装修/新增装修
     * @param addDto 新增装修数据
     * @return 添加success/fail结果
     */
    JsonVO<String> addRenovation(RenovationAddDTO addDto);

    /**
     * 修改装修
     * @param modifyDto 修改条件
     * @return 修改结果
     */
    JsonVO<String> modifyRenovation(RenovationDTO modifyDto);

    /**
     * 删除装修
     * @param rId 删除装修对象的rId
     * @return 删除结果
     */
    JsonVO<String> removeRenovation(@NotBlank(message = "rId不能为空") String rId);

    /**
     * 审核装修(修改装修部分条件)
     * @param rId 装修对象的rId
     * @param state 3000-审核通过  2000-审核不通过
     * @param examineRemark 审核备注
     * @return 审核结果
     */
    JsonVO<String> modifyRenoStatus(@NotBlank(message = "rId不能为空") String rId, @NotBlank(message = "state不能为空") String state, String examineRemark);

    /**
     * 完成装修 通过rId查询对象，并且只需修改对象status一个参数为4000
     * @param id 修改对象的rId
     * @return 修改结果
     */
    JsonVO<String> modifyRenoStatusById(@NotBlank(message = "rId不能为空") String id);
}
