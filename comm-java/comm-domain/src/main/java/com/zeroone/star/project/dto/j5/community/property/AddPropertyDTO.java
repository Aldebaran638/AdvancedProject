package com.zeroone.star.project.dto.j5.community.property;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.mapstruct.Mapping;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author Jungle
 * @version 1.0.0
 */
@ApiModel("添加房屋产权数据对象")
@Data
public class AddPropertyDTO {

    @ApiModelProperty(value = "姓名",example = "Jungle",required = true)
    @NotBlank(message = "姓名不能为空")
    private String name;

    @NotBlank(message = "联系方式不能为空")
    @ApiModelProperty(value = "联系方式",example = "13452452141",required = true)
    private String link;

    @Pattern(regexp = "^\\d{18}$", message = "身份证号必须是18位纯数字")
    @ApiModelProperty(value = "身份证号",example = "111222333444556566",required = true)
    private String idCard;

    @NotBlank(message = "地址不能为空")
    @ApiModelProperty(value = "地址",example = "北京中路999号",required = true)
    private String address;


    @ApiModelProperty(value = "小区Id",example = "2023052267100146",required = true)
    private String communityId;


    @ApiModelProperty(value = "楼栋名",example = "1栋",required = true)
    private String floorName;


    @ApiModelProperty(value = "单元编号",example = "1",required = true)
    private String unitNum;

    @ApiModelProperty(value = "房屋编号",example = "1001",required = true)
    private String roomNum;

    @Pattern(regexp = "是|否", message = "缴费状态只能为   是|否")
    @ApiModelProperty(value = "维修基金是否缴费",example = "否",required = true)
    private String fundIsPaid;

    @Pattern(regexp = "是|否", message = "缴费状态只能为   是|否")
    @ApiModelProperty(value = "契税是否缴费",example = "否",required = true)
    private String taxIsPaid;

    @ApiModelProperty(value = "身份证正面照片照片",example = "PDF文件，大小不超过5MB",required = true)
    private MultipartFile frontIdCardImage;

    @ApiModelProperty(value = "身份证反面照片照片",example = "PDF文件，大小不超过5MB",required = true)
    private MultipartFile backIdCardImage;

    @ApiModelProperty(value = "购房合同图片上传",example = "请上传不超过十张购房合同图片",required = true)
    private MultipartFile[] contractImages;

    @ApiModelProperty(value = "对象ID",example = "772023061990824972",required = true)
    private String objId;




/*    @Pattern(regexp = "001|002|003|004", message = " 材料状态只能为这些值:001身份证   002购房合同   003维修基金   004契税")
    @ApiModelProperty(value = "材料类型",example = "001")
    private String securities;*/




/*    @Pattern(regexp = "0|1", message = "状态只能是0(有效的，在用的)|1(无效的，不在用的)")
    @ApiModelProperty(value = "数据状态",example = "0")
    private String statusCd;*/

/*    @ApiModelProperty(value = "创建人",example = "111")
    private String createUser;*/



    //file_rel相关参数

/*
   *//*
    @ApiModelProperty(value = "文件类型",example = "业主照片")
    private String relTypeCd;

    *//*
      存放方式，ftp table,fastdfs 具体查看t_dict表
     *//*
    @ApiModelProperty(value = "存放方式",example = "fastdfs")
    private String saveWay;

    *//*
      对象ID，及说明这个文件归宿于谁，业主则填写业主ID
     *//*
    @ApiModelProperty(value = "对象ID",example = "111111")
    private String objId;

    *//*
      文件真实名称
     *//*
    @ApiModelProperty(value = "文件真实名称",example = "业主照片")
    private String fileRealName;

    *//*
      文件存储名称
     *//*
    @ApiModelProperty(value = "文件存储名称",example = "文件存储名称")
    private String fileSaveName;*/



}
