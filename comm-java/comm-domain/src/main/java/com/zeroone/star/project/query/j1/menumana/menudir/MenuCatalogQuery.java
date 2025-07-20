package com.zeroone.star.project.query.j1.menumana.menudir;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;
import org.springframework.web.bind.annotation.RequestParam;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;

@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("菜单目录查询（分页、条件）请求参数对象")
public class MenuCatalogQuery extends PageQuery {
    /**
     * 菜单目录名称
     */
    @ApiModelProperty(value = "菜单目录名称", example = "物业")
    private String name;

    /**
     * 商户类型
     */
    @ApiModelProperty(value = "商户类型", example = "800900000000", required = true)
    private String storeType;
    /**
     * 是否显示
     */
    @ApiModelProperty(value = "是否显示",example = "Y")
    private String isShow;

    @NotNull(message = "页码不能为空")
    @Min(value = 1, message = "页码最小为1")
    @ApiModelProperty(value = "页码", required = true, example = "1")
    @Override  // 覆盖父类字段
    public long getPageIndex() {
        return super.getPageIndex();
    }

    @NotNull(message = "每页数量不能为空")
    @Min(value = 1, message = "每页数量最小为1")
    @ApiModelProperty(value = "每页数量", required = true, example = "10")
    @Override
    public long getPageSize() {
        return super.getPageSize();
    }
}