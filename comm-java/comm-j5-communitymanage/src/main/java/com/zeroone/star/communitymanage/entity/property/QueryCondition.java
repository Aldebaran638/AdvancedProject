package com.zeroone.star.communitymanage.entity.property;

import lombok.Data;

/**
 * <p>
 * 描述：查询房屋产权列表的条件
 * </p>
 * @author 苏坡man
 */
@Data
public class QueryCondition {



    private long pageIndex;

    private long pageSize;

    private  String roomId;


    private  String roomNum;


    private  String name;
}