package com.zeroone.star.reportconfiguration.controller.component;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.RCCDeleteDTO;
import com.zeroone.star.project.j3.reportconfiguration.component.ReportComponentApis;
import com.zeroone.star.project.query.j3.reportconfiguration.component.RCCQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.RCCVO;
import com.zeroone.star.reportconfiguration.service.IReportCustomComponentService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.validation.constraints.NotNull;


/**
 * <p>
 * 描述：报表组件
 * </p>
 *
 *
 * @author huicheng
 * @version 1.0.0
 */



@RestController
@RequestMapping("j3-report/report-component")
@Api(tags = "报表组件")
public class ReportComponentController implements ReportComponentApis {

    @Autowired
    private IReportCustomComponentService rccService;

    @ApiOperation(value = "获取报表组件列表(条件+分页)")
    @GetMapping("/query")
    @Override
    public JsonVO<PageDTO<RCCVO>> queryComponent( RCCQuery query) {
        PageDTO<RCCVO> result=rccService.queryRCC(query);
        if(result!=null){
            return JsonVO.success(result);
        }

        return JsonVO.fail(null);
    }

    @ApiOperation(value = "添加报表组件")
    @PostMapping("/add")
    @Override
    public JsonVO<String> addComponent(@RequestBody RCCAddDTO componentAddDTO) {
        // 参数校验
        if (componentAddDTO == null) {
            return JsonVO.fail("请求参数不能为空");
        }

        String result = rccService.saveRCC(componentAddDTO);

        // 判断结果是否为ID（假设ID是数字）
        if (result != null && !result.isEmpty() && result.matches("\\d+")) {
            return JsonVO.success(result);
        }

        // 如果result为null或空，使用默认错误消息
        String errorMsg = (result == null || result.isEmpty()) ? "操作失败" : result;
        return JsonVO.fail(errorMsg);
    }

    @ApiOperation(value = "修改报表组件")
    @PutMapping("/modify")
    @Override
    public JsonVO<String> modifyComponent(@RequestBody RCCDTO componentDTO) {
        if(componentDTO==null){
            return JsonVO.fail("请求参数不能为空");
        }
        String result=rccService.updateRCC(componentDTO);
        if(result!=null&& result.matches("\\d+")){
            return JsonVO.success(result);
        }
        String errorMsg=(result == null || result.isEmpty())?"操作失败" : result;
        return JsonVO.fail(errorMsg);
    }

    @ApiOperation(value = "删除报表组件")
    @DeleteMapping("/delete")
    @Override
    public JsonVO<String> removeComponent(@RequestBody RCCDeleteDTO rccDeleteDTO) {
        String result=rccService.deleteRCC(rccDeleteDTO);
        if(result!=null&& result.matches("\\d+")){
            return JsonVO.success(result);
        }
        String errorMsg=(result == null || result.isEmpty())?"操作失败" : result;
        return JsonVO.fail(errorMsg);
    }
}
