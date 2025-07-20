package com.zeroone.star.orgmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.*;
import com.zeroone.star.orgmanager.mapper.EmployeeMapper;
import com.zeroone.star.orgmanager.service.EmployeeService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.j4.orgmanager.AddEmployeeDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ModifyEmployeeDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmpAuthTreeVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmpOrgAuthorityVO;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeBaseInfoVO;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.transaction.interceptor.TransactionAspectSupport;
import org.springframework.web.multipart.MultipartFile;
import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.zeroone.star.orgmanager.entity.UUser;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j4.orgmanager.employee.EmployeeQuery;
import com.zeroone.star.project.vo.j4.orgmanager.EmployeeListVO;
import com.alibaba.fastjson2.JSON;


import java.util.List;

@Mapper(componentModel = "spring")
interface EmMapper{
    EmployeeBaseInfoVO UUserToEmployeeBaseInfoVO(UUser user);
    UUser AddEmpoyeeDTOToUUser(AddEmployeeDTO addEmployeeDTO);
}


@Service
@Slf4j
public class EmployeeServiceImpl extends ServiceImpl<EmployeeMapper, UUser> implements EmployeeService {
    @Resource
    private EmployeeMapper employeeMapper;
    @Resource
    EmMapper emMapper;

    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

    @Resource
    FastDfsClientComponent dfs;

    @Resource
    RedisTemplate<String, String> redisTemplate;

    /**
     * 删除员工
     * @param userId 员工的user_id字段
     * @return 执行结果 true or false
     */
    @Override
    public String deleteEmployee(String userId) {
        try{
            LambdaUpdateWrapper<UUser> lambdaUpdateWrapper = new LambdaUpdateWrapper<>();
            lambdaUpdateWrapper.set(UUser::getStatusCd,1).eq(UUser::getUserId,userId);
            int row = employeeMapper.update(null, lambdaUpdateWrapper);
            if(row > 0) return "success";
            return "user不存在";
        }catch (Exception e){
            e.printStackTrace();
            return "fail";
        }

    }

    /**
     * 获取员工基础信息
     * @param userId 员工的user_id字段
     * @return 响应基础信息
     */
    @SneakyThrows
    @Override
    public JsonVO<EmployeeBaseInfoVO> getEmployeeBaseInfo(String userId) {
        try{
            LambdaQueryWrapper<UUser> lambdaQueryWrapper = new LambdaQueryWrapper<>();
            lambdaQueryWrapper.eq(UUser::getUserId,userId);
            UUser user = employeeMapper.selectOne(lambdaQueryWrapper);
            if(user == null) {
                JsonVO<EmployeeBaseInfoVO> jsonVO = new JsonVO<>();
                jsonVO.setCode(9999);
                jsonVO.setMessage("user不存在");
                jsonVO.setData(null);
                return jsonVO;
            }
            EmployeeBaseInfoVO employeeBaseInfoVO = emMapper.UUserToEmployeeBaseInfoVO(user);
            employeeBaseInfoVO.setSex(employeeBaseInfoVO.getSex().equals("0") ? "男" : "女");
            String url = employeeMapper.getFileSaveName(userId);
            employeeBaseInfoVO.setPicture(null);
            if(url != null){
//            FastDfsFileInfo fastDfsFileInfo = getFastDfsFileInfo(url);
//            byte[] picture = dfs.downloadFile(fastDfsFileInfo);
//            employeeBaseInfoVO.setPicture(picture);
                url = url.substring(0, url.indexOf('?'));
                employeeBaseInfoVO.setPicture(url);
            }
            return JsonVO.success(employeeBaseInfoVO);
        }catch (Exception e){
            return JsonVO.fail(null);
        }
    }

