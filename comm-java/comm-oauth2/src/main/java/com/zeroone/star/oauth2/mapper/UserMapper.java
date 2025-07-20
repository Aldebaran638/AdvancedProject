package com.zeroone.star.oauth2.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oauth2.entity.User;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 用户表 Mapper 接口
 * </p>
 *
 * @author 阿伟
 */
@Mapper
public interface UserMapper extends BaseMapper<User> {
    
    /**
     * 根据用户ID查询关联的商店ID列表
     * @param userId 用户ID
     * @return 商店ID列表
     */
    List<String> selectStoreIdsByUserId(String userId);

}
