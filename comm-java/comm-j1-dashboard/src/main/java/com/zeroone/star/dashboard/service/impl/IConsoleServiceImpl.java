package com.zeroone.star.dashboard.service.impl;

import com.zeroone.star.dashboard.entity.*;
import com.zeroone.star.dashboard.mapper.*;
import com.zeroone.star.dashboard.service.IConsoleService;
import com.zeroone.star.project.vo.j1.dashboard.console.*;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import java.util.*;
import java.util.concurrent.TimeUnit;

import static com.zeroone.star.project.constant.DashBoardConstant.*;

/**
 * 控制台数据统计服务实现类(允许传来的参数：communityId，tel)
 */
@Service
@Slf4j
@RequiredArgsConstructor
public class IConsoleServiceImpl implements IConsoleService {



    private final RRepairPoolMapper rRepairPoolMapper;


    private final ComplaintMapper complaintMapper;


    private final BuildingOwnerMapper buildingOwnerMapper;


    private final TDictMapper dictMapper;


    private final NotepadMapper notepadMapper;


    private final RedisTemplate<String, Object> redisTemplate;


    private final BusinessCommunityInfoMapper businessCommunityInfoMapper;


    private final BusinessCommunityMapper businessCommunityMapper;



    @Override
    public RepairStatisticsVO getAllRepairStats(String tel) {


//        // 尝试从缓存中获取数据,相关常量定义请看DashBoardConstant
        String cacheKey = CACHE_KEY_REPAIR_STATS + ":" + tel;
        RepairStatisticsVO cachedResult = (RepairStatisticsVO) redisTemplate.opsForValue().get(cacheKey);

        if (cachedResult != null) {
            return cachedResult;
        }

        // 查询 table_name 为 r_repair_pool 且 table_columns 为 state 的所有记录
        List<TDict> allRepairStatuses = dictMapper.selectByTableNameAndColumn("r_repair_pool", "state");
        List<RRepairPool> entityList = null;
        //此刻传来的是电话号码
        if(tel.length() == 11) {
            String communityId = businessCommunityMapper.getCommunityIdByTel(tel);
            // 查询所有投诉统计实体数据
            entityList = rRepairPoolMapper.selectAll(communityId);
        } else if(tel.length() > 11){
            //此刻传来的是小区编号
            String communityId = tel;
            // 查询所有投诉统计实体数据
            entityList = rRepairPoolMapper.selectAll(communityId);
        }
        // 初始化计数器
        int totalRepairs = 0;
        int pendingAssignments = 0;
        int processing = 0;
        int processed = 0;

        // 遍历实体列表进行统计
        if (entityList != null) {
            totalRepairs = entityList.size();
            for (RRepairPool entity : entityList) {
                String state = entity.getState();
                for (TDict status : allRepairStatuses) {
                    String statusCd = status.getStatusCd();
                    String statusName = status.getName();
                    if (statusCd.equals(state) && statusName.equals(REPAIR_STATUS_UNASSIGNED)) {
                        pendingAssignments++;
                    } else if (statusCd.equals(state) && (Integer.parseInt(statusCd) > 1000) && (Integer.parseInt(statusCd) < 1900)) {
                        processing++;
                    } else if (statusCd.equals(state)) {
                        processed++;
                    }
                }
            }
        }
        // 构建 RepairStatisticsVO
        RepairStatisticsVO vo = RepairStatisticsVO.builder()
                .allRepairs(totalRepairs)
                .pendingRepairs(pendingAssignments)
                .processingRepairs(processing)
                .processedRepairs(processed)
                .build();
        SaveCache(cacheKey, vo, 5, TimeUnit.MINUTES);
        return vo;
    }


    @Override
    public ComplaintStatisticsVO getAllComplaintStats(String tel) {
        String cacheKey = CACHE_KEY_COMPLAINT_STATS + ":" + tel;
        ComplaintStatisticsVO cachedResult = (ComplaintStatisticsVO) redisTemplate.opsForValue().get(cacheKey);

        if (cachedResult != null) {
            return cachedResult;
        }

        // 查询 table_name 为 complaint 且 table_columns 为 state 的所有记录
        List<TDict> allComplaintStatuses = dictMapper.selectByTableNameAndColumn("complaint", "state");


        // 初始化计数器
        int totalComplaints = 0;
        int processingComplaints = 0;
        int processedComplaints = 0;
        List<Complaint> entityList = null;
        if(tel.length() == 11) {
            String communityId = businessCommunityMapper.getCommunityIdByTel(tel);
            // 查询所有投诉统计实体数据
            entityList = complaintMapper.selectAll(communityId);
        }else if(tel.length() > 11){
            String communityId = tel;
            // 查询所有投诉统计实体数据
            entityList = complaintMapper.selectAll(communityId);
        }
        // 遍历实体列表进行统计
        if (entityList != null) {
            totalComplaints = entityList.size();
            for (Complaint entity : entityList) {
                String state = entity.getState();
                for (TDict status : allComplaintStatuses) {
                    String statusName = status.getName();
                    String statusCd = status.getStatusCd();
                    if (statusCd.equals(state) && statusName.equals(COMPLAINT_STATUS_PROCESSING)) {
                        processingComplaints++;
                    } else if (statusName.equals(COMPLAINT_STATUS_COMPLETED)) {
                        processedComplaints++;
                    }
                }
            }
        }
        // 构建 ComplaintStatisticsVO
        ComplaintStatisticsVO vo = ComplaintStatisticsVO.builder()
                .totalComplaints(totalComplaints)
                .processingComplaints(processingComplaints)
                .processedComplaints(processedComplaints)
                .build();
        SaveCache(cacheKey, vo, 5, TimeUnit.MINUTES);
        return vo;
    }