    /**
     * 获取员工组织权限信息
     * @param userId 员工id
     * @return 员工组织权限信息
     */
    @Override
    public JsonVO<EmpOrgAuthorityVO> getEmpOrgAuthority(String userId) {
        try{
            UOrgStaffRel uosr = employeeMapper.selectRelCdAndOrgId(userId);
            if(uosr == null) {
                JsonVO<EmpOrgAuthorityVO> jsonVO = new JsonVO<>();
                jsonVO.setCode(9999);
                jsonVO.setMessage("user不存在");
                jsonVO.setData(null);
                return jsonVO;
            }
            String orgId = uosr.getOrgId();
            String relCd = uosr.getRelCd();
            String org = null;
            if (orgId != null) {
                UOrg uOrg = employeeMapper.selectUOrg(orgId);
                if(uOrg != null){
                    org = uOrg.getOrgName();
                    //寻找父组织
                    while(!uOrg.getParentOrgId().equals(orgId)){
                        orgId = uOrg.getParentOrgId();
                        uOrg = employeeMapper.selectUOrg(uOrg.getParentOrgId());
                        org = uOrg.getOrgName() + " / " + org;
                    }
                }
            }
            String job = null;
            if(relCd != null) job = employeeMapper.selectJob(relCd);
            PPrivilegeUser ppu = employeeMapper.selectPIdAndStoreId(userId);
            String pId = null;
            String storeId = null;
            if(ppu != null){
                pId = ppu.getPId();
                storeId = ppu.getStoreId();
            }
            String associatedRoles = null;
            List<String> associatedCommunities = null;
            List<EmpAuthTreeVO> authorities = null;
            if(storeId != null) associatedCommunities = employeeMapper.selectAssociatedCommunities(storeId);
            if(pId != null){
                associatedRoles = employeeMapper.selectAssociatedRoles(pId);
                String domain = employeeMapper.selectDomain(pId);
                if(domain != null) authorities = getEmpAuth(domain);
            }
            return JsonVO.success(new EmpOrgAuthorityVO(org,job,associatedRoles,associatedCommunities,authorities));
        }catch (Exception e){
            return JsonVO.fail(null);
        }
    }

    /**
     * 添加员工
     * @param addEmployeeDTO 添加员工信息
     * @return 相应数据
     */
    @Transactional
    @Override
    public String addEmployee(AddEmployeeDTO addEmployeeDTO) {
        try{
            UUser uUser = emMapper.AddEmpoyeeDTOToUUser(addEmployeeDTO);
            //password默认密码是123456
            BCryptPasswordEncoder encoder = new BCryptPasswordEncoder();
            uUser.setPassword(encoder.encode("123456"));
            uUser.setLevelCd("01");
            uUser.setStatusCd("0");
            LocalDateTime now = getLocalTime();
            uUser.setCreateTime(now);
            String userId = getRandomId("30");
            uUser.setUserId(userId);
            String relCd = employeeMapper.selectRelCd(addEmployeeDTO.getJob());
            String orgId = employeeMapper.selectOrgId(addEmployeeDTO.getAssociatedOrg());
            String bId = getRandomId("20");
            String storeId = "400000000000000001";
            UOrgStaffRel uOrgStaffRel = new UOrgStaffRel(
                    getRandomId("84"),bId,orgId,userId,relCd,now,"0",storeId
            );
            employeeMapper.insert(uUser);
            employeeMapper.insertUOrgStaffRel(uOrgStaffRel);
            //添加s_store_user
            String storeUserId = getRandomId("45");
            SStoreUser sStoreUser = new SStoreUser(storeUserId,storeId,bId,userId,relCd,now,"0");
            employeeMapper.insertSStoreUser(sStoreUser);
            //添加business_store_user
            BusinessStoreUser businessStoreUser = new BusinessStoreUser(storeUserId,storeId,bId,userId,relCd,now,"ADD");
            employeeMapper.insertBusinessStoreUser(businessStoreUser);
            //头像
            MultipartFile file = addEmployeeDTO.getPicture();
            if(file != null){
                String filename = file.getOriginalFilename();
                String extName = filename.substring(filename.lastIndexOf(".")+1);
                FastDfsFileInfo fastDfsFileInfo = dfs.uploadFile(file.getBytes(), extName);
                if (fastDfsFileInfo == null) return "fail";
                String url = dfs.fetchUrl(fastDfsFileInfo, serverUrl, true);
                String fileRelId = getRandomId("77");
                FileRel fileRel = new FileRel(fileRelId,"-1","12000","OSS",uUser.getUserId(),filename,url,now,"0");
                employeeMapper.insertFileRel(fileRel);
            }
            return "success";
        }catch (Exception e){
            e.printStackTrace();
            TransactionAspectSupport.currentTransactionStatus().setRollbackOnly();
            return "fail";
        }
    }

