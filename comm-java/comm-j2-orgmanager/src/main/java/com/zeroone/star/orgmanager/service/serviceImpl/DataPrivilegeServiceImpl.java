package com.zeroone.star.orgmanager.service.serviceImpl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.DataPrivilege;
import com.zeroone.star.orgmanager.mapper.DataPrivilegeMapper;
import com.zeroone.star.orgmanager.service.IDataPrivilegeService;
import com.zeroone.star.project.dto.j2.orgmanager.dataPrivilege.DataPrivilegeDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author hubery
 * @since 2025-05-19
 */
@Service
public class DataPrivilegeServiceImpl extends ServiceImpl<DataPrivilegeMapper, DataPrivilege> implements IDataPrivilegeService {

    @Autowired
    private DataPrivilegeMapper mapper;
    @Autowired
    private MsDataPrivilegeMapper ms;

    @Override
    public List<DataPrivilegeDTO> listAll(String communityId) {

        QueryWrapper<DataPrivilege> wrapper = new QueryWrapper<>();
        wrapper.eq("community_id", communityId);
        wrapper.eq("status_cd","0");
        List<DataPrivilege> dataPrivileges = mapper.selectList(wrapper);

        List<DataPrivilegeDTO> result = new ArrayList<>();
        for (DataPrivilege dataPrivilege : dataPrivileges) {
            result.add(ms.doToDto(dataPrivilege));
        }

        return result;
    }
}
