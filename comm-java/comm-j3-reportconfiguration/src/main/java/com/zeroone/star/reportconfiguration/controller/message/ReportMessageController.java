package com.zeroone.star.reportconfiguration.controller.message;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.ComponentRelDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.MessageAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.MessageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.ReportComponentRelDTO;
import com.zeroone.star.project.j3.reportconfiguration.message.ReportMessageApis;
import com.zeroone.star.project.query.j3.reportconfiguration.message.MessageQuery;
import com.zeroone.star.project.query.j3.reportconfiguration.message.ReportComponentRelQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.MessageVo;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.ReportComponentRelVo;
import com.zeroone.star.reportconfiguration.entity.Message;
import com.zeroone.star.reportconfiguration.service.IReportCustomComponentRelService;
import com.zeroone.star.reportconfiguration.service.ReportMessageService;
import com.zeroone.star.reportconfiguration.service.impl.MsMessageMapper;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("j3-report/report-message")
@Api(tags = "报表信息")
public class ReportMessageController implements ReportMessageApis {
    @Resource
    private MsMessageMapper ms;
    @Resource
    private ReportMessageService reportMessageService;
    @Resource
    private IReportCustomComponentRelService reportCustomComponentRel;

    @GetMapping("/query-all")
    @ApiOperation(value = "分页查询报表信息")
    @Override
    public JsonVO<PageDTO<MessageVo>> queryReportMessage(@Validated MessageQuery query) {
        PageDTO<MessageVo> voPageDTO = reportMessageService.listAll(query);
        if (voPageDTO.getRows().isEmpty()) {
            return JsonVO.fail(null);
        }
        return JsonVO.success(voPageDTO);
    }

    @PostMapping("/add-report-message")
    @ApiOperation(value = "新增报表信息")
    @Override
    public JsonVO<String> addReportMessage(@Validated @RequestBody MessageAddDTO addDto) {
        Message message = ms.addDtoToDo(addDto);
        if(reportMessageService.saveMessage(message)){
            return JsonVO.success(message.getCustomId());
        }
        return JsonVO.fail(null);
    }
    @GetMapping("/component-rel/pageList")
    @ApiOperation("分页获取关联组件列表")
    @Override
    public JsonVO<PageDTO<ReportComponentRelVo>> queryComponentRelPageList(@Validated ReportComponentRelQuery query) {

        PageDTO<ReportComponentRelVo> reportComponentRelVoPageDTO = reportCustomComponentRel.ComponentRelPageList(query);
        if (reportComponentRelVoPageDTO.getRows() == null || reportComponentRelVoPageDTO.getRows().isEmpty()) {
            return JsonVO.fail(null);
        }
        return JsonVO.success(reportComponentRelVoPageDTO);

    }

    @PostMapping("/save-component-rel")
    @ApiOperation("关联组件")
    @Override
    public JsonVO<String> saveComponentRel(@RequestBody ComponentRelDTO componentRelDTO) {

        return reportCustomComponentRel.saveComponentRel(componentRelDTO);
    }

    @DeleteMapping("/delete-component-rel")
    @ApiOperation("删除关联组件")
    @Override
    public JsonVO<String> deleteComponentRel(@RequestBody ReportComponentRelDTO componentRelDTO) {
        return reportCustomComponentRel.deleteComponentRel(componentRelDTO);
    }

    @ApiOperation(value = "修改报表信息")
    @PutMapping("/modify-report-message")
    @Override
    public JsonVO<String> modifyReportMessage(@RequestBody MessageDTO messageDTO) {
        // 参数校验
        if (messageDTO.getGroupId() == null || messageDTO.getGroupId().isEmpty()) {
            return JsonVO.fail("groupId参数不能为空");
        }
        if (!(messageDTO.getGroupId().equals("102021111007300001") || messageDTO.getGroupId().equals("102022022795370086") || messageDTO.getGroupId().equals("102022051141350637"))){
            return JsonVO.fail("groupId参数不存在");
        }
        if (reportMessageService.updateById(ms.dtoToDo(messageDTO))){
            return JsonVO.success("修改报表信息成功");
        }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "删除报表信息")
    @DeleteMapping("/delete-report-message")
    @Override
    public JsonVO<String> removeReportMessage(@RequestParam String customId) {
        if (reportMessageService.removeById(customId)){
            return JsonVO.success("删除报表信息成功");
        }
        return JsonVO.fail(null);
    }
}
