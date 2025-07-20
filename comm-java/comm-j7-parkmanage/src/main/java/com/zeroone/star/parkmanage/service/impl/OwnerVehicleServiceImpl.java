package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.parkmanage.entity.*;
import com.zeroone.star.parkmanage.mapper.*;
import com.zeroone.star.parkmanage.service.OwnerVehicleService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.AddCarDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.RenewParkingSpaceLeaseDTO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.CarQuery;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.ExportCarQuery;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.*;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.List;
import java.util.ArrayList;
import java.io.IOException;
import java.io.ByteArrayOutputStream;

import cn.hutool.core.util.IdUtil;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

import java.lang.reflect.Field;
import java.util.Base64;
import cn.hutool.core.util.StrUtil;

@Slf4j
@Service
public class OwnerVehicleServiceImpl extends ServiceImpl<OwnerVehicleMapper, OwnerCar> implements OwnerVehicleService {

    private static final Integer HEAD_ROWS = 2;
    @Resource
    private OwnerVehicleMapper ownerVehicleMapper;

    @Override
    public String selectUserIdByOwnerId(String ownerId) {
        return ownerVehicleMapper.selectUserIdByOwnerId(ownerId);
    }

    @Override
    public PageDTO<OwnerCarInfoVO> selectOwnerCarInfoByPage(CarQuery carQuery) {
        // 创建分页对象
        Page<OwnerCarInfoVO> page = Page.of(carQuery.getPageIndex(), carQuery.getPageSize());

        // 执行分页查询
        Page<OwnerCarInfoVO> resultPage = ownerVehicleMapper.selectOwnerCarInfoByPage(page, carQuery);

        ownerVehicleMapper.selectOwnerCarInfoByPage(resultPage, carQuery);

        return PageDTO.create(resultPage);
    }

    @Override
    public void save(AddCarDTO addCarDTO) {

        // 将addCarDTO转为ownerVehicle
        OwnerCar ownerCar = new OwnerCar();
        BeanUtils.copyProperties(addCarDTO, ownerCar);

        // 判断租赁类型是否为出租车，添加字段值
        if ("H".equals(ownerCar.getLeaseType())) {
            // 为起租和结组时间加上零点时间
            LocalDate startDate = addCarDTO.getStartTime();
            LocalDate endDate = addCarDTO.getEndTime();
            LocalTime midnight = LocalTime.MIDNIGHT;
            ownerCar.setStartTime(startDate.atTime(midnight));
            ownerCar.setEndTime(endDate.atTime(midnight));
        } else {
            // 不是出租车，设置起租时间为当前日期+零点时间，结组时间默认2050-01-01 00:00:00
            ownerCar.setStartTime(LocalDate.now().atStartOfDay());
            ownerCar.setEndTime(LocalDateTime.of(2050, 1, 1, 0, 0, 0));
        }

        // 封装ownerCar属性
        // 根据业主id，查询用户id
        String userId = selectUserIdByOwnerId(ownerCar.getOwnerId());
        // 设置用户id
        ownerCar.setUserId(userId);
        // 设置业务id，雪花算法
        ownerCar.setBId(IdUtil.getSnowflakeNextIdStr());
        ownerCar.setState("1001");
        ownerCar.setStatusCd("0");
        ownerCar.setCarTypeCd("1001");

        ownerVehicleMapper.inserOwnerCar(ownerCar);
    }

    @Value("${spring.application.name}")
    private String serviceName;
    @Resource
    private EasyExcelComponent easyExcelComponent;

    @Resource
    private OwnerVehicleExportMapper ownerVehicleExportMapper;

    @Autowired
    private ParkingSpaceMapper parkingSpaceMapper;

