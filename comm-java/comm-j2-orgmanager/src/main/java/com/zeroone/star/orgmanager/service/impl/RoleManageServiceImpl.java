package com.zeroone.star.orgmanager.service.impl;



import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.orgmanager.entity.PPrivilegeGroup;
import com.zeroone.star.orgmanager.entity.SStore;
import com.zeroone.star.orgmanager.mapper.PPrivilegeGroupMapper;
import com.zeroone.star.orgmanager.mapper.SStoreMapper;
import com.zeroone.star.orgmanager.service.RoleManageService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleAddDTO;
import com.zeroone.star.project.dto.j2.orgmanager.rolemanage.RoleDTO;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author SETTRA
 * @since 2025-05-30
 */
@Service
public class RoleManageServiceImpl extends ServiceImpl<PPrivilegeGroupMapper, PPrivilegeGroup> implements RoleManageService {

    @Resource
    MsRoleManageMapper ms;


    @Resource
    SStoreMapper sStoreMapper;

    @Resource
    private PPrivilegeGroupMapper pPrivilegeGroupMapper;

    @Resource
    private UserHolder userHolder;

    @Override
    public List<RoleDTO> listAllRoles() {
        try {
            UserDTO userDTO = userHolder.getCurrentUser();
            String storeId = userDTO.getStoreIds().get(0);
            List<RoleDTO> result = new ArrayList<>();
            //构建查询条件
            QueryWrapper<PPrivilegeGroup> wrapper = new QueryWrapper<>();
            wrapper.eq("store_id",storeId);
            wrapper.orderByAsc("seq");
            wrapper.orderByAsc("pg_id");
            //执行查询
            List<PPrivilegeGroup> list = pPrivilegeGroupMapper.selectList(wrapper);
            //获取管理员角色数据实体
            for(PPrivilegeGroup roleGroup : list){
                RoleDTO dto = new RoleDTO();
                dto.setPg_id(roleGroup.getPgId());
                dto.setName(roleGroup.getName());
                dto.setSeq(roleGroup.getSeq());
                dto.setDescription(roleGroup.getDescription());
                if(roleGroup.getStatusCd().equals("0")) result.add(dto);
            }
            return result;
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException("获取角色列表失败: " + e.getMessage(), e);
        }
    }

    @Override
    public String saveRole(RoleAddDTO roleAddDTO) {
        try {
            UserDTO userDTO = userHolder.getCurrentUser();
            String storeId = userDTO.getStoreIds().get(0);
            PPrivilegeGroup newRole = new PPrivilegeGroup();
            newRole.setName(roleAddDTO.getName());
            newRole.setSeq(roleAddDTO.getSeq());
            newRole.setDescription(roleAddDTO.getDescription());
            newRole.setStatusCd("0");
            //执行查询，查出s_store表中store_id是“当前登录管理员”的那条数据
            SStore sStore = sStoreMapper.selectById(storeId);
            if(sStore != null) {
                newRole.setStoreId(storeId);
                newRole.setDomain(sStore.getStoreTypeCd());
                if(sStore.getStoreTypeCd().equals("800900000000")){
                    newRole.setRoleType("SYSTEM");
                }else{
                    newRole.setRoleType("USER");
                }
            }
            int result = pPrivilegeGroupMapper.insert(newRole);
            //0表示新增成功，1表示新增失败
            if(result>0) return "0";
            else return "1";
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public String updateRole(RoleDTO roleDTO) {
        UpdateWrapper<PPrivilegeGroup> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("pg_id",roleDTO.getPg_id())
                .set(!StringUtils.isEmpty(roleDTO.getName()),"name",roleDTO.getName())
                .set(!StringUtils.isEmpty(roleDTO.getSeq()),"seq",roleDTO.getSeq())
                .set(!StringUtils.isEmpty(roleDTO.getDescription()),"description",roleDTO.getDescription());
        int update = pPrivilegeGroupMapper.update(null,updateWrapper);
        //0表示更新成功
        if(update>0) return "0";
            //1表示更新失败
        else return "1";
    }

    @Override
    public String deleteRole(String pg_id) {
        //int delete = pPrivilegeGroupMapper.deleteById(pg_id);
        //该业务中删除不是直接删除那条数据，而是把状态码从0改为1
        UpdateWrapper<PPrivilegeGroup> deleteWrapper = new UpdateWrapper<>();
        deleteWrapper.eq("pg_id",pg_id).set("status_cd","1");
        int delete = pPrivilegeGroupMapper.update(null,deleteWrapper);
        //0表示成功删除，1表示删除失败
        if(delete>0) return "0";
        else return "1";
    }


}
