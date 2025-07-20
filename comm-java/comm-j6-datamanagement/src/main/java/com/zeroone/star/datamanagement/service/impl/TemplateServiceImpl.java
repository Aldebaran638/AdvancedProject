package com.zeroone.star.datamanagement.service.impl;


import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.datamanagement.entity.Template;
import com.zeroone.star.datamanagement.mapper.TemplateMapper;
import com.zeroone.star.datamanagement.service.ITemplateService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j6.datamanagement.importtemplate.TemplatePageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.datamanagement.importtemplate.TemplateVO;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

/**
 * <p>
 * 模板文件表 服务实现类
 * </p>
 *
 * @author 落
 * @since 2025-05-18
 */
@Service
public class TemplateServiceImpl extends ServiceImpl<TemplateMapper, Template> implements ITemplateService {
    @Resource
    MsTemplateMapper msTemplateMapper;

    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    String serverUrl;
    /**
     * 模板分页查询
     *
     * @param templatePageQuery 分页查询条件
     * @return 模板数据集合
     */
    @Override
    public PageDTO<TemplateVO> pageQuery(TemplatePageQuery templatePageQuery) {
        long pageSize = templatePageQuery.getPageSize();
        long pageIndex = templatePageQuery.getPageIndex();

        Page<Template> templatePage = new Page<>(pageIndex, pageSize);
        boolean notBlank = StrUtil.isNotBlank(templatePageQuery.getName());
        Page<Template> page = page(templatePage, new LambdaQueryWrapper<Template>()
                .like(notBlank, Template::getName, templatePageQuery.getName()));
        return PageDTO.create(page,TemplateVO.class);
    }

    /**
     * 添加模板
     *
     * @param file 模板文件
     * @return 模板id
     */
    @Override
    public JsonVO<Boolean> saveTemplate(MultipartFile file){
        // 上传到dfs文件系统
        String[] fileInfo = uploadFile(file);
        // 构建数据
        Template template = new Template();
        template.setGroup(fileInfo[0]);
        template.setStorageId(fileInfo[1]);
        template.setPath(fileInfo[2]);
        template.setName(file.getOriginalFilename());
        // 将数据插入到数据库
        boolean save = save(template);
        if(save){
            return JsonVO.success(true);
        }else {
            return JsonVO.fail(false);
        }
    }

    /**
     * 修改模板
     *
     * @param file 文件数据
     * @return 文件id
     */
    @Override
    @Transactional
    public JsonVO<Boolean> updateTemplate(MultipartFile file, String id) {

        // 执行删除
        removeTemplate(id);
        // 执行新增方法
        JsonVO<Boolean> stringJsonVO = saveTemplate(file);
        return stringJsonVO;

    }

    /**
     * 删除模板信息
     *
     * @param id 模板id
     * @return 模板id
     */
    @Override
    public JsonVO<Boolean> removeTemplate(String id) {
        // 查询数据库获取dfs中文件的group和storageId
        Template template = getById(id);
        if(template==null) {
            return JsonVO.fail(false);
        }
        String group = template.getGroup();
        String storageId = template.getStorageId();
        FastDfsFileInfo dfsFileInfo = FastDfsFileInfo.builder()
                .group(group)
                .storageId(storageId)
                .build();
        int delete;
        try {
            delete= dfs.deleteFile(dfsFileInfo);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        if(delete!=0) {
            return JsonVO.fail(false);
        }

        boolean b = removeById(id);
        if(!b){
            return JsonVO.fail(false);
        }
        return JsonVO.success(true);
    }


    /**
     * 上传文件到dfs
     * @param file 文件
     * @return 0：group 1:storageId 2:url
     */
    private String[] uploadFile(MultipartFile file) {
        String filename = file.getOriginalFilename();
        String extName = filename.substring(filename.lastIndexOf(".") + 1);
        FastDfsFileInfo fastDfsFileInfo;
        String[] result = new String[3];
        try {
            fastDfsFileInfo = dfs.uploadFile(file.getBytes(), extName);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        // 获取文件地址
        String url = dfs.fetchUrl(fastDfsFileInfo, serverUrl, true);
        result[0]=fastDfsFileInfo.getGroup();
        result[1] = fastDfsFileInfo.getStorageId();
        result[2] = url;
        return result;
    }
}
