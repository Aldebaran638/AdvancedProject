package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.zeroone.star.orgmanager.entity.Classes;
import com.zeroone.star.orgmanager.entity.ClassesTime;
import com.zeroone.star.orgmanager.mapper.ShiftSettingMapper;
import com.zeroone.star.orgmanager.service.ShiftSettingService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddShiftSettingDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ClassManagerDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ShiftSettingDTO;
import com.zeroone.star.project.query.j4.orgmanager.ShiftSettingQuery;
import com.zeroone.star.project.vo.j4.orgmanager.ClassManagerVO;
import com.zeroone.star.project.vo.j4.orgmanager.ShiftSettingVO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.beans.Transient;
import java.sql.Timestamp;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.util.*;


@Service
public class ShiftSettingServiceImpl implements ShiftSettingService {

    String userId;
    private static final String STATE_ENABLE = "1001";
    private static final String STAYUSCD_ENABLE = "0";
    private static final String BID_ENABLE = "-1";

    @Resource
    private UserHolder userHolder;
    @Resource
    private ShiftSettingMapper shiftSettingMapper;

    /**
     * 获取当前登录用户的id
     */
    private String getLoginUserId(){
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if (currentUser != null && currentUser.getId() != null) {
                userId = String.valueOf(currentUser.getId());
            }else{
                throw new RuntimeException("无法获取当前用户ID");
            }
        } catch (Exception e) {
            throw new RuntimeException("获取用户信息失败", e);
        }
        return userId;
    }

    /**
     * 获取班次名称列表
     * @return
     */
    @Override
    public List<ShiftSettingDTO> listClassName() {
        Classes  classes = Classes.builder()
                .storeId(getLoginUserId())
                .state(STATE_ENABLE)
                .statusCd(STAYUSCD_ENABLE)
                .build();
        //根据相关信息查询DTO数据返回List的Map数据，eg[ {"name":"zhangsan1","time":"6:00~11:00, 15:00~20:00"},
        //                                       {"name":"zhangsan2","time":"11:00~18:00"},                              ]
        List<Map<String, Object>> mapList = shiftSettingMapper.listClassWithTime(classes);

        //把List的Map数据封装到DTO数据中，并返回List
        List<ShiftSettingDTO> list = new ArrayList<>();
        for (Map<String,Object> map : mapList){
            ShiftSettingDTO shiftSettingDTO = new ShiftSettingDTO();
            shiftSettingDTO.setName(map.get("name").toString());
            //把String类型的时间段数据转换成List
            String workTime = map.get("workTime").toString();
            if (workTime!=null)
                shiftSettingDTO.setWorkTime(Arrays.asList(workTime.split(",")));
            else
                shiftSettingDTO.setWorkTime(new ArrayList<>());
            list.add(shiftSettingDTO);
        }
        return list;
    }

    /**
     *获取班次列表(条件+分页)
     * @param query
     * @return
     */
    @Override
    public PageDTO<ShiftSettingVO> listClass(ShiftSettingQuery query) {
        PageHelper.startPage((int) query.getPageIndex(), (int) query.getPageSize());

        Classes classes = Classes.builder()
                .storeId(getLoginUserId())
                .name(query.getName())
                .state(STATE_ENABLE)
                .statusCd(STAYUSCD_ENABLE)
                .build();
        List<Map<String,Object>> MaplistClass = shiftSettingMapper.listClassWithTime(classes);

        //获取PageHelper生成的分页信息
        PageInfo<Map<String,Object>> pageInfo = new PageInfo<>(MaplistClass);

        List<ShiftSettingVO> shiftSettingVOList = new ArrayList<>();
        for(Map<String,Object> map : MaplistClass){
            ShiftSettingVO shiftSettingVO = ShiftSettingVO.builder()
                    .classesId(String.valueOf(map.get("classesId")))
                    .name(String.valueOf(map.get("name")))
                    .state(STATE_ENABLE.equals(String.valueOf(map.get("state")))?"启用":"停用")
                    .remark(String.valueOf(map.get("remark")))
                    .createTime(map.get("createTime") instanceof Timestamp ? (Timestamp) map.get("createTime") : null)
                    .build();
            //获取工作时间段
            String ListWorkTime = map.get("workTime").toString();
            if (ListWorkTime!=null)
                shiftSettingVO.setWorkTime(Arrays.asList(ListWorkTime.split(",")));
            else
                shiftSettingVO.setWorkTime(new ArrayList<>());
            shiftSettingVOList.add(shiftSettingVO);
        }
        //封装分页结果
        PageDTO<ShiftSettingVO> result = new PageDTO<>();
        result.setPageIndex((long) pageInfo.getPageNum());  // 当前页码
        result.setPageSize((long) pageInfo.getPageSize()); // 每页条数
        result.setTotal(pageInfo.getTotal());              // 总条数
        result.setPages((long) pageInfo.getPages());       // 总页数
        result.setRows(shiftSettingVOList);                // 数据列表
        return result;
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public String addShiftSetting(AddShiftSettingDTO addShiftSettingDTO) {
        String classesId = "10"+generateId();
        //添加班次信息
        Classes classes = Classes.builder()
                .classesId(classesId)
                .bId(BID_ENABLE)
                .name(addShiftSettingDTO.getName())
                .storeId(getLoginUserId())
                .state(STATE_ENABLE)
                .remark(addShiftSettingDTO.getRemark())
                .createTime(LocalDateTime.now(ZoneId.of("Asia/Shanghai")))
                .statusCd(STAYUSCD_ENABLE)
                .build();
        Boolean r1 = shiftSettingMapper.addClassesInfo(classes);
        if (!r1){
            throw new RuntimeException("添加班次信息失败");
        }
        //获取并添加班次工作上下班时间段信息
        List<String> workTimeList = addShiftSettingDTO.getWorkTime();
        for (int i = 0; i < workTimeList.size(); i++) {
            ClassesTime classesTime = ClassesTime.builder()
                    .timeId("11"+generateId())
                    .classesId(classesId)
                    .startTime(workTimeList.get(i).split("~")[0])
                    .endTime(workTimeList.get(i).split("~")[1])
                    .createTime(LocalDateTime.now(ZoneId.of("Asia/Shanghai")))
                    .statusCd(STAYUSCD_ENABLE)
                    .build();
            Boolean r2 = shiftSettingMapper.addClassesTimeInfo(classesTime);
            if (!r2){
                throw new RuntimeException("添加班次时间段信息失败");
            }
        }
        return "ok";
    }
    /**
     * 生成 classesId
     * @return
     */
    public static String generateId() {
        // 获取当前时间
        LocalDateTime now = LocalDateTime.now();
        // 格式化时间，例如 "2025-05-24"
        String formattedDate = now.format(DateTimeFormatter.ofPattern("yyyyMMdd"));
        // 生成8位随机数
        Random random = new Random();
        String randomNumber = String.format("%08d", random.nextInt(99999999) + 1); // 生成1到99999999之间的随机数，并确保是8位数
        // 拼接 classesId
        return formattedDate + randomNumber;
    }


    /**
     * 班次回显
     * @param classId
     * @return ClassManagerVO
     */
    @Override
    public ClassManagerVO getByClassId(String classId) {
        List<ClassesTime> classesTimeList = shiftSettingMapper.selectFromClassesTimeByClassId(classId);
        Classes classes = shiftSettingMapper.selectFromClassesByClassId(classId);

        List<String> timePeriod = new ArrayList<>();
        for(ClassesTime classesTime : classesTimeList){
            timePeriod.add(classesTime.getStartTime() + "~" + classesTime.getEndTime());
        }

        ClassManagerVO classManagerVO = new ClassManagerVO();
        classManagerVO.setClassId(classId);
        classManagerVO.setClassName(classes.getName());
        classManagerVO.setRemark(classes.getRemark());
        classManagerVO.setTimePeriods(timePeriod);

        return classManagerVO;
    }

    /**
     *
     * @param classManagerDTO
     * @return
     */
    @Override
    @Transient
    public boolean updateClasses(ClassManagerDTO classManagerDTO){

        List<ClassesTime> classesTimeList = new ArrayList<>();

        LocalDate now = LocalDate.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMdd");
        String time = now.format(formatter);

        List<String> timePeriods = classManagerDTO.getTimePeriods();

        String[] arr = null;
        for(String timePeriod : timePeriods){
            //生成一个随机的8位数
            //int randomNum = ThreadLocalRandom.current().nextInt(10000000, 100000000);
            ClassesTime classesTime = new ClassesTime();
            classesTime.setClassesId(classManagerDTO.getClassId());
            // 使用雪花算法生成主键Id
            classesTime.setTimeId(IdWorker.getIdStr());
            arr = timePeriod.split("~");
            classesTime.setStartTime(arr[0]);
            classesTime.setEndTime(arr[1]);
            classesTime.setCreateTime(LocalDateTime.now());
            classesTime.setStatusCd("1");
            classesTimeList.add(classesTime);
        }

        try {
            shiftSettingMapper.deleteClassesTimeByClassId(classManagerDTO.getClassId());
            shiftSettingMapper.insertClassesTimeBatch(classesTimeList);

            Classes classes = new Classes();
            classes.setName(classManagerDTO.getClassName());
            classes.setRemark(classManagerDTO.getRemark());
            classes.setClassesId(classManagerDTO.getClassId());
            shiftSettingMapper.updateClasses(classes);

        } catch (Exception e) {
            return false;
        }

        return true;
    }

    /**
     * 删除对应的班次信息
     * @param classId
     */
    @Override
    @Transient
    public boolean removeByClassId(String classId) {
        try{
            shiftSettingMapper.deleteClassesTimeByClassId(classId);
            shiftSettingMapper.deleteClassesByClassId(classId);
        }catch(Exception e){
            return false;
        }
        return true;
    }

    /**
     * 修改班次状态
     * @param classId
     */
    @Override
    public boolean updateClassesStatus(String classId) {
        Classes classes = shiftSettingMapper.selectFromClassesByClassId(classId);
        if(classes.getState().equals("1001")) classes.setState("2002");
        else classes.setState("1001");
        try{
            shiftSettingMapper.updateClassesState(classes);
        }catch(Exception e){
            return false;
        }
        return true;
    }
}
