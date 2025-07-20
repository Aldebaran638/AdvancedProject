package com.zeroone.star.reportconfiguration.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.zeroone.star.project.dto.j3.reportconfiguration.group.GroupDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import org.springframework.boot.context.properties.ConstructorBinding;

import java.io.Serializable;
@Getter
@Setter
@TableName("report_custom_group")
public class ReportGroupDO implements Serializable {
    public ReportGroupDO() {
    }

    @ApiModelProperty(value = "组ID",example = "102021111007300001")
    @TableId
    private String groupId;

    @ApiModelProperty(value = "组名称",example = "报修报表")
    private String name;

    @ApiModelProperty(value = "组url",example = "/#/pages/property/custom.html")
    private String url;

    @ApiModelProperty(value = "描述",example = "报修报表1")
    private String remark;

//    @TableField(fill = FieldFill.INSERT)
    @ApiModelProperty(value = "创表时间",example = "2021-11-10 00:52:57")
    private String createTime;

    /**
     * 数据状态
     * 详细参考c_status表，S 保存，0, 在用 1失效
     */
    @ApiModelProperty(value = "数据状态",example = "0")
    private String statusCd;

    public ReportGroupDO(GroupDTO dto){
        this.groupId=dto.getGroupId();
        this.name=dto.getName();
        this.url=dto.getUrl();
        this.remark=dto.getRemark();
    }


}
