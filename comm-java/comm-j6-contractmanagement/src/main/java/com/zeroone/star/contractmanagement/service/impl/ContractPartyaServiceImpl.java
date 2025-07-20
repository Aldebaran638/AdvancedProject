package com.zeroone.star.contractmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.zeroone.star.contractmanagement.entity.ContractPartya;
import com.zeroone.star.contractmanagement.entity.SStore;
import com.zeroone.star.contractmanagement.mapper.ContractPartyaMapper;
import com.zeroone.star.contractmanagement.mapper.SStoreMapper;
import com.zeroone.star.contractmanagement.service.IContractPartyaService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.contractmanagement.contractpartya.ContractPartyaAddDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contractpartya.ContractPartyaQuery;
import com.zeroone.star.project.vo.j6.contractmanagement.contractpartya.ContractPartyaVO;
import lombok.SneakyThrows;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author denghuo
 * @since 2025-05-25
 */
@Service
public class ContractPartyaServiceImpl extends ServiceImpl<ContractPartyaMapper, ContractPartya> implements IContractPartyaService {

    @Resource
    private MsContractPartyaMapper msContractPartyaMapper;

    @Resource
    private ContractPartyaMapper contractPartyaMapper;

    @Resource
    UserHolder userHolder;



    @Override
    public PageDTO<ContractPartyaVO> getContractPartyaPageByConditions(ContractPartyaQuery conditions) throws Exception {
        // 构建查询条件
        LambdaQueryWrapper<ContractPartya> wrapper = new LambdaQueryWrapper<>();
        //判断请求头是否传送了
        if(com.alibaba.cloud.commons.lang.StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(com.alibaba.cloud.commons.lang.StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }
        //TODO 缺少storeid
        wrapper.eq(ContractPartya::getStoreId,storeId)
                .eq(ContractPartya::getStatusCd, "0")     // 在用状态
                .like(StringUtils.hasText(conditions.getPartyA()), ContractPartya::getPartyA, conditions.getPartyA())
                .like(StringUtils.hasText(conditions.getAContacts()), ContractPartya::getAContacts, conditions.getAContacts())
                .eq(StringUtils.hasText(conditions.getALink()), ContractPartya::getALink, conditions.getALink());

        // 执行分页查询
        Page<ContractPartya> page = new Page<>(conditions.getPageIndex(), conditions.getPageSize());
        Page<ContractPartya> resultPage = page(page, wrapper);
        // 转换为 VO 分页对象
        return PageDTO.create(resultPage, ContractPartyaVO.class);

    }

    @Override
    public List<ContractPartyaVO> getContractPartyaList() throws Exception {
        // 构建查询条件
        LambdaQueryWrapper<ContractPartya> wrapper = new LambdaQueryWrapper<>();
        //TODO 缺少storeid
        //判断请求头是否传送了
        if(com.alibaba.cloud.commons.lang.StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(com.alibaba.cloud.commons.lang.StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        wrapper.eq(ContractPartya::getStoreId, storeId)  // 当前商户
                .eq(ContractPartya::getStatusCd, "0");     // 在用状态

        // 执行查询
        List<ContractPartya> contractPartyaList = contractPartyaMapper.selectList(wrapper);

        // 将查询结果转换为ContractPartyaVO类型并返回
        return contractPartyaList.stream()
                .map(this::convertToVo)
                .collect(Collectors.toList());
    }

    @SneakyThrows
    @Override
    public Boolean addContractPartya(ContractPartyaAddDTO addDTO)  {
        //TODO 缺少storeId

        // 获取当前用户的 storeId
        //判断请求头是否传送了
        if(com.alibaba.cloud.commons.lang.StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(com.alibaba.cloud.commons.lang.StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        addDTO.setStoreId(storeId);
        // DTO → 实体转换（忽略主键）
        ContractPartya entity = msContractPartyaMapper.addDtoToEntity(addDTO);
        int result = contractPartyaMapper.insert(entity);
        // 返回结果
        return result==1;
    }

    private ContractPartyaVO convertToVo(ContractPartya entity) {
        return msContractPartyaMapper.entityToVo(entity);
    }
    @Override
    public boolean modifyContractPartya(ContractPartyaAddDTO contractpartyaaddDTO){
        UpdateWrapper<ContractPartya> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("partya_id", contractpartyaaddDTO.getPartyaId())
                .set("party_a", contractpartyaaddDTO.getPartyA())
                .set("a_contacts", contractpartyaaddDTO.getAContacts())
                .set("a_link", contractpartyaaddDTO.getALink());
        // 执行更新
        int update = contractPartyaMapper.update(null, updateWrapper);
        // 返回是否更新成功
        return update != 0;
    }
    @Override
    public String deleteContractPartya(ContractPartyaAddDTO contractpartyaaddDTO){
        if (contractpartyaaddDTO.getPartyaId() == null) {
            throw new IllegalArgumentException("partya_id不能为空");
        }
        //获取逻辑删除前的数据
        ContractPartya contractPartya = contractPartyaMapper.selectById(contractpartyaaddDTO.getPartyaId());
        if(contractPartya == null){
            throw new IllegalArgumentException("合同甲方数据不存在");
        }
        //删除
        int rows = contractPartyaMapper.deleteById(contractpartyaaddDTO.getPartyaId());
        return rows > 0 ? contractpartyaaddDTO.getPartyaId() : null;
    }
}
