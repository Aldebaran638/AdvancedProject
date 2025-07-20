package com.zeroone.star.project.j6.contractmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.expiredcontract.ExpiredContractDTO;
import com.zeroone.star.project.query.j6.contractmanagement.draftcontract.ContractQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractListVO;

/*
 *描述 ：到期合同接口
 *Author:28768
 */
public interface ExpiredContractApis {

    /**
     * 获取到期合同列表（条件+分页）
     *
     * @param query
     * @return
     */
    JsonVO<PageDTO<ContractListVO>> queryAllExpiredContracts(ContractQuery query);

    /**
     * 续签合同
     *
     * @param contractDTO
     * @return
     */
    public JsonVO<Boolean> modifyToRenewExpiredContract(ContractDTO contractDTO);

    /**
     * 终止合同
     *
     * @param contractId
     * @return
     */
    JsonVO<Boolean> modifyToEndExpiredContract(String contractId);



}
