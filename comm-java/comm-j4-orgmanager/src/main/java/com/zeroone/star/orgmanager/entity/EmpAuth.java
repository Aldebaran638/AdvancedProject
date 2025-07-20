package com.zeroone.star.orgmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

/**
 * <p>
 * 员工权限
 * </p>
 * @author heavydrink
 */
@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class EmpAuth {
    /**
     * 权限id
     */
    private String id;

    /**
     * 权限名
     */
    private String name;

    /**
     * 父级菜单编号
     */
    private String parentAuthId;

}
