package com.zeroone.star.project.vo.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 描述：员工基础信息类
 * </p>
 * @author heavydrink
 * @version 1.0.0
 */
@ApiModel("员工基础信息类")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class EmployeeBaseInfoVO {
    /**
     * 编号
     */
    @ApiModelProperty(value = "编号", example = "302024022434513355")
    private String userId;
    /**
     * 名称
     */
    @ApiModelProperty(value = "姓名", example = "小艺哥")
    private String name;
    /**
     * 邮箱
     */
    @ApiModelProperty(value = "邮箱", example = "jack.king@jdai.com")
    private String email;
    /**
     * 手机号
     */
    @ApiModelProperty(value = "手机号", example = "13639399343")
    private String tel;
    /**
     * 性别
     */
    @ApiModelProperty(value = "性别", example = "男")
    private String sex;
    /**
     * 住址
     */
    @ApiModelProperty(value = "住址", example = "甘南路")
    private String address;
    /**
     * 头像
     */
    @ApiModelProperty(value = "头像", example = "")
    private String picture;
}
