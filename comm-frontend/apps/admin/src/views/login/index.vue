<script setup lang="ts">
import { useI18n } from "vue-i18n";
import Motion from "./utils/motion";
import { useRouter } from "vue-router";
import { message } from "@/utils/message";
import { loginRules } from "./utils/rule";
import TypeIt from "@/components/ReTypeit";
import { debounce } from "@pureadmin/utils";
import { useNav } from "@/layout/hooks/useNav";
import { useEventListener } from "@vueuse/core";
import type { FormInstance } from "element-plus";
import { $t, transformI18n } from "@/plugins/i18n";
import { operates, thirdParty } from "./utils/enums";
import { useLayout } from "@/layout/hooks/useLayout";
import LoginPhone from "./components/LoginPhone.vue";
import LoginRegist from "./components/LoginRegist.vue";
import LoginUpdate from "./components/LoginUpdate.vue";
import LoginQrCode from "./components/LoginQrCode.vue";
import { bg, avatar, illustration } from "./utils/static";
import { ReImageVerify } from "@/components/ReImageVerify";
import { ref, toRaw, reactive, watch, computed, onMounted, useTemplateRef } from "vue";
import { useRenderIcon } from "@/components/ReIcon/src/hooks";
import { useTranslationLang } from "@/layout/hooks/useTranslationLang";
import { useDataThemeChange } from "@/layout/hooks/useDataThemeChange";

/** @see https://pure-admin.cn/pages/routerMenu/#如何只要静态路由 */
// import { initRouter, getTopMenu } from "@/router/utils";
// 很多逻辑需要使用该工具 故继续配置
import { useUserStoreHook } from "@/store/modules/user";

import { setToken } from "@/utils/auth";
import { addPathMatch, getTopMenu } from "@/router/utils";
import { usePermissionStoreHook } from "@/store/modules/permission";

import dayIcon from "@/assets/svg/day.svg?component";
import darkIcon from "@/assets/svg/dark.svg?component";
import globalization from "@/assets/svg/globalization.svg?component";
import Lock from "~icons/ri/lock-fill";
import Check from "~icons/ep/check";
import User from "~icons/ri/user-3-fill";
import Info from "~icons/ri/information-line";
import Keyhole from "~icons/ri/shield-keyhole-line";

import ReImageVerifySimple from "@/components/ReImageVerifySimple";
import type { CaptchaResult } from "@/components/ReImageVerifySimple";

defineOptions({
	name: "Login",
});

const imgCode = ref("");
const loginDay = ref(7);
const router = useRouter();
const [loading, setLoading] = useToggle(false);
const checked = ref(false);
const disabled = ref(false);
const ruleFormRef = ref<FormInstance>();
const currentPage = computed(() => {
	return useUserStoreHook().currentPage;
});

const { t } = useI18n();
const { initStorage } = useLayout();
initStorage();
const { dataTheme, overallStyle, dataThemeChange } = useDataThemeChange();
dataThemeChange(overallStyle.value);
const { title, getDropdownItemStyle, getDropdownItemClass } = useNav();
const { locale, translationCh, translationEn } = useTranslationLang();

const ruleForm = reactive({
	// 业务变更 框架原版的密码规则是 admin admin123
	// username: "admin",
	// password: "admin123",
	// 由j1组后端提供的账号和密码组
	username: "admin",
	password: "123456",
	verifyCode: "",
});

/** 验证码相关数据 */
const captchaInfo = ref<CaptchaResult | null>(null);
const captchaRef = useTemplateRef("captchaRef");

