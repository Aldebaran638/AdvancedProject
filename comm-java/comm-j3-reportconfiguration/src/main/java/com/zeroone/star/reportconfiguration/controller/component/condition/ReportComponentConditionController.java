package com.zeroone.star.reportconfiguration.controller.component.condition;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCUpdateDTO;
import com.zeroone.star.project.j3.reportconfiguration.component.condition.ReportComponentConditionApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.query.j3.reportconfiguration.component.condition.RCCCQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.condition.RCCCVO;
import com.zeroone.star.reportconfiguration.service.IReportCustomComponentConditionService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cache.annotation.CacheEvict;
import org.springframework.cache.annotation.Cacheable;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;
/**
 * <p>
 *  报表组件设置条件
 * </p>
 *
 * @author 丁香与醋栗
 * @since 2025-05-19
 */
@Validated
@RestController
@RequestMapping("j3-report/report-component/condition")
@Api(tags ="报表组件")
@Slf4j
public class ReportComponentConditionController implements ReportComponentConditionApis {



    @Autowired
    private IReportCustomComponentConditionService reportCustomComponentConditionService;
    //获取条件列表（条件+分页）
    @ApiOperation(value = "获取条件列表（条件+分页）", notes = "返回条件列表,列表为空返回查询失败（null)")
    @GetMapping("query")
    @Cacheable(cacheNames = "REPORT_CUSTOM_COMPONENT_CONDITION_LIST", key = "#query", unless = "#result?.data?.total == 0 || #result.code != 200")
    public JsonVO<PageDTO<RCCCVO>> queryAll(@Validated RCCCQuery query) {
        PageDTO<RCCCVO> result = reportCustomComponentConditionService.getConditionList(query);
        log.info("获取条件列表成功"+result.toString());
        if (result != null && result.getTotal() > 0) {
            return JsonVO.success(result);
        } else {
            return JsonVO.fail(null);
        }
    }

    //添加条件
    @ApiOperation(value = "添加条件", notes = "返回条件id")
    @PostMapping("add")
    public JsonVO<String> addCondition(@Validated @RequestBody RCCCDTO rcccdto)
    {

        String result = reportCustomComponentConditionService.saveCondition(rcccdto);
        if(result!=null)
        {
            return JsonVO.success(result);
        }
        return JsonVO.fail(null);
    }
    @PutMapping("modify")
    @ApiOperation(value = "修改条件",notes = "返回条件id")
    @CacheEvict(cacheNames = "REPORT_CUSTOM_COMPONENT_CONDITION_LIST", key =  "#rcccdto.componentId")
    public JsonVO<String> modifyCondition(@Validated @RequestBody RCCCUpdateDTO rcccdto)
    {
        String result = reportCustomComponentConditionService.updateCondition(rcccdto);
        if(result != null)
        {
            return JsonVO.success(result);
        }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "删除条件")
    @DeleteMapping("remove/{id}")
    @CacheEvict(cacheNames = "REPORT_CUSTOM_COMPONENT_CONDITION_LIST", key =  "#rcccdto.componentId")
    //删除条件
    public JsonVO<String> removeCondition(@PathVariable String id)
    {
        reportCustomComponentConditionService.removeCondition(id);
        return JsonVO.success(null);
    }

}

