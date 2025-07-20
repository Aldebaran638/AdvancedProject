package com.zeroone.star.contractmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.contractmanagement.entity.ContractPartya;
import com.zeroone.star.project.dto.PageDTO;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j6.contractmanagement.contractpartya.ContractPartyaAddDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contractpartya.ContractPartyaQuery;
import com.zeroone.star.project.vo.j6.contractmanagement.contractpartya.ContractPartyaVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author denghuo
 * @since 2025-05-25
 */
public interface IContractPartyaService extends IService<ContractPartya> {

    /**
     * @param conditions
     * @return
     */
    PageDTO<ContractPartyaVO> getContractPartyaPageByConditions(ContractPartyaQuery conditions) throws Exception;

    /**
     * @return
     */
    List<ContractPartyaVO> getContractPartyaList() throws Exception;

    /**
     *
     * @param addDTO
     * @return
     */
    Boolean addContractPartya(ContractPartyaAddDTO addDTO);


    public boolean modifyContractPartya(ContractPartyaAddDTO contractpartyaaddDTO);

    public String deleteContractPartya(ContractPartyaAddDTO contractpartyaaddDTO);
}
