package com.zeroone.star.parkmanage.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

/**
 * @author neko
 * #Description：Swagger配置
 * #Date: 2025/5/19 18:13
 */
@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {
    @Bean
    Docket parkManageApi(){
        return SwaggerCore.defaultDocketBuilder("parkmanage","com.zeroone.star.parkmanage.controller","parkmanage");
    }
}
