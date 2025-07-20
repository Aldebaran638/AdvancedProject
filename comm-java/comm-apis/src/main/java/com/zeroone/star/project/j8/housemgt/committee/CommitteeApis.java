package com.zeroone.star.project.j8.housemgt.committee;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.j8.housemgt.committee.dto.AddCommitteeDTO;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeDTO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;

/**
 * 业委会管理接口定义
 */
@Api(tags = "业委会管理")
public interface CommitteeApis {

    @ApiOperation("添加业委会")
    JsonVO<String> addCommittee(AddCommitteeDTO addCommitteeDTO);

    @ApiOperation("修改业委会")
    JsonVO<String> modifyCommittee(CommitteeDTO committeeDTO);

    @ApiOperation("删除业委会")
    @ApiImplicitParam(name = "ocId", value = "业委会编号（oc_id）", required = true, dataType = "String", paramType = "query")
    JsonVO<String> removeCommittee(String ocId);
}
