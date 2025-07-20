#pragma once
#ifndef _OERPAYDETDTO_H_
#define _OERPAYDETDTO_H_

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)    //启用DTO宏定义

//查询参数DTO

class OerPayDetQueryDTO : public oatpp::DTO
{
	DTO_INIT(OerPayDetQueryDTO, DTO)

	API_DTO_FIELD_DEFAULT(String, feeCategory, ZH_WORDS_GETTER("oerpaydet-catalog.field.feeCategory"));         //收费大类
	API_DTO_FIELD_DEFAULT(String, feeItem, ZH_WORDS_GETTER("oerpaydet-catalog.field.feeItem"));                //收费项目
	API_DTO_FIELD_DEFAULT(String, roomNumber, ZH_WORDS_GETTER("oerpaydet-catalog.field.roomNumber"));          //房屋编号
	API_DTO_FIELD_DEFAULT(String, ownerName, ZH_WORDS_GETTER("oerpaydet-catalog.field.ownerName"));            //业主名称
	API_DTO_FIELD_DEFAULT(String, year, ZH_WORDS_GETTER("oerpaydet-catalog.field.year"));                      //年份

};

//单条业主缴费明细

class OerPayDetDetailDTO : public OerPayDetQueryDTO
{
	DTO_INIT(OerPayDetDetailDTO, DTO)

	// 各月缴费金额 
	API_DTO_FIELD_DEFAULT(String, month1, ZH_WORDS_GETTER("oerpaydet-export.field.month1"));
	API_DTO_FIELD_DEFAULT(String, month2, ZH_WORDS_GETTER("oerpaydet-export.field.month2"));
	API_DTO_FIELD_DEFAULT(String, month3, ZH_WORDS_GETTER("oerpaydet-export.field.month3"));
	API_DTO_FIELD_DEFAULT(String, month4, ZH_WORDS_GETTER("oerpaydet-export.field.month4"));
	API_DTO_FIELD_DEFAULT(String, month5, ZH_WORDS_GETTER("oerpaydet-export.field.month5"));
	API_DTO_FIELD_DEFAULT(String, month6, ZH_WORDS_GETTER("oerpaydet-export.field.month6"));
	API_DTO_FIELD_DEFAULT(String, month7, ZH_WORDS_GETTER("oerpaydet-export.field.month7"));
	API_DTO_FIELD_DEFAULT(String, month8, ZH_WORDS_GETTER("oerpaydet-export.field.month8"));
	API_DTO_FIELD_DEFAULT(String, month9, ZH_WORDS_GETTER("oerpaydet-export.field.month9"));
	API_DTO_FIELD_DEFAULT(String, month10, ZH_WORDS_GETTER("oerpaydet-export.field.month10"));
	API_DTO_FIELD_DEFAULT(String, month11, ZH_WORDS_GETTER("oerpaydet-export.field.month11"));
	API_DTO_FIELD_DEFAULT(String, month12, ZH_WORDS_GETTER("oerpaydet-export.field.month12"));

	API_DTO_FIELD_DEFAULT(Float64, totalAmount, ZH_WORDS_GETTER("oerpaydet-export.field.total"));             // 合计
	API_DTO_FIELD_DEFAULT(Float64, receivable, ZH_WORDS_GETTER("oerpaydet-export.field.receivable"));         // 应收
	API_DTO_FIELD_DEFAULT(Float64, prepaid, ZH_WORDS_GETTER("oerpaydet-export.field.prepaid"));               // 预收
};

//分页响应DTO

class OerPayDetPageDTO : public PageDTO<OerPayDetDetailDTO::Wrapper>
{
	DTO_INIT(OerPayDetPageDTO, PageDTO<OerPayDetDetailDTO::Wrapper>);

	//API_DTO_FIELD_DEFAULT(Int32, total, ZH_WORDS_GETTER("total"));                                       // 总条数
	//API_DTO_FIELD_DEFAULT(Int32, pageNo, ZH_WORDS_GETTER("pageNo"));                                     // 当前页
	//API_DTO_FIELD_DEFAULT(Int32, pageSize, ZH_WORDS_GETTER("pageSize"));                                 // 每页数量
	//API_DTO_FIELD_DEFAULT(Vector<oatpp::Object<PaymentDetailDTO>>, records, ZH_WORDS_GETTER("records")); // 表格数据
};

#include OATPP_CODEGEN_END(DTO)

#endif
