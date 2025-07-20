package com.zeroone.star.communitymanage.service.property.impl;
import cn.hutool.core.lang.Snowflake;
import cn.hutool.core.util.IdUtil;
import com.zeroone.star.communitymanage.entity.property.BusinessPropertyRightRegistration;
import com.zeroone.star.communitymanage.entity.property.BusinessPropertyRightRegistrationDetail;
import com.zeroone.star.communitymanage.entity.property.PropertyRightRegistration;
import com.zeroone.star.communitymanage.entity.property.PropertyRightRegistrationDetail;
import com.zeroone.star.communitymanage.service.property.IPropertyUpdateService;
import com.zeroone.star.project.dto.j5.community.property.AddPropertyDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyCheckDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyDTO;
import com.zeroone.star.project.dto.j5.community.property.PropertyDetailDTO;
import com.zeroone.star.communitymanage.mapper.property.PropertyDetailQueryMapper;
import com.zeroone.star.communitymanage.mapper.property.PropertyUpdateMapper;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author Jungle
 * @version 1.0.0
 */
@Slf4j
@Service
public class PropertyUpdateServiceImpl  implements IPropertyUpdateService {

    @Resource
    PropertyDetailQueryMapper propertyDetailQueryMapper;

    @Resource
    PropertyUpdateMapper propertyUpdateMapper;

    @Resource
    MsPropertyMapper ms;

    // 创建雪花算法生成器（指定机器ID和数据中心ID）
    private final Snowflake snowflake = IdUtil.createSnowflake(1, 1);

    /**
     * 添加产权登记
     */
    // 添加事务注解，指定回滚条件
    @Transactional(rollbackFor = Exception.class)
    @Override
    public String saveProperty(AddPropertyDTO addDto)
    {
        try {

            PropertyRightRegistration prr =ms.addPropertyDtoToPrr(addDto);
            PropertyRightRegistrationDetail prrd=ms.addPropertyDtoToPrrd(addDto);
            BusinessPropertyRightRegistration bprr=ms.addPropertyDtoToBprr(addDto);
            BusinessPropertyRightRegistrationDetail bprrd=ms.addPropertyDtoToBprrd(addDto);


            String floorId=propertyUpdateMapper.selectFloorId(addDto.getFloorName(),addDto.getCommunityId());
            String unitId=propertyUpdateMapper.selectUnitId(floorId,addDto.getUnitNum());
            prr.setRoomId(propertyUpdateMapper.selectRoomId(addDto.getRoomNum(),unitId));


            // TODO 创建人参数设为默认值,之后需要修改
            prr.setCreateUser("111");
            prrd.setCreateUser("111");
            bprr.setCreateUser("111");
            bprrd.setCreateUser("111");
            //TODO 数据库表没有自增策略,实体类添加自增策略无效,控制层手动添加了自增策略
            String Id=String.valueOf(snowflake.nextId());
            prr.setPrrId(Id);
            prr.setState("0");
            prr.setStatusCd("0");

            String bId=String.valueOf(snowflake.nextId());
            prrd.setPrrdId(bId);
            prrd.setPrrId(prr.getPrrId());
            prrd.setStatusCd("0");

            bprr.setBId(bId);
            bprr.setCreateUser("111");
            bprr.setPrrId(prr.getPrrId());
            bprr.setStatusCd("0");
            bprr.setOperate("ADD");
            bprr.setState("0");
            bprr.setRoomId(propertyUpdateMapper.selectRoomId(addDto.getRoomNum(),unitId));

            bprrd.setPrrdId(prrd.getPrrdId());
            bprrd.setPrrId(prr.getPrrId());
            bprrd.setOperate("ADD");
            bprrd.setFundIsPaid(addDto.getFundIsPaid());
            bprrd.setTaxIsPaid(addDto.getTaxIsPaid());

/*            String saveWay="ftp";

            frontIdCard.setBId(bId);
            frontIdCard.setFileRelId(String.valueOf(snowflake.nextId()));
            frontIdCard.setSaveWay(saveWay);
            frontIdCard.setFileRealName(addDto.getFrontIdCardImage().getOriginalFilename());
            frontIdCard.setFileSaveName(addDto.getFrontIdCardImage().getName());
            frontIdCard.setRelTypeCd("10000");
            frontIdCard.setObjId(addDto.getObjId());
            propertyUpdateMapper.insertFileRel(frontIdCard);*/

/*            backIdCard.setBId(bId);
            backIdCard.setFileRelId(String.valueOf(snowflake.nextId()));
            backIdCard.setFileRealName(addDto.getBackIdCardImage().getOriginalFilename());
            backIdCard.setFileSaveName(addDto.getBackIdCardImage().getName());
            backIdCard.setSaveWay(saveWay);
            backIdCard.setRelTypeCd("10000");
            backIdCard.setObjId(addDto.getObjId());
            propertyUpdateMapper.insertFileRel(backIdCard);*/




            //首先插入产权登记表
            propertyUpdateMapper.insertPrr(prr);
            //再插入登记详情表
            propertyUpdateMapper.insertPrrd(prrd);
            //再插入业务表
            propertyUpdateMapper.insertBPrr(bprr);
            //再插入业务详情表
            propertyUpdateMapper.insertBPrrd(bprrd);
            //再插入关联文件表

            //propertyUpdateMapper.insertFileRel(frontIdCard);
            return Id;
        }
        catch (Exception e)
        {
            log.info(String.valueOf(e));
            throw new RuntimeException("保存产权登记信息失败,传递的数据与数据库不匹配", e);
        }

    }



