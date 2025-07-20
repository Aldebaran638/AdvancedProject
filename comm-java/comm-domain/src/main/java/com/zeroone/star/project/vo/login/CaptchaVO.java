package com.zeroone.star.project.vo.login;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * ClassName: CaptchaVO
 * Package: com.zeroone.star.project.vo.login
 * Description:
 *
 * @Author: FLFfang
 * @Create: 2025/5/30 - 22:29
 */
@ApiModel("验证码返回对象")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class CaptchaVO {
    @ApiModelProperty(value = "验证码", example = "a1b2c3d4-e5f6-7890-abcd-ef1234567890")
    private String uuid;

    @ApiModelProperty(value = "验证码图片", example = "data:image/png;base64,iVBORw0KGgoAAAANSU...")
    private String captchaImage;
}
