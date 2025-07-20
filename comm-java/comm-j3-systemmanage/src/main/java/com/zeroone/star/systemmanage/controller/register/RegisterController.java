package com.zeroone.star.systemmanage.controller.register;

import com.zeroone.star.project.j3.systemmanage.register.RegisterApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanage.service.RegisterProtocolService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import com.zeroone.star.project.dto.j3.systemmanage.register.RegisterProtocolDTO;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("j3-system/register")
@Api(tags = "注册协议")
public class RegisterController implements RegisterApis {

    @Resource
    RegisterProtocolService registerProtocolService;

    @Override
    @PutMapping("/update-register-protocol")
    @ApiOperation("修改注册协议")
    public JsonVO<String> updateRegisterProtocol(@RequestBody RegisterProtocolDTO registerProtocolDto){
        int result = registerProtocolService.updateProtocol(registerProtocolDto);
        if(result >= 0){
            return JsonVO.success("修改注册协议成功！");
        }
        else {
            return JsonVO.fail("修改注册协议失败！");
        }

    }
}
