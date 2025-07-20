package com.zeroone.star.project.vo.j1.menumana.menudir;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@ApiModel(value = "删除对应菜单组响应参数")
@Data
public class GroupCatalogDelVO {
    /**
     * 菜单组目录编号
     */
    @ApiModelProperty(value = "菜单组目录编号",example = "102022022662880029")
    private String gcId;
}
