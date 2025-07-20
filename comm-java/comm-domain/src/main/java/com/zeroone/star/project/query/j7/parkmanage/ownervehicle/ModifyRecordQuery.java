package com.zeroone.star.project.query.j7.parkmanage.ownervehicle;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;

/**
 * @Author：daimon
 * @Date：2025/6/2
 * @discription:
 */
@ApiModel("获取车辆修改记录查询对象")
@Data
public class ModifyRecordQuery extends PageQuery {
    @ApiModelProperty(value = "车辆ID",example = "102024022034585148",required = true)
    @Size(min = 18,max = 18,message = "车辆ID只能为18位")
    @Pattern(regexp = "[0-9]+",message = "车牌ID只能为数字")
    String carId;

    @ApiModelProperty(value = "成员ID",example = "102024022034585148",required = true)
    @Size(min = 18,max = 18,message = "车辆ID只能为18位")
    @Pattern(regexp = "[0-9]+",message = "车牌ID只能为数字")
    String memberId;
}
