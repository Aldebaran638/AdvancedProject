package com.zeroone.star.project.j2.configmanager.dict;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecAddDTO;
import com.zeroone.star.project.dto.j2.configmanager.dict.DictSpecDTO;
import com.zeroone.star.project.query.j2.configmanager.dict.DictSpecQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：测试字典类型API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author fish
 * @version 1.0.0
 */
public interface DictSpecApis {

    /**
     * 测试新增
     * @param addDto 新增数据
     * @return 新增结果
     */
    JsonVO<String> addDictSpec(DictSpecAddDTO addDto);

    /**
     * 测试修改
     * @param dto 修改数据
     * @return 修改结果
     */
    JsonVO<String> modifyDictSpec(DictSpecDTO dto);


    /**
     * 测试删除
     * @param id 主键ID
     * @return 删除结果
     * */
    JsonVO<String> deleteDictSpec(String id);


    /**
     * 测试查询所有名称列表
     *
     * */
    JsonVO<List<DictSpecDTO>> queryListNames();

    /**
     * 测试分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<DictSpecDTO>> queryAll(DictSpecQuery condition);

}