    /**
     * 删除产权
     */
    @Transactional(rollbackFor = Exception.class)
    @Override
    public String remove(String prrId) {
        //如果不存在则返回false
        if (propertyDetailQueryMapper.countById(prrId)==0) return "该Id不存在";
        //否则执行删除操作
        //获取业务产权和详情数据
        BusinessPropertyRightRegistration bprr=propertyUpdateMapper.selectBprr(prrId);
        BusinessPropertyRightRegistrationDetail bprrd= propertyUpdateMapper.selectBprrd(prrId);

        String bId=String.valueOf(snowflake.nextId());
        bprr.setBId(bId);
        bprr.setOperate("DEL");
        bprr.setStatusCd("1");

        bprrd.setOperate("DEL");

        //首先获得bId
        try {

            propertyUpdateMapper.deletePrrByprrId(prrId);
            propertyUpdateMapper.deletePrrdByprrId(prrId);
            propertyUpdateMapper.insertBPrr(bprr);
            propertyUpdateMapper.insertBPrrd(bprrd);
            //propertyUpdateMapper.insertFileRel();
            return null;
        }
        catch (Exception e)
        {
            return "数据库该id有多条数据,请检查数据库数据";
        }

    }



    /**
     * 修改产权登记
     */
    @Override
    @Transactional(rollbackFor = Exception.class)
    public String updateProperty(PropertyDTO propertyDTO) {
        if (propertyDetailQueryMapper.countById(propertyDTO.getPrrId())==0) return "该Id不存在";
        PropertyRightRegistration prr = ms.dtoToPrr(propertyDTO);

        String floorId=propertyUpdateMapper.selectFloorId(propertyDTO.getFloorName(),propertyDTO.getCommunityId());
        String unitId=propertyUpdateMapper.selectUnitId(floorId,propertyDTO.getUnitNum());
        String roomId=propertyUpdateMapper.selectRoomId(propertyDTO.getRoomNum(),unitId);

        try {
            propertyUpdateMapper.updatePrr(prr,roomId);
            return null;
        } catch (Exception e) {
            log.info(String.valueOf(e));
            return "传输数据存在问题";
        }
    }

    /**
     * 审核产权
     */
    @Transactional(rollbackFor = Exception.class)
    @Override
    public String checkPrr(PropertyCheckDTO checkDTO) {

        //如果id不存在,则返回错误
        if (propertyDetailQueryMapper.countById(checkDTO.getPrrId())==0) return "id不存在";
        //存在,则进行审核,把prr和bprr表审核状态设置为1
        try
        {
            checkDTO.setRemark(checkDTO.getRemark() + " ");
            if (propertyUpdateMapper.checkPrr(checkDTO.getPrrId(), checkDTO.getState(), checkDTO.getRemark())==0) return "prrId和roomId不匹配";
            return null;
        }
        catch (Exception e)
        {
            log.error(String.valueOf(e));
            throw e;
        }

    }



    /**
     * 修改附件项
     */
    @Transactional(rollbackFor = Exception.class)
    @Override
    public String  updatePrrd(PropertyDetailDTO propertyDetailDTO)
    {
        PropertyRightRegistrationDetail prrd = ms.PrrddtoToDo(propertyDetailDTO);
        prrd.setIsTrue(propertyDetailDTO.getIsTrue());
        int result = propertyUpdateMapper.updateprrd(prrd);
        if (result == 1) return null;
        else return "未修改,数据传输错误";

    }
}
