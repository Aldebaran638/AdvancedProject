package com.zeroone.star.project.j6.contractmanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractPrintDTO;
import com.zeroone.star.project.query.j6.contractmanagement.draftcontract.ContractQuery;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.*;

/*
 *描述 ：起草合同接口
 *Author:28768
 */
public interface DraftContractApis {

    /**
     * 获取合同列表（条件+分页）
     * @param condition 查询条件（含分页参数）
     * @return 分页列表数据
     */
    JsonVO<PageDTO<ContractListVO>> queryContractList(ContractQuery condition);


    /**
     * 选择合同列表（条件+分页）
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<ContractListVO>> selectContractList(ContractQuery condition);

    /**
     * 获取合同详情
     * @param id 合同id
     * @return 合同详情
     */
    JsonVO<ContractDTO> queryById(String id);

    /**
     * 获取合同附件
     * @param condition 分页参数
     * @return 合同详情
     */
    JsonVO<PageDTO<ContractFileVo>> queryFiles(ContractQuery condition);



    /**
     * 获取合同修改记录（条件+分页）
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<ContractChangePlanVO>> listContractChangePlanById(ContractQuery condition);




    /**
     * 起草合同
     */
    JsonVO<Boolean> addContract(ContractDTO contractDTO);


    /**
     * 修改合同
     */
    JsonVO<Boolean> modifyContract(ContractDTO contractDTO);

    /**
     * 删除合同
     */
    JsonVO<Boolean> deleteContract(String contractId);

    /**
     * 打印合同
     * @param dto
     * @return
     */
    public JsonVO<ContractPrintVO> createPrintTask( ContractPrintDTO dto);

}
