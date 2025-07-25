// 全局路由类型声明

import type { RouteComponent, RouteLocationNormalized } from "vue-router";
import type { FunctionalComponent } from "vue";

/**
 * 使用了 自动布局插件 故此处手动声明清楚可以使用的布局类型
 * @description
 * 这里有一个坑 此处写的字符串 本质上是layout文件夹下面的文件名
 * 未来更改vue文件名时，此处不一定会及时更新到位
 * 一律以 `layout文件夹下面的文件名` 为准
 */
type LayoutEnums = // 默认布局

		| "index"
		// 简单布局
		| "simple";

const userRoles = ["开发团队", "物业团队", "运营团队", "组织员工"] as const;
type UserRoles = (typeof userRoles)[number];

declare global {
	interface ToRouteType extends RouteLocationNormalized {
		meta: CustomizeRouteMeta;
		// 警告 报错不存在 路由名称 name 可能需要导入自动化路由的name
	}

	/**
	 * @description 完整子路由的`meta`配置表
	 */
	interface CustomizeRouteMeta {
		/** 菜单名称（兼容国际化、非国际化，如何用国际化的写法就必须在根目录的`locales`文件夹下对应添加） `必填` */
		title: string;
		/** 菜单图标 `可选` */
		icon?: string | FunctionalComponent;
		/** 菜单名称右侧的额外图标 */
		extraIcon?: string | FunctionalComponent;
		/** 是否在菜单中显示（默认`true`）`可选` */
		showLink?: boolean;
		/** 是否显示父级菜单 `可选` */
		showParent?: boolean;
		/**
		 * 页面级别权限设置 `可选`
		 * @description
		 * 在本项目内 角色被固定为以下几个固定值 且为中文
		 * - 开发团队
		 * - 物业团队
		 * - 运营团队
		 * - 组织员工
		 */
		// roles?: Array<string>;
		roles?: UserRoles[];
		/** 按钮级别权限设置 `可选` */
		auths?: Array<string>;
		/** 路由组件缓存（开启 `true`、关闭 `false`）`可选` */
		keepAlive?: boolean;
		/** 内嵌的`iframe`链接 `可选` */
		frameSrc?: string;
		/** `iframe`页是否开启首次加载动画（默认`true`）`可选` */
		frameLoading?: boolean;
		/** 页面加载动画（两种模式，第二种权重更高，第一种直接采用`vue`内置的`transitions`动画，第二种是使用`animate.css`编写进、离场动画，平台更推荐使用第二种模式，已经内置了`animate.css`，直接写对应的动画名即可）`可选` */
		transition?: {
			/**
			 * @description 当前路由动画效果
			 * @see {@link https://next.router.vuejs.org/guide/advanced/transitions.html#transitions}
			 * @see animate.css {@link https://animate.style}
			 */
			name?: string;
			/** 进场动画 */
			enterTransition?: string;
			/** 离场动画 */
			leaveTransition?: string;
		};
		/** 当前菜单名称或自定义信息禁止添加到标签页（默认`false`） */
		hiddenTag?: boolean;
		/** 当前菜单名称是否固定显示在标签页且不可关闭（默认`false`） */
		fixedTag?: boolean;
		/** 动态路由可打开的最大数量 `可选` */
		dynamicLevel?: number;
		/** 将某个菜单激活
		 * （主要用于通过`query`或`params`传参的路由，当它们通过配置`showLink: false`后不在菜单中显示，就不会有任何菜单高亮，
		 * 而通过设置`activePath`指定激活菜单即可获得高亮，`activePath`为指定激活菜单的`path`）
		 */
		activePath?: string;

		/** 为路由的 meta 对象增加 自动布局插件 所需要的配置 */
		layout?: LayoutEnums;

		/**
		 * 菜单升序排序，值越高排的越后（只针对顶级路由）`可选`
		 * @description
		 * 这个值不是原版框架自带的 是后期添加的
		 */
		rank?: number;
	}

	/**
	 * @description 完整子路由配置表
	 */
	interface RouteChildrenConfigsTable {
		/** 子路由地址 `必填` */
		path: string;
		/** 路由名字（对应不要重复，和当前组件的`name`保持一致）`必填` */
		name?: string;
		/** 路由重定向 `可选` */
		redirect?: string;
		/** 按需加载组件 `可选` */
		component?: RouteComponent;
		meta?: CustomizeRouteMeta;
		/** 子路由配置项 */
		children?: Array<RouteChildrenConfigsTable>;
	}

	/**
	 * @description 整体路由配置表（包括完整子路由）
	 */
	interface RouteConfigsTable {
		/** 路由地址 `必填` */
		path: string;
		/** 路由名字（保持唯一）`可选` */
		name?: string;
		/** `Layout`组件 `可选` */
		component?: RouteComponent;
		/** 路由重定向 `可选` */
		redirect?: string;
		meta?: {
			/** 菜单名称（兼容国际化、非国际化，如何用国际化的写法就必须在根目录的`locales`文件夹下对应添加）`必填` */
			title: string;
			/** 菜单图标 `可选` */
			icon?: string | FunctionalComponent;
			/** 是否在菜单中显示（默认`true`）`可选` */
			showLink?: boolean;
			/** 菜单升序排序，值越高排的越后（只针对顶级路由）`可选` */
			rank?: number;

			/** 为路由的 meta 对象增加 自动布局插件 所需要的配置 */
			layout?: LayoutEnums;
		};
		/** 子路由配置项 */
		children?: Array<RouteChildrenConfigsTable>;
	}
}

// https://router.vuejs.org/zh/guide/advanced/meta.html#typescript
declare module "vue-router" {
	// eslint-disable-next-line
	interface RouteMeta extends CustomizeRouteMeta {
		/** 为路由的 meta 对象增加 自动布局插件 所需要的配置 */
		layout?: LayoutEnums;
	}
}
