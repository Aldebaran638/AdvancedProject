package com.zeroone.star.housemgt;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@EnableDiscoveryClient
public class HouseManagementApplication {
    public static void main(String[] args) {
        SpringApplication.run(HouseManagementApplication.class, args);
    }
}
