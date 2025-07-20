package com.zeroone.star.orgmanager.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddShiftSettingDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ShiftSettingDTO;
import com.zeroone.star.project.query.j4.orgmanager.ShiftSettingQuery;
import com.zeroone.star.project.vo.j4.orgmanager.ShiftSettingVO;
import com.zeroone.star.project.dto.j4.orgmanager.ClassManagerDTO;
import com.zeroone.star.project.vo.j4.orgmanager.ClassManagerVO;
import java.util.List;

public interface ShiftSettingService {
    List<ShiftSettingDTO> listClassName();

    PageDTO<ShiftSettingVO> listClass(ShiftSettingQuery query);

    String addShiftSetting(AddShiftSettingDTO addShiftSettingDTO);

    ClassManagerVO getByClassId(String classId);

    boolean updateClasses(ClassManagerDTO classManagerDTO);

    boolean removeByClassId(String classId);

    boolean updateClassesStatus(String classId);


}