    /**
     * 导出车辆数据
     * @param query 筛选条件 (使用ExportCarQuery)
     * @return
     */
    @Override
    public byte[] triggerExport(ExportCarQuery query) {
        log.info("开始导出车辆数据，查询条件：{}", query);

        ByteArrayOutputStream out = new ByteArrayOutputStream();

        try {
            // 1. 获取需要导出的数据 (可能为空)
            List<ExportVehicleVO> exportData = getExportVehicleData(query);

            // 即使数据为空也继续导出，EasyExcel会只写表头
            if (exportData == null || exportData.isEmpty()) {
                // 创建一个只包含表头的空对象列表
                exportData = new ArrayList<>();
                // 添加一个空对象，确保表头显示
                exportData.add(new ExportVehicleVO());
                log.warn("未查询到需要导出的车辆数据，将导出空文件（仅表头）");
            }
            log.info("查询到{}条车辆数据待导出", exportData.size());

            // 2. 生成Excel文件到内存输出流
            easyExcelComponent.export("业主车辆数据", out, ExportVehicleVO.class, exportData);
            log.info("Excel文件生成成功到内存流");

            // 3. 返回字节数组
            byte[] excelBytes = out.toByteArray();
            return Base64.getEncoder().encode(excelBytes); // Base64 编码

        } catch (IOException e) {
            log.error("文件处理异常", e);
            // 导出失败时返回错误信息字节数组，也进行 Base64 编码
            return Base64.getEncoder().encode(("导出失败：文件处理异常: " + e.getMessage()).getBytes(java.nio.charset.StandardCharsets.UTF_8));
        } catch (Exception e) {
            log.error("导出过程中发生异常", e);
            // 导出失败时返回错误信息字节数组，也进行 Base64 编码
            return Base64.getEncoder().encode(("导出失败：发生内部错误: " + e.getMessage()).getBytes(java.nio.charset.StandardCharsets.UTF_8));
        } finally {
            // 关闭流
            try {
                if (out != null) {
                    out.close();
                }
            } catch (IOException e) {
                log.error("关闭ByteArrayOutputStream异常", e);
            }
        }
    }

    /**
     * 获取导出数据
     * @param query 筛选条件 (使用CarQuery)
     * @return
     */
    @Override
    public List<ExportVehicleVO> getExportVehicleData(ExportCarQuery query) {
        log.debug("开始查询导出数据，查询条件：{}", query);
//        log.debug("CarQuery state value: {}, type: {}", query.getState(), query.getState() != null ? query.getState().getClass().getName() : "null");

        List<VehicleDO> poList = ownerVehicleExportMapper.selectVehiclesForExport(query);
        if (poList == null || poList.isEmpty()) {
            log.warn("未查询到车辆数据");
            return new ArrayList<>();
        }
        log.debug("查询到{}条原始数据", poList.size());

        // 转换 DO 到 VO 并合并数据
        List<ExportVehicleVO> exportVOList = new ArrayList<>();
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

        for (VehicleDO po : poList) {
            ExportVehicleVO vo = new ExportVehicleVO();

            // 映射基本字段，使用ExportVehicleDO中定义的字段名
            vo.setCarNumber(po.getCarNumber()); // 从carNumber获取车牌号
            vo.setCarBrand(po.getCarBrand());
            vo.setCarTypeName(po.getCarTypeName());
            vo.setCarColor(po.getCarColor());
            vo.setStatus(po.getStatus()); // 从status获取状态
            vo.setRemark(po.getRemark());
            vo.setRoom(po.getRoom()); // 从room获取房屋号

            // 合并业主信息: 姓名(电话)
            StringBuilder ownerInfo = new StringBuilder();
            if (po.getOwnerName() != null) {
                ownerInfo.append(po.getOwnerName());
            }
            if (po.getOwnerTel() != null) {
                if (ownerInfo.length() > 0) {
                    ownerInfo.append("(");
                }
                ownerInfo.append(po.getOwnerTel());
                if (ownerInfo.length() > 0 && ownerInfo.indexOf("(") > -1) {
                    ownerInfo.append(")");
                }
            }
            vo.setOwnerInfo(ownerInfo.toString());

            // 合并车位信息: 区域-编号
            StringBuilder parkingSpace = new StringBuilder();
            if (po.getAreaNum() != null) {
                parkingSpace.append(po.getAreaNum());
            }
            if (po.getParkingSpaceNum() != null) {
                if (parkingSpace.length() > 0) {
                    parkingSpace.append("-");
                }
                parkingSpace.append(po.getParkingSpaceNum());
            }
            vo.setParkingSpaceInfo(parkingSpace.toString());

            // 合并有效期: 开始时间--结束时间
            StringBuilder validityPeriod = new StringBuilder();
            if (po.getStartTime() != null) {
                try {
                    validityPeriod.append(sdf.format(po.getStartTime()));
                } catch (Exception e) {
                    log.error("格式化开始时间失败", e);
                }
            }
            if (po.getEndTime() != null) {
                if (validityPeriod.length() > 0) {
                    validityPeriod.append("--");
                }
                try {
                    validityPeriod.append(sdf.format(po.getEndTime()));
                } catch (Exception e) {
                    log.error("格式化结束时间失败", e);
                }
            }
            vo.setValidityPeriod(validityPeriod.toString());

            // 成员车辆数量转换为"是/否"
            try {
                int count = Integer.parseInt(po.getMemberVehicle());
                vo.setMemberVehicle(count > 0 ? "是" : "否");
            } catch (NumberFormatException e) {
                vo.setMemberVehicle("否");
                log.warn("成员车辆数量转换失败，原始值: {}", po.getMemberVehicle());
            }

            exportVOList.add(vo);
        }

        log.debug("数据转换完成，转换后数据量：{}", exportVOList.size());
        return exportVOList;
    }


