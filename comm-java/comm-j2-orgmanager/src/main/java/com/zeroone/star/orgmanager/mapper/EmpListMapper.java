package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.orgmanager.entity.UUserDO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.EmpListQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * Mapper 接口
 */
@Mapper
public interface EmpListMapper extends BaseMapper<UUserDO> {
    /**
     * 根据 pgId 查询用户列表（带分页）
     */
    Page<UUserDO> selectByPgId(@Param("query") EmpListQuery query, @Param("page") Page<UUserDO> page);
}

