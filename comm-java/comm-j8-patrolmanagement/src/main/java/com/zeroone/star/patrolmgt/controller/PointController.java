package com.zeroone.star.patrolmgt.controller; // 包名保持原样，符合模块结构

import com.zeroone.star.patrolmgt.service.IPatrolPointService;
import com.zeroone.star.project.dto.PageDTO;

import com.zeroone.star.patrolmgt.service.IInspectionPointService;
import com.zeroone.star.patrolmgt.service.PointService;
import com.zeroone.star.project.j8.patrolmgt.point.PointApis;
import com.zeroone.star.project.j8.patrolmgt.point.dto.AddPointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.PointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.SelectPointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.query.PointQuery;
import com.zeroone.star.project.j8.patrolmgt.point.query.SelectPointQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

//
import com.zeroone.star.patrolmgt.service.IInspectionPointService;
import com.zeroone.star.project.j8.patrolmgt.point.PointApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

/**
 * <p>
 * 描述：巡检点控制器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author susu Niu renyifei
 * @version 1.0.0
 */
@RestController // 标记这是一个 RESTful 控制器
@RequestMapping("/j8-patrolmgt/point") // 定义Controller的根路径，第一级模块名称
@Api(tags = "巡检点") // Swagger API 分组名称
public class PointController implements PointApis { // 类名修改为 PointController，并实现 APIs 接口

    @Autowired // 注入 Service 层接口
    private IPatrolPointService patrolPointService; // TODO 确保你创建了 IPatrolPointService 接口和实现类

    /**susu
     * 获取巡检点列表（条件+分页）
     *
     * @param query 查询条件和分页参数对象
     * @return 查询结果，包含分页信息和巡检点数据列表
     */
    @ApiOperation(value = "获取巡检点列表（条件+分页）") // Swagger 方法描述
    @GetMapping("/query-point-list") // 映射 GET 请求到 /patrolmgt/point 路径，第二级资源名称
    @Override // 实现 PointApis 接口中的方法
    public JsonVO<PageDTO<PointDTO>> queryPointList(@Validated PointQuery query) { // @Validated 开启参数校验
        // 调用 Service 层方法处理业务逻辑
        // Service 层方法返回 PageDTO<PointDTO>
        PageDTO<PointDTO> pageResult = patrolPointService.listPatrolPoints(query);
        // 将 Service 返回结果封装到 JsonVO 中返回
        return JsonVO.success(pageResult);
    }

    //susu
    @ApiOperation(value = "获取可选巡检点列表（条件+分页）")
    @GetMapping("/select-points") // 定义新的路径
    @Override
    public JsonVO<PageDTO<SelectPointDTO>> querySelectablePoints(@Validated SelectPointQuery query) {
        PageDTO<SelectPointDTO> pageResult = patrolPointService.listSelectablePoints(query);
        return JsonVO.success(pageResult);
    }

    //susu
    @ApiOperation(value = "修改巡检点信息")
    @PutMapping("//modify-point")
    @Override
    public JsonVO<String> modifyPoint(@RequestBody @Validated PointDTO pointDto) {
        int updatedCount = patrolPointService.updateExistingPatrolPoint(pointDto);
        if (updatedCount == 1) {
            return JsonVO.success("巡检点信息修改成功");
        } else {
            return JsonVO.fail("巡检点信息修改失败");
        }
    }

    //Niu
    @Autowired
    private IInspectionPointService inspectionPointService;

    /**
     * 删除巡检点
     */
    @ApiOperation(value = "删除巡检点")
    @DeleteMapping("/remove-point")
    @ApiImplicitParam(name = "inspectionId", value = "巡检点id", required = true, dataType = "String")
    @Override
    public JsonVO<String> removePoint(String inspectionId){
        int success = inspectionPointService.deleteInspectionPointByInspectionId(inspectionId);
        if (success == 1){
            return JsonVO.success("删除检查点成功");
        }else{
            return JsonVO.fail("删除检查点失败");
        }

    }

    @Resource
    PointService pointService;
    /**renyifei
     * 添加巡检点
     * @param addPointDTO
     * @return
     */
    @ApiOperation(value="添加巡检点")
    @PostMapping("/add-point")
    @Override
    public JsonVO<String> addPoint(@RequestBody AddPointDTO addPointDTO) {
        if(addPointDTO==null){
            return JsonVO.fail("添加对象不能为空");
        }
        if(
                isNullOrEmpty(addPointDTO.getInspectionName())  || isNullOrEmpty(addPointDTO.getPointObjType())
                || isNullOrEmpty(addPointDTO.getPointObjName()) || isNullOrEmpty(addPointDTO.getItemId())
                || isNullOrEmpty(addPointDTO.getCommunityId())  || isNullOrEmpty(addPointDTO.getPointObjId())
           )
        {
            return JsonVO.fail("添加对象的属性不能为null或空字符串");
        }
        return pointService.savePoint(addPointDTO);
    }

    /**
     * 判断前端传来的数据是否是null或者空字符串
     * @param str
     * @return
     */
    private boolean isNullOrEmpty(final CharSequence  str){
        return str == null || str.length() == 0;
    }
}
