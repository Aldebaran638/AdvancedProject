package com.zeroone.star.reportconfiguration.controller.component.count;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.count.CountAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.count.CountDTO;
import com.zeroone.star.project.j3.reportconfiguration.component.count.ReportComponentCountApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.reportconfiguration.entity.RCCCFooter;

import com.zeroone.star.reportconfiguration.service.impl.IReportCustomComponentCountServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：报表组件-底部统计
 * </p>
 * 实现了ReportComponentCountApis接口，提供报表组件底层统计的控制器功能
 *
 * @author Arthur
 * @version 1.0.0
 */
@RestController
@RequestMapping("j3-report/report-component-count")
@Api(tags = "组件底层统计")
public class ReportComponentCountController implements ReportComponentCountApis {
    
    @Resource
    private IReportCustomComponentCountServiceImpl countService;
    
    @ApiOperation(value = "查询报表组件底层统计列表")
    @GetMapping("/query-count")
    @Override
    public JsonVO<PageDTO<CountDTO>> queryCount(PageDTO pageDTO, String componentId) {
        // 调用Service层方法获取分页数据
        PageDTO<RCCCFooter> footerPageDTO = countService.listCoountFooterList(pageDTO, componentId);
        
        // 创建返回的DTO对象
        PageDTO<CountDTO> result = new PageDTO<>();
        result.setPageIndex(footerPageDTO.getPageIndex());
        result.setPageSize(footerPageDTO.getPageSize());
        result.setTotal(footerPageDTO.getTotal());
        
        // 转换实体对象为DTO
        List<CountDTO> dtoList = new ArrayList<>();
        for (RCCCFooter footer : footerPageDTO.getRows()) {
            CountDTO dto = new CountDTO();
            dto.setFooterId(footer.getFooterId());
            dto.setComponentId(footer.getComponentId());
            dto.setName(footer.getName());
            dto.setQueryModel(footer.getQueryModel());
            dto.setFooterDescription(footer.getRemark());
            dtoList.add(dto);
        }
        result.setRows(dtoList);
        
        // 返回成功结果
        return JsonVO.success(result);
    }
    
    @ApiOperation(value = "添加报表组件底层统计")
    @PostMapping("/add-count")
    @Override
    public JsonVO<String> addCount(@RequestBody CountAddDTO addDto) {
        // 调用Service层方法保存数据
        boolean success = countService.saveCondition(addDto);
        
        // 根据操作结果返回
        if (success) {
            return JsonVO.success("添加成功");
        } else {
            return JsonVO.fail("添加失败");
        }
    }
    
    @ApiOperation(value = "修改报表组件底层统计")
    @PutMapping("/modify-count")
    @Override
    public JsonVO<String> modifyCount(@RequestBody CountDTO dto) {
        // 调用Service层方法更新数据
        boolean success = countService.updateCondition(dto);
        
        // 根据操作结果返回
        if (success) {
            return JsonVO.success("修改成功");
        } else {
            return JsonVO.fail("修改失败");
        }
    }
    
    @ApiOperation(value = "删除报表组件底层统计")
    @DeleteMapping("/remove-count/{footerID}")
    @Override
    public JsonVO<String> removeCount(@PathVariable String footerID) {
        // 调用Service层方法删除数据
        boolean success = countService.deleteCondition(footerID);
        
        // 根据操作结果返回
        if (success) {
            return JsonVO.success("删除成功");
        } else {
            return JsonVO.fail("删除失败");
        }
    }
}