    @Override
    public ResidentRegistrationStatisticsVO getAllRegistrationStats(String tel) {
        String cacheKey = CACHE_KEY_REGISTER_STATS +  ":" + tel;
        ResidentRegistrationStatisticsVO cachedResult = (ResidentRegistrationStatisticsVO) redisTemplate.opsForValue().get(cacheKey);
        if (cachedResult != null) {
            return cachedResult;
        }

        String communityId = "";
        if(tel.length() == 11) {
            communityId = businessCommunityMapper.getCommunityIdByTel(tel);
        }else if(tel.length() > 11){
            communityId = tel;
        }
        Integer registeredCount = buildingOwnerMapper.getRegisteredCount(communityId);
        Integer unregisteredCount = buildingOwnerMapper.getUnregisteredCount(communityId);
        Integer unboundCount = buildingOwnerMapper.getUnboundCount(communityId);
        Integer boundCount = buildingOwnerMapper.getBoundCount(communityId);
        ResidentRegistrationStatisticsVO vo = ResidentRegistrationStatisticsVO.builder()
                .registeredCount(registeredCount)
                .unregisteredCount(unregisteredCount)
                .unboundHouseCount(unboundCount)
                .boundHouseCount(boundCount)
                .build();
        SaveCache(cacheKey, vo, 5, TimeUnit.MINUTES);
        return vo;

    }


    @Override
    public BusinessCommunityInfoVO getAllBusinessCommunitys(String tel) {
        //  缓存
        String cacheKey = CACHE_KEY_BUSINESS_COMMUNITY  + ":" + tel;
        BusinessCommunityInfoVO cachedResult = (BusinessCommunityInfoVO) redisTemplate.opsForValue().get(cacheKey);
        if (cachedResult != null) {
            return cachedResult;
        }
        String  communityId = "";
        if(tel.length() == 11) {
            communityId = businessCommunityMapper.getCommunityIdByTel(tel);
        }else if(tel.length() > 11){
            communityId = tel;
        }

        List<BuildingOwner> userIds = businessCommunityInfoMapper.selectAllUserIdByCommunityId(communityId);
        log.info("查询到的 userIds: {}", userIds);
        for (BuildingOwner bo : userIds) {
            log.debug("User ID: {}", bo.getUserId());
        }

        int totalStoreCount = 0;
        int totalBuildingCount = 0;

        for (BuildingOwner userId : userIds) {
            totalBuildingCount += businessCommunityInfoMapper.getBuildingUnitCount(userId.getUserId());
            totalStoreCount += businessCommunityInfoMapper.getSStoreCount(userId.getUserId());
        }

        //  查询所有小区信息
        BusinessCommunityInfoVO vo = BusinessCommunityInfoVO.builder()
                .vehicleCount(businessCommunityInfoMapper.getOwnerCarCount(communityId))
                .buildingCount(totalBuildingCount)
                .houseCount(businessCommunityInfoMapper.getBuildingRoomCount(communityId))
                .shopCount(totalStoreCount)
                .parkingCount(businessCommunityInfoMapper.getParkingSpaceCount(communityId))
                .build();
        // 将结果存储到缓存
        SaveCache(cacheKey, vo, 5, TimeUnit.MINUTES);
        return vo;
    }

    @Override
    public List<OwnerFeedbackVO> getAllOwnerFeedback(String tel) {
        // 尝试从缓存中获取数据
        String cacheKey = CACHE_KEY_OWNER_FEEDBACK  + ":" + tel;
        List<OwnerFeedbackVO> cachedResult = (List<OwnerFeedbackVO>) redisTemplate.opsForValue().get(cacheKey);

        if (cachedResult != null) {
            return cachedResult;
        }
        String communityId = "";
        if( tel.length() == 11) {
            communityId = businessCommunityMapper.getCommunityIdByTel(tel);
        }else if(tel.length() > 11){
            communityId = tel;
        }
        List<OwnerFeedbackVO> result = new ArrayList<OwnerFeedbackVO>();
        List<BuildingOwner> userIds = businessCommunityInfoMapper.selectAllUserIdByCommunityId(communityId);
        log.info("查询到的 userIds: {}", userIds);
        for (BuildingOwner bo : userIds) {
            log.debug("User ID: {}", bo.getUserId());
        }
        for (BuildingOwner userId : userIds) {
            List<Notepad> notepadList = notepadMapper.selectList(userId.getUserId());
            if (notepadList != null) {
                for (Notepad notepad : notepadList) {
                    String statusName = notepad.getState();
                    OwnerFeedbackVO vo = OwnerFeedbackVO.builder()
                            .objName(notepad.getObjName())// 用户名称
                            .roomName(notepad.getRoomName())//  房屋名称
                            .title(notepad.getTitle())       // 反馈内容
                            .state(statusName.equals(FEEDBACK_STATUS)? FEEDBACK_STATUS_FOLLOWING : FEEDBACK_STATUS_COMPLETED)              // 状态名称
                            .createTime(String.valueOf(notepad.getCreateTime())) // 创建时间
                            .build();
                    result.add(vo);
                }
            }
        }
        // 4. 缓存并返回
        SaveCache(cacheKey, result , 5 , TimeUnit.MINUTES);
        return result;
    }


    public void SaveCache(String cacheKey, Object result , int expiration , TimeUnit timeUnit){
        redisTemplate.opsForValue().set(cacheKey, result, expiration, timeUnit);
    }



}