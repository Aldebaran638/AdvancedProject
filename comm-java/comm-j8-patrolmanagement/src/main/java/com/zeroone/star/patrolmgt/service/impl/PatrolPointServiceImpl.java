package com.zeroone.star.patrolmgt.service.impl; // 请根据你的实际包结构调整

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.patrolmgt.entity.InspectionItem;
import com.zeroone.star.patrolmgt.entity.Susu_InspectionItem;
import com.zeroone.star.patrolmgt.entity.Susu_InspectionPoint;
import com.zeroone.star.patrolmgt.entity.Susu_TDict;
import com.zeroone.star.patrolmgt.mapper.InspectionItemMapper;
import com.zeroone.star.patrolmgt.mapper.InspectionPointMapper;
import com.zeroone.star.patrolmgt.mapper.MsPointMapper;
import com.zeroone.star.patrolmgt.mapper.TDictMapper;
import com.zeroone.star.patrolmgt.service.IPatrolPointService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.PointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.dto.SelectPointDTO;
import com.zeroone.star.project.j8.patrolmgt.point.query.PointQuery;
import com.zeroone.star.project.j8.patrolmgt.point.query.SelectPointQuery;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.StringUtils;

import javax.annotation.Resource;
// import java.util.function.Function; // 如果不直接使用 Function.identity()，可以移除此引入

/**
 * <p>
 * 巡检点服务实现类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Susu
 * @since 2025-05-19
 */
@Service // 标记这是一个 Spring Service Bean
public class PatrolPointServiceImpl extends ServiceImpl<InspectionPointMapper, Susu_InspectionPoint> implements IPatrolPointService { // 继承 ServiceImpl，并实现 Service 接口

    @Resource // 注入 MapStruct Mapper (在此方法中不直接用于分页结果转换，但其他方法可能需要)
    MsPointMapper msPointMapper; // TODO 确保你创建了 MsPointMapper 接口

    @Resource
    private TDictMapper tDictMapper;
    @Resource
    private InspectionItemMapper inspectionItemMapper;

    @Override
    public PageDTO<PointDTO> listPatrolPoints(PointQuery query) {
        // 1. 构建分页对象
        // Mybatis-Plus 的 Page 对象用于封装分页参数和查询结果
        // 注意：这里的泛型仍然是 InspectionPoint，但最终 Mapper 会返回 Page<PointDTO>
        Page<Susu_InspectionPoint> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 2. 构建查询条件
        // QueryWrapper 用于构建 SQL 的 WHERE 子句和排序等
        // QueryWrapper 主要用于处理 inspection_point 表自身字段的条件
        QueryWrapper<Susu_InspectionPoint> wrapper = new QueryWrapper<>();

        // 添加条件：根据巡检点ID模糊查询
        // 在 JOIN 查询中，条件字段通常需要加上表别名（例如 "ip.inspection_id"）。
        // 这里为了简化 ServiceImpl 代码，QueryWrapper 中暂时不加别名，
        // 依赖于 Mybatis-Plus 在处理 ${ew.customSqlSegment} 时能够智能地处理字段。
        // 但请务必在 Mapper XML 的 SQL 中使用正确的表别名来引用字段！
        if (StringUtils.hasText(query.getInspectionId())) {
            wrapper.like("inspection_id", query.getInspectionId());
        }

        // 添加条件：根据巡检点名称模糊查询
        if (StringUtils.hasText(query.getInspectionName())) {
            wrapper.like("inspection_name", query.getInspectionName());
        }

        // 注意：按巡检点类型名称过滤的逻辑在 Mapper XML 中处理，无需在这里添加到 QueryWrapper
        // 因为 PointQuery 中的 pointTypeName 字段会直接传递给 Mapper

        // TODO 添加其他基于 inspection_point 表字段的查询条件
        // wrapper.eq("community_id", query.getCommunityId()); // 假设 Query 对象中有 communityId 字段

        // 添加排序条件
        // 示例：按创建时间倒序排序
        // 在 JOIN 查询中，排序字段通常需要加上表别名（例如 "ip.create_time"）。
        // 这里 QueryWrapper 中暂时不加别名，依赖 Mybatis-Plus 自动处理。
        // 但请务必在 Mapper XML 的 SQL 中使用正确的表别名！
//        wrapper.orderByDesc("create_time");
        // TODO 根据实际需求添加或修改排序规则

        // 3. 执行关联查询
        // 调用 InspectionPointMapper 中自定义的关联查询方法 selectPatrolPointPageWithJoin。
        // 这个方法在 Mapper XML 中实现了 JOIN 查询，并将结果直接映射到 PointDTO。
        // 将返回结果的声明类型改为 Page<PointDTO>
        // 传递完整的 query 对象作为参数
        Page<PointDTO> pageResultWithJoin = baseMapper.selectPatrolPointPageWithJoin(page, wrapper, query);

        // 4. 封装为 PageDTO 并返回
        // 由于 selectPatrolPointPageWithJoin 方法已经返回 Page<PointDTO>，
        // 并且 Mybatis 已经根据 resultMap (或自动映射) 将结果映射到了 PointDTO，
        // 这里直接调用 PageDTO.create 的单参数版本进行封装
        return PageDTO.create(pageResultWithJoin);

    }

