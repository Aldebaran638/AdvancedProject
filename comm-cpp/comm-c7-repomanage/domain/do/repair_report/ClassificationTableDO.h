#pragma once
#ifndef _CLASSIFICATIONTABlE_DO_H
#define _CLASSIFICATIONTABlE_DO_H
#include "../DoInclude.h"

class ClassificationTableDO {	
	CC_SYNTHESIZE(string, public_area,PublicArea);
	CC_SYNTHESIZE(string, repair_type_name,RepairTypeName);
	CC_SYNTHESIZE(int, type_count,TypeCount);
public:
	ClassificationTableDO() {
		repair_type_name = " ";
		public_area = " ";
		type_count = 0;
	}
	ClassificationTableDO(string repair_type_name,string public_area,int type_count) {
		this->repair_type_name=repair_type_name;
		this->public_area=public_area;
		this->type_count =type_count;
	}
};
typedef std::shared_ptr<ClassificationTableDO> PtrClassificationTableDO;
#endif // !_CLASSIFICATIONTABlE_DO_H
