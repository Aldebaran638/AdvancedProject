#include "CommunityVenueService.h"
#include "dao/communityvenue/CommunityVenueDAO.h"
#include "id/SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include<iostream>
#include "oatpp/core/base/Environment.hpp"  
#include <exception>


// 分页查询所有数据
CommunityVenuePageDTO::Wrapper CommunityVenueService::listAll(const CommunityVenueQuery::Wrapper& query) 
{
    // 构建返回对象
    auto pages = CommunityVenuePageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    CommunityVenueDAO dao;
    v_uint64 count = dao.count(query);
    if (count == 0) {
        return pages;
    }

    // 设置总条数并计算页数
    pages->total = count;
    pages->calcPages();

    // 分页查询数据
    list<CommunityVenueDO> result = dao.selectWithPage(query);
    for (CommunityVenueDO& doItem : result) 
    {
        auto dto = CommunityVenueDTO::createShared();
        // DO -> DTO 字段映射（按照 CommunityVenueDO 的属性）
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, doItem,
            venueId, VenueId,    // ← 先写 dto 字段，再写 doItem.getVenueId()
            name, Name,
            remark, Remark,
            bId, BId,
            statusCd, StatusCd,
            startTime, StartTime,
            endTime, EndTime);
        pages->addData(dto);
    }
    return pages;
}

// 通过ID查询单个数据
    CommunityVenueDTO::Wrapper CommunityVenueService::getById(std::string id)
     {
        CommunityVenueDAO dao;
        auto doRes = dao.selectById(id);
        if (!doRes) {
            return nullptr;
        }
        auto dto = CommunityVenueDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, doRes,
            venueId, VenueId,
            name, Name,
            remark, Remark,
            bId, BId,

            statusCd, StatusCd,
            startTime, StartTime,
            endTime, EndTime);
        return dto;
    }

// 保存数据
std::string CommunityVenueService::saveData(const CommunityVenueAddDTO::Wrapper& dto) {
    // 组装 DO
    CommunityVenueDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Name, name,
        Remark, remark,
        StartTime, startTime,
        EndTime, endTime);
    // 生成 ID
    SnowFlake sf(1, 1);
    std::string newId = std::to_string(sf.nextId());
    data.setVenueId(newId);

    SnowFlake sff(1, 1);
    std::string newIdd = std::to_string(sff.nextId());
    data.setCommunityId(newIdd);
    // 设置创建人、创建时间
    //data.setCreateBy(dto->getPayload()->getUsername());
    data.setCreateTime(SimpleDateTimeFormat::format());
    data.setStatusCd("0");
    data.setBId("");

    CommunityVenueDAO dao;
    return dao.insert(data) == 1 ? data.getVenueId() : "";
}


   /* std::string CommunityVenueService::saveData(const CommunityVenueAddDTO::Wrapper& dto) {
        try {
            CommunityVenueDO data;

            // DTO -> DO 字段拷贝
            ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
                Name, name,
                Remark, remark,
                StartTime, startTime,
                EndTime, endTime);

            // 生成主键
            SnowFlake sf(1,1);
            std::string newId = std::to_string(sf.nextId());
            data.setVenueId(newId);

            // 注入审计字段
            data.setCreateBy(dto->getPayload()->getUsername());
            data.setCreateTime(SimpleDateTimeFormat::format());

            // 打印插入前的所有关键字段
            OATPP_LOGD("CommunityVenueService",
                "准备插入场馆: venueId=%s, name=%s, startTime=%s, endTime=%s, createBy=%s",
                data.getVenueId().c_str(),
                data.getName().c_str(),
                data.getStartTime().c_str(),
                data.getEndTime().c_str(),
                data.getCreateBy().c_str());

            // 执行插入
            CommunityVenueDAO dao;
            int ret = dao.insert(data);
            if (ret != 1) {
                OATPP_LOGE("CommunityVenueService",
                    "插入失败: venueId=%s, 返回行数=%d",
                    newId.c_str(),
                    ret);
                return "";
            }

            OATPP_LOGI("CommunityVenueService",
                "插入成功: venueId=%s",
                newId.c_str());
            return newId;
        }
        catch (const std::exception& e) {
            OATPP_LOGE("CommunityVenueService",
                "保存异常: %s",
                e.what());
            return "";
        }
        catch (...) {
            OATPP_LOGE("CommunityVenueService",
                "保存未知异常");
            return "";
        }
    }
    */



// 修改数据
bool CommunityVenueService::updateData(const CommunityVenueModifyDTO::Wrapper& dto) {
    CommunityVenueDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        Name, name,
        Remark, remark,


        StartTime, startTime,
        EndTime, endTime,
        VenueId, venueId);
    // 设置修改人、修改时间
   // data.setUpdateBy(dto->getPayload()->getUsername());
    //data.setUpdateTime(SimpleDateTimeFormat::format());

    CommunityVenueDAO dao;
    return dao.update(data) == 1;
}

// 通过ID删除数据
bool CommunityVenueService::removeData(const oatpp::List<oatpp::String>& ids) 
{
    CommunityVenueDAO dao;
    auto session = dao.getSqlSession();
    session->beginTransaction();
    int rows = 0;
    for (auto one : *ids.get()) {
        rows += dao.deleteById(one.getValue({}));
    }
    if (rows == ids->size()) {
        session->commitTransaction();
        return true;
    }
    session->rollbackTransaction();
    return false;
}
