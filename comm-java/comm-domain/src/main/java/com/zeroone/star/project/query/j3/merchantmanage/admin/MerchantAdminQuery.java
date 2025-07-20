package com.zeroone.star.project.query.j3.merchantmanage.admin;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;

/**
 * 商户管理员查询
 *
 * @author wyr on 2025/5/19
 */
@Data
@ApiModel("商户管理员查询模型")
public class MerchantAdminQuery extends PageQuery {
    @ApiModelProperty(value = "物业名称", example = "HC演示物业2")
    @Size(max = 100, message = "物业名称长度不能超过100字符")
    private String storeName;
    @ApiModelProperty(value = "管理员", example = "HC演示物业2")
    @Size(max = 50, message = "管理员名称长度不能超过50字符")
    private String name;
    @ApiModelProperty(value = "电话", example = "18909711443")
    @Pattern(regexp = "^(1[3-9]\\d{9})?$", message = "电话格式不合法")
    private String tel;
}
