package com.zeroone.star.contractmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.contractmanagement.entity.ContractChangePlan;
import com.zeroone.star.contractmanagement.entity.ContractChangePlanDetail;
import com.zeroone.star.contractmanagement.mapper.ContractChangePlanDetailMapper;
import com.zeroone.star.contractmanagement.mapper.ContractChangePlanMapper;
import com.zeroone.star.contractmanagement.service.IContractChangePlanDetailService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractChangeDetailVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.ContractPrintVO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

@Service
public class ContractChangePlanDetailServiceImpl extends ServiceImpl<ContractChangePlanDetailMapper, ContractChangePlanDetail>
        implements IContractChangePlanDetailService {

    @Resource
    private ContractChangePlanMapper contractChangePlanMapper;
    @Resource
    private  ContractChangePlanDetailMapper contractChangePlanDetailMapper;

    @Override
   public JsonVO<List<ContractChangeDetailVO>> listChangeDetails(String planId) {
        // 2. 构建查询条件
        QueryWrapper<ContractChangePlanDetail> wrapper = new QueryWrapper<>();
        wrapper.eq("plan_id", planId);

        // 3. 查询数据列表
        List<ContractChangePlanDetail> contractChangePlanDetails = contractChangePlanDetailMapper.selectList(wrapper);
        ContractChangePlan contractChangePlan = contractChangePlanMapper.selectById(planId);
        List<ContractChangeDetailVO> contractChangeDetailVOS = new ArrayList<>();
        for(int i = 0;i<contractChangePlanDetails.size();i++){
            ContractChangeDetailVO contractChangeDetailVO = new ContractChangeDetailVO();
            BeanUtils.copyProperties(contractChangePlanDetails.get(i),contractChangeDetailVO);
            contractChangeDetailVO.setPlanType(contractChangePlan.getPlanType());
            switch (contractChangePlan.getPlanType()){
                case "1001":
                    contractChangeDetailVO.setPlanTypeName("主体变更");
                    break;
                case "2002":
                    contractChangeDetailVO.setPlanTypeName("租期调整");
                    break;
                case "3003":
                    contractChangeDetailVO.setPlanTypeName("资产调整");
                    break;
                case "4004":
                    contractChangeDetailVO.setPlanTypeName("费用标准调整");
                    break;
                case "5005":
                    contractChangeDetailVO.setPlanTypeName("退约管理");
                    break;
                case "6006":
                    contractChangeDetailVO.setPlanTypeName("续约管理");
                    break;
            }
            contractChangeDetailVOS.add(contractChangeDetailVO);
        }
    return JsonVO.success(contractChangeDetailVOS);
    }


}