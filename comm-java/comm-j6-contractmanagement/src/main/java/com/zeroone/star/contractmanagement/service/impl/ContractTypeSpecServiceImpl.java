package com.zeroone.star.contractmanagement.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.contractmanagement.entity.ContractTypeSpec;
import com.zeroone.star.contractmanagement.mapper.ContractTypeSpecMapper;
import com.zeroone.star.contractmanagement.service.IContractTypeSpecService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contracttype.ContractTypeSpecQuery;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeSpecVO;
import lombok.SneakyThrows;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/*
 *描述 ：
 *Author:28768
 */
@Service
public class ContractTypeSpecServiceImpl extends ServiceImpl<ContractTypeSpecMapper, ContractTypeSpec> implements IContractTypeSpecService {

    @Resource
    private ContractTypeSpecMapper contractTypeSpecMapper;
    @Resource
    private UserHolder userHolder;

    @Override
    public boolean deleteSpec(String specCd) {
        if (specCd == null || specCd.isEmpty()) {
            return false;
        }
        int deletedRows = baseMapper.deleteById(specCd);
        return deletedRows > 0;
    }
    @Override
    public PageDTO<ContractTypeSpecVO> listContractTypeSpec(ContractTypeSpecQuery condition) {
        LambdaQueryWrapper<ContractTypeSpec> wrapper = new LambdaQueryWrapper<>();

        // 动态构建查询条件
        if (condition.getSpecName() != null && !condition.getSpecName().isEmpty()) {
            wrapper.like(ContractTypeSpec::getSpecName, condition.getSpecName());
        }
        if (condition.getSpecShow() != null && !condition.getSpecShow().isEmpty()) {
            wrapper.eq(ContractTypeSpec::getSpecShow, condition.getSpecShow());
        }
        if (condition.getContractTypeId() != null) {
            wrapper.eq(ContractTypeSpec::getContractTypeId, condition.getContractTypeId());
        }
        if (condition.getSpecCd() != null && !condition.getSpecCd().isEmpty()) {
            wrapper.eq(ContractTypeSpec::getSpecCd, condition.getSpecCd());
        }

        // 设置分页参数
        Page<ContractTypeSpec> ContractTypeSpecPage = new Page<>(condition.getPageIndex(), condition.getPageSize());

        // 执行分页查询
        Page<ContractTypeSpec> resultPage = contractTypeSpecMapper.selectPage(ContractTypeSpecPage, wrapper);

        return  PageDTO.create(resultPage, ContractTypeSpecVO.class);
    }
    @SneakyThrows
    @Override
    public void addContractExtInfo(ContractTypeSpec contractExtType) {
        //TODO 缺少storeid
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }
        contractExtType.setStoreId(storeId);
        contractTypeSpecMapper.addContractExtInfo(contractExtType);
    }

    @SneakyThrows
    @Override
    public void modifyContractExtInfo(ContractTypeSpec contractExtType) {
        //TODO 缺少storeid
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }
        contractExtType.setStoreId(storeId);
        contractTypeSpecMapper.modifyContractExtInfo(contractExtType);
    }
}
