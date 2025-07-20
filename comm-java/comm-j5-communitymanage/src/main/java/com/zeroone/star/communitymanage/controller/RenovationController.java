package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.renovation.IRenovationService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationAddDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDTO;
import com.zeroone.star.project.j5.community.renovation.RenovationApis;
import com.zeroone.star.project.query.j5.community.renovation.RenovationQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.communitymanage.entity.renovation.RoomRenovation;
import com.zeroone.star.communitymanage.service.renovation.impl.MsRenovationMapper;
import io.swagger.annotations.*;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：房屋装修基础接口的控制器
 * </p>
 * @author 西班牙馅饼
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/renovation")
@Api(tags = "房屋装修")
public class RenovationController implements RenovationApis {

    @Resource
    IRenovationService service;

    @Resource
    MsRenovationMapper ms;

    @ApiOperation(value = "获取装修列表(条件+分页)")
    @GetMapping("/query")
    @Override
    @ApiResponses({
            @ApiResponse(code = 200, message = "查询成功"),
            @ApiResponse(code = 400, message = "参数校验失败", response = JsonVO.class),
            @ApiResponse(code = 401, message = "暂未登录或TOKEN已经过期"),
            @ApiResponse(code = 500, message = "系统内部错误", response = JsonVO.class)
    })
    public JsonVO<PageDTO<RenovationDTO>> queryRenovation(@Validated RenovationQuery query, String communityId) {
        return JsonVO.success(service.listAll(query, communityId));
    }

    @ApiOperation(value = "添加装修")
    @PostMapping("/add")
    @Override
    @ApiResponses({
            @ApiResponse(code = 200, message = "添加成功"),
            @ApiResponse(code = 400, message = "参数校验失败", response = JsonVO.class),
            @ApiResponse(code = 401, message = "暂未登录或TOKEN已经过期"),
            @ApiResponse(code = 403, message = "没有相关权限"),
            @ApiResponse(code = 409, message = "装修申请冲突", response = JsonVO.class),
            @ApiResponse(code = 500, message = "系统内部错误", response = JsonVO.class)
    })
    public JsonVO<String> addRenovation(@Validated @RequestBody RenovationAddDTO addDto) {
        RoomRenovation roomRenovation = ms.addDtoToRenovation(addDto);
        if(service.save(roomRenovation)) {
            return JsonVO.success(roomRenovation.getRId());
        }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "修改装修")
    @PutMapping("/modify")
    @Override
    @ApiResponses({
            @ApiResponse(code = 200, message = "修改成功"),
            @ApiResponse(code = 400, message = "参数校验失败", response = JsonVO.class),
            @ApiResponse(code = 404, message = "装修记录不存在", response = JsonVO.class),
            @ApiResponse(code = 403, message = "禁止修改", response = JsonVO.class),
            @ApiResponse(code = 500, message = "系统内部错误", response = JsonVO.class)
    })
    public JsonVO<String> modifyRenovation(@Validated @RequestBody RenovationDTO modifyDto) {
        if(service.updateRenoById(ms.DtoToRenovation(modifyDto))) {
            return JsonVO.success(modifyDto.getRId());
        }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "删除装修")
    @ApiImplicitParam(name = "rId", value = "装修编号", required = true)
    @DeleteMapping("/delete-by-id")
    @Override
    @ApiResponses({
            @ApiResponse(code = 200, message = "删除成功"),
            @ApiResponse(code = 400, message = "rId参数为空", response = JsonVO.class),
            @ApiResponse(code = 404, message = "装修记录不存在", response = JsonVO.class),
            @ApiResponse(code = 403, message = "禁止删除", response = JsonVO.class),
            @ApiResponse(code = 500, message = "系统内部错误", response = JsonVO.class)
    })
    public JsonVO<String> removeRenovation(@RequestParam @NotBlank(message = "rId不能为空") String rId) {
        if(service.removeById(rId)) {
            return JsonVO.success(rId);
        }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "审核装修")
    @ApiImplicitParams({
            @ApiImplicitParam(
                    name = "rId",
                    value = "主键id,装修编号",
                    required = true
            ),
            @ApiImplicitParam(
                    name = "state",
                    value = "审核通过 审核不通过",
                    required = true
            ),
            @ApiImplicitParam(
                    name = "examineRemark",
                    value = "审核备注",
                    required = false    // 非必填
            )
    })
    @GetMapping("/modify-state")
    @Override
    @ApiResponses({
            @ApiResponse(code = 200, message = "审核成功"),
            @ApiResponse(code = 400, message = "必填参数为空", response = JsonVO.class),
            @ApiResponse(code = 404, message = "装修记录不存在", response = JsonVO.class),
            @ApiResponse(code = 409, message = "状态冲突", response = JsonVO.class),
            @ApiResponse(code = 500, message = "系统内部错误", response = JsonVO.class)
    })
    public JsonVO<String> modifyRenoStatus(@RequestParam @NotBlank(message = "rId不能为空") String rId, @RequestParam @NotBlank(message = "state不能为空") String state, String examineRemark) {
        if(service.updateStatus(rId, state, examineRemark)) {
            return JsonVO.success(rId);
        }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "完成装修")
    @ApiImplicitParam(name = "rId", value = "装修编号", required = true)
    @GetMapping("/modify-by-id")
    @Override
    @ApiResponses({
            @ApiResponse(code = 200, message = "操作成功"),
            @ApiResponse(code = 400, message = "rId参数为空", response = JsonVO.class),
            @ApiResponse(code = 404, message = "装修记录不存在", response = JsonVO.class),
            @ApiResponse(code = 409, message = "状态冲突", response = JsonVO.class),
            @ApiResponse(code = 500, message = "系统内部错误", response = JsonVO.class)
    })
    public JsonVO<String> modifyRenoStatusById(@RequestParam @NotBlank(message = "rId不能为空") String rId) {
        if(service.updateByRId(rId)){
            return JsonVO.success(rId);
        }
        return JsonVO.fail(null);
    }
}
