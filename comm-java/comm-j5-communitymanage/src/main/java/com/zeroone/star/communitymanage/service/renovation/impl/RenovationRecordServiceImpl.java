package com.zeroone.star.communitymanage.service.renovation.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.community.renovation.AddRenovationRecordDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationDetailDTO;
import com.zeroone.star.project.dto.j5.community.renovation.RenovationRecordDTO;
import com.zeroone.star.project.query.j5.community.renovation.RenovationDetailQuery;
import com.zeroone.star.project.query.j5.community.renovation.RenovationRecordQuery;
import com.zeroone.star.communitymanage.entity.renovation.FileRel;
import com.zeroone.star.communitymanage.entity.renovation.RoomRenovationRecord;
import com.zeroone.star.communitymanage.mapper.renovation.FileRelMapper;
import com.zeroone.star.communitymanage.mapper.renovation.RenovationRecordMapper;
import com.zeroone.star.communitymanage.service.renovation.IRenovationRecordService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author tianganwuzao
 * @since 2025-05-23
 */
@Service
public class RenovationRecordServiceImpl extends ServiceImpl<RenovationRecordMapper, RoomRenovationRecord> implements IRenovationRecordService {

    @Resource
    UserHolder userHolder;

    @Resource
    MsRecordDetailMapper  ms;

    @Resource
    FileRelMapper fileRelMapper;
    @Resource
    RenovationRecordMapper renovationRecordMapper;
    /**
     * 获取装修记录列表
     * @param query 查询参数
     * @return 装修记录列表
     */
    @Override
    public PageDTO<RenovationRecordDTO> listRenovationRecord(RenovationRecordQuery query) {
        //构建分页查询对象
        Page<RoomRenovationRecord> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询条件
        QueryWrapper<RoomRenovationRecord> wrapper = new QueryWrapper<>();
        wrapper.eq("r_id", query.getRenovationId());
        wrapper.eq("status_cd","0");
        wrapper.orderBy(true,false,"create_time");
        //查询结果
        Page<RoomRenovationRecord> result = baseMapper.selectPage(page, wrapper);

        PageDTO<RenovationRecordDTO> pageDTO = PageDTO.create(result, src -> {
            RenovationRecordDTO renovationRecordDTO = new RenovationRecordDTO();
            BeanUtil.copyProperties(src, renovationRecordDTO);
            renovationRecordDTO.setRenovationId(src.getRId());
            renovationRecordDTO.setIsViolation(src.getIsTrue());
            renovationRecordDTO.setStateName(stateName(src.getState()));
            return renovationRecordDTO;
        });
        if(result.getTotal()==0){
            return pageDTO;
        }
        pageDTO.getRows().forEach(item->{
            item.setRoomId(query.getRoomId());
            item.setRoomName(query.getRoomName());
        });
        return pageDTO;
    }
    /**
     * 删除装修记录
     * @param recordId 装修记录id
     * @return 是否删除成功
     */
    @Transactional
    @Override
    public Boolean removeRenovationRecord(String recordId) {
        RoomRenovationRecord record = getById(recordId);
        if (record==null){
            return false;
        }
        record.setStatusCd("1");
        baseMapper.updateById(record);
        List<FileRel> fileRels = fileRelMapper.selectList(new QueryWrapper<FileRel>().eq("obj_id", recordId));
        if (fileRels.size()!=0){
            fileRels.forEach(item->{
                item.setStatusCd( "1");
                fileRelMapper.updateById(item);
            });
        }
        return baseMapper.selectById(recordId).getStatusCd().equals("1");
    }

