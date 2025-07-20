package com.zeroone.star.configmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.configmanager.entity.TDict;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.*;
import com.zeroone.star.project.query.j2.configmanager.sys.dictionary.DictionaryQuery;
import com.zeroone.star.project.query.j2.configmanager.sys.dictionary.TDictQuery;
import com.zeroone.star.project.vo.ResultStatus;

import java.util.List;

public interface ITDictService extends IService<TDict> {
    /**
     * 分页查询
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<AddTDictResDTO> listAll(TDictQuery query);

    PageDTO<AddDictionaryDTO> listByConditions(DictionaryQuery query);

    ResultStatus addTDict(AddTDictDTO dto);

    ResultStatus modifyTDict(ModifyTDictDTO dto);

    //仅用于获取t_dict_spec表内的所有spec_name
    List<String> getAllSpecNames();

    //获取t_dict_spec表内的所有spec_Id
    List<String> getAllSpecIds();
}
