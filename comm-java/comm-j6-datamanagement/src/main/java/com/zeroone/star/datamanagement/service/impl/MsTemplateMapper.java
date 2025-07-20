package com.zeroone.star.datamanagement.service.impl;



import com.zeroone.star.datamanagement.entity.Template;
import com.zeroone.star.project.vo.j6.datamanagement.importtemplate.TemplateVO;

import org.mapstruct.Mapper;

/**
 * <p>
 * 描述：Template对应的MapStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsTemplateMapper {
    /**
     * 将实体类转换为vo
     * @param sdo 实体类
     * @return 转换结果
     */
    TemplateVO templateToVO(Template sdo);


}
