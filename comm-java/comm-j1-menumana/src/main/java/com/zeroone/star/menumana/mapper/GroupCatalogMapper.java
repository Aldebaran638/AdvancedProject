package com.zeroone.star.menumana.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.menumana.entity.GroupCatalog;
import org.apache.ibatis.annotations.*;

@Mapper
public interface GroupCatalogMapper extends BaseMapper<GroupCatalog> {
    @Select(
            "SELECT CASE WHEN EXISTS (" +
                    "   SELECT 1 FROM m_menu_group_catalog " +
                    "   WHERE g_id = #{gId} " +
                    "     AND store_type = #{storeType} " +
                    "     AND ca_id = #{caId} " +
                    ") THEN 1 ELSE 0 END"
    )
    boolean existsByGIdStoreTypeCaId(
            @Param("gId") String gId,
            @Param("storeType") String storeType,
            @Param("caId") String caId
    );
}