    /**
     * 根据车辆ID获取车辆信息
     * @param carId 车辆ID
     * @return
     */
    @Override
    public OwnerVehicleVO getVehicleInfoByCarId(String carId) {
        // 调用Mapper根据车辆ID查询车辆信息
       VehicleDO vehicleDO = ownerVehicleMapper.getVehicleInfoByCarId(carId);

        // 将DO对象转换为VO对象
        if (vehicleDO == null) {
            return null;
        }
        OwnerVehicleVO vehicleVO = VehicleStructMapper.INSTANCE.toVO(vehicleDO);
        return vehicleVO;
    }



    @Override
    @Transactional(rollbackFor = Exception.class)
    public String importVehicleData(String tempFilePath) {
        log.info("开始导入车辆数据，文件路径：{}", tempFilePath);
        
        try {
            // 1. 使用EasyExcelComponent解析Excel
            List<ImportVehicleExcelVO> dataList = easyExcelComponent.parseExcel(tempFilePath, ImportVehicleExcelVO.class);
            if (dataList == null || dataList.isEmpty()) {
                log.warn("Excel文件为空");
                return "Excel文件为空";
            }

            // 打印读取到的数据
            for (ImportVehicleExcelVO importVehicleExcelVO : dataList) {
                System.out.println(importVehicleExcelVO.toString());
            }
            
            log.info("成功读取Excel数据，共{}条记录", dataList.size());
            
            // 2. 数据验证和保存
            int successCount = 0;
            int failureCount = 0;
            List<ImportFailureDetail> failureDetails = new ArrayList<>();
            
            // 检查是否有实际数据行 (排除表头和空行)
            boolean hasActualData = false;
            for (int i = 1; i < dataList.size(); i++) {
                if (!isRowEmpty(dataList.get(i))) {
                    hasActualData = true;
                    break;
                }
            }
            
            if (!hasActualData) {
                log.warn("Excel文件不包含有效数据");
                return "导入数据为空";
            }
            
            // 跳过表头，从第2行开始处理数据
            for (int i = 1; i < dataList.size(); i++) {
                ImportVehicleExcelVO data = dataList.get(i);
                int rowIndex = i + 2; // Excel从第2行开始是数据
                log.info("正在处理第{}行数据: {}", rowIndex, data);
                
                // 检查是否为空行
                if (isRowEmpty(data)) {
                    log.debug("第{}行为空行，跳过", rowIndex);
                    continue;
                }

                StringBuilder errorMsg = new StringBuilder();

                // 2.1 数据非空校验
                if (com.baomidou.mybatisplus.core.toolkit.StringUtils.isBlank(data.getCarNumber())) {
                    errorMsg.append("车牌号不能为空;");
                }
                if (com.baomidou.mybatisplus.core.toolkit.StringUtils.isBlank(data.getOwnerName())) {
                    errorMsg.append("业主姓名不能为空;");
                }
                if (com.baomidou.mybatisplus.core.toolkit.StringUtils.isBlank(data.getPhoneNumber())) {
                    errorMsg.append("业主手机号不能为空;");
                }
                if (com.baomidou.mybatisplus.core.toolkit.StringUtils.isBlank(data.getCarType())) {
                    errorMsg.append("车辆类型不能为空;");
                }
                if (com.baomidou.mybatisplus.core.toolkit.StringUtils.isBlank(data.getStatus())) {
                    errorMsg.append("车位类型不能为空;");
                }
                
                // 2.2 日期格式校验
                try {
                    if (data.getStartTime() != null) {
                        try {
                            parseDate(data.getStartTime());
                        } catch (Exception e) {
                            log.error("无法解析起租时间: {}", data.getStartTime());
                            errorMsg.append("起租时间格式不正确，请检查Excel文件;");
                        }
                    }
                    if (data.getEndTime() != null) {
                        try {
                            parseDate(data.getEndTime());
                        } catch (Exception e) {
                            log.error("无法解析截止时间: {}", data.getEndTime());
                            errorMsg.append("截止时间格式不正确，请检查Excel文件;");
                        }
                    }
                } catch (Exception e) {
                    log.error("日期格式转换失败", e);
                    errorMsg.append("日期格式转换失败;");
                }
                
                if (errorMsg.length() > 0) {
                    failureCount++;
                    failureDetails.add(new ImportFailureDetail(rowIndex, errorMsg.toString()));
                    log.error("第{}行数据验证失败: {}", rowIndex, errorMsg.toString());
                    continue;
                }
                
                // 2.3 业务校验
                try {
                    // 2.3.1 验证业主信息
                    BuildingOwner owner = ownerVehicleMapper.getOwnerByNameAndTel(data.getOwnerName(), data.getPhoneNumber());
                    if (owner == null) {
                        errorMsg.append("业主信息不存在;");
                    }
                    
                    // 2.3.2 验证车位信息
                    ParkingSpace parkingSpace = null;
                    if (errorMsg.length() == 0) {
                        parkingSpace = ownerVehicleMapper.getParkingSpaceByNums(data.getParkingLot(), data.getParkingSpace());
                        if (parkingSpace == null) { // 如果车位不存在，尝试创建

                            String communityId = owner.getCommunityId();
                            ParkingArea existingParkingArea = ownerVehicleMapper.getParkingAreaByNumAndCommunityId(data.getParkingLot(), communityId);
                            
                            String paId;
                            if (existingParkingArea != null) {
                                log.info("停车场已存在，使用现有停车场：{}", existingParkingArea.getPaId());
                                paId = existingParkingArea.getPaId();
                            } else {
                                log.info("停车场不存在，创建新的停车场");
                                paId = IdUtil.getSnowflakeNextIdStr();
                                ParkingArea newParkingArea = new ParkingArea();
                                newParkingArea.setPaId(paId);
                                newParkingArea.setNum(data.getParkingLot());
                                newParkingArea.setRemark("导入数据");
                                newParkingArea.setCommunityId(communityId);
                                newParkingArea.setStatusCd("0");
                                newParkingArea.setTypeCd(data.getParkingLotType()); // 设置停车场类型为普通停车场
                                ownerVehicleMapper.insertParkingArea(newParkingArea);
                                log.info("新的停车场创建成功：{}", paId);
                            }
                            
                            // 创建新车位
                            String psId = IdUtil.getSnowflakeNextIdStr();
                            ParkingSpace newParkingSpace = new ParkingSpace();
                            newParkingSpace.setPsId(psId);
                            newParkingSpace.setRemark("导入数据");
                            newParkingSpace.setCommunityId(communityId);
                            newParkingSpace.setNum(data.getParkingSpace());
                            newParkingSpace.setPaId(paId);
                            newParkingSpace.setState(data.getStatus());
                            newParkingSpace.setStatusCd("0");
                            newParkingSpace.setParkingType("1"); // 设置为普通车位
                            newParkingSpace.setArea(BigDecimal.valueOf(1.00)); // 设置area字段默认值
                            ownerVehicleMapper.insertParkingSpace(newParkingSpace);
                            log.info("新的车位创建成功：{}", psId);
                            
                            parkingSpace = newParkingSpace;
                        }
                    }
                    
                    // 在查找或创建车位后，立即检查车位是否已被占用（包括同一辆车或不同车辆）
                    if (parkingSpace != null && errorMsg.length() == 0) {
                        // 查询该车位是否有有效未释放的车辆占用 (status_cd = 0, state = 1001)
                        int occupiedCount = ownerVehicleMapper.checkParkingSpaceOccupiedActive(parkingSpace.getPsId());
                        if (occupiedCount > 0) {
                            // 进一步检查是否是同一辆车占用
                            OwnerCar existingActiveCarInSpace = ownerVehicleMapper.getActiveCarByCarNumAndPsId(data.getCarNumber(), parkingSpace.getPsId());
                            if (existingActiveCarInSpace != null) {
                                // 同一辆车同一车位有效未释放，提示车位已被占
                                errorMsg.append("该车位已被占; ");
                                log.warn("第{}行数据导入的车牌号{}已占用该车位{}", rowIndex, data.getCarNumber(), parkingSpace.getNum());
                            } else {
                                // 其他车辆占用该车位，提示车位已被占
                                errorMsg.append("该车位已被其他车辆占用;");
                                log.warn("第{}行数据导入的车位{}已被其他车辆占用", rowIndex, parkingSpace.getNum());
                            }
                            // 车位被占用，立即标记失败并跳过当前行
                            failureCount++;
                            failureDetails.add(new ImportFailureDetail(rowIndex, errorMsg.toString()));
                            log.error("第{}行数据验证失败: {}", rowIndex, errorMsg.toString());
                            continue; // 跳过当前行
                        }
                    }
                    
                    // 2.3.3 验证车牌号并获取车辆信息
                    if (errorMsg.length() == 0 && parkingSpace != null) {
                        // 查询该车牌号的所有记录 (按创建时间降序排列，获取最新记录)
                        List<OwnerCar> existingCars = ownerVehicleMapper.findCarsByCarNum(data.getCarNumber());
                        
                        if (existingCars != null && !existingCars.isEmpty()) {
                            // 找到最新一条记录
                            OwnerCar latestExistingCar = existingCars.get(0);
                            log.info("找到车牌号为{}的最新记录，状态: {}, 有效性: {}", data.getCarNumber(), latestExistingCar.getState(), latestExistingCar.getStatusCd());

                            // 判断最新记录的状态
                            if (latestExistingCar.getStatusCd().equals("0") && latestExistingCar.getState().equals("1001")) {
                                // 最新记录是有效且未释放的
                                // 如果导入的车位ID和最新记录的车位ID不同，则认为是冲突，需要手动处理或返回错误
                                if (!Objects.equals(latestExistingCar.getPsId(), parkingSpace.getPsId())) {
                                    errorMsg.append("该车牌号已有有效记录占用其他车位，请检查或手动处理; ");
                                    failureCount++;
                                    failureDetails.add(new ImportFailureDetail(rowIndex, errorMsg.toString()));
                                    log.error("第{}行数据验证失败: {}", rowIndex, errorMsg.toString());
                                    continue; // 跳过当前行
                                }
                                // 如果导入的车位ID相同，且数据内容完全一致，则无需操作 (精确检查已处理)
                                // 如果车位ID相同，但数据内容不一致，这不应该发生，或者应该根据业务规则更新
                                // 考虑到精确检查已经排除了完全重复的情况，这里不再处理完全一致的数据更新
                                log.warn("第{}行数据与最新有效未释放记录数据内容不完全一致，或已被精确检查处理，跳过当前复杂场景处理", rowIndex);
                                errorMsg.append("数据与现有记录冲突，请检查或手动处理;");
                                failureCount++;
                                failureDetails.add(new ImportFailureDetail(rowIndex, errorMsg.toString()));
                                log.error("第{}行数据验证失败: {}", rowIndex, errorMsg.toString());
                                continue; // 跳过当前行
                            } else if (latestExistingCar.getStatusCd().equals("0") && latestExistingCar.getState().equals("3003")) {
                                // 最新记录是有效但已释放的，视为新增记录
                                log.info("车牌号{}最新记录已释放，将新增记录", data.getCarNumber());
                                // 继续执行下面的新增逻辑
                            } else if (!latestExistingCar.getStatusCd().equals("0")) {
                                // 最新记录是已删除的，视为新增记录
                                log.info("车牌号{}最新记录已删除，将新增记录", data.getCarNumber());
                                // 继续执行下面的新增逻辑
                            } else {
                                // 其他未知状态，记录错误并跳过
                                log.error("车牌号{}最新记录状态({})未知，有效性({})", data.getCarNumber(), latestExistingCar.getState(), latestExistingCar.getStatusCd());
                                errorMsg.append("车辆记录状态异常，请联系管理员;");
                                failureCount++;
                                failureDetails.add(new ImportFailureDetail(rowIndex, errorMsg.toString()));
                                continue; // 跳过当前行
                            }
                            // 如果走到这里，说明应该新增记录（最新记录已释放或已删除），继续执行下面的新增逻辑
                        } else {
                            // 没有找到该车牌号的有效记录（可能是新车）
                            log.info("未找到车牌号{}的有效记录，将新增记录", data.getCarNumber());
                        }
                        
                        // 创建新记录
                        OwnerCar ownerCar = new OwnerCar();
                        ownerCar.setCarId(IdUtil.getSnowflakeNextIdStr()); // 生成车辆ID
                        ownerCar.setBId(IdUtil.getSnowflakeNextIdStr()); // 生成业务ID
                        ownerCar.setMemberId(IdUtil.getSnowflakeNextIdStr()); // 生成会员ID
                        ownerCar.setPsId(parkingSpace.getPsId()); // 设置车位ID
                        ownerCar.setCarNum(data.getCarNumber()); // 设置车牌号
                        ownerCar.setStatusCd("0"); // 设置状态为正常
                        ownerCar.setState("1001"); // 设置状态为正常
                        
                        setCarBasicInfo(ownerCar, data, null);
                        setCarTimeInfo(ownerCar, data);
                        
                        if (owner != null) {
                            ownerCar.setOwnerId(owner.getMemberId());
                            ownerCar.setUserId(owner.getUserId());
                            ownerCar.setCommunityId(owner.getCommunityId());
                        }
                        
                        try {
                            boolean saved = this.save(ownerCar);
                            if (saved) {
                                // 创建业务车辆记录
                                createBusinessOwnerCar(ownerCar, "ADD");
                                
                                // 生成业务订单
                                String orderId = createOrder(ownerCar, "车辆导入订单-新增");
                                
                                // 记录操作日志
                                createLog(ownerCar.getBId(), "新增车辆数据：" + data.getCarNumber(), orderId);
                                
                                successCount++;
                                log.info("第{}行数据保存成功", rowIndex);
                            } else {
                                // save返回false通常表示插入失败，但没有抛出异常
                                String errorMessage = "数据保存失败，save方法返回false";
                                failureCount++;
                                failureDetails.add(new ImportFailureDetail(rowIndex, errorMessage));
                                log.error("第{}行数据保存失败: {}", rowIndex, errorMessage);
                            }
                        } catch (Exception e) {
                            // 捕获数据库异常，例如唯一约束冲突
                            String errorMessage = "数据保存失败，发生数据库异常: " + e.getMessage();
                            // 对于唯一约束冲突，提供更友好的提示
                            if (e.getMessage() != null && e.getMessage().contains("Duplicate entry")) {
                                errorMessage = "数据保存失败：检测到重复数据，该车辆可能已存在有效记录或存在时间冲突记录。";
                            }
                            failureCount++;
                            failureDetails.add(new ImportFailureDetail(rowIndex, errorMessage));
                            log.error("第{}行数据保存失败: {}", rowIndex, e);
                        }
                    }
                    
                } catch (Exception e) {
                    failureCount++;
                    failureDetails.add(new ImportFailureDetail(rowIndex, "处理数据时发生异常: " + e.getMessage()));
                    log.error("第{}行数据处理异常", rowIndex, e);
                }
            }
            
            // 3. 返回处理结果
            if (failureCount == 0) {
                return "全部导入成功";
            } else {
                // 构建详细的错误信息或部分成功信息
                StringBuilder resultInfo = new StringBuilder();
                if (successCount > 0) {
                    resultInfo.append(String.format("部分导入成功，成功：%d，失败：%d\n", successCount, failureCount));
                } else {
                    resultInfo.append("导入失败，具体错误如下：\n");
                }
                for (ImportFailureDetail detail : failureDetails) {
                    resultInfo.append("第").append(detail.getRowIndex())
                              .append("行: ").append(detail.getErrorMessage()).append("\n");
                }
                // 特殊处理"业主不存在"的情况，如果所有失败都是业主不存在，返回特定错误
                if (failureCount == dataList.size() -1 && failureDetails.stream().allMatch(detail -> detail.getErrorMessage().contains("业主信息不存在"))) {
                     return "业主不存在";
                }
                return resultInfo.toString();
            }
            
        } catch (Exception e) {
            log.error("导入过程中发生异常", e);
            return "导入过程中发生异常：" + e.getMessage();
        }
    }
    /**
     * 删除车辆
     * @param carId 车辆ID
     * @return 删除结果信息（成功/失败原因）
     */
    @Transactional(rollbackFor = Exception.class)
    public String removeVehicle(String carId) {
        OwnerCar ownerCar = ownerVehicleMapper.selectById(carId);
        if(ownerCar == null){
             return  "车辆不存在";
        }
        String psId = ownerCar.getPsId();
        ParkingSpace parkingSpace = parkingSpaceMapper.selectById(psId);
        if(!parkingSpace.getState().equals("F")){
            ParkingSpace newPs = new ParkingSpace();
            newPs.setState("F");
            newPs.setPsId(psId);
            int res = parkingSpaceMapper.updateById(newPs);
            if(res != 1){
                throw new RuntimeException("修改车位状态时出现异常");
                //return "修改车位状态时出现异常";
            }
        }
        ownerCar.setStatusCd("1");
        int updateRes = ownerVehicleMapper.updateById(ownerCar);
        if(updateRes != 1){
            throw new RuntimeException("删除车辆时出现异常");
             //return "删除车辆时出现异常";
        }
        return "删除车辆成功";
    }

