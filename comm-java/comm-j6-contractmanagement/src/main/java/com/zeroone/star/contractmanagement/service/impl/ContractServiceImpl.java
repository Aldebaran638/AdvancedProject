package com.zeroone.star.contractmanagement.service.impl;


import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.core.toolkit.CollectionUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.contractmanagement.entity.*;
import com.zeroone.star.contractmanagement.mapper.*;
import com.zeroone.star.contractmanagement.service.IContractService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contractmodification.ContractChangePlanDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.contractmodification.ContractRoomDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractDTO;
import com.zeroone.star.project.dto.j6.contractmanagement.draftcontract.ContractPrintDTO;
import com.zeroone.star.project.query.j6.contractmanagement.contractmodification.ContractChangeListQuery;
import com.zeroone.star.project.query.j6.contractmanagement.draftcontract.ContractQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeSpecVO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeTemplateVO;
import com.zeroone.star.project.vo.j6.contractmanagement.draftcontract.*;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Lazy;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Service
public class ContractServiceImpl extends ServiceImpl<ContractMapper, Contract> implements IContractService {
    @Resource
    private ContractMapper contractMapper;
    @Resource
    private ContractTypeMapper contractTypeMapper;

    @Resource
    @Lazy
    private UserHolder userHolder;

    @Resource
    private SStoreMapper sStoreMapper;
    @Resource
    private MsContractMapper msContractMapper;

    @Resource
    private ContractChangePlanMapper contractChangePlanMapper;

    @Resource
    private ContractChangePlanDetailMapper contractChangePlanDetailMapper;

    @Resource
    private ContractRoomMapper contractRoomMapper;

    @Resource
    private   ContractChangePlanRoomMapper contractChangePlanRoomMapper;

    @Resource
    private ContractFileMapper contractFileMapper;

    @Resource
    private MsContractRoomMapper msContractRoomMapper;

    @Autowired
    private ContractTypeSpecMapper contractTypeSpecMapper;

    @Resource
    private MsContractTypeSpecMapper msContractTypeSpecMapper;
    @Resource
    private ContractTypeTemplateMapper contractTypeTemplateMapper;

    @Resource
    private MsContractTypeTemplateMapper msContractTypeTemplateMapper;



    @SneakyThrows
    @Override
    public JsonVO<PageDTO<ContractListVO>> listContract(ContractQuery cquery) {
        // 构造条件
        QueryWrapper<Contract> wrapper = new QueryWrapper<>();
        //TODO 需要storeid
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        wrapper.eq("c.store_id",storeId);

        if(StringUtils.isNotEmpty(cquery.getContractId())){
            wrapper.eq("c.contract_id",cquery.getContractId());
        }

        if (StringUtils.isNotEmpty(cquery.getContractName())) {
            wrapper.like("Contract_name", cquery.getContractName());
        }

        if (StringUtils.isNotEmpty(cquery.getContractCode())) {
            wrapper.like("Contract_code", cquery.getContractCode());
        }

        if (StringUtils.isNotEmpty(cquery.getContractType())) {
            wrapper.eq("Contract_type", cquery.getContractType());
        }

        // 全查（含 contract_type + contract_file 的一个 file_real_name、file_save_name）
        List<ContractListVO> list = baseMapper.selectContractInfo(wrapper);

        // 手动分页
        int total = list.size();
        int fromIndex = (int) Math.min((cquery.getPageIndex() - 1) * cquery.getPageSize(), total);
        int toIndex = (int) Math.min(fromIndex + cquery.getPageSize(), total);
        List<ContractListVO> pagedList = list.subList(fromIndex, toIndex);

        // 查询附件信息（额外补充）
        List<String> contractIds = pagedList.stream()
                .map(ContractListVO::getContractId)
                .filter(StringUtils::isNotBlank)
                .distinct()
                .collect(Collectors.toList());

        List<ContractFile> fileList = contractFileMapper.selectFilesByContractIds(contractIds);

        // 按 contract_id 分组
        Map<String, List<AttrFileVO>> fileMap = fileList.stream()
                .collect(Collectors.groupingBy(
                        ContractFile::getContractId,
                        Collectors.mapping(f -> {
                            AttrFileVO vo = new AttrFileVO();
                            vo.setFileRealName(f.getFileRealName());
                            vo.setFileSaveName(f.getFileSaveName());
                            return vo;
                        }, Collectors.toList())
                ));

        // 回填 attrs 字段
        for (ContractListVO vo : pagedList) {
            vo.setAttrs(fileMap.getOrDefault(vo.getContractId(), new ArrayList<>()));
        }

        // 封装分页对象
        PageDTO<ContractListVO> pageDTO = new PageDTO<>();
        pageDTO.setRows(pagedList);
        pageDTO.setTotal((long) total);
        pageDTO.setPageIndex(cquery.getPageIndex());
         pageDTO.setPageSize(cquery.getPageSize());
        return JsonVO.success(pageDTO);

    }
    @Override
    public ContractDTO getContractById(String id) {
        //非空判断
        if(StringUtils.isEmpty(id)){
            throw new RuntimeException("合同id不能为空");
        }
        ContractDTO contractDTO = new ContractDTO();
           Contract contract = contractMapper.selectById(id);
           // 获取合同类型名称
           ContractType contractType = contractTypeMapper.selectById(contract.getContractType());
           BeanUtils.copyProperties(contract, contractDTO);
           contractDTO.setContractType(contractType.getTypeName());
           //TODO 没有获取附件
        return contractDTO;

    }

