package com.zeroone.star.project.constant;

public interface DashBoardConstant {

    // 缓存键常量
    String CACHE_KEY_REPAIR_STATS = "repairStats";
    String CACHE_KEY_COMPLAINT_STATS = "complaintStats";
    String CACHE_KEY_REGISTER_STATS = "registerStats";
    String CACHE_KEY_BUSINESS_COMMUNITY = "businessCommunity";
    String CACHE_KEY_OWNER_FEEDBACK = "ownerFeedback";

    // 反馈状态
    String FEEDBACK_STATUS = "W";
    String FEEDBACK_STATUS_FOLLOWING = "跟进中";
    String FEEDBACK_STATUS_COMPLETED = "完成";

    // 投诉处理状态
    String COMPLAINT_STATUS_PROCESSING = "处理中";
    String COMPLAINT_STATUS_COMPLETED = "处理完成";

    // 维修工单状态
    String REPAIR_STATUS_UNASSIGNED = "未派单";

}
