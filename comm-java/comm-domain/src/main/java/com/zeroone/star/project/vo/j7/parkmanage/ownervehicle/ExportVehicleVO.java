package com.zeroone.star.project.vo.j7.parkmanage.ownervehicle;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
@ApiModel("车辆导出视图对象")
public class ExportVehicleVO implements Serializable {
    
    private static final long serialVersionUID = 1L;

    @ExcelProperty("车牌号")
    @ApiModelProperty(value = "车牌号", example = "AW2222")
    private String carNumber;
    
    @ExcelProperty("成员车辆")
    @ApiModelProperty(value = "成员车辆", example = "是/否")
    private String memberVehicle;
    
    @ExcelProperty("房屋号")
    @ApiModelProperty(value = "房屋号", example = "1号楼-101")
    private String room;
    
    @ExcelProperty("车辆品牌")
    @ApiModelProperty(value = "车辆品牌", example = "保时捷")
    private String carBrand;
    
    @ExcelProperty("车辆类型")
    @ApiModelProperty(value = "车辆类型", example = "家用小汽车")
    private String carTypeName;
    
    @ExcelProperty("颜色")
    @ApiModelProperty(value = "车辆颜色", example = "黄黑色")
    private String carColor;
    
    @ExcelProperty("业主")
    @ApiModelProperty(value = "业主姓名(电话)", example = "张三(19168091922)")
    private String ownerInfo; // 合并业主姓名和电话
    
    @ExcelProperty("车位")
    @ApiModelProperty(value = "车位区域-编号", example = "1号-A100")
    private String parkingSpaceInfo; // 合并车位区域和编号
    
    @ExcelProperty("有效期")
    @ApiModelProperty(value = "有效期开始时间--结束时间", example = "2025-05-15 00:00:00--2050-01-01 00:00:00")
    private String validityPeriod; // 合并开始时间和结束时间
    
    @ExcelProperty("状态")
    @ApiModelProperty(value = "车辆状态", example = "正常")
    private String status;
    
    @ExcelProperty("备注")
    @ApiModelProperty(value = "备注", example = "www1241")
    private String remark;
} 