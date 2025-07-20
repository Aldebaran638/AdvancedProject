package com.zeroone.star.project.j3.systemmanage.register;

import com.zeroone.star.project.dto.j3.systemmanage.register.RegisterProtocolDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 注册协议接口
 */
public interface RegisterApis {
    /**
     * 修改注册协议
     * @param registerProtocolDto 修改注册协议数据对象
     * @return 修改结果
     */
    JsonVO<String> updateRegisterProtocol(RegisterProtocolDTO registerProtocolDto);
}
