package com.zeroone.star.contractmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.contractmanagement.entity.ContractFile;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface ContractFileMapper extends BaseMapper<ContractFile> {
    @Select({
            "<script>",
            "SELECT contract_id, file_real_name, file_save_name FROM contract_file",
            "WHERE contract_id IN",
            "<foreach collection='contractIds' item='id' open='(' separator=',' close=')'>",
            "#{id}",
            "</foreach>",
            "</script>"
    })
    List<ContractFile> selectFilesByContractIds(@Param("contractIds") List<String> contractIds);
}