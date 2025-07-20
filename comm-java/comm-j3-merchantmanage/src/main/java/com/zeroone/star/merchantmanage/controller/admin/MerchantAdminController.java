package com.zeroone.star.merchantmanage.controller.admin;

import com.zeroone.star.merchantmanage.service.admin.IMerchantAdminService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.MerchantAdminDTO;
import com.zeroone.star.project.dto.j3.merchantmanage.admin.UpdateStatusDTO;
import com.zeroone.star.project.j3.merchantmanage.admin.MerchantAdminApis;
import com.zeroone.star.project.query.j3.merchantmanage.admin.MerchantAdminQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import java.util.Objects;

@RestController
@RequestMapping("j3-merchant/merchant-admin")
@Api(tags = "商户管理员管理")
public class MerchantAdminController implements MerchantAdminApis {
    @Autowired
    private IMerchantAdminService merchantAdminService;
    /**
     * 获取商户管理员列表（条件+分页）
     * @param query 查询条件
     * @return 商户管理员信息列表
     */
    @Override
    @ApiOperation("获取商户管理员列表（条件+分页）")
    @GetMapping("/query")
    public JsonVO<PageDTO<MerchantAdminDTO>> queryMerchantAdmin(@Validated MerchantAdminQuery query) {

        // 调用服务层查询商户管理员信息
        PageDTO<MerchantAdminDTO> merchantAdminList = merchantAdminService.listAllMerchantAdmins(query);
        if(merchantAdminList == null || merchantAdminList.getTotal() == null || merchantAdminList.getTotal() == 0) {
            return JsonVO.create(null, 9999, "没有查询到商户管理员信息");
        }
        // 返回结果
        return JsonVO.success(merchantAdminList);

    }
    /**
     * 限制登录
     * @param updateStatusDTO 更新状态信息
     * @return 修改结果信息
     */
    @Override
    @ApiOperation("限制登录")
    @PutMapping("/modify-status")
    public JsonVO<String> modifyMerchantAdminStatus(@RequestBody UpdateStatusDTO updateStatusDTO) {
        // 参数校验
        if(updateStatusDTO == null ){
            return JsonVO.fail("请求体不能为空");
        }
        if(updateStatusDTO.getUserId() == null || updateStatusDTO.getUserId().isEmpty()) {
            return JsonVO.fail("用户ID不能为空");
        }
        if(updateStatusDTO.getStatus() == null || updateStatusDTO.getStatus().isEmpty()) {
            return JsonVO.fail("状态不能为空");
        }
        if(!Objects.equals(updateStatusDTO.getStatus(), "48001") && !Objects.equals(updateStatusDTO.getStatus(), "48002")) {
            return JsonVO.fail("状态值错误，请输入48001或48002");
        }
        // 调用服务层修改商户管理员状态
        int result = merchantAdminService.updateMerchantAdminStatus(updateStatusDTO);
        // 返回结果
        if(result == 0) {
            return JsonVO.fail("商户管理员状态更新失败");
        }
        return JsonVO.success("商户管理员状态更新成功");
    }
}
