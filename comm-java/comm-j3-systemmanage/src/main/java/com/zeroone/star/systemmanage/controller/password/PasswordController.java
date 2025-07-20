package com.zeroone.star.systemmanage.controller.password;

import cn.hutool.crypto.digest.DigestUtil;
import com.zeroone.star.project.dto.j3.systemmanage.password.UserDTO;
import com.zeroone.star.project.j3.systemmanage.password.PasswordApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanage.entity.UserDO;
import com.zeroone.star.systemmanage.service.PasswordService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.codec.cli.Digest;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("j3-system/password")
@Api(tags="修改密码")
@Slf4j
public class PasswordController implements PasswordApis {

    private static final String SALT = "hc@java110";
    @Resource
    PasswordService passwordService;

    @Override
    @PutMapping("/modify-staff-pwd")
    @ApiOperation("修改密码")
    public JsonVO<String> modifyStaffPwd(@RequestBody UserDTO userDto) {
        List<UserDTO> users = passwordService.listUserByIdAndPwd(userDto);
        if (users.size() == 0) {
            return JsonVO.fail("用户不存在！");
        }
        if (users.size() > 1) {
            return JsonVO.fail("数据错误，查询到多条用户信息！");
        }
        UserDTO user = users.get(0);
        if (!user.getOldPwd().equals(encode(userDto.getOldPwd()))) {
            return JsonVO.fail("旧密码错误！");
        }
        userDto.setNewPwd(encode(userDto.getNewPwd()));
        int result = passwordService.updateStaffPwd(userDto);
        if (result >= 0) {
                return JsonVO.success("修改密码成功！");
        } else {
                return JsonVO.fail("修改密码失败！");
            }
    }

    private String encode(String password){
        return DigestUtil.md5Hex(DigestUtil.md5Hex(password+SALT));
    }
}