    /**
     * 修改员工
     * @param modifyEmployeeDTO 修改员工信息
     * @return 响应数据
     */
    @Transactional
    @Override
    public String modifyEmployee(ModifyEmployeeDTO modifyEmployeeDTO) {
        try{
            LambdaUpdateWrapper<UUser> lambdaUpdateWrapper = getModifyEmployeeLambdaUpdateWrapper(modifyEmployeeDTO);
            if(lambdaUpdateWrapper != null) employeeMapper.update(null, lambdaUpdateWrapper);
            String userId = modifyEmployeeDTO.getUserId();
            if(modifyEmployeeDTO.getJob() != null){
                String relCd = employeeMapper.getRelCdByName(modifyEmployeeDTO.getJob());
                if(relCd != null){
                    employeeMapper.updateRelCd(relCd,userId);
                }else{
                    throw new RuntimeException("参数出错");
                }
            }
            //头像
            if(modifyEmployeeDTO.getPicture() != null){
                MultipartFile file = modifyEmployeeDTO.getPicture();
                String filename = file.getOriginalFilename();
                String extName = filename.substring(filename.lastIndexOf(".")+1);
                FastDfsFileInfo fastDfsFileInfo = dfs.uploadFile(file.getBytes(), extName);
                if (fastDfsFileInfo == null) return "fail";
                String url = dfs.fetchUrl(fastDfsFileInfo, serverUrl, true);
                employeeMapper.updateFileRel(modifyEmployeeDTO.getUserId(),filename,url);
            }
            return "success";
        }catch (RuntimeException e){
            e.printStackTrace();
            TransactionAspectSupport.currentTransactionStatus().setRollbackOnly();
            return "参数出错";
        }catch (Exception e){
            e.printStackTrace();
            TransactionAspectSupport.currentTransactionStatus().setRollbackOnly();
            return "fail";
        }
    }

    private static LambdaUpdateWrapper<UUser> getModifyEmployeeLambdaUpdateWrapper(ModifyEmployeeDTO modifyEmployeeDTO) {
        LambdaUpdateWrapper<UUser> lambdaUpdateWrapper = new LambdaUpdateWrapper<>();
        lambdaUpdateWrapper.eq(UUser::getUserId,modifyEmployeeDTO.getUserId());
        int flag = 0;
        if(modifyEmployeeDTO.getName() != null){
            lambdaUpdateWrapper.set(UUser::getName,modifyEmployeeDTO.getName());
            flag = 1;
        }
        if(modifyEmployeeDTO.getTel() != null){
            lambdaUpdateWrapper.set(UUser::getTel,modifyEmployeeDTO.getTel());
            flag = 1;
        }
        if(modifyEmployeeDTO.getEmail() != null){
            lambdaUpdateWrapper.set(UUser::getEmail,modifyEmployeeDTO.getEmail());
            flag = 1;
        }
        if(modifyEmployeeDTO.getSex() != null) {
            lambdaUpdateWrapper.set(UUser::getSex,modifyEmployeeDTO.getSex());
            flag = 1;
        }
        if(modifyEmployeeDTO.getAddress() != null){
            lambdaUpdateWrapper.set(UUser::getAddress,modifyEmployeeDTO.getAddress());
            flag = 1;
        }
        if(flag == 1) return lambdaUpdateWrapper;
        else return null;
    }

    /**
     * 重置密码
     * @param userId 员工id
     * @return 新密码
     */
    @Override
    public String resetPassword(String userId) {
        try{
            //得到六位数字
            Random random = new Random();
            Integer password = random.nextInt(900000) + 100000;
            BCryptPasswordEncoder passwordEncoder = new BCryptPasswordEncoder();
            String ppassword = passwordEncoder.encode(password.toString());
            LambdaUpdateWrapper<UUser> lambdaUpdateWrapper = new LambdaUpdateWrapper<>();
            lambdaUpdateWrapper.set(UUser::getPassword,ppassword).eq(UUser::getUserId,userId);
            int row = employeeMapper.update(null, lambdaUpdateWrapper);
            if(row > 0) return password.toString();
            else return "user不存在";
        }catch (Exception e){
            return "fail";
        }
    }

    private static String getRandomId(String prefix){
        //prefix + time + 8bit random
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMdd");
        String time = LocalDateTime.now().format(formatter);
        Random random = new Random();
        int randomNumber = random.nextInt(99999999);
        return prefix + time + randomNumber ;
    }

    private static LocalDateTime getLocalTime(){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return LocalDateTime.parse(LocalDateTime.now().format(formatter),formatter);
    }