    @Override
    public PageDTO<ContractSelectVO> listSelectContract(ContractQuery contractQuery) {
        //构建wrapper
        LambdaQueryWrapper<Contract> wrapper = new LambdaQueryWrapper<>();
         wrapper.like(Contract::getContractName, contractQuery.getContractName());
        List<Contract> contracts = contractMapper.selectList(wrapper);
        //查询
        Page<Contract> page = new Page<>(contractQuery.getPageIndex(), contractQuery.getPageSize());
        Page<Contract> pageResult = baseMapper.selectPage(page, wrapper);
        PageDTO<ContractSelectVO> contractSelectVOPageDTO = PageDTO.create(pageResult, ContractSelectVO.class);
        return contractSelectVOPageDTO;
    }

    @Override
    public PageDTO<ContractFileVo> getFilesById(ContractQuery condition) {
        //非空判断
        if(StringUtils.isEmpty(condition.getContractId())){
            throw new RuntimeException("合同id不能为空");
        }
        condition.setPageIndex(condition.getPageIndex()-1);
        List<ContractFileVo> list = contractMapper.selectFilesById(condition);
        Page<ContractFileVo> pageResult = new Page<>(condition.getPageIndex(),condition.getPageSize());
        pageResult.setRecords(list);
        return PageDTO.create(pageResult);
    }

