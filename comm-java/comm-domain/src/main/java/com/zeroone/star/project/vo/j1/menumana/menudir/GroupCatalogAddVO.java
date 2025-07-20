package com.zeroone.star.project.vo.j1.menumana.menudir;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@ApiModel(value = "添加对应菜单组响应参数")
@Data
public class GroupCatalogAddVO {
    /**
     * 菜单组目录编号
     */
    @ApiModelProperty(value = "菜单组目录编号",example = "102022022662880029")
    private String gcId;
    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间",example = "2022-07-28 21:31:15")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;
}
