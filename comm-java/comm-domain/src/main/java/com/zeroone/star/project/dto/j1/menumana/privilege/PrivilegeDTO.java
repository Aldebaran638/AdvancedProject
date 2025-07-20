package com.zeroone.star.project.dto.j1.menumana.privilege;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.Pattern;
import java.time.LocalDateTime;

/**
 * \* @author cv
 * \* Time: 2025/5/20 + 13:40
 * \* Description:
 * \
 */
@Getter
@Setter
@ApiModel("权限传输数据对象")
public class PrivilegeDTO extends PrivilegeAddDTO {
    @ApiModelProperty(value="权限ID",example = "1fse51sdv684vd4rg1s3fe5",required = true)
    private String pid;
    @ApiModelProperty(value="创建时间",example = "2019-04-19 16:01:21")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;
}
