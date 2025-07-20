package com.zeroone.star.configmanager.service.impl;


import com.zeroone.star.configmanager.entity.TDict;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.AddDictionaryDTO;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.AddTDictDTO;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.DictionaryDTO;
import com.zeroone.star.project.dto.j2.configmanager.sys.dictionary.TDictDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

@Mapper(componentModel = "spring")
public interface MSTDictMapper {
    TDictDTO tDictToDto(TDict tdo);

    TDict addDtoToDo(AddTDictDTO dto);

    TDict dtoToDo(TDictDTO dto);

    DictionaryDTO DictToDto(TDict tdo);

    TDict addDictToDo(AddDictionaryDTO dto);

    TDict dtoToDo(AddDictionaryDTO dto);
}
