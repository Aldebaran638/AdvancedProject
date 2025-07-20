package com.zeroone.star.parkmanage.service;

import com.zeroone.star.parkmanage.entity.OwnerAppUser;
import com.baomidou.mybatisplus.extension.service.IService;

import java.sql.Struct;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author daimon
 * @since 2025-06-02
 */
public interface IOwnerAppUserService extends IService<OwnerAppUser> {
    String getUserName(String communityId,String memberId);

    String getUserTel(String communityId, String memberId);
}
