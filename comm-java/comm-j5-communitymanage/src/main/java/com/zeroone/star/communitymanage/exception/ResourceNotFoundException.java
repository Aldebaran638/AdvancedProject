package com.zeroone.star.communitymanage.exception;

/**
 * @className: ResourceNotFoundException
 * @author: powfu
 * @date: 13/6/2025 下午4:05
 * @Version: 1.0
 * @description:
 */
public class ResourceNotFoundException extends RuntimeException{
    public ResourceNotFoundException(String message) {
        super(message);
    }
}
