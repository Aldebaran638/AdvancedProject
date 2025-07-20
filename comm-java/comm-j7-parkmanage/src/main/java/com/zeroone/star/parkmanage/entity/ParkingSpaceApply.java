package com.zeroone.star.parkmanage.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

@Getter
@Setter
public class ParkingSpaceApply implements Serializable {
    private static final long serialVersionUID = 1L;
    // 申请ID
    @TableId(value="apply_id",type = IdType.ASSIGN_ID)
    private String applyId;

    // 车位ID
    private String psId;

    // 小区ID
    private String communityId;

    // 车牌号（varchar(12)）
    private String carNum;

    // 汽车品牌
    private String carBrand;

    // 车辆类型（9901 家用小汽车，9902 客车，9903 货车）
    private String carType;

    // 车辆颜色
    private String carColor;

    // 起租时间
    private LocalDateTime startTime;

    // 续租时间
    private LocalDateTime endTime;

    // 状态（1001 待审核 2002 待缴费 3003 完成 4004 审核）
    private String state;

    // 费用项ID  0000
    private String configId;

    // 申请人姓名
    private String applyPersonName;

    // 申请人电话（varchar(11)）
    private String applyPersonLink;

    // 申请人ID 0000
    private String applyPersonId;

    // 备注（varchar(300)）
    private String remark;

    // 创建时间
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    // 数据状态（S 保存，0 在用，1 失效）
    private String statusCd;

    // 费用ID  000
    private String feeId;


}
