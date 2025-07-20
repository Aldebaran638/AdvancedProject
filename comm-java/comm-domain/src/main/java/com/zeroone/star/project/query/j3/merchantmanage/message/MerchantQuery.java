package com.zeroone.star.project.query.j3.merchantmanage.message;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Max;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;

/**
 * 查询商户信息
 *
 * @author wyr on 2025/5/19
 */
@Data
@ApiModel("商户信息查询模型")
public class MerchantQuery extends PageQuery {
    @Size(max = 100, message = "商户名称长度不能超过100字符")
    @ApiModelProperty(value = "商户名称", example = "YF物业")
    private String storeName;
    @ApiModelProperty(value = "商户类型", example = "商家")
    @Size(max = 50, message = "商户类型长度不能超过50字符")
    private String storeType;
    @ApiModelProperty(value = "电话", example = "18502260001")
    @Pattern(regexp = "^(1[3-9]\\d{9})?$", message = "电话格式不合法")
    private String tel;


}
