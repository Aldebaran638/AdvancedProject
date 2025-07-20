package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("发票事件新增模型")
public class InvoiceEventCreateDTO implements Serializable {

    public static final String STATE_COMPLETE = "1001";         //审核成功
    public static final String STATE_UPLOAD = "2002";           //上传
    public static final String STATE_FAIL = "3003";             //审核失败
    public static final String EVENT_TYPE_GET = "4004";         //领用
    public static final String EVENT_TYPE_REGISTER = "5005";    // 登记

    @ApiModelProperty(value = "发票申请ID")
    private String applyId;

    @ApiModelProperty(value = "社区ID")
    private String communityId;

    @ApiModelProperty(value = "事件类型")
    private String eventType;

    @ApiModelProperty(value = "创建人Id")
    private Integer createUserId;

    @ApiModelProperty(value = "创建人名称")
    private String createUserName;

    @ApiModelProperty(value = "备注")
    private String remark;
}
