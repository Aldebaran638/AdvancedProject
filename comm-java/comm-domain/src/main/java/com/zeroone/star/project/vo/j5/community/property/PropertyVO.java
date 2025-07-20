package com.zeroone.star.project.vo.j5.community.property;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.hibernate.validator.constraints.Length;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author Jungle
 * @version 1.0.0
 */
@ApiModel("房屋产权显示对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class PropertyVO {

    @ApiModelProperty(value="产权登记Id", example = "112022122438600864",required = true)
    private  String prrdId;

    @ApiModelProperty(value = "姓名",example = "Jungle")
    private String name;

    @Pattern(regexp = "^\\d{18}$", message = "房屋Id必须是18位纯数字")
    @ApiModelProperty(value = "房屋Id",example = "111222333444556566")
    private String roomId;

    @ApiModelProperty(value = "房屋编号",example = "一号房")
    private String roomNum;

    @ApiModelProperty(value = "联系方式",example = "13452452141")
    private String link;

    @Pattern(regexp = "^\\d{18}$", message = "身份证号必须是18位纯数字")
    @ApiModelProperty(value = "身份证号",example = "111222333444556566")
    private String idCard;

    @ApiModelProperty(value = "地址",example = "北京中路999号")
    private String address;

    @ApiModelProperty(value = "楼栋编号",example = "4号楼")
    private String floorNum;


    @ApiModelProperty(value = "单元编号",example = "一单元")
    private String unitNum;


    @ApiModelProperty(value = "材料类型",example = "身份证")
    private String securities;


    @ApiModelProperty(value = "是否缴费",example = "已缴费")
    private String isTrue;

    @ApiModelProperty(value = "数据状态",example = "1")
    private String statusCd;
}
