/*
 Copyright Zero One Star. All rights reserved.

 @Author: KBchulan
 @Date: 2024/5/24

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef DATASTATMAPPER_H
#define DATASTATMAPPER_H

#include <Mapper.h>
#include <domain/dto/datastat/DataStatDTO.h>

/*
 * 通用double类型映射器
 */
class DoubleMapper : public Mapper<double> {
public:
	double mapper(ResultSet* resultSet) const override {
		return resultSet->getDouble(1);
	}
};


/**
 * 实收统计结果映射器
 */
class DataStatFinalCostMapper : public Mapper<DataStatFinalCostDO>
{
public:
	DataStatFinalCostDO mapper(ResultSet* resultSet) const override
	{
		DataStatFinalCostDO data;

		data.setHouse(resultSet->getString("house"));
		data.setHostnum(resultSet->getInt("hostnum"));
		data.setCostnum(resultSet->getInt("costnum"));
		data.setWuye(resultSet->getDouble("wuye"));
		data.setYajin(resultSet->getDouble("yajin"));
		data.setTingche(resultSet->getDouble("tingche"));
		data.setMeiqi(resultSet->getDouble("meiqi"));
		data.setQunuan(resultSet->getDouble("qunuan"));
		data.setWeixiu(resultSet->getDouble("weixiu"));
		data.setQita(resultSet->getDouble("qita"));
		data.setFuwu(resultSet->getDouble("fuwu"));
		data.setShuifei(resultSet->getDouble("shuifei"));
		data.setDianfei(resultSet->getDouble("dianfei"));
		data.setZujin(resultSet->getDouble("zujin"));
		data.setGongtan(resultSet->getDouble("gongtan"));
		data.setFinal(resultSet->getDouble("final"));
		data.setAllfinal(resultSet->getDouble("allfinal"));

		return data;
	}
};

/**
 * 抓包SQL结构的映射器 - 处理每个楼栋每个费用类型的记录
 */
class DataStatPageMapper : public Mapper<DataStatFinalCostDO>
{
public:
	DataStatFinalCostDO mapper(ResultSet* resultSet) const override
	{
		DataStatFinalCostDO data;

		// 楼栋信息
		data.setHouse(resultSet->getString("floorNum") + ZH_WORDS_GETTER("datastat.building"));
		data.setHostnum(0);  // 暂时设为0，后续可能需要单独查询
		data.setCostnum(resultSet->getInt("feeRoomCount"));

		// 费用类型和金额
		std::string feeTypeCd = resultSet->getString("feeTypeCd");
		double receivedFee = resultSet->getDouble("receivedFee");

		// 根据费用类型设置对应字段
		if (feeTypeCd == "888800010001") {
			data.setWuye(receivedFee);  // 物业费
		}
		else if (feeTypeCd == "888800010006") {
			data.setYajin(receivedFee);  // 押金
		}
		else if (feeTypeCd == "888800010008") {
			data.setTingche(receivedFee);  // 停车费
		}
		else if (feeTypeCd == "888800010009") {
			data.setMeiqi(receivedFee);  // 煤气费
		}
		else if (feeTypeCd == "888800010011") {
			data.setQunuan(receivedFee);  // 取暖费
		}
		else if (feeTypeCd == "888800010012") {
			data.setWeixiu(receivedFee);  // 维修费
		}
		else if (feeTypeCd == "888800010014") {
			data.setQita(receivedFee);  // 其他费用
		}
		else if (feeTypeCd == "888800010013") {
			data.setFuwu(receivedFee);  // 服务费
		}
		else if (feeTypeCd == "888800010015") {
			data.setShuifei(receivedFee);  // 水费
		}
		else if (feeTypeCd == "888800010016") {
			data.setDianfei(receivedFee);  // 电费
		}
		else if (feeTypeCd == "888800010018") {
			data.setZujin(receivedFee);  // 租金
		}
		else if (feeTypeCd == "888800010017") {
			data.setGongtan(receivedFee);  // 公摊费
		}

		data.setFinal(receivedFee);  // 该费用类型的实收金额

		return data;
	}
};

/**
 * 欠费统计结果映射器
 */
class DataStatQianfeiMapper : public Mapper<DataStatQianfeiDO> {
public:
	DataStatQianfeiDO mapper(ResultSet* resultSet) const override {
		DataStatQianfeiDO data;
		data.setHouse(resultSet->getString(1));      // house
		data.setWuye(resultSet->getDouble(2));       // wuye
		data.setYajin(resultSet->getDouble(3));      // yajin
		data.setTingche(resultSet->getDouble(4));    // tingche
		data.setMeiqi(resultSet->getDouble(5));      // meiqi
		data.setQunuan(resultSet->getDouble(6));     // qunuan
		data.setWeixiu(resultSet->getDouble(7));     // weixiu
		data.setQita(resultSet->getDouble(8));       // qita
		data.setFuwu(resultSet->getDouble(9));       // fuwu
		data.setShuifei(resultSet->getDouble(10));   // shuifei
		data.setDianfei(resultSet->getDouble(11));   // dianfei
		data.setZujin(resultSet->getDouble(12));     // zujin
		data.setGongtan(resultSet->getDouble(13));   // gongtan
		data.setQianfei(resultSet->getDouble(14));   // qianfei
		data.setAllqianfei(resultSet->getDouble(15)); // allqianfei
		return data;
	}
};

