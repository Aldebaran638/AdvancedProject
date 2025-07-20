package com.zeroone.star.datamanagement.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.datamanagement.entity.Template;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j6.datamanagement.importtemplate.TemplatePageQuery;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.vo.j6.datamanagement.importtemplate.TemplateVO;

import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 模板文件表 服务类
 * </p>
 *
 * @author 落
 * @since 2025-05-18
 */
public interface ITemplateService extends IService<Template> {

    /**
     * 模板分页查询
     * @param templatePageQuery 分页查询条件
     * @return 模板数据集合
     */
    PageDTO<TemplateVO> pageQuery(TemplatePageQuery templatePageQuery);

    /**
     * 添加模板
     * @param file 模板文件
     * @return 模板id
     */
    JsonVO<Boolean> saveTemplate(MultipartFile file);

    /**
     * 修改模板
     *
     * @param file 文件数据
     * @param id   原文件id
     * @return 文件id
     */
    JsonVO<Boolean> updateTemplate(MultipartFile file, String id);

    /**
     * 删除模板信息
     * @param id 模板id
     * @return 模板id
     */
    JsonVO<Boolean> removeTemplate(String id);

}
