package com.zeroone.star.contractmanagement.service;

import com.zeroone.star.contractmanagement.entity.ContractType;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contracttype.ContractTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeNameVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeVO;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author 坤哥
 * @since 2025-05-18
 */
public interface IContractTypeService extends IService<ContractType> {

    PageDTO<ContractTypeVO> listContractTypes(ContractTypeQuery query);

    List<ContractTypeNameVO> listContractTypeNames();

    Integer removeContractType(ContractTypeDTO contractDTO);

    Integer addContractType(ContractTypeDTO dto);

    Integer updateContractType(ContractTypeDTO contractTypeDTO);
}
