package com.zeroone.star.project.j7.parkmanage;

import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.AddApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ApplyDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ReviewApplicationDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkingapply.GetParkingApplyQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @author neko
 * #Description：车位申请apis
 * #Date: 2025/5/19 17:56
 */
public interface  ParkingApplyApis {


    /**
     * 添加申请
     * @param   addApplyDTO 添加停车申请模型
     * @return 操作结果
     */
    JsonVO<String> addApply(AddApplyDTO addApplyDTO);



    /**
     * 更新申请
     * @param applyDTO 添加申请模型
     * @return 操作结果
     */
    JsonVO<String> modifyApply(ApplyDTO applyDTO);


    /**
     * 删除申请
     * @param  applyId 申请id
     * @return 操作结果
     */
    JsonVO<String> removeApply(String applyId);





    /**
=======
   /**
>>>>>>> remotes/origin/j7-zhangjiaqi
     * 审核申请
     * @param reviewApplicationDTO 审核模型
     * @return 审核结果
     */
    JsonVO<String> reviewApplication(ReviewApplicationDTO reviewApplicationDTO);



  /**
     * 获取申请列表（分页+条件）
     * @param query 查询模型
     * @return 申请列表
     */
    JsonVO<PageDTO<ApplyDTO>> queryParkingApplyQuery(GetParkingApplyQuery query,String id, String applyPersonName, String carBrand);


}
