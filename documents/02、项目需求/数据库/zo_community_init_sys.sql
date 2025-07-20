-- Change DataBase
USE `zo_community`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Records of c_status
-- ----------------------------
INSERT INTO `c_status` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (1, '1', '无效的，不在用的', '无效的，不在用的', '2018-11-14 13:28:44', NULL, NULL);
INSERT INTO `c_status` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (2, '0', '有效的，在用的', '有效的，在用的', '2018-11-14 13:28:44', NULL, NULL);
INSERT INTO `c_status` (`id`, `status_cd`, `name`, `description`, `create_time`, `table_name`, `table_columns`) VALUES (3, 'S', '保存成功', '保存成功', '2018-11-14 13:28:44', NULL, NULL);
-- TODO 需要后续补充

-- ----------------------------
-- Records of user_level
-- ----------------------------
INSERT INTO `user_level` (`id`, `level_cd`, `name`, `description`, `create_time`) VALUES (1, '00', '系统管理员', '系统管理员', '2018-11-14 13:28:59');
INSERT INTO `user_level` (`id`, `level_cd`, `name`, `description`, `create_time`) VALUES (3, '01', '员工', '员工', '2019-02-13 09:03:10');
INSERT INTO `user_level` (`id`, `level_cd`, `name`, `description`, `create_time`) VALUES (4, '02', '普通用户', '普通用户', '2019-02-13 09:04:25');
INSERT INTO `user_level` (`id`, `level_cd`, `name`, `description`, `create_time`) VALUES (5, '03', '商城用户', '商城用户', '2019-02-13 09:04:25');
INSERT INTO `user_level` (`id`, `level_cd`, `name`, `description`, `create_time`) VALUES (6, '04', '运维管理员', '运维管理员', '2021-07-06 16:33:04');
INSERT INTO `user_level` (`id`, `level_cd`, `name`, `description`, `create_time`) VALUES (7, '05', '临时人员', '临时人员', '2021-07-06 16:33:04');
-- TODO 需要后续补充

-- ----------------------------
-- Records of u_user
-- ----------------------------
INSERT INTO `u_user` (`id`, `user_id`, `name`, `email`, `address`, `password`, `location_cd`, `age`, `sex`, `tel`, `level_cd`, `b_id`, `create_time`, `status_cd`, `score`) VALUES (1, '30518939884421922816', 'admin', 'sss@sf.com', 'ccc地方都是', '3ad352384261cbc2c7462210dbb3ce61', NULL, NULL, '0', '17797173944', '00', '202022030905502375', '2018-12-02 16:01:50', '0', NULL);
INSERT INTO `u_user` (`id`, `user_id`, `name`, `email`, `address`, `password`, `location_cd`, `age`, `sex`, `tel`, `level_cd`, `b_id`, `create_time`, `status_cd`, `score`) VALUES (2, '30520751775595118592', 'dev', '129@qq.com', 'Qingdao', '3ad352384261cbc2c7462210dbb3ce61', NULL, 0, '0', '17797173942', '00', '202021111595270456', '2018-12-07 16:01:38', '0', NULL);
-- TODO 需要后续补充

SET FOREIGN_KEY_CHECKS = 1;