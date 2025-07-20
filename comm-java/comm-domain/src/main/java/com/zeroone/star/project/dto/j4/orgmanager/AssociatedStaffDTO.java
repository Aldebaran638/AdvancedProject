package com.zeroone.star.project.dto.j4.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
/**
 * @Author: dashuai
 * @Description:
 * 组织信息相关DTO
 * 关联员工后会出现员工列表
 * 选相应应员工添加时，前端传入List<String>
 * 负责人：Altolia
 */
@Data
@ToString
@Setter
@Getter
public class AssociatedStaffDTO extends PageDTO {
    @ApiModelProperty(value = "名称",example = "维修师傅")
    private String name;

    @ApiModelProperty(value = "手机号",example = "18512341234")
    private String tel;

    @ApiModelProperty(value = "员工编号",example = "302024022077105316")
    private String userId;

}
