package com.zeroone.star.menumana.mapper;


import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.menumana.entity.Privilege;
import org.apache.ibatis.annotations.Mapper;

/**
* @author cv
* @description 针对表【p_privilege】的数据库操作Mapper
* @createDate 2025-05-20 17:05:06
* @Entity com.zeroone.star.menumana.entity.Privilege
*/

@Mapper
@TableName("p_privilege")
public interface PrivilegeMapper extends BaseMapper<Privilege> {


}
