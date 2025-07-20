package com.zeroone.star.configmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.configmanager.entity.TDict;
import com.zeroone.star.configmanager.entity.TDictSpec;
import com.zeroone.star.configmanager.mapper.TDictMapper;
import com.zeroone.star.configmanager.mapper.TDictSpecMapper;
import com.zeroone.star.configmanager.service.ITDictService;
import com.zeroone.star.project.dto.PageDTO;

import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.*;
import com.zeroone.star.project.query.j2.configmanager.sys.dictionary.DictionaryQuery;
import com.zeroone.star.project.query.j2.configmanager.sys.dictionary.TDictQuery;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

@Service
public class TDictServiceImpl
        extends ServiceImpl<TDictMapper, TDict>
        implements ITDictService
{
    @Resource
    private TDictMapper tDictMapper;

    @Resource
    private TDictSpecMapper tDictSpecMapper;

    @Override
    public PageDTO<AddTDictResDTO> listAll(TDictQuery query) {
        Page<TDict> page = new Page<>(query.getPageIndex(), query.getPageSize());
        List<AddTDictResDTO> dtoList = tDictMapper.selectWithSpecId(
                query.getSpecId(),
                query.getName(),
                query.getStatusCd()
        );

        List<AddTDictResDTO> dtoResList = tDictMapper.selectWithSpecId(
                query.getSpecId(),
                query.getName(),
                query.getStatusCd()
        );

        // 构造分页结果
        Page<AddTDictResDTO> dtoPage = new Page<>();
        dtoPage.setSize(page.getSize());
        dtoPage.setCurrent(page.getCurrent());
        dtoPage.setTotal(dtoList.size());
        dtoPage.setRecords(dtoList);

        return PageDTO.create(dtoPage, item -> item);
    }

    @Override
    public PageDTO<AddDictionaryDTO> listByConditions(DictionaryQuery condition) {
        Page<TDict> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        QueryWrapper<TDict> wrapper = new QueryWrapper<>();

        //配置固定条件
        wrapper.eq("table_columns", "rel_cd");
        wrapper.eq("table_name", "u_org_staff_rel");

        //可选条件1:name不为空时添加
        if (condition.getName() != null && !condition.getName().isEmpty()) {
            wrapper.eq("name", condition.getName());
        }

        Page<TDict> resultPage = tDictMapper.selectPage(page, wrapper);
        return PageDTO.create(resultPage, AddDictionaryDTO.class);
    }

    //添加字典
    @Override
    @Transactional(rollbackFor = Exception.class)
    public ResultStatus addTDict(AddTDictDTO dto) {
        try {
            List<String> specIds=getAllSpecIds();

            //检查输入的specId值是否合法
            String testId=dto.getSpecId();
            boolean flag = false;
            for (String specId : specIds) {
                if(specId.equals(testId)){
                    flag=true;
                    break;
                }
            }
            if(!flag) return ResultStatus.FAIL;

            // 1. 根据 specId 查询 t_dict_spec 获取 tableName 和 tableColumns
            TDictSpec spec = tDictSpecMapper.selectBySpecId(testId);

            // 2. 构造 TDict 实体
            TDict tDict = new TDict();
            tDict.setStatusCd(dto.getStatusCd());
            tDict.setName(dto.getName());
            tDict.setDescription(dto.getDescription());

            tDict.setCreateTime(LocalDateTime.now());

            tDict.setTableName(spec.getTableName());
            tDict.setTableColumns(spec.getTableColumns());

            int rows=tDictMapper.insert(tDict);
            return rows > 0 ? ResultStatus.SUCCESS : ResultStatus.FAIL;
        } catch (Exception e) {
            e.printStackTrace();
            return ResultStatus.SERVER_ERROR;
        }
    }

    //修改字典
    @Override
    public ResultStatus modifyTDict(ModifyTDictDTO dto) {
        try {
            TDict tDict = tDictMapper.selectById(dto.getId());
            if (tDict == null) {
                System.out.println("字典不存在或表名无效");
                return ResultStatus.FAIL;
            }
            TDictSpec spec =tDictSpecMapper.selectBySpecId(dto.getSpecId());
            tDict.setName(dto.getName());
            tDict.setTableName(spec.getTableName());
            tDict.setTableColumns(spec.getTableColumns());
            tDict.setStatusCd(dto.getStatusCd());
            tDict.setDescription(dto.getDescription());
            tDict.setCreateTime(LocalDateTime.now());

            int rows = tDictMapper.updateById(tDict);
            return rows>0? ResultStatus.SUCCESS : ResultStatus.FAIL;
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }

    //仅用于获取t_dict_spec表中的所有spec_name字段
    @Override
    public List<String> getAllSpecNames() {
        return tDictSpecMapper.getAllSpecNames();
    }

    //仅用于获取t_dict_spec表中的所有spec_id字段
    @Override
    public List<String> getAllSpecIds() {
        return tDictSpecMapper.getAllSpecIds();
    }

    //仅用于检查 table_name 是否存在于 t_dict_spec
    private boolean isTableNameValid(String tableName) {
        if (tableName == null || tableName.isEmpty()) {
            return false;
        }
        return tDictSpecMapper.existsByTableName(tableName);
    }


}
