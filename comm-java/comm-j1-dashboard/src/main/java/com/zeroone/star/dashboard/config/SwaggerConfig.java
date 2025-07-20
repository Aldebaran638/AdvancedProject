package com.zeroone.star.dashboard.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket DashboardApi() {
        return SwaggerCore.defaultDocketBuilder("控制面板", "com.zeroone.star.dashboard.controller", "dashboard");
    }
}

