package com.zeroone.star.project.dto.j4.orgmanager;

import io.swagger.annotations.ApiModel;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@ApiModel(value = "员工表")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class EmployeeDTO {

    /** 用户ID */
    private String userId;

    /** 名称 */
    private String name;

    /** 邮箱地址 */
    private String email;

    /** 用户年龄 */
    private Integer age;

    /** 性别，0表示男孩 1表示女孩 */
    private String sex;

    /** 电话 */
    private String tel;

    /** 创建时间 */
    private LocalDateTime createTime;

    /** 数据状态，详细参考 c_status 表，S 保存，0 在用，1 失效 */
    private String statusCd;

}
