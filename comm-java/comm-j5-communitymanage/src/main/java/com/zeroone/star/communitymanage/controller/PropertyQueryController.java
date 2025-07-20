package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.property.impl.PropertyDetailQueryService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyPageDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyDetailDTO;
import com.zeroone.star.project.j5.community.property.PropertyQueryApis;
import com.zeroone.star.project.query.j5.community.property.PropertyDetailQuery;
import com.zeroone.star.project.query.j5.community.property.PropertyQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.communitymanage.service.property.impl.PropertyQueryServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：产权登记查询相关的控制器
 * </p>
 * @author 苏坡man
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/property")
@Api(tags = "产权登记")
@Validated
public class PropertyQueryController implements PropertyQueryApis {

    @Resource
    PropertyQueryServiceImpl propertyQueryService;

    @Resource
    PropertyDetailQueryService propertyDetailQueryService;
    private  FastDfsClientComponent dfs;
    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;


    @ApiOperation("获取房屋产权列表（条件+分页）")
    @GetMapping("query-property-list")
    @Override
    public JsonVO<PageDTO<PropertyPageDTO>> queryPropertyList(@Validated PropertyQuery query) {
        return JsonVO.success(propertyQueryService.listPropertyPage(query));
    }



    @ApiOperation("获取房屋产权详情")
    @GetMapping("query-property-detail")
    @Override
    public JsonVO<PageDTO<PropertyDetailDTO>> queryPropertyDetail(@Validated PropertyDetailQuery query) {
        return JsonVO.success(propertyDetailQueryService.listPropertyDetail(query));
    }


    /**
     * 上传产权详情里的图片
     * @param file 上传的客服二维码
     * @return 图片的url
     */
    @Override
    @ApiOperation("上传产权详情里的图片")
    @PostMapping("upload")
    public JsonVO<String> uploadFile(@ApiParam(value = "上传图片", required = true) MultipartFile file) {
        //获取文件的后缀名
        String fileName = file.getOriginalFilename();
        String extName = fileName.substring(fileName.lastIndexOf(".") + 1);
        FastDfsFileInfo fastDfsFileInfo = null;
        //上传文件
        try {
            fastDfsFileInfo = dfs.uploadFile(file.getBytes(), extName);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        if(fastDfsFileInfo == null){
            JsonVO.fail("上传失败");
        }
        String url = dfs.fetchUrl(fastDfsFileInfo, serverUrl, true);
        return JsonVO.success(url);
    }
}
