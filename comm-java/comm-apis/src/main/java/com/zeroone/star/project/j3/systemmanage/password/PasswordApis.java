package com.zeroone.star.project.j3.systemmanage.password;

import com.zeroone.star.project.dto.j3.systemmanage.password.UserDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 修改密码接口
 */
public interface PasswordApis {
    /**
     * 修改密码
     * @param userDto 修改密码数据对象
     * @return 修改结果
     */
    JsonVO<String> modifyStaffPwd(UserDTO userDto);
}
