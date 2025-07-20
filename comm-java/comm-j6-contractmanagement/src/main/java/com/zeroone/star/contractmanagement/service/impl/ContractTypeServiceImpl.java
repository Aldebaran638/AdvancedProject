package com.zeroone.star.contractmanagement.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.contractmanagement.entity.ContractType;
import com.zeroone.star.contractmanagement.entity.SStore;
import com.zeroone.star.contractmanagement.mapper.ContractTypeMapper;
import com.zeroone.star.contractmanagement.mapper.SStoreMapper;
import com.zeroone.star.contractmanagement.service.IContractTypeService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.jwt.JwtComponent;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractTypeDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contracttype.ContractTypeQuery;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeNameVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeVO;
import lombok.SneakyThrows;
import org.springframework.context.annotation.Lazy;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.awt.print.PrinterAbortException;
import java.util.ArrayList;
import java.util.List;

import static com.zeroone.star.project.vo.ResultStatus.UNAUTHORIZED;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author 坤哥
 * @since 2025-05-18
 */
@Service
public class ContractTypeServiceImpl extends ServiceImpl<ContractTypeMapper, ContractType> implements IContractTypeService {

    @Resource
    private MsContractTypeMapper msContractTypeMapper;

    @Resource
    private ContractTypeMapper contractTypeMapper;


    @Resource
    @Lazy
    private UserHolder userHolder;
    @SneakyThrows
    @Override
    public PageDTO<ContractTypeVO> listContractTypes(ContractTypeQuery query) {
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
        LambdaQueryWrapper<ContractType> wrapper = new LambdaQueryWrapper<>();
        wrapper.like(query.getTypeName()!=null&&query.getTypeName()!="",ContractType::getTypeName,query.getTypeName())
                .eq(query.getAudit()!=null&&query.getAudit()!="",ContractType::getAudit,query.getAudit())
                .eq(ContractType::getStoreId,storeId);
        //设置分页条件
        Page<ContractType> contractTypePage = new Page<>(query.getPageIndex(),query.getPageSize());
        //根据分页条件和条件查询出数据
        Page<ContractType> resultPage = baseMapper.selectPage(contractTypePage, wrapper);
        PageDTO<ContractTypeVO> pageDTO = PageDTO.create(resultPage, ContractTypeVO.class);
        return pageDTO;
    }

    @SneakyThrows
    @Override
    public List<ContractTypeNameVO> listContractTypeNames() {
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
        LambdaQueryWrapper<ContractType> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq( ContractType::getStoreId,storeId);
        List<ContractType> contractTypes = baseMapper.selectList(wrapper);
        //把contractType转换成contractTypeNameVO
        ArrayList<ContractTypeNameVO> contractTypeNameVOS = new ArrayList<>();
        for(int i=0;i<contractTypes.size();i++){
            if(contractTypes.get(i).getTypeName()!=null&&contractTypes.get(i).getTypeName()!=""){
                contractTypeNameVOS.add(msContractTypeMapper.toContractTypeNameVO(contractTypes.get(i)));
            }
        }
        return contractTypeNameVOS;
    }

    @Override
    public Integer removeContractType(ContractTypeDTO contractDTO) {
        String contractTypeId = contractDTO.getContractTypeId();
        return  contractTypeMapper.deleteByContractTypeId(contractTypeId);

    }

    @SneakyThrows
    @Override
    public Integer addContractType(ContractTypeDTO dto) {
        //TODO storeid
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
        //用mapstruct将dto转为do
        ContractType contractType = msContractTypeMapper.toContractType(dto);
        contractType.setStoreId(storeId);
        //进行数据插入
        return baseMapper.insert(contractType);
    }

    @Override
    public Integer updateContractType(ContractTypeDTO contractTypeDTO) {
        //用mapstruct将dto转为do
        ContractType contractType = msContractTypeMapper.toContractType(contractTypeDTO);
        //进行数据修改
         return  baseMapper.updateById(contractType);

    }
}
