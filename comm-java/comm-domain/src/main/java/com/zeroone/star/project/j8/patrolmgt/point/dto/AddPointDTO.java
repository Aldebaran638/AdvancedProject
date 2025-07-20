package com.zeroone.star.project.j8.patrolmgt.point.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 添加巡检点模型类
 */
@ApiModel("添加巡检点模型类")
@Data
public class AddPointDTO {
    @ApiModelProperty(value="巡检点名称",example="1",required=true)
    private String inspectionName;
    @ApiModelProperty(value="巡检类型",example="2002",required=true)
    private String pointObjType;
    @ApiModelProperty(value="位置(只有在巡检类型选择了环境巡检才会出现这个框；因为巡检类型不考虑巡检设备)",example="1",required=true)
    private String pointObjName;
    @ApiModelProperty(value="巡检项目",example="102024022168537630",required=true)
    private String itemId;
    @ApiModelProperty(value="nfc编码",example="")
    private String nfcCode;
    @ApiModelProperty(value="备注",example="")
    private String remark;
    @ApiModelProperty(value="小区ID(隐藏条件)",example="2024012252790005",required=true,notes = "该字段前端无需展示输入框,但是需要传递给后端")
    private String communityId;
    @ApiModelProperty(value="对象id(隐藏条件)",example="-1",required=true,notes = "该字段前端无需展示输入框,但是需要传递给后端")
    private String pointObjId;
}
