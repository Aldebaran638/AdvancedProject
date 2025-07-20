package com.zeroone.star.project.j5.community.publicity;

import com.zeroone.star.project.dto.j5.community.publicity.AddPublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.UpdatePublicityDTO;
import com.zeroone.star.project.dto.j5.community.publicity.DeletePublicityDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：小区公示接口
 *      语：添加公示、修改公示、删除公示
 * </p>
 * @author 语
 * @version 1.0.0
 */
public interface PublicityUpdateApis {

    /**
     * 添加公示信息
     * @param dto 添加公示的数据对象
     * @return 操作结果
     */
    JsonVO<String> addPublicity(AddPublicityDTO dto);

    /**
     * 修改公示信息
     * @param dto 修改公示的数据对象
     * @return 操作结果
     */
    JsonVO<String> modifyPublicity(UpdatePublicityDTO dto);

    /**
     * 删除公示信息（逻辑删除）
     * @param dto 删除公示的数据对象
     * @return 操作结果
     */
    JsonVO<String> removePublicity(DeletePublicityDTO dto);
}
