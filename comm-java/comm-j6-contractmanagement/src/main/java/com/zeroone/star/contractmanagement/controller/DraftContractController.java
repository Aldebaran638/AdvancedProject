package com.zeroone.star.contractmanagement.controller;

import com.zeroone.star.contractmanagement.service.IContractService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractPrintDTO;
import com.zeroone.star.project.j6.contractmanagement.DraftContractApis;
import com.zeroone.star.project.query.j6.contractmanagement.draftcontract.ContractQuery;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import javax.validation.Valid;


/*
 *描述 ：起草合同的代码实现
 *Author:28768
 */
@RestController
@RequestMapping("/j6-contract/draft")
@Api(tags = "起草合同")
public class DraftContractController  implements DraftContractApis {

    @Resource
    private IContractService contractService;


    @GetMapping("/query-contract")
    @ApiOperation(value = "获取合同列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<ContractListVO>> queryContractList(ContractQuery condition) {
        return contractService.listContract(condition);
    }
    @ApiOperation(value = "选择合同列表（条件+分页）")
    @GetMapping("/query-contract-select")
    @Override
    public JsonVO<PageDTO<ContractListVO>> selectContractList(ContractQuery condition) {
        return contractService.listContract(condition);
    }

    @ApiOperation(value = "获取合同详情")
    @GetMapping("/query-by-id")
    @Override
    public JsonVO<ContractDTO> queryById(@RequestParam String contractTypeId) {
        ContractDTO contractDTO = contractService.getContractById(contractTypeId);
        return JsonVO.success(contractDTO);
    }
    //TODO 不知道是返回数据信息，还是文件
    @ApiOperation(value = "获取合同附件")
    @GetMapping("/query-files")
    @Override
    public JsonVO<PageDTO<ContractFileVo>> queryFiles(ContractQuery condition) {
        return JsonVO.success(contractService.getFilesById(condition));
    }

    //TODO 测试不了，需要页面修改合同，有了记录才能测试
    @ApiOperation(value = "获取合同修改记录（条件+分页）")
    @GetMapping("/query-contract-change-plan-by-id")
    @Override
    public JsonVO<PageDTO<ContractChangePlanVO>> listContractChangePlanById(ContractQuery condition) {
        return JsonVO.success(contractService.listContractChangePlanById(condition));
    }

    @PostMapping("/add-contract")
    @ApiOperation("起草合同")
    @Override
    public JsonVO<Boolean> addContract(@RequestBody ContractDTO contractDTO) {
        boolean b = contractService.addContract(contractDTO);
        if(b){
            return JsonVO.success(b);
        }
        return JsonVO.fail(b);
    }

    @PutMapping("/modify-contract")
    @ApiOperation("修改合同")
    @Override
    public JsonVO<Boolean> modifyContract(@RequestBody ContractDTO contractDTO) {
        boolean b = contractService.modifyContract(contractDTO);
        if(b){
            return JsonVO.success(b);
        }
        return JsonVO.fail(b);
    }

    @DeleteMapping("/delete-contract")
    @ApiOperation("删除合同")
    @Override
    public JsonVO<Boolean> deleteContract(String  contractId) {
        boolean b = contractService.deleteContract(contractId);
        if(b){
            return JsonVO.success(b);
        }
        return JsonVO.fail(b);
    }

    @ApiOperation("打印合同")
    @Override
    @GetMapping("/print")
    public JsonVO<ContractPrintVO> createPrintTask(@Valid ContractPrintDTO contractPrintDTO) {
        ContractPrintVO printTask = contractService.createPrintTask(contractPrintDTO);
        return JsonVO.success(printTask);
    }

}
