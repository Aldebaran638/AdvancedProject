package com.zeroone.star.project.dto.j3.merchantmanage.message;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 商户信息传输模型
 * @author wyr on 2025/5/19
 */
@ApiModel("商户信息传输模型")
@Data
public class MerchantDTO {
    @ApiModelProperty(value = "商户名称", example = "HC小区开发团队")
    private String name;
    @ApiModelProperty(value = "商户地址", example = "广东省东莞市振兴路197号")
    private String address;
    @ApiModelProperty(value = "联系电话", example = "18502260001")
    private String tel;
    @ApiModelProperty(value = "商户类型", example = "物业公司")
    private String storeType;
    @ApiModelProperty(value = "企业法人", example = "张三")
    private String corporate;
    @ApiModelProperty(value = "成立日期", example = "2000-01-01")
    private String establishDate;

}
