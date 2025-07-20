package com.zeroone.star.project.dto.j1.menumana.menuitem;

import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.List;

@Data
public class MenuPrivilegeTreeDTO extends PageDTO implements Serializable {
    /**
     * 菜单组id
     */
    @ApiModelProperty(value = "菜单组id",example = "800201904004")
    private String MenuGroupId;
    /**
     * 菜单组名称
     */
    @ApiModelProperty(value = "菜单组名称",example = "小区")
    private String MenuGroupName;

    /**
     * 菜单组顺序
     */
    @ApiModelProperty(value = "菜单组顺序",example = "1")
    private Integer groupSeq;
    /**
     * 子菜单
     */
    @ApiModelProperty(value = "子菜单")
    private List<MenuItemDTO> children;

    public String getMenuGroupId() {
        return MenuGroupId;
    }

    public void setMenuGroupId(String menuGroupId) {
        MenuGroupId = menuGroupId;
    }

    public String getMenuGroupName() {
        return MenuGroupName;
    }

    public void setMenuGroupName(String menuGroupName) {
        MenuGroupName = menuGroupName;
    }

    public Integer getGroupSeq() {
        return groupSeq;
    }

    public void setGroupSeq(Integer groupSeq) {
        this.groupSeq = groupSeq;
    }

    public List<MenuItemDTO> getChildren() {
        return children;
    }

    public void setChildren(List<MenuItemDTO> children) {
        this.children = children;
    }

    public static class MenuItemDTO{
        /**
         * 菜单id
         */
        @ApiModelProperty(value = "菜单id",example = "800201904004")
        private String menuId;

        /**
         * 菜单名称
         */
        @ApiModelProperty(value = "菜单名称",example = "我的小区")
        private String menuName;
        /**
         * 菜单顺序
         */
        @ApiModelProperty(value = "菜单顺序",example = "1")
        private Integer menuSeq;
        /**
         * 菜单组id
         */
        @ApiModelProperty(value = "菜单组id",example = "800201904004")
        private String MenuGroupId;
        /**
         * 权限列表
         */
        @ApiModelProperty(value = "权限列表")
        private List<PrivilegeDTO> privileges;

        public String getMenuId() {
            return menuId;
        }

        public void setMenuId(String menuId) {
            this.menuId = menuId;
        }

        public String getMenuName() {
            return menuName;
        }

        public void setMenuName(String menuName) {
            this.menuName = menuName;
        }

        public Integer getMenuSeq() {
            return menuSeq;
        }

        public void setMenuSeq(Integer menuSeq) {
            this.menuSeq = menuSeq;
        }

        public String getMenuGroupId() {
            return MenuGroupId;
        }

        public void setMenuGroupId(String menuGroupId) {
            MenuGroupId = menuGroupId;
        }

        public List<PrivilegeDTO> getPrivileges() {
            return privileges;
        }

        public void setPrivileges(List<PrivilegeDTO> privileges) {
            this.privileges = privileges;
        }

        public static class PrivilegeDTO{
            /**
             * 权限id
             */
            @ApiModelProperty(value = "权限id",example = "800201904004")
            private String privilegeId;

            /**
             * 权限名称
             */
            @ApiModelProperty(value = "权限名称",example = "我的小区")
            private String privilegeName;

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
        }
    }

}
