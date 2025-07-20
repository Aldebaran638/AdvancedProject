package com.zeroone.star.merchantmanage.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.MerchantAdminDTO;
import com.zeroone.star.project.query.j3.merchantmanage.admin.MerchantAdminQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * 商户管理员Mapper层
 *
 * @author wyr on 2025/5/26
 */
@Mapper
public interface MerchantAdminMapper {
    /**
     * 获取商户管理员列表（条件+分页）
     * @param page
     * @param query
     * @return
     */
    Page<MerchantAdminDTO> listAllMerchantAdmins(@Param("page") Page<MerchantAdminDTO> page,@Param("query") MerchantAdminQuery query);

    /**
     * 更新商户管理员状态
     * @param status
     * @param userId
     * @return
     */
    int updateMerchantAdminStatus(String status, String userId);
}
