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
 * 巡检点DO模型
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("巡检点DO模型")
@TableName("inspection_point")
public class RenYiFei_InspectionPoint {

    @ApiModelProperty(value="ID",example="132024021643360702")
    @TableId(value="inspection_id",type= IdType.ASSIGN_ID)
    private String inspectionId;

    @ApiModelProperty(value="业务ID",example="-1")
    private String bId;

    @ApiModelProperty(value="巡检名称",example="1号巡检点")
    private String inspectionName;

    @ApiModelProperty(value="小区ID",example="2023052267100146")
    private String communityId;

    @ApiModelProperty(value="备注",example="")
    private String remark;

    @ApiModelProperty(value="创建时间",example="2024-02-16 16:20:30")
    private LocalDateTime createTime;

    @TableLogic(value="0",delval="1")
    @ApiModelProperty(value="数据状态",example="0")
    private String statusCd;

    @ApiModelProperty(value="环境巡检",example="2002")
    private String pointObjType;

    @ApiModelProperty(value="对象ID",example="-1")
    private String pointObjId;

    @ApiModelProperty(value="对象名称",example="NB物联网水表(123456789)")
    private String pointObjName;

    @ApiModelProperty(value="巡检项目",example="102024021947622731")
    private String itemId;

    @ApiModelProperty(value="nfc编码",example="")
    private String nfcCode;

}
