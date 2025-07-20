package com.zeroone.star.communityinfo;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.cloud.stream.messaging.Source;

/**
 * 小区信息入口
 * @author yuezi
 * @version 1.0
 */
@SpringBootApplication
@EnableDiscoveryClient
@MapperScan("com.zeroone.star.communityinfo.mapper")
@EnableBinding({Source.class, Sink.class})
public class CommunityInfoApplication {
    public static void main(String[] args) {
        SpringApplication.run(CommunityInfoApplication.class, args);
    }
}
