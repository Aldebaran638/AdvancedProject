package com.zeroone.star.project.vo.j6.datamanagement.importtemplate;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDate;

/**
 * <p>
 * 模板文件表
 * </p>
 *
 * @author 落
 * @since 2025-05-18
 */
@Data
public class TemplateVO implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 文件md5值
     */
    @ApiModelProperty(value = "文件md5值", example = "1")
    @JsonProperty("id")
    private String id;

    /**
     * 文件名
     */
    @ApiModelProperty(value = "文件名", example = "1")
    @JsonProperty("name")
    private String name;

    /**
     * 文件分组
     */
    @ApiModelProperty(value = "文件分组", example = "1")
    @JsonProperty("group")
    private String group;

    /**
     * 分组路径
     */
    @ApiModelProperty(value = "分组路径", example = "1")
    @JsonProperty("storageId")
    private String storageId;

    /**
     * 文件路径
     */
    @ApiModelProperty(value = "文件路径", example = "1")
    @JsonProperty("path")
    private String path;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "1")
    @JsonProperty("createTime")
    private LocalDate createTime;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间", example = "1")
    @JsonProperty("updateTime")
    private LocalDate updateTime;

}
