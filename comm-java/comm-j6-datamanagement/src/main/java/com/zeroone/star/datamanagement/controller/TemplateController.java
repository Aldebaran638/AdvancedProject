package com.zeroone.star.datamanagement.controller;


import com.zeroone.star.datamanagement.entity.Template;
import com.zeroone.star.datamanagement.service.ITemplateService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.datamanagement.ImportTemplateApis;
import com.zeroone.star.project.query.j6.datamanagement.importtemplate.TemplatePageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.datamanagement.importtemplate.TemplateVO;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

/**
 * <p>
 * 模板文件表 前端控制器
 * </p>
 *
 * @author 落
 * @since 2025-05-18
 */
@RestController
@RequestMapping("/j6-datamanagement/template")
public class TemplateController implements ImportTemplateApis {

    @Resource
    ITemplateService templateService;

    /**
     * 分页条件查询模板
     *
     * @param templatePageQuery 分页条件
     * @return 模板数据
     */
    @Override
    @GetMapping("/query-page")
    @ApiOperation("分页条件查询模板")
    public JsonVO<PageDTO<TemplateVO>> pageQuery(@Validated TemplatePageQuery templatePageQuery) {
       PageDTO<TemplateVO> result =  templateService.pageQuery(templatePageQuery);
        return JsonVO.success(result);
    }

    /**
     * 根据id查询模板
     *
     * @param id 模板id
     * @return 模板下载路径
     */
    @Override
    @GetMapping("/query-by-id/{id}")
    @ApiOperation("根据id查询模板")
    public JsonVO<String> queryById(@PathVariable("id") String id) {
        Template template = templateService.getById(id);
        return JsonVO.success(template.getPath());
    }

    /**
     * 新增模板
     *
     * @param file 文件数据
     * @return 文件id
     */
    @Override
    @PostMapping("/add")
    @ApiOperation("添加模板")
    @ApiImplicitParam(name = "file", value = "模板文件", required = true)
    public JsonVO<Boolean> addTemplate(@RequestBody MultipartFile file) {
      return templateService.saveTemplate(file);
    }


    /**
     * 修改模板
     *
     * @param file 文件数据
     * @return 文件id
     */
    @Override
    @PutMapping("/modify")
    @ApiImplicitParam(name = "file", value = "模板文件", required = true)
    @ApiOperation("修改模板")
    public JsonVO<Boolean> modifyTemplate(MultipartFile file, String id) {
        return templateService.updateTemplate(file,id);
    }

    /**
     * 删除模板
     *
     * @param id 模板id
     * @return 模板id
     */
    @Override
    @ApiOperation("删除模板")
    @DeleteMapping("/delete-by-id/{id}")
    public JsonVO<Boolean> removeTemplate(@PathVariable("id") String id) {
        return templateService.removeTemplate(id);
    }
}

