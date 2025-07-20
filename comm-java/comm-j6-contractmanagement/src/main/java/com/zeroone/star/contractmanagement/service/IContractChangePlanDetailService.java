package com.zeroone.star.contractmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.contractmanagement.entity.ContractChangePlanDetail;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractChangeDetailVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractPrintVO;

import java.util.List;

public interface IContractChangePlanDetailService extends IService<ContractChangePlanDetail> {

    JsonVO<List<ContractChangeDetailVO>> listChangeDetails(String planId);
}
