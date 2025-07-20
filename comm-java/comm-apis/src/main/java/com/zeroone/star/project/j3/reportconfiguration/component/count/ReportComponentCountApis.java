package com.zeroone.star.project.j3.reportconfiguration.component.count;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.count.CountAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.component.count.CountDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：报表组件-底部统计
 * </p>
 *
 *
 * @author Arthur
 * @version 1.0.0
 */
public interface ReportComponentCountApis {
    
    /**
     * 底层统计查询
     * @param pageDTO 分页参数
     * @param componentId 组件ID
     * @return 底部统计列表
     */
    JsonVO<PageDTO<CountDTO>> queryCount(PageDTO pageDTO, String componentId);
    
    /**
     * 底层统计新增
     * @param addDto 新增数据
     * @return 新增结果
     */
    JsonVO<String> addCount(CountAddDTO addDto);
    
    /**
     * 底层统计修改
     * @param dto 修改数据
     * @return 修改结果
     */
    JsonVO<String> modifyCount(CountDTO dto);
    
    /**
     * 底层统计删除
     * @param countID 删除数据
     * @return 修改结果
     */
    JsonVO<String> removeCount(String footerID);
    
}
