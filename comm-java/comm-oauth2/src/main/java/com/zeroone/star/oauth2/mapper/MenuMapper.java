package com.zeroone.star.oauth2.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oauth2.entity.Menu;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 菜单 Mapper 接口
 * </p>
 *
 * @author 阿伟
 */
@Mapper
public interface MenuMapper extends BaseMapper<Menu> {
    /**
     * 获取所有菜单的链接地址
     * @return 菜单列表
     */
    List<Menu> selectAllLinkUrl();
}