    private static FastDfsFileInfo getFastDfsFileInfo(String url){
        int startIndexGroup1 = url.indexOf("/", url.indexOf("//") + 2) + 1;
        int endIndexGroup1 = url.indexOf("/", startIndexGroup1);
        String group = url.substring(startIndexGroup1, endIndexGroup1);
        int startIndexPath = endIndexGroup1 + 1;
        int endIndexPath = url.indexOf("?", startIndexPath);
        String storeId = url.substring(startIndexPath, endIndexPath);
        return FastDfsFileInfo.builder()
                .group(group)
                .storageId(storeId)
                .build();
    }

    private List<EmpAuthTreeVO> getEmpAuth(String domain){
        //先从redis中查找
        String authJson = redisTemplate.opsForValue().get("EmpAuth_"+domain);
        if(authJson != null) return JSON.parseArray(authJson, EmpAuthTreeVO.class);
        List<EmpAuthTreeVO> rootNodes = new ArrayList<>();
        Map<String,EmpAuthTreeVO> nodeMap = new HashMap<>();
        List<EmpAuthTreeVO> nodes = new ArrayList<>();
        List<EmpAuth> empAuthList = employeeMapper.selectAuthOnPPrivilge(domain);
        for(EmpAuth empAuth : empAuthList){
            //找第二层
            EmpAuth tEA = employeeMapper.selectAuthOnMMenu(empAuth.getParentAuthId());
            if(tEA == null) continue;
            //找第一层
            String ttName = employeeMapper.selectAuthOnMMenuGroup(tEA.getParentAuthId());
            if(ttName == null) continue;
            //第一层
            if(!nodeMap.containsKey(tEA.getParentAuthId())){
                EmpAuthTreeVO empAuthTreeVO = new EmpAuthTreeVO(tEA.getParentAuthId(),ttName,null,new ArrayList<>());
                nodes.add(empAuthTreeVO);
                nodeMap.put(empAuthTreeVO.getId(),empAuthTreeVO);
            }
            //第二层
            if(!nodeMap.containsKey(empAuth.getParentAuthId())){
                EmpAuthTreeVO empAuthTreeVO = new EmpAuthTreeVO(empAuth.getParentAuthId(),tEA.getName(), tEA.getParentAuthId(), new ArrayList<>());
                nodes.add(empAuthTreeVO);
                nodeMap.put(empAuthTreeVO.getId(),empAuthTreeVO);
            }
            //第三层
            if(!nodeMap.containsKey(empAuth.getId())){
                EmpAuthTreeVO empAuthTreeVO = new EmpAuthTreeVO(empAuth.getId(),empAuth.getName(), empAuth.getParentAuthId(), null);
                nodes.add(empAuthTreeVO);
                nodeMap.put(empAuthTreeVO.getId(),empAuthTreeVO);
            }
        }

        for (EmpAuthTreeVO node : nodes) {
            String pId = node.getPid();
            if (pId == null) {
                // 如果 pId 为 null，则该节点为根节点
                rootNodes.add(node);
            } else {
                // 找到父节点
                EmpAuthTreeVO parent = nodeMap.get(pId);
                if (parent != null) {
                    // 将当前节点添加到父节点的子节点列表中
                    parent.addChild(node);
                }
            }
        }
        authJson = JSON.toJSONString(rootNodes);
        redisTemplate.opsForValue().set("EmpAuth_"+domain,authJson);
        return rootNodes;
    }


    /**
     * 查询员工列表
     * @param query
     * @return
     */
    @Override
    public JsonVO<PageDTO<EmployeeListVO>> emplist(EmployeeQuery query) {
        // 1. 启动分页
        PageHelper.startPage((int) query.getPageIndex(), (int) query.getPageSize());
        // 2. 执行查询（会被 PageHelper 拦截）
        List<EmployeeListVO> list = employeeMapper.selectEmployeeList(query);
        // 3. 用 PageInfo 包装
        PageInfo<EmployeeListVO> page = new PageInfo<>(list);

        PageDTO<EmployeeListVO> pageDTO = new PageDTO<>();
        pageDTO.setPageIndex((long) page.getPageNum());
        pageDTO.setPageSize((long) page.getPageSize());
        pageDTO.setTotal(page.getTotal());
        pageDTO.setPages((long) page.getPages());
        pageDTO.setRows(list);

        // 4. 返回 JsonVO 包裹的结果
        return JsonVO.success(pageDTO);
    }
}
