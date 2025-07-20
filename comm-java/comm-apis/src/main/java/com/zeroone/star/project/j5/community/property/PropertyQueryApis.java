

package com.zeroone.star.project.j5.community.property;

        import com.zeroone.star.project.dto.PageDTO;
        import com.zeroone.star.project.dto.j5.community.property.PropertyDetailDTO;
        import com.zeroone.star.project.dto.j5.community.property.PropertyPageDTO;
        import com.zeroone.star.project.query.j5.community.property.PropertyDetailQuery;
        import com.zeroone.star.project.query.j5.community.property.PropertyQuery;
        import com.zeroone.star.project.vo.JsonVO;
        import io.swagger.annotations.ApiOperation;
        import io.swagger.annotations.ApiParam;
        import org.springframework.web.bind.annotation.PostMapping;
        import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 描述：产权登记接口
 *      苏坡man : 获取房屋产权列表（条件+分页）、获取房屋产权详情
 * </p>
 * @author 苏坡man
 * @version 1.0.0
 */
public interface PropertyQueryApis {
    /**
     * 获取房屋产权列表
     *
     * @param query 查询条件
     * @return 房屋产权列表
     */
    JsonVO<PageDTO<PropertyPageDTO>> queryPropertyList(PropertyQuery query);

    /**
     * 获取房屋产权详情
     *
     * @param query 查询条件
     * @return 房屋产权详情
     */

    JsonVO<PageDTO<PropertyDetailDTO>> queryPropertyDetail(PropertyDetailQuery query);

    @ApiOperation("上传客服二维码")
    @PostMapping("upload")
    JsonVO<String> uploadFile(@ApiParam(value = "上传的客服二维码", required = true) MultipartFile file);
}



