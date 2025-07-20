#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _OWNER_MAPPER_
#define _OWNER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/owner/OwnerDO.h"

/**
 * 业主表字段匹配映射
 */
class OwnerMapper : public Mapper<OwnerDO>
{
public:
    OwnerDO mapper(ResultSet* resultSet) const override
    {
        OwnerDO data;
        /*data.setMemberId(resultSet->getString(1));
        
        data.setBId(resultSet->getString(3));*/
        data.setName(resultSet->getString(1));
        data.setSex(resultSet->getString(2));
        //data.setAge(resultSet->getString(6));
        data.setLink(resultSet->getString(3));
        data.setRemark(resultSet->getString(4));
        data.setAddress(resultSet->getString(5));
        data.setOwnerId(resultSet->getString(6));
        /*data.setUserId(resultSet->getString(8));
        
        data.setCreateTime(resultSet->getString(10));
        data.setStatusCd(resultSet->getString(11));
        data.setOwnerTypeCd(resultSet->getString(12));
        data.setCommunityId(resultSet->getString(13));*/
        data.setIdCard(resultSet->getString(7));
       /* data.setState(resultSet->getString(15));
        data.setOwnerFlag(resultSet->getString(16));
        */
        data.setCreateBy(resultSet->getString(8));
       // data.setRoomNum(resultSet->getString(19));
        return data;
    }
};

/**
 * 业主表字段匹配映射-创建智能指针对象
 */
class PtrOwnerMapper : public Mapper<PtrOwnerDO>
{
public:
    PtrOwnerDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<OwnerDO>();
        data->setMemberId(resultSet->getString(1));
        data->setOwnerId(resultSet->getString(2));
        data->setBId(resultSet->getString(3));
        data->setName(resultSet->getString(4));
        data->setSex(resultSet->getString(5));
        data->setAge(resultSet->getString(6));
        data->setLink(resultSet->getString(7));
        data->setUserId(resultSet->getString(8));
        data->setRemark(resultSet->getString(9));
        data->setCreateTime(resultSet->getString(10));
        data->setStatusCd(resultSet->getString(11));
        data->setOwnerTypeCd(resultSet->getString(12));
        data->setCommunityId(resultSet->getString(13));
        data->setIdCard(resultSet->getString(14));
        data->setState(resultSet->getString(15));
        data->setOwnerFlag(resultSet->getString(16));
        data->setAddress(resultSet->getString(17));
        data->setCreateBy(resultSet->getString(18));
        data->setRoomNum(resultSet->getString(19));
        return data;
    }
};

#endif // !_OWNER_MAPPER_