    @Override
    public PageDTO<ContractChangePlanVO> listContractChangePlanById(ContractQuery condition) {
        //非空判断
        if(StringUtils.isEmpty(condition.getContractId())){
            throw new RuntimeException("合同id不能为空");
        }
        //查找基本数据
        List<ContractChangePlanVO> ContractChangePlanVOS = contractMapper.selectContractChangePlansById(condition);
        Page<ContractChangePlanVO> pageResult = new Page<>(condition.getPageIndex(),condition.getPageSize());
        //补充其他数据
        for (ContractChangePlanVO record : ContractChangePlanVOS) {
            record.setContractTypeName(contractTypeMapper.selectById(record.getContractType()).getTypeName());
            //TODO changePersonName测试不了，需要页面修改合同，有了记录才能测试
            //需要联查，我直接写了，后面有别人写的再改
            SStore sStore = sStoreMapper.selectById(record.getStoreId());
            record.setChangePersonName(sStore.getName());
            //typeId转名称，找不到表，应该是这样
            //变更类型,1001 主体变更,2002租期调整,3003资产调整,4004费用标准调整,5005退约管理,6006续约管理
            switch (record.getPlanType()){
                case "1001": record.setPlanTypeName("主体变更"); break;
                case "2002": record.setPlanTypeName("租期调整"); break;
                case "3003": record.setPlanTypeName("资产调整"); break;
                case "4004": record.setPlanTypeName("费用标准调整"); break;
                case "5005": record.setPlanTypeName("退约管理"); break;
                case "6006": record.setPlanTypeName("续约管理"); break;
            }
            //state转Name同理
            //11 待审核 22 审核通过 33 审核失败
            switch (record.getState()){
                case "11": record.setStateName("待审核"); break;
                case "22": record.setStateName("审核通过"); break;
                case "33": record.setStateName("审核失败"); break;
            }
        }
        //封装返回
        pageResult.setRecords(ContractChangePlanVOS);
        return PageDTO.create(pageResult);
    }


    /**
     * 合同变更
     * @param dto
     * @return
     */
    @SneakyThrows
    @Override
    @Transactional
    public Contract updateyContractChangePlan(ContractChangePlanDTO dto)  {
        // 1、根据dto，添加ContractChangePlan表字段信息
        ContractChangePlan changePlan = new ContractChangePlan();
        BeanUtils.copyProperties(dto, changePlan);
        changePlan.setChangePerson(userHolder.getCurrentUser().getId());//TODO 这里需要修改userid
        changePlan.setRemark(dto.getChangeRemark());
        changePlan.setStatusCd("0");
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }
        changePlan.setStoreId(storeId);//TODO 这里需要修改storeId
        int row = contractChangePlanMapper.insert(changePlan);
        // 2、根据contractId查询变更之前的合同，并且将获取到的合同信息插入ContractChangePlanDetail表，operate设置为DEL
        Contract oldContract = baseMapper.selectById(dto.getContractId());
        if (oldContract != null && row > 0) {
            ContractChangePlanDetail delDetail = new ContractChangePlanDetail();
            BeanUtils.copyProperties(oldContract, delDetail);
            delDetail.setContractId(dto.getContractId());
            delDetail.setPlanId(changePlan.getPlanId());
            delDetail.setCreateTime(LocalDateTime.now());
            delDetail.setOperate("DEL");
            contractChangePlanDetailMapper.insert(delDetail);
        }
        // 3、根据dto，修改contract表中的contract_name 、party_a、party_b、a_contracts、a_link、b_contracts、b_link这几个字段信息
        Contract newContract = new Contract();
        assert oldContract != null;
        BeanUtils.copyProperties(oldContract, newContract);
        BeanUtils.copyProperties(dto, newContract);

        newContract.setStartUserId(userHolder.getCurrentUser().getId());//TODO 这里需要修改userid
        baseMapper.updateById(newContract);



        // 4、根据dto，添加ContractChangePlanDetail表字段信息，operate设置为ADD
        if (row > 0) {
            ContractChangePlanDetail addDetail = new ContractChangePlanDetail();
            addDetail.setContractId(dto.getContractId());
            BeanUtils.copyProperties(newContract, addDetail);
            addDetail.setPlanId(changePlan.getPlanId());
            addDetail.setCreateTime(LocalDateTime.now());
            addDetail.setOperate("ADD");
            contractChangePlanDetailMapper.insert(addDetail);
        }

