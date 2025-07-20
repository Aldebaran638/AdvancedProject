package com.zeroone.star.contractmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.zeroone.star.contractmanagement.entity.ContractTypeTemplate;
import com.zeroone.star.contractmanagement.mapper.ContractTypeTemplateMapper;
import com.zeroone.star.contractmanagement.service.IContractTypeTemplateService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeTemplateDTO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeTemplateVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author kunge
 * @since 2025-06-03
 */
@Service
public class ContractTypeTemplateServiceImpl extends ServiceImpl<ContractTypeTemplateMapper, ContractTypeTemplate> implements IContractTypeTemplateService {

    @Resource
    private ContractTypeTemplateMapper contractTypeTemplateMapper;

    @Resource
    private MsContractTypeTemplateMapper msContractTypeTemplateMapper;

    @Override
    public boolean modifyContractTypeTemplate(ContractTypeTemplateDTO contractTypeTemplateDTO) {
        LambdaUpdateWrapper<ContractTypeTemplate> wrapper = new LambdaUpdateWrapper<>();
        wrapper.eq(ContractTypeTemplate::getContractTypeId, contractTypeTemplateDTO.getContractTypeId());
        wrapper.set(ContractTypeTemplate::getContext,contractTypeTemplateDTO.getContext());
        int update = contractTypeTemplateMapper.update(null, wrapper);
        return update != 0;
    }
    @Override
    public ContractTypeTemplateVO queryByContractTypeId(String contractTypeId) {
        LambdaQueryWrapper<ContractTypeTemplate> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(contractTypeId!=null,ContractTypeTemplate::getContractTypeId, contractTypeId);
        ContractTypeTemplate contractTypeTemplate = contractTypeTemplateMapper.selectOne(wrapper);
        if(contractTypeTemplate==null){
            return null;
        }
        return msContractTypeTemplateMapper.toContractTypeTemplateVO(contractTypeTemplate);
    }
}
