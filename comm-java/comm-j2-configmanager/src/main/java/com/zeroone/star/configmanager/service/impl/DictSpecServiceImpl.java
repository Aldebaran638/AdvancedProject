package com.zeroone.star.configmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.configmanager.entity.DictSpec;
import com.zeroone.star.configmanager.mapper.DictSpecMapper;
import com.zeroone.star.configmanager.service.IDictSpecService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecDTO;
import com.zeroone.star.project.query.j2.configmanager.dict.DictSpecQuery;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;


/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author fish
 * @since 2025-05-19
 */
@Service
//开启事务
@Transactional
public class DictSpecServiceImpl extends ServiceImpl<DictSpecMapper, DictSpec> implements IDictSpecService {

    @Resource
    private MsDictSpecMapper ms;

    @Override
    public int saveDictSpec(DictSpecAddDTO dictSpecAddDTO) {
        DictSpec dictSpec = ms.addDtoToDo(dictSpecAddDTO);

        List<DictSpecDTO> queryListNames = queryListNames();

        for (DictSpecDTO dto : queryListNames) {
            if (dto.getSpecName().equals(dictSpecAddDTO.getSpecName())) {
                return 2;
            }
        }

        if (save(dictSpec))
            return 1;
        return 0;
    }

    @Override
    public PageDTO<DictSpecDTO> queryAll(DictSpecQuery query) {
        // 构建分页查询对象
        Page<DictSpec> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        LambdaQueryWrapper<DictSpec> wrapper = new LambdaQueryWrapper<>();
        wrapper.like(!StringUtils.isEmpty(query.getSpecName()), DictSpec::getSpecName, query.getSpecName())
                .orderByDesc(DictSpec::getSpecId);
        // 查询数据
        Page<DictSpec> pageResult = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(pageResult, src -> ms.dictSpecToDto(src));
    }

    @Override
    public List<DictSpecDTO> queryListNames() {
        // 构建查询条件
        LambdaQueryWrapper<DictSpec> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(DictSpec::getStatusCd, "0")
                .orderByDesc(DictSpec::getSpecId);
        // 查询数据并转换为DTO
        List<DictSpecDTO> list = baseMapper.selectList(wrapper).stream()
                .map(ms::dictSpecToDto).collect(Collectors.toList());
        return list;
    }

}
