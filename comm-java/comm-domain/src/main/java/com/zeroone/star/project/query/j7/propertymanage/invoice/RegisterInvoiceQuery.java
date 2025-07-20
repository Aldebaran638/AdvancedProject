package com.zeroone.star.project.query.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import java.io.Serializable;

/**
 * @ClassName RegisterInvoiceQuery
 * @Description 登记发票数据层封装
 **/
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("登记发票请求模型")
public class RegisterInvoiceQuery implements Serializable {

    @ApiModelProperty("发票申请ID")
    @NotBlank(message = "applyId不能为空")
    private String applyId;

    @ApiModelProperty("操作说明")
    @NotBlank(message = "说明不能为空")
    private String remark;

    @ApiModelProperty("事件类型")
    @NotBlank(message = "类型不能为空")
    private String eventType;

    @ApiModelProperty("社区Id")
    @NotBlank(message = "communityId不能为空")
    private String communityId;

}
