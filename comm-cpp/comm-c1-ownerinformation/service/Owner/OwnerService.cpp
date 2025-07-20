#include "stdafx.h"
#include "OwnerService.h"
#include "dao/owner/OwnerDAO.h"
#include "domain/dto/owner/OwnerDTO.h"
#include "domain/vo/owner/OwnerVo.h"
#include "domain/query/owner/OwnerListQuery.h"
#include "id/UuidFacade.h"
#include "SimpleDateTimeFormat.h"

using namespace oatpp;

OwnerPageDTO::Wrapper OwnerService::listAll(const OwnerListQuery::Wrapper& query)
{
    // 创建返回对象
    auto pages = OwnerPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    OwnerDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    list<OwnerDO> result = dao.selectWithPage(query);

    // 将DO转换成DTO
    for (OwnerDO sub : result)
    {
        auto dto = OwnerDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,name,Name,sex,Sex,link,Link,id_card,IdCard,create_by,CreateBy,
            remark,Remark,address,Address,owner_id,OwnerId);
        pages->addData(dto);
    }
    return pages;
}

/*OwnerDTO::Wrapper OwnerService::getById(std::string id)
{
    // 查询数据
    OwnerDAO dao;
    auto res = dao.selectById(id);

    // 如果没有查询到数据，返回空指针
    if (!res)
        return nullptr;

    // 将查询到的数据转换成DTO
    auto dto = OwnerDTO::createShared();
    ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, name, Name, sex, Sex, id_card, IdCard, link, Link);
    return dto;
}*/

std::string OwnerService::saveData(const OwnerAddDTO::Wrapper& dto)
{
    // 组装DO数据
    OwnerDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
        MemberId,member_id,
        //OwnerId, owner_id, 
        BId,b_id, Name, name,Sex,sex,Age,age,
        Link,link,UserId,user_id,Remark,remark,CreateTime,create_time,
        StatusCd,status_cd, OwnerTypeCd, owner_type_cd, CommunityId, community_id,
        IdCard, id_card, State,state, OwnerFlag, owner_flag, Address, address, 
        RoomNum,room_num);

    // 生成ID
    UuidFacade uf;
    data.setOwnerId(uf.genUuid());

    // 设置创建时间
    data.setCreateTime(SimpleDateTimeFormat::format("%Y-%m-%d %H:%M:%S"));
    // 执行数据添加
    OwnerDAO dao;
    return dao.insert(data) == 1 ? data.getOwnerId() : "";
}

bool OwnerService::updateData(const OwnerDTO::Wrapper& dto)
{
    // 组装DO数据
    OwnerDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,  Name, name, Sex, sex,Link,link,  Remark, remark,IdCard,id_card,
        Address, address,OwnerId,owner_id);

    // 执行数据修改
    OwnerDAO dao;
    return dao.update(data) == 1;
}

bool OwnerService::removeData(const oatpp::List<oatpp::String>& ids)
{
    OwnerDAO dao;
    // 开启事务
    dao.getSqlSession()->beginTransaction();
    // 循环删除
    int rows = 0;
    for (auto one : *ids.get())
    {
        rows += dao.deleteById(one.getValue({}));
    }
    // 判断是否全部删除成功
    if (rows == ids->size())
    {
        // 提交事务
        dao.getSqlSession()->commitTransaction();
        return true;
    }
    // 回滚事务
    dao.getSqlSession()->rollbackTransaction();
    return false;
}