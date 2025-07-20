package com.zeroone.star.reportconfiguration.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.j3.reportconfiguration.message.MessageQuery;
import com.zeroone.star.project.vo.j3.reportconfiguration.message.MessageVo;
import com.zeroone.star.reportconfiguration.entity.Message;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface MessageMapper extends BaseMapper<Message> {
    Page<MessageVo> selectWithGroup(@Param("page") Page<Message> page, @Param("query") MessageQuery query);

    /**
     * 查询是否存在指定的 groupId
     *
     * @param groupId 组ID
     * @return 是否存在
     */
    boolean existsByGroupId( @Param("groupId")String groupId);
}
