package com.zeroone.star.communityinfo.comp;

import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityNotifyDTO;
import org.springframework.cloud.stream.messaging.Source;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：消息发布组件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
public class RmqPublish {

    @Resource
    Source source;

    public boolean publishNotify(CommunityNotifyDTO notify) {
        return source.output().send(MessageBuilder.withPayload(notify).build());
    }
}
