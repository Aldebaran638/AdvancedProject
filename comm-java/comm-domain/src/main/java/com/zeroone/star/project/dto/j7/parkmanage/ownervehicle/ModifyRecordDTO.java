package com.zeroone.star.project.dto.j7.parkmanage.ownervehicle;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Pattern;

/**
 * @Author：daimon
 * @Date：2025/5/20
 * @discription:
 */
@Data
@ApiModel(value = "车辆修改记录模型")
public class ModifyRecordDTO {

    @ApiModelProperty(value = "车牌号",example = "渝A12112")
    @Pattern(regexp = "^[\\u4e00-\\u9fa5][A-Z][A-Z0-9]{5}$",message = "车牌号的格式不正确，合法的格式为：渝A12112")
    private String carNum;

    @ApiModelProperty(value = "车辆品牌",example = "大众")
    private String carBrand;

    @ApiModelProperty(value = "车辆类型",example = "9901")
    @Pattern(regexp = "^990[123]$",message = "只能是9901/9902/9903")
    private String carType;

    @ApiModelProperty(value = "车辆颜色",example = "黑色")
    private String carColor;

    @ApiModelProperty(value = "用户名",example = "qq1")
    private String userName;

    @ApiModelProperty(value = "电话",example = "18109711443")
    @Pattern(regexp = "^1[0-9]{10}$")
    private String userTel;

    @ApiModelProperty(value = "车位状态",example = "1001")
    @Pattern(regexp = "^100[12]$",message = "只能为1001或者1002")
    private String state;

    @ApiModelProperty(value = "起租时间",example = "2024-01-01 00:00:00")
    @Pattern(
            regexp = "^(19|20)\\d{2}-(0[1-9]|1[0-2])-"
                    + "(0[1-9]|[12][0-9]|3[01]) "
                    + "([01][0-9]|2[0-3]):"
                    + "([0-5][0-9]):([0-5][0-9])$",
            message = "起租时间的格式应为：yyyy-MM-dd HH:mm:ss，例如 2024-01-01 00:00:00"
    )
    private String startTime;

    @ApiModelProperty(value = "截止时间",example = "2024-12-31 23:55:00")
    @Pattern(
            regexp = "^(19|20)\\d{2}-(0[1-9]|1[0-2])-"
                    + "(0[1-9]|[12][0-9]|3[01]) "
                    + "([01][0-9]|2[0-3]):"
                    + "([0-5][0-9]):([0-5][0-9])$",
            message = "起租时间的格式应为：yyyy-MM-dd HH:mm:ss，例如 2024-01-01 00:00:00"
    )
    private String endTime;

    @ApiModelProperty(value = "创建时间",example = "2025-06-02 14:59:20")
    @Pattern(
            regexp = "^(19|20)\\d{2}-(0[1-9]|1[0-2])-"
                    + "(0[1-9]|[12][0-9]|3[01]) "
                    + "([01][0-9]|2[0-3]):"
                    + "([0-5][0-9]):([0-5][0-9])$",
            message = "起租时间的格式应为：yyyy-MM-dd HH:mm:ss，例如 2024-01-01 00:00:00"
    )
    private String createTime;
}
