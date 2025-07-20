package com.zeroone.star.orgmanager.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.RelatedUnitAddDTO;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.NoRelatedUnitQuery;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.RelatedUnitQuery;
import com.zeroone.star.project.vo.j2.orgmanager.dataPriviledge.RelatedUnitVO;

import java.util.ArrayList;
import java.util.List;

public interface RelatedUnitService {
    PageDTO<RelatedUnitVO> queryRelatedUnitList(Page<RelatedUnitVO> page, RelatedUnitQuery query);

    PageDTO<RelatedUnitVO> queryNoRelatedUnitList(Page<RelatedUnitVO> page,NoRelatedUnitQuery query);

    String addRelatedUnit(ArrayList<RelatedUnitAddDTO> relatedUnitAddDTOList);

    String removeRelatedUnit(String dpUnitId);
}
