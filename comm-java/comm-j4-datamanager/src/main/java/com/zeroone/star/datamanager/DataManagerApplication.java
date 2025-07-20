package com.zeroone.star.datamanager;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
/**
 * <p>
 * 描述：程序启动入口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@SpringBootApplication
@MapperScan(basePackages = "com.zeroone.star.datamanager.mapper")
public class DataManagerApplication {

    public static void main(String[] args) {
        SpringApplication.run(DataManagerApplication.class, args);
    }

}
