package com.zeroone.star.oauth2.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.oauth2.entity.Store;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface StoreMapper extends BaseMapper<Store> {

    /**
     * 通过用户编号查询角色名称列表
     * @param userId 用户编号
     * @return 角色名称列表
     */
    @Select("SELECT " +
            "    st.* " +
            "FROM " +
            "    u_user uu " +
            "INNER JOIN " +
            "    s_store_user ssu ON uu.user_id = ssu.user_id " +
            "INNER JOIN " +
            "    s_store ss ON ssu.store_id = ss.store_id " +
            "INNER JOIN " +
            "    store_type st ON ss.store_type_cd = st.store_type_cd " +
            "WHERE " +
            "    uu.user_id = #{userId}")
    List<Store> selectRolesByUserId(int userId);

    /**
     * 通过菜单路径获取对应的角色
     * @param path 菜单路径
     * @return 角色列表
     */
    @Select("SELECT st.* FROM m_menu mu INNER JOIN m_menu_user mmu ON mmu.m_id = mu.m_id INNER JOIN s_store WHERE mu.url = ${path}")
    List<Store> selectByMenuPath(String path);
}
