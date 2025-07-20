package com.zeroone.star.project.dto.j4.datamanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 请求重置物业密码
 * </p>
 *
 * @author 叶落孤城
 * @since 2023-05-23
 */
@ApiModel("请求重置物业密码")
@Data
public class RequstPasswordCompanyDTO {
    @ApiModelProperty(value = "物业公司id", example = "10202305221014333605000192")
    private String communityId;
    @ApiModelProperty(value = "员工id", example = "10202305221014333605000192")
    private String staffId;
}
