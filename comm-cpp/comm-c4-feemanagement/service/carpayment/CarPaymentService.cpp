#include "stdafx.h"
#include "CarPaymentService.h"
#include "../../domain/dto/carpayment/CarPaymentDTO.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"
#include "../../dao/carpayment/CarPaymentDAO.h"
#include "../../domain/do/carpayment/CarPaymentDO.h"
#include "id/SnowFlake.h"
GetVehicleFeeDTO::Wrapper GetVehicleFeeService::getById(std::string id)
{
	// 查询数据
	GetVehicleFeeDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = GetVehicleFeeDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res,
		fee_id, FeeId,             // DTO field: fee_id
		fee_flag, FeeFlag,         // DTO field: fee_flag
		fee_type_cd, FeeTypeCd,   // DTO field: fee_type_cd
		value, Value,             // DTO field: value
		fee_name, FeeName,         // DTO field: fee_name
		state, State,             // DTO field: state
		create_time, CreateTime,     // DTO field: creat_time
		start_time, StartTime,     // DTO field: start_time
		end_time, EndTime,         // DTO field: end_time
		batch_id, BatchId,         // DTO field: batch_id
		owe_amount, OweAmount,     // DTO field: owe_amount (DO: float -> DTO: String)
		owner_id, OwnerId,         // DTO field: owner_id
		owner_name, OwnerName,     // DTO field: owner_name
		link, Link               // DTO field: link
	);
	return dto;
}

GetPaymentRecordsPageDTO::Wrapper GetPaymentRecordsService::listAll(const GetPaymentRecordsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetPaymentRecordsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GetPaymentRecordsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GetPaymentRecordsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (GetPaymentRecordsDO sub : result)
	{
		auto dto = GetPaymentRecordsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			fee_name, FeeName,
			value, Value,
			cycle, Cycle,                         // DO: float, DTO: Float64 (通常兼容)
			receivable_amount, ReceivableAmount,   // DO: float, DTO: Float64
			received_amount, ReceivedAmount,       // DO: float (field: received_amount), DTO: Float64 (Pascal: ReceivedAmount)
			create_time, CreateTime,
			pay_fee_time, PayFeeTime,
			cashier_name, CashierName,
			status_cd, StatusCd,
			remark, Remark
		);
		pages->addData(dto);
	}
	return pages;
}

GetPaymentDetailedRecordDTO::Wrapper GetPaymentDetailedRecordService::getById(std::string id)
{
	// 查询数据
	GetPaymentDetailedRecordDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = GetPaymentDetailedRecordDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, \
		fee_id, FeeId,
		cycle, Cycle,
		receivable_amount, ReceivableAmount,
		received_amount, ReceivedAmount,
		pay_fee_time, PayFeeTime,
		create_time, CreateTime,
		deadline_time, DeadlineTime,
		cashier_name, CashierName,
		status_cd, StatusCd,
		remark, Remark
	);
	return dto;
}

GetFeeModificationRecordsPageDTO::Wrapper GetFeeModificationRecordsService::listAll(const GetFeeModificationRecordsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetFeeModificationRecordsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GetFeeModificationRecordsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GetFeeModificationRecordsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (GetFeeModificationRecordsDO sub : result)
	{
		auto dto = GetFeeModificationRecordsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, \
			fee_name, FeeName, \
			create_time, CreateTime, \
			start_time, StartTime, \
			create_user_name, CreateUserName
		);
		pages->addData(dto);
	}
	return pages;
}
CarPaymentPageDTO::Wrapper CarPaymentService::listAll(const CarPaymentQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CarPaymentPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CarPaymentDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<Pay_FeeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (Pay_FeeDO sub : result)
	{
		auto dto = CarPaymentDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_name, FeeName, fee_flag,FeeFlag, fee_type, FeeTypeCd, rece_pay, Amount, create_time, CreateTime, qdt, RecePeriod, description, Description,status, State);
		pages->addData(dto);
	}
	return pages;
}



CarPaymentPageDTO::Wrapper CarPaymentService::getById(const CarPaymentQuery::Wrapper& query)
{
   
    // 构建返回对象
    auto pages = CarPaymentPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    CarPaymentDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    list<Pay_FeeDO> result = dao.selectWithPage(query);
    // 将DO转换成DTO
    for (Pay_FeeDO sub : result)
    {
        auto dto = CarPaymentDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee_name, FeeName, fee_flag, FeeFlag, fee_type, FeeTypeCd, rece_pay, Amount, create_time, CreateTime, qdt, RecePeriod, description, Description, status, State);
        pages->addData(dto);
    }
    return pages;
    
   
}



