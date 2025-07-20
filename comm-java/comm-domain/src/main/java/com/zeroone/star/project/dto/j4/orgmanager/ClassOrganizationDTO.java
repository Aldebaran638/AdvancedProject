package com.zeroone.star.project.dto.j4.orgmanager;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import lombok.Data;
/**
 * @Author: dashuai
 * @Description:
 * 组织信息相关接口
 *添加组织
 *
 *
package com.zeroone.star.project.dto.sample;

 */
@Data
public class ClassOrganizationDTO {
    //记录组织
    private int orgId;
    //层级
    private int level;
    //父组织id
    private Integer parentId;
}
//@Data
//@ApiModel("示例传输数据对象")
//public class SampleDTO extends SampleAddDTO {
//    @ApiModelProperty(value = "编号", example = "1d7b0520e93e72715d5d6af1fb7d9a37")
//    @NotBlank(message = "编号不能为空")
//    private String id;
//}