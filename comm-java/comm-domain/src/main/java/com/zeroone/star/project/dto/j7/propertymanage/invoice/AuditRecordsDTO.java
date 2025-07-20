package com.zeroone.star.project.dto.j7.propertymanage.invoice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author ermali
 * @version 1.0
 */

@ApiModel("查询发票详情-----审核记录领域模型")
@Data
public class AuditRecordsDTO {
    @ApiModelProperty(value = "事件ID",example = "112321212312122132")
    private String eventId;
    @ApiModelProperty(value = "发票申请ID",example = "111111111111111111")
    private String applyId;
    @ApiModelProperty(value = "小区ID",example = "2024022647620054")
    private String communityId;
    @ApiModelProperty(value = "类型 1001 审核成功 2002 上传 3003 审核失败 4004 领用 5005 登记 ",example = "1001")
    private String eventType;
    @ApiModelProperty(value = "操作人",example = "西游物业")
    private String createUserName;
    @ApiModelProperty(value = "操作人ID",example = "302024022634540081")
    private String createUserId;
    @ApiModelProperty(value = "备注",example = "备注")
    private String remark;
    @ApiModelProperty(value = "创建时间",example = "2025-05-20 21:35:39")
    private Data createTime;
    @ApiModelProperty(value = "数据状态  详细参考c_status表， 0在用  1失效",example = "1")
    private String statusCd;

}
