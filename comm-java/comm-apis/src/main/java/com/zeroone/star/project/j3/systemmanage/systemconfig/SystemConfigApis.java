package com.zeroone.star.project.j3.systemmanage.systemconfig;

import com.zeroone.star.project.dto.j3.systemmanage.systemconfig.SystemInfoDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 系统配置接口
 */
public interface SystemConfigApis {
    /**
     * 修改系统配置
     * @param systemInfoDto 系统配置修改数据对象
     * @return 修改结果
     */
    JsonVO<String> updateSystemInfo(SystemInfoDTO systemInfoDto);
}
