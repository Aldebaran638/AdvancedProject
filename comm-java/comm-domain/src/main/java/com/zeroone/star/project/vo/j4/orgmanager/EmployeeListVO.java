package com.zeroone.star.project.vo.j4.orgmanager;

import com.baomidou.mybatisplus.annotation.EnumValue;
import com.fasterxml.jackson.annotation.JsonValue;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("员工列表类")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class EmployeeListVO {

    /**
     * 员工编号
     */
    @ApiModelProperty(value = "员工编号", example = "302024022434513355")
    private String userID;

    /**
     * 名称"
     */
    @ApiModelProperty(value = "名称", example = "贾诩")
    private String name;

    /**
     * 手机号
     */
    @ApiModelProperty(value = "手机号", example = "1311101111")
    private String tel;

    /**
     * 关联组织
     */
    @ApiModelProperty(value = "关联组织", example = "三国物业")
    private String orgName;

    /**
     * 岗位
     */
    @ApiModelProperty(value = "岗位", example = "总公司副总经理")
    private String postName;

    /**
     * 邮箱
     */
    @ApiModelProperty(value = "邮箱", example = "1962492080@qq.com")
    private String email;

    /**
     * 地址
     */
    @ApiModelProperty(value = "地址", example = "上海")
    private String address;

    /**
     * 性别
     */
    @ApiModelProperty(value = "性别", example = "1") //1是男 ,0是女
    private String sex;

}
