package com.zeroone.star.project.j8.patrolmgt.point.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.io.Serializable;
import java.time.LocalDateTime; // 或者使用 java.util.Date

/**
 * <p>
 * 描述：巡检点数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Susu //
 * @version 1.0.0
 */
@ApiModel("巡检点数据对象")
@Data
public class PointDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @NotBlank(message = "巡检点ID不能为空") // 1. 添加 Bean Validation 注解，表示该字段不能为空白
    @ApiModelProperty(value = "巡检点ID", example = "132025051426620008", required = true) // 2. 设置 required = true
    private String inspectionId; // 对应 inspection_point.inspection_id

    @ApiModelProperty(value = "巡检点名称", example = "库房")
    private String inspectionName; // 对应 inspection_point.inspection_name

    @ApiModelProperty(value = "巡检点类型", example = "环境巡检")
    private String pointType; // 对应 t_dict.name (通过 inspection_point.point_obj_type 关联)

    @ApiModelProperty(value = "巡检位置", example = "111")
    private String pointObjName; // 对应 inspection_point.point_obj_name

    @ApiModelProperty(value = "巡检项目", example = "电饭锅")
    private String itemName; // 对应 inspection_item.item_name (通过 inspection_point.item_id 关联)

    @ApiModelProperty(value = "nfc编码", example = "11")
    private String nfcCode; // 对应 inspection_point.nfc_code

    @ApiModelProperty(value = "备注", example = "bzhu111")
    private String remark; // 对应 inspection_point.remark

    // 如果前端需要展示创建时间、更新时间等信息，可以在 DTO 中添加
    // @ApiModelProperty(value = "创建时间")
    // private LocalDateTime createTime;
    // @ApiModelProperty(value = "更新时间")
    // private LocalDateTime updateTime;

    // 其他可能需要展示的字段可以根据原型图和需求添加
}
