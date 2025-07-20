package com.zeroone.star.project.j6.datamanagement;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j6.datamanagement.importtemplate.TemplatePageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.datamanagement.importtemplate.TemplateVO;
import org.springframework.web.multipart.MultipartFile;

/*
 *描述 ：导入模版接口
 *Author:28768
 */
public interface ImportTemplateApis {


    /**
     * 获取合同类型名称列表
     *
     * @param templatePageQuery 分页条件
     * @return 模板数据
     */
    JsonVO<PageDTO<TemplateVO>> pageQuery(TemplatePageQuery templatePageQuery);


    /**
     * 获取模板下载地址
     * @param id 模板id
     * @return 模板下载路径
     */
    JsonVO<String> queryById(String id);



    /**
     * 添加模板
     *
     * @param file 文件数据
     * @return 文件id
     */
    JsonVO<Boolean> addTemplate(MultipartFile file);


    /**
     * 修改模板
     *
     * @param file 文件数据
     * @return 文件id
     */
    JsonVO<Boolean> modifyTemplate(MultipartFile file, String id);


    /**
     * 删除模板
     *
     * @param id 模板id
     * @return 模板id
     */
    JsonVO<Boolean> removeTemplate(String id);

}
