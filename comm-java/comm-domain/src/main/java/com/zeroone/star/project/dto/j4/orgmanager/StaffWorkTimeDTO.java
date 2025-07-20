package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalTime;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("")
public class StaffWorkTimeDTO {

    /**
     * 是否休息
     */
    private boolean isBreak;

    /**
     * 上午工作时间
     */
    private LocalTime morningStartTime;
    private LocalTime morningEndTime;

    /**
     * 下午工作时间
     */
    private LocalTime eveningStartTime;
    private LocalTime eveningEndTime;

    public StaffWorkTimeDTO(boolean b) {
        this.isBreak = b;
    }
}
