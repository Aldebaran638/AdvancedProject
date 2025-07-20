package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.property.impl.MsPropertyMapper;
import com.zeroone.star.project.dto.j5.community.property.*;
import com.zeroone.star.project.j5.community.property.PropertyUpdateApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.communitymanage.service.property.impl.PropertyUpdateServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：产权登记增删改相关的控制器
 * </p>
 * @author Jungle
 * @version 1.0.0
 */
@Slf4j
@Validated
@RestController
@RequestMapping("/j5-community/property")
@Api(tags = "产权登记")
public class PropertyUpdateController implements PropertyUpdateApis {

    @Resource
    MsPropertyMapper ms;

    @Resource
    PropertyUpdateServiceImpl propertyUpdateService;

    @PostMapping("/add-property")
    @ApiOperation(value = "添加房屋产权")
    public JsonVO<String> addProperty(@Validated  @RequestBody AddPropertyDTO addDto) {

        log.info("addDto:{}", addDto);

        //参数校验 使用validate在传入参数时已经校验过了

        //调用service
        String result=propertyUpdateService.saveProperty(addDto);
        if (result!=null) return JsonVO.success("操作成功,产权登记id为"+result);
        else return JsonVO.fail("失败");
    }


    @ApiOperation(value = "删除房屋产权")
    @DeleteMapping("/delete-by-prrId")
    public JsonVO<String> removeProperty(@Validated  @RequestBody PropertyDeleteDTO propertyDeleteDTO)
    {

        String msg=propertyUpdateService.remove(propertyDeleteDTO.getPrrId());
        if(msg==null)
            return JsonVO.success("删除成功,prrId为:"+propertyDeleteDTO.getPrrId());
        return JsonVO.fail(msg);
    }


    @ApiOperation(value = "修改房屋产权")
    @PutMapping("/modify-property")
    public JsonVO<String> modifyProperty(@Validated @RequestBody PropertyDTO propertyDto) {
        String msg=propertyUpdateService.updateProperty(propertyDto);
        if (msg==null) return JsonVO.success("修改成功,prrId为:"+propertyDto.getPrrId());
        return JsonVO.fail(msg);
    }

    @ApiOperation(value = "修改附件项" )
    @PutMapping("/modify-file-rel")
    public JsonVO<String> modifyFileRel(@Validated @RequestBody PropertyDetailDTO propertyDetailDTO)
    {
        String msg=propertyUpdateService.updatePrrd(propertyDetailDTO);
        if (msg==null) return JsonVO.success("修改成功");
        return JsonVO.fail(msg);
    }

    @ApiOperation(value = "审核房屋产权")
    @PostMapping("/check-property")
    public JsonVO<String> checkProperty(@Validated @RequestBody PropertyCheckDTO checkDTO) {

        String msg=propertyUpdateService.checkPrr(checkDTO);
        if (msg==null) return JsonVO.success("审核成功,prrId为:"+checkDTO.getPrrId());
        return JsonVO.fail(msg);
    }

}
