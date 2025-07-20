package com.zeroone.star.project.dto.j4.datamanager;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.io.Serializable;
import java.util.Date;
import java.util.List;

@Data
@ApiModel(value = "物业公司新增和修改的条件")
public class CompanyDTO implements Serializable {

    @NotBlank(message = "公司名称不能为空")
    @ApiModelProperty(value = "公司名称", required = true, example = "坤坤物业")
    private String storeName;

    @NotBlank(message = "地址不能为空")
    @ApiModelProperty(value = "地址", required = true, example = "王者峡谷")
    private String address;

    @NotBlank(message = "联系电话不能为空")
    @ApiModelProperty(value = "联系电话", required = true, example = "111111111")
    private String tel;

    @NotBlank(message = "公司法人不能为空")
    @ApiModelProperty(value = "公司法人", required = true, example = "111111111")
    private String userName;

    @NotBlank(message = "地标不能为空")
    @ApiModelProperty(value = "地标", required = true, example = "狮子头")
    private String nearbyLandmarks;

    @NotNull(message = "成立日期不能为空")
    @ApiModelProperty(value = "成立日期", required = true, example = "2023-01-01")
    @JsonFormat(pattern = "yyyy-MM-dd")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date createDate;

    // 开通小区
    @ApiModelProperty(value = "开通小区标识", example = "YF小区")
    private String openCommunityName;

    // 功能权限
    @ApiModelProperty(value = "功能权限列表", example = "['巡检','OA']")
    private List<String> functions;


}
