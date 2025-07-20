package com.zeroone.star.housemgt.controller;

import com.zeroone.star.housemgt.service.CommitteDetailService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.housemgt.committee.query.CommitteeQueryApis;
import com.zeroone.star.project.j8.housemgt.committee.query.CommitteeListQuery;
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeDetailDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.housemgt.service.CommitteeListService;  // 添加导入
import com.zeroone.star.project.j8.housemgt.committee.dto.CommitteeListDTO;  // 添加导入
import io.swagger.annotations.Api;
import org.springframework.beans.factory.annotation.Autowired;  // 添加导入
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;

@RestController
@RequestMapping("j8-housemgt/committee")
@Api(tags = "业委会成员管理")
public class CommitteeQueryController implements CommitteeQueryApis{
    @Autowired
    private CommitteeListService committeeListService;

    @Autowired
    private CommitteDetailService committeDetailService; // 添加这个注入

    /**
     * 查询业委会成员列表
     * @param query 查询数据对象
     * @return 业委会成员列表
     */
    @ApiOperation("获取业委会列表(条件+分页)")
    @GetMapping("/query-list")
    @Override
    public JsonVO<PageDTO<CommitteeListDTO>> queryCommitteeList(@ModelAttribute CommitteeListQuery query){
        try {
            // 调用Service层方法获取DTO分页数据
            PageDTO<CommitteeListDTO> dtoPageData = committeeListService.queryList(query);


            // 返回成功结果
            return JsonVO.success(dtoPageData);
        } catch (Exception e) {
            // 返回错误结果 - 传入null作为data
            return JsonVO.fail(null);
        }
    }


    /**
     * 查询业委会成员详情
     * @param ocId 业委会编号
     * @return 业委会成员详情
     */
    @ApiOperation("获取业委会详情")
    @GetMapping("/query-detail/{ocId}")
    @Override
    public JsonVO<CommitteeDetailDTO> queryCommitteeDetail(@PathVariable("ocId") String ocId){
        try {
            // 调用Service层方法获取详情数据
            CommitteeDetailDTO detailData = committeDetailService.queryDetailById(ocId);

            if (detailData == null) {
                return JsonVO.fail(null);
            }

            // 返回成功结果
            return JsonVO.success(detailData);
        } catch (Exception e) {
            // 返回错误结果
            return JsonVO.fail(null);
        }
    }
}
