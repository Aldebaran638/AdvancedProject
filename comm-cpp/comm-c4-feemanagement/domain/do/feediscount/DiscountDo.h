#ifndef _FEE_DISCOUNT_DO_H_
#define _FEE_DISCOUNT_DO_H_

#include "../DoInclude.h"


//对应数据库fee_discount(1)和fee_discout_spec(2)   
//！！插入，修改，删除直接用 ！！ 在分页查询完后将下面两个转为这个。
class DiscountDo {
	//discount_id	(1)(2)	打折ID	
	CC_SYNTHESIZE(string,discount_id,DiscountId);
	
	//community_id	(1)(2)	小区ID
	CC_SYNTHESIZE(string,community_id,CommunityId);

	//discount_type	(1)	折扣类型
	CC_SYNTHESIZE(string,discount_type,DiscountType);

	//discount_name	(1)	折扣名称
	CC_SYNTHESIZE(string,discount_name,DiscountName);

	//rule_id (1)	规则ID
	CC_SYNTHESIZE(string,rule_id,RuleId);

	//rule_id (1)	规则名称
	CC_SYNTHESIZE(string, rule_name, RuleName); //分页查询时用的

	//discount_desc (1)	打折说明
	CC_SYNTHESIZE(string,discount_desc,DiscountDesc);

	//create_time (1)(2)	创建时间
	CC_SYNTHESIZE(string,create_time,CreateTime);

	//status_cd	(1)(2)	数据状态
	CC_SYNTHESIZE(string,status_cd,StatusCd);

	//discount_spec_id  (2) 主键ID
	CC_SYNTHESIZE(std::vector<std::string>,discount_spec_id,DiscountSpecId);

	//spec_id	(2)	规格ID
	CC_SYNTHESIZE(std::vector<std::string>,spec_id,SpecId);

	//spec_name	(2)	规格名称
	CC_SYNTHESIZE(std::vector<std::string>,spec_name,SpecName);

	//spec_value	(2)	规格值
	CC_SYNTHESIZE(std::vector<std::string>,spec_value,SpecValue);
};

//分页查询用
class DiscountPageDo {
	//discount_id	(1)(2)	打折ID	
	CC_SYNTHESIZE(string, discount_id, DiscountId);

	//discount_name	(1)	折扣名称
	CC_SYNTHESIZE(string, discount_name, DiscountName);

	//discount_type	(1)	折扣类型
	CC_SYNTHESIZE(string, discount_type, DiscountType);

	//rule_id (1)	规则ID
	CC_SYNTHESIZE(string, rule_id, RuleId);

	//rule_id (1)	规则名
	CC_SYNTHESIZE(string, rule_name, RuleName);

	//create_time (1)(2)	创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
};

class DiscountSpecPageDo {
	//spec_name	(2)	规格名称
	CC_SYNTHESIZE(string, spec_name, SpecName);

	//spec_value	(2)	规格值
	CC_SYNTHESIZE(string, spec_value, SpecValue);
};

#endif