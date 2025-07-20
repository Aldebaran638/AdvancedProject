package com.zeroone.star.dashboard.mapper;

import com.zeroone.star.dashboard.entity.Notepad;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.dashboard.entity.TDict;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author wunianwufeng
 * @since 2025-05-25
 */
@Mapper
public interface NotepadMapper extends BaseMapper<Notepad> {


    List<Notepad> selectList(String communityId);


}
