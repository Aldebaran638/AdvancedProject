package com.zeroone.star.project.dto.j7.parkmanage.ownervehicle;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：业主车辆-续租车位 使用的 DTO
 * </p>
 * @author 申健健
 * @version 1.0.0
 */
@ApiModel("业主车辆-续租车位使用的DTO")
@Data
public class RenewParkingSpaceLeaseDTO {
    @ApiModelProperty(value = "车辆ID", example = "102024022034585148", required = true)
    private String carId;
    @ApiModelProperty(value = "车位ID", example = "792024021869862263", required = true)
    private String psId;
    @ApiModelProperty(value = "起租时间", example = "2025-01-01 00:00:00",required = true)
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime startTime;
    @ApiModelProperty(value = "结租时间", example = "2025-02-01 00:00:00",required = true)
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime endTime;
    @ApiModelProperty(value = "备注", example = "备注信息")
    private String remark;
}
