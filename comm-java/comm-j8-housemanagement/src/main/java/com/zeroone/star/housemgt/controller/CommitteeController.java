package com.zeroone.star.housemgt.controller;


import com.zeroone.star.housemgt.service.CommitteeService;
import com.zeroone.star.project.j8.housemgt.committee.CommitteeApis;
import com.zeroone.star.project.j8.housemgt.committee.dto.AddCommitteeDTO;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import javax.validation.constraints.NotBlank;

/**
 * 业委会管理 Controller
 */


@Api(tags = "业委会")
@RestController
@RequestMapping("j8-housemgt/committee")
public class CommitteeController implements CommitteeApis {

    private final CommitteeService committeeService;

    @Autowired
    public CommitteeController(CommitteeService committeeService) {
        this.committeeService = committeeService;
    }

    @Override
    @ApiOperation("添加业委会")
    @PostMapping("/add-committee")
    public JsonVO<String> addCommittee(@RequestBody @Valid AddCommitteeDTO addCommitteeDTO) {
        // 校验前端是否传了communityId
        if (addCommitteeDTO.getCommunityId() == null || addCommitteeDTO.getCommunityId().trim().isEmpty()) {
            //return JsonVO.fail(null);
            return JsonVO.create(null, 400, "添加业委会时，必须提供 communityId");
        }

        // 把DTO交给Service层
        return committeeService.addCommittee(addCommitteeDTO);
    }

    @Override
    @ApiOperation("修改业委会")
    @PutMapping("/modify-committee")
    public JsonVO<String> modifyCommittee(@RequestBody @Valid CommitteeDTO committeeDTO) {
        return committeeService.modifyCommittee(committeeDTO);
    }

    @Override
    @ApiOperation("删除业委会")
    @ApiImplicitParam(name = "ocId", value = "业委会编号（oc_id）", required = true, dataType = "String", paramType = "query")
    @DeleteMapping("/remove-committee")
    public JsonVO<String> removeCommittee(@RequestParam @NotBlank(message = "请输入业委会编号") String ocId) {
        return committeeService.removeCommittee(ocId);
    }

}
