package com.zeroone.star.systemmanage.controller.communitysetting;

import com.zeroone.star.project.dto.j3.systemmanage.communitysetting.UpdateCommunitySettingDTO;
import com.zeroone.star.project.j3.systemmanage.communitysetting.CommunitySettingApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingKeyVo;
import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingVo;
import com.zeroone.star.systemmanage.service.CommunitySettingKeyService;
import com.zeroone.star.systemmanage.service.CommunitySettingService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("j3-system/community-setting")
@Api(tags = "小区配置")
public class CommunitySettingController implements CommunitySettingApis {

    @Resource
    private CommunitySettingKeyService communitySettingKeyService;
    @Resource
    private CommunitySettingService communitySettingService;

    /**
     * 获取配置项列表
     * @param communityId 小区ID（必填）
     * @return
     */
    @ApiOperation(value = "获取配置项列表")
    @GetMapping("/query-communitysettingkey")
    @Override
    public JsonVO<List<CommunitySettingKeyVo>> queryCommunitySettingKeyList(
            @ApiParam(value = "小区ID", required = true, example = "2023052267100146") @RequestParam String communityId) {
        List<CommunitySettingKeyVo> data = communitySettingKeyService.queryCommunitySettingKeyList(communityId);
        return JsonVO.success(data);
    }

    /**
     * 获取配置项数据
     * @param communityId 小区ID（必填）
     * @param settingType 设置类型，用于筛选特定类别的配置项。
     * @return
     */
    @ApiOperation(value = "获取配置项数据")
    @GetMapping("/query-communitysetting")
    @Override
    public JsonVO<List<CommunitySettingVo>> queryCommunitySettingList(
            @ApiParam(value = "小区ID", required = true, example = "2023052267100146") @RequestParam String communityId,
            @ApiParam(value = "设置类型，用于筛选特定类别的配置项。例如：2002表示费用相关的配置项数据", required = true, example = "2002") @RequestParam String settingType) {

        List<CommunitySettingVo> result = communitySettingService.queryCommunitySettingList(communityId, settingType);
        return JsonVO.success(result);
    }

    /**
     * 提交配置项修改
     * @param updateCommunitySettingDTO 更新参数
     * @return
     */
    @ApiOperation(value = "提交配置项修改")
    @PutMapping("/modify-communitysetting")
    @Override
    public JsonVO<String> modifyCommunitySetting(@RequestBody UpdateCommunitySettingDTO updateCommunitySettingDTO) {
        if (updateCommunitySettingDTO == null || updateCommunitySettingDTO.getSettingItems() == null || updateCommunitySettingDTO.getSettingItems().isEmpty()) {
            return JsonVO.fail("修改参数不能为空");
        }
        String result = communitySettingService.updateCommunitySetting(updateCommunitySettingDTO.getSettingItems());
        return "success".equals(result) ? JsonVO.success("修改成功") : JsonVO.fail(result);
    }
}
