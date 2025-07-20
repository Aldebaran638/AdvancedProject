package com.zeroone.star.project.j4.orgmanager;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddShiftSettingDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ClassManagerDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ShiftSettingDTO;
import com.zeroone.star.project.query.j4.orgmanager.ShiftSettingQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.ClassManagerVO;
import com.zeroone.star.project.vo.j4.orgmanager.ShiftSettingVO;
import io.swagger.annotations.ApiModelProperty;

import java.util.List;

/**
 * @Author: dashuai
 * @Description:
 * 包含获取班次名称列表、获取班次列表、添加班次、修改班次、删除班次、启用/停用班次
 *
 * 负责人：
 * zzw3867、@@@
 */
public interface ShiftSettingApis {

    /**
     * @Author:zzw3867
     * 获取班次名称列表
     * 涉及表：classes_time表、classes表
     * 商户id(store_id)应该从前端传过来
     * 名称获取规则(商户编号，状态=1001，数据状态=0)
     * 时段获取规则(班次编号，数据状态=0)(时段展示注意前端格式，eg 6:00~12:00)
     * @return JsonVO<List < ShiftSettingVO>>
     */
    JsonVO<List<ShiftSettingDTO>> listShiftSettingName();
    /**
     * @Author:zzw3867
     * 获取班次列表(条件+分页)
     * 涉及表：classes_time表、classes表
     * 商户id(store_id)应该从前端传过来
     * 其余获取规则(商户编号，数据状态=0，有条件就加条件)
     * 时段获取规则(班次编号，数据状态=0)(时段展示注意前端格式，eg 6:00~12:00)
     * @return JsonVO<List < ShiftSettingVO>>
     */
    JsonVO<PageDTO<ShiftSettingVO>> listShiftSetting(ShiftSettingQuery query);
    /**
     * @Author:zzw3867
     * 添加班次
     * 涉及表：classes_time表、classes表
     * 商户id(store_id)应该从前端传过来
     * 班次id(主键)自动生成，状态，数据状态以及创建时间在service层处理
     * 先添加班次(classes)，再添加时段(classes_time)
     * (其中，在班次添加开始时间，结束时间的时候，要想添加多个时间段，
     * 要设置数据状态（status_cd）为0)
     * @return JsonVO<String>
     */
    JsonVO<String> addShiftSetting(AddShiftSettingDTO addShiftSettingDTO);

    /**
     * 通过classId得到相应班次信息和班次时间(回显操作)
     * @param classId
     * @return
     */
    JsonVO<ClassManagerVO> queryByClassId(String classId);

    /**
     * 更新班次信息和时间段
     * @param classManagerDTO
     * @return String (success/fail)
     */
    JsonVO<String> modifyClass(ClassManagerDTO classManagerDTO);

    /**
     * 根据classId删除对应的班次信息
     * @param classId
     * @return String (success/fail)
     */
    JsonVO<String> removeByClassId(String classId);

    /**
     * 根据classId修改对应的班次的状态
     * @param classId
     * @return String (success/fail)
     */
    JsonVO<String> modifyClassStatus(String classId);

}
