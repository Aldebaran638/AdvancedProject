package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.renovation.IRenovationDetailService;
import com.zeroone.star.communitymanage.service.renovation.IRenovationRecordService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.renovation.AddRenovationRecordDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDetailDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationRecordDTO;
import com.zeroone.star.project.j5.community.renovation.RenovationRecordApis;
import com.zeroone.star.project.query.j5.community.renovation.RenovationDetailQuery;
import com.zeroone.star.project.query.j5.community.renovation.RenovationRecordQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.*;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：房屋装修跟进记录的控制器
 * </p>
 * @author 天干勿躁
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/renovation-record")
@Api(tags = "房屋装修")
@Validated
public class RenovationRecordController implements RenovationRecordApis {

    @Resource
    IRenovationRecordService renovationRecordService;
    @Resource
    IRenovationDetailService renovationDetailService;

    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

    @Resource
    FastDfsClientComponent dfs;

    @ApiOperation(value = "获取跟进记录列表（条件+分页）")
    @GetMapping("/queryPage")
    @Override
    public JsonVO<PageDTO<RenovationRecordDTO>> queryRenovationRecord(@Validated  RenovationRecordQuery query) {
        return JsonVO.success(renovationRecordService.listRenovationRecord(query));
    }

    @ApiOperation(value = "添加跟进记录")
    @PutMapping("/add")
    @Override
    public JsonVO<String> addRenovationRecord(@Validated @RequestBody AddRenovationRecordDTO dto) {
        if(renovationRecordService.saveRenovationRecord(dto)) {
            return JsonVO.success("添加成功");
        }
        return JsonVO.fail("添加失败");
    }
    @ApiOperation(value = "删除跟进记录")
    @DeleteMapping("/delete")
    @ApiImplicitParams({
             @ApiImplicitParam(name = "recordId", value = "装修跟踪记录id", required = true, dataType = "String",example = "172025051967580002"),
             @ApiImplicitParam(name = "communityId", value = "小区id", required = true, dataType = "String",example =  "2023052267100146")
    })
    @Override
    public JsonVO<String> deleteRenovationRecord(String recordId,String communityId) {
        if (renovationRecordService.removeRenovationRecord(recordId)){
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败，记录不存在");
    }

    @ApiOperation(value = "查看跟进记录详情")
    @GetMapping("/queryDetail")
    @Override
    public JsonVO<PageDTO<RenovationDetailDTO>> queryRenovationRecordDetail(@Validated RenovationDetailQuery query) {
        return JsonVO.success(renovationRecordService.listRenovationRecordDetail(query));
    }

}
