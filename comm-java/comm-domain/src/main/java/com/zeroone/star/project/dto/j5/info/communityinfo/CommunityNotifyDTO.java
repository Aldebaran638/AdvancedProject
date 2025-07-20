package com.zeroone.star.project.dto.j5.info.communityinfo;

import lombok.AllArgsConstructor;
import lombok.Data;

@AllArgsConstructor
@Data
public class CommunityNotifyDTO {
    /**
     * 客户端编号
     */
    private String clientId;

    /**
     * 通知消息内容
     */
    private String message;
}