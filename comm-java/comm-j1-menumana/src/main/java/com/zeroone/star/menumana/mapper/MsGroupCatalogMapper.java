package com.zeroone.star.menumana.mapper;

import com.zeroone.star.menumana.entity.GroupCatalog;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogAddDTO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogAddVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogQueryVO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;
import org.mapstruct.factory.Mappers;

@Mapper(componentModel = "spring")
public interface MsGroupCatalogMapper {
    /**
     * 单例访问方式
     */
    MsGroupCatalogMapper INSTANCE = Mappers.getMapper(MsGroupCatalogMapper.class);
    /**
     * addDTO -> DO
     */
    @Mappings({
            @Mapping(target = "gcId", ignore = true),
            @Mapping(target = "statusCd", ignore = true),
            @Mapping(target = "createTime", ignore = true)
    })
    GroupCatalog addDTO2DO(GroupCatalogAddDTO groupCatalogAddDTO);
    /**
     * DO -> addVO
     */
    @Mappings({
            @Mapping(source = "gcId",target = "gcId"),
            @Mapping(source = "createTime",target = "createTime")
    })
    GroupCatalogAddVO DO2addVO(GroupCatalog groupCatalog);
    /**
     * DO -> queryVO
     */
    @Mappings({
            @Mapping(source = "gcId",target = "gcId"),
            @Mapping(source = "gid",target = "gid")
    })
    GroupCatalogQueryVO DO2queryVO(GroupCatalog groupCatalog);
}