    @Override
    public PageDTO<SelectPointDTO> listSelectablePoints(SelectPointQuery query) {
        // 1. 构建分页查询对象
        Page<Susu_InspectionPoint> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 2. 构建查询条件
        QueryWrapper<Susu_InspectionPoint> wrapper = new QueryWrapper<>();
        if (StringUtils.hasText(query.getInspectionName())) {
            // 直接查询 InspectionPoint 表的 inspection_name 字段
            wrapper.like("inspection_name", query.getInspectionName());
        }
        // 可选：添加默认排序
        wrapper.orderByAsc("inspection_name"); // 例如按名称升序

        // 3. 查询数据 (直接使用 Mybatis-Plus 的 selectPage)
        // baseMapper 是 ServiceImpl<M, T> 提供的，可以直接调用 M (InspectionPointMapper) 的方法
        // selectPage 会查询出 Page<InspectionPoint>
        Page<Susu_InspectionPoint> inspectionPointPageResult = baseMapper.selectPage(page, wrapper);

        // 4. 将 Page<InspectionPoint> 转换为 PageDTO<SelectPointDTO>
        //    这里使用 PageDTO.create 的一个重载版本，它接受一个转换函数
        //    你需要确保 MsPointMapper 中有 InspectionPoint -> SelectPointDTO 的转换方法
        return PageDTO.create(inspectionPointPageResult, src -> msPointMapper.inspectionPointToSelectPointDTO(src));
    }

    // TODO 实现 IPatrolPointService 接口中的其他方法
    @Transactional
    @Override
    public int updateExistingPatrolPoint(PointDTO pointDto) {
        if (!StringUtils.hasText(pointDto.getInspectionId())) {
            log.error("修改巡检点失败：巡检点ID不能为空。"); // 使用LOGGER
            return -1;
        }

        Susu_InspectionPoint existingPoint = baseMapper.selectById(pointDto.getInspectionId());
        if (existingPoint == null) {
            log.warn("修改巡检点失败：未找到ID为 {} 的巡检点。"); // 使用LOGGER
            return 0;
        }

        // 巡检点名称 (假设是必填项，DTO层面应有@NotBlank)
        if (StringUtils.hasText(pointDto.getInspectionName())) {
            existingPoint.setInspectionName(pointDto.getInspectionName());
        } else {
            log.error("修改巡检点失败：巡检点名称不能为空。巡检点ID");
            return -1; // 或者更具体的错误码，如-4
        }

        if (StringUtils.hasText(pointDto.getPointType())) {
            QueryWrapper<Susu_TDict> tDictQuery = new QueryWrapper<Susu_TDict>()
                    .eq("name", pointDto.getPointType())
                    .eq("table_name", "inspection_point")
                    .eq("table_columns", "point_obj_type")
                    .select("status_cd");
            Susu_TDict dictEntry = tDictMapper.selectOne(tDictQuery); // 使用注入的tDictMapper
            if (dictEntry != null && StringUtils.hasText(dictEntry.getStatusCd())) {
                existingPoint.setPointObjType(dictEntry.getStatusCd());
            } else {
                log.warn("修改巡检点失败：提供的巡检点类型名称 '{}' 无效。巡检点ID: {}"); // 使用LOGGER
                return -1; // 类型无效，中断操作
            }
        } else {
            existingPoint.setPointObjType(null); // 允许通过传入空类型名称来清空类型
        }

        if (StringUtils.hasText(pointDto.getItemName())) {
            QueryWrapper<InspectionItem> itemQuery = new QueryWrapper<InspectionItem>()
                    .eq("item_name", pointDto.getItemName())
                    .eq("community_id", existingPoint.getCommunityId())
                    .select("item_id");
            InspectionItem itemEntry = inspectionItemMapper.selectOne(itemQuery); // 使用注入的inspectionItemMapper
            if (itemEntry != null && StringUtils.hasText(itemEntry.getItemId())) {
                existingPoint.setItemId(itemEntry.getItemId());
            } else {
                log.warn("修改巡检点失败：提供的巡检项目名称 '{}' 在小区ID '{}' 下无效。巡检点ID: {}"); // 使用LOGGER
                return -1; // 项目无效，中断操作
            }
        } else {
            existingPoint.setItemId(null); // 允许通过传入空项目名称来清空项目
        }

        if (pointDto.getPointObjName() != null) {
            existingPoint.setPointObjName(pointDto.getPointObjName());
        } else { // 如果DTO中为null，则将数据库字段也设为null (清空)
            existingPoint.setPointObjName(null);
        }

        if (pointDto.getNfcCode() != null) {
            existingPoint.setNfcCode(pointDto.getNfcCode());
        } else {
            existingPoint.setNfcCode(null);
        }

        if (pointDto.getRemark() != null) {
            existingPoint.setRemark(pointDto.getRemark());
        } else {
            existingPoint.setRemark(null);
        }


        int rowsAffected = baseMapper.updateById(existingPoint);
        if (rowsAffected > 0) {
            System.out.println("成功===============");//
        } else {
            log.warn("巡检点信息修改操作执行后，影响行数为0。ID: {}。可能数据无变化或记录已被删除。"); //
        }
        return rowsAffected;
    }
}
