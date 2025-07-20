package com.zeroone.star.project.dto.j2.configmanager.sys.dictionary;

import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel("增加菜单目录模型")
public class AddTDictResDTO {
    private String SpecName;

    private String name;

    private String statusCd;

    private String description;
}
