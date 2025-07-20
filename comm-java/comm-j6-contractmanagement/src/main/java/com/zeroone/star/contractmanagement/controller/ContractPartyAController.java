package com.zeroone.star.contractmanagement.controller;

import com.zeroone.star.contractmanagement.service.IContractPartyaService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contractpartya.ContractPartyaAddDTO;
import com.zeroone.star.project.vo.j6.contractmanagement.contractpartya.ContractPartyaVO;
import com.zeroone.star.project.j6.contractmanagement.ContractPartyAApis;
import com.zeroone.star.project.query.j6.contractmanagement.contractpartya.ContractPartyaQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

/*
 *描述 ：合同甲方的代码实现
 *Author:28768
 */
@RestController
@RequestMapping("/j6-contract/partya")
@Api(tags = "合同甲方")
public class ContractPartyAController implements ContractPartyAApis {
    @Resource
    IContractPartyaService contractPartyaService;

    @PostMapping("/save-contract-partya")
    @ApiOperation(value = "添加合同甲方", notes = "添加新的合同甲方信息")
    @Override
    public JsonVO<Boolean> addContractPartya(@RequestBody @Valid ContractPartyaAddDTO addDto) throws Exception {
        return contractPartyaService.addContractPartya(addDto)?JsonVO.success(true):JsonVO.fail(false);
    }

    @PostMapping("/update-contract-partya")
    @ApiOperation(value = "修改合同甲方")
    @Override
    public JsonVO<Boolean> updateContractPartyDTO(@RequestBody @Valid ContractPartyaAddDTO contractPartyDTO) {
        boolean result = contractPartyaService.modifyContractPartya(contractPartyDTO);
       if(!result){
           return JsonVO.fail(false);
       }
       return JsonVO.success(true);
    }

    @DeleteMapping("/delete-contract-partya")
    @ApiOperation(value = "删除合同甲方")
    @Override
    public JsonVO<Boolean> deleteContractPartyDTO (@RequestBody @Valid ContractPartyaAddDTO contractPartyDTO) {
        // 调用 service 删除方法，返回被删除的数据（逻辑删除前的数据）
        String result = contractPartyaService.deleteContractPartya(contractPartyDTO);
        if(result==null){
            return JsonVO.fail(true);
        }
        return JsonVO.success(false);
    }


    @GetMapping("/list-contract-partya")
    @ApiOperation(value = "获取合同甲方列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<ContractPartyaVO>> queryAll(@Valid ContractPartyaQuery condition) throws Exception {
        PageDTO<ContractPartyaVO> contractPartyaVOPageDTO = contractPartyaService.getContractPartyaPageByConditions(condition);
        return JsonVO.success(contractPartyaVOPageDTO);
    }


    @GetMapping("/query-contract-partya")
    @ApiOperation(value = "获取合同甲方名称列表")
    @Override
    public JsonVO<List<ContractPartyaVO>> listQuery() throws Exception {
        return JsonVO.success(contractPartyaService.getContractPartyaList());
    }


}