std::string CarPaymentService::saveData(const CarPaymentDTO::Wrapper& dto)
{

    CarPaymentDAO dao;
    // 开启事务
    //dao.getSqlSession()->beginTransaction();

    
        // 生成ID
         SnowFlake sf(1, 1);
        std::string feeId = std::to_string(sf.nextId());
        std::string configId = std::to_string(sf.nextId());


   
        //std::string oweId = uf.genUuid();

        // 创建DO对象
        Pay_FeeDO payFeeData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(payFeeData, dto,
            FeeName, fee_name,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount,
            Description, description
        );
        payFeeData.setFeeTypeCd(dto->fee_type);
       
        payFeeData.setFeeId(feeId);
        payFeeData.setConfigId(configId);

        // 设置创建人和创建时间
        auto payload = dto->getPayload();
        if (payload) {
            // 设置当前操作用户ID（从认证信息获取）
            payFeeData.setUserId(payload->getId());
          // payFeeData.setCreateBy(payload->getUsername());
        
        }
        payFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值
        payFeeData.setBId("1");
        payFeeData.setStatusCd("0");
        payFeeData.setFeeFlag("1003006");
        payFeeData.setState("2008001");
        payFeeData.setPayerObjType("3333");
        payFeeData.setBatchId("-1");
        payFeeData.setRecePeriod("-1");
        return dao.insert(payFeeData) == 1 ? payFeeData.getFeeId() : "";
        /*/ 插入pay_fee表
        if (dao.insert(payFeeData) != 1)
        {
            throw std::runtime_error("Failed to insert into pay_fee");
        }
        
        // 创建费用配置DO对象
     
        Pay_Fee_ConfigDO feeConfigData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(feeConfigData, dto,
            CommunityId, community_id,
            FeeTypeCd, fee_type,
            SquarePrice, square_price,
            AdditionalAmount, sur_fee,
            StartTime, start_time,
            EndTime, end_time,
            FeeName, fee_name,
            ComputingFormula, computing_formula,
            BillType, bill_type,
            PaymentCycle, pay_cycle,
            PaymentCd, pay_type,
            ComputingFormulaText, computing_formula_text,
            DeductFrom, deduct_from,
            PayOnline, pay_online,
            Scale, scale,
            DecimalPlace, decimal_place,
            Units, units,
            PrepaymentPeriod, prepayment_period
        );

   
        feeConfigData.setConfigId(configId);
        // 设置创建时间和创建人
       // auto payload = dto->getPayload();
       /* if (payload) {
            //feeConfigData.setUserId(payload->getId()); // 设置创建用户ID
        }
        feeConfigData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值
        feeConfigData.setBId("1");
        feeConfigData.setStatusCd("0");
        feeConfigData.setFeeFlag("1003006");
        feeConfigData.setIsDefault("F"); // 默认不是默认配置

        // 插入pay_fee_config表
        if (dao.insert(feeConfigData) != 1)
        {
            throw std::runtime_error("Failed to insert into pay_fee_config");
        }

        // 组装 Business_Pay_FeeDO
        Business_Pay_FeeDO businessPayFeeData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeData, dto,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount
        );
        businessPayFeeData.setFeeTypeCd(dto->fee_type);
        businessPayFeeData.setFeeId(feeId);
        businessPayFeeData.setConfigId(configId);

        // 设置创建人和创建时间
      //  auto payload = dto->getPayload();
        
            businessPayFeeData.setUserId(dto->getPayload()->getId());
        
        businessPayFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值
        businessPayFeeData.setBId("1");
        businessPayFeeData.setFeeFlag("1003006");
        businessPayFeeData.setState("2008001");
        businessPayFeeData.setPayerObjType("3333");
        businessPayFeeData.setBatchId("-1");
        businessPayFeeData.setOperate("ADD");  // 明确设置操作类型
        // 插入business_pay_fee表
        if (dao.insert(businessPayFeeData) != 1)
        {
            throw std::runtime_error("Failed to insert into business_pay_fee");
        }

        // 组装 Business_Pay_Fee_ConfigDO
        Business_Pay_Fee_ConfigDO businessPayFeeConfigData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeConfigData, dto,
            FeeName,fee_name,
            FeeTypeCd, fee_type,
            CommunityId, community_id,
            StartTime, start_time,
            EndTime, end_time,
            FeeName, fee_name
        );
        // 设置特殊字段
        businessPayFeeConfigData.setConfigId(configId);
        businessPayFeeConfigData.setFeeTypeCd(dto->fee_type);
        businessPayFeeConfigData.setSquarePrice(dto->unit_price);   // 假设DTO中有单价字段
        businessPayFeeConfigData.setAdditionalAmount(dto->sur_fee); // 假设DTO中有附加费字段

        // 设置创建时间
        businessPayFeeConfigData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值和默认值
        businessPayFeeConfigData.setBId("1");
        businessPayFeeConfigData.setOperate("ADD");
        businessPayFeeConfigData.setIsDefault("F");
        businessPayFeeConfigData.setFeeFlag("1003006");
        businessPayFeeConfigData.setComputingFormula("1001");
        businessPayFeeConfigData.setBillType("004");
        businessPayFeeConfigData.setPaymentCycle("1");
        businessPayFeeConfigData.setPaymentCd("1200");
        businessPayFeeConfigData.setComputingFormulaText("");
        businessPayFeeConfigData.setDeductFrom("Y");
        businessPayFeeConfigData.setUnits("元");
        businessPayFeeConfigData.setDecimalPlace(2);
        businessPayFeeConfigData.setScale("1");
        businessPayFeeConfigData.setPayOnline("Y");
        businessPayFeeConfigData.setPrepaymentPeriod("");
        // 插入business_pay_fee_config表
        if (dao.insert(businessPayFeeConfigData) != 1)
        {
            throw std::runtime_error("Failed to insert into business_pay_fee_config");
        }

        // 组装 Report_Owe_FeeDO
        Report_Owe_FeeDO reportOweFeeData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(reportOweFeeData, dto,
            ConfigName, config_name,         // 费用项名称（假设与fee_name相同）
            FeeName, fee_name,            // 费用名称
            OwnerId, owner_id,    
            OwnerName, owner_name,    
            OwnerTel, owner_tel,          // 业主电话（假设DTO中有owner_tel字段）
            PayerObjName, payer_obj_name, // 付费对象名称（假设DTO中有payer_obj_name字段）
            CommunityId, community_id,    // 小区ID
            EndTime, end_time,             // 结束时间
            DeadlineTime, deadline_time
        );

        // 设置关联ID
        reportOweFeeData.setConfigId(configId);  // 使用相同的configId
        reportOweFeeData.setFeeId(feeId);        // 使用相同的feeId

        // 设置付款方信息（从Pay_FeeDO继承）
        reportOweFeeData.setPayerObjId(payFeeData.getPayerObjId());
        reportOweFeeData.setPayerObjType(payFeeData.getPayerObjType());

        // 设置欠费金额（默认为总金额）
        reportOweFeeData.setAmountOwed(payFeeData.getAmount());

        // 设置时间信息
        std::string currentTime = SimpleDateTimeFormat::format();
        reportOweFeeData.setCreateTime(currentTime);
        reportOweFeeData.setUpdateTime(currentTime);

         设置截止时间（默认为结束时间+30天）
        SimpleDateTime deadline(dto->end_time);
        deadline.addDays(30);
        reportOweFeeData.setDeadlineTime(deadline.toString());
        

        // 生成欠费ID
        reportOweFeeData.setOweId(oweId);
        // 插入report_owe_fee表
        if (dao.insert(reportOweFeeData) != 1)
        {
            throw std::runtime_error("Failed to insert into report_owe_fee");
        }

        // 提交事务
        dao.getSqlSession()->commitTransaction();
        */
        return feeId;
    
  
        // 回滚事务
        /*dao.getSqlSession()->rollbackTransaction();
        return false; // 重新抛出异常
          */

}

