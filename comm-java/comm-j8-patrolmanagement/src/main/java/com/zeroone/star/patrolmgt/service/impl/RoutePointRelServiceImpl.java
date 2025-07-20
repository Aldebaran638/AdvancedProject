package com.zeroone.star.patrolmgt.service.impl;

import cn.hutool.log.AbstractLog;
import com.zeroone.star.patrolmgt.entity.yuxixia_DO;
import com.zeroone.star.patrolmgt.mapper.RoutePointRelMapper;
import com.zeroone.star.patrolmgt.service.RoutePointRelService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RemoveRoutePointDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.RoutePointRelModifyImagesDTO;
import com.zeroone.star.project.j8.patrolmgt.route.dto.routepointrel.AddRoutePointRelListDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;


/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author 阿伟
 * @since 2025-05-20
 */
@Service
public class RoutePointRelServiceImpl extends ServiceImpl<RoutePointRelMapper, yuxixia_DO> implements RoutePointRelService {

    @Autowired
    private RoutePointRelMapper routePointRelMapper;
    @Override
    public JsonVO<List<String>> addRoutePointRelListService(List<AddRoutePointRelListDTO> addRoutePointRelListAll)
    {
        List <String> resultList=new ArrayList<>();

        // 判断传入的参数是否为空
        if(addRoutePointRelListAll!=null) {

            // 遍历传入的参数
            for (AddRoutePointRelListDTO addRoutePointRel : addRoutePointRelListAll) {
                // 判断数据库中是否存在该条数据

                yuxixia_DO yuxixiaDoRelNext=new yuxixia_DO();
                yuxixiaDoRelNext =routePointRelMapper.selectRoutePoint(addRoutePointRel);
                if(yuxixiaDoRelNext==null){
                String prefix = "51";

                // 获取当前时间
                LocalDateTime now = LocalDateTime.now();
                // 设置时间格式
                DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMddHHmm");
                // 格式化时间
                String dateTimePart = now.format(formatter);

                // 生成随机数
                int randomNum = ThreadLocalRandom.current().nextInt(10000);
                // 格式化随机数
                String randomPart = String.format("%04d", randomNum);
                String result = prefix + dateTimePart + randomPart;
                // 创建yuxixia_DO对象
                yuxixia_DO yuxixiaDO = new yuxixia_DO();
                // 设置inspectionId
                yuxixiaDO.setInspectionId(addRoutePointRel.getInspectionId());
                // 设置inspectionRouteId
                yuxixiaDO.setInspectionRouteId(addRoutePointRel.getInspectionRouteId());
                // 设置communityId
                yuxixiaDO.setCommunityId("2024022643710121");
                // 设置BId
                yuxixiaDO.setBId("-1");
                // 设置irpRelId
                yuxixiaDO.setIrpRelId(result);
                // 设置状态码
                yuxixiaDO.setStatusCd(addRoutePointRel.getStatusCd());
                // 插入
                routePointRelMapper.insertByRoutePointId(yuxixiaDO);
                resultList.add(yuxixiaDO.getInspectionId());
              }else {
                    yuxixia_DO yuxixiaDoRel=new yuxixia_DO();
                    yuxixiaDoRel=routePointRelMapper.selectRoutePoint(addRoutePointRel);
                    yuxixiaDoRel.setStatusCd("0");
                    routePointRelMapper.updateById(yuxixiaDoRel);
                    resultList.add(yuxixiaDoRel.getInspectionId());
                }
           }
            // 返回resultList
            return JsonVO.success(resultList);
        }
        // 返回resultList
        return JsonVO.success(resultList);
    }
    @Override
    public JsonVO<String> modifyRoutePointRelService(RoutePointRelModifyImagesDTO routePointRelModifyImagesDTO) {
        // 调用routePointRelMapper的modifyRoutePoint方法，传入routePointRelModifyImagesDTO参数，
        //修改数据库中对应的数据
        if(routePointRelMapper.modifyRoutePoint(routePointRelModifyImagesDTO))
        // 返回一个JsonVO对象，状态为成功，并返回一个字符串"成功"
        {
            return JsonVO.success("成功");
        }else {
            return JsonVO.fail("数据库当中没能查到对应的数据，数据routeId,RoutePointId有问题");
        }
    }

    @Override
    public JsonVO<String> removeRoutePointRelService(RemoveRoutePointDTO removeInspectionId) {
        // 根据irpRelId查询yuxixia_DO对象
        yuxixia_DO yuxixiaDo=routePointRelMapper.selectRemoveRoutePoint(removeInspectionId);

        // 如果查询结果为空，则返回失败信息
        if(yuxixiaDo==null)return JsonVO.fail("数据库当中没能查到对应的数据，传入的routeId,或者routePoint有问题");
        // 将yuxixiaDo的状态码设置为"1"
        yuxixiaDo.setPointStartTime(null);
        yuxixiaDo.setPointStartTime(null);
        yuxixiaDo.setSortNumber(null);
        yuxixiaDo.setStatusCd("1");
        System.out.println(123);
        // 更新yuxixiaDo对象
        routePointRelMapper.updateById(yuxixiaDo);
        System.out.println(123);
        // 返回成功信息
        return JsonVO.success("成功");
    }
}
