package com.zeroone.star.menumana.config;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import java.time.LocalDateTime;

/**
 * \* @author cv
 * \* Time: 2025/5/20 + 16:37
 * \* Description:
 * \
 */

@Configuration
@ComponentScan("com.zeroone.star.project.config.mybatis")
public class MpConfig {
    @Bean
    public MetaObjectHandler metaObjectHandler() {
        return new MetaObjectHandler() {

            @Override
            public void insertFill(MetaObject metaObject) {
                //插入时填充
                this.strictInsertFill(metaObject,"createTime", LocalDateTime.class, LocalDateTime.now());
            }

            @Override
            public void updateFill(MetaObject metaObject) {
            }
        };
    }

}
