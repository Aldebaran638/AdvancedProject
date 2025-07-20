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
public class StaffWorkTime {

    private boolean isBreak;

    private LocalTime morningStartTime;
    private LocalTime morningEndTime;

    private LocalTime eveningStartTime;
    private LocalTime eveningEndTime;
}
