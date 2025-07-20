package com.zeroone.star.project.vo.j4.datamanager;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.util.Date;


@Data
@ApiModel(value = "物业公司查询返回结果")
public class CompanyVO implements Serializable {

    @ApiModelProperty(value = "编号", example = "111111111111111")
    private String storeId;

    @ApiModelProperty(value = "名称", example = "坤坤物业")
    private String storeName;

    @ApiModelProperty(value = "地址", example = "王者峡谷")
    private String address;

    @ApiModelProperty(value = "管理员", example = "331331313")
    private String administrator;

    @ApiModelProperty(value = "电话", example = "331331313")
    private String tel;

    @ApiModelProperty(value = "公司法人", example = "坤坤人")
    private String userName;

    @ApiModelProperty(value = "成立日期", example = "2023-01-01")
    @JsonFormat(pattern = "yyyy-MM-dd")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date createDate;

    @ApiModelProperty(value = "地标", example = "坤坤广场")
    private String nearbyLandmarks;

    @ApiModelProperty(value = "创建时间", example = "2023-01-01 11:27:32")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private Date createTime;

}
