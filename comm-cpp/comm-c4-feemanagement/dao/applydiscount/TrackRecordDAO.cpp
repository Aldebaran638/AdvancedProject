#include "stdafx.h"
#include "TrackRecordDAO.h"
#include "TrackRecordMapper.h"
#include <sstream>

PtrTrackRecordDO TrackRecordDAO::getTrackRecordDetailById(std::string ardr_id) {
	string sql = "SELECT ardr.ardr_id, ard.room_name, ardr.create_user_name, ardr.create_time, ardr.state, ardr.is_true, ardr.remark FROM apply_room_discount_record ardr LEFT JOIN apply_room_discount ard ON ardr.ard_id = ard.ard_id WHERE ardr_id = ?;";
	PtrTrackRecordMapper mapper;
	return sqlSession->executeQueryOne<PtrTrackRecordDO>(sql, mapper, "%s", ardr_id);
}

int TrackRecordDAO::insert(const TrackRecordDO& iObj) {
	string sql = "INSERT INTO `apply_room_discount_record` (`ardr_id`, `ard_id`, `b_id`, `community_id`, `status_cd`, `create_user_id`, `create_user_name`, `remark`, `is_true`, `state`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s", iObj.getArdrId(), iObj.getArdId(), iObj.getBId(), iObj.getCommunityId(),
		iObj.getStatusCd(), iObj.getCreateUserId(), iObj.getCreateUserName(), iObj.getRemark(), iObj.getIsTrue(), iObj.getState());
}

int TrackRecordDAO::deleteTrackRecordById(std::string ardr_id) {
	string sql = "DELETE FROM apply_room_discount_record WHERE ardr_id=?";
	return sqlSession->executeUpdate(sql, "%s", ardr_id);
}

int TrackRecordDAO::deleteTrackRecordById(const TrackRecordDO& dObj) {
	string id = dObj.getArdrId();
	string sql = "DELETE FROM apply_room_discount_record WHERE ardr_id=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