async function onLogin(formEl: FormInstance | undefined) {
	if (!formEl) return;
	await formEl.validate(async (valid) => {
		if (valid) {
			// 检查验证码
			if (!captchaInfo.value?.uuid) {
				message("请获取验证码", { type: "warning" });
				return;
			}

			if (!ruleForm.verifyCode.trim()) {
				message("请输入验证码", { type: "warning" });
				return;
			}

			/** 框架自带的登录逻辑 */
			function oldLogin() {
				// useUserStoreHook()
				// 	.loginByUsername({
				// 		username: ruleForm.username,
				// 		password: ruleForm.password,
				// 	})
				// 	.then((res) => {
				// 		if (res.success) {
				// 			// 获取后端路由
				// 			return initRouter().then(() => {
				// 				disabled.value = true;
				// 				router
				// 					.push(getTopMenu(true).path)
				// 					.then(() => {
				// 						message(t("common.login.pureLoginSuccess"), { type: "success" });
				// 					})
				// 					.finally(() => (disabled.value = false));
				// 			});
				// 		} else {
				// 			message(t("common.login.pureLoginFail"), { type: "error" });
				// 		}
				// 	})
				// 	.finally(() => (loading.value = false));
			}

			/** @see https://pure-admin.cn/pages/routerMenu/#如何只要静态路由 */
			function newLogin() {
				// 模拟登录请求，实际应该发送到后端
				const loginData = {
					username: ruleForm.username,
					password: ruleForm.password,
					verifyCode: ruleForm.verifyCode,
					uuid: captchaInfo.value?.uuid,
				};

				console.log("登录数据:", loginData);

				// 这里应该是真实的登录请求
				// const response = await loginApi(loginData);

				// 模拟登录成功
				setToken({
					username: "admin",
					roles: ["admin"],
					accessToken: "eyJhbGciOiJIUzUxMiJ9.admin",
				} as any);
				// 静态路由
				usePermissionStoreHook().handleWholeMenus([]);
				addPathMatch();
				router.push(getTopMenu(true).path);
				message(t("common.login.pureLoginSuccess"), { type: "success" });

				// 登录成功后刷新验证码，为下次登录准备
				refreshCaptcha();
			}

			/** 带有验证码的 真实登录接口请求 对接01s接口 */
			async function doLoginWithCaptcha() {
				/**
				 * 执行真实的登录请求
				 * 携带验证码 和uuid
				 */
				await useUserStoreHook()
					.loginByUsername({
						username: ruleForm.username,
						password: ruleForm.password,
						code: ruleForm.verifyCode,
						uuid: captchaInfo.value?.uuid,
					})
					.then(() => {
						// TODO: 对接获取菜单的接口 并存储菜单
						// TODO: 模拟设置用户角色
						setUserRoles(["开发团队", "物业团队", "运营团队", "组织员工"]);
					})
					.then(async () => {
						// TODO: 对接获取菜单的接口 并存储菜单
						// 静态路由
						usePermissionStoreHook().handleWholeMenus([]);
						addPathMatch();
						router.push(getTopMenu(true).path);
						message(t("common.login.pureLoginSuccess"), { type: "success" });
						// 登录成功后刷新验证码，为下次登录准备
						await refreshCaptcha();
					});
			}

			setLoading(true);
			await doLoginWithCaptcha()
				.catch(async () => {
					// 登录失败时刷新验证码
					await refreshCaptcha();
					message(t("common.login.pureLoginFail"), { type: "error" });
				})
				.finally(() => {
					setLoading(false);
				});
		}
	});
}

const immediateDebounce: any = debounce((formRef) => onLogin(formRef), 1000, true);

useEventListener(document, "keydown", ({ code }) => {
	if (["Enter", "NumpadEnter"].includes(code) && !disabled.value && !loading.value)
		immediateDebounce(ruleFormRef.value);
});

watch(imgCode, (value) => {
	useUserStoreHook().SET_VERIFYCODE(value);
});
watch(checked, (bool) => {
	useUserStoreHook().SET_ISREMEMBERED(bool);
});
watch(loginDay, (value) => {
	useUserStoreHook().SET_LOGINDAY(value);
});

/**
 * 验证码加载成功的处理函数
 */
function handleCaptchaLoaded(data: CaptchaResult) {
	captchaInfo.value = data;
	// console.log("验证码加载成功:", data);
	// 这里可以进行额外的处理，比如保存验证码uuid等
}

/**
 * 验证码加载失败的处理函数
 */
function handleCaptchaError(error: any) {
	captchaInfo.value = null;
	console.error("验证码加载失败:", error);
	message("验证码加载失败，请重试", { type: "error" });
}

/**
 * 刷新验证码
 */
async function refreshCaptcha() {
	if (captchaRef.value) {
		await captchaRef.value.refresh();
		// 清空用户输入的验证码
		ruleForm.verifyCode = "";
	}
}

onMounted(async () => {});
</script>

