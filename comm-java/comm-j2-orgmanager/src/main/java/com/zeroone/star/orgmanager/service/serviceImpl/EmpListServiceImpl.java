package com.zeroone.star.orgmanager.service.serviceImpl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.PPrivilegeRel;
import com.zeroone.star.orgmanager.entity.UUserDO;
import com.zeroone.star.orgmanager.mapper.EmpListMapper;
import com.zeroone.star.orgmanager.mapper.PPrivilegeRelMapper;
import com.zeroone.star.orgmanager.service.EmpListService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.AddEmpListDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolePermission.EmpListDTO;
import com.zeroone.star.project.query.j2.orgmanager.rolePermission.EmpListQuery;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

/**
 * 实现类
 */
@Service
@Transactional
public class EmpListServiceImpl extends ServiceImpl<EmpListMapper, UUserDO> implements EmpListService {
    @Resource
    private EmpListMapper empListMapper;
    @Resource
    private MSEmpListMapper msEmpListMapper;
    @Resource
    private PPrivilegeRelMapper pPrivilegeRelMapper;

    @Override
    public PageDTO<EmpListDTO> listAllEmp(EmpListQuery query) {
        long pageIndex=query.getPageIndex();
        long pageSize=query.getPageSize();
        Page<UUserDO> page=new Page<>(pageIndex,pageSize);
        //自定义xml
        Page<UUserDO> resultPage = empListMapper.selectByPgId(query, page);
        return PageDTO.create(resultPage, src->msEmpListMapper.uuserToDto(src));
    }

    @Override
    public ResultStatus saveEmpList(AddEmpListDTO addEmpListDTO) {
        // 批量插入新的权限关系
        int count = pPrivilegeRelMapper.InsertPrivilegeRel(addEmpListDTO);
        return count>0?ResultStatus.SUCCESS:ResultStatus.FAIL;
    }

    @Override
    public int removeEmpList(String pId, String pgId) {
        LambdaQueryWrapper<PPrivilegeRel> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(PPrivilegeRel::getPId, pId)
                .eq(PPrivilegeRel::getPgId, pgId);
        // 执行删除
        int result = pPrivilegeRelMapper.delete(wrapper);

        return result;
    }
}
