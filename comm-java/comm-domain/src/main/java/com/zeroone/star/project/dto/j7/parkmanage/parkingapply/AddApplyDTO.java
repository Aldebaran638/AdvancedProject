package com.zeroone.star.project.dto.j7.parkmanage.parkingapply;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@ApiModel("添加停车申请模型")
@Data
public class AddApplyDTO  {

    @ApiModelProperty(value = "申请人id", example = "772024022183707296772024022183707296",required = true)
    private String applyPersonId;
    @ApiModelProperty(value = "申请人", example = "成龙",required = true)
    private String applyPersonName;
    @ApiModelProperty(value = "小区id", example = "2023052267100146",required = true)
    private String communityId;
    @ApiModelProperty(value = "车牌号", example = "黑AR7970",required = true)
    private String carNum;
    @ApiModelProperty(value = "汽车品牌", example = "大众",required = true)
    private String carBrand;
    @ApiModelProperty(value = "车辆类型", example = "9901",required = true)
    private String carType;
    @ApiModelProperty(value = "颜色", example = "红色",required = true)
    private String carColor;
    @ApiModelProperty(value = "起租时间", example = "2024-02-22 11:25:00",required = true)
    private Date startTime;
    @ApiModelProperty(value = "结束时间", example = "2025-01-17 11:55:00",required = true)
    private Date endTime;
    @ApiModelProperty(value = "申请人电话", example = "13345674567",required = true)
    private String applyPersonLink;
    @ApiModelProperty(value = "备注", example = "审核意见：可以通过")
    private String remark;




}
