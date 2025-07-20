package com.zeroone.star.systemmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.systemmanage.entity.SystemInfoDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface SystemInfoMapper extends BaseMapper<SystemInfoDO> {
    int updateSystemInfo(SystemInfoDO systemInfoDO);
}
