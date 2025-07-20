package com.zeroone.star.project.vo.j4.orgmanager;

import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;

import java.util.List;

/**
 * <p>
 * 描述：树状权限显示数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class EmpAuthTreeVO{
    @ApiModelProperty(value = "序号", example = "1")
    private String id;
    @ApiModelProperty(value = "权限名称", example = "主页")
    private String name;
    @ApiModelProperty(value = "父级菜单编号", example = "0")
    private String pid;
    @ApiModelProperty(value = "节点包含的子节点")
    public List<EmpAuthTreeVO> children;

    public void addChild(EmpAuthTreeVO vo){
        this.children.add(vo);
    }
}
