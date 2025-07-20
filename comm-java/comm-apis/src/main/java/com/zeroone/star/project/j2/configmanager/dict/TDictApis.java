package com.zeroone.star.project.j2.configmanager.dict;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.*;

import com.zeroone.star.project.query.j2.configmanager.sys.dictionary.DictionaryQuery;
import com.zeroone.star.project.query.j2.configmanager.sys.dictionary.TDictQuery;
import com.zeroone.star.project.vo.JsonVO;



/**
 * 菜单目录接口定义
 */
public interface TDictApis {

    /**
     * 查询字典名称列表
     *
     * @return 字典名称列表
     */
    JsonVO<PageDTO<AddDictionaryDTO>> queryDictionary(DictionaryQuery query);

    /**
     * 分页查询目录
     *
     * @param query 查询参数
     * @return 菜单目录列表
     */
    JsonVO<PageDTO<AddTDictResDTO>> queryTDict(
            TDictQuery query);

    /**
     * 添加目录
     *
     * @param addTDictDTO 添加目录参数
     * @return 添加结果
     */
    JsonVO<Boolean> addTDict(
            AddTDictDTO addTDictDTO);

    /**
     * 修改目录
     *
     * @param tDictDTO 修改目录参数
     * @return 修改结果
     */
    JsonVO<Boolean> modifyTDict(ModifyTDictDTO tDictDTO);

    /**
     * 删除目录
     *
     * @param id 目录id
     * @return 删除结果
     */
    JsonVO<String> removeTDict(Integer id);
}
