package com.zeroone.star.configmanager.service;

import com.zeroone.star.configmanager.entity.DictSpec;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecDTO;
import com.zeroone.star.project.query.j2.configmanager.dict.DictSpecQuery;

import java.util.List;


/**
 * <p>
 *  服务类接口,继承IService,自带了CRUD方法
 * </p>
 *
 * @author fish
 * @since 2025-05-19
 */
public interface IDictSpecService extends IService<DictSpec> {


    /**
     * 新增字典类型
     * @param dictSpecAddDTO 字典类型信息
     * @return 是否成功
     */
    int saveDictSpec(DictSpecAddDTO dictSpecAddDTO);

    /**
     * 分页查询字典类型数据
     * @param query 分页查询条件
     * @return 分页数据
     */
    PageDTO<DictSpecDTO> queryAll(DictSpecQuery query);

    /**
     * 查询字典类型的所有名称列表
     * @return 字典类型名称列表
     * */
    List<DictSpecDTO> queryListNames();
}
