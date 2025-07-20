package com.zeroone.star.merchantmanage.config;

import com.zeroone.star.project.config.swagger.SwaggerCore;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2WebMvc;

@Configuration
@EnableSwagger2WebMvc
public class SwaggerConfig {

    @Bean
    Docket merchantmanageApi(){
        return SwaggerCore.defaultDocketBuilder("商户管理模块","com.zeroone.star.merchantmanage.controller","merchantmanage");
    }
}
