package com.zeroone.star.dashboard.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan({
        "com.zeroone.star.project.config.mybatis",
        "com.zeroone.star.project.config.redis"
})
public class ComponentInit {
}
