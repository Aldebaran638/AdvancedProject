package com.zeroone.star.project.j3.merchantmanage.admin;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.MerchantAdminDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.UpdateStatusDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.message.MerchantDTO;
import com.zeroone.star.project.query.j3.merchantmanage.admin.MerchantAdminQuery;
import com.zeroone.star.project.query.j3.merchantmanage.message.MerchantQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 商户管理员相关API接口
 */
public interface MerchantAdminApis {
    /**
     * 查询商户管理员信息
     * @param query 查询条件
     * @return 商户管理员信息列表
     */
    JsonVO<PageDTO<MerchantAdminDTO>> queryMerchantAdmin(MerchantAdminQuery query);

    /**
     * 修改商户管理员信息
     * @param updateStatusDTO
     * @return 修改结果
     */
    JsonVO<String> modifyMerchantAdminStatus(UpdateStatusDTO updateStatusDTO);
}
