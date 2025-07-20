package com.zeroone.star.orgmanager.controller;

import com.zeroone.star.orgmanager.service.ShiftSettingService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.orgmanager.AddShiftSettingDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ClassManagerDTO;
import com.zeroone.star.project.dto.j4.orgmanager.ShiftSettingDTO;
import com.zeroone.star.project.j4.orgmanager.ShiftSettingApis;
import com.zeroone.star.project.query.j4.orgmanager.ShiftSettingQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.orgmanager.ClassManagerVO;
import com.zeroone.star.project.vo.j4.orgmanager.ShiftSettingVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.web.bind.annotation.*;
import javax.annotation.Resource;
import java.util.List;
import java.util.Set;
import java.util.concurrent.TimeUnit;

/**
 * @Author: dashuai
 * @Description: 班次设置接口
 */
@RestController
@RequestMapping("/j4-orgmanager/shiftSetting")
@Api(tags = "班次设置接口")
public class ShiftSettingController implements ShiftSettingApis {
    String userId;

    @Resource
    private UserHolder userHolder;

    @Autowired
    private ShiftSettingService sss;

    @Autowired
    private RedisTemplate redisTemplate;

    @Resource
    ShiftSettingService shiftSettingService;

    /**
     * 获取当前登录用户的id
     */
    private String getLoginUserId(){
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            if (currentUser != null && currentUser.getId() != null) {
                userId = String.valueOf(currentUser.getId());
            }else{
                throw new RuntimeException("无法获取当前用户ID");
            }
        } catch (Exception e) {
            throw new RuntimeException("获取用户信息失败", e);
        }
        return userId;
    }

    @ApiOperation(value = "获取班次名称列表")
    @GetMapping("/listShiftSettingName")
    @Override
    public JsonVO<List<ShiftSettingDTO>> listShiftSettingName() {
        //构造redis中的key，规则：classes_name_登录用户Id
        String key = "classes_name_" + getLoginUserId();

        //查询redis中是否存在班次名称列表数据
        List<ShiftSettingDTO> r_list= (List<ShiftSettingDTO>)redisTemplate.opsForValue().get(key);
        //若存在直接返回，无需查询数据库
        if(r_list!=null){
            return JsonVO.success(r_list);
        }
        //若不存在，查询数据库，将查到的数据放入redis中
        List<ShiftSettingDTO> list = sss.listClassName();
        if (list==null){
            return JsonVO.fail(null);
        }
        redisTemplate.opsForValue().set(key,list,12, TimeUnit.HOURS);
        return JsonVO.success(list);
    }

    @ApiOperation(value = "获取班次列表（条件+分页）")
    @GetMapping("/listShiftSetting")
    @Override
    public JsonVO<PageDTO<ShiftSettingVO>> listShiftSetting(ShiftSettingQuery query) {
        // 构造 Redis 缓存键（区分有无名称查询）
        String key = "classes_" + getLoginUserId() +
                (query.getName() != null ? "_name_" + query.getName() : "");
        // 缓存读取
        PageDTO<ShiftSettingVO> cachedResult = (PageDTO<ShiftSettingVO>) redisTemplate.opsForValue().get(key);
        if (cachedResult != null && !cachedResult.getRows().isEmpty()) {
            return JsonVO.success(cachedResult);
        }
        // 没缓存，则查询数据库
        PageDTO<ShiftSettingVO> dbResult = sss.listClass(query);
        if (dbResult == null) {
            return JsonVO.fail(null);
        }
        // 将查询结果写入缓存（设置过期时间 1 小时）
        redisTemplate.opsForValue().set(key, dbResult, 12, TimeUnit.HOURS);
        return JsonVO.success(dbResult);
    }

    @ApiOperation(value = "添加班次信息")
    @PostMapping("/addShiftSetting")
    @Override
    public JsonVO<String> addShiftSetting(@RequestBody AddShiftSettingDTO addShiftSettingDTO) {
        String r = sss.addShiftSetting(addShiftSettingDTO);
        if (r.equals("ok")){
            String key = "classes_"+getLoginUserId();
            String key2 = "classes_name_"+getLoginUserId();
            Set keys = redisTemplate.keys(key);
            Set keys2 = redisTemplate.keys(key2);
            redisTemplate.delete(keys);
            redisTemplate.delete(keys2);
            return JsonVO.success("添加成功!");
        }else
            return JsonVO.fail("添加有误");

    }

    @ApiOperation(value = "班次信息回显")
    @GetMapping("/{classId}")
    @Override
    public JsonVO<ClassManagerVO> queryByClassId(@PathVariable String classId) {
        ClassManagerVO classManagerVO = shiftSettingService.getByClassId(classId);
        return JsonVO.success(classManagerVO);
    }

    @ApiOperation(value = "修改班次信息")
    @PutMapping("/class")
    @Override
    public JsonVO<String> modifyClass(@RequestBody ClassManagerDTO classManagerDTO) {
        if(shiftSettingService.updateClasses(classManagerDTO)) return JsonVO.success("success");
        return JsonVO.fail("修改班次信息失败");
    }

    @ApiOperation(value = "删除班次")
    @DeleteMapping("/{classId}")
    @Override
    public JsonVO<String> removeByClassId(@PathVariable String classId) {
        if(shiftSettingService.removeByClassId(classId)) return JsonVO.success("success");;
        return JsonVO.fail("删除班次信息失败");
    }

    @ApiOperation("修改班次状态")
    @PutMapping("/{classId}")
    @Override
    public JsonVO<String> modifyClassStatus(@PathVariable String classId) {
        if(shiftSettingService.updateClassesStatus(classId)) return JsonVO.success("success");
        return JsonVO.fail("修改班次状态失败");
    }
}