bool CarPaymentService::updateData(const CarPaymentDTO::Wrapper& dto)
{
    CarPaymentDAO dao;
    // 开启事务
   // dao.getSqlSession()->beginTransaction();

    
        // 从DTO获取主键（假设DTO包含这些ID）
        std::string feeId = dto->fee_id;
        std::string configId = dto->fee_item_id;
        std::string oweId = dto->owe_id;

        // 创建DO对象
        Pay_FeeDO payFeeData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(payFeeData, dto,
            FeeName, fee_name,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount,
            Description, description
        );
        payFeeData.setFeeTypeCd(dto->fee_type);
        
        payFeeData.setFeeId(feeId);
        payFeeData.setConfigId(configId);

        // 设置创建人和创建时间
        //auto payload = dto->getPayload();
        
            // 设置当前操作用户ID（从认证信息获取）
            payFeeData.setUserId(dto->getPayload()->getId());
            // payFeeData.setCreateBy(payload->getUsername());

        
        payFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值
        payFeeData.setBId("1");
        payFeeData.setStatusCd("0");
        payFeeData.setFeeFlag("1003006");
        payFeeData.setState("2008001");
        payFeeData.setPayerObjType("3333");
        payFeeData.setBatchId("-1");
        
        return dao.update(payFeeData);
        
        /*
        if (dao.update(payFeeData) != 1) {
            throw std::runtime_error("Failed to update pay_fee");
        }

        // 创建费用配置DO对象
        Pay_Fee_ConfigDO feeConfigData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(feeConfigData, dto,
            CommunityId, community_id,
            FeeTypeCd, fee_type,
            SquarePrice, square_price,
            AdditionalAmount, sur_fee,
            StartTime, start_time,
            EndTime, end_time,
            FeeName, fee_name,
            ComputingFormula, computing_formula,
            BillType, bill_type,
            PaymentCycle, pay_cycle,
            PaymentCd, pay_type,
            ComputingFormulaText, computing_formula_text,
            DeductFrom, deduct_from,
            PayOnline, pay_online,
            Scale, scale,
            DecimalPlace, decimal_place,
            Units, units,
            PrepaymentPeriod, prepayment_period
        );

        
        feeConfigData.setConfigId(configId);
        // 设置创建时间和创建人
        //auto payload = dto->getPayload();
       
            //feeConfigData.setUserId(dto->getPayload()->getId()); // 设置创建用户ID
        
        feeConfigData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值
        feeConfigData.setBId("1");
        feeConfigData.setStatusCd("0");
        feeConfigData.setFeeFlag("1003006");
        feeConfigData.setIsDefault("F"); // 默认不是默认配置

        if (dao.update(feeConfigData) != 1) {
            throw std::runtime_error("Failed to update pay_fee_config");
        }

        // 组装 Business_Pay_FeeDO
        Business_Pay_FeeDO businessPayFeeData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeData, dto,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount
        );
        businessPayFeeData.setFeeTypeCd(dto->fee_type);
        businessPayFeeData.setFeeId(feeId);
        businessPayFeeData.setConfigId(configId);

        // 设置创建人和创建时间
       // auto payload = dto->getPayload();
        
            businessPayFeeData.setUserId(dto->getPayload()->getId());
        
        businessPayFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值
        businessPayFeeData.setBId("1");
        businessPayFeeData.setFeeFlag("1003006");
        businessPayFeeData.setState("2008001");
        businessPayFeeData.setPayerObjType("3333");
        businessPayFeeData.setBatchId("-1");
        businessPayFeeData.setOperate("MODIFY");  // 明确设置操作类型

        if (dao.update(businessPayFeeData) != 1) {
            throw std::runtime_error("Failed to update business_pay_fee");
        }

        // 组装 Business_Pay_Fee_ConfigDO
        Business_Pay_Fee_ConfigDO businessPayFeeConfigData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeConfigData, dto,
            FeeName, fee_name,
            FeeTypeCd, fee_type,
            CommunityId, community_id,
            StartTime, start_time,
            EndTime, end_time,
            FeeName, fee_name
        );
        // 设置特殊字段
        businessPayFeeConfigData.setConfigId(configId);
        businessPayFeeConfigData.setFeeTypeCd(dto->fee_type);
        businessPayFeeConfigData.setSquarePrice(dto->unit_price);   // 假设DTO中有单价字段
        businessPayFeeConfigData.setAdditionalAmount(dto->sur_fee); // 假设DTO中有附加费字段

        // 设置创建时间
        businessPayFeeConfigData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值和默认值
        businessPayFeeConfigData.setBId("1");
        businessPayFeeConfigData.setOperate("MODIFY");
        businessPayFeeConfigData.setIsDefault("F");
        businessPayFeeConfigData.setFeeFlag("1003006");
        businessPayFeeConfigData.setComputingFormula("1001");
        businessPayFeeConfigData.setBillType("004");
        businessPayFeeConfigData.setPaymentCycle("1");
        businessPayFeeConfigData.setPaymentCd("1200");
        businessPayFeeConfigData.setComputingFormulaText("");
        businessPayFeeConfigData.setDeductFrom("Y");
        businessPayFeeConfigData.setUnits("元");
        businessPayFeeConfigData.setDecimalPlace(2);
        businessPayFeeConfigData.setScale("1");
        businessPayFeeConfigData.setPayOnline("Y");
        businessPayFeeConfigData.setPrepaymentPeriod("");

        if (dao.update(businessPayFeeConfigData) != 1) {
            throw std::runtime_error("Failed to update business_pay_fee_config");
        }

        // 组装 Report_Owe_FeeDO
        Report_Owe_FeeDO reportOweFeeData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(reportOweFeeData, dto,
            ConfigName, config_name,         // 费用项名称（假设与fee_name相同）
            FeeName, fee_name,            // 费用名称
            OwnerId, owner_id,
            OwnerName, owner_name,
            OwnerTel, owner_tel,          // 业主电话（假设DTO中有owner_tel字段）
            PayerObjName, payer_obj_name, // 付费对象名称（假设DTO中有payer_obj_name字段）
            CommunityId, community_id,    // 小区ID
            EndTime, end_time,             // 结束时间
            DeadlineTime, deadline_time
        );

        // 设置关联ID
        reportOweFeeData.setConfigId(configId);  // 使用相同的configId
        reportOweFeeData.setFeeId(feeId);        // 使用相同的feeId

        // 设置付款方信息（从Pay_FeeDO继承）
        reportOweFeeData.setPayerObjId(payFeeData.getPayerObjId());
        reportOweFeeData.setPayerObjType(payFeeData.getPayerObjType());

        // 设置欠费金额（默认为总金额）
        reportOweFeeData.setAmountOwed(payFeeData.getAmount());

        // 设置时间信息
        std::string currentTime = SimpleDateTimeFormat::format();
        reportOweFeeData.setCreateTime(currentTime);
        reportOweFeeData.setUpdateTime(currentTime);

        / 设置截止时间（默认为结束时间+30天）
        SimpleDateTime deadline(dto->end_time);
        deadline.addDays(30);
        reportOweFeeData.setDeadlineTime(deadline.toString());
        

        // 生成欠费ID
        reportOweFeeData.setOweId(oweId);

        if (dao.update(reportOweFeeData) != 1) {
            throw std::runtime_error("Failed to update report_owe_fee");
        }

        // 提交事务
        dao.getSqlSession()->commitTransaction();
        return true;
    
  
        dao.getSqlSession()->rollbackTransaction();
        return false;
        */
    
}
/*
bool CarPaymentService::removeData(const oatpp::List<oatpp::String>& ids)
{
    CarPaymentDAO dao;
    // 开启事务
    dao.getSqlSession()->beginTransaction();
    // 循环删除
    int rows = 0;
    for (auto one : *ids.get())
    {
        rows += dao.deleteById(one.getValue({}));
    }
    // 判断是否全部删除成功
    if (rows == ids->size()) {
        // 提交事务
        dao.getSqlSession()->commitTransaction();
        return true;
    }
    // 回滚事务
    dao.getSqlSession()->rollbackTransaction();
    return false;
}*/

