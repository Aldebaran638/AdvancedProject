package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * 更新发票申请状态
 */
@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("登记发票模型")
public class InvoiceApplyUpdateDTO implements Serializable {

    public static final String STATE_WAIT = "W"; // 待审核
    public static final String STATE_UPLOAD = "U"; // 待上传
    public static final String STATE_FAIL = "F"; // 审核失败
    public static final String STATE_GET = "G"; // 带领用
    public static final String STATE_COMPLETE = "C"; // 已领用

    @ApiModelProperty(value = "发票申请ID")
    private String applyId;

    @ApiModelProperty(value = "状态")
    private String state;

    @ApiModelProperty(value = "社区id")
    private String communityId;
}
