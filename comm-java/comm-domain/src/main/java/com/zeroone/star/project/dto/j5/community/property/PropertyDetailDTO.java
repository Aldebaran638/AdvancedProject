package com.zeroone.star.project.dto.j5.community.property;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：房屋产权详情数据模型
 * </p>
 *
 * @author 苏坡man
 */
@ApiModel("房屋产权详情模型")
@Data
public class PropertyDetailDTO  {
    @ApiModelProperty(value="产权登记Id", example = "112022122438600864",required = true)
    private  String prrdId;

    @Pattern(regexp = "001|002|003|004", message = " 材料状态只能为这些值:001身份证   002购房合同   003维修基金   004契税")
    @ApiModelProperty(value = "材料类型      001身份证   002购房合同   003维修基金   004契税",example = "001",required = true)
    private String securities;

    @Pattern(regexp = "是|否", message = "是否缴费  ture 是   false 否")
    @ApiModelProperty(value="是否缴费      ture 是   false 否", example = "是",required = true)
    private  String isTrue;


    @ApiModelProperty(value = "文件真实名称",example = "",required = true)
    private String fileRealName;
    @ApiModelProperty(value = "图片URL地址",example = "",required = true)
    private String url ="http://39.103.62.65:8888/" + fileRealName;
    @Pattern(regexp = "0|1", message = "状态只能是0(有效的，在用的)|1(无效的，不在用的)")
    @ApiModelProperty(value = "数据状态    0有效的,1无效的",example = "0",required = true)
    private String statusCd;

    @ApiModelProperty(value="创建时间", example = "2022-12-24 16:16:45",required = true)
    private  String createTime;


}
