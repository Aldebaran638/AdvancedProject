package com.zeroone.star.communitymanage.service.property;

import com.zeroone.star.project.dto.j5.community.property.AddPropertyDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyCheckDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyDetailDTO;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author Jungle
 * @since 2025-05-23
 */
public interface IPropertyUpdateService {
    String saveProperty(AddPropertyDTO dto);

    //删除产权登记
    String remove(String prrId);

    //修改产权登记
    String updateProperty(PropertyDTO propertyDTO);

    //审核产权登记
    String checkPrr(PropertyCheckDTO checkDTO);

    //修改附件项
    String updatePrrd(PropertyDetailDTO propertyDetailDTO);

}