int CarPaymentService::removeData(const CarPaymentDeleteDTO::Wrapper& dto, const PayloadDTO& payload) {
    CarPaymentDAO dao;
    Pay_FeeDO DO;
    ZO_STAR_DOMAIN_DTO_TO_DO(DO, dto,
        FeeId, fee_id);
    return dao.deleteById(DO.getFeeId());
}

/*
bool CarPaymentService::removeData(const CarPaymentDTO::Wrapper& dto)
{
    CarPaymentDAO dao;
 
    // 开启事务
   // dao.getSqlSession()->beginTransaction();

    
        // 1. 查询要删除的原始数据
        PtrPay_FeeDO originalPayFee = dao.queryPayFeeById(dto->fee_id);
       // PtrPay_Fee_ConfigDO originalPayFeeConfig = dao.queryPayFeeConfigById(dto->fee_item_id);
        //PtrReport_Owe_FeeDO originalOweFee = dao.queryOweFeeById(dto->owe_id);


        / 2. 向 business_pay_fee 表添加删除记录
        Business_Pay_FeeDO businessPayFeeData;
        businessPayFeeData.setFeeId(originalPayFee->getFeeId());
        businessPayFeeData.setBId(originalPayFee->getBId());
        businessPayFeeData.setFeeTypeCd(originalPayFee->getFeeTypeCd());
        businessPayFeeData.setCommunityId(originalPayFee->getCommunityId());
        businessPayFeeData.setPayerObjId(originalPayFee->getPayerObjId());
        businessPayFeeData.setIncomeObjId(originalPayFee->getIncomeObjId());
        businessPayFeeData.setStartTime(originalPayFee->getStartTime());
        businessPayFeeData.setEndTime(originalPayFee->getEndTime());
        businessPayFeeData.setAmount(originalPayFee->getAmount());
        businessPayFeeData.setUserId(originalPayFee->getUserId());
        businessPayFeeData.setOperate("DEL"); // 标记为删除操作
        businessPayFeeData.setFeeFlag(originalPayFee->getFeeFlag());
        businessPayFeeData.setState(originalPayFee->getState());
        businessPayFeeData.setConfigId(originalPayFee->getConfigId());
        businessPayFeeData.setPayerObjType(originalPayFee->getPayerObjType());
        businessPayFeeData.setBatchId(originalPayFee->getBatchId());

        if (dao.insert(businessPayFeeData) != 1) {
            throw std::runtime_error("Failed to insert into business_pay_fee");
        }

        // 3. 向 business_pay_fee_config 表添加删除记录
        Business_Pay_Fee_ConfigDO businessPayFeeConfigData;
        businessPayFeeConfigData.setConfigId(originalPayFeeConfig->getConfigId());
        businessPayFeeConfigData.setBId(originalPayFeeConfig->getBId());
        businessPayFeeConfigData.setCommunityId(originalPayFeeConfig->getCommunityId());
        businessPayFeeConfigData.setFeeTypeCd(originalPayFeeConfig->getFeeTypeCd());
        businessPayFeeConfigData.setSquarePrice(originalPayFeeConfig->getSquarePrice());
        businessPayFeeConfigData.setAdditionalAmount(originalPayFeeConfig->getAdditionalAmount());
        businessPayFeeConfigData.setOperate("DEL"); // 标记为删除操作
        businessPayFeeConfigData.setIsDefault(originalPayFeeConfig->getIsDefault());
        businessPayFeeConfigData.setStartTime(originalPayFeeConfig->getStartTime());
        businessPayFeeConfigData.setEndTime(originalPayFeeConfig->getEndTime());
        businessPayFeeConfigData.setFeeFlag(originalPayFeeConfig->getFeeFlag());
        businessPayFeeConfigData.setFeeName(originalPayFeeConfig->getFeeName());
        businessPayFeeConfigData.setComputingFormula(originalPayFeeConfig->getComputingFormula());
        businessPayFeeConfigData.setBillType(originalPayFeeConfig->getBillType());
        businessPayFeeConfigData.setPaymentCycle(originalPayFeeConfig->getPaymentCycle());
        businessPayFeeConfigData.setPaymentCd(originalPayFeeConfig->getPaymentCd());
        businessPayFeeConfigData.setComputingFormulaText(originalPayFeeConfig->getComputingFormulaText());
        businessPayFeeConfigData.setDeductFrom(originalPayFeeConfig->getDeductFrom());
        businessPayFeeConfigData.setUnits(originalPayFeeConfig->getUnits());
        businessPayFeeConfigData.setDecimalPlace(originalPayFeeConfig->getDecimalPlace());
        businessPayFeeConfigData.setScale(originalPayFeeConfig->getScale());
        businessPayFeeConfigData.setPayOnline(originalPayFeeConfig->getPayOnline());
        businessPayFeeConfigData.setPrepaymentPeriod(originalPayFeeConfig->getPrepaymentPeriod());

        if (dao.insert(businessPayFeeConfigData) != 1) {
            throw std::runtime_error("Failed to insert into business_pay_fee_config");
        }

        // 4. 删除主表数据
        if (dao.deleteByIds(dto) <= 0) {
            throw std::runtime_error("Failed to delete main records");
        }

        // 提交事务
        dao.getSqlSession()->commitTransaction();
        return true;
    
   
        // 回滚事务
        dao.getSqlSession()->rollbackTransaction();      
        return false;
}
*/


