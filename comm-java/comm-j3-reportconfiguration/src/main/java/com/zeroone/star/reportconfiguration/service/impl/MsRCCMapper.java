package com.zeroone.star.reportconfiguration.service.impl;

import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDTO;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.RCCVO;
import com.zeroone.star.reportconfiguration.entity.RCCDO;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsRCCMapper {
    /**
     * 实现DO转VO，用来将数据库查询的信息返回给前端
     * @param src
     * @return
     */
    RCCVO DO_VO(RCCDO src);

    /**
     * DTO转DO，用来将前端添加或者修改表中的数据，转化为符合数据库的字段并添加
     * @param src
     * @return
     */
    RCCDO DTO_DO(RCCDTO src);

    /**
     * DTO转DO，用来将前端添加或者修改表中的数据，转化为符合数据库的字段并添加
     * @param src
     * @return
     */
    RCCDO AddDTO_DO(RCCAddDTO src);


}
