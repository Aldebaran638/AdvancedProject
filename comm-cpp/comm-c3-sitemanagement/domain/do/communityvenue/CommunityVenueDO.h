#pragma once
#ifndef _COMMUNITYVENUE_DO_
#define _COMMUNITYVENUE_DO_

#include "../DoInclude.h"

/**
 * 场馆（CommunityVenue）数据库实体类
 */
class CommunityVenueDO {
    // 场馆编号 〈对应数据库列 community_venue.venue_id〉
    CC_SYNTHESIZE(std::string, venueId, VenueId);
    // 场馆名称 〈对应数据库列 name〉
    CC_SYNTHESIZE(std::string, name, Name);
    // 备注/描述 〈对应数据库列 remark〉
    CC_SYNTHESIZE(std::string, remark, Remark);
    // 开场时间 〈对应数据库列 start_time〉
    CC_SYNTHESIZE(std::string, startTime, StartTime);
    // 关场时间 〈对应数据库列 end_time〉
    CC_SYNTHESIZE(std::string, endTime, EndTime);
    // 状态（可预约/Y，不可预约/N） 〈对应数据库列 status_cd〉
    CC_SYNTHESIZE(std::string, statusCd, StatusCd);
    // 小区 ID 〈对应数据库列 community_id〉
    CC_SYNTHESIZE(std::string, communityId, CommunityId);
    // 业务关联 ID 〈对应数据库列 b_id〉
    CC_SYNTHESIZE(std::string, bId, BId);

    // 创建人
    CC_SYNTHESIZE(std::string, createBy, CreateBy);
    // 创建时间
    CC_SYNTHESIZE(std::string, createTime, CreateTime);
    // 修改人
    CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
    // 修改时间
    CC_SYNTHESIZE(std::string, updateTime, UpdateTime);

public:
    CommunityVenueDO() {
        venueId = "";
        name = "";
        remark = "";
        startTime = "";
        endTime = "";
        statusCd = "";
        communityId = "";
        bId = "";
        // 创建/修改者、时间可留空或由框架填充
        createBy = "";
        createTime = "";
        updateBy = "";
        updateTime = "";
    }
};

// 给 CommunityVenueDO 智能指针设定别名，方便在 DAO 层使用
typedef std::shared_ptr<CommunityVenueDO> PtrCommunityVenueDO;

#endif // _COMMUNITYVENUE_DO_
