package com.zeroone.star.configmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.configmanager.entity.TDictSpec;
import org.apache.ibatis.annotations.Mapper;


import java.util.List;
@Mapper
public interface TDictSpecMapper extends BaseMapper<TDictSpec> {
    // 查询所有t_dict_spec表中的table_name
    List<String> selectAllTableNames();

    // 判断t_dict_spec表中某个table_name是否存在
    boolean existsByTableName(String tableName);

    //根据spec_name查询t_dict_spec表中的对应字段
    TDictSpec selectBySpecName(String specName);

    //根据spec_id查询t_dict_spec表中的对应字段
    TDictSpec selectBySpecId(String specId);
    //获取t_dict_spec表内的所有spec_name
    List<String> getAllSpecNames();

    //获取t_dict_spec表内的所有spec_Id
    List<String> getAllSpecIds();
}
