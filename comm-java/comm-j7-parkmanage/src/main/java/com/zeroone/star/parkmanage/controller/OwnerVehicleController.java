package com.zeroone.star.parkmanage.controller;

import cn.hutool.core.util.IdUtil;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import com.zeroone.star.parkmanage.entity.OwnerCar;
import com.zeroone.star.parkmanage.entity.OwnerCar1;
import com.zeroone.star.parkmanage.service.IBusinessOwnerCarService;
import com.zeroone.star.parkmanage.service.IOwnerCarService;
import com.zeroone.star.parkmanage.service.OwnerVehicleService;
import com.zeroone.star.parkmanage.service.IMemberVehicleService;
import com.zeroone.star.parkmanage.service.impl.MsMemberVehicleMapper;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.*;
import com.zeroone.star.project.j7.parkmanage.OwnerVehicleApis;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.MemberVehicleQuery;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.ModifyRecordQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.OwnerCarInfoVO;
import com.zeroone.star.project.vo.j7.parkmanage.ownervehicle.OwnerVehicleVO;
import io.swagger.annotations.*;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.CarQuery;
import com.zeroone.star.project.query.j7.parkmanage.ownervehicle.ExportCarQuery;

import com.zeroone.star.project.dto.j7.parkmanage.ownervehicle.ModifyOwnerVehicleDTO;

import java.io.File;
import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;


import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;

import javax.annotation.Resource;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.time.format.DateTimeFormatter;

import java.util.HashMap;
import java.util.Map;



/**
 * @author neko
 * #Description：业主车辆控制器
 * #Date: 2025/5/19 18:23
 */
@RestController
@RequestMapping("/j7-park/park-manage/owner-vehicle")
@Api(tags = "业主车辆")
@Slf4j
public class OwnerVehicleController implements OwnerVehicleApis {

    @Autowired
    private OwnerVehicleService ownerVehicleService;

    @Autowired
    private IOwnerCarService ownerCarService;

    @Resource
    IMemberVehicleService memberVehicleService;

    @Resource
    IBusinessOwnerCarService businessOwnerCarService;

    @Resource
    MsMemberVehicleMapper ms1;
    @ApiOperation(value = "获取车辆修改记录（条件+分页）")
    @GetMapping("modify-record")
    @Override
    public JsonVO<PageDTO<ModifyRecordDTO>> queryModifyRecordList(@Validated ModifyRecordQuery query) {
        return JsonVO.success(businessOwnerCarService.listModifyRecord(query));
    }
    @ApiOperation(value = "获取成员车辆列表（条件+分页）")
    @GetMapping("member-vehicle")
    @Override
    public JsonVO<PageDTO<MemberVehicleDTO>> queryMemberVehicleList(@Validated MemberVehicleQuery query) {
        return JsonVO.success(ownerCarService.listMemberVehicle(query));
    }
    @ApiOperation(value = "添加成员车辆")
    @PostMapping("add-member-vehicle")
    @Override
    public JsonVO<String> addMemberVehicle(@Validated AddMemberVehicleDTO addMemberVehicleDTO) {
        OwnerCar1 ownerCar = ownerCarService.saveAddToOwnerCar(addMemberVehicleDTO);
        if(ownerCarService.save(ownerCar)){
            return JsonVO.success(ownerCar.getMemberId());
        }
        return JsonVO.fail("成员车辆保存失败");
    }

    /**
     * 获取车辆基础信息
     * @param carId
     * @return
     */
    @ApiOperation("获取车辆基础信息")
    @GetMapping("/query-vehicle-info")
    @Override
    public JsonVO<OwnerVehicleVO> getOwnerVehicleInfo(@RequestParam String carId) {
        // 1. 参数校验 (车牌号)
        if (carId==null) {
            return JsonVO.fail(null);
        }

        // 2. 调用服务层根据车牌号查询车辆信息
        OwnerVehicleVO vehicleInfo = ownerVehicleService.getVehicleInfoByCarId(carId);

        // 3. 返回结果
         if (vehicleInfo == null) {
             return JsonVO.fail( null);
         }
        return JsonVO.success(vehicleInfo);
    }


    /**
     * 导入车辆
     * @param file
     * @return
     */
    @ApiOperation("导入车辆")
    @PostMapping("/import-vehicle")
    @Override
    public JsonVO<String> importVehicle(MultipartFile file) {
        if (file == null || file.isEmpty()) {
            return JsonVO.fail("请选择要导入的文件");
        }
        String fileName = file.getOriginalFilename();
        if (fileName == null || (!fileName.endsWith(".xlsx") && !fileName.endsWith(".xls"))) {
            return JsonVO.fail("请上传Excel文件");
        }

        // 保存文件到临时目录
        String tempFilePath = null;
        try {
            tempFilePath = saveTempFile(file);
            String result = ownerVehicleService.importVehicleData(tempFilePath);

            // 根据返回结果判断导入状态
            if ("全部导入成功".equals(result)) {
                return JsonVO.success(result);
            } else {
                return JsonVO.fail(result);
            }

        } catch (Exception e) {
            log.error("导入车辆数据失败", e);
            return JsonVO.fail("导入过程中发生错误：" + e.getMessage());
        } finally {
            // 删除临时文件
            if (tempFilePath != null) {
                deleteTempFile(tempFilePath);
            }
        }
    }

