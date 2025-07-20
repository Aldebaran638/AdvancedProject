package com.zeroone.star.patrolmgt.controller;

import com.zeroone.star.patrolmgt.service.IInspectionTaskDetailService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.detail.DetailApis;
import com.zeroone.star.project.j8.patrolmgt.detail.dto.DetailDTO;
import com.zeroone.star.project.j8.patrolmgt.detail.query.DetailQuery;
import com.zeroone.star.project.j8.patrolmgt.detail.vo.DetailVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

@RestController
@RequestMapping("j8-patrolmgt/detail")
@Api(tags = "巡检明细")
public class DetailController implements DetailApis {

    @Resource
    IInspectionTaskDetailService inspectionTaskDetailService;

    @ApiOperation("获取巡检明细列表（条件+分页）")
    @GetMapping("/query-detail-list")
    @Override
    public JsonVO<PageDTO<DetailDTO>> queryDetail(DetailQuery query) {
        PageDTO<DetailDTO> res = inspectionTaskDetailService.queryAll(query);
        if(res != null){
            return JsonVO.success(res);
        }else {
            return JsonVO.fail(null);
        }
    }
}
