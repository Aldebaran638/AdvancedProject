package com.zeroone.star.contractmanagement.mapper;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.toolkit.Constants;
import com.zeroone.star.contractmanagement.entity.Contract;
import com.zeroone.star.project.query.j6.contractmanagement.draftcontract.ContractQuery;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractChangePlanVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractFileVo;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractListVO;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface ContractMapper extends BaseMapper<Contract> {

    @Select("SELECT * FROM contract_change_plan p INNER JOIN contract_change_plan_detail d ON p.plan_id = d.plan_id WHERE d.contract_id = #{contractId} ORDER BY p.create_time DESC LIMIT #{pageIndex}, #{pageSize}")
    List<ContractChangePlanVO> selectContractChangePlansById(ContractQuery condition);

    @Select("SELECT contract_id,contract_file_id,create_time,file_real_name,file_save_name,status_cd from contract_file where contract_id = #{contractId} and status_cd = 0 ORDER BY create_time DESC LIMIT #{pageIndex}, #{pageSize}")
    List<ContractFileVo> selectFilesById(ContractQuery condition);

    @Select("SELECT c.*, ct.type_name AS contractTypeName, ct.audit, cf.file_real_name, cf.file_save_name " +
            "FROM contract c " +
            "LEFT JOIN contract_type ct ON c.contract_type = ct.contract_type_id " +
            "LEFT JOIN contract_file cf ON cf.contract_id = c.contract_id " +
            "${ew.customSqlSegment}")
    List<ContractListVO> selectContractInfo(@Param(Constants.WRAPPER) Wrapper<Contract> wrapper);

    @Delete("delete  from contract where contract_id=#{contractId}")
    int deleteId(String contractId);
}
