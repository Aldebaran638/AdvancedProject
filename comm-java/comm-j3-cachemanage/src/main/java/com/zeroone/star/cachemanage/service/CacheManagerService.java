package com.zeroone.star.cachemanage.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j3.cachemanage.CacheQuery;
import com.zeroone.star.project.vo.j3.cachemanage.CacheVO;

public interface CacheManagerService {

    PageDTO<CacheVO> queryCaches(CacheQuery cacheQuery);

}
