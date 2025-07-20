package com.zeroone.star.orgmanager.service.serviceImpl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.IdUtil;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.mapper.RelatedUnitMapper;
import com.zeroone.star.orgmanager.service.RelatedUnitService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.RelatedUnitAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.RelatedUnitDTO;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.NoRelatedUnitQuery;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.RelatedUnitQuery;
import com.zeroone.star.project.vo.j2.orgmanager.dataPriviledge.RelatedUnitVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

@Service
public class RelatedUnitServiceImpl implements RelatedUnitService {
    @Autowired
    private RelatedUnitMapper relatedUnitMapper;
    @Override
    public PageDTO<RelatedUnitVO> queryRelatedUnitList(Page<RelatedUnitVO> page, RelatedUnitQuery query) {
        // 将 page 和 query 一起传给 mapper
        return PageDTO.create(relatedUnitMapper.queryRelatedUnitList(page, query));
    }


    @Override
    public PageDTO<RelatedUnitVO> queryNoRelatedUnitList(Page<RelatedUnitVO> page,NoRelatedUnitQuery query) {
        query.setCommunityId(relatedUnitMapper.getCommunityIdBydpId(query.getDpId(),query.getStatusCd()));
        PageDTO<RelatedUnitVO> allUnitList = PageDTO.create(relatedUnitMapper.queryNoRelatedUnitList(page,query));
        PageDTO<RelatedUnitVO> relatedUnitList = PageDTO.create(relatedUnitMapper.queryRelatedUnitList(page,query));
        allUnitList.getRows().removeAll(relatedUnitList.getRows());
        return allUnitList;
    }
    @Transactional(rollbackFor = Exception.class)
    @Override
    public String addRelatedUnit(ArrayList<RelatedUnitAddDTO> relatedUnitAddDTOList) {
        for (RelatedUnitAddDTO relatedUnitAddDTO : relatedUnitAddDTOList) {
            RelatedUnitDTO relatedUnitDTO = new RelatedUnitDTO();
            BeanUtil.copyProperties(relatedUnitDTO, relatedUnitAddDTO);
            LocalDateTime now = LocalDateTime.now();
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            String createTimeStr = now.format(formatter);

            relatedUnitDTO.setStatusCd("0");
            relatedUnitDTO.setBId("-1");
            relatedUnitDTO.setCreateTime(createTimeStr);
            String statusCd = "0";
            String  communityId = relatedUnitMapper.getCommunityIdBydpId(relatedUnitDTO.getDpId(),statusCd);
            if (communityId == null){
                return "数据权限人所在的小区不存在";
            }
            relatedUnitDTO.setCommunityId(communityId);
            String  unitNum = relatedUnitAddDTO.getUnitNum();
            String  floorNum = relatedUnitAddDTO.getFloorNum();
            String UnitId = relatedUnitMapper.getUnitId(unitNum,floorNum,communityId);
            String  floorId = relatedUnitMapper.getFloorId(unitNum,floorNum,communityId);
            if (UnitId == null || floorId == null){
                return "数据权限人所在的小区不存在该单元或楼栋";
            }
            relatedUnitDTO.setUnitId(UnitId);
            relatedUnitDTO.setFloorId(floorId);
            relatedUnitDTO.setDpUnitId(String.valueOf(IdUtil.getSnowflakeNextId()));
            relatedUnitMapper.addRelatedUnit(relatedUnitDTO);
        }

        return "";
    }
    @Transactional(rollbackFor = Exception.class)
    @Override
    public String removeRelatedUnit(String dpUnitId) {
        relatedUnitMapper.removeRelatedUnit(dpUnitId);
        return "";
    }
}
