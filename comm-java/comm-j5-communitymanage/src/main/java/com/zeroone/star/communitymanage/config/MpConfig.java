package com.zeroone.star.communitymanage.config;

import com.baomidou.mybatisplus.core.handlers.MetaObjectHandler;
import com.zeroone.star.communitymanage.entity.notepad.NotePad;
import com.zeroone.star.communitymanage.entity.notepad.NotePadDetail;
import com.zeroone.star.project.components.user.UserHolder;
import org.apache.ibatis.reflection.MetaObject;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import javax.annotation.Resource;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：注入MyBaits Plus插件与配置
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Configuration
@ComponentScan("com.zeroone.star.project.config.mybatis")
public class MpConfig {

    @Resource
    UserHolder uh;

    @Bean
    public MetaObjectHandler metaObjectHandler() {
        return new MetaObjectHandler() {
            @Override
            public void insertFill(MetaObject metaObject) {
                // 插入时填充
                this.strictInsertFill(metaObject, "createTime", LocalDateTime.class, LocalDateTime.now());
                try {
                    String username = uh.getCurrentUser().getUsername();
                    String userId = uh.getCurrentUser().getId() + "";
                    this.strictInsertFill(metaObject, "createUserName", String.class, username);
                    this.strictInsertFill(metaObject, "createUserId", String.class, userId);

                    this.strictInsertFill(metaObject, "createBy", String.class, uh.getCurrentUser().getUsername());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }

            @Override
            public void updateFill(MetaObject metaObject) {
                // 更新时填充
                this.strictUpdateFill(metaObject, "updateTime", LocalDateTime.class, LocalDateTime.now());
                try {
                    this.strictUpdateFill(metaObject, "updateBy", String.class, uh.getCurrentUser().getUsername());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        };
    }
}
