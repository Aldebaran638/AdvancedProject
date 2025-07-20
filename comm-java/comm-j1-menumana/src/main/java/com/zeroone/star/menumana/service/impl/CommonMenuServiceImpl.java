package com.zeroone.star.menumana.service.impl;

import cn.hutool.core.lang.Snowflake;
import cn.hutool.core.util.IdUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.menumana.entity.EasyMenu;
import com.zeroone.star.menumana.entity.UserMenu;
import com.zeroone.star.menumana.mapper.ICommonMenuMapper;
import com.zeroone.star.menumana.mapper.MsCommonMenuMapper;
import com.zeroone.star.menumana.service.ICommonMenuService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.AddCommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.CommonMenuDTO;
import com.zeroone.star.project.dto.j1.menumana.commonmenu.MixMenuDTO;
import com.zeroone.star.project.query.j1.menumana.commonmenu.CommonMenuQuery;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import lombok.SneakyThrows;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestBody;

import javax.annotation.Resource;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Random;
import java.util.concurrent.atomic.AtomicInteger;

@Service
public class CommonMenuServiceImpl extends ServiceImpl<ICommonMenuMapper, UserMenu>implements ICommonMenuService {

    @Resource
    MsCommonMenuMapper ms;

    @Resource
    ICommonMenuMapper iCommonMenuMapper;

    @Resource
    UserHolder userHolder;


    @SneakyThrows
    @Override
    public PageDTO<CommonMenuDTO> listAllCommonMenu(CommonMenuQuery query)  {
        Page<UserMenu> page = new Page<>(query.getPageIndex(),query.getPageSize());
        UserDTO currentUser = userHolder.getCurrentUser();
        String staffId = currentUser.getId();
        QueryWrapper<UserMenu> wrapper = new QueryWrapper<>();
        wrapper.eq("staff_id",staffId);
        wrapper.orderBy(true,true,"seq");
        wrapper.orderBy(true,true,"create_time");
        Page<UserMenu> pageResult = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(pageResult,src -> ms.commonMenuToDto(src));
    }

    @SneakyThrows
    @Override
    public List<MixMenuDTO> listMixMenu() {
        UserDTO currentUser = userHolder.getCurrentUser();
        String userId = currentUser.getId();
        List<String> urls = iCommonMenuMapper.pIdSelectUrl(userId);
        String url1 = urls.get(0);
        String[] split = url1.split("/");
        String url = split[2];
        List<EasyMenu> newEasy = iCommonMenuMapper.selectByUrl(url);
        List<MixMenuDTO> mixNameList = new ArrayList<>();
        for (EasyMenu easyMenu:newEasy){
            String gId = easyMenu.getGId();
            String groupName = iCommonMenuMapper.selectGroupName(gId);
            String mixName = groupName+"-"+easyMenu.getName();
            MixMenuDTO mixMenuDTO = new MixMenuDTO();
            mixMenuDTO.setMixName(mixName);
            mixMenuDTO.setMid(easyMenu.getMId());
            mixNameList.add(mixMenuDTO);
        }
        return mixNameList;
    }

    @SneakyThrows
    @Override
    public String addMenu(@RequestBody AddCommonMenuDTO addCommonMenuDTO) {
        UserDTO currentUser = userHolder.getCurrentUser();
        String userId = currentUser.getId();
        String mId = addCommonMenuDTO.getMid();

        String prefix = "10";
        // 2. 获取当前日期（格式：yyyyMMdd）
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyyMMdd");
        String datePart = dateFormat.format(new Date());
        // 3. 生成8位随机数（范围：00000000 ~ 99999999）
        Random random = new Random();
        int randomNum = random.nextInt(100000000); // 0 ~ 99999999
        String randomPart = String.format("%08d", randomNum); // 补零至8位
        // 4. 拼接最终ID
        String muId = prefix + datePart + randomPart;

        String name = iCommonMenuMapper.selectName(mId);
        String url = iCommonMenuMapper.selectUrl(mId);
        UserMenu userMenu = new UserMenu();
        userMenu.setMuId(muId);
        userMenu.setMId(mId);
        userMenu.setStaffId(userId);
        userMenu.setName(name);
        userMenu.setIcon(addCommonMenuDTO.getIcon());
        userMenu.setUrl(url);
        userMenu.setSeq(addCommonMenuDTO.getSeq());
        int insert = baseMapper.insert(userMenu);
        if (insert>0){
            return "添加成功";
        }else {
            return "添加失败";
        }
    }

    //根据id修改显示状态码
    @Override
    public String updateMuId(String muId) {
        UpdateWrapper<UserMenu> wrapper = new UpdateWrapper<>();
        wrapper.eq("mu_id",muId);
        UserMenu menu = new UserMenu();
        menu.setStatusCd("1");
        int status = baseMapper.update(menu, wrapper);
        if (status>0){
            return "操作成功！";
        }else {
            return "操作失败！";
        }
    }


}