<template>
	<div class="select-none">
		<img :src="bg" class="wave" />
		<div class="flex-c absolute right-5 top-3">
			<!-- 主题 -->
			<el-switch
				v-model="dataTheme"
				inline-prompt
				:active-icon="dayIcon"
				:inactive-icon="darkIcon"
				@change="dataThemeChange"
			/>
			<!-- 国际化 -->
			<el-dropdown trigger="click">
				<globalization
					class="hover:text-primary hover:bg-[transparent]! w-[20px] h-[20px] ml-1.5 cursor-pointer outline-hidden duration-300"
				/>
				<template #dropdown>
					<el-dropdown-menu class="translation">
						<el-dropdown-item
							:style="getDropdownItemStyle(locale, 'zh')"
							:class="['dark:text-white!', getDropdownItemClass(locale, 'zh')]"
							@click="translationCh"
						>
							<IconifyIconOffline v-show="locale === 'zh'" class="check-zh" :icon="Check" />
							简体中文
						</el-dropdown-item>
						<el-dropdown-item
							:style="getDropdownItemStyle(locale, 'en')"
							:class="['dark:text-white!', getDropdownItemClass(locale, 'en')]"
							@click="translationEn"
						>
							<span v-show="locale === 'en'" class="check-en">
								<IconifyIconOffline :icon="Check" />
							</span>
							English
						</el-dropdown-item>
					</el-dropdown-menu>
				</template>
			</el-dropdown>
		</div>
		<div class="login-container">
			<div class="img">
				<component :is="toRaw(illustration)" />
			</div>
			<div class="login-box">
				<div class="login-form">
					<avatar class="avatar" />
					<Motion>
						<h2 class="outline-hidden">
							<TypeIt :options="{ strings: [title], cursor: false, speed: 100 }" />
						</h2>
					</Motion>

					<el-form v-if="currentPage === 0" ref="ruleFormRef" :model="ruleForm" :rules="loginRules" size="large">
						<Motion :delay="100">
							<el-form-item
								:rules="[
									{
										required: true,
										message: transformI18n($t('common.login.pureUsernameReg')),
										trigger: 'blur',
									},
								]"
								prop="username"
							>
								<el-input
									v-model="ruleForm.username"
									clearable
									:placeholder="t('common.login.pureUsername')"
									:prefix-icon="useRenderIcon(User)"
								/>
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
							<el-form-item prop="verifyCode">
								<el-input
									v-model="ruleForm.verifyCode"
									clearable
									:placeholder="t('common.login.pureVerifyCode')"
									:prefix-icon="useRenderIcon(Keyhole)"
								>
									<template v-slot:append>
										<!-- 业务变更 不使用框架自带的前端验证码 -->
										<!-- <ReImageVerify v-model:code="imgCode" /> -->
										<ReImageVerifySimple
											ref="captchaRef"
											@captcha-loaded="handleCaptchaLoaded"
											@captcha-error="handleCaptchaError"
										/>
									</template>
								</el-input>
							</el-form-item>
						</Motion>

						<Motion :delay="250">
							<el-form-item>
								<div class="w-full h-[20px] flex justify-between items-center">
									<el-checkbox v-model="checked">
										<span class="flex">
											<select
												v-model="loginDay"
												:style="{
													width: loginDay < 10 ? '10px' : '16px',
													outline: 'none',
													background: 'none',
													appearance: 'none',
													border: 'none',
												}"
											>
												<option value="1">1</option>
												<option value="7">7</option>
												<option value="30">30</option>
											</select>
											{{ t("common.login.pureRemember") }}
											<IconifyIconOffline
												v-tippy="{
													content: t('common.login.pureRememberInfo'),
													placement: 'top',
												}"
												:icon="Info"
												class="ml-1"
											/>
										</span>
									</el-checkbox>
									<el-button link type="primary" @click="useUserStoreHook().SET_CURRENTPAGE(4)">
										{{ t("common.login.pureForget") }}
									</el-button>
								</div>
								<el-button
									class="w-full mt-4!"
									size="default"
									type="primary"
									:loading="loading"
									:disabled="disabled"
									@click="onLogin(ruleFormRef)"
								>
									{{ t("common.login.pureLogin") }}
								</el-button>
							</el-form-item>
						</Motion>

						<Motion :delay="300">
							<el-form-item>
								<div class="w-full h-[20px] flex justify-between items-center">
									<el-button
										v-for="(item, index) in operates"
										:key="index"
										class="w-full mt-4!"
										size="default"
										@click="useUserStoreHook().SET_CURRENTPAGE(index + 1)"
									>
										{{ t(item.title) }}
									</el-button>
								</div>
							</el-form-item>
						</Motion>
					</el-form>

					<Motion v-if="currentPage === 0" :delay="350">
						<el-form-item>
							<el-divider>
								<p class="text-gray-500 text-xs">
									{{ t("common.login.pureThirdLogin") }}
								</p>
							</el-divider>
							<div class="w-full flex justify-evenly">
								<span v-for="(item, index) in thirdParty" :key="index" :title="t(item.title)">
									<IconifyIconOnline
										:icon="`ri:${item.icon}-fill`"
										width="20"
										class="cursor-pointer text-gray-500 hover:text-blue-400"
									/>
								</span>
							</div>
						</el-form-item>
					</Motion>
					<!-- 手机号登录 -->
					<LoginPhone v-if="currentPage === 1" />
					<!-- 二维码登录 -->
					<LoginQrCode v-if="currentPage === 2" />
					<!-- 注册 -->
					<LoginRegist v-if="currentPage === 3" />
					<!-- 忘记密码 -->
					<LoginUpdate v-if="currentPage === 4" />
				</div>
			</div>
		</div>
		<div class="w-full flex-c absolute bottom-3 text-sm text-[rgba(0,0,0,0.6)] dark:text-[rgba(220,220,242,0.8)]">
			Copyright © 2020-present
			<a class="hover:text-primary" href="https://github.com/pure-admin" target="_blank"> &nbsp;{{ title }} </a>
		</div>
	</div>
</template>

<style scoped>
@import url("@/style/login.css");
</style>

<style lang="scss" scoped>
:deep(.el-input-group__append, .el-input-group__prepend) {
	padding: 0;
}

.translation {
	::v-deep(.el-dropdown-menu__item) {
		padding: 5px 40px;
	}

	.check-zh {
		position: absolute;
		left: 20px;
	}

	.check-en {
		position: absolute;
		left: 20px;
	}
}
</style>
