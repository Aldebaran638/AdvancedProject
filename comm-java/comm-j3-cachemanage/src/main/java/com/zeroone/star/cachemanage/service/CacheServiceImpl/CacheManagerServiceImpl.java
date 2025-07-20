package com.zeroone.star.cachemanage.service.CacheServiceImpl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.cachemanage.entity.CCacheDO;
import com.zeroone.star.cachemanage.mapper.CacheManagerMapper;
import com.zeroone.star.cachemanage.service.CacheManagerService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j3.cachemanage.CacheQuery;
import com.zeroone.star.project.vo.j3.cachemanage.CacheVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class CacheManagerServiceImpl implements CacheManagerService {
    @Autowired
    private CacheManagerMapper cacheManagerMapper;
    @Override
    public PageDTO<CacheVO> queryCaches(CacheQuery cacheQuery) {
        long pageSize=cacheQuery.getPageSize();
        long pageIndex=cacheQuery.getPageIndex();
        //获取参数
        Page<CCacheDO> page=new Page<>(pageIndex,pageSize);
        Page<CCacheDO> CCacheDOPage=cacheManagerMapper.selectAllCaches(page,cacheQuery);
        return PageDTO.create(CCacheDOPage,CacheVO.class);//把DO转换成VO


    }
}
