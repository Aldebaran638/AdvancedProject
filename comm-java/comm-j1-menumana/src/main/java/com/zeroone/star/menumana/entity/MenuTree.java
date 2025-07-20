package com.zeroone.star.menumana.entity;

import lombok.Data;

import java.io.Serializable;
@Data
public class MenuTree implements Serializable {
    private String menuGroupId;
    private String menuGroupName;
    private Integer mgseq;
    private String menuId;
    private String privilegeId;
    private String privilegeName;

    public String getMenuGroupId() {
        return menuGroupId;
    }

    public void setMenuGroupId(String menuGroupId) {
        this.menuGroupId = menuGroupId;
    }

    public String getMenuGroupName() {
        return menuGroupName;
    }

    public void setMenuGroupName(String menuGroupName) {
        this.menuGroupName = menuGroupName;
    }

    public Integer getMgseq() {
        return mgseq;
    }

    public void setMgseq(Integer mgseq) {
        this.mgseq = mgseq;
    }

    public String getMenuId() {
        return menuId;
    }

    public void setMenuId(String menuId) {
        this.menuId = menuId;
    }

    public String getPrivilegeId() {
        return privilegeId;
    }

    public void setPrivilegeId(String privilegeId) {
        this.privilegeId = privilegeId;
    }

    public String getPrivilegeName() {
        return privilegeName;
    }

    public void setPrivilegeName(String privilegeName) {
        this.privilegeName = privilegeName;
    }

    public MenuTree(String menuGroupId, String menuGroupName, Integer mgseq, String menuId, String privilegeId, String privilegeName) {
        this.menuGroupId = menuGroupId;
        this.menuGroupName = menuGroupName;
        this.mgseq = mgseq;
        this.menuId = menuId;
        this.privilegeId = privilegeId;
        this.privilegeName = privilegeName;
    }

}
