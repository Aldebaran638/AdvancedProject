package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import com.zeroone.star.parkmanage.entity.ParkingSpaceApply;
import com.zeroone.star.parkmanage.mapper.ParkingApplyMapper;
import com.zeroone.star.parkmanage.mapper.ParkingSpaceApplyMapper;
import com.zeroone.star.parkmanage.service.IParkingApplyService;
import com.zeroone.star.parkmanage.service.IParkingSpaceApplyService;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.AddApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ApplyDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkingapply.ReviewApplicationDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
@Service
public class ParkingApplyService extends ServiceImpl<ParkingSpaceApplyMapper, ParkingSpaceApply> implements IParkingSpaceApplyService {
    @Resource
    MsParkingApplyMapper ms;


    @Transactional
    @Override
    public int saveParkingApply(AddApplyDTO addApplyDTO) {
        ParkingSpaceApply parkingSpaceApply = ms.addDtoToDo(addApplyDTO);
        //设置默认值 插入默认数据为有用状态为0
        parkingSpaceApply.setStatusCd("0");
        //添加的申请默认为未审核状态为1001
        parkingSpaceApply.setState("1001");
        int result=baseMapper.insert(parkingSpaceApply);
        return result;

    }

    @Override
    public int updateParkingApply(ApplyDTO applyDTO) {
        int result=baseMapper.updateById(ms.dtoToDo(applyDTO));
        return result;

    }

    @Override
    public int removeParkingApply(String applyId) {
        int result=baseMapper.deleteById(applyId);
        return result;

    }

    @Override
    public JsonVO<String> reviewApplication(ReviewApplicationDTO reviewApplicationDTO) {
        int i = baseMapper.updateById(ms.dtoToDo(reviewApplicationDTO));
        if (i > 0){
            return JsonVO.success("审核成功");
        }
        return JsonVO.fail("审核失败");
    }
}
