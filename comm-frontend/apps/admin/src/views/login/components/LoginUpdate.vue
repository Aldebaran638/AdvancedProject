<script setup lang="ts">
import { useI18n } from "vue-i18n";
import { ref, reactive } from "vue";
import Motion from "../utils/motion";
import { message } from "@/utils/message";
import { updateRules } from "../utils/rule";
import type { FormInstance } from "element-plus";
import { useVerifyCode } from "../utils/verifyCode";
import { $t, transformI18n } from "@/plugins/i18n";
import { useUserStoreHook } from "@/store/modules/user";
import { useRenderIcon } from "@/components/ReIcon/src/hooks";
import Lock from "~icons/ri/lock-fill";
import Iphone from "~icons/ep/iphone";
import Keyhole from "~icons/ri/shield-keyhole-line";

const { t } = useI18n();
const loading = ref(false);
const ruleForm = reactive({
	phone: "",
	verifyCode: "",
	password: "",
	repeatPassword: "",
});
const ruleFormRef = ref<FormInstance>();
const { isDisabled, text } = useVerifyCode();
const repeatPasswordRule = [
	{
		validator: (rule, value, callback) => {
			if (value === "") {
				callback(new Error(transformI18n($t("common.login.purePassWordSureReg"))));
			} else if (ruleForm.password !== value) {
				callback(new Error(transformI18n($t("common.login.purePassWordDifferentReg"))));
			} else {
				callback();
			}
		},
		trigger: "blur",
	},
];

const onUpdate = async (formEl: FormInstance | undefined) => {
	loading.value = true;
	if (!formEl) return;
	await formEl.validate((valid) => {
		if (valid) {
			// 模拟请求，需根据实际开发进行修改
			setTimeout(() => {
				message(transformI18n($t("common.login.purePassWordUpdateReg")), {
					type: "success",
				});
				loading.value = false;
			}, 2000);
		} else {
			loading.value = false;
		}
	});
};

function onBack() {
	useVerifyCode().end();
	useUserStoreHook().SET_CURRENTPAGE(0);
}
</script>

<template>
	<el-form ref="ruleFormRef" :model="ruleForm" :rules="updateRules" size="large">
		<Motion>
			<el-form-item prop="phone">
				<el-input
					v-model="ruleForm.phone"
					clearable
					:placeholder="t('common.login.purePhone')"
					:prefix-icon="useRenderIcon(Iphone)"
				/>
			</el-form-item>
		</Motion>

		<Motion :delay="100">
			<el-form-item prop="verifyCode">
				<div class="w-full flex justify-between">
					<el-input
						v-model="ruleForm.verifyCode"
						clearable
						:placeholder="t('common.login.pureSmsVerifyCode')"
						:prefix-icon="useRenderIcon(Keyhole)"
					/>
					<el-button :disabled="isDisabled" class="ml-2!" @click="useVerifyCode().start(ruleFormRef, 'phone')">
						{{ text.length > 0 ? text + t("common.login.pureInfo") : t("common.login.pureGetVerifyCode") }}
					</el-button>
				</div>
			</el-form-item>
		</Motion>

		<Motion :delay="150">
			<el-form-item prop="password">
				<el-input
					v-model="ruleForm.password"
					clearable
					show-password
					:placeholder="t('common.login.purePassword')"
					:prefix-icon="useRenderIcon(Lock)"
				/>
			</el-form-item>
		</Motion>

		<Motion :delay="200">
			<el-form-item :rules="repeatPasswordRule" prop="repeatPassword">
				<el-input
					v-model="ruleForm.repeatPassword"
					clearable
					show-password
					:placeholder="t('common.login.pureSure')"
					:prefix-icon="useRenderIcon(Lock)"
				/>
			</el-form-item>
		</Motion>

		<Motion :delay="250">
			<el-form-item>
				<el-button class="w-full" size="default" type="primary" :loading="loading" @click="onUpdate(ruleFormRef)">
					{{ t("common.login.pureDefinite") }}
				</el-button>
			</el-form-item>
		</Motion>

		<Motion :delay="300">
			<el-form-item>
				<el-button class="w-full" size="default" @click="onBack">
					{{ t("common.login.pureBack") }}
				</el-button>
			</el-form-item>
		</Motion>
	</el-form>
</template>
