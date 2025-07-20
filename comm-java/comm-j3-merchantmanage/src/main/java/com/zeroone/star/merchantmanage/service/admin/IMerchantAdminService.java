package com.zeroone.star.merchantmanage.service.admin;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.MerchantAdminDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.UpdateStatusDTO;
import com.zeroone.star.project.query.j3.merchantmanage.admin.MerchantAdminQuery;

/**
 * 商户管理服务层
 *
 * @author wyr on 2025/5/26
 */
public interface IMerchantAdminService {

    /**
     * 获取商户管理员列表（条件+分页）
     *
     * @param query 查询条件
     * @return 商户管理员列表
     */
    PageDTO<MerchantAdminDTO> listAllMerchantAdmins(MerchantAdminQuery query);

    int updateMerchantAdminStatus(UpdateStatusDTO updateStatusDTO);
}
