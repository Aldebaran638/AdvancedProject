package com.zeroone.star.communitymanage.utils;

/**
 * @description: 雪花算法的工具类
 * @author: yu
 * @data 2025年05月23日 20:29
 */
public class IdUtil {
    private static final SnowflakeIdGenerator generator = new SnowflakeIdGenerator(1, 1);

    public static String getSnowflakeId() {
        return String.valueOf(generator.nextId());
    }
}
