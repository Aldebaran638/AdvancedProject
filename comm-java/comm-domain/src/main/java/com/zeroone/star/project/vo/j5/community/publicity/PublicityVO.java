package com.zeroone.star.project.vo.j5.community.publicity;

import lombok.Data;

/**
 * ClassName: PublicityVo
 * Package: com.zeroone.star.project.vo.j5.community.publicity
 * Description:只保留前端需要展示的数据
 *
 * @Author 贾东伟
 * @Create 2025/5/25 23:14
 * @Version 1.0
 */
@Data
public class PublicityVO {
    private String pubId;
    private String title;
    private String pubType;
    private String headerImg;
    private String createTime;
    private String createUserName;
}
