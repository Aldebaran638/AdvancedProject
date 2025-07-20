package com.zeroone.star.project.j4.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.orgmanager.PersonnelScheduleQuery;
import com.zeroone.star.project.vo.j4.orgmanager.PersonnelSchedulingVO;
import io.swagger.annotations.ApiOperation;

/**
 * @Author: dashuai
 * @Description:
 * 包含：获取人员排班列表（条件+分页）
 *
 * 负责人：
 * 頹
 */
public interface SchedulingTableApis {
    /*获取人员排班列表（条件+分页）
     *@param schedule
     *@return
     */
    @ApiOperation("获取人员排班列表（条件+分页）")
    PageDTO<PersonnelSchedulingVO> getpagePersonnelSchedulingList(PersonnelScheduleQuery query);
}
