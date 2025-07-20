package com.zeroone.star.reportconfiguration.service.impl;

import com.zeroone.star.project.dto.j3.reportconfiguration.message.MessageAddDTO;
import com.zeroone.star.project.dto.j3.reportconfiguration.message.MessageDTO;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.MessageVo;
import com.zeroone.star.reportconfiguration.entity.Message;
import org.mapstruct.Mapper;

@Mapper(componentModel = "spring")
public interface MsMessageMapper {
    /**
     * dto转message实体
     *
     * @param dto
     * @return
     */
    Message addDtoToDo(MessageAddDTO dto);

    /**
     * dto转message实体
     *
     * @param dto
     * @return
     */

    Message dtoToDo(MessageDTO dto);

    /**
     * 实体类转换为DTO
     * @param message
     * @return
     */
    MessageDTO messageToDto(Message message);

    /**
     * message实体转messageVo
     *
     * @param mdo
     * @return
     */
    MessageVo messageToVo(Message mdo);

    /**
     * dto转messageVo
     *
     * @param dto
     * @return
     */

    MessageVo addDtoToDo(MessageDTO dto);

}
