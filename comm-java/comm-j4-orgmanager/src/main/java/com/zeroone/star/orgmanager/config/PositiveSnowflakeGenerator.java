package com.zeroone.star.orgmanager.config;

import java.util.concurrent.atomic.AtomicLong;

public class PositiveSnowflakeGenerator {
    // 起始时间戳（2020-01-01 00:00:00 UTC）
    private static final long START_TIMESTAMP = 1577836800000L; // 修正：移除多余的0

    // 位数配置（总长度=13位时间戳 + 4位机器ID + 1位序列号 = 18位）
    private static final long MACHINE_ID_BITS = 4L;   // 机器ID范围：0-15（16台机器）
    private static final long SEQUENCE_BITS = 1L;     // 序列号范围：0-1（每毫秒2个ID）

    private static final long MAX_MACHINE_ID = (1L << MACHINE_ID_BITS) - 1; // 15
    private static final long MAX_SEQUENCE = (1L << SEQUENCE_BITS) - 1;     // 1

    private static final long TIMESTAMP_SHIFT = MACHINE_ID_BITS + SEQUENCE_BITS;
    private static final long MACHINE_ID_SHIFT = SEQUENCE_BITS;

    private static final AtomicLong sequence = new AtomicLong(0);
    private static final AtomicLong lastTimestamp = new AtomicLong(-1L);

    private final long machineId;

    public PositiveSnowflakeGenerator(long machineId) {
        if (machineId < 0 || machineId > MAX_MACHINE_ID) {
            throw new IllegalArgumentException("Machine ID must be between 0 and " + MAX_MACHINE_ID);
        }
        this.machineId = machineId;
    }

    public synchronized String createUUID() {
        long currentTimestamp = System.currentTimeMillis();

        // 日志输出（用于调试）
        System.out.println("当前时间戳: " + currentTimestamp);
        System.out.println("起始时间戳: " + START_TIMESTAMP);

        // 处理时钟回拨（容忍2秒内的回拨）
        if (currentTimestamp < lastTimestamp.get()) {
            long offset = lastTimestamp.get() - currentTimestamp;
            if (offset <= 2000) { // 容忍2秒内的时钟回拨
                System.out.println("时钟回拨警告，将使用上一时间戳: " + offset + " 毫秒");
                currentTimestamp = lastTimestamp.get();
            } else {
                throw new RuntimeException("时钟回拨超过2秒，拒绝生成ID: " + offset + " 毫秒");
            }
        }

        if (currentTimestamp == lastTimestamp.get()) {
            // 同一毫秒内，序列号递增
            long newSequence = (sequence.incrementAndGet()) & MAX_SEQUENCE;
            if (newSequence == 0) {
                // 序列号溢出，等待下一毫秒
                currentTimestamp = waitNextMillis(currentTimestamp);
            }
        } else {
            // 新的毫秒，重置序列号
            sequence.set(0);
        }

        lastTimestamp.set(currentTimestamp);

        // 计算时间部分（确保为正数）
        long timePart = currentTimestamp - START_TIMESTAMP;
        if (timePart < 0) {
            throw new IllegalArgumentException("当前时间早于起始时间: " +
                    new java.util.Date(currentTimestamp) + " < " +
                    new java.util.Date(START_TIMESTAMP));
        }

        // 生成64位ID
        long id = (timePart << TIMESTAMP_SHIFT) |
                (machineId << MACHINE_ID_SHIFT) |
                sequence.get();

        // 转换为18位字符串（取绝对值确保为正数）
        return String.format("%018d", Math.abs(id) % 1000000000000000000L);
    }

    private long waitNextMillis(long lastTimestamp) {
        long timestamp = System.currentTimeMillis();
        while (timestamp <= lastTimestamp) {
            timestamp = System.currentTimeMillis();
        }
        return timestamp;
    }
}