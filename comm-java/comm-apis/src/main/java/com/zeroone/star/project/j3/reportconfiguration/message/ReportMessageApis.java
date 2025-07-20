package com.zeroone.star.project.j3.reportconfiguration.message;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.ComponentRelDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.MessageAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.MessageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.ReportComponentRelDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.message.MessageQuery;
import com.zeroone.star.project.query.j3.reportconfiguration.message.ReportComponentRelQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.MessageVo;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.ReportComponentRelVo;
import org.springframework.validation.annotation.Validated;

import java.util.List;

public interface ReportMessageApis {

    /**
     * 分页查询报表信息
     *
     * @param query
     * @return
     */


    JsonVO<PageDTO<MessageVo>> queryReportMessage(@Validated MessageQuery query);
    /**
     * 新增报表信息
     *
     * @param addDto
     * @return
     */
    JsonVO<String> addReportMessage(MessageAddDTO addDto);


    /**
     * 分页查询报表组件关系
     * @param query
     * @return
     */
    public JsonVO<PageDTO<ReportComponentRelVo>>  queryComponentRelPageList( ReportComponentRelQuery query);


    /**
     * 对报表添加组件关系
     * @param componentRelDTO  添加信息
     * @return
     */
    public JsonVO<String> saveComponentRel(ComponentRelDTO componentRelDTO);

    /**
     * 删除报表组件关系
     * @param componentRelDTO 删除信息
     * @return
     */
    public JsonVO<String> deleteComponentRel(ReportComponentRelDTO componentRelDTO);

    /**
     * 修改报表信息
     * @param messageDTO 修改内容
     * @return
     */
    public JsonVO<String> modifyReportMessage(MessageDTO messageDTO);

    /**
     * 删除报表信息
     * @param customId 报表id
     * @return
     */
    public JsonVO<String> removeReportMessage(String customId);
}
