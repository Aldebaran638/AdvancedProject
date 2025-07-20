package com.zeroone.star.communitymanage.controller;

import com.zeroone.star.communitymanage.service.mycommunity.MyCommunityService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.mycommunity.MyCommunityDTO;
import com.zeroone.star.project.j5.community.mycommunity.MyCommunityApis;
import com.zeroone.star.project.query.j5.community.mycommunity.MyCommunityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.community.mycommunity.MyCommunityVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cache.annotation.CacheEvict;
import org.springframework.cache.annotation.Cacheable;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;


/**
 * <p>
 * 描述：我的小区的控制器
 * </p>
 * @author 猕猴桃本桃
 * @version 1.0.0
 */
@RestController
@RequestMapping("/j5-community/mycommunity")
@RequiredArgsConstructor
@Slf4j
@Api(tags = "我的小区")
public class MyCommunityController implements MyCommunityApis {
    private final MyCommunityService myCommunityService;
    private final FastDfsClientComponent dfs;
    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

    /**
     * 根据小区id查询我的小区信息
     * @param query 查询条件
     * @return 我的小区数据展示模型
     */
    @GetMapping("query-my-community")
    @ApiOperation("查看入驻小区")
    @Override
    @Cacheable(cacheNames = "mycommunityCache",key = "#query.communityId")
    public JsonVO<PageDTO<MyCommunityVO>> queryMyCommunityById(@Validated MyCommunityQuery query) {
        PageDTO<MyCommunityVO> myCommunity = myCommunityService.getMyCommunity(query);
        return JsonVO.success(myCommunity);
    }

    /**
     * 修改入驻小区
     * @param myCommunityDTO 修改我的小区数据模型
     * @return 修改结果
     */
    @PutMapping("modify-my-community")
    @Override
    @ApiOperation("修改入驻小区（部分信息）")
    @CacheEvict(cacheNames = "mycommunityCache",key = "#myCommunityDTO.communityId")
    public JsonVO<String> modifyMyCommunity(@Validated @RequestBody MyCommunityDTO myCommunityDTO) {
        boolean result = myCommunityService.updateMyCommunity(myCommunityDTO);
        return result ? JsonVO.success(""):JsonVO.fail("");
    }

    // /**
    //  * 根据当前登录用户查询所有我的小区信息
    //  * @param query 查询我的所有小区信息的参数
    //  * @return 我的所有小区数据展示模型
    //  */
    // @Override
    // @ApiOperation("查看所有入驻小区")
    // @GetMapping("query-all-my-community")
    // public JsonVO<PageDTO<AllMyCommunityVO>> queryAllMyCommunity(@Validated AllMyCommunityQuery query) {
    //     PageDTO<AllMyCommunityVO> allMyCommunity = myCommunityService.listMyCommunity(query);
    //     return JsonVO.success(allMyCommunity);
    // }

    /**
     * 上传客服二维码
     * @param file 上传的客服二维码
     * @return 客服二维码的url
     */
    @Override
    @ApiOperation("上传客服二维码")
    @PostMapping("upload")
    public JsonVO<String> uploadFile(@ApiParam(value = "上传的客服二维码", required = true) MultipartFile file) {
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
