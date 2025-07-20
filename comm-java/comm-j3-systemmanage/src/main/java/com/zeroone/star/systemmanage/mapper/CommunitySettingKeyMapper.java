package com.zeroone.star.systemmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.vo.j3.systemmanage.communitysetting.CommunitySettingKeyVo;
import com.zeroone.star.systemmanage.entity.CommunitySettingKey;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * 小区设置值Mapper
 */
@Mapper
public interface CommunitySettingKeyMapper extends BaseMapper<CommunitySettingKey> {

    /**
     * 查询字典表和社区设置关联数据
     *
     * @return 字典设置数据列表
     */
    @Select("SELECT distinct csk.status_cd, csk.setting_type, t_dict.name " +
            "FROM t_dict " +
            "INNER JOIN community_setting_key csk " +
            "ON t_dict.status_cd = csk.setting_type " +
            "WHERE t_dict.table_name = 'community_setting_key' and csk.status_cd = '0'")
    List<CommunitySettingKeyVo> queryDictSettings();

}
