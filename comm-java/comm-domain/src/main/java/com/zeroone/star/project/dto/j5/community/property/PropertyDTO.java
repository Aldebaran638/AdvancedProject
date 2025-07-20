package com.zeroone.star.project.dto.j5.community.property;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Value;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：房屋产权数据传输模型
 * </p>
 *
 * @author 苏坡man
 */
@ApiModel("房屋产权传输模型")
@Data
public class PropertyDTO{

    @ApiModelProperty(value="房屋产权ID", example = "1929925019366985728",required = true)
    private  String prrId;

    @ApiModelProperty(value = "姓名",example = "Jungle",required = true)
    @NotBlank(message = "姓名不能为空")
    private String name;

    @NotBlank(message = "联系方式不能为空")
    @ApiModelProperty(value = "联系方式",example = "13452452141",required = true)
    private String link;

    @Pattern(regexp = "^\\d{18}$", message = "身份证号必须是18位纯数字")
    @ApiModelProperty(value = "身份证号",example = "111222333444556566",required = true)
    private String idCard;

    @NotBlank(message = "地址不能为空")
    @ApiModelProperty(value = "地址",example = "北京中路999号",required = true)
    private String address;


    @ApiModelProperty(value = "小区Id",example = "2023052267100146",required = true)
    private String communityId;


    @ApiModelProperty(value = "楼栋名",example = "1栋",required = true)
    private String floorName;


    @ApiModelProperty(value = "单元编号",example = "1",required = true)
    private String unitNum;

    @ApiModelProperty(value = "房屋编号",example = "1001",required = true)
    private String roomNum;

    @ApiModelProperty(value = "对象ID",example = "772023061990824972",required = true)
    private String objId;


}
