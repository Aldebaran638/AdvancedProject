package com.zeroone.star.configmanager.service;

import com.zeroone.star.configmanager.entity.CMappingDomain;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.MappingDomainDTO;
import com.zeroone.star.project.dto.j2.configmanager.mappingdomain.MappingDomainNameDTO;
import com.zeroone.star.project.query.j2.configmanager.MappingDomainQuery;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author hubery
 * @since 2025-05-16
 */
public interface ICMappingDomainService extends IService<CMappingDomain> {


    PageDTO<MappingDomainDTO> search(MappingDomainQuery query);


    List<MappingDomainNameDTO> listAllNames();
}
