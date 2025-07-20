package com.zeroone.star.contractmanagement.controller;



import com.zeroone.star.contractmanagement.entity.ContractTypeSpec;
import com.zeroone.star.contractmanagement.service.IContractTypeService;
import com.zeroone.star.contractmanagement.service.IContractTypeSpecService;
import com.zeroone.star.contractmanagement.service.IContractTypeTemplateService;
import com.zeroone.star.contractmanagement.service.impl.MsContractTypeSpecMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractExtMetaDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeSpecDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeTemplateDTO;
import com.zeroone.star.project.j6.contractmanagement.ContractTypeApis;
import com.zeroone.star.project.query.j6.contractmanagement.contracttype.ContractTypeQuery;
import com.zeroone.star.project.query.j6.contractmanagement.contracttype.ContractTypeSpecQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeNameVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeSpecVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeTemplateVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.Valid;
import java.util.List;

/*
 *描述 ：合同类型的代码实现
 *Author:28768
 */
@RestController
@RequestMapping("/j6-contract/type")
@Api(tags = "合同类型")
public class ContractTypeController implements ContractTypeApis {

    @Resource
    IContractTypeTemplateService contractTypeTemplateService;
    @Resource
    IContractTypeSpecService contractTypeSpecService;

    @Resource
    IContractTypeService contractTypeService;

    @Resource
    MsContractTypeSpecMapper mscontractTypeSpecMapper;




    @ApiOperation(value = "获取合同类型列表（条件+分页）")
    @GetMapping("/query-contract-types")
    @Override
    public JsonVO<PageDTO<ContractTypeVO>> listContractTypes(ContractTypeQuery query) {
        PageDTO<ContractTypeVO> contractTypeVOPageDTO = contractTypeService.listContractTypes(query);
        return JsonVO.success(contractTypeVOPageDTO);
    }

    @ApiOperation(value = "获取合同类型名称列表")
    @GetMapping("/list-contract-type-names")
    @Override
    public JsonVO<List<ContractTypeNameVO>> listContractTypeNames() {
        List<ContractTypeNameVO> contractTypeNames= contractTypeService.listContractTypeNames();
        return JsonVO.success(contractTypeNames);
    }

    @ApiOperation(value = "删除合同类型扩展信息")
    @DeleteMapping("/delete-contract-type-extend")
    @Override
    public JsonVO<Boolean> deleteContractTypeExtend(@RequestBody ContractTypeSpecDTO contractTypeSpecDTO) {
        return contractTypeSpecService.deleteSpec(contractTypeSpecDTO.getSpecCd()) ? JsonVO.success(true) : JsonVO.fail(false);
    }

    @ApiOperation(value = "获取合同类型模板")
    @GetMapping("/query-template")
    @Override
    public JsonVO<ContractTypeTemplateVO> getContractTypeTemplate(String contractTypeId) {
        ContractTypeTemplateVO contractTypeTemplateVO=contractTypeTemplateService.queryByContractTypeId(contractTypeId);
        if(contractTypeTemplateVO==null){
            return JsonVO.fail(null);
        }
        return JsonVO.success(contractTypeTemplateVO);
    }

    @ApiOperation(value = "修改合同类型模板")
    @PutMapping("/modify-template")
    @Override
    public JsonVO<Boolean> modifyContractTypeTemplate(@RequestBody ContractTypeTemplateDTO contractTypeTemplateDTO) {
        if (contractTypeTemplateService.modifyContractTypeTemplate(contractTypeTemplateDTO)) {
            return JsonVO.success(true);
        } else {
            return JsonVO.fail(false);
        }
    }
    @PostMapping("/add-contract-type")
    @ApiOperation(value = "新增合同类型")
    @Override
    public JsonVO<Boolean> addContractType(@RequestBody @Valid ContractTypeDTO dto) {
        Integer result=contractTypeService.addContractType(dto);
        if(result == 0){
            //插入失败
            return JsonVO.fail(false);
        }
        //插入成功
        return JsonVO.success(true);
    }

    @PutMapping("/update-contract-type")
    @ApiOperation("修改合同类型")
    @Override
    public JsonVO<Boolean> updateContractType(@RequestBody @Valid ContractTypeDTO contractTypeDTO) {
        Integer result = contractTypeService.updateContractType(contractTypeDTO);
        if(result == 0){
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }
    @ApiOperation(value = "获取合同类型扩展信息列表（条件+分页）",notes = "需要分页查询的条件")
    @GetMapping("/queryAll-contract-type-info")
    @Override
    public JsonVO<PageDTO<ContractTypeSpecVO>> queryAll(ContractTypeSpecQuery condition) {
        PageDTO<ContractTypeSpecVO> contractTypeSpecVOS = contractTypeSpecService.listContractTypeSpec(condition);
       return JsonVO.success(contractTypeSpecVOS);
    }

    @PostMapping("/add-extend-info")
    @ApiOperation("添加合同扩展信息")
    @Override
    public JsonVO<Boolean> addContractExtInfo(@RequestBody @Valid ContractExtMetaDTO contractExtMetaDTO) {
        ContractTypeSpec entity = mscontractTypeSpecMapper.dtoToEntity(contractExtMetaDTO);
        contractTypeSpecService.addContractExtInfo(entity);
        return JsonVO.success(true);
    }
    @PutMapping("/modify-extend-info")
    @ApiOperation("修改合同扩展信息")
    @Override
    public JsonVO<Boolean> modifyContractExtInfo(@RequestBody @Valid ContractExtMetaDTO contractExtMetaDTO) {
        ContractTypeSpec entity = mscontractTypeSpecMapper.dtoToEntity(contractExtMetaDTO);
        contractTypeSpecService.modifyContractExtInfo(entity);
        if (entity.getSpecCd() == null) {
            return JsonVO.fail(false);
        }
        else
            return JsonVO.success(true);
    }

    @ApiOperation(value = "删除合同类型",notes = "需要传入合同类型数据")
    @DeleteMapping("/remove-contract-type")
    @Override
    public JsonVO<Boolean> remove(@RequestBody @Valid ContractTypeDTO contractDTO) {
        Integer result = contractTypeService.removeContractType(contractDTO);
        if (result==0){
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }
}

