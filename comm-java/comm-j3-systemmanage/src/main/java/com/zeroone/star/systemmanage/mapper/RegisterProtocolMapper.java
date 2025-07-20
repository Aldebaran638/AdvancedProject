package com.zeroone.star.systemmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j3.systemmanage.register.RegisterProtocolDTO;
import com.zeroone.star.systemmanage.entity.RegisterProtocolDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface RegisterProtocolMapper extends BaseMapper<RegisterProtocolDTO> {
    int updateRegisterProtocol(RegisterProtocolDO registerProtocolDO);
}
