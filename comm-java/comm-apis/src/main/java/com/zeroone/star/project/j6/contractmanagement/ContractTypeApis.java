package com.zeroone.star.project.j6.contractmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractExtMetaDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeSpecDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeTemplateDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contracttype.ContractTypeQuery;
import com.zeroone.star.project.query.j6.contractmanagement.contracttype.ContractTypeSpecQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeNameVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeSpecVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeTemplateVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeVO;

import java.util.List;

/*
 *描述 ：合同类型接口
 *Author:28768
 */
public interface ContractTypeApis {

    /**
     * 获取合同类型列表（条件+分页）
     * @param query
     * @return 返回合同类型列表
     */
        JsonVO<PageDTO<ContractTypeVO>> listContractTypes(ContractTypeQuery query);

    /**
     * 获取合同类型名称列表
     * @return 返回合同类型名称列表
     */
        JsonVO<List<ContractTypeNameVO>> listContractTypeNames();



    /**
     * 新增合同类型
     */
    JsonVO<Boolean> addContractType(ContractTypeDTO contractTypeDTO);

    /**
     * 修改合同类型
     */
    JsonVO<Boolean> updateContractType(ContractTypeDTO contractTypeDTO);


    /**
     * 获取合同类型扩展信息（条件+分页）
     * @param condition
     * @return
     */
    JsonVO<PageDTO<ContractTypeSpecVO>> queryAll(ContractTypeSpecQuery condition);

    /**
     * 添加合同扩展信息
     *
     * @param contractExtMetaDTO
     * @return 保存是否成功
     */
    JsonVO<Boolean> addContractExtInfo(ContractExtMetaDTO contractExtMetaDTO);
    /**
     * 修改合同扩展信息
     *
     * @param contractExtMetaDTO
     * @return 修改后完整的合同扩展信息
     */
    JsonVO<Boolean> modifyContractExtInfo(ContractExtMetaDTO contractExtMetaDTO);

    /**
     * 删除合同类型扩展信息
     *
     * @param contractTypeSpecDTO 合同类型编号
     * @return 返回删除结果
     */
    JsonVO<Boolean> deleteContractTypeExtend(ContractTypeSpecDTO contractTypeSpecDTO);

    /**
     * 获取合同类型模板
     * @param contractTypeId 合同类型编号
     * @return 返回合同类型模板
     */
    JsonVO<ContractTypeTemplateVO> getContractTypeTemplate(String contractTypeId);

    /**
     * 修改合同类型模板
     *
     * @param contractTypeTemplateDTO 合同类型模板DTO
     * @return 返回修改结果
     */
    JsonVO<Boolean> modifyContractTypeTemplate(ContractTypeTemplateDTO contractTypeTemplateDTO);


    /**
     * 删除合同类型
     *
     * @param contractDTO
     * @return
     */
    JsonVO<Boolean> remove(ContractTypeDTO contractDTO);

}
