package com.zeroone.star.parkmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.parkmanage.entity.ParkingSpaceApply;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.AddApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ReviewApplicationDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestBody;

public interface IParkingSpaceApplyService extends IService<ParkingSpaceApply> {


    /**
     * 新增停车申请
     * @param addApplyDTO
     * @return
     */
    int saveParkingApply(AddApplyDTO addApplyDTO);

    /**
     *
     * @param applyDTO
     * @return
     */
    int updateParkingApply(ApplyDTO applyDTO);

    /**
     * 删除停车申请
     * @param applyId
     * @return
     */
    int removeParkingApply(String applyId);

    /**
     * 审核申请
     * @param reviewApplicationDTO 申请dto
     * @return 成功/失败
     */
    JsonVO<String> reviewApplication(ReviewApplicationDTO reviewApplicationDTO);



}