/**
 * 实收明细结果映射器 - 按房间查询
 * 映射到DataStatDetailCostDTO的15个字段
 */
class DataStatDetailCostMapper : public Mapper<DataStatDetailCostDO> {
public:
	DataStatDetailCostDO mapper(ResultSet* resultSet) const override {
		DataStatDetailCostDO data;

		// DataStatDetailCostDTO自有的3个字段
		data.setHouse(resultSet->getString("house"));        // 楼栋单元房间信息
		data.setHost(resultSet->getString("host"));          // 业主姓名
		data.setFinal(resultSet->getDouble("final"));        // 实收总额

		// 继承自DataStatCostDTO的12个费用字段
		data.setWuye(resultSet->getDouble("wuye"));          // 物业费
		data.setYajin(resultSet->getDouble("yajin"));        // 押金
		data.setTingche(resultSet->getDouble("tingche"));    // 停车费
		data.setMeiqi(resultSet->getDouble("meiqi"));        // 煤气费
		data.setQunuan(resultSet->getDouble("qunuan"));      // 取暖费
		data.setWeixiu(resultSet->getDouble("weixiu"));      // 维修费
		data.setQita(resultSet->getDouble("qita"));          // 其他费用
		data.setFuwu(resultSet->getDouble("fuwu"));          // 服务费
		data.setShuifei(resultSet->getDouble("shuifei"));    // 水费
		data.setDianfei(resultSet->getDouble("dianfei"));    // 电费
		data.setZujin(resultSet->getDouble("zujin"));        // 租金
		data.setGongtan(resultSet->getDouble("gongtan"));    // 公摊费

		return data;
	}
};




/*              数据统计-3            */
/**
 * 欠费明细字段匹配映射
 */
class DatastatFeeDetailMapper : public Mapper<DatastatFeeDetailDO>
{
public:
	DatastatFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		DatastatFeeDetailDO data;
		// 核心字段映射
		data.setRoom_name(resultSet->getString("room_num"));
		data.setName(resultSet->getString("name"));
		data.setQianfei(resultSet->getInt("amount_owed"));

		return data;
	}
};

/**
 * 欠费明细字段匹配映射-创建智能指针对象
 */
class PtrDatastatFeeDetailMapper : public Mapper<PtrDatastatFeeDetailDO>
{
public:
	PtrDatastatFeeDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<DatastatFeeDetailDO>();
		// 核心字段映射
		data->setRoom_name(resultSet->getString("room_num"));
		data->setName(resultSet->getString("name"));
		data->setQianfei(resultSet->getInt("amount_owed"));
		return data;
	}
};

/**
 * 收缴情况字段匹配映射
 */
class DatastatChargeDetailMapper : public Mapper<DatastatChargeDetailDO>
{
public:
	DatastatChargeDetailDO mapper(ResultSet* resultSet) const override
	{
		DatastatChargeDetailDO data;
		// 核心字段映射
		data.setBuilding(resultSet->getString("name"));
		data.setNum_for_house(resultSet->getInt("num_for_house"));
		data.setNum_for_chargeable_house(resultSet->getInt("num_for_chargeable_house"));

		return data;
	}
};

/**
 * 收缴情况字段匹配映射-创建智能指针对象
 */
class PtrDatastatChargeDetailMapper : public Mapper<PtrDatastatChargeDetailDO>
{
public:
	PtrDatastatChargeDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<DatastatChargeDetailDO>();
		// 核心字段映射
		data->setBuilding(resultSet->getString("name"));
		data->setNum_for_house(resultSet->getInt("num_for_house"));
		data->setNum_for_chargeable_house(resultSet->getInt("num_for_chargeable_house"));

		return data;
	}
};


/**
 * 月实收明细字段匹配映射
 */
class DatastatMonthDetailMapper : public Mapper<DatastatMonthDetailDO>
{
public:
	DatastatMonthDetailDO mapper(ResultSet* resultSet) const override
	{
		DatastatMonthDetailDO data;
		// 核心字段映射
		data.setHouse(resultSet->getString("room_num"));
		data.setOw(resultSet->getString("name"));

		return data;
	}
};

/**
 * 月实收明细字段匹配映射-创建智能指针对象
 */
class PtrDatastatMonthDetailMapper : public Mapper<PtrDatastatMonthDetailDO>
{
public:
	PtrDatastatMonthDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<DatastatMonthDetailDO>();
		// 核心字段映射
		data->setHouse(resultSet->getString("room_num"));
		data->setOw(resultSet->getString("name"));
		return data;
	}
};


/**
 * 月欠费明细字段匹配映射
 */
class DatastatMonthFeeMapper : public Mapper<DatastatMonthFeeDO>
{
public:
	DatastatMonthFeeDO mapper(ResultSet* resultSet) const override
	{
		DatastatMonthFeeDO data;
		// 核心字段映射
		data.setHouse(resultSet->getString("room_num"));
		data.setOw(resultSet->getString("name"));

		return data;
	}
};

/**
 * 月欠费明细字段匹配映射-创建智能指针对象
 */
class PtrDatastatMonthFeeMapper : public Mapper<PtrDatastatMonthFeeDO>
{
public:
	PtrDatastatMonthFeeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<DatastatMonthFeeDO>();
		// 核心字段映射
		data->setHouse(resultSet->getString("room_num"));
		data->setOw(resultSet->getString("name"));
		return data;
	}
};


#endif // !DATASTATMAPPER_H
