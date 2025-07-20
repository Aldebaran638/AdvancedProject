package com.zeroone.star.communitymanage;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cache.annotation.EnableCaching;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.context.annotation.EnableAspectJAutoProxy;
import org.springframework.transaction.annotation.EnableTransactionManagement;

/**
 * 小区管理入口
 * @author yuezi
 * @version 1.0
 */
@SpringBootApplication
@EnableDiscoveryClient
@MapperScan("com.zeroone.star.communitymanage.mapper")
@EnableTransactionManagement
@EnableAspectJAutoProxy
@EnableCaching
public class CommunityManageApplication {
    public static void main(String[] args) {
        SpringApplication.run(CommunityManageApplication.class, args);
    }
}
