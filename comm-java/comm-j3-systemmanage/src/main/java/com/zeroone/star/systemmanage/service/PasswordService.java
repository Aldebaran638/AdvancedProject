package com.zeroone.star.systemmanage.service;

import com.zeroone.star.project.dto.j3.systemmanage.password.UserDTO;

import java.util.List;

public interface PasswordService {
    int updateStaffPwd(UserDTO userDTO);
    List<UserDTO> listUserByIdAndPwd(UserDTO userDTO);
}