    /**
     * 保存上传的文件到临时目录
     */
    private String saveTempFile(MultipartFile file) throws IOException {
        String tempDir = System.getProperty("java.io.tmpdir");
        String fileName = file.getOriginalFilename();
        String tempFilePath = tempDir + File.separator + fileName;
        File dest = new File(tempFilePath);
        file.transferTo(dest);
        return tempFilePath;
    }

    /**
     * 删除临时文件
     */
    private void deleteTempFile(String filePath) {
        try {
            File file = new File(filePath);
            if (file.exists()) {
                file.delete();
            }
        } catch (Exception e) {
            log.error("删除临时文件失败: {}", filePath, e);
        }
    }



    /**
     * 导出车辆数据
     * @param query 查询条件，包含社区ID、车牌号、业主名称等筛选条件
     * @return 返回Excel文件的字节流
     * @author 岚图
     */
    @ApiOperation(value = "导出车辆数据", notes = "根据查询条件导出车辆数据，返回Excel文件的字节流")
    @GetMapping("/export-vehicle")
    @Override
    public JsonVO<Map<String, String>> exportVehicle(ExportCarQuery query) {
        log.info("Controller 接收到导出车辆请求，查询条件：{}", query);

        // 参数校验 (可根据需要添加更详细的校验)
        if (query == null) {
            log.warn("导出请求参数为空");
            JsonVO<Map<String, String>> result = new JsonVO<>();
            result.setCode(500); // 或者其他代表失败的状态码
            result.setMessage("查询参数不能为空");
            result.setData(new HashMap<>()); // data字段设置为一个空Map或包含error键的Map
            return result;
        }

        try {
            // 1. 调用Service层获取Base64编码后的字节数组
            byte[] base64Bytes = ownerVehicleService.triggerExport(query);
            String base64Content = new String(base64Bytes, StandardCharsets.UTF_8); // 转换为字符串

            log.debug("Service 层导出方法返回 {} 字节 Base64 数据", base64Bytes.length);

            // 2. 判断返回的是否是错误信息
            // 假设 Service 返回的错误信息是 UTF-8 编码的 Base64 字符串
            if (base64Bytes != null && base64Bytes.length > 0) {
                String possibleError = new String(java.util.Base64.getDecoder().decode(base64Bytes), StandardCharsets.UTF_8); // 先解码再判断
                if (possibleError.startsWith("导出失败：") || possibleError.equals("导入数据为空") || possibleError.equals("业主不存在") || possibleError.startsWith("数据保存失败")) {
                    log.error("Service 层导出失败：{}", possibleError);
                    JsonVO<Map<String, String>> result = new JsonVO<>();
                    result.setCode(500); // 或者其他代表失败的状态码
                    result.setMessage(possibleError);
                    result.setData(new HashMap<>()); // data字段设置为一个空Map或包含error键的Map
                    return result;
                }
            } else {
                log.warn("Service 层导出方法返回空数据");
                JsonVO<Map<String, String>> result = new JsonVO<>();
                result.setCode(500); // 或者其他代表失败的状态码
                result.setMessage("未查询到可导出的车辆数据");
                result.setData(new HashMap<>()); // data字段设置为一个空Map或包含error键的Map
                return result;
            }

            // 3. 构建返回给前端的Map，包含文件名、Content-Type和Base64内容
            Map<String, String> resultData = new HashMap<>();
            String filename = "业主车辆导出-" + LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMddHHmmss")) + ".xlsx";
            
            resultData.put("filename", filename);
            resultData.put("contentType", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
            resultData.put("fileContent", base64Content); // Base64编码后的文件内容

            log.info("成功构建导出响应，文件大小：{} 字节", base64Bytes.length);

            // 4. 封装到 JsonVO 并返回
            return JsonVO.success(resultData);

        } catch (Exception e) {
            // 捕获 Service 或其他环节发生的意外异常
            log.error("导出车辆数据过程中发生异常", e);
            // 返回一个包含错误信息的 JsonVO
            JsonVO<Map<String, String>> result = new JsonVO<>();
            result.setCode(500); // 或者其他代表失败的状态码
            result.setMessage("导出失败：服务器内部错误：" + e.getMessage());
            result.setData(new HashMap<>()); // data字段设置为一个空Map或包含error键的Map
            return result;
        }
    }


    @PostMapping("/add-car")
    @ApiOperation("添加车辆")
    @Override
    public JsonVO<String> addCar(@Validated @RequestBody AddCarDTO addCarDTO) {
        // 判断车牌类型是否为月租车
        if ("H".equals(addCarDTO.getLeaseType())) {
            // 时间不能为空
            if (addCarDTO.getStartTime() == null) {
                return JsonVO.fail("起租时间不能为空");
            }

            if (addCarDTO.getEndTime() == null) {
                return JsonVO.fail("结组时间不能为空");
            }

            // 校验起租和结组时间
            if (addCarDTO.getStartTime().isAfter(addCarDTO.getEndTime())) {
                return JsonVO.fail("起租时间不能晚于结租时间");
            }
        }

        ownerVehicleService.save(addCarDTO);

        return JsonVO.success("添加成功");
    }

    @PutMapping("/modify-car")
    @ApiOperation("修改车辆")
    @Override
    public JsonVO<String> modifyCar(@Validated @RequestBody CarDTO carDTO) {
        // 判断车牌类型是否为月租车
        if ("H".equals(carDTO.getLeaseType())) {
            if (carDTO.getStartTime() == null) {
                return JsonVO.fail("起租时间不能为空");
            }

            if (carDTO.getEndTime() == null) {
                return JsonVO.fail("结组时间不能为空");
            }

            // 校验起租和结组时间
            if (carDTO.getStartTime().isAfter(carDTO.getEndTime())) {
                return JsonVO.fail("起租时间不能晚于结租时间");
            }
        }

        LambdaUpdateWrapper<OwnerCar> updateWrapper = new LambdaUpdateWrapper<>();
        updateWrapper.eq(OwnerCar::getMemberId, carDTO.getMemberId());

        OwnerCar updateCar = new OwnerCar();
        // 更新字段值
        updateCar.setCarNum(carDTO.getCarNum());
        updateCar.setCarBrand(carDTO.getCarBrand());
        updateCar.setCarType(carDTO.getCarType());
        updateCar.setCarColor(carDTO.getCarColor());
        updateCar.setLeaseType(carDTO.getLeaseType());
        updateCar.setRemark(carDTO.getRemark());

        // 更新业务id，雪花算法
        updateCar.setBId(IdUtil.getSnowflakeNextIdStr());

        // 判断租赁类型是否为出租车
        if ("H".equals(updateCar.getLeaseType())) {
            // 更新起租和结组时间
            updateCar.setStartTime(carDTO.getStartTime());
            updateCar.setEndTime(carDTO.getEndTime());
        }

        // 调用service
        boolean update = ownerVehicleService.update(updateCar, updateWrapper);

        return update ? JsonVO.success("修改成功") : JsonVO.fail("修改失败");
    }

    @GetMapping("/query-all")
    @ApiOperation("获取车辆列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<OwnerCarInfoVO>> queryCarList(CarQuery carQuery) {
        return JsonVO.success(ownerVehicleService.selectOwnerCarInfoByPage(carQuery));
    }

    @ApiOperation(value = "删除车辆")
    @ApiImplicitParam(name = "carId", value = "车辆ID",required = true)
    @DeleteMapping("/remove-owner-vehicle")
    public JsonVO<String> removeOwnerVehicle(String carId) {
        String res = ownerVehicleService.removeVehicle(carId);
        if(res.equals("删除车辆成功")){
            return JsonVO.success(res);
        }
        return JsonVO.fail(res);
    }

    @ApiOperation(value = "释放车位")
    @ApiImplicitParam(name = "carId", value = "车辆ID",required = true)
    @PutMapping("/release-parking-space")
    public JsonVO<String> modifyOwnerVehicleByReleaseParkingSpace(String carId) {
        String res = ownerVehicleService.updateOwnerVehicleByReleaseParkingSpace(carId);
        if(res.equals("释放车位成功")){
            return JsonVO.success(res);
        }
        return JsonVO.fail(res);
    }

    @ApiOperation(value = "续租车位")
    @PutMapping("/renew-parking-space-lease")
    public JsonVO<String> modifyOwnerVehicleByRenewParkingSpaceLease(@RequestBody RenewParkingSpaceLeaseDTO dto) {
        String res = ownerVehicleService.updateOwnerVehicleByRenewParkingSpaceLease(dto);
        if(res.equals("续租车位成功")){
            return JsonVO.success(res);
        }
        return JsonVO.fail(res);
    }
    @ApiOperation(value = "修改成员车辆")
    @PutMapping("modify-owner-vehicle")
    @Override
    public JsonVO<String> modifyOwnerVehicle(@RequestBody ModifyOwnerVehicleDTO dto){

        if (memberVehicleService.updateById(ms1.toMemberVehicle(dto))){
           return JsonVO.success(dto.getId());
       }
        return JsonVO.fail(null);
    }

    @ApiOperation(value = "删除成员车辆")
    @ApiImplicitParam(name = "id", value = "车辆ID", required = true, example = "802023061661080002")
    @DeleteMapping("delete-owner-vehicle")
    @Override
    public JsonVO<String> deleteOwnerVehicle(String carId){
        boolean isDeleted = memberVehicleService.removeById(carId);
        if (isDeleted) {
            return JsonVO.success("删除成功");
        } else {
            return JsonVO.fail("删除失败，车辆不存在或已被删除");
        }
    }
}
