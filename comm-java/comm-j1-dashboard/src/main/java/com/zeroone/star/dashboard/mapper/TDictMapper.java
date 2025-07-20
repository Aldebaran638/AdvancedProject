package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.TDict;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author wunianwufeng
 * @since 2025-05-23
 */
@Mapper
public interface TDictMapper extends BaseMapper<TDict> {

    @Select("select status_cd , name from t_dict where table_name = #{tableName} and table_columns = #{tableColumns}")
    List<TDict> selectByTableNameAndColumn(@Param("tableName") String tableName, @Param("tableColumns") String column);


}
