## 收费管理
### 房屋收费
#### 创建房屋费用

关联数据表： 
1. pay_fee
2. pay_fee_config


逻辑：

前端传入 ： 

~~~c++
class HouseFeeDTO : public oatpp::DTO
{
	DTO_INIT(HouseFeeDTO, DTO);
	
	//房屋ID house_id
	DTO_FIELD(Int32, house_id);
	DTO_FIELD_INFO(house_id) {
		info->description = ZH_WORDS_GETTER("");
	}
	
	//费用类型 fee_type
	DTO_FIELD(String, fee_type);
	DTO_FIELD_INFO(fee_type)
	{
		info->description = ZH_WORDS_GETTER("");
	}
	
	//收费项目 charge_project
	DTO_FIELD(String, charge_project);
	DTO_FIELD_INFO(charge_project)
	{
		info->description = ZH_WORDS_GETTER("");
	}
	//计费起始时间 start_time
	DTO_FIELD(String, start_time);
	DTO_FIELD_INFO(start_time)
	{
		info->description = ZH_WORDS_GETTER("");
	}
	//计费结束时间 end_time
	DTO_FIELD(String, end_time);
	DTO_FIELD_INFO(fend_time)
	{
		info->description = ZH_WORDS_GETTER("");
	}
};
~~~
在`execAddHouseFee`中进行数据校验
在 `Service`层中
1. 创建各类`id` , `fee_type_cd` 由 fee_type + charge_project 拼接后转换为`id`
2. 查`pay_fee_config`计算具体费用
3. 用 `PayLoad`中获取的`user_id`
4. 从`pay_fee_config`获取`amount`
5. 从`PayLoad`获取`commmunity_id`
6.  


~~~



## 增加房屋费用功能业务结构

增加房屋费用是物业管理系统中的核心功能之一，主要用于对房屋设置收费项目。从代码分析来看，整个业务流程如下：

### 1. 业务入口

- **控制器层**：`SaveRoomCreateFeeCmd`类是处理增加房屋费用的入口点，其服务编码为"fee.saveRoomCreateFee"。
- **请求参数**：必须包含communityId（小区ID）、locationObjId（房屋ID）、configId（费用配置ID）、storeId（商户ID）等参数。

### 2. 业务处理流程

1. **参数校验**：校验必要参数，并获取费用配置信息。
2. **生成批次号**：通过`generatorBatch`方法生成费用批次号，并保存至pay_fee_batch表。
3. **查询房屋信息**：根据房屋ID查询房屋详情，包括楼层、单元、房间号等信息。
4. **获取业主信息**：根据房屋ID查询业主信息，包括业主ID、姓名、联系方式等。
5. **创建费用记录**：
   - 通过`feeBMOImpl.addRoomFee`方法创建基本费用记录
   - 填充费用信息，包括费用ID、费用类型、开始/结束时间、缴费对象等
   - 设置费用状态为"2008001"（正常）
6. **创建费用属性**：
   - 添加一次性费用截止时间（若适用）
   - 添加业主ID、名称、联系方式等属性
   - 添加费用对象名称（楼层-单元-房间号）
   - 如果是租金递增类型，还需添加递增周期、递增率、递增开始时间等属性
7. **保存数据**：通过`saveFeeAndAttrs`方法将费用和费用属性保存到数据库
8. **生成月度账单**：异步方式计算月数据和欠费数据，为后续账单做准备

### 3. 相关的数据库表

从代码分析，增加房屋费用功能涉及以下主要数据库表：

1. **pay_fee（费用主表）**：
   - feeId：费用ID（主键）
   - communityId：小区ID
   - configId：费用配置ID
   - payerObjId：缴费对象ID（房屋ID）
   - payerObjType：缴费对象类型（"3333"表示房屋）
   - feeTypeCd：费用类型编码
   - startTime：计费开始时间
   - endTime：计费结束时间
   - maxTime：最大结束时间
   - amount：金额（-1表示动态计算）
   - feeFlag：收费标识（周期性或一次性）
   - state：状态（2008001表示正常）
   - batchId：批次ID
   - incomeObjId：收入对象ID（商户ID）
   - userId：创建用户ID

2. **pay_fee_attr（费用属性表）**：
   - attrId：属性ID（主键）
   - feeId：费用ID（外键）
   - specCd：规格编码（用于区分不同属性）
   - value：属性值
   - communityId：小区ID
   
   常见的specCd包括：
   - 390001：业主ID
   - 390002：业主名称
   - 390003：业主联系方式
   - 390004：支付对象名称（楼层-单元-房间）
   - 390006：一次性费用截止时间
   - 390008：租金递增周期
   - 390009：租金递增率
   - 390010：租金递增开始时间

3. **pay_fee_batch（费用批次表）**：
   - batchId：批次ID（主键）
   - communityId：小区ID
   - createUserId：创建用户ID
   - createUserName：创建用户名称
   - state：状态
   - msg：描述

4. **pay_fee_config（费用配置表）**：
   - configId：配置ID（主键）
   - feeName：费用名称
   - feeTypeCd：费用类型编码
   - computingFormula：计算公式
   - squarePrice：每平米单价
   - additionalAmount：附加费用
   - communityId：小区ID
   - feeFlag：收费标识

5. **report_fee_month_statistics（费用月度统计表）**：
   - statisticsId：统计ID（主键）
   - feeId：费用ID
   - communityId：小区ID
   - configId：费用配置ID
   - feeCreateTime：费用创建时间
   - feeYear：费用年份
   - feeMonth：费用月份
   - receivableAmount：应收金额
   - receivedAmount：实收金额
   - oweAmount：欠费金额

6. **report_owe_fee（欠费表）**：
   - oweId：欠费ID（主键）
   - feeId：费用ID
   - communityId：小区ID
   - configId：费用配置ID
   - payerObjId：缴费对象ID
   - payerObjType：缴费对象类型
   - ownerId：业主ID
   - ownerName：业主名称
   - ownerTel：业主电话
   - amountOwed：欠费金额

### 4. 数据关系

- 一个房屋可以关联多个费用项目
- 每个费用项目通过configId关联到费用配置
- 每个费用有多个费用属性，通过feeId关联
- 费用与业主通过费用属性表关联（业主ID存储在fee_attr表中）
- 费用批次通过batchId关联多个费用记录
- 月度统计和欠费数据通过feeId关联到费用记录

### 5. 特殊处理

1. **租金递增**：对于需要按时间递增的租金，通过费用属性记录递增周期、递增率和递增开始时间。
2. **一次性费用**：针对一次性费用，需要设置截止时间属性。
3. **计费金额**：费用记录的amount字段默认为-1，表示需要动态计算，系统会根据各种因素（如面积、单价、公式等）计算实际费用。

以上是对房屋收费的增加房屋费用功能的业务结构和关联数据库表的分析。该功能通过合理的数据设计，实现了灵活的费用管理，支持多种计费方式和特殊处理逻辑。

~~~

# 小区架构
小区里面的角色有：
物业
商户
开发团队
运营团队
community_member 表记录这小区和小区角色的信息![alt text](PixPin_2025-05-20_12-37-00.png)