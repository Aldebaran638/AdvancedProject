package com.zeroone.star.project.j3.cachemanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.cachemanage.CacheDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.j3.cachemanage.CacheQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.cachemanage.CacheVO;
import com.zeroone.star.project.vo.j3.cachemanage.CacheVO;
import org.springframework.web.bind.annotation.RequestBody;

/**
 * <p>
 * 缓存管理接口
 * </p>
 */
public interface CacheManageApis {
    /**
     *
     * @param cacheQuery 分页信息+用户输入内容
     * @return 查询缓存的分页结果
     */
    JsonVO<PageDTO<CacheVO>> queryCaches(CacheQuery cacheQuery);
    /**
     *
     * @param cacheDto 属性：缓存类别和用户ID
     * @return JsonVo 刷新的信息
     */
    JsonVO flushCache(@RequestBody CacheDTO cacheDto);
}
