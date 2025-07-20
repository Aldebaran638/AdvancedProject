package com.zeroone.star.menumana.entity;

import com.baomidou.mybatisplus.annotation.*;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@ApiModel(value = "菜单目录")
@Data
@TableName("m_menu_catalog")
public class MenuCatalog implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 编号
     */
    @TableId(value = "ca_id", type = IdType.ASSIGN_ID)
    private String caId;
    /**
     * 组名称
     */
    private String name;
    /**
     * 图标
     */
    private String icon;
    /**
     * 顺序
     */
    private Integer seq;
    /**
     * 商户类型编号
     */
    private String storeType;
    /**
     * 页面
     */
    private String url;
    /**
     * 是否显示
     */
    private String isShow;
    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    /**
     * 状态
     */
    @ApiModelProperty(value = "状态",example = "0")
    private Integer statusCd;
    /**
     *权限编号
     */
    @ApiModelProperty(value = "权限编号",example = "502020101335250026")
    private String privId;
}