<script lang="ts" setup>
definePage({
	meta: {
		title: "巡检计划",
		icon: "f7:menu",
		roles: ["物业团队"],
		rank: getRouteRank("propertyManage.patrolManage.plan"),
	},
});

import { ref, computed, watch } from "vue";
import { transformI18n } from "@/plugins/i18n";

interface 巡检计划_列表数据 {
	计划名称: string;
	计划路线: string;
	计划周期: string;
	签到方式: 签到方式;
	日期范围: string;
	时间范围: 时间范围;
	"任务提前(分钟)": string;
	制定人: string;
	制定时间: string;
	状态: string;
	巡检人员: string;
	操作: string;
}

const tableDataItem: 巡检计划_列表数据 = {
	计划名称: "计划名称",
	计划路线: "计划路线",
	计划周期: "计划周期",
	签到方式: "签到方式",
	日期范围: "日期范围",
	时间范围: "时间范围",
	"任务提前(分钟)": "任务提前(分钟)",
	制定人: "制定人",
	制定时间: "制定时间",
	状态: "状态",
	巡检人员: "巡检人员",
	操作: "操作",
};

/** 表格数据 */
const tableData = ref<巡检计划_列表数据[]>(
	Array(35)
		.fill(null)
		.map(() => ({ ...tableDataItem })),
);

/** 表格列配置 */
const columns = ref<TableColumnList>([
	{
		label: "计划名称",
		prop: "计划名称",
		width: 120,
		fixed: true,
	},
	{
		label: "计划路线",
		prop: "计划路线",
		width: 120,
	},
	{
		label: "计划周期",
		prop: "计划周期",
		width: 120,
	},
	{
		label: "签到方式",
		prop: "签到方式",
		width: 120,
	},
	{
		label: "日期范围",
		prop: "日期范围",
		width: 120,
	},
	{
		label: "时间范围",
		prop: "时间范围",
		width: 120,
	},
	{
		label: "任务提前(分钟)",
		prop: "任务提前(分钟)",
		width: 120,
	},
	{
		label: "制定人",
		prop: "制定人",
		width: 120,
	},
	{
		label: "制定时间",
		prop: "制定时间",
		width: 120,
	},
	{
		label: "状态",
		prop: "状态",
		width: 120,
	},
	{
		label: "巡检人员",
		prop: "巡检人员",
		width: 120,
	},

	{
		label: transformI18n($t("common.table.operation")),
		minWidth: 240,
		fixed: "right",
		slot: "operation",
	},
]);
/** 分页配置 */
const pagination = ref<PaginationProps>({
	...defaultPagination,
	pageSize: 10,
	currentPage: 1,
	total: 1000,
});

/** 处理页数变化 */
async function handlePageSizeChange(pageSize: number) {
	pagination.value.pageSize = pageSize;
	// 做异步接口请求
}
/** 处理页码变化 即后端的 pageIndex */
async function handleCurrentPageChange(currentPage: number) {
	pagination.value.currentPage = currentPage;
	// 做异步接口请求
}

/** 表格组件 配置 */
const pureTableProps = ref<PureTableProps>({
	...defaultPureTableProps,
	data: tableData.value,
	columns: [],
	pagination: pagination.value,
});

/** 表格操作栏组件 配置  */
const pureTableBarProps = ref<PureTableBarProps>({
	title: "巡检计划",
	columns: columns.value,
});

interface 巡检计划_列表查询_VO {
	计划ID?: string;
	计划名称?: string;
	巡检人?: string;
	巡检状态?: string;
}

/**
 * 表格搜索栏 双向绑定的变量 原本的数据
 * @description
 * 为了满足搜索栏组件的校验需求 这里需要额外拓展为索引类型
 */
const plusSearchModelRef: FieldValues & 巡检计划_列表查询_VO = {
	计划ID: "",
	计划名称: "",
	巡检人: "",
	状态: "",
};

/** 表格搜索栏 重置功能用的默认数据 */
const plusSearchDefaultValues = cloneDeep(plusSearchModelRef);

/** 表格搜索栏变量 双向绑定的变量 响应式数据 */
const plusSearchModel = ref(plusSearchModelRef);

/**
 * 表格搜索栏组件 表单配置
 * @see https://github.com/plus-pro-components/plus-pro-components/issues/184
 */
const plusSearchColumns = computed<PlusColumn[]>(() => [
	{
		label: transformI18n($t("propertyManage_inspectionManage.inspection.planID")),
		prop: "计划ID",
		valueType: "input",
	},

	{
		label: transformI18n($t("propertyManage_inspectionManage.inspection.projectName")),
		prop: "计划名称",
		valueType: "input",
	},

	{
		label: transformI18n($t("propertyManage_inspectionManage.inspection.inspectionPersonnel")),
		prop: "巡检人",
		valueType: "input",
	},

	{
		label: transformI18n($t("propertyManage_inspectionManage.inspection.status")),
		prop: "状态",
		valueType: "select",
		options: [
			{
				label: "启用",
				value: "启用",
			},
			{
				label: "停用",
				value: "停用",
			},
		],
	},
]);

/** 表格搜索栏组件 配置  */
const plusSearchProps = ref<PlusSearchProps>({
	defaultValues: plusSearchDefaultValues,
	columns: [],
	labelWidth: 140,
	labelPosition: "right",
	showNumber: 3,
});

function handleReSearch() {
	console.log("重新搜索");
}

async function handleSearch() {
	console.log("搜索");
}
</script>

<template>
	<section class="index-root">
		<PlusSearch v-model="plusSearchModel" :="plusSearchProps" :columns="plusSearchColumns" @search="handleSearch" />

		<!-- {{ plusSearchModel }} -->

		<PureTableBar :="pureTableBarProps" @refresh="handleReSearch">
			<template #buttons>
				<ElButton type="primary"> {{ transformI18n($t("common.buttons.add")) }} </ElButton>
			</template>

			<template #default="{ size, dynamicColumns }">
				<!-- @vue-ignore 忽略treeProps所需要的checkStrictly类型 -->
				<PureTable
					:="pureTableProps"
					:columns="dynamicColumns"
					:size="size"
					@page-size-change="handlePageSizeChange"
					@page-current-change="handleCurrentPageChange"
				>
					<template #operation="{ row }">
						<ElButton type="warning"> {{ transformI18n($t("common.buttons.edit")) }} </ElButton>
						<ElButton type="info"> {{ transformI18n($t("common.buttons.info")) }} </ElButton>
						<ElButton type="danger"> {{ transformI18n($t("common.buttons.del")) }} </ElButton>
					</template>
				</PureTable>
			</template>
		</PureTableBar>
	</section>
</template>

<style lang="scss" scoped>
.index-root {
}
</style>
