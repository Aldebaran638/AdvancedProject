package com.zeroone.star.project.j3.reportconfiguration.component.condition;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.condition.RCCCUpdateDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.component.condition.RCCCQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.reportconfiguration.component.condition.RCCCVO;
import org.springframework.web.bind.annotation.RequestBody;

public interface ReportComponentConditionApis {
    /**
     * 查询所有条件列表（分页）
     *
     * 该方法用于根据传入的查询条件对象 RCCCQuery 分页查询 RCCC 数据，并返回封装了分页数据的 JsonVO 对象。
     *
     * @param query 包含查询条件的对象
     * @return 返回一个 JsonVO 对象，其中包含分页结果 PageDTO<RCCCVO>
     */
    public JsonVO<PageDTO<RCCCVO>> queryAll( RCCCQuery query);

    /**
     * 添加条件
     *
     * 该方法用于添加新的 RCCC 条目，接收一个 RCCCDTO 对象作为请求体。
     *
     * @param condition 包含新增数据信息的对象
     * @return 返回一个 JsonVO 对象，表示操作结果，组件id,数据部分为 String 类型，
     */
    public JsonVO<String> addCondition(@RequestBody RCCCDTO condition);

    /**
     * 更新条件
     *
     * 该方法用于更新已有的 RCCC 条目，接收一个 RCCCDTO 对象作为请求体。
     *
     * @param rcccdto 包含更新数据信息的对象
     * @return 返回一个 JsonVO 对象，表示操作结果，组件id，数据部分为 String 类型，通常用于返回成功或错误信息
     */
    public JsonVO<String> modifyCondition(@RequestBody RCCCUpdateDTO rcccdto);

    // 删除条件
    public JsonVO<String> removeCondition(String id);
}
