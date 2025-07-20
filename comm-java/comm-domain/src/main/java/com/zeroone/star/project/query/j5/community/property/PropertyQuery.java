package com.zeroone.star.project.query.j5.community.property;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：查询房屋产权列表的参数
 * </p>
 * @author 苏坡man
 */
@ApiModel("分页查询房屋产权列表")
@Data
public class PropertyQuery  extends PageQuery {

    @ApiModelProperty(value="小区ID", example = "2021080494780158",required = true)
    private  String communityId;
    @ApiModelProperty(value="房屋ID", example = "752022121911900401")
    private  String roomId;

    @ApiModelProperty(value="房屋编号", example = "3-201")
    private  String roomNum;
    @ApiModelProperty(value="姓名", example = "啊吧啊吧")
    private  String name;
    @ApiModelProperty(value="联系方式", example = "18947314754")
    private  String link;

    @ApiModelProperty(value="身份证号", example = "768681189007243679")
    private  String idCard;

    @ApiModelProperty(value="地址", example = "啊啊啊")
    private  String address;
    @Pattern(regexp = "0|1|2", message = " 审核状态  0 未审核  1 审核通过  2 审核拒绝")
    @ApiModelProperty(value="状态", example = "0")
    private  String state;//审核状态  0 未审核  1 审核通过  2 审核拒绝
    @ApiModelProperty(value="楼栋", example = "2")
    private  String floorNum;
    @ApiModelProperty(value="单元", example = "1")
    private  String unitNum;
}