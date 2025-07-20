package com.zeroone.star.configmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.configmanager.entity.CMappingDomain;
import com.zeroone.star.configmanager.mapper.CMappingDomainMapper;
import com.zeroone.star.configmanager.service.ICMappingDomainService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.MappingDomainDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.MappingDomainNameDTO;
import com.zeroone.star.project.query.j2.configmanager.MappingDomainQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hubery
 * @since 2025-05-16
 */
@Service
public class CMappingDomainServiceImpl extends ServiceImpl<CMappingDomainMapper, CMappingDomain> implements ICMappingDomainService {

    @Autowired
    private CMappingDomainMapper mapper;
    @Autowired
    private MsMappingDomainMapper ms;


    /**
     * 根据传入条件分页查询配置项并排序
     * @param query 查询条件
     * @return 查询结果
     */
    @Override
    public PageDTO<MappingDomainDTO> search(MappingDomainQuery query) {
        // 构造分页对象
        Page<CMappingDomain> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构造查询对象
        LambdaQueryWrapper<CMappingDomain> wrapper = new LambdaQueryWrapper<>();
        // 只添加非空的条件
        wrapper.eq(StringUtils.hasText(query.getDomain()), CMappingDomain::getDomain, query.getDomain())
                .eq(StringUtils.hasText(query.getDomainName()), CMappingDomain::getDomainName, query.getDomainName())
                .eq(CMappingDomain::getStatusCd, "0")  // 状态为有效
                .orderByAsc(CMappingDomain::getSeq);   // 按seq升序
        // 执行
        Page<CMappingDomain> selectPage = mapper.selectPage(page, wrapper);
        return PageDTO.create(selectPage,src->ms.doToDto(src));
    }


    /**
     * 查询所有的配置项名称
     */
    @Override
    public List<MappingDomainNameDTO> listAllNames() {
        List<CMappingDomain> list = mapper.selectList(null);
        List<MappingDomainNameDTO> result = new ArrayList<>();
        for (CMappingDomain domain : list) {
            MappingDomainNameDTO dto = new MappingDomainNameDTO();
            dto.setDomainName(domain.getDomainName());
            dto.setId(domain.getId());
            dto.setRemark(domain.getRemark());
            result.add(dto);
        }
        return result;
    }
}
