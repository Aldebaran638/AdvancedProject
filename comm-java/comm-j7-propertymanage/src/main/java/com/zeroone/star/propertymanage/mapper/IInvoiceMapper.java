package com.zeroone.star.propertymanage.mapper;

import com.baomidou.mybatisplus.core.conditions.Wrapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.toolkit.Constants;
import com.zeroone.star.propertymanage.entity.Invoice;
import com.zeroone.star.propertymanage.entity.InvoiceTitle;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface IInvoiceMapper extends BaseMapper<Invoice> {

}
