package com.zeroone.star.contractmanagement.service.impl;

import com.zeroone.star.contractmanagement.entity.ContractTypeSpec;
import com.zeroone.star.project.dto.j6.contractmanagement.contracttype.ContractExtMetaDTO;
import com.zeroone.star.project.vo.j6.contractmanagement.contracttype.ContractTypeSpecVO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Named;

@Mapper(componentModel = "spring")
public interface MsContractTypeSpecMapper {
    /**
     * 将ContractExtType对象转换为ContractTypeSpecVO对象
     * @param record
     * @return
     */
    ContractTypeSpecVO toContractTypeSpecVO(ContractTypeSpec record);

    @Mapping(target = "specCd", source = "specCd")
    @Mapping(target = "specShow", source = "specShow", qualifiedByName = "booleanToString")
    @Mapping(target = "listShow", source = "listShow", qualifiedByName = "booleanToString")
    @Mapping(target = "required", source = "required", qualifiedByName = "booleanToString")
    @Mapping(target = "specValueType", source = "specValueType", qualifiedByName = "convertValueType")
    @Mapping(target = "specType", source = "specType", qualifiedByName = "convertSpecType")
    @Mapping(target = "createTime", ignore = true)
    ContractTypeSpec dtoToEntity(ContractExtMetaDTO dto);

    @Named("booleanToString")
    static String booleanToString(boolean value) {
        return value ? "Y" : "N";
    }

    @Named("convertValueType")
    static String convertValueType(String text) {
        if (text == null) return null;
        if (text.startsWith("1001") || text.startsWith("2002") ||
                text.startsWith("3003") || text.startsWith("4004") ||
                text.startsWith("5005")) {
            return text;
        }
        if ("字符串".equals(text.trim())) {
            return "1001";
        } else if ("整数".equals(text.trim())) {
            return "2002";
        } else if ("金额".equals(text.trim())) {
            return "3003";
        } else if ("日期".equals(text.trim())) {
            return "4004";
        } else if ("时间".equals(text.trim())) {
            return "5005";
        }
        return text;
    }

    @Named("convertSpecType")
    static String convertSpecType(String code) {
        if (code == null) return null;

        if ("input".equals(code)) {
            return "2233";
        } else if ("select".equals(code)) {
            return "3344";
        } else if ("日期".equals(code)) {
            return "4455";
        } else {
            return code;
        }
    }

}