        //资产变更部分
        if (dto.getPlanType().equals("3003")) {
            //查询ContractRoom信息列表
            QueryWrapper<ContractRoom> queryWrapper = new QueryWrapper<ContractRoom>()
                    .eq("contract_id", dto.getContractId())
                    .eq("status_cd", "0");
            List<ContractRoom> contractRoomList = contractRoomMapper.selectList(queryWrapper);

            //将ContractRoom列表中的信息，复制到ContractChangePlanRoom表中,并且将status_cd置为1
            List<ContractChangePlanRoom> contractChangePlanRoomList = new ArrayList<>();
            for (ContractRoom contractRoom : contractRoomList) {
                ContractChangePlanRoom changePlanRoom = new ContractChangePlanRoom();
                BeanUtils.copyProperties(contractRoom, changePlanRoom);
                changePlanRoom.setPlanId(changePlan.getPlanId());
                changePlanRoom.setOperate("DEL");
                contractChangePlanRoomList.add(changePlanRoom);
            }

            //将ContractChangePlanRoom列表，插入ContractChangePlanRoom表中
            if (!contractChangePlanRoomList.isEmpty()) {
                contractChangePlanRoomMapper.insertBatchSomeColumn(contractChangePlanRoomList);
            }

            //根据合同id将ContractRoom中的status_cd置为1
            UpdateWrapper<ContractRoom> updateWrapper = new UpdateWrapper<>();
            updateWrapper.eq("contract_id", dto.getContractId())
                    .set("status_cd", "1");
            contractRoomMapper.update(null, updateWrapper);

            //将dto中的rooms数据循环赋值给ContractChangePlanRoom和ContractRoom
            List<ContractChangePlanRoom> contractChangePlanRoomListADD = new ArrayList<>();
            for (ContractRoomDTO roomDTO : dto.getRooms()) {
                ContractChangePlanRoom changePlanRoom = new ContractChangePlanRoom();
                BeanUtils.copyProperties(roomDTO, changePlanRoom);
                changePlanRoom.setPlanId(changePlan.getPlanId());
                changePlanRoom.setOperate("ADD");
                contractChangePlanRoomListADD.add(changePlanRoom);
            }
            if (!contractChangePlanRoomListADD.isEmpty()) {
                contractChangePlanRoomMapper.insertBatchSomeColumn(contractChangePlanRoomListADD);
            }

            List<ContractRoom> contractRoomListADD = new ArrayList<>();
            for (ContractChangePlanRoom contractChangePlanRoom : contractChangePlanRoomListADD) {
                ContractRoom contractRoom = new ContractRoom();
                BeanUtils.copyProperties(contractChangePlanRoom, contractRoom);
                contractRoom.setStatusCd("0");
                contractRoomMapper.insert(contractRoom);
                contractRoomListADD.add(contractRoom);
            }

            /// 将 contractRoomListADD 插入到数据库中
            if (!CollectionUtils.isEmpty(contractRoomListADD)) {
                contractRoomMapper.insertBatchSomeColumn(contractRoomListADD);
            }

        }

