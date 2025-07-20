package com.zeroone.star.dashboard.controller;

import com.zeroone.star.dashboard.service.CenterService;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import com.zeroone.star.project.j1.dashboard.center.CenterCommonMenuApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/j1-dashboard/center")
@Api(tags = "开发中心")
public class CenterController implements CenterCommonMenuApis {
    @Autowired
    private CenterService  CenterService;
    @GetMapping("/commonmenu")
    @ApiOperation(value = "常用功能")
    @Override
    public JsonVO<List<CommonMenuDTO>> getCenterCommonMenu() {
        List<CommonMenuDTO> commonMenu = CenterService.getCommonMenu();
        if (commonMenu != null) {

            return JsonVO.success(commonMenu);
        }
        return JsonVO.fail(null);
    }
}
