package com.zeroone.star.systemmanage.controller.systemconfig;

import com.zeroone.star.project.dto.j3.systemmanage.systemconfig.SystemInfoDTO;
import com.zeroone.star.project.j3.systemmanage.systemconfig.SystemConfigApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanage.service.SystemInfoService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

@RestController
@RequestMapping("j3-system/system-config")
@Api(tags = "系统配置")
public class SystemConfigController implements SystemConfigApis {

    @Resource
    private SystemInfoService systemInfoService;

    @Override
    @PutMapping("/update-system-info")
    @ApiOperation("修改系统配置")
    public JsonVO<String> updateSystemInfo(@RequestBody SystemInfoDTO systemInfoDto){
        int result = systemInfoService.updateSystemInfo(systemInfoDto);
        if(result>0){
            return JsonVO.success("修改系统配置成功！");
        }
        else {
            return JsonVO.fail("修改系统配置失败！");
        }
    }
}
