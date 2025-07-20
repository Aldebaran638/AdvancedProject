package com.zeroone.star.propertymanage.mapper;

import org.apache.ibatis.annotations.Mapper;

import java.util.Map;

@Mapper
public interface FileRelMapper {
    /**
     * 保存文件关联信息
     * @param info 文件关联信息 Map (对应 FileRelPo 字段)
     * @return 影响的行数
     * @throws Exception 操作数据库异常
     */
    int saveFileRel(Map<String, Object> info) throws Exception;
}
