package com.zeroone.star.menumana.controller;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.menumana.mapper.MsPrivilegeMapper;
import com.zeroone.star.menumana.service.IPrivilegeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeAddDTO;
import com.zeroone.star.project.dto.j1.menumana.privilege.PrivilegeDTO;
import com.zeroone.star.project.j1.menumana.menuitem.PrivilegeApis;

import com.zeroone.star.project.query.j1.menumana.privilege.PrivilegeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j1.menumana.privilege.PrivilegeQueryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * \* @author cv
 * \* Time: 2025/5/20 + 13:27
 * \* Description:
 * \
 */
@RestController
@Api(tags = "菜单项")
@RequestMapping("/j1-menumana/privilege")
public class PrivilegeController implements PrivilegeApis {

    @Resource
    IPrivilegeService service;

    @Resource
    MsPrivilegeMapper ms;

    @Override
    @PostMapping("/add-privilege")
    @ApiOperation(value = "添加权限")
    public JsonVO<String> addPrivilege(@RequestBody PrivilegeAddDTO privilegeAddDTO) {
        String pId = service.addPrivilege(privilegeAddDTO);
        return pId != null ? JsonVO.success(pId) : JsonVO.fail("添加失败");
    }

    @Override
    @PutMapping("/modify-privilege")
    @ApiOperation(value = "修改权限")
    public JsonVO<String> modifyPrivilege(@RequestBody PrivilegeDTO privilegeDTO) {
        boolean result = service.modifyPrivilege(privilegeDTO);
        return result ? JsonVO.success("修改成功") : JsonVO.fail("修改失败");
    }


    @Override
    @GetMapping("/query-condition")
    @ApiOperation(value = "权限查询（条件与分页）")
    public JsonVO<PageDTO<PrivilegeQueryVO>> queryAll(PrivilegeQuery condition) {

        Page<PrivilegeDTO> dtoPage = service.listByCondition(condition);

        PageDTO<PrivilegeQueryVO> voPage = PageDTO.create(
                dtoPage,  // 传入Page<PrivilegeDTO>对象
                dto -> {
                    PrivilegeQueryVO vo = new PrivilegeQueryVO();
                    BeanUtil.copyProperties(dto, vo);
                    return vo;
                }
        );

        return JsonVO.success(voPage);
    }

    @Override
    @DeleteMapping("/delete-privilege")
    @ApiOperation(value = "删除权限")
    @ApiImplicitParams({
            @ApiImplicitParam(
                    name = "privilegeDTO",
                    value = "权限DTO（pid字段必需）",
                    required = true,
                    dataType = "PrivilegeDTO",
                    paramType = "body"
            )
    })
    public JsonVO<String> deletePrivilege(@RequestBody PrivilegeDTO privilegeDTO) {
        String id = privilegeDTO.getPid();
        boolean result = service.deletePrivilege(id);
        return result ? JsonVO.success("删除成功") : JsonVO.fail("删除失败，ID不存在");
    }

}
