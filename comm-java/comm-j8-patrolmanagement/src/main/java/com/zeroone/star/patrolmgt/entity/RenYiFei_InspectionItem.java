package com.zeroone.star.patrolmgt.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableLogic;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 巡检项目DO
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("巡检项目DO")
@TableName("inspection_item")
public class RenYiFei_InspectionItem {

    @ApiModelProperty(value="主键ID",example="102022050608420018")
    @TableId(value="item_id",type=IdType.ASSIGN_ID)
    private String itemId;

    @ApiModelProperty(value="巡检项目名称",example="水电费")
    private String itemName;

    @ApiModelProperty(value="小区ID",example="2022022584520644")
    private String communityId;

    @ApiModelProperty(value="备注",example="水电费")
    private String remark;

    @ApiModelProperty(value="创建时间（数据库默认当前时间）",example="2022-05-06 14:25:31")
    private LocalDateTime createTime;

    @ApiModelProperty(value="数据状态（默认0，对应c_status表，0在用）",example="0")
    @TableLogic(value="0",delval="1")
    private String statusCd;
}
