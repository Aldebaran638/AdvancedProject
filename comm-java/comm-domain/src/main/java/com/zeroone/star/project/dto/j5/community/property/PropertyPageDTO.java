package com.zeroone.star.project.dto.j5.community.property;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Value;

import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：房屋产权数据传输模型
 * </p>
 *
 * @author 苏坡man
 */
@ApiModel("房屋产权详情模型")
@Data
public class PropertyPageDTO {

    @ApiModelProperty(value="房屋产权ID", example = "102022122430650861",required = true)
    private  String prrId;

    @ApiModelProperty(value="房屋ID", example = "752022121911900401",required = true)
    private  String roomId;

    @ApiModelProperty(value="房屋编号", example = "3-201",required = true)
    private  String roomNum;

    @ApiModelProperty(value="姓名", example = "啊吧啊吧",required = true)
    private  String name;

    @ApiModelProperty(value="联系方式", example = "18947314754",required = true)
    private  String link;

    @ApiModelProperty(value="身份证号", example = "768681189007243679",required = true)
    private  String idCard;

    @ApiModelProperty(value="地址", example = "啊啊啊",required = true)
    private  String address;

    @Pattern(regexp = "0|1|2", message = " 审核状态  0 未审核  1 审核通过  2 审核拒绝")
    @ApiModelProperty(value="状态", example = "0",required = true)
    private  String state;



}
