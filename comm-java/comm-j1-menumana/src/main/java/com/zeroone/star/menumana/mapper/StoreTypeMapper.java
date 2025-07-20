package com.zeroone.star.menumana.mapper;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.menumana.entity.StoreType;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * \* @author cv
 * \* Time: 2025/5/29 + 0:00
 * \* Description:用于映射domain和商家名称
 * \
 */

@Mapper
@TableName("store_type")
public interface StoreTypeMapper extends BaseMapper<StoreType> {

    @Select("select store_type_cd from store_type where name = #{storeTypeName}")
    String getStoreTypeCdByName(String storeTypeName);
}
