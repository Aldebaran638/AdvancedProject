#pragma once

#ifndef _SELECTOWNER_MAPPER_
#define _SELECTOWNER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/owner/OwnerDO.h"

#include "NacosClient.h"
#include "gtest/gtest.h"
#include "ServerInfo.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
/**
 * ÒµÖ÷±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class selectOwnerMapper : public Mapper<OwnerDO>
{
public:
	OwnerDO mapper(ResultSet* resultSet) const override
	{
		OwnerDO data;
		NacosClient ns(
			ServerInfo::getInstance().getNacosAddr(),
			ServerInfo::getInstance().getNacosNs());
#ifdef LINUX
		auto thirdServerConfig = ns.getConfig("third-services.yaml");
#else
		auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
#endif
		data.setOwner_id(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		std::string file = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/"+resultSet->getString(3);
		data.setFile_real_name(file);
		data.setSex(resultSet->getString(4));
		data.setId_card(resultSet->getString(5));
		data.setLink(resultSet->getString(6));
		data.setAddress(resultSet->getString(7));
		data.setHouse_num(resultSet->getInt(8));
		data.setMember_num(resultSet->getInt(9));
		data.setCar_number(resultSet->getInt(10));
		data.setComplaint_num(resultSet->getInt(11));
		data.setRepair_num(resultSet->getInt(12));
		data.setAmount_owed(resultSet->getString(13));
		data.setContract_num(resultSet->getInt(14));
		data.setAccess_control_key(resultSet->getString(15));
		return data;
	}
};

class PtrselectOwnerMapper : public Mapper<PtrOwnerDO>
{
public:
	PtrOwnerDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<OwnerDO>();
		NacosClient ns(
			ServerInfo::getInstance().getNacosAddr(),
			ServerInfo::getInstance().getNacosNs());
#ifdef LINUX
		auto thirdServerConfig = ns.getConfig("third-services.yaml");
#else
		auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
#endif
		data->setOwner_id(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		std::string fileName = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/"+resultSet->getString(3);
		data->setFile_real_name(fileName);
		//data->setFile_real_name(URIUtil::urlDecode(fileName));
		data->setSex(resultSet->getString(4));
		data->setId_card(resultSet->getString(5));
		data->setLink(resultSet->getString(6));
		data->setAddress(resultSet->getString(7));
		data->setHouse_num(resultSet->getInt(8));
		data->setMember_num(resultSet->getInt(9));
		data->setCar_number(resultSet->getInt(10));
		data->setComplaint_num(resultSet->getInt(11));
		data->setRepair_num(resultSet->getInt(12));
		data->setAmount_owed(resultSet->getString(13));
		data->setContract_num(resultSet->getInt(14));
		data->setAccess_control_key(resultSet->getString(15));
		return data;
	}
};

#endif
