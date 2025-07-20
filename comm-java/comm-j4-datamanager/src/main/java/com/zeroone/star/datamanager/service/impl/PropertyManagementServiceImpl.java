package com.zeroone.star.datamanager.service.impl;

import cn.hutool.core.util.IdUtil;
import cn.hutool.crypto.digest.BCrypt;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.github.xiaoymin.knife4j.core.util.CollectionUtils;
import com.zeroone.star.datamanager.entity.MMenuGroupCommunity;
import com.zeroone.star.datamanager.entity.SStore;
import com.zeroone.star.datamanager.mapper.PropertyManagementMapper;
import com.zeroone.star.datamanager.service.PropertyManagementService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.datamanager.CommunityMenuGroupDTO;
import com.zeroone.star.project.dto.j4.datamanager.CompanyDTO;
import com.zeroone.star.project.query.j4.datamanager.CompanyQuery;
import com.zeroone.star.project.query.j4.datamanager.JoinCommunityQuery;
import com.zeroone.star.project.query.j4.datamanager.NoJoinCommunityQuery;
import com.zeroone.star.project.vo.j4.datamanager.CommunityMenuGroup;
import com.zeroone.star.project.vo.j4.datamanager.CompanyVO;
import com.zeroone.star.project.vo.j4.datamanager.JoinCommunityVO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;

/**
 * @author Henry
 * @version 1.0
 * @program: comm-java
 * @create: 2025/5/23 下午2:40
 */
@Service
public class PropertyManagementServiceImpl implements PropertyManagementService {

    @Resource
    private PropertyManagementMapper propertyManagementMapper;
    @Resource
    private PropertyManagementServiceImpl self; // 注入自身的代理

    /**
     * 获取物业公司（条件+分页接口）
     *
     * @param query
     * @return
     */
    @Override
    public PageDTO<CompanyVO> getCompanyList(CompanyQuery query) {
        Long total = propertyManagementMapper.countCompanies(query);
        query.setPageIndex(1);
        query.setPageSize(10);

        // 如果是分页查询，查询数据
        List<CompanyVO> companyList = Collections.emptyList();
        if (query.getPageIndex() > 0 && query.getPageSize() > 0) {
            long offset = (query.getPageIndex() - 1) * query.getPageSize();
            companyList = propertyManagementMapper.getCompanyList(query, offset, query.getPageSize());
            // 计算总页数
            long totalPages = (total + query.getPageSize() - 1) / query.getPageSize();
            return new PageDTO<>(total, totalPages, query.getPageSize(), query.getPageIndex(), companyList);
        }

        // 处理非分页情况
        return new PageDTO<>(1L, query.getPageSize(), total, 1L, Collections.emptyList());
    }

    /**
     * 添加物业公司
     *
     * @param dto
     * @return
     */
    @Override
    public void addCompany(CompanyDTO dto) throws Exception {
        // 生成雪花ID
        String id = IdWorker.getIdStr();
        String userId = IdWorker.getIdStr();
        // 生成UUID作为userId
        SStore sStore = new SStore();
        sStore.setUserId(userId);
        sStore.setStoreId(id);
        sStore.setName(dto.getStoreName());
        sStore.setAddress(dto.getAddress());
        sStore.setTel(dto.getTel());
        sStore.setNearbyLandmarks(dto.getNearbyLandmarks());
        if (dto.getCreateDate() != null) {
            sStore.setCreateTime(dto.getCreateDate());
        }


        // 2. 处理关联的小区
        if (dto.getOpenCommunityName() != null) {
            // 检查小区是否存在
            MMenuGroupCommunity community = propertyManagementMapper.selectByCommunityNameAndId(dto.getOpenCommunityName());
            if (community == null) {
                throw new Exception("小区不存在");
            }
            sStore.setOpenCommunityName(community.getCommunityName());
        }

        // 处理功能权限
        if (CollectionUtils.isNotEmpty(dto.getFunctions())) {
            List<String> existFunctions = propertyManagementMapper.selectExistFunctions(dto.getFunctions());
            if (existFunctions.size() != dto.getFunctions().size()) {
                // 找出不存在的功能
                Set<String> existSet = new HashSet<>(existFunctions);
                List<String> invalidFunctions = dto.getFunctions().stream()
                        .filter(f -> !existSet.contains(f))
                        .collect(Collectors.toList());
                throw new Exception("以下功能权限不存在: " + String.join(", ", invalidFunctions));
            }
                sStore.setFunctions(dto.getFunctions());
        }


        propertyManagementMapper.insert(sStore);
    }

