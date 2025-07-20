package com.zeroone.star.merchantmanage.service.admin;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.merchantmanage.mapper.MerchantAdminMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.MerchantAdminDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.UpdateStatusDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.message.MerchantDTO;
import com.zeroone.star.project.query.j3.merchantmanage.admin.MerchantAdminQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

/**
 * 商户管理服务层实现
 *
 * @author wyr on 2025/5/26
 */
@Service
public class MerchantAdminServiceImpl implements IMerchantAdminService{
    @Autowired
    private MerchantAdminMapper merchantAdminMapper;
    /**
     * 获取商户管理员列表（条件+分页）
     * @param query 查询条件
     * @return
     */
    @Override
    public PageDTO<MerchantAdminDTO> listAllMerchantAdmins(MerchantAdminQuery query) {
        // 1. 创建 Mybatis-Plus 的分页对象
        Page<MerchantAdminDTO> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 2. 调用 Mapper 的分页查询方法，获取原始数据
        Page<MerchantAdminDTO> resultPage = merchantAdminMapper.listAllMerchantAdmins(page, query);

        // 3. 处理查询结果，为每个 MerchantAdminDTO 实例设置 statusText
        List<MerchantAdminDTO> dtoList = resultPage.getRecords().stream()
                .map(dto -> {
                    // 根据 status 字段的值设置 statusText
                    switch (dto.getStatus()) {
                        case "48001":
                            dto.setStatusText("商户正常状态");
                            break;
                        case "48002":
                            dto.setStatusText("限制商户登录");
                            break;
                    }
                    return dto;
                })
                .collect(Collectors.toList());

        // 4. 将处理后的列表设置回 Page 对象
        resultPage.setRecords(dtoList);

        // 5. 使用 PageDTO.create 静态方法构建返回结果
        return PageDTO.create(resultPage);
    }

    /**
     * 更新商户管理员状态
     * @param updateStatusDTO 更新状态信息
     * @return 修改结果信息
     */
    @Override
    public int updateMerchantAdminStatus(UpdateStatusDTO updateStatusDTO) {
        //获取状态和用户ID
        String status = updateStatusDTO.getStatus();
        String userId = updateStatusDTO.getUserId();
        //调用Mapper层方法更新状态
        int update = merchantAdminMapper.updateMerchantAdminStatus(status, userId);
        if (update > 0) {
            return 1;
        } else {
            return 0;
        }
    }
}
