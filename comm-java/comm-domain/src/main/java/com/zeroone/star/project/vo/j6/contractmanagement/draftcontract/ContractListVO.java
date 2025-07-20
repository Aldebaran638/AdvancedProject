package com.zeroone.star.project.vo.j6.contractmanagement.draftcontract;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.ToString;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.util.List;

@Data
@ToString
@ApiModel("合同列表展示对象")
public class ContractListVO {

    @JsonProperty("aContacts")
    @ApiModelProperty(value = "甲方联系人", example = "张经理")
    private String aContacts;

    @JsonProperty("aLink")
    @ApiModelProperty(value = "甲方联系电话", example = "18912345678")
    private String aLink;

    @JsonProperty("amount")
    @ApiModelProperty(value = "合同金额", example = "5000.00")
    private BigDecimal amount;

    @JsonProperty("attrs")
    @ApiModelProperty(value = "附件信息", example = "contract.pdf")
    private List<AttrFileVO> attrs;

    @JsonProperty("audit")
    @ApiModelProperty(value = "审核信息", example = "2002")
    private String audit;

    @JsonProperty("bContacts")
    @ApiModelProperty(value = "乙方联系人", example = "王主管")
    private String bContacts;

    @JsonProperty("bLink")
    @ApiModelProperty(value = "乙方联系电话", example = "18987654321")
    private String bLink;

    @JsonProperty("contractCode")
    @ApiModelProperty(value = "合同编号", example = "1222001")
    private String contractCode;

    @JsonProperty("contractId")
    @ApiModelProperty(value = "合同ID", example = "812025052712520410")
    private String contractId;

    @JsonProperty("contractName")
    @ApiModelProperty(value = "合同名称", example = "测试合同")
    private String contractName;

    @JsonProperty("contractParentId")
    @ApiModelProperty(value = "父合同编号", example = "FAT20240501001")
    private String contractParentId;

    @JsonProperty("contractType")
    @ApiModelProperty(value = "合同类型编码", example = "81202550236290004")
    private String contractType;

    @JsonProperty("contractTypeName")
    @ApiModelProperty(value = "合同类型名称", example = "租房合同")
    private String contractTypeName;

    @JsonProperty("createTime")
    @ApiModelProperty(value = "开始时间", example = "2025-05-01 08:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime createTime;

    @JsonProperty("endTime")
    @ApiModelProperty(value = "结束时间", example = "2025-12-31 18:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime endTime;

    @JsonProperty("objId")
    @ApiModelProperty(value = "合同对象ID", example = "OBJ123456")
    private String objId;

    @JsonProperty("objName")
    @ApiModelProperty(value = "对象名称", example = "格林城便利店")
    private String objName;

    @JsonProperty("objPersonId")
    @ApiModelProperty(value = "对象负责人ID", example = "PER20240530001")
    private String objPersonId;

    @JsonProperty("objPersonName")
    @ApiModelProperty(value = "对象负责人姓名", example = "李四")
    private String objPersonName;

    @JsonProperty("objType")
    @ApiModelProperty(value = "合同对象类型")
    private String objType;

    @JsonProperty("operator")
    @ApiModelProperty(value = "经办人", example = "王五")
    private String operator;

    @JsonProperty("operatorLink")
    @ApiModelProperty(value = "经办人联系方式", example = "13812345678")
    private String operatorLink;

    @JsonProperty("partyA")
    @ApiModelProperty(value = "甲方名称", example = "平台公司")
    private String partyA;

    @JsonProperty("partyB")
    @ApiModelProperty(value = "乙方名称", example = "格林城店铺")
    private String partyB;

    @JsonProperty("signingTime")
    @ApiModelProperty(value = "签署时间", example = "2025-04-30 10:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime signingTime;

    @JsonProperty("startTime")
    @ApiModelProperty(value = "合同开始时间", example = "2025-04-30 10:00:00")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime startTime;

    @JsonProperty("startUserId")
    @ApiModelProperty(value = "提交用户")
    private String startUserId;

    @JsonProperty("state")
    @ApiModelProperty(value = "状态码", example = "22")
    private int state;

    @JsonProperty("storeId")
    @ApiModelProperty(value = "商户ID", example = "402025052712520410")
    private String storeId;

    @JsonProperty("stateName")
    @ApiModelProperty(value = "状态名称", example = "审核中")
    private String stateName;

    @JsonProperty("statusCd")
    @ApiModelProperty(value = "状态码标识", example = "0")
    private String statusCd;

    public void setState(int state) {
        this.state = state;
        switch (state) {
            case 11:
                this.stateName = "待审核";
                break;
            case 22:
                this.stateName = "审核通过";
                break;
            case 33:
                this.stateName = "审核失败";
                break;
            case 44:
                this.stateName = "手工停止";
                break;
            default:
                this.stateName = "未知状态";
                break;
        }
    }
}
