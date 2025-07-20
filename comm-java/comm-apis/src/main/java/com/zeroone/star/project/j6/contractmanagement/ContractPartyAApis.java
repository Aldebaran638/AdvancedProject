package com.zeroone.star.project.j6.contractmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contractpartya.ContractPartyaAddDTO;
import com.zeroone.star.project.vo.j6.contractmanagement.contractpartya.ContractPartyaVO;
import com.zeroone.star.project.query.j6.contractmanagement.contractpartya.ContractPartyaQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/*
 *描述 ：合同甲方接口
 *Author:28768
 */
public interface ContractPartyAApis {

    /**
     * 获取合同甲方列表（条件+分页）
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<ContractPartyaVO>> queryAll(ContractPartyaQuery condition) throws Exception;

    /**
     * 获取合同甲方列表
     * @return 查询结果
     */
    JsonVO<List<ContractPartyaVO>> listQuery() throws Exception;

    /**
     * 新增合同甲方
     *
     * @param addDto 新增数据
     * @return 新增结果
     */
    JsonVO<Boolean> addContractPartya(ContractPartyaAddDTO addDto) throws Exception;


    /**
     * 修改合同甲方
     *
     * @param contractPartyDTO 修改的数据
     * @return 修改结果
     */
    JsonVO<Boolean> updateContractPartyDTO(ContractPartyaAddDTO contractPartyDTO);
    /**
     * 删除合同甲方
     *
     * @param contractPartyDTO
     * @return 删除结果
     */
    JsonVO<Boolean> deleteContractPartyDTO(ContractPartyaAddDTO contractPartyDTO);

}
