package com.zeroone.star.parkmanage.controller;

import com.zeroone.star.parkmanage.service.IParkingApplyService;
import com.zeroone.star.parkmanage.service.IParkingSpaceApplyService;
import com.zeroone.star.parkmanage.service.impl.MsParkingApplyMapper;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.AddApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ApplyDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ReviewApplicationDTO;
import com.zeroone.star.project.j7.parkmanage.ParkingApplyApis;
import com.zeroone.star.project.query.j7.parkmanage.parkingapply.GetParkingApplyQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * @author neko
 * #Description：车位申请控制器
 * #Date: 2025/5/19 18:23
 */
@RestController
@RequestMapping("/j7-park/park-manage/parking-apply")
@Api(tags = "车位申请")
public class ParkingApplyController implements ParkingApplyApis {
    @Resource
    IParkingApplyService service;

    @Resource
    MsParkingApplyMapper ms;

    @Autowired
    IParkingSpaceApplyService parkingApplyService;

    @ApiOperation(value = "添加申请")
    @PostMapping("add")
    @Override
    public JsonVO<String> addApply(@RequestBody AddApplyDTO addApplyDTO) {
       int rs= parkingApplyService.saveParkingApply(addApplyDTO);

        if(rs>0){
            return JsonVO.success("添加申请成功");
        }else {
            return JsonVO.fail("添加申请失败");
        }
    }
    @ApiOperation(value = "修改申请")
    @PostMapping("modify")
    @Override
    public JsonVO<String> modifyApply(@RequestBody ApplyDTO applyDTO) {
        int rs=parkingApplyService.updateParkingApply(applyDTO);
        if(rs>0){
            return JsonVO.success("修改申请成功");
        }else {
            return JsonVO.fail("修改申请失败");
        }
    }


    @ApiOperation(value = "删除申请")
    @DeleteMapping("remove")
    @ApiImplicitParam(name = "applyId", value = "申请id", required = true)
    @Override
    public JsonVO<String> removeApply(String applyId) {
        int rs=parkingApplyService.removeParkingApply(applyId);
        if(rs>0){
            return JsonVO.success("删除申请成功");
        }else {
            return JsonVO.fail("删除申请失败");
        }
    }





    @ApiOperation(value = "获取申请列表（分页+条件）")
    @GetMapping("query")
    @Override
    public JsonVO<PageDTO<ApplyDTO>> queryParkingApplyQuery(GetParkingApplyQuery query,String id, String applyPersonName, String carBrand){
        PageDTO<ApplyDTO> result = service.queryParkingApplyQuery(query,id,applyPersonName,carBrand);

        // 返回成功响应
        return JsonVO.success(result);

    }


    @ApiOperation(value = "审核申请")
    @PutMapping("review")
    @Override
    public JsonVO<String> reviewApplication(@RequestBody ReviewApplicationDTO reviewApplicationDTO) {
        JsonVO<String> result = parkingApplyService.reviewApplication(reviewApplicationDTO);
        return result;
    }
}
