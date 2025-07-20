package com.zeroone.star.patrolmgt.controller;

import com.zeroone.star.patrolmgt.service.IInspectionItemService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.item.ItemApis;
import com.zeroone.star.project.j8.patrolmgt.item.query.ItemQuery;
import com.zeroone.star.project.j8.patrolmgt.item.vo.ItemVO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import com.alibaba.cloud.commons.lang.StringUtils;
import com.zeroone.star.patrolmgt.service.ItemService;
import com.zeroone.star.project.j8.patrolmgt.item.ItemApis;
import com.zeroone.star.project.j8.patrolmgt.item.dto.AddItemDTO;
import com.zeroone.star.project.j8.patrolmgt.item.dto.ItemDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import javax.annotation.Resource;

/**
 * <p>
 * 描述: 巡检项目控制器
 * </p>
 * @author  1-panzhire,2-renyifei
 * @version 1.0.0
 */
@RestController
@RequestMapping("j8-patrolmgt/item")
@Api(tags = "巡检项目")
public class ItemController implements ItemApis {

    @Resource
    IInspectionItemService service;
    
    @Override
    @GetMapping("/query-item-name-list")
    @ApiOperation(value = "获取巡检项目名称列表")
    @ApiImplicitParam(name = "communityId", value = "小区编号", required = true, dataType = "String", paramType = "query")
    public JsonVO<PageDTO<ItemVO>> listItem(@RequestParam String communityId) {
        return JsonVO.success(service.listItem(communityId));
    }

    @Override
    @GetMapping("/query-item-list")
    @ApiOperation(value = "获取巡检项目列表（条件＋分页）")
    public JsonVO<PageDTO<ItemVO>> queryItemList(ItemQuery query) {
        return JsonVO.success(service.queryItemList(query));
    }

    @Resource
    private ItemService itemService;
    /**
     * 添加巡检项目
     * @param addItemDTO
     * @return
     */
    @PostMapping("/add-item")
    @ApiOperation("添加巡检项目")
    @Override
    public JsonVO<String> addItem(@RequestBody AddItemDTO addItemDTO) {
        // 检验传输对象是否为空
        if(addItemDTO==null){
            return JsonVO.fail("添加对象不能为空");
        }
        if(isNullOrEmpty(addItemDTO.getCommunityId()) || isNullOrEmpty(addItemDTO.getItemName())
                || isNullOrEmpty(addItemDTO.getRemark())){
            return JsonVO.fail("添加对象时属性不能为null或者是空字符串");
        }
        return itemService.saveItem(addItemDTO);
    }

    /**
     * 修改巡检项目
     * @param itemDTO
     * @return
     */
    @PutMapping("/modify-item")
    @ApiOperation("修改巡检项目")
    @Override
    public JsonVO<String> modifyItem(@RequestBody ItemDTO itemDTO) {
        if(itemDTO==null){
            return JsonVO.fail("修改对象不能为空");
        }
        if(isNullOrEmpty(itemDTO.getCommunityId()) || isNullOrEmpty(itemDTO.getItemName())
                || isNullOrEmpty(itemDTO.getRemark())|| isNullOrEmpty(itemDTO.getItemId())){
            return JsonVO.fail("添加对象时属性不能为null或者是空字符串");
        }
        return itemService.updateItem(itemDTO);
    }

    /**
     * 删除巡检项目
     * @param itemId
     * @return
     */
    @DeleteMapping(value="/remove-item/{itemId}")
    @ApiOperation("删除巡检项目")
    @ApiImplicitParam(name="itemId",value="巡检项目的主键id",required=true,example="102022050608420018")
    @Override
    public JsonVO<String> removeItem(@PathVariable("itemId")String itemId) {
        if(StringUtils.isBlank(itemId)){
            return JsonVO.fail("没有传输正确的值");
        }
        return itemService.removeItem(itemId);
    }

    /**
     * 判断前端传来的数据是否是null或者空字符串
     * @param str
     * @return
     */
    private boolean isNullOrEmpty(final CharSequence  str){
        return str == null || str.length() == 0;
    }
}
