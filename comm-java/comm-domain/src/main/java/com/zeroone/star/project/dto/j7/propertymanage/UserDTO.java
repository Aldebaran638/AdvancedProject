package com.zeroone.star.project.dto.j7.propertymanage;

import lombok.Data;

import java.io.Serializable;
import java.util.List;

// 用户领域模型
@Data
public class UserDTO implements Serializable {
    public static final String LEVEL_CD_MALL = "03";//商城用户
    public static final String LEVEL_CD_ADMIN = "00";//系统管理员
    public static final String LEVEL_CD_STAFF = "01";//员工
    public static final String LEVEL_CD_USER = "02";//普通用户

    private String userId;
    private String[] userIds;

    private String userName;

    private String name;

    private String nameLike;

    private String tel;

    private String email;

    private String address;

    private String password;

    private String locationCd;

    private int age;

    private String sex;

    private String levelCd;
    private String[] levelCds;

    private String storeId;

    private String orgName;

    private String parentOrgId;

    private String departmentOrgId;

    private String orgId;

    private String[] orgIds;

    private String staffName;

    private String staffId;

    private String openId;
    private String unionId;
    private String mallOpenId;

    private String statusCd = "0";

    private String token;

    private String key;//临时登录秘钥，每次登录后重置

    private String parentOrgName;

    private List<UserAttrDTO> userAttrs;

    private String bId;

    private String belongCommunityId;

    private boolean loginByPhone;

    private String relCd;

    private String  relCdName;

    private String score;

    private String userFlag;

    private String relId;

}
