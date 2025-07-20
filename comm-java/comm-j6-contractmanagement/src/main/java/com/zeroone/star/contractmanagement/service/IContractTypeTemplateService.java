package com.zeroone.star.contractmanagement.service;

import com.zeroone.star.contractmanagement.entity.ContractTypeTemplate;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeTemplateDTO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeTemplateVO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author kunge
 * @since 2025-06-03
 */
public interface IContractTypeTemplateService extends IService<ContractTypeTemplate> {
    public boolean modifyContractTypeTemplate(ContractTypeTemplateDTO contractTypeTemplateDTO);

    ContractTypeTemplateVO queryByContractTypeId(String contractTypeId);
}
