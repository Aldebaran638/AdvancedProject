package com.zeroone.star.cachemanage.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket cachemanageApi(){
        return SwaggerCore.defaultDocketBuilder("缓存管理模块","com.zeroone.star.cachemanage.controller","cachemanage");
    }
}
