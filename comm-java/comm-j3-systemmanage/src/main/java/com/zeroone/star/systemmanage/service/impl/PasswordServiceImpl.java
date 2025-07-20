package com.zeroone.star.systemmanage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.project.dto.j3.systemmanage.password.UserDTO;
import com.zeroone.star.systemmanage.entity.UserDO;
import com.zeroone.star.systemmanage.mapper.PasswordMapper;
import com.zeroone.star.systemmanage.service.PasswordService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class PasswordServiceImpl implements PasswordService {
    @Resource
    PasswordMapper passwordMapper;
    @Override
    public int updateStaffPwd(UserDTO userDTO) {
        UserDO userDO = new UserDO();
        BeanUtil.copyProperties(userDTO,userDO);
        userDO.setPassword(userDTO.getNewPwd());
        int result = passwordMapper.updateStaffPwd(userDO);
        return result;
    }

    @Override
    public List<UserDTO> listUserByIdAndPwd(UserDTO userDTO) {
        UserDO userDO = new UserDO();
        BeanUtil.copyProperties(userDTO,userDO);
        List<UserDO> users = passwordMapper.selectList(new LambdaQueryWrapper<>(userDO));
        List<UserDTO> collect = users.stream().map(user -> {
            UserDTO newUserDTO = new UserDTO();
            newUserDTO.setUserId(user.getUserId());
            newUserDTO.setOldPwd(user.getPassword());
            return newUserDTO;
        }).collect(Collectors.toList());
        return collect;
    }
}
