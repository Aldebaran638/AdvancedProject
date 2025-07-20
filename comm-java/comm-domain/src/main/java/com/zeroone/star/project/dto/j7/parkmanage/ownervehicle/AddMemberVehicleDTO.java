package com.zeroone.star.project.dto.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;

/**
 * @Author：daimon
 * @Date：2025/5/20
 * @discription:
 */
@Data
@ApiModel(value = "添加成员车辆模型")
public class AddMemberVehicleDTO {

    @ApiModelProperty(value = "车牌号", example = "渝A12112", required = true)
    @Pattern(regexp = "^[\\u4e00-\\u9fa5][A-Z][A-Z0-9]{5}$",message = "车牌号的格式不正确，合法的格式为：渝A12112")
    private String carNum;

    @ApiModelProperty(value = "车辆品牌", example = "大众", required = true)
    private String carBrand;

    @ApiModelProperty(value = "车辆类型", example = "9901", required = true)
    @Pattern(regexp = "^990[123]$",message = "只能是9901/9902/9903")
    private String carType;

    @ApiModelProperty(value = "车辆颜色", example = "黑色", required = true)
    private String carColor;

    @ApiModelProperty(value = "汽车Id", example = "102024022034585148")
    @Size(min = 18,max = 18,message = "车辆ID只能为18位")
    @Pattern(regexp = "[0-9]+",message = "车牌ID只能为数字")
    private String carId;

    @ApiModelProperty(value = "成员ID", example = "102024022034585148")
    @Size(min = 18,max = 18,message = "车辆ID只能为18位")
    @Pattern(regexp = "[0-9]+",message = "车牌ID只能为数字")
    private String memberId;

    @ApiModelProperty(value = "备注")
    private String remark;

}
