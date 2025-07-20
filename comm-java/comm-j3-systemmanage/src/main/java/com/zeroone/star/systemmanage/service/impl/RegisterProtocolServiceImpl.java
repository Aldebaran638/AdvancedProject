package com.zeroone.star.systemmanage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.dto.j3.systemmanage.register.RegisterProtocolDTO;
import com.zeroone.star.systemmanage.entity.RegisterProtocolDO;
import com.zeroone.star.systemmanage.mapper.RegisterProtocolMapper;
import com.zeroone.star.systemmanage.service.RegisterProtocolService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import javax.xml.bind.annotation.XmlRegistry;

@Service
public class RegisterProtocolServiceImpl implements RegisterProtocolService {


    @Resource
    RegisterProtocolMapper registerProtocolMapper;
    @Override
    public int updateProtocol(RegisterProtocolDTO registerProtocolDTO) {
        RegisterProtocolDO registerProtocolDO = new RegisterProtocolDO();
        BeanUtil.copyProperties(registerProtocolDTO,registerProtocolDO);
        if(registerProtocolDO.getProtolcolId()==null){
            registerProtocolDO.setProtolcolId("1");
        }
        return registerProtocolMapper.updateRegisterProtocol(registerProtocolDO);
    }
}
