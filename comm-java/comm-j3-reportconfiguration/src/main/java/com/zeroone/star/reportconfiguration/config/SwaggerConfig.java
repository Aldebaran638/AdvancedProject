package com.zeroone.star.reportconfiguration.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {

    @Bean
    Docket reportconfigurationApi(){
        return SwaggerCore.defaultDocketBuilder("报表配置","com.zeroone.star.reportconfiguration.controller","reportconfiguration");
    }
}
