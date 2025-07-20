package com.zeroone.star.parkmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.IdWorker;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.parkmanage.entity.ParkingArea;
import com.zeroone.star.parkmanage.entity.ParkingAreaAttr;
import com.zeroone.star.parkmanage.mapper.ParkingAreaAttrMapper;
import com.zeroone.star.parkmanage.mapper.ParkingAreaMapper;
import com.zeroone.star.parkmanage.service.IParkingAreaAttrService;
import com.zeroone.star.parkmanage.service.IParkingAreaService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.GetParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.InsertParkingLotDTO;
import com.zeroone.star.project.dto.j7.parkmanage.parkinglotmanage.UpdateParkingLotDTO;
import com.zeroone.star.project.query.j7.parkmanage.parkinglotmanage.GetParkingLotQuery;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author wuven
 * @since 2025-05-26
 */
@Service
public class ParkingAreaServiceImpl extends ServiceImpl<ParkingAreaMapper, ParkingArea> implements IParkingAreaService {
    @Autowired
    private ParkingAreaMapper parkingAreaMapper;

    @Autowired
    private MsParkingAreaMapper msParkingAreaMapper;

    @Autowired
    private IParkingAreaAttrService iParkingAreaAttrService;

    @Autowired
    private ParkingAreaAttrMapper parkingAreaAttrMapper;

    @Override
    public PageDTO<GetParkingLotDTO> listParkingLots(GetParkingLotQuery query) {

        Page<ParkingArea> page =new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<ParkingArea> queryWrapper = new QueryWrapper<>();
        if (query.getNum()!=null && query.getType_cd()==null){
            queryWrapper.eq("num", query.getNum());
        }
        if (query.getNum()==null && query.getType_cd()!=null){
            queryWrapper.eq("type_cd", query.getType_cd());
        }
        if (query.getNum()!=null && query.getType_cd()!=null){
            queryWrapper.eq("num",query.getNum());
            queryWrapper.eq("type_cd",query.getType_cd());
        }
        Page<ParkingArea> businessParkingAreaPageList = parkingAreaMapper.selectPage(page, queryWrapper);
        List<ParkingArea> records = businessParkingAreaPageList.getRecords();

        List<GetParkingLotDTO> getParkingLotDTOList=new ArrayList<>();
        for (ParkingArea businessParkingArea : records) {
            String outNum = iParkingAreaAttrService.getOutNum(businessParkingArea.getPaId());
            GetParkingLotDTO parkingLotDTO = new GetParkingLotDTO();
            parkingLotDTO = msParkingAreaMapper.businessParkingAreaToGetParkingLotDTO(businessParkingArea);
            parkingLotDTO.setOut_num(outNum);
            //查询出没有逻辑删除的
            if (businessParkingArea.getStatusCd().equals("0")){
                getParkingLotDTOList.add(parkingLotDTO);
            }
        }

        PageDTO<GetParkingLotDTO> pageDTO=new PageDTO<>();
        pageDTO.setPageIndex(page.getCurrent());
        pageDTO.setPageSize(page.getSize());
        pageDTO.setPages(page.getPages());
        pageDTO.setTotal(page.getTotal());
        pageDTO.setRows(getParkingLotDTOList);

        return pageDTO;
    }

    //TODO 新增了小区id的字段
    @Override
    public void insertParkingLot(InsertParkingLotDTO insertParkingLotDTO) {
        ParkingArea parkingArea = msParkingAreaMapper.insertParkingLotDtoTOgetBusinessParkingArea(insertParkingLotDTO);
        String value=insertParkingLotDTO.getOut_num();  //停车场外部编码
        parkingArea.setPaId(String.valueOf(IdWorker.getId()));
        parkingArea.setBId(String.valueOf(IdWorker.getId()));
        parkingArea.setCommunityId(insertParkingLotDTO.getCommunityId());
        parkingArea.setNum(insertParkingLotDTO.getNum());
        parkingArea.setTypeCd(insertParkingLotDTO.getType());
        parkingAreaMapper.insert(parkingArea);

        ParkingAreaAttr parkingAreaAttr=new ParkingAreaAttr();
        parkingAreaAttr.setPaId(parkingArea.getPaId());
        parkingAreaAttr.setCommunityId(parkingArea.getCommunityId());
        parkingAreaAttr.setPaId(parkingArea.getPaId());
        parkingAreaAttr.setAttrId(String.valueOf(IdWorker.getId()));
        parkingAreaAttr.setSpecCd("6185-17861");
        parkingAreaAttr.setValue(insertParkingLotDTO.getOut_num());
        parkingAreaAttrMapper.insert(parkingAreaAttr);

    }

    //TODO 新增加了id的字段 需要通知给前端
    @Override
    public void updateParkingLot(UpdateParkingLotDTO updateParkingLotDTO) {
        ParkingArea parkingArea = msParkingAreaMapper.updateParkingLotDtoTOBusinessParkingArea(updateParkingLotDTO);
        QueryWrapper<ParkingArea> queryWrapper=new QueryWrapper<>();
        queryWrapper.eq("pa_id",parkingArea.getPaId());
        parkingAreaMapper.update(parkingArea,queryWrapper);

        //获得停车场外部编码
        String value=updateParkingLotDTO.getOut_num();
        ParkingAreaAttr parkingAreaAttr=new ParkingAreaAttr();
        parkingAreaAttr.setValue(value);
        QueryWrapper<ParkingAreaAttr> queryWrapperAttr=new QueryWrapper<>();
        queryWrapperAttr.eq("pa_id",parkingArea.getPaId());
        parkingAreaAttrMapper.update(parkingAreaAttr,queryWrapperAttr);

    }
}



