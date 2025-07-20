# 执行`SQL`注意事项

***注意：这里存放初始的数据库结构，如果后续根据业务需要对数据库进行了修改，需要将新的数据库脚本备份到此目录下面。***

`SQL`文件说明:

- `zo_community.sql`：脚本包含建库、建表语句，必须执行
- `zo_community_init*.sql`：脚本定义系统初始化必须要创建的数据，必须执行
- `zo_community_test*.sql`：脚本定义开发测试数据，可选执行

在执行 `SQL` 文件的时候如果运行报错的话，检查你的 `sql_mode` 是否删除了下面的选项：

```txt
ONLY_FULL_GROUP_BY
NO_ZERO_DAT
NO_ZERO_IN_DATE
```

你可以通过下面命令行查看`sql_mode`情况

```sql
# 查看当前sql_mode
select @@sql_mode;
# 查看全局sql_mode
select @@global.sql_mode;
```

你可以通过下列指令修改（服务器重启后将会失效）

```sql
# 修改全局
set @@global.sql_mode = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';
# 修改当前
set @@sql_mode = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';
```

想要永久生效需要修改`my.ini`配置文件

在导入`sql`的时候还有可能因为数据库`max_allowed_packet`过小导致问题，通过下面命令修改

```	sql
set global max_allowed_packet=1024102416;
```

# 系统核心表记录

```sql
-- 小区表
show full fields from s_community;
-- 小区和物业关系表
show full fields from s_community_member;
-- 商户表
show full fields from s_store;
-- 用户表
show full fields from u_user ;
-- 员工表
show full fields from s_store_user;
-- 楼栋表
show full fields from f_floor ;
-- 单元表
show full fields from building_unit ;
-- 房屋表
show full fields from building_room ;
-- 业主表
show full fields from building_owner ;
-- 字典表
select *from t_dict t where t.table_name = 'u_org_staff_rel'
-- 业主房屋关系表
show full fields from building_owner_room_rel ;
-- 费用项
show full fields from pay_fee_config ;
-- 费用 费用项和房屋 或者 车辆 或者合同的关系表
show full fields from pay_fee;
-- 缴费明细表
show full FIELDS from pay_fee_detail ;
-- 组织 集团分公司 部门
show full fields from u_org;
-- 部门 员工表
show full fields from u_org_staff_rel ;
-- 账户表
show full fields from account;
-- 报修表
show full fields from r_repair_pool ;
-- 水电抄表
show full fields from meter_water;
-- 停车场
show full fields from parking_area;
-- 车位
show full fields from parking_space;
-- 车辆
show full fields from owner_car;
```