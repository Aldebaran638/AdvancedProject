package com.zeroone.star.project.j5.community.property;

import com.zeroone.star.project.dto.j5.community.property.*;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.annotations.ApiParam;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.RequestBody;

/**
 * <p>
 * 描述：产权登记接口
 *      Jungle : 添加房屋产权、修改房屋产权、修改附件项、删除房屋产权、审核房屋产权
 * </p>
 * @author Jungle
 * @version 1.0.0
 */
public interface PropertyUpdateApis {

    /**
     * 添加房屋产权
     */
    JsonVO<String> addProperty(AddPropertyDTO addDto);

    /**
     * 删除房屋产权
     */
    JsonVO<String> removeProperty(PropertyDeleteDTO propertyDeleteDTO);

    /**
     * 修改房屋产权
     */
    JsonVO<String> modifyProperty(PropertyDTO propertyDto);

    /**
     * 修改附件项
     */
    JsonVO<String> modifyFileRel(@Validated @RequestBody PropertyDetailDTO propertyDetailDTO);

    /**
     * 审核房屋产权
     */
    JsonVO<String> checkProperty(@Validated @RequestBody PropertyCheckDTO checkDTO);

}
