package com.zeroone.star.parkmanage.controller;

import com.zeroone.star.parkmanage.service.IParkingInfoService;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.GetParkingSpaceDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.ParkingSpaceDTO;
import com.zeroone.star.project.j7.parkmanage.ParkingInfoApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import org.springframework.web.bind.annotation.GetMapping;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinginfo.BatchAddParkingSpacesDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinginfo.ParkingInfoQuery;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author neko
 * #Description：车位信息控制器
 * #Date: 2025/5/19 18:23
 */
@RestController
@RequestMapping("/j7-park/park-manage/parking-info")
@Api(tags = "车位信息")
@RequiredArgsConstructor
public class ParkingInfoController implements ParkingInfoApis {

	private final IParkingInfoService parkingInfoService;

	@ApiOperation(value = "添加车位")
	@PostMapping("/save")
	@Override
	public JsonVO<String> save(@RequestBody ParkingSpaceDTO parkingSpaceDTO) {
		parkingInfoService.save(parkingSpaceDTO);
		return JsonVO.success("success");
	}

	@ApiOperation(value = "修改车位")
	@PutMapping("/edit")
	@Override
	public JsonVO<String> update(@RequestBody ParkingSpaceDTO parkingSpaceDTO) {
		parkingInfoService.update(parkingSpaceDTO);
		return JsonVO.success("success");
	}

	@ApiOperation(value = "删除车位")
	@DeleteMapping("/remove/{psId}")
	@Override
	public JsonVO<String> remove(@PathVariable("psId") Long psId) {
		parkingInfoService.remove(psId);
		return JsonVO.success("success");
	}


    @ApiOperation("获取车位列表 (条件+分页)")
    @GetMapping("/query")
    @Override
    public JsonVO<PageDTO<GetParkingSpaceDTO>> queryParkingInfo(ParkingInfoQuery query) {
        return JsonVO.success(parkingInfoService.listParkingSpace(query));
    }

    @ApiOperation("批量添加车位")
    @PostMapping("/batch-add")
    @Override
    public JsonVO<String> batchAddParkingSpaces(@RequestBody BatchAddParkingSpacesDTO batchAddParkingSpacesDTO) {

        return JsonVO.success(parkingInfoService.saveBatch(batchAddParkingSpacesDTO));
    }


}
