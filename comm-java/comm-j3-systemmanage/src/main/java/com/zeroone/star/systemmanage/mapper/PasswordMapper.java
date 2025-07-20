package com.zeroone.star.systemmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.systemmanage.entity.UserDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface PasswordMapper extends BaseMapper<UserDO> {
    int updateStaffPwd(UserDO userDO);
}
