package com.zeroone.star.project.dto.j7.parkmanage.parkingapply;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author neko
 * #Description：审核申请模型
 * #Date: 2025/5/19 17:30
 */
@ApiModel("审核申请模型")
@Data
public class ReviewApplicationDTO {
    @ApiModelProperty(value = "申请ID", example = "102021101844540055")
    private String applyId;
    @ApiModelProperty(value = "车位ID", example = "792022010572850986")
    private String psId;
    @ApiModelProperty(value = "费用项ID", example = "922022011217560084")
    private String configId;
    @ApiModelProperty(value = "状态", example = "2002")
    private String state;
    @ApiModelProperty(value = "备注", example = "审核意见：可以通过")
    private String remark;
    @ApiModelProperty(value = "费用ID", example = "102022012476870453")
    private String feeId;
}
