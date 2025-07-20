package com.zeroone.star.patrolmgt;

import com.zeroone.star.patrolmgt.mapper.detail_InspectionTaskMapper;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.CommandLineRunner;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@MapperScan("com.zeroone.star.patrolmgt.mapper")
@EnableDiscoveryClient
public class PatrolManagementApplication {
    public static void main(String[] args) {
        SpringApplication.run(PatrolManagementApplication.class, args);
    }
}
