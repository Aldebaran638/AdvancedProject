package com.zeroone.star.systemmanage.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import lombok.Data;

import java.util.Date;

@Data
@TableName("system_info")
public class SystemInfoDO {
    private String imgUrl;
    @TableId(type = IdType.AUTO)
    private String systemId;
    private String ownerTitle;
    private String defaultCommunityId;
    private String systemTitle;

    private String systemSimpleTitle;

    private String qqMapKey;
    private String subSystemTitle;
    private String companyName;
    private String mallUrl;

    private String ownerUrl;
    private String propertyUrl;

    private String logoUrl;
    private String propertyTitle;


    private Date createTime;

    private String statusCd = "0";

}
