package com.zeroone.star.parkmanage;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;
import org.springframework.context.annotation.Import;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;

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
@MapperScan("com.zeroone.star.parkmanage.mapper")
@EnableDiscoveryClient
@Import(EasyExcelComponent.class)
public class ParkManageApplication {
    public static void main(String[] args) {
        SpringApplication.run(ParkManageApplication.class, args);
    }
}
