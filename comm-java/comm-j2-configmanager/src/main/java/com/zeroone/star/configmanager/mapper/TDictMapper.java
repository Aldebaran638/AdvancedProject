package com.zeroone.star.configmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;

import com.zeroone.star.configmanager.entity.TDict;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.AddTDictDTO;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.AddTDictResDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;
@Mapper
public interface TDictMapper extends BaseMapper<TDict> {
    List<AddTDictDTO> selectWithSpecName(
            @Param("spec_id") String specId,
            @Param("name") String name,
            @Param("status_cd") String statusCd);

    List<AddTDictResDTO> selectWithSpecId(
            @Param("spec_id") String specId,
            @Param("name") String name,
            @Param("status_cd") String statusCd);


    Integer selectMaxId();
}