    /**
     * 解析日期字符串，支持多种格式
     * @param dateStr 日期字符串
     * @return 解析后的LocalDate对象
     * @throws RuntimeException 如果所有格式都无法解析
     */
    private LocalDate parseDate(String dateStr) {
        if (dateStr == null) {
            return null;
        }

        // 定义所有可能的日期格式
        DateTimeFormatter[] formatters = {
                DateTimeFormatter.ofPattern("yyyy/M/d"),    // 2025/5/9
                DateTimeFormatter.ofPattern("yyyy/M/dd"),   // 2025/5/09
                DateTimeFormatter.ofPattern("yyyy/MM/d"),   // 2025/05/9
                DateTimeFormatter.ofPattern("yyyy/MM/dd"),  // 2025/05/09
                DateTimeFormatter.ofPattern("yyyy-M-d"),    // 2025-5-9
                DateTimeFormatter.ofPattern("yyyy-M-dd"),   // 2025-5-09
                DateTimeFormatter.ofPattern("yyyy-MM-d"),   // 2025-05-9
                DateTimeFormatter.ofPattern("yyyy-MM-dd")   // 2025-05-09
        };

        for (DateTimeFormatter formatter : formatters) {
            try {
                return LocalDate.parse(dateStr, formatter);
            } catch (Exception e) {
                continue;
            }
        }

        throw new RuntimeException("无法解析日期: " + dateStr);
    }

