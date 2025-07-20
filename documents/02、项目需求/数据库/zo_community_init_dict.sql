-- Change DataBase
USE `zo_community`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Records of t_dict
-- ----------------------------
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (1, '1', '无效的，不在用的', '无效的，不在用的', '2018-11-14 13:28:44', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (2, '0', '有效的，在用的', '有效的，在用的', '2018-11-14 13:28:44', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (3, 'S', '保存成功', '保存成功', '2018-11-14 13:28:44', 'c_business', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (4, 'D', '作废订单', '作废订单', '2018-11-14 13:28:44', 'c_business', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (5, 'E', '错误订单', '错误订单', '2018-11-14 13:28:44', 'c_business', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (6, 'NE', '通知错误订单', '通知错误订单', '2018-11-14 13:28:44', 'c_business', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (7, 'C', '订单完成', '订单完成', '2018-11-14 13:28:44', 'c_business', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (8, 'B', 'Business过程', 'Business过程', '2018-11-14 13:28:44', 'c_business', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (9, 'I', 'Instance过程', 'Instance过程', '2018-11-14 13:28:44', 'c_business', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (10, '1000', '入驻小区审核', '入驻小区审核', '2019-04-15 03:26:51', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (11, '2001', '房屋已售', '房屋已售', '2019-04-17 03:10:48', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (12, '2002', '房屋未售', '房屋未售', '2019-04-17 03:11:10', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (13, '1001', '申请退出小区审核', '申请退出小区审核', '2019-04-18 07:46:14', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (14, '0000', '审核完成', '审核完成', '2019-04-26 16:12:42', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (15, '2003', '房屋出售已交定金', '房屋出售已交定金', '2019-05-09 05:45:00', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (16, '2004', '房屋已出租', '房屋已出租', '2019-05-09 05:46:30', NULL, NULL);
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (17, '0', '有效', '数据状态', '2019-09-19 11:37:49', 'all', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (18, '1', '无效', '数据状态', '2019-09-19 11:37:49', 'all', 'status_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (19, '1000', '待审核', '审核状态', '2019-09-19 11:37:50', 's_community', 'state');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (20, '1100', '审核通过', '审核状态', '2019-09-19 11:37:50', 's_community', 'state');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (21, '1200', '拒绝审核', '审核状态', '2019-09-19 11:37:50', 's_community', 'state');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (22, '1', '总公司', '公司级', '2019-10-06 09:43:55', 'u_org', 'org_level');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (23, '2', '分公司', '分公司级', '2019-10-06 09:44:16', 'u_org', 'org_level');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (24, '3', '部门', '部门级', '2019-10-06 09:44:26', 'u_org', 'org_level');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (25, '1000', '普通员工', '普通员工', '2019-10-06 09:46:12', 'u_org_staff_rel', 'rel_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (26, '2000', '部门经理', '部门经理', '2019-10-06 09:47:21', 'u_org_staff_rel', 'rel_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (27, '1001', '地上停车位', '地上停车位', '2019-10-15 09:47:21', 'parking_area', 'type_cd');
INSERT INTO `t_dict` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (28, '2001', '地下停车位', '地下停车位', '2019-10-15 09:47:21', 'parking_area', 'type_cd');
-- TODO 需要后续补充

SET FOREIGN_KEY_CHECKS = 1;