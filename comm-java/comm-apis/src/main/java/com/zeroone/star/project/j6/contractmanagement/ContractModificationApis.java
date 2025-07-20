package com.zeroone.star.project.j6.contractmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contractmodification.ContractChangePlanDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contractmodification.ContractChangeListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractChangeDetailVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractChangeListVO;

import java.util.List;

/*
 *描述 ：合同变更接口
 *Author:28768
 */
public interface ContractModificationApis {


    /**
     * 获取合同变更列表（条件+分页）
     */
    public JsonVO<PageDTO<ContractChangeListVO>> listContractChanges(ContractChangeListQuery query);

    /**
     * 查看变更明细
     */
    public JsonVO<List<ContractChangeDetailVO>> listChangeDetails(String planId);


    /**
     * 资产变更 主体变更 租期调整
     *
     * @param contractChangePlanDTO 修改数据
     * @return 修改结果
     */
    JsonVO<Boolean> modifyContractChangePlan(ContractChangePlanDTO contractChangePlanDTO);
}