    /**
     * 设置车辆起止时间
     */
    private void setCarTimeInfo(OwnerCar car, ImportVehicleExcelVO data) {
        try {
            if (data.getStartTime() != null) {
                LocalDate startDate = parseDate(data.getStartTime());
                car.setStartTime(startDate.atStartOfDay());
            }
            if (data.getEndTime() != null) {
                LocalDate endDate = parseDate(data.getEndTime());
                car.setEndTime(endDate.atStartOfDay());
            }
        } catch (Exception e) {
            log.error("日期格式转换失败", e);
            throw new RuntimeException("日期格式转换失败");
        }
    }

    /**
     * 设置车辆基本信息
     */
    private void setCarBasicInfo(OwnerCar car, ImportVehicleExcelVO data, OwnerCar carInfo) {
        car.setCarType(data.getCarType());
        car.setCarBrand(data.getCarBrand());
        car.setCarColor(data.getColor());
        car.setRemark("车辆导入数据");

        // 如果有相同车牌号的记录，使用其信息
        if (carInfo != null) {
            car.setLeaseType(carInfo.getLeaseType());
            car.setCarTypeCd(carInfo.getCarTypeCd());
            car.setUserId(carInfo.getUserId());
        } else {
            car.setLeaseType("H"); // 默认月租
            car.setCarTypeCd("1001"); // 主车辆
        }
    }

