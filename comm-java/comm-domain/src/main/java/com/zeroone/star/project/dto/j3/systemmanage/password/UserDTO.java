package com.zeroone.star.project.dto.j3.systemmanage.password;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotNull;
import java.io.Serializable;

@Getter
@Setter
@ToString
@ApiModel("修改密码数据对象")
public class UserDTO implements Serializable {

    @ApiModelProperty(value = "用户ID", example = "U123456",required = true)
    private String userId;

    @ApiModelProperty(value = "旧密码", example = "123456",required = true)
    @NotNull
    private String oldPwd;

    @ApiModelProperty(value = "新密码" , example = "121234",required = true)
    @NotNull
    private String newPwd;
}
