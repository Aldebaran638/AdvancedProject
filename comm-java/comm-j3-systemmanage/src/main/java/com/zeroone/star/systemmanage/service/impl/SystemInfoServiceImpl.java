package com.zeroone.star.systemmanage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.dto.j3.systemmanage.systemconfig.SystemInfoDTO;
import com.zeroone.star.systemmanage.entity.SystemInfoDO;
import com.zeroone.star.systemmanage.mapper.SystemInfoMapper;
import com.zeroone.star.systemmanage.service.SystemInfoService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class SystemInfoServiceImpl implements SystemInfoService {
    @Resource
    private SystemInfoMapper systemInfoMapper;
    @Override
    public int updateSystemInfo(SystemInfoDTO systemInfoDto) {
        SystemInfoDO systemInfoDO = new SystemInfoDO();
        BeanUtil.copyProperties(systemInfoDto,systemInfoDO);
        return systemInfoMapper.updateSystemInfo(systemInfoDO);
    }
}
