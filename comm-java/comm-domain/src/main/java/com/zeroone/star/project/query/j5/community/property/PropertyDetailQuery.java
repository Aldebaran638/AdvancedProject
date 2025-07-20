package com.zeroone.star.project.query.j5.community.property;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.web.bind.annotation.RequestParam;

import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：查询房屋产权详情的参数
 * </p>
 * @author 苏坡man
 */
@ApiModel("查询房屋产权详情")
@Data
public class PropertyDetailQuery extends PageQuery {
    @ApiModelProperty(value="小区ID", example = "2021080494780158",required = true)
    private  String communityId;
    @ApiModelProperty(value="产权登记ID", example = "102024022019845984",required = true)
    private  String prrId;
    @ApiModelProperty(value="楼栋", example = "2",required = true)
    private  String floorNum;
    @ApiModelProperty(value="单元", example = "1",required = true)
    private  String unitNum;
    @ApiModelProperty(value="房屋编号", example = "110",required = true)
    private  String roomNum;



}
