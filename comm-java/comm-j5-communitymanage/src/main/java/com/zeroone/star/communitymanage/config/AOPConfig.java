package com.zeroone.star.communitymanage.config;

import lombok.extern.slf4j.Slf4j;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

/**
 * 统计每个controller方法中的执行耗时情况
 */
@Aspect
@Component
@Slf4j
public class AOPConfig {
    @Pointcut("execution(* com.zeroone.star.communitymanage.controller.MyCommunityController.*(..))")
    public void pt(){}
    @Around("pt()")
    public Object longTime(ProceedingJoinPoint proceedingJoinPoint) throws Throwable{
        long startTime = System.currentTimeMillis();
        try {
            //执行目标方法
            Object result = proceedingJoinPoint.proceed();
            return result;
        } finally {
            long endTime = System.currentTimeMillis();
            long executionTime = endTime - startTime;
            //获取方法名
            String methodName = proceedingJoinPoint.getSignature().getName();
            log.info("{}方法执行耗时：{}ms",methodName,executionTime);
        }
    }
}
