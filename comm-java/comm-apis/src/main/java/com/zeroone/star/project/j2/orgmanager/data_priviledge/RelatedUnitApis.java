package com.zeroone.star.project.j2.orgmanager.data_priviledge;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.RelatedUnitAddDTO;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.NoRelatedUnitQuery;
import com.zeroone.star.project.query.j2.orgmanager.dataPrivilege.RelatedUnitQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.orgmanager.dataPriviledge.RelatedUnitVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PutMapping;

import java.util.ArrayList;
import java.util.List;


/**
 * 关联单元接口
 * @author 噤玥
 * @version 1.0.0
 */
public interface RelatedUnitApis {
    /**
     * 分页查询已关联单元
     *
     * @param query 查询数据对象
     * @return 查询结果
     */
    JsonVO<PageDTO<RelatedUnitVO>> queryRelatedUnitList(RelatedUnitQuery query);
    /**
     * 分页查询未关联单元
     *
     * @param query 查询数据对象
     * @return 查询结果
     */
    JsonVO<PageDTO<RelatedUnitVO>> queryNoRelatedUnitList(NoRelatedUnitQuery query);
    /**
     * 添加关联单元
     *
     * @param  RelatedUnitAddDTOList 添加数据对象
     * @return 添加结果
     */

    JsonVO<String> addRelatedUnit(ArrayList<RelatedUnitAddDTO> RelatedUnitAddDTOList);

    /**
     * 删除关联单元
     *
     * @param  dpUnitId 删除数据对象
     * @return 删除结果
     */
    JsonVO<String> removeRelatedUnit(String dpUnitId);
}