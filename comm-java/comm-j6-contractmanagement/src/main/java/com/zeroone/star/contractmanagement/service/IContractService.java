package com.zeroone.star.contractmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.contractmanagement.entity.Contract;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contractmodification.ContractChangePlanDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractPrintDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contractmodification.ContractChangeListQuery;
import com.zeroone.star.project.query.j6.contractmanagement.draftcontract.ContractQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.*;

public interface IContractService extends IService<Contract> {
    ContractDTO getContractById(String id);

    PageDTO<ContractSelectVO> listSelectContract(ContractQuery contractQuery);

    PageDTO<ContractFileVo> getFilesById(ContractQuery condition);

    PageDTO<ContractChangePlanVO> listContractChangePlanById(ContractQuery condition);
    JsonVO<PageDTO<ContractListVO>> listContract(ContractQuery cquery);

    Contract updateyContractChangePlan(ContractChangePlanDTO dto);

    PageDTO<ContractChangeListVO> listContractChanges(ContractChangeListQuery query);


    boolean addContract(ContractDTO contractDTO);

    boolean modifyContract(ContractDTO contractDTO);

    boolean deleteContract(String contractId);

    ContractPrintVO createPrintTask(ContractPrintDTO contractPrintDTO);

    public PageDTO<ContractListVO> listAllExpiredContract(ContractQuery query);

    public boolean updateToEndExpiredContract(String contractId);

    public Boolean modifyToRenewExpiredContract( ContractDTO contractDTO);
}
