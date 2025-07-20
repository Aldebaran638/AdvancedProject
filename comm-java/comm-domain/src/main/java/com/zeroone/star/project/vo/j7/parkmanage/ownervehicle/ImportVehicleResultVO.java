package com.zeroone.star.project.vo.j7.parkmanage.ownervehicle;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.io.Serializable;
import java.util.List;

@ApiModel("导入车辆结果视图对象")
@Data
public class ImportVehicleResultVO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "总处理条数", example = "100")
    private Integer totalCount;

    @ApiModelProperty(value = "成功导入条数", example = "95")
    private Integer successCount;

    @ApiModelProperty(value = "失败条数", example = "5")
    private Integer failureCount;

    @ApiModelProperty(value = "失败详情列表")
    private List<ImportFailureDetail> failureDetails;

    @ApiModel("导入失败详情")
    @Data
    public static class ImportFailureDetail implements Serializable {
        private static final long serialVersionUID = 1L;

        @ApiModelProperty(value = "行号 (从1开始)", example = "3")
        private Integer rowNum;

        @ApiModelProperty(value = "错误信息", example = "车牌号格式不正确")
        private String errorMessage;

        // 可以根据需要添加更多详情，例如具体字段名等
    }
} 