    /**
     * 创建业务车辆记录
     */
    private void createBusinessOwnerCar(OwnerCar car, String operate) {
        BusinessOwnerCar businessOwnerCar = BusinessOwnerCarStruct.INSTANCE.toBusinessOwnerCar(car, operate);
        // 确保 user_id 被正确赋值
        businessOwnerCar.setUserId(car.getUserId());
        ownerVehicleMapper.insertBusinessOwnerCar(businessOwnerCar);
    }

    /**
     * 创建业务订单
     */
    private String createOrder(OwnerCar car, String remark) {
        String orderId = IdUtil.getSnowflakeNextIdStr();
        COrders order = new COrders();
        order.setOrderId(orderId);
        order.setBId(car.getBId());
        order.setAppId("8000418004");
        order.setOrderTypeCd("D");
        order.setStatusCd("C");
        order.setUserId(car.getUserId());
        order.setRequestTime(LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")));
        order.setCreateTime(LocalDateTime.now());
        order.setFinishTime(LocalDate.now());
        order.setRemark(remark);
        ownerVehicleMapper.insertOrder(order);
        return orderId;
    }

    /**
     * 记录操作日志
     */
    private void createLog(String bId, String content, String orderId) {
        UnitemLog unitemLog = new UnitemLog();
        unitemLog.setBId(IdUtil.getSnowflakeNextIdStr()); // 生成新的b_id
        unitemLog.setOperateContent(content);
        unitemLog.setStatusCd("0");
        unitemLog.setServiceName(serviceName);
        unitemLog.setOId(orderId);
        ownerVehicleMapper.insertLog(unitemLog);
    }

    /**
     * 检查车辆数据是否完全一致
     */
    private boolean isCarDataIdentical(OwnerCar existingCar, ImportVehicleExcelVO newData, ParkingSpace parkingSpace) {
        if (existingCar == null || newData == null) {
            return false;
        }
        
        // 检查所有关键字段
        return Objects.equals(existingCar.getCarNum(), newData.getCarNumber()) && // 车牌号
               Objects.equals(existingCar.getCarType(), newData.getCarType()) && // 车辆类型
               Objects.equals(existingCar.getCarBrand(), newData.getCarBrand()) && // 车辆品牌
               Objects.equals(existingCar.getCarColor(), newData.getColor()) && // 颜色
               Objects.equals(existingCar.getPsId(), parkingSpace.getPsId()) && // 车位ID
               Objects.equals(existingCar.getStatusCd(), "0") && // 有效性
               isTimeIdentical(existingCar, newData); // 时间信息
    }

    /**
     * 检查时间信息是否一致
     */
    private boolean isTimeIdentical(OwnerCar existingCar, ImportVehicleExcelVO newData) {
        try {
            LocalDate newStart = parseDate(newData.getStartTime());
            LocalDate newEnd = parseDate(newData.getEndTime());
            LocalDate existingStart = existingCar.getStartTime().toLocalDate();
            LocalDate existingEnd = existingCar.getEndTime().toLocalDate();
            
            return Objects.equals(newStart, existingStart) && 
                   Objects.equals(newEnd, existingEnd);
        } catch (Exception e) {
            return false;
        }
    }

    /**
     * 检查导入的Excel行是否为空行（所有字段均为null或空字符串）
     * @param rowData 导入的行数据对象
     * @return 如果是空行则返回 true，否则返回 false
     */
    private boolean isRowEmpty(ImportVehicleExcelVO rowData) {
        if (rowData == null) {
            return true;
        }
        // 使用反射检查对象的所有字段
        Field[] fields = ImportVehicleExcelVO.class.getDeclaredFields();
        for (Field field : fields) {
            field.setAccessible(true);
            try {
                Object value = field.get(rowData);
                // 如果任何一个字段的值不是null且不是空字符串，则认为不是空行
                if (value != null && (!(value instanceof String) || StrUtil.isNotBlank((String) value))) {
                    return false;
                }
            } catch (IllegalAccessException e) {
                log.error("访问ImportVehicleExcelVO字段失败", e);
                // 如果发生异常，为了安全起见，认为它不是空行，继续处理
                return false;
            }
        }
        // 如果所有字段都是null或空字符串，则是空行
        return true;
    }
    /**
     * 释放车位
     * @param   carId 车辆ID
     * @return 释放车位结果信息（成功/失败原因）
     */
    @Transactional(rollbackFor = Exception.class)
    public String updateOwnerVehicleByReleaseParkingSpace(String carId) {
        OwnerCar ownerCar = ownerVehicleMapper.selectById(carId);
        if(ownerCar == null){
             return  "车辆不存在";
        }
        String psId = ownerCar.getPsId();
        ParkingSpace parkingSpace = parkingSpaceMapper.selectById(psId);
        parkingSpace.setState("F");
        int res = parkingSpaceMapper.updateById(parkingSpace);
        if(res < 1){
            throw new RuntimeException("修改车位状态时出现异常");
            //return  "修改车位状态时出现异常";
        }
        ownerCar.setState("3003");
        int updateRes = ownerVehicleMapper.updateById(ownerCar);
        if(updateRes < 1){
            throw new RuntimeException("修改车辆状态时出现异常");
            //return  "修改车辆状态时出现异常";
        }
        return "释放车位成功";
    }

    /**
     * 续租车位
     * @param dto 续租车位参数
     * @return 续租车位结果信息（成功/失败原因）
     */
    @Transactional(rollbackFor = Exception.class)
    public String updateOwnerVehicleByRenewParkingSpaceLease(RenewParkingSpaceLeaseDTO dto) {
        OwnerCar ownerCar = ownerVehicleMapper.selectById(dto.getCarId());
        if(ownerCar == null){
             return  "车辆不存在";
        }
        String psId = dto.getPsId();
        ParkingSpace parkingSpace = parkingSpaceMapper.selectById(psId);
        if(!parkingSpace.getState().equals("F")){
            return "车位不是空闲状态，不能续租";
        }
        parkingSpace.setState("H");
        int res = parkingSpaceMapper.updateById(parkingSpace);
        if(res < 1){
            throw new RuntimeException("修改车位状态时出现异常");
            //return "修改车位状态时出现异常";
        }
        ownerCar.setPsId(psId);
        if(dto.getStartTime() != null ){
            ownerCar.setStartTime(dto.getStartTime());
        }
        if(dto.getEndTime() != null){
            ownerCar.setEndTime(dto.getEndTime());
        }
        ownerCar.setState("1001");
        if(dto.getRemark() != null){
            ownerCar.setRemark(dto.getRemark());
        }
        int updateRes = ownerVehicleMapper.updateById(ownerCar);
        if(updateRes < 1)  {
            throw new RuntimeException("修改车辆信息时出现异常");
            //return "修改车辆信息时出现异常";
        }
        return "续租车位成功";
    }
}