    /**
     * 获取装修详情列表
     * @param query 查询参数
     * @return 装修详情列表
     */
    @Override
    public PageDTO<RenovationDetailDTO> listRenovationRecordDetail(RenovationDetailQuery query) {
        PageDTO<RenovationDetailDTO> pageDTO = PageDTO.create(new Page<>(query.getPageIndex(), query.getPageSize()));
        if (renovationRecordMapper.selectById(query.getRecordId())==null){
            return pageDTO;
        }
        //构建分页查询对象
        List<FileRel> fileRels = fileRelMapper.selectList(new QueryWrapper<FileRel>().eq("obj_id", query.getRecordId()));
        Page<RenovationDetailDTO> result = new Page<>(query.getPageIndex(), query.getPageSize());
        if (fileRels.size()!=0){
            fileRels.forEach(item->{
                RenovationDetailDTO detail = new RenovationDetailDTO();
                detail.setUrl(item.getFileSaveName());
                detail.setCreateTime(item.getCreateTime());
                result.getRecords().add(detail);
            });
        }else {
            RenovationDetailDTO renovationDetailDTO = new RenovationDetailDTO();
            renovationDetailDTO.setRoomName( query.getRoomName());
            renovationDetailDTO.setRoomId(query.getRoomId());
            renovationDetailDTO.setCreateTime(renovationRecordMapper.selectById(query.getRecordId()).getCreateTime());
            result.setRecords(new ArrayList<>());
            result.getRecords().add(renovationDetailDTO);
            pageDTO = PageDTO.create(result, src -> {
                return renovationDetailDTO;
            });
            return pageDTO;
        }
        pageDTO = PageDTO.create(result, src -> {
            RenovationDetailDTO renovationDetailDTO = new RenovationDetailDTO();
            renovationDetailDTO.setRoomId(query.getRoomId());
            renovationDetailDTO.setRoomName(query.getRoomName());
            renovationDetailDTO.setCreateTime(src.getCreateTime());
            renovationDetailDTO.setUrl(src.getUrl());
            return renovationDetailDTO;
        });
        return pageDTO;
    }
    /**
     * 添加装修记录
     * @param dto 添加参数
     * @return 是否添加成功
     */
    @Transactional
    @Override
    public boolean saveRenovationRecord(AddRenovationRecordDTO dto) {
        //构建装修记录对象
        RoomRenovationRecord roomRenovationRecord = new RoomRenovationRecord();
        BeanUtil.copyProperties(dto, roomRenovationRecord);
        roomRenovationRecord.setStatusCd("0");
        roomRenovationRecord.setCreateTime(LocalDateTime.now());
        roomRenovationRecord.setIsTrue(dto.getIsViolation());
        roomRenovationRecord.setRId(dto.getRenovationId());
      try {
            roomRenovationRecord.setStaffId(String.valueOf(userHolder.getCurrentUser().getId()));
            roomRenovationRecord.setStaffName(userHolder.getCurrentUser().getUsername());
        } catch (Exception e) {
            e.printStackTrace();
        }
        Boolean result =renovationRecordMapper.insert(roomRenovationRecord)>0;
        //构建文件关系对象
        String recordId = roomRenovationRecord.getRecordId();
            FileRel fileRel = new FileRel();
            fileRel.setFileRelId(recordId);
            fileRel.setBId("-1");
            fileRel.setSaveWay("fastdfs");
         try {
                fileRel.setObjId(String.valueOf(userHolder.getCurrentUser().getId()));
            } catch (Exception e) {
                e.printStackTrace();
            }
            fileRel.setStatusCd("0");
            fileRel.setCreateTime(LocalDateTime.now());
        if (dto.getImgUrls()!=null){
            for (String imgUrl : dto.getImgUrls()) {
                fileRel.setFileRealName(imgUrl);
                fileRel.setFileSaveName(imgUrl);
                fileRel.setRelTypeCd("19000");
                fileRelMapper.insert(fileRel);
            }
        }
        if ( dto.getVideoUrls()!=null){
            for (String videoUrl : dto.getVideoUrls()) {
                fileRel.setFileRealName(videoUrl);
                fileRel.setFileSaveName(videoUrl);
                fileRel.setRelTypeCd("21000");
                fileRelMapper.insert(fileRel);
            }
        }
        return result;
    }

    public String stateName(String state){
        switch (state) {
            case "1000":
                return "待审核";
            case "2000":
                return "审核不通过";
            case "3000":
                return "装修中";
            case "4000":
                return "待验收";
            case "5000":
                return "验收成功";
            case "6000":
                return "验收失败";
            default:
                return "未知状态";
        }
    }
}
