package com.zeroone.star.parkmanage.config;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import com.baomidou.mybatisplus.core.incrementer.IdentifierGenerator;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import java.time.LocalDateTime;

/**
 * @author neko
 * #Description：注入Mybaits Plus插件与配置
 * #Date: 2025/5/19 18:17
 */
@Configuration
@ComponentScan("com.zeroone.star.project.config.mybatis")
public class MpConfig {

    @Bean
    public MetaObjectHandler metaObjectHandler() {
        return new MetaObjectHandler() {
            @Override
            public void insertFill(MetaObject metaObject) {
                // 插入时填充
                this.strictInsertFill(metaObject, "createTime", LocalDateTime.class, LocalDateTime.now());

                // 设置memberId等于carId（OwnerCar的字段）
//                setFieldValByName("memberId", getFieldValByName("carId", metaObject), metaObject);
            }
            @Override
            public void updateFill(MetaObject metaObject) {
                // 更新时填充
                this.strictUpdateFill(metaObject, "updateTime", LocalDateTime.class, LocalDateTime.now());

            }
        };
    }
}
