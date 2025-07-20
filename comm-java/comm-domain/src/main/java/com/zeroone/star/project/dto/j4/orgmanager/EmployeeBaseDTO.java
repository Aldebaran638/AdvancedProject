package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

@ApiModel("员工基础类")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class EmployeeBaseDTO {
    /**
     * 名称
     */
    @ApiModelProperty(value = "名称", example = "小艺哥", required = true)
    private String name;

    /**
     * 岗位
     */
    @ApiModelProperty(value = "岗位", example = "总公司总经理", required = true)
    private String job;

    /**
     * 邮箱
     */
    @ApiModelProperty(value = "邮箱", example = "jack.king@jdai.com")
    private String email;

    /**
     * 电话
     */
    @ApiModelProperty(value = "电话", example = "13639399343", required = true)
    private String tel;

    /**
     * 性别
     */
    @ApiModelProperty(value = "性别", example = "男", required = true)
    private String sex;

    /**
     * 地址
     */
    @ApiModelProperty(value = "地址", example = "甘南路", required = true)
    private String address;

    /**
     * 头像
     */
    @ApiModelProperty(value = "头像", example = "")
    private MultipartFile picture;
}
