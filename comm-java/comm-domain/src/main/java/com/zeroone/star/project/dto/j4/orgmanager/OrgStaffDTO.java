package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Data
@Setter
@Getter
@ToString
@ApiModel("组织员工列表模型")
public class OrgStaffDTO {

    @ApiModelProperty(value = "名称",example = "阿姨")
    private String name;

    @ApiModelProperty(value = "手机号",example = "18900110011")
    private String tel;

    @ApiModelProperty(value = "岗位",example = "部门组长")
    private String jobName;

    @ApiModelProperty(value = "邮箱",example = "45335433355@qq.com")
    private String email;

    @ApiModelProperty(value = "地址",example = "中国")
    private String address;

    @ApiModelProperty(value = "性别",example = "女")
    private String sex;
}
