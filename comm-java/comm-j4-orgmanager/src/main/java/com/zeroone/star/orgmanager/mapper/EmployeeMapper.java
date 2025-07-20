package com.zeroone.star.orgmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.orgmanager.entity.*;
import org.apache.ibatis.annotations.Mapper;
import com.zeroone.star.orgmanager.entity.UUser;
import com.zeroone.star.project.query.j4.orgmanager.employee.EmployeeQuery;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeListVO;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface EmployeeMapper extends BaseMapper<UUser> {

    UOrgStaffRel selectRelCdAndOrgId(String userId);

//    String selectOrg(String orgId);

    String selectJob(String relCd);

    PPrivilegeUser selectPIdAndStoreId(String userId);

    String selectAssociatedRoles(String pId);

    List<String> selectAssociatedCommunities(String storeId);

    String selectDomain(String pId);

//    List<String> selectAuthorities(String domain);

    int updateJob(String relCd, String job);

    String selectRelCd(String job);

    String selectOrgId(String associatedOrg);

    int insertUOrgStaffRel(UOrgStaffRel uOrgStaffRel);

    UOrg selectUOrg(String orgId);

    int insertFileRel(FileRel fileRel);

    int updateFileRel(String objId,String fileRealName,String fileSaveName);

    String getFileSaveName(String objId);

    List<EmpAuth> selectAuthOnPPrivilge(String domain);

    EmpAuth selectAuthOnMMenu(String mId);

    String selectAuthOnMMenuGroup(String gId);

    int insertSStoreUser(SStoreUser sStoreUser);

    int insertBusinessStoreUser(BusinessStoreUser businessStoreUser);

    /**
     * 分页多表联查员工列表
     * 服了兄弟们PageHelp和mybatisplus的分页冲突，mybatisplus的分页用不了！
     */
    List<EmployeeListVO> selectEmployeeList(@Param("q") EmployeeQuery query);

    String getRelCdByName(String job);

    String updateRelCd(String relCd,String userId);
}
