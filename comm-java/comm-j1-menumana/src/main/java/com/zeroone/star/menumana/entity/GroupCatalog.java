package com.zeroone.star.menumana.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@ApiModel(value = "菜单组目录实体")
@Data
@TableName("m_menu_group_catalog")
public class GroupCatalog {
    /**
     * 菜单组目录编号
     */
    @TableId
    @ApiModelProperty(value = "菜单组目录编号",example = "102022022662880029")
    private String gcId;
    /**
     * 菜单目录编号
     */
    @ApiModelProperty(value = "菜单目录编号",example = "102022022695140008")
    private String caId;
    /**
     * 菜单组编号
     */
    @TableField("g_id")
    @ApiModelProperty(value = "菜单组编号",example = "802021031653410070")
    private String gid;
    /**
     * 商户类型
     */
    @ApiModelProperty(value = "商户类型",example = "800900000000")
    private String storeType;
    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间",example = "2022-07-28 21:31:15")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;
    /**
     * 状态码
     */
    @ApiModelProperty(value = "状态码",example = "0")
    private Integer statusCd;
}