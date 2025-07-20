#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yingjiu
 @Date: 2025/5/23 18:22:07

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
#ifndef _PAYMENTAUDIT_MAPPER_
#define _PAYMENTAUDIT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/payment_reviews/PaymentAuditDO.h"


class PaymentAuditListMapper : public Mapper<PaymentAuditListDO>
{
public:
	PaymentAuditListDO mapper(ResultSet* resultSet) const override
	{
		PaymentAuditListDO data;
		data.setObjName(resultSet->getString(1));       
		data.setFeeName(resultSet->getString(2));  
		data.setCycles(resultSet->getInt(3));      
		data.setStartTime(resultSet->getString(4));      
		data.setEndTime(resultSet->getString(5));     
		data.setReceivableAmount(resultSet->getInt(6)); 
		data.setReceivedAmount(resultSet->getInt(7));    
		data.setCashierName(resultSet->getString(8));      
		data.setCreateTime(resultSet->getString(9));      
		data.setState(resultSet->getString(10));     
		data.setMessage(resultSet->getString(11));     
		data.setRemark(resultSet->getString(12));     
		return data;
	}
};

class PtrPaymentAuditListMapper : public Mapper<PtrPaymentAuditListDO>
{
public:
	PtrPaymentAuditListDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared <PaymentAuditListDO>();
		data->setObjName(resultSet->getString(1));     
		data->setFeeName(resultSet->getString(2));    
		data->setCycles(resultSet->getInt(3));        
		data->setStartTime(resultSet->getString(4));     
		data->setEndTime(resultSet->getString(5));      
		data->setReceivableAmount(resultSet->getInt(6));  
		data->setReceivedAmount(resultSet->getInt(7)); 
		data->setCashierName(resultSet->getString(8));  
		data->setCreateTime(resultSet->getString(9));       
		data->setState(resultSet->getString(10));         
		data->setMessage(resultSet->getString(11));        
		data->setRemark(resultSet->getString(12));       
		return data;
	}
};

class PaymentAuditDetailMapper : public Mapper<PaymentAuditDetailDO>
{
public:
	PaymentAuditDetailDO mapper(ResultSet* resultSet) const override
	{
		PaymentAuditDetailDO data;
		data.setFeeId(resultSet->getString(1));      
		data.setFeeFlag(resultSet->getString(2));        
		data.setFeeTypeCd(resultSet->getString(3));   
		data.setPayerObjName(resultSet->getString(4));  
		data.setFeeName(resultSet->getString(5));   
		data.setFeeState(resultSet->getString(6));      
		data.setCreateTimea(resultSet->getString(7)); 
		data.setStartTime(resultSet->getString(8));    
		data.setEndTime(resultSet->getString(9));       
		data.setBatchId(resultSet->getString(10));       
		data.setArea(resultSet->getInt(11));          
		data.setSquarePrice(resultSet->getInt(12));    
		data.setFeeAddition(resultSet->getInt(13));    
		return data;
	}
};

class PtrPaymentAuditDetailMapper : public Mapper<PtrPaymentAuditDetailDO>
{
public:
	PtrPaymentAuditDetailDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<PaymentAuditDetailDO>();
		data->setFeeId(resultSet->getString(1));  
		data->setFeeFlag(resultSet->getString(2));      
		data->setFeeTypeCd(resultSet->getString(3));     
		data->setPayerObjName(resultSet->getString(4)); 
		data->setFeeName(resultSet->getString(5));       
		data->setFeeState(resultSet->getString(6));     
		data->setCreateTimea(resultSet->getString(7));   
		data->setStartTime(resultSet->getString(8));  
		data->setEndTime(resultSet->getString(9));      
		data->setBatchId(resultSet->getString(10));   
		data->setArea(resultSet->getInt(11));     
		data->setSquarePrice(resultSet->getInt(12));   
		data->setFeeAddition(resultSet->getInt(13));   
		return data;
	}
};



class PaymentAuditHistoryMapper : public Mapper<PaymentAuditHistoryDO>
{
public:
	PaymentAuditHistoryDO mapper(ResultSet* resultSet) const override
	{
		PaymentAuditHistoryDO data;
		data.setDetailId(resultSet->getString(1));        
		data.setCycles(resultSet->getInt(2));         
		data.setPrimeRate(resultSet->getString(3));    
		data.setReceivableAmount(resultSet->getInt(4)); 
		data.setReceivedAmount(resultSet->getInt(5));  
		data.setCreateTime(resultSet->getString(6));    
		data.setStartTime(resultSet->getString(7));    
		data.setEndTime(resultSet->getString(8));         
		data.setCashierName(resultSet->getString(9));    
		data.setStatusCd(resultSet->getString(10));   
		data.setRemark(resultSet->getString(11));   
		return data;
	}
};

class PtrPaymentAuditHistoryMapper : public Mapper<PtrPaymentAuditHistoryDO>
{
public:
	PtrPaymentAuditHistoryDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<PaymentAuditHistoryDO>();
		data->setDetailId(resultSet->getString(1));    
		data->setCycles(resultSet->getInt(2));   
		data->setPrimeRate(resultSet->getString(3));    
		data->setReceivableAmount(resultSet->getInt(4)); 
		data->setReceivedAmount(resultSet->getInt(5));   
		data->setCreateTime(resultSet->getString(6));      
		data->setStartTime(resultSet->getString(7));      
		data->setEndTime(resultSet->getString(8));        
		data->setCashierName(resultSet->getString(9));   
		data->setStatusCd(resultSet->getString(10));      
		data->setRemark(resultSet->getString(11));        
		return data;
	}
};

#endif // !_PAYMENTAUDIT_MAPPER_