#pragma once
#ifndef _DISSATISFIEDREPAIR_DO_H_
#define _DISSATISFIEDREPAIR_DO_H_
#include "../DoInclude.h"

class DissatisfiedRepairDO {
	CC_SYNTHESIZE(string, repair_time, RepairTime);
	CC_SYNTHESIZE(string, repair_location, RepairLocation);
	CC_SYNTHESIZE(string, repair_id, RepairId);
	CC_SYNTHESIZE(string, status, Status);
	CC_SYNTHESIZE(string, reason, Reason);
public:
	DissatisfiedRepairDO() {
		repair_time = "";
		repair_location = "";
		repair_id = "";
		status = "";
		reason = "";
	}
	DissatisfiedRepairDO(string repair_time, string repair_location, string repair_id, string status, string reason) {
		this->repair_time = repair_time;
		this->repair_location = repair_location;
		this->repair_id = repair_id;
		this->status = status;
		this->reason = reason;
	}
};
typedef std::shared_ptr<DissatisfiedRepairDO> PtrDissatisfiedRepairDO;

#endif // _DISSATISFIEDREPAIR_DO_H_
