package com.zeroone.star.project.query.j5.community.renovation;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
 * @className: RenovationQuery
 * @author: powfu
 * @date: 19/5/2025 下午10:34
 * @Version: 1.0
 * @description: 装修查询对象 查询条件如下 共三条
 */
@EqualsAndHashCode(callSuper = true)  //用于自动生成 equals() 和 hashCode() 方法时包含父类的字段
@Data
@ApiModel(value = "装修查询对象")
public class RenovationQuery extends PageQuery {
    @ApiModelProperty(value = "小区id", example = "2023052267100146", required = true)
    @NotBlank(message = "小区id不能为空")
    private String communityId;
    @ApiModelProperty(value = "房屋名称", example = "1-1-1021")
    private String roomName;
    @ApiModelProperty(value = "联系人", example = "朽木玲子")
    private String personName;
    @ApiModelProperty(value = "联系电话", example = "12333333333")
    private String personTel;
    @ApiModelProperty(value = "状态", example = "待审核 审核不通过 装修中 待验收 验收成功 验收失败")  //1000 待审核 2000 审核不通过 3000 装修中 4000 待验收 5000 验收成功 6000 验收失败
    private String state;
    @ApiModelProperty(value = "是否延期", example = "N")  //Y违规 N正常
    private String isPostpone;
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "装修时间", example = "2021-05-17 00:00:00")
    private LocalDateTime renovationTime;
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "装修开始时间", example = "2021-05-17 00:00:00")
    private LocalDateTime startTime;
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "装修结束时间", example = "2021-12-19 23:59:59")
    private LocalDateTime endTime;
    @ApiModelProperty(value = "延期时间", example = "2021-12-19")
    private String postponeTime;
    @ApiModelProperty(value = "违规说明", example = "这是违规说明")
    private String violationDesc;
}
