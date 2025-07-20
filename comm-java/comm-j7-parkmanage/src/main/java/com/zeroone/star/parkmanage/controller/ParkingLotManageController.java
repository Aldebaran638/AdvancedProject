package com.zeroone.star.parkmanage.controller;

import com.zeroone.star.parkmanage.service.IParkingLotManageService;
import com.zeroone.star.parkmanage.service.ParkingLotManagerService;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.ParkingAreaDTO;
import com.zeroone.star.parkmanage.service.IParkingAreaService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.InsertParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.UpdateParkingLotDTO;
import com.zeroone.star.project.j7.parkmanage.ParkingLotManageApis;
import com.zeroone.star.project.query.j7.parkmanage.parkinginfo.ListParkingAreaQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j7.parkmanage.parkinginfo.ParkingAreaVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import com.zeroone.star.project.query.j7.parkmanage.parkinglotmanage.GetParkingLotQuery;
import org.springframework.web.bind.annotation.*;


/**
 * @author neko
 * #Description：停车场管理控制器
 * #Date: 2025/5/19 18:23
 */
@RestController
@RequestMapping("/j7-park/park-manage/parking-lot-manage")
@Api(tags = "停车场管理")
@RequiredArgsConstructor
public class ParkingLotManageController implements ParkingLotManageApis {
    private final ParkingLotManagerService parkingLotManagerService;

    private final IParkingLotManageService iparkingLotManageService;

    @Autowired
    private IParkingAreaService parkingAreaService;

    @ApiOperation("获取停车场名称列表")
    @PostMapping("list-parkingArea-name")
    public JsonVO<ParkingAreaVO> listParkingAreaName(@RequestBody ListParkingAreaQuery requestParam) {
        ParkingAreaDTO parkingAreaDTO = new ParkingAreaDTO();
        BeanUtils.copyProperties(requestParam, parkingAreaDTO);
        return JsonVO.success(parkingLotManagerService.listParkingAreaName(parkingAreaDTO));
    }

    @ApiOperation(value = "删除停车场")
    @DeleteMapping("/remove-parking-lot")
    @ApiImplicitParam(name = "paId", value = "停车场ID", required = true, example = "102023031146610004")
    @Override
    public JsonVO<String> removeParkingLot(String paId) {
        iparkingLotManageService.removeById(paId);
        return JsonVO.success("操作成功");
    }
    @ApiOperation(value = "获取停车场列表 (条件+分页)")
    @GetMapping("/list-parking-lots")
    @Override
    public JsonVO<PageDTO<GetParkingLotDTO>> listParkingLots(GetParkingLotQuery query) {
        PageDTO<GetParkingLotDTO> getParkingLotDTOPageDTO = parkingAreaService.listParkingLots(query);
        return JsonVO.success(getParkingLotDTOPageDTO);

    }

    @ApiOperation(value = "添加停车场")
    @PostMapping("/insert-parking-lot")
    @Override
    public JsonVO<String> insertParkingLot(@RequestBody InsertParkingLotDTO insertParkingLotDTO) {
        parkingAreaService.insertParkingLot(insertParkingLotDTO);
        return JsonVO.success("操作成功");
    }

    @ApiOperation(value = "修改停车场")
    @PutMapping("/update-parking-lot")
    @Override
    public JsonVO<String> updateParkingLot(@RequestBody UpdateParkingLotDTO updateParkingLotDTO) {
        parkingAreaService.updateParkingLot(updateParkingLotDTO);
        return JsonVO.success("操作成功");
    }
}
