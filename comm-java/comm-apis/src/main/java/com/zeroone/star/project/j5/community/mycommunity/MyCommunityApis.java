package com.zeroone.star.project.j5.community.mycommunity;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.mycommunity.MyCommunityDTO;
import com.zeroone.star.project.query.j5.community.mycommunity.AllMyCommunityQuery;
import com.zeroone.star.project.query.j5.community.mycommunity.MyCommunityQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j5.community.mycommunity.AllMyCommunityVO;
import com.zeroone.star.project.vo.j5.community.mycommunity.MyCommunityVO;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;


/**
 * <p>
 * 描述：我的小区接口
 *      猕猴桃本桃 : 查看入驻小区、修改入驻小区（部分信息）
 * </p>
 * @author 猕猴桃本桃
 * @version 1.0.0
 */
public interface MyCommunityApis {
    /**
     * 根据小区id获取我的小区信息
     * @param query 查询小区信息的参数
     * @return 我的小区数据展示模型
     */
    JsonVO<PageDTO<MyCommunityVO>> queryMyCommunityById(MyCommunityQuery query);

    /**
     * 修改入住小区
     * @param myCommunityDTO 修改我的小区数据模型
     * @return 修改结果
     */
    JsonVO<String> modifyMyCommunity(MyCommunityDTO myCommunityDTO);

    // /**
    //  * 根据当前登录用户查询所有我的小区信息
    //  * @param query 查询我的所有小区信息的参数
    //  * @return 我的所有小区数据展示模型
    //  */
    // JsonVO<PageDTO<AllMyCommunityVO>> queryAllMyCommunity(AllMyCommunityQuery query);

    /**
     * 上传客服二维码
     * @param file 上传的客服二维码
     * @return 文件的url
     */
    JsonVO<String> uploadFile(MultipartFile file);
}
