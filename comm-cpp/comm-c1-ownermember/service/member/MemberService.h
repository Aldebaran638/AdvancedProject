#pragma once
#ifndef _MEMBER_SERVICE_
#define _MEMBER_SERVICE_
#include "domain/vo/member/MemberVO.h"
#include "domain/query/member/MemberQuery.h"
#include "domain/dto/member/MemberDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class MemberService
{
public:
	// 分页查询所有数据
	MemberPageDTO::Wrapper listAll(const MemberQuery::Wrapper& query);
	// 保存数据
	std::string saveData(const MemberAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const MemberDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(const oatpp::List<oatpp::String>& ids);
};

#endif // !_SAMPLE_SERVICE_