bool CarPaymentService::payFee(const CarPaymentDTO::Wrapper& dto)
{
    CarPaymentDAO dao;
    /* 开启事务
    dao.getSqlSession()->beginTransaction();

    
        // 从DTO获取主键（假设DTO包含这些ID）
        std::string feeId = dto->fee_id;
        std::string configId = dto->fee_item_id;
        std::string oweId = dto->owe_id;

        // 创建DO对象
        Pay_FeeDO payFeeData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(payFeeData, dto,
            FeeName, fee_name,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount,
            Description, description
        );
        payFeeData.setFeeTypeCd(dto->fee_type);
      
        payFeeData.setFeeId(feeId);
        payFeeData.setConfigId(configId);

        // 设置创建人和创建时间
       // auto payload = dto->getPayload();
       
            // 设置当前操作用户ID（从认证信息获取）
            payFeeData.setUserId(dto->getPayload()->getId());
            // payFeeData.setCreateBy(payload->getUsername());

        
        payFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值
        payFeeData.setBId("1");
        payFeeData.setStatusCd("1");
        payFeeData.setFeeFlag("1003006");
        payFeeData.setState("2008002");
        payFeeData.setPayerObjType("3333");
        payFeeData.setBatchId("-1");

        if (dao.update(payFeeData) != 1) {
            throw std::runtime_error("Failed to update pay_fee");
        }

        /*
        // 组装 Business_Pay_FeeDO
        Business_Pay_FeeDO businessPayFeeData;

        // 使用宏从DTO复制属性
        ZO_STAR_DOMAIN_DTO_TO_DO(businessPayFeeData, dto,
            CommunityId, community_id,
            PayerObjId, payer_obj_id,
            IncomeObjId, income_obj_id,
            StartTime, start_time,
            EndTime, end_time,
            Amount, amount
        );
        businessPayFeeData.setFeeTypeCd(dto->fee_type);
        businessPayFeeData.setFeeId(feeId);
        businessPayFeeData.setConfigId(configId);

        // 设置创建人和创建时间
        //auto payload = dto->getPayload();
    
            businessPayFeeData.setUserId(dto->getPayload()->getId());
        
        businessPayFeeData.setCreateTime(SimpleDateTimeFormat::format());

        // 设置固定值
        businessPayFeeData.setBId("1");
        businessPayFeeData.setFeeFlag("1003006");
        businessPayFeeData.setState("2008002");
        businessPayFeeData.setPayerObjType("3333");
        businessPayFeeData.setBatchId("-1");
        businessPayFeeData.setOperate("PAY");  // 明确设置操作类型

        if (dao.update(businessPayFeeData) != 1) {
            throw std::runtime_error("Failed to update business_pay_fee");
        }

       */
        // 获取当前欠费记录
        PtrReport_Owe_FeeDO reportOweFeeData=dao.queryOweFeeById(dto->owe_id);
       
        if (!dao.queryOweFeeById(dto->owe_id)) {
            throw std::runtime_error("Owe fee record not found: " + dto->owe_id);
        }

        // 计算新的欠费金额（当前欠费减去本次支付金额）
        double currentOwedAmount = reportOweFeeData->getAmountOwed();
        double paidAmount = dto->paid_amount; // 从DTO获取本次支付金额
        double newOwedAmount = currentOwedAmount - paidAmount;

        // 设置更新后的值
        reportOweFeeData->setAmountOwed(newOwedAmount);
        reportOweFeeData->setUpdateTime(SimpleDateTimeFormat::format());
     
        if (newOwedAmount <= 0) {
            // 设置完成时间和状态
            reportOweFeeData->setEndTime(SimpleDateTimeFormat::format());
           

            // 更新数据库（而不是删除）
            return dao.update(reportOweFeeData);
        }
        else {
            // 更新欠费金额
            reportOweFeeData->setAmountOwed(newOwedAmount);
            return dao.update(reportOweFeeData);
        }

        // 提交事务
       // dao.getSqlSession()->commitTransaction();
        //return true;
    
    
        // 回滚事务
        //dao.getSqlSession()->rollbackTransaction();
        //return false;*/
}
