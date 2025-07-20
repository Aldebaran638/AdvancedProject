package com.zeroone.star.communitymanage.service.notepad;

import com.zeroone.star.project.dto.j5.community.notepad.RepairTypeDTO;
import com.zeroone.star.project.query.j5.community.notepad.RepairTypeQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface RepairTypeService {

    JsonVO<List<RepairTypeDTO>> queryRepairType(RepairTypeQuery repairQuery);


}
