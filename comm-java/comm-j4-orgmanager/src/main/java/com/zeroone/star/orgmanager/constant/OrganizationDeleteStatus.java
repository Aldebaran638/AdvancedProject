package com.zeroone.star.orgmanager.constant;

public enum OrganizationDeleteStatus {
    SUCCESS(200, "删除组织成功"),
    NOT_FOUND(404, "组织不存在或已删除"),
    HAS_CHILDREN(403, "组织下存在子组织，无法删除"),
    FAILED(500, "删除组织失败");

    private final int code;
    private final String msg;

    OrganizationDeleteStatus(int code,String msg) {
        this.code=code;
        this.msg=msg;
    }
    public int getCode() {
        return code;
    }
    public String getMsg() {
        return msg;
    }
}
