package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.publicity.PublicityUpdateService;
import com.zeroone.star.project.dto.j5.community.publicity.AddPublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.DeletePublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.UpdatePublicityDTO;
import com.zeroone.star.project.j5.community.publicity.PublicityUpdateApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiResponse;
import io.swagger.annotations.ApiResponses;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：小区公示查询的控制器
 * </p>
 *
 * @author 语
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/property")
@Api(tags = "小区公示")
@Validated
public class PublicityUpdateController implements PublicityUpdateApis {

    @Resource
    PublicityUpdateService publicityUpdateService;

    /**
     * @description: 添加公示的数据对象
     * @title: addPublicity
     * @param: [dto]
     */
    @Override
    @PostMapping("/add-publicity")
    @ApiOperation("添加公示")
    @ApiResponses({
            @ApiResponse(code = 200, message = "添加成功"),
            @ApiResponse(code = 400, message = "请求参数错误"),
            @ApiResponse(code = 500, message = "服务器内部错误")
    })
    public JsonVO<String> addPublicity(@Validated @RequestBody AddPublicityDTO addPublicityDTO) {
        try {
            publicityUpdateService.add(addPublicityDTO);
            return JsonVO.success("添加成功");
        } catch (RuntimeException e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    /**
     * @description: 修改公示的数据对象
     * @title: updatePublicity
     * @param: [dto]
     */
    @Override
    @PostMapping("/modify-publicity")
    @ApiOperation("修改公示")
    @ApiResponses({
            @ApiResponse(code = 200, message = "添加成功"),
            @ApiResponse(code = 400, message = "请求参数错误"),
            @ApiResponse(code = 500, message = "服务器内部错误")
    })
    public JsonVO<String> modifyPublicity(@Validated @RequestBody UpdatePublicityDTO updatePublicityDTO) {
        try {
            publicityUpdateService.update(updatePublicityDTO);
            return JsonVO.success("修改成功");
        } catch (RuntimeException e) {
            return JsonVO.fail(e.getMessage());
        }
    }

    /**
     * @description: 删除公示的数据对象
     * @title: deletePublicity
     * @param: [dto]
     */
    @Override
    @PostMapping("/remove-publicity")
    @ApiOperation("删除公示")
    @ApiResponses({
            @ApiResponse(code = 200, message = "添加成功"),
            @ApiResponse(code = 400, message = "请求参数错误"),
            @ApiResponse(code = 500, message = "服务器内部错误")
    })
    public JsonVO<String> removePublicity(@Validated @RequestBody DeletePublicityDTO deletePublicityDTO) {
        try {
            publicityUpdateService.remove(deletePublicityDTO);
            return JsonVO.success("删除成功");
        } catch (RuntimeException e) {
            return JsonVO.fail(e.getMessage());
        }
    }
}
