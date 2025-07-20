package com.zeroone.star.project.dto.j3.systemmanage.register;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.util.Date;

@Getter
@Setter
@ToString
@ApiModel("注册协议修改数据对象")
public class RegisterProtocolDTO implements Serializable {
    @ApiModelProperty(value = "商家注册协议",example = "注册协议条款的确认和接受...")
    private String merchantProtocol;
    @ApiModelProperty(value = "用户注册协议",example = "注册协议条款的确认和接受...")
    private String userProtocol;
    @ApiModelProperty(value = "数据状态，详细参考c_status表，S 保存，0, 在用 1失效",example = "0")
    private String statusCd = "0";
}
