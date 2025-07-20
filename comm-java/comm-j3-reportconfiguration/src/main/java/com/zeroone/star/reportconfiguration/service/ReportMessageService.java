package com.zeroone.star.reportconfiguration.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j3.reportconfiguration.message.MessageQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.MessageVo;
import com.zeroone.star.reportconfiguration.entity.Message;

/**
 * <p>
 * 报表信息表 服务类
 * </p>
 *
 * @author maff
 * @since 2023-05-07
 */
public interface ReportMessageService extends IService<Message> {

    /**
     * 查询报表信息列表
     *
     * @param query 条件查询参数
     * @return 查询结果
     */
    PageDTO<MessageVo> listAll(MessageQuery query);


    /**
     * 新增报表信息
     *
     * @param message 报表信息
     * @return 是否添加成功
     */
    boolean saveMessage(Message message);


    /**
     * 校验 groupId 是否存在
     *
     * @param groupId 组ID
     * @return 是否存在
     */
    boolean existsByGroupId(String groupId);
}
