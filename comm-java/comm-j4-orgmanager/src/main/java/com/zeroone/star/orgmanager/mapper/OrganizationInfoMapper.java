package com.zeroone.star.orgmanager.mapper;

import com.zeroone.star.orgmanager.entity.UOrg;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.vo.j4.orgmanager.ClassOrganizationVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Result;
import org.apache.ibatis.annotations.Results;
import org.apache.ibatis.annotations.Select;

import javax.annotation.Resource;
import java.util.List;
/**
 * @Author: Alisa
 * @Description : 修改组织
 */
@Mapper
public interface OrganizationInfoMapper {

    /**
     * 根据组织ID获取组织树信息
     * @return 组织信息列表
     */
    List<UOrg> selectOrganizationTreeByOrgId(String userId);

}
