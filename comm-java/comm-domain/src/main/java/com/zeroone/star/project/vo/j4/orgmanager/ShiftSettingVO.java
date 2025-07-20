package com.zeroone.star.project.vo.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.sql.Timestamp;
import java.io.Serializable;
import java.util.List;

/**
 * @Author:zzw3867
 *
 */
@ApiModel("班次列表显示对象")
@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
public class ShiftSettingVO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "班次编号", example = "102025051399570080")
    private String classesId;
    @ApiModelProperty(value = "班次名称", example = "早班1")
    private String name;
    @ApiModelProperty(value = "工作时间段", example = "[\"4:30~11:30\"]")
    private List<String> workTime;
    @ApiModelProperty(value = "状态", example = "启用(1001)")
    private String state;
    @ApiModelProperty(value = "创建时间", example = "2025-05-11 22:10:24")
    private Timestamp createTime;
    @ApiModelProperty(value = "备注说明", example = "早班加点油")
    private String remark;
}
