#pragma once
#ifndef _HOUSEFEEMGRQUERY_H_
#define _HOUSEFEEMGRQUERY_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class HouseFeeMgrQuery :public PageQuery
{
	DTO_INIT(HouseFeeMgrQuery, PageQuery);

	//社区号
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("HouseFeeMgr.field.communityId"));
	//房屋号
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("HouseFeeMgr.field.roomNum"));
	////状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("HouseFeeMgr.field.status"));
	//业主名字
	API_DTO_FIELD_DEFAULT(String, ownerNameLike, ZH_WORDS_GETTER("HouseFeeMgr.field.ownerNameLike"));
};
class HouseFeeMgrQueryByRoom :public PageQuery
{
	DTO_INIT(HouseFeeMgrQueryByRoom, PageQuery);

	//社区号
	API_DTO_FIELD_DEFAULT(String, communityId, ZH_WORDS_GETTER("HouseFeeMgr.field.communityId"));
	//房屋号
	API_DTO_FIELD_DEFAULT(String, roomNum, ZH_WORDS_GETTER("HouseFeeMgr.field.roomNum"));
	////状态
	//API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("HouseFeeMgr.field.status"));
	//业主名字
	//API_DTO_FIELD_DEFAULT(String, ownerNameLike, ZH_WORDS_GETTER("HouseFeeMgr.field.ownerNameLike"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_HOUSEFEEMGRQUERY_H_
