package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 描述：修改员工类
 * </p>
 * @author heavydrink
 * @version 1.0.0
 */
@ApiModel("修改员工类")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class ModifyEmployeeDTO extends EmployeeBaseDTO {
    /**
     * userId
     */
    @ApiModelProperty(value = "userId", example = "302024022434513355", required = true)
    private String userId;

}
