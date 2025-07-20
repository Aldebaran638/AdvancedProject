package com.zeroone.star.orgmanager.service.impl;

import cn.hutool.core.lang.Snowflake;
import cn.hutool.core.util.IdUtil;
import com.alibaba.nacos.common.utils.CollectionUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.orgmanager.entity.AssociatedPersonnelClasses;
import com.zeroone.star.orgmanager.mapper.AssociatedPersonnelMapper;
import com.zeroone.star.orgmanager.mapper.SchedulingTableMapper;
import com.zeroone.star.orgmanager.service.AssociatedPersonnelService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddAssociatedPersonnelDTO;
import com.zeroone.star.project.query.j4.orgmanager.PersonnelScheduleQuery;
import com.zeroone.star.project.vo.j4.orgmanager.PersonnelSchedulingVO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.util.stream.Collectors;

@Service
public class AssociatedPersonnelServiceImpl implements AssociatedPersonnelService {
    @Autowired
    private AssociatedPersonnelMapper associatedPersonnelMapper;
    @Autowired
    private SchedulingTableMapper schedulingTableMapper;
    @Transactional
    @Override
    public void addAssociatedPersonnel(AddAssociatedPersonnelDTO dto) {
        // 1. 转换DTO为Entity
        AssociatedPersonnelClasses entity = new AssociatedPersonnelClasses();
        BeanUtils.copyProperties(dto, entity);
        // 2. 设置默认值
        entity.setStatusCd(1); // 默认为有效状态
        entity.setCreateTime(new Date());
        // 3. 雪花算法生成唯一ID
        Snowflake snowflake = IdUtil.createSnowflake(1, 1);
        String scsId = String.valueOf(snowflake.nextId()); // 生成19位数字ID
        entity.setScsId(scsId);
        // 4. 插入数据库
        associatedPersonnelMapper.insertAssociatedPersonnel(entity);
    }

    @Transactional
    @Override
    public boolean deleteAssociatedPersonnel(String staffId, String scheduleId) {
        // 1. 构建参数Map
        Map<String, Object> params = new HashMap<>();
        params.put("staffId", staffId);
        params.put("scheduleId", scheduleId);
        // 2. 执行逻辑删除
        int rows = associatedPersonnelMapper.deleteByClassesAndStaffId(params);
        return rows > 0;
    }
    @Transactional
    @Override
    public PageDTO<PersonnelSchedulingVO> listPersonnelScheduling(PersonnelScheduleQuery query) {
        // 校验查询参数
        if (query.getYear() == null || query.getMonth() == null) {
            LocalDate now = LocalDate.now();
            query.setYear(now.getYear());
            query.setMonth(now.getMonthValue());
        }
        // 计算当月天数
        YearMonth yearMonth = YearMonth.of(query.getYear(), query.getMonth());
        // 创建 MyBatis-Plus 分页对象
        Page<PersonnelSchedulingVO> page = new Page<>(
                query.getPageIndex(),  // 继承自 PageQuery
                query.getPageSize()    // 继承自 PageQuery
        );
        // 执行分页查询
        IPage<PersonnelSchedulingVO> result = schedulingTableMapper.selectAttendanceSchedule(page, query);
        // 处理查询结果
        List<PersonnelSchedulingVO> records = result.getRecords();
        if (CollectionUtils.isNotEmpty(records)) {
            // 按员工ID分组，构建日历视图
            Map<String, List<PersonnelSchedulingVO>> staffScheduleMap = records.stream()
                    .collect(Collectors.groupingBy(PersonnelSchedulingVO::getStaffId));
            // 日期格式化器
            DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            ZoneId zoneId = ZoneId.systemDefault();
            // 重新构建返回结果
            List<PersonnelSchedulingVO> processedRecords = new ArrayList<>();
            staffScheduleMap.forEach((staffId, schedules) -> {
                PersonnelSchedulingVO staffVO = schedules.get(0);
                // 构建员工完整排班详情，处理日期格式转换
                Map<String, String> scheduleDetails = schedules.stream()
                        .filter(vo -> vo.getAttendanceDate() != null) // 过滤空日期
                        .collect(Collectors.toMap(
                                vo -> {
                                    // 将 Date 转换为 LocalDate 再格式化为字符串
                                    Instant instant = vo.getAttendanceDate().toInstant();
                                    LocalDate localDate = instant.atZone(zoneId).toLocalDate();
                                    return localDate.format(dateFormatter);
                                },
                                PersonnelSchedulingVO::getScheduleTime,
                                (existing, replacement) -> existing // 处理重复日期的策略
                        ));
                staffVO.setScheduleDetails(scheduleDetails);
                processedRecords.add(staffVO);
            });
            // 更新结果记录
            result.setRecords(processedRecords);
        }
        // 转换为自定义分页对象
        PageDTO<PersonnelSchedulingVO> pageResult = new PageDTO<>();
        pageResult.setPageIndex(result.getCurrent());
        pageResult.setPageSize(result.getSize());
        pageResult.setRows(result.getRecords());
        pageResult.setTotal(result.getTotal());

        return pageResult;
    }
}
