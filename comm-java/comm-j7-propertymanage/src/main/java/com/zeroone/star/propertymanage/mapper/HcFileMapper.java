package com.zeroone.star.propertymanage.mapper;

import org.apache.ibatis.annotations.Mapper;

import java.util.Map;

@Mapper
public interface HcFileMapper {
    /**
     * 保存文件元数据
     * @param info 文件信息 Map (对应 HcFilePo 字段)
     * @return 影响的行数
     * @throws Exception 操作数据库异常
     */
    int saveFile(Map<String, Object> info) throws Exception;
}
