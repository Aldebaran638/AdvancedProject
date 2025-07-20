package com.zeroone.star.contractmanagement.controller;

import com.zeroone.star.contractmanagement.service.IContractService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.expiredcontract.ExpiredContractDTO;
import com.zeroone.star.project.j6.contractmanagement.ExpiredContractApis;
import com.zeroone.star.project.query.j6.contractmanagement.draftcontract.ContractQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/*
 *描述 ：到期合同的代码实现
 *Author:28768
 */
@RestController
@RequestMapping("/j6-contract/expire")
@Api(tags = "到期合同")
public class ExpiredContractController implements ExpiredContractApis {


    @Resource
    private IContractService contractService;

    @GetMapping("/query-expired-contract")
    @ApiOperation("获取到期合同列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<ContractListVO>> queryAllExpiredContracts(ContractQuery query) {
        PageDTO<ContractListVO> expiredContractDTOPageDTO = contractService.listAllExpiredContract(query);
        return JsonVO.success(expiredContractDTOPageDTO);
    }

    @PostMapping("/modify-to-renew-expired-contract")
    @ApiOperation("续签合同")
    @Override
    public JsonVO<Boolean> modifyToRenewExpiredContract(@RequestBody ContractDTO contractDTO) {
        boolean b = contractService.modifyToRenewExpiredContract(contractDTO);
        if(b){
            return JsonVO.success(b);
        }
        return JsonVO.fail(b);
    }

    @PutMapping("/modify-to-end-expired-contract")
    @ApiOperation("终止合同")
    @Override
    public JsonVO<Boolean> modifyToEndExpiredContract(String contractId) {
        if(contractService.updateToEndExpiredContract(contractId)){
            return JsonVO.success(true);
        }
        return JsonVO.fail(false);
    }
}
