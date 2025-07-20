package com.zeroone.star.patrolmgt.service.impl;

import com.zeroone.star.patrolmgt.entity.InspectionTaskDetail;
import com.zeroone.star.project.j8.patrolmgt.detail.dto.DetailDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;
import org.mapstruct.Named;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.Date;

@Mapper(componentModel = "spring")
public interface MsDetailMapper {

    @Named("stringToDate")
    default Date stringToDate(String dateStr) {
        if (dateStr == null) return null;
        try {
            return new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").parse(dateStr);
        } catch (ParseException e) {
            throw new RuntimeException("日期格式错误：" + dateStr, e);
        }
    }

    @Named("localDateTimeToDate")
    default Date localDateTimeToDate(LocalDateTime time) {
        return time == null ? null : Date.from(time.atZone(ZoneId.systemDefault()).toInstant());
    }

    /**
     * 巡检明细实体类转DTO
     *
     * @param inspectionTaskDetail 巡检明细实体类
     * @return 巡检明细DTO
     */
    @Mappings({
            @Mapping(source = "pointStartTime", target = "pointStartTime", qualifiedByName = "stringToDate"),
            @Mapping(source = "pointEndTime", target = "pointEndTime", qualifiedByName = "stringToDate"),
            @Mapping(source = "createTime", target = "createTime", qualifiedByName = "localDateTimeToDate"),
    })
    DetailDTO detailToDto(InspectionTaskDetail inspectionTaskDetail);

    /**
     * 巡检明细DTO转实体类
     *
     * @param detailDTO 巡检明细DTO
     * @return 巡检明细实体类
     */
    InspectionTaskDetail dtoToDetail(DetailDTO detailDTO);
}
