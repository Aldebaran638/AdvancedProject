package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

import java.io.Serializable;
import java.util.List;

/**
 * 上传发票图片请求DTO
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("发票图片上传模型")
public class InvoicePhotoUploadDTO implements Serializable{

    @ApiModelProperty(value = "发票申请ID")
    private String applyId;

    @ApiModelProperty(value = "社区ID")
    private String communityId;

    @ApiModelProperty(value = "发票图片")
    private List<MultipartFile> files;

}