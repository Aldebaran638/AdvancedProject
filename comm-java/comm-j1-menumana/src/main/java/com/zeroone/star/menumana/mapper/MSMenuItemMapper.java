package com.zeroone.star.menumana.mapper;

import com.zeroone.star.menumana.entity.MenuItem;
import com.zeroone.star.project.dto.j1.menumana.menuitem.AddMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.DeleteMenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.MenuItemDTO;
import com.zeroone.star.project.dto.j1.menumana.menuitem.ModifyMenuItemDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.Mappings;
import org.mapstruct.Named;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

/**
 * @Description
 * @Author eu
 * @Date 2025/5/25
 */
@Mapper(componentModel = "spring")
public interface MSMenuItemMapper {

    MenuItemDTO doToDTO(MenuItem menuItem);


    MenuItem dtoToDo(MenuItemDTO dto);

    MenuItem addDtoTODo(AddMenuItemDTO dto);

    MenuItem modifyDtoTODo(ModifyMenuItemDTO dto);

    List<MenuItemDTO> doToDTO(List<MenuItem> menuItems);

    List<MenuItem> dtoToDo(List<MenuItemDTO> dtos);


/*转换*/
    @Named("dateToString")
    public static  String dateToString(Date date){
        return date!=null? new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(date): null;
    }
    @Named("stringToDate")
    public static Date stringToDate(String dateStr){
        try {
            return dateStr!=null? new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").parse(dateStr) : null;
        }catch (Exception e){
            return null;
        }
    }
}
