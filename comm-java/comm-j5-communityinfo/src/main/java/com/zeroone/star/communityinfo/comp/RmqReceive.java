package com.zeroone.star.communityinfo.comp;

import com.zeroone.star.communityinfo.service.CommunityInfoQueryService;
import com.zeroone.star.project.dto.j5.info.communityinfo.CommunityNotifyDTO;
import com.zeroone.star.project.vo.j5.info.communityinfo.CommunityNameVO;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.util.List;
import java.util.Random;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 * 描述：消息接收组件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Slf4j
@Component
public class RmqReceive {

    @Resource
    private CommunityInfoQueryService infoQueryService;

    @StreamListener(Sink.INPUT)
    public void receiveNotify(CommunityNotifyDTO notify) {
        // log.info("接收到消息：{} 更新缓存信息", notify);
        infoQueryService.ListNotEnteredCommunityNameWithNoCache();
    }
}