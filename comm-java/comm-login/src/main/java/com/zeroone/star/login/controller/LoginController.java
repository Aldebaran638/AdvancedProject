package com.zeroone.star.login.controller;

import cn.hutool.captcha.CaptchaUtil;
import cn.hutool.captcha.LineCaptcha;
import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import com.zeroone.cloud.oauth2.entity.Oauth2Token;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.constant.RedisConstant;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.dto.login.RefreshTokenDTO;
import com.zeroone.star.project.login.LoginApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.LoginVO;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import com.zeroone.star.project.vo.login.CaptchaVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 * 描述：登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestController
@RequestMapping("login")
@Api(tags = "login")
public class LoginController implements LoginApis {
    @Resource
    OauthService oAuthService;
    @Resource
    UserHolder userHolder;
    @Resource
    RedisTemplate<String, Object> redisTemplate;

    @Value("${zo.cloud.starter.oauth2.mgr-id}")
    String clientId;

    @Value("${zo.cloud.starter.oauth2.mgr-password}")
    String clientPassword;
    @Value("${zo.captcha.enabled:true}")
    Boolean captchaEnabled;

    @ApiOperation(value = "获取验证码")
    @GetMapping("captcha")
    @Override
    public JsonVO<CaptchaVO> getCaptcha() {
        try {
            // 自动生成UUID
            String uuid = java.util.UUID.randomUUID().toString();

            // 创建线性验证码
            LineCaptcha lineCaptcha = CaptchaUtil.createLineCaptcha(120, 40, 4, 10);

            // 获取验证码文本
            String code = lineCaptcha.getCode();

            // 将验证码保存到Redis，有效期5分钟
            redisTemplate.opsForValue().set(
                    RedisConstant.CAPTCHA_PREFIX + uuid,
                    code,
                    5,
                    TimeUnit.MINUTES
            );

            // 获取验证码图片的base64编码
            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            lineCaptcha.write(outputStream);
            byte[] imageBytes = outputStream.toByteArray();
            String base64Image = "data:image/png;base64," + java.util.Base64.getEncoder().encodeToString(imageBytes);

            // 构建返回对象
            CaptchaVO captchaVO = new CaptchaVO(uuid, base64Image);

            return JsonVO.success(captchaVO);
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "生成验证码失败：" + e.getMessage());
        }
    }

    @ApiOperation(value = "授权登录")
    @PostMapping("auth-login")
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {
        // 验证码验证（根据配置决定是否启用）
        if (captchaEnabled && StrUtil.isNotBlank(loginDTO.getCode())) {
            String cachedCode = (String) redisTemplate.opsForValue().get(
                    RedisConstant.CAPTCHA_PREFIX + loginDTO.getUuid()
            );

            if (StrUtil.isBlank(cachedCode)) {
                return JsonVO.create(null, ResultStatus.FAIL.getCode(), "验证码已过期");
            }

            if (!cachedCode.equalsIgnoreCase(loginDTO.getCode())) {
                return JsonVO.create(null, ResultStatus.FAIL.getCode(), "验证码错误");
            }

            // 验证通过后删除验证码
            redisTemplate.delete(RedisConstant.CAPTCHA_PREFIX + loginDTO.getUuid());
        }

        // 账号密码认证
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");
        params.put("client_id", clientId);
        params.put("client_secret", clientPassword);
        params.put("username", loginDTO.getUsername());
        params.put("password", loginDTO.getPassword());
        Oauth2Token oauth2Token = oAuthService.postAccessToken(params);

        // 认证失败
        if (oauth2Token.getErrorMsg() != null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), oauth2Token.getErrorMsg());
        }

        // 认证成功后记录凭证（用于注销功能）
        Oauth2TokenDTO tokenDTO = BeanUtil.toBean(oauth2Token, Oauth2TokenDTO.class);
        String accessToken = tokenDTO.getToken();
        if (StrUtil.isNotBlank(accessToken)) {
            // 将token标记为活跃状态，过期时间与token一致
            redisTemplate.opsForValue().set(
                    RedisConstant.LOGOUT_TOKEN_PREFIX + accessToken,
                    "active",
                    oauth2Token.getExpiresIn(),
                    TimeUnit.SECONDS
            );
        }

        // 响应认证成功数据
        return JsonVO.success(tokenDTO);
    }

    @ApiOperation(value = "刷新登录")
    @PostMapping("refresh-token")
    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(RefreshTokenDTO refreshTokenDTO) {
        // 获取当前token进行注销凭证验证
        String currentToken = userHolder.getCurrentToken();
        if (StrUtil.isNotBlank(currentToken)) {
            String tokenStatus = (String) redisTemplate.opsForValue().get(
                    RedisConstant.LOGOUT_TOKEN_PREFIX + currentToken
            );
            if (StrUtil.isBlank(tokenStatus) || !"active".equals(tokenStatus)) {
                return JsonVO.create(null, ResultStatus.FAIL.getCode(), "当前凭证已失效");
            }
        }

        // 刷新凭证
        Map<String, String> params = new HashMap<>(4);
        params.put("grant_type", "refresh_token");
        params.put("client_id", clientId);
        params.put("client_secret", clientPassword);
        params.put("refresh_token", refreshTokenDTO.getRefreshToken());
        Oauth2Token oauth2Token = oAuthService.postAccessToken(params);

        // 刷新失败
        if (oauth2Token.getErrorMsg() != null) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), oauth2Token.getErrorMsg());
        }

        // 刷新成功后更新注销凭证记录
        Oauth2TokenDTO newTokenDTO = BeanUtil.toBean(oauth2Token, Oauth2TokenDTO.class);
        String newAccessToken = newTokenDTO.getToken();
        if (StrUtil.isNotBlank(newAccessToken)) {
            // 删除旧token
            if (StrUtil.isNotBlank(currentToken)) {
                redisTemplate.delete(RedisConstant.LOGOUT_TOKEN_PREFIX + currentToken);
            }
            // 记录新token
            redisTemplate.opsForValue().set(
                    RedisConstant.LOGOUT_TOKEN_PREFIX + newAccessToken,
                    "active",
                    oauth2Token.getExpiresIn(),
                    TimeUnit.SECONDS
            );
        }

        // 响应刷新成功数据
        return JsonVO.success(newTokenDTO);
    }

    @ApiOperation(value = "获取当前用户")
    @GetMapping("current-user")
    @Override
    public JsonVO<LoginVO> getCurrUser() {
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if (currentUser == null) {
                // 用户未认证或token已注销，返回401状态码
                return JsonVO.create(null, 401, "未授权访问，请重新登录");
            }

            // 构建返回的用户信息
            LoginVO vo = new LoginVO();
            BeanUtil.copyProperties(currentUser, vo);

            // 确保启用状态有默认值
            if (vo.getIsEnabled() == null) {
                vo.setIsEnabled((byte) 1);
            }

            return JsonVO.success(vo);
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取用户信息失败：" + e.getMessage());
        }
    }

    @ApiOperation(value = "退出登录")
    @GetMapping("logout")
    @Override
    public JsonVO<String> logout() {
        try {
            // 获取当前请求的token
            String token = userHolder.getCurrentToken();
            if (token != null) {
                // 从Redis中删除token记录，实现真正的注销
                redisTemplate.delete(RedisConstant.LOGOUT_TOKEN_PREFIX + token);
                return JsonVO.success("退出成功");
            }
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取凭证失败，退出失败");
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "退出登录失败：" + e.getMessage());
        }
    }

    @Resource
    IMenuService menuService;

    @ApiOperation(value = "获取菜单")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<MenuTreeVO>> getMenus() throws Exception {
        try {
            // 1 获取当前用户
            UserDTO currentUser = userHolder.getCurrentUser();
            if (currentUser == null) {
                return JsonVO.create(null, ResultStatus.FAIL.getCode(), "未获取到用户信息");
            }

            // 2 检查用户是否有角色
            List<String> userRoles = currentUser.getRoles();
            if (userRoles == null || userRoles.isEmpty()) {
                return JsonVO.create(null, ResultStatus.FAIL.getCode(), "用户未分配角色");
            }

            // 3 根据用户角色获取有权访问的菜单
            List<MenuTreeVO> menus = menuService.listMenuByRoleName(userRoles);

            // 4 检查是否获取到菜单
            if (menus == null || menus.isEmpty()) {
                // 返回空菜单列表，不算错误
                return JsonVO.success(menus);
            }

            return JsonVO.success(menus);
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "获取菜单失败：" + e.getMessage());
        }
    }
}