    /**
     * 修改物业公司
     *
     * @param dto
     * @return
     */
    @Override
    public SStore modifyCompany(CompanyDTO dto, String storeId) throws Exception {

        // 校验 storeId
        if (storeId == null || storeId.isEmpty()) {
            throw new IllegalArgumentException("storeId 不能为空");
        }
        Map<String, Object> params = new HashMap<>();
        params.put("storeId", storeId);
        params.put("userName", dto.getUserName());
        params.put("storeName", dto.getStoreName());
        params.put("address", dto.getAddress());
        params.put("tel", dto.getTel());
        params.put("createDate", dto.getCreateDate());
        params.put("nearbyLandmarks", dto.getNearbyLandmarks());

        // 执行更新操作
        int rows = propertyManagementMapper.updateByStoreId(params);
        if (rows == 0) {
            throw new RuntimeException("未找到该公司，修改失败");
        }

        // 查询并返回更新后的完整记录
        return propertyManagementMapper.selectByStoreId(storeId);
    }
    /**
     * 分页查询加入小区列表
     *
     * @param query
     * @return
     */
    @Override
    public PageDTO<JoinCommunityVO> queryJoinCommunityList(Long pageIndex, Long pageSize, JoinCommunityQuery query) {
        // 分页查询
        List<JoinCommunityVO> list = propertyManagementMapper.queryJoinCommunityList(pageIndex-1, pageSize, query);
        PageDTO<JoinCommunityVO> pageResult = new PageDTO<>();
        //当前页码
        pageResult.setPageIndex(pageIndex);
        //每页显示最大数据条数
        pageResult.setPageSize(pageSize);
        //数据
        pageResult.setRows(list);
        return pageResult;
    }

    /**
     * 查询未加入小区列表
     * @param query
     * @return
     */
    @Override
    public List<String> queryNoJoinCommunityList(NoJoinCommunityQuery query) {
        // 查询
        return propertyManagementMapper.queryNoJoinCommunityList(query);
    }

    /**
     * 加入小区
     * @param dto
     */
    @Override
    @Transactional
    public void becomeJoinCommunity(CommunityMenuGroupDTO dto) {
        // 加入小区
        propertyManagementMapper.updateJoinCommunity(dto.getCommunityId());
        // 更新小区功能
        self.insertMenuGroupCommunity(dto);
    }


    /**
     * 退出小区
     *
     * @param communityId
     */
    @Override
    @Transactional
    public void quitJoinCommunity(String communityId) {
        propertyManagementMapper.updateQuitJoinCommunity(communityId);
    }

    /**
     * 获取小区功能
     * @param query
     * @return
     */
    @Override
    public List<CommunityMenuGroup> getCommunityMenuGroup(String query) {
        return propertyManagementMapper.selectCommunityMenuGroup(query);

    }

    /**
     * 修改小区功能
     * @param dto
     */
    @Override
    @Transactional
    public void updateCommunityMenuGroup(CommunityMenuGroupDTO dto) {
        self.insertMenuGroupCommunity(dto);
    }

    /**
     * 批量更新小区功能
     * @param dto
     */
    @Transactional
    public void insertMenuGroupCommunity(CommunityMenuGroupDTO dto) {
        //  统一批量更新的当前时间
        LocalDateTime now = LocalDateTime.now();
        //dto转实体
        List<MMenuGroupCommunity> mMenuGroupCommunityList = new ArrayList<>();
        //遍历dto
        for (CommunityMenuGroupDTO.MenuGroup menuGroup : dto.getMenuGroups()) {
            MMenuGroupCommunity mMenuGroupCommunity = new MMenuGroupCommunity();
            // 关键：手动生成雪花ID字符串并赋值给 gcId
            mMenuGroupCommunity.setGcId(IdUtil.getSnowflakeNextIdStr());
            mMenuGroupCommunity.setCommunityId(dto.getCommunityId());
            mMenuGroupCommunity.setGId(menuGroup.getGId());
            mMenuGroupCommunity.setStatusCd(menuGroup.getStatusCd());
            mMenuGroupCommunity.setName(menuGroup.getName());
            mMenuGroupCommunity.setCommunityName(dto.getCommunityName());
            mMenuGroupCommunity.setCreateTime(now);
            mMenuGroupCommunityList.add(mMenuGroupCommunity);
        }
        /**
         * 玺朽 叹气，唉。。。
         *  这里我放弃使用saveBatch，在d2数据源下会报错，
         *  MyBatis-Plus 初始化 TableInfoCache 时，可能因为某些原因（比如默认数据源 d1 的问题
         *  ，或者动态数据源配置与MP初始化时序问题）没有成功为 MMenuGroupCommunity 构建缓存
         *  虽然 @DS("d2") 在运行时切换数据源，但 TableInfoCache 通常在启动时或首次访问实体时构建。
         */
//        saveBatch(mMenuGroupCommunityList);
        // 改用手动插入
        propertyManagementMapper.insertMenuGroupCommunity(mMenuGroupCommunityList);
    }

    /**
     * 删除物业公司
     *
     * @param storeId
     */
    @Override
    public void deleteCompany(String storeId) {
        propertyManagementMapper.deleteByStoreId(storeId);
    }

    /**
     * 限制物业登录
     *
     * @param storeId
     */
    @Override
    public void limitCompanyLogin(String storeId, String operate) {
        propertyManagementMapper.limitCompanyLogin(storeId, operate);
    }

    /**
     * 重置物业公司密码
     *
     * @param storeId
     * @return
     */
    @Override
    public String resetCompanyPassword(String storeId) {
        Random random = new Random();
        int ranPassword = random.nextInt(900000) + 100000;
        String newPassword = Integer.toString(ranPassword);
        String password = BCrypt.hashpw(newPassword);
        propertyManagementMapper.resetCompanyPassword(storeId, password);
        return newPassword;
    }
}