        return newContract;
    }

    @SneakyThrows
    @Override
    public PageDTO<ContractChangeListVO> listContractChanges(ContractChangeListQuery query) {
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        //从合同表中获取数据
        LambdaQueryWrapper<Contract> wrapper = new LambdaQueryWrapper<>();
        wrapper.like(query.getContractName()!=null,Contract::getContractName,query.getContractName())
                .eq(query.getContractCode()!=null,Contract::getContractCode,query.getContractCode())
                .eq(query.getContractType()!=null, Contract::getContractType,query.getContractType())
                .eq(Contract::getStoreId,storeId);
        //TODO storeId缺失
        //根据合同表显示数据
        List<Contract> contracts = contractMapper.selectList(wrapper);

        List<ContractChangeListVO> contractChangeListVOS = new ArrayList<>();
        for(int i=0;i< contracts.size();i++){
            ContractChangeListVO contractChangeListVO= msContractMapper.toContractChangeListVO(contracts.get(i));
            contractChangeListVO.setChangePerson( contracts.get(i).getStartUserId());
            //从store表获取数据
            //TODO 缺少storeid
            SStore sStore = sStoreMapper.selectById(storeId);
            contractChangeListVO.setChangePersonName(sStore.getName());
            //从contractType表中那合同类型名
            ContractType contractType = contractTypeMapper.selectById(contractChangeListVO.getContractType());
            contractChangeListVO.setContractTypeName(contractType.getTypeName());
            //从contract_change_plan表获取planId
            LambdaQueryWrapper<ContractChangePlan> wrapper1 = new LambdaQueryWrapper<>();
            wrapper1.eq(ContractChangePlan::getContractId,contractChangeListVO.getContractId());
            //TODO 缺少storeid
            wrapper1.eq(ContractChangePlan::getStoreId, storeId);
            List<ContractChangePlan> contractChangePlans = contractChangePlanMapper.selectList(wrapper1);
            //每一个合同表中多条变更数据
            for(ContractChangePlan contractChangePlan:contractChangePlans){
                ContractChangeListVO contractChangeListVO1 = new ContractChangeListVO();
                //从contract_change_plan_detail表中获取数据
                LambdaQueryWrapper<ContractChangePlanDetail> wrapper2 = new LambdaQueryWrapper<>();
                //根据 planId和contractId查找变更数据
                wrapper2.eq(ContractChangePlanDetail::getContractId,contractChangePlan.getContractId())
                                .eq( ContractChangePlanDetail::getPlanId,contractChangePlan.getPlanId());
                ContractChangePlanDetail contractChangePlanDetail = contractChangePlanDetailMapper.selectOne(wrapper2);
                BeanUtils.copyProperties(contractChangeListVO,contractChangeListVO1);
                BeanUtils.copyProperties(contractChangePlanDetail,contractChangeListVO1);

                contractChangeListVO1.setPlanId(contractChangePlan.getPlanId());
                contractChangeListVO1.setPlanType(contractChangePlan.getPlanType());
                switch (contractChangePlan.getPlanType()){
                    case "1001":
                        contractChangeListVO1.setPlanTypeName("主体变更");
                        break;
                    case "2002":
                        contractChangeListVO1.setPlanTypeName("租期调整");
                        break;
                    case "3003":
                        contractChangeListVO1.setPlanTypeName("资金调整");
                        break;
                    case "4004":
                        contractChangeListVO1.setPlanTypeName("费用标准调整");
                        break;
                    case "5005":
                        contractChangeListVO1.setPlanTypeName("退约管理");
                        break;
                    case "6006":
                        contractChangeListVO1.setPlanTypeName("续约管理");
                        break;
                }
                contractChangeListVO1.setRemark( contractChangePlan.getRemark());
                switch (contractChangePlan.getState()){
                    case "11":
                        contractChangeListVO1.setStateName("待审核");
                        break;
                    case "22":
                        contractChangeListVO1.setStateName("审核通过");
                        break;
                    case "33":
                        contractChangeListVO1.setStateName("审核失败");
                        break;
                }
                contractChangeListVOS.add(contractChangeListVO1);
            }
        }
        // 手动分页实现
        PageDTO<ContractChangeListVO> pageDTO = new PageDTO<>();
        // 获取总记录数
                int total = contractChangeListVOS.size();
                pageDTO.setTotal((long) total);
        // 设置当前页码和每页大小（使用query中的参数）
                long pageIndex =  query.getPageIndex() ;  // 默认第1页
                long pageSize =  query.getPageSize() ;    // 默认每页10条
                pageDTO.setPageIndex(pageIndex);
                pageDTO.setPageSize(pageSize);
        // 计算总页数
                int pages = (int) Math.ceil((double) total / pageSize);
                pageDTO.setPages((long) pages);
        // 计算分页起始和结束位置
                long fromIndex = (pageIndex - 1) * pageSize;
                 long toIndex = Math.min(fromIndex + pageSize, total);
        // 如果起始位置超出范围，返回空列表
                if (fromIndex >= total) {
                    pageDTO.setRows(Collections.emptyList());
                    return pageDTO;
                }
        // 获取分页数据
                List<ContractChangeListVO> pageList = contractChangeListVOS.subList((int)fromIndex, (int)toIndex);
                pageDTO.setRows(pageList);
        return pageDTO;


    }

    @SneakyThrows
    @Override
    public boolean addContract(ContractDTO contractDTO) {
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        //将dto转为do
        Contract contract = msContractMapper.contractDTOtocontractDo(contractDTO);
        //获取ContractRoomDTO数组
        ContractRoomDTO[] contractRoomDTOs = contractDTO.getRooms();
        //添加contract_room表的数据
        for(int i = 0;i<contractRoomDTOs.length;i++){
            ContractRoom contractRoom = msContractRoomMapper.ContractRoomDTOtoContractRoom(contractRoomDTOs[i]);
            contractRoom.setContractId(contractDTO.getContractType());
            //TODO 缺少storeId
            contractRoom.setStoreId(storeId);
            int insert = contractRoomMapper.insert(contractRoom);
            if(insert==0){
                return false;
            }
            return true;
        }
        //添加数据
        //TODO 缺少storeId
        contract.setStoreId(storeId);
        int insert = contractMapper.insert(contract);
        if(insert==0){
            return false;
        }
        return true;
    }

    @Override
    public boolean modifyContract(ContractDTO contractDTO) {
        //将dto转为do
        Contract contract = msContractMapper.contractDTOtocontractDo(contractDTO);
        //修改数据
        int update = contractMapper.updateById(contract);
        if(update == 0){
            return false;
        }
        return true;
    }

    @Override
    public boolean deleteContract(String  contractId) {
        //删除数据
        int delete = contractMapper.deleteById(contractId);
        return delete!=0;
    }

    @Override
    public ContractPrintVO createPrintTask( ContractPrintDTO contractDTO) {
        if(contractDTO.getContractId()==null)
        {
            return null;
        }
        // 2. 构建合同打印数据
        ContractPrintVO contractPrintVO = buildFullContractPrintData(contractDTO.getContractId(),contractDTO.getContractTypeId());
        return contractPrintVO;
    }

    /**
     * 构建完整的合同打印数据结构
     * @param contractId 合同ID
     * @return 完整的合同打印VO
     */
    private ContractPrintVO buildFullContractPrintData( String contractId,String contractTypeId) {
        ContractPrintVO contractPrintVO = new ContractPrintVO();
        // 填充基础替换字段
        contractPrintVO.setBaseRepalce(buildBaseReplaceItems());

        //  填充合同信息
        contractPrintVO.setContract(buildContractItems(contractId));

        //  填充合同类型规格
        contractPrintVO.setContractTypeSpec(buildContractTypeSpecItems(contractTypeId));

        // 填充合同类型模板
        contractPrintVO.setContractTypeTemplate(buildContractTypeTemplateItems(contractTypeId));

        return contractPrintVO;
    }

    /**
     * 构建基础替换字段项
     */
    private List<BaseReplaceItem> buildBaseReplaceItems() {
        List<BaseReplaceItem> items = new ArrayList<>();
        // 添加所有基础替换字段（实际应从配置服务获取）
        items.add(createBaseReplaceItem("STORE.CONTRACT", "partyA", "甲方", "partyA"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "partyB", "乙方", "partyB"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "contractName", "合同名称", "contractName"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "contractCode", "合同编号", "contractCode"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "aLink", "甲方联系电话", "aLink"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "bLink", "乙方联系电话", "bLink"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "aContacts", "甲方联系人", "aContacts"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "bContacts", "乙方联系人", "bContacts"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "operator", "经办人", "operator"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "operatorLink", "联系电话", "operatorLink"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "amount", "合同金额", "amount"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "startTime", "开始时间", "startTime"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "endTime", "结束时间", "endTime"));
        items.add(createBaseReplaceItem("STORE.CONTRACT", "signingTime", "签订时间", "signingTime"));

        return items;
    }

    private BaseReplaceItem createBaseReplaceItem(String domain, String key, String name, String value) {
        BaseReplaceItem item = new BaseReplaceItem();
        item.setDomain(domain);
        item.setId(0L);
        item.setKey(key);
        item.setName(name);
        item.setRemark("");
        item.setValue(value);
        return item;
    }

    /**
     * 构建合同信息项
     */
    private List<ContractListVO> buildContractItems(String contractId) {
        //TODO ContractListVO使用获取合同列表的实现代码
        ContractQuery contractQuery = new ContractQuery();
        contractQuery.setContractId( contractId);
        contractQuery.setPageIndex(1);
        contractQuery.setPageSize(99999999999l);
        JsonVO<PageDTO<ContractListVO>> pageDTOJsonVO = listContract(contractQuery);
        return pageDTOJsonVO.getData().getRows();
    }

    /**
     * 构建合同类型规格项
     */
    @SneakyThrows
    private List<ContractTypeSpecVO> buildContractTypeSpecItems(String contractTypeId) {
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        //TODO contractTypeSepc表根据contractid和storeid查数据，组长写
        LambdaQueryWrapper<ContractTypeSpec> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(ContractTypeSpec::getContractTypeId, contractTypeId)
                //TODO 缺失storeId
                .eq(ContractTypeSpec::getStoreId, storeId);
        List<ContractTypeSpec> contractTypeSpecs = contractTypeSpecMapper.selectList(wrapper);
        List<ContractTypeSpecVO> contractTypeSpecVOS = new ArrayList<>();
        for(ContractTypeSpec contractTypeSpec : contractTypeSpecs){
            contractTypeSpecVOS.add(msContractTypeSpecMapper.toContractTypeSpecVO( contractTypeSpec))  ;
        }
        return contractTypeSpecVOS;
    }

    /**
     * 构建合同类型模板项
     */
    @SneakyThrows
    private List< ContractTypeTemplateVO> buildContractTypeTemplateItems(String contractTypeId) {
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        //TODO ContractTypeTemplateItem根据contractid和storeid写，组长写
        LambdaQueryWrapper<ContractTypeTemplate> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(ContractTypeTemplate::getContractTypeId, contractTypeId)
                //TODO 缺失storeid
                .eq(ContractTypeTemplate::getStoreId, storeId);
        List<ContractTypeTemplate> contractTypeTemplates = contractTypeTemplateMapper.selectList(wrapper);
        List<ContractTypeTemplateVO> contractTypeTemplateVOS = new ArrayList<>();
        for(ContractTypeTemplate contractTypeTemplate:contractTypeTemplates){
            contractTypeTemplateVOS.add(msContractTypeTemplateMapper.toContractTypeTemplateVO(contractTypeTemplate));
        }
        return contractTypeTemplateVOS;
    }

    @SneakyThrows
    @Override
    public PageDTO<ContractListVO> listAllExpiredContract(ContractQuery query) {
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        // 构造条件
        QueryWrapper<Contract> wrapper = new QueryWrapper<>();
        //TODO 需要storeid
        wrapper.eq("c.store_id",storeId);

        if(StringUtils.isNotEmpty(query.getContractId())){
            wrapper.eq("c.contract_id",query.getContractId());
        }

        if (StringUtils.isNotEmpty(query.getContractName())) {
            wrapper.like("Contract_name", query.getContractName());
        }

        if (StringUtils.isNotEmpty(query.getContractCode())) {
            wrapper.like("Contract_code", query.getContractCode());
        }

        if (StringUtils.isNotEmpty(query.getContractType())) {
            wrapper.eq("Contract_type", query.getContractType());
        }
        wrapper.lt("c.end_time", LocalDateTime.now());
        //逻辑删除字段
        wrapper.eq("c.status_cd", "0");
        wrapper.eq("c.state","22");
        // 全查（含 contract_type + contract_file 的一个 file_real_name、file_save_name）
        List<ContractListVO> list = baseMapper.selectContractInfo(wrapper);

        // 手动分页
        int total = list.size();
        int fromIndex = (int) Math.min((query.getPageIndex() - 1) * query.getPageSize(), total);
        int toIndex = (int) Math.min(fromIndex + query.getPageSize(), total);
        List<ContractListVO> pagedList = list.subList(fromIndex, toIndex);

        // 查询附件信息（额外补充）
        List<String> contractIds = pagedList.stream()
                .map(ContractListVO::getContractId)
                .filter(StringUtils::isNotBlank)
                .distinct()
                .collect(Collectors.toList());

        List<ContractFile> fileList = contractFileMapper.selectFilesByContractIds(contractIds);

        // 按 contract_id 分组
        Map<String, List<AttrFileVO>> fileMap = fileList.stream()
                .collect(Collectors.groupingBy(
                        ContractFile::getContractId,
                        Collectors.mapping(f -> {
                            AttrFileVO vo = new AttrFileVO();
                            vo.setFileRealName(f.getFileRealName());
                            vo.setFileSaveName(f.getFileSaveName());
                            return vo;
                        }, Collectors.toList())
                ));

        // 回填 attrs 字段
        for (ContractListVO vo : pagedList) {
            vo.setAttrs(fileMap.getOrDefault(vo.getContractId(), new ArrayList<>()));
        }

        // 封装分页对象
        PageDTO<ContractListVO> pageDTO = new PageDTO<>();
        pageDTO.setRows(pagedList);
        pageDTO.setTotal((long) total);
        pageDTO.setPageIndex(query.getPageIndex());
        pageDTO.setPageSize(query.getPageSize());
        return pageDTO;
    }

    @Override
    public boolean updateToEndExpiredContract(String contractId) {
        Contract contract = contractMapper.selectById(contractId);
        //44 表示合同结束
        contract.setState("44");
        return baseMapper.updateById(contract)==1;
    }

    @SneakyThrows
    @Override
    public Boolean modifyToRenewExpiredContract( ContractDTO contractDTO){
         //判断请求头是否传送了
        if(StringUtils.isEmpty(userHolder.getCurrentToken())){
            throw new IllegalArgumentException("请求头里没有token");
        }
        //TODO storeid
        String storeId = userHolder.getCurrentUser().getStoreIds().get(0);
        //没有storeid报异常
        if(StringUtils.isBlank(storeId)){
            throw new IllegalArgumentException("请求头里的storeId为空");
        }

        //删除新的contract数据
        contractMapper.deleteId(contractDTO.getContractId());
        //删除旧的contract_room数据
            contractRoomMapper.deleteByContractId(contractDTO.getContractId());
        //将dto转为do
        Contract contract = msContractMapper.contractDTOtocontractDo(contractDTO);
        //获取ContractRoomDTO数组
        ContractRoomDTO[] contractRoomDTOs = contractDTO.getRooms();
        //添加数据
        //TODO 缺少storeid
        contract.setStoreId(storeId);
        contract.setState("22");
        contract.setContractId(null);
        int insert1 = contractMapper.insert(contract);
        //添加contract_room表的数据
        for(int i = 0;i<contractRoomDTOs.length;i++){
            ContractRoom contractRoom = msContractRoomMapper.ContractRoomDTOtoContractRoom(contractRoomDTOs[i]);
            contractRoom.setContractId(contractDTO.getContractType());
            //缺少storeId
            contractRoom.setStoreId(storeId);
            contractRoom.setContractId(contract.getContractId());
            contractRoom.setCrId(null);
            int insert = contractRoomMapper.insert(contractRoom);
            if(insert==0){
                return false;
            }
            return true;
        }
        if(insert1==0){
            return false;
        }
        return true;
    }
}
