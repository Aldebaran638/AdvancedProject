package com.zeroone.star.contractmanagement.controller;

import com.zeroone.star.contractmanagement.entity.Contract;
import com.zeroone.star.contractmanagement.service.IContractChangePlanDetailService;
import com.zeroone.star.contractmanagement.service.IContractService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contractmodification.ContractChangePlanDTO;
import com.zeroone.star.project.j6.contractmanagement.ContractModificationApis;
import com.zeroone.star.project.query.j6.contractmanagement.contractmodification.ContractChangeListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractChangeDetailVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractChangeListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

/*
 *描述 ：合同变更的代码实现
 *Author:28768
 */
@RestController
@RequestMapping("/j6-contract/change")
@Api(tags = "合同变更")
public class ContractModificationController implements ContractModificationApis {
    @Resource
    private IContractService contractService;

    @Resource
    private IContractChangePlanDetailService contractChangePlanDetailService;
    @ApiOperation("获取合同变更列表（条件+分页）")
    @GetMapping("/get-contract-change")
    @Override
    public JsonVO<PageDTO<ContractChangeListVO>> listContractChanges(ContractChangeListQuery query) {
        PageDTO<ContractChangeListVO>  contractPrintVOPageDTO=contractService.listContractChanges(query);
        return JsonVO.success(contractPrintVOPageDTO);
    }

    @GetMapping("/get-change-detail")
    @ApiOperation("查看变更明细")
    @Override
    public JsonVO<List<ContractChangeDetailVO>> listChangeDetails(String planId) {
        return contractChangePlanDetailService.listChangeDetails(planId);
    }

    @PutMapping("/modify-asset-change")
    @ApiOperation("主体变更--租期调整--资产变更")
    @Override
    public JsonVO<Boolean> modifyContractChangePlan(@RequestBody @Valid ContractChangePlanDTO dto)   {
        Contract contract = contractService.updateyContractChangePlan(dto);
        if (contract != null) {
            return JsonVO.success(true  );
        }
        return JsonVO.fail(false);
    }
}
