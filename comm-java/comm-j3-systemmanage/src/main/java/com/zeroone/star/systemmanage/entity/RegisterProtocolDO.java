package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
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
@TableName("register_protocol")
public class RegisterProtocolDO implements Serializable {
    @ApiModelProperty(value = "商家注册协议",example = "注册协议条款的确认和接受...")
    private String merchantProtocol;
    @ApiModelProperty(value = "用户注册协议",example = "注册协议条款的确认和接受...")
    private String userProtocol;
    @ApiModelProperty(value = "协议ID",example = "1")
    @TableId
    private String protolcolId;
    @ApiModelProperty(value = "创建时间",example = "2023-01-10 16:44:22")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date createTime;
    @ApiModelProperty(value = "数据状态，详细参考c_status表，S 保存，0, 在用 1失效",example = "0")
    private String statusCd = "0";
}
