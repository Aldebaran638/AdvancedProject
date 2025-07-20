package com.zeroone.star.orgmanager.service.serviceImpl;

import com.zeroone.star.orgmanager.entity.Staff;
import com.zeroone.star.project.dto.j2.orgmanager.AddStaffDTO;
import com.zeroone.star.project.dto.j2.orgmanager.StaffDTO;
import org.mapstruct.Mapper;
/**
 * <p>
 * 描述：Staff对应的MapStruct映射接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 瓜田里犯了错
 * @version 1.0.0
 */
@Mapper(componentModel = "spring")
public interface MsStaffMapper {
    /**
     * 将实体类转换为DTO
     * @param sdo 实体类
     * @return 转换结果
     */
    StaffDTO staffToDto(Staff sdo);

    /**
     * 将Add DTO转换为实体类
     * @param dto Add DTO
     * @return 转换结果
     */
    Staff addDtoToDo(AddStaffDTO dto);

    /**
     * 将DTO转换为实体类
     * @param dto DTO
     * @return 转换结果
     */
    Staff dtoToDo(StaffDTO dto);
}
