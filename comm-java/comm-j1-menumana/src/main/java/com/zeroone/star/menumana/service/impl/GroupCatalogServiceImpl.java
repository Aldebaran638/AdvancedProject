package com.zeroone.star.menumana.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.menumana.entity.GroupCatalog;
import com.zeroone.star.menumana.mapper.GroupCatalogMapper;
import com.zeroone.star.menumana.mapper.MsGroupCatalogMapper;
import com.zeroone.star.menumana.service.IGroupCatalogService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogAddDTO;
import com.zeroone.star.project.dto.j1.menumana.menudir.GroupCatalogDelDTO;
import com.zeroone.star.project.query.j1.menumana.menudir.GroupCatalogQuery;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogAddVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogDelVO;
import com.zeroone.star.project.vo.j1.menumana.menudir.GroupCatalogQueryVO;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@RequiredArgsConstructor
public class GroupCatalogServiceImpl implements IGroupCatalogService {
    private final MsGroupCatalogMapper msGroupCatalogMapper;
    private final GroupCatalogMapper groupCatalogMapper;

    @Override
    public PageDTO<GroupCatalogQueryVO> listMenuCatalogGroup(GroupCatalogQuery groupCatalogQuery) {
        QueryWrapper<GroupCatalog> wrapper = new QueryWrapper<>();
        Page<GroupCatalog> page = new Page<>(groupCatalogQuery.getPageIndex(),groupCatalogQuery.getPageSize());
        wrapper.lambda()
                .eq(GroupCatalog::getCaId,groupCatalogQuery.getCaId())
                .eq(GroupCatalog::getStoreType,groupCatalogQuery.getStoreType());
        Page<GroupCatalog> groupCatalogPage = groupCatalogMapper.selectPage(page, wrapper);
        return PageDTO.create(groupCatalogPage, msGroupCatalogMapper::DO2queryVO);
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public GroupCatalogAddVO saveMenuCatalogGroup(GroupCatalogAddDTO groupCatalogAddDTO) {
        GroupCatalog groupCatalog = msGroupCatalogMapper.addDTO2DO(groupCatalogAddDTO);
        if (groupCatalogMapper.existsByGIdStoreTypeCaId(
                groupCatalogAddDTO.getGid(),groupCatalogAddDTO.getStoreType(),groupCatalogAddDTO.getCaId())){
            return null;
        }
        // 参数回填
        int affectedRows = groupCatalogMapper.insert(groupCatalog);
        GroupCatalogAddVO groupCatalogAddVO = new GroupCatalogAddVO();
        if (affectedRows >= 1) {
            groupCatalogAddVO.setGcId(groupCatalog.getGcId());
            groupCatalogAddVO.setCreateTime(groupCatalog.getCreateTime());
            return groupCatalogAddVO;
        }else{
            return null;
        }
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public GroupCatalogDelVO removeMenuCatalogGroup(GroupCatalogDelDTO groupCatalogDelDTO) {
        String gcId = groupCatalogDelDTO.getGcId();
        int affectedRows = groupCatalogMapper.deleteById(gcId);
        GroupCatalogDelVO groupCatalogDelVO = new GroupCatalogDelVO();
        if (affectedRows >= 1) {
            groupCatalogDelVO.setGcId(gcId);
            return groupCatalogDelVO;
        }else{
            return null;
        }
    }
}
