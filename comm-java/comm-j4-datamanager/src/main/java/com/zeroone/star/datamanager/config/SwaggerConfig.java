package com.zeroone.star.datamanager.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * @Author: dashuai
 * @Description: Swagger配置信息
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket dataManagerApi(){
        return SwaggerCore.defaultDocketBuilder("数据管理模块", "com.zeroone.star.datamanager.controller", "datamanager");
    }
}
