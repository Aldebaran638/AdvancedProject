package com.zeroone.star.project.vo.j4.orgmanager;

import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

/**
 * <p>
 * 描述：员工组织权限类
 * </p>
 * @author heavydrink
 * @version 1.0.0
 */
@ApiModel("员工组织权限类")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class EmpOrgAuthorityVO {
    /**
     * 组织
     */
    @ApiModelProperty(value = "组织", example = "运维团队")
    String org;
    /**
     * 岗位
     */
    @ApiModelProperty(value = "岗位", example = "总公司总经理")
    String job;
    /**
     * 关联角色
     */
    @ApiModelProperty(value = "关联角色", example = "管理员角色")
    String associatedRoles;
    /**
     * 关联小区
     */
    @ApiModelProperty(value = "关联小区", example = "[\"物联网同步小区\", \"三国小区\", \"中航AFC\"]")
    List<String> associatedCommunities;
    /**
     * 权限
     */
    @ApiModelProperty(value = "权限", example = "[\n" +
            "      {\n" +
            "        \"id\": \"800201904004\",\n" +
            "        \"name\": \"小区\",\n" +
            "        \"children\": [\n" +
            "          {\n" +
            "            \"id\": \"702019091772280004\",\n" +
            "            \"name\": \"审核小区\",\n" +
            "            \"pid\": \"800201904004\",\n" +
            "            \"children\": [\n" +
            "              {\n" +
            "                \"id\": \"502019091773700003\",\n" +
            "                \"name\": \"审核小区\",\n" +
            "                \"pid\": \"702019091772280004\",\n" +
            "                \"children\": []\n" +
            "              }\n" +
            "            ]\n" +
            "          },\n" +
            "          {\n" +
            "            \"id\": \"702019091754830002\",\n" +
            "            \"name\": \"小区信息\",\n" +
            "            \"pid\": \"800201904004\",\n" +
            "            \"children\": []\n" +
            "          }\n" +
            "        ]\n" +
            "      },\n" +
            "      {\n" +
            "        \"id\": \"802020021776010055\",\n" +
            "        \"name\": \"商户\",\n" +
            "        \"children\": [\n" +
            "          {\n" +
            "            \"id\": \"702020021777330057\",\n" +
            "            \"name\": \"商户信息\",\n" +
            "            \"pid\": \"802020021776010055\",\n" +
            "            \"children\": [\n" +
            "              {\n" +
            "                \"id\": \"502020021737880056\",\n" +
            "                \"name\": \"商户信息\",\n" +
            "                \"pid\": \"702020021777330057\",\n" +
            "                \"children\": []\n" +
            "              }\n" +
            "            ]\n" +
            "          }\n" +
            "        ]\n" +
            "      }\n" +
            "\t  ]")
    List<EmpAuthTreeVO> authorities;
}
