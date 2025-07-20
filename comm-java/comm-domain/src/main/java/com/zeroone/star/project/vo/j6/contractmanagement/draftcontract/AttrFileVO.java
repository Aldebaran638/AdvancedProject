package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
@ApiModel("传输文件信息")
public class AttrFileVO {

    @ApiModelProperty("文件真实名")
    @JsonProperty("fileRealName")
    private String fileRealName;

    @ApiModelProperty("文件保存名")
    @JsonProperty("fileSaveName")
    private String fileSaveName;
}
