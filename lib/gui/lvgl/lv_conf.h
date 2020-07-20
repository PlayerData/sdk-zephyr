/*
 * Copyright (c) 2018-2019 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 * Copyright (c) 2020 Teslabs Engineering S.L.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_
#define ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_

#ifdef CONFIG_LVGL_USE_DEBUG
#include <sys/__assert.h>
#define LV_DEBUG_ASSERT(expr, msg, value) __ASSERT(expr, msg)
#endif

/* Graphical settings */

#define LV_HOR_RES_MAX	CONFIG_LVGL_HOR_RES
#define LV_VER_RES_MAX	CONFIG_LVGL_VER_RES

#ifdef CONFIG_LVGL_COLOR_DEPTH_32
#define LV_COLOR_DEPTH	32
#elif defined(CONFIG_LVGL_COLOR_DEPTH_16)
#define LV_COLOR_DEPTH	16
#elif defined(CONFIG_LVGL_COLOR_DEPTH_8)
#define LV_COLOR_DEPTH	8
#elif defined(CONFIG_LVGL_COLOR_DEPTH_1)
#define LV_COLOR_DEPTH	1
#endif

#ifdef CONFIG_LVGL_COLOR_16_SWAP
#define LV_COLOR_16_SWAP 1
#else
#define LV_COLOR_16_SWAP 0
#endif

#ifdef CONFIG_LVGL_COLOR_SCREEN_TRANSP
#define LV_COLOR_SCREEN_TRANSP 1
#else
#define LV_COLOR_SCREEN_TRANSP 0
#endif

#ifdef CONFIG_LVGL_CHROMA_KEY_RED
#define LV_COLOR_TRANSP LV_COLOR_RED
#elif defined(CONFIG_LVGL_CHROMA_KEY_GREEN)
#define LV_COLOR_TRANSP LV_COLOR_LIME
#elif defined(CONFIG_LVGL_CHROMA_KEY_BLUE)
#define LV_COLOR_TRANSP LV_COLOR_BLUE
#elif defined(CONFIG_LVGL_CHROMA_KEY_CUSTOM)
#define LV_COLOR_TRANSP \
	LV_COLOR_MAKE(CONFIG_LVGL_CUSTOM_CHROMA_KEY_RED, \
		      CONFIG_LVGL_CUSTOM_CHROMA_KEY_GREEN, \
		      CONFIG_LVGL_CUSTOM_CHROMA_KEY_BLUE)
#endif

#ifdef CONFIG_LVGL_ANTIALIAS
#define LV_ANTIALIAS 1
#else
#define LV_ANTIALIAS 0
#endif

#define LV_DISP_DEF_REFR_PERIOD	CONFIG_LVGL_SCREEN_REFRESH_PERIOD

#define LV_DPI CONFIG_LVGL_DPI

#define LV_DISP_SMALL_LIMIT CONFIG_LVGL_DISP_SMALL_LIMIT
#define LV_DISP_MEDIUM_LIMIT CONFIG_LVGL_DISP_MEDIUM_LIMIT
#define LV_DISP_LARGE_LIMIT CONFIG_LVGL_DISP_LARGE_LIMIT

typedef short lv_coord_t;

/* Memory manager settings */

#define LV_MEM_CUSTOM 1

#ifdef CONFIG_LVGL_MEM_POOL_HEAP_KERNEL

#define LV_MEM_CUSTOM_INCLUDE	"kernel.h"
#define LV_MEM_CUSTOM_ALLOC	k_malloc
#define LV_MEM_CUSTOM_FREE	k_free

#elif defined(CONFIG_LVGL_MEM_POOL_HEAP_LIB_C)

#define LV_MEM_CUSTOM_INCLUDE	"stdlib.h"
#define LV_MEM_CUSTOM_ALLOC	malloc
#define LV_MEM_CUSTOM_FREE	free

#else

#define LV_MEM_CUSTOM_INCLUDE	"lvgl_mem.h"
#define LV_MEM_CUSTOM_ALLOC	lvgl_malloc
#define LV_MEM_CUSTOM_FREE	lvgl_free

#endif

#define LV_ENABLE_GC 0

/* Input device settings */

#define LV_INDEV_DEF_READ_PERIOD CONFIG_LVGL_INPUT_REFRESH_PERIOD

#define LV_INDEV_DEF_DRAG_LIMIT CONFIG_LVGL_INPUT_DRAG_THRESHOLD

#define LV_INDEV_DEF_DRAG_THROW CONFIG_LVGL_INPUT_DRAG_THROW_SLOW_DOWN

#define LV_INDEV_DEF_LONG_PRESS_TIME CONFIG_LVGL_INPUT_LONG_PRESS_TIME

#define LV_INDEV_DEF_LONG_PRESS_REP_TIME \
	CONFIG_LVGL_INPUT_LONG_RESS_REPEAT_TIME

#define LV_INDEV_DEF_GESTURE_LIMIT CONFIG_LVGL_INPUT_GESTURE_LIMIT

#define LV_INDEV_DEF_GESTURE_MIN_VELOCITY CONFIG_LVGL_INPUT_GESTURE_MIN_VELOCITY

/* Feature usage */

#ifdef CONFIG_LVGL_ANIMATION
#define LV_USE_ANIMATION 1
#else
#define LV_USE_ANIMATION 0
#endif

#if LV_USE_ANIMATION
typedef void *lv_anim_user_data_t;
#endif

#ifdef CONFIG_LVGL_SHADOW
#define LV_USE_SHADOW 1
#else
#define LV_USE_SHADOW 0
#endif

#if LV_USE_SHADOW
#define LV_SHADOW_CACHE_SIZE CONFIG_LVGL_SHADOW_CACHE_SIZE
#endif

#ifdef CONFIG_LVGL_BLEND_MODES
#define LV_USE_BLEND_MODES 1
#else
#define LV_USE_BLEND_MODES 0
#endif

#ifdef CONFIG_LVGL_OPA_SCALE
#define LV_USE_OPA_SCALE 1
#else
#define LV_USE_OPA_SCALE 0
#endif

#ifdef CONFIG_LVGL_IMG_TRANSFORM
#define LV_USE_IMG_TRANSFORM 1
#else
#define LV_USE_IMG_TRANSFORM 0
#endif

#ifdef CONFIG_LVGL_GROUP
#define LV_USE_GROUP 1
#else
#define LV_USE_GROUP 0
#endif

#if LV_USE_GROUP
typedef void *lv_group_user_data_t;
#endif

#ifdef CONFIG_LVGL_GPU
#define LV_USE_GPU 1
#else
#define LV_USE_GPU 0
#endif

#ifdef CONFIG_LVGL_FILESYSTEM
#define LV_USE_FILESYSTEM 1
#else
#define LV_USE_FILESYSTEM 0
#endif

#if LV_USE_FILESYSTEM
typedef void *lv_fs_drv_user_data_t;
#endif

#define LV_USE_USER_DATA 1

#ifdef CONFIG_LVGL_PERF_MONITOR
#define LV_USE_PERF_MONITOR 1
#else
#define LV_USE_PERF_MONITOR 0
#endif

#ifdef CONFIG_LVGL_API_EXTENSION_V6
#define LV_USE_API_EXTENSION_V6 1
#else
#define LV_USE_API_EXTENSION_V6 0
#endif

/* Image decoder and cache */

#ifdef CONFIG_LVGL_IMG_CF_INDEXED
#define LV_IMG_CF_INDEXED 1
#else
#define LV_IMG_CF_INDEXED 0
#endif

#ifdef CONFIG_LVGL_IMG_CF_ALPHA
#define LV_IMG_CF_ALPHA 1
#else
#define LV_IMG_CF_ALPHA 0
#endif

#define LV_IMG_CACHE_DEF_SIZE CONFIG_LVGL_IMG_CACHE_DEF_SIZE

typedef void *lv_img_decoder_user_data_t;

/* Compiler settings */

#define LV_ATTRIBUTE_TICK_INC

#define LV_ATTRIBUTE_TASK_HANDLER

#define LV_ATTRIBUTE_MEM_ALIGN

#define LV_ATTRIBUTE_LARGE_CONST

#define LV_EXPORT_CONST_INT(int_value)

/* HAL settings */

#define LV_TICK_CUSTOM			1
#define LV_TICK_CUSTOM_INCLUDE		"kernel.h"
#define LV_TICK_CUSTOM_SYS_TIME_EXPR	(k_uptime_get_32())

typedef void *lv_disp_drv_user_data_t;
typedef void *lv_indev_drv_user_data_t;

/* Log settings */

#if CONFIG_LVGL_LOG_LEVEL == 0
#define LV_USE_LOG 0
#else
#define LV_USE_LOG 1

#if CONFIG_LVGL_LOG_LEVEL == 1
#define LV_LOG_LEVEL LV_LOG_LEVEL_ERROR
#elif CONFIG_LVGL_LOG_LEVEL == 2
#define LV_LOG_LEVEL LV_LOG_LEVEL_WARN
#elif CONFIG_LVGL_LOG_LEVEL == 3
#define LV_LOG_LEVEL LV_LOG_LEVEL_INFO
#elif CONFIG_LVGL_LOG_LEVEL == 4
#define LV_LOG_LEVEL LV_LOG_LEVEL_TRACE
#endif

#define LV_LOG_PRINTF 0
#endif

/* Debug settings */

#ifdef CONFIG_LVGL_USE_DEBUG
#define LV_USE_DEBUG 1
#else
#define LV_USE_DEBUG 0
#endif

#if LV_USE_DEBUG

#ifdef CONFIG_LVGL_USE_ASSERT_NULL
#define LV_USE_ASSERT_NULL 1
#else
#define LV_USE_ASSERT_NULL 0
#endif

#ifdef CONFIG_LVGL_USE_ASSERT_MEM
#define LV_USE_ASSERT_MEM 1
#else
#define LV_USE_ASSERT_MEM 0
#endif

#ifdef CONFIG_LVGL_USE_ASSERT_MEM_INTEGRITY
#define LV_USE_ASSERT_MEM_INTEGRITY 1
#else
#define LV_USE_ASSERT_MEM_INTEGRITY 0
#endif

#ifdef CONFIG_LVGL_USE_ASSERT_STR
#define LV_USE_ASSERT_STR 1
#else
#define LV_USE_ASSERT_STR 0
#endif

#ifdef CONFIG_LVGL_USE_ASSERT_OBJ
#define LV_USE_ASSERT_OBJ 1
#else
#define LV_USE_ASSERT_OBJ 0
#endif

#ifdef CONFIG_LVGL_USE_ASSERT_STYLE
#define LV_USE_ASSERT_STYLE 1
#else
#define LV_USE_ASSERT_STYLE 0
#endif

#endif /* LV_USE_DEBUG */

/* THEME USAGE */

/* Empty theme */
#ifdef CONFIG_LVGL_THEME_EMPTY
#define LV_USE_THEME_EMPTY 1
#else
#define LV_USE_THEME_EMPTY 0
#endif

#if LV_USE_THEME_EMPTY
#define LV_THEME_DEFAULT_FLAG 0
#define LV_THEME_DEFAULT_INIT lv_theme_empty_init
#endif

/* Material theme */
#ifdef CONFIG_LVGL_THEME_MATERIAL
#define LV_USE_THEME_MATERIAL 1
#else
#define LV_USE_THEME_MATERIAL 0
#endif

#if LV_USE_THEME_MATERIAL
#define LV_THEME_DEFAULT_INIT lv_theme_material_init

#if defined(CONFIG_LVGL_THEME_MATERIAL_LIGHT)
#define LV_THEME_DEFAULT_FLAG LV_THEME_MATERIAL_FLAG_LIGHT
#elif defined(CONFIG_LVGL_THEME_MATERIAL_DARK)
#define LV_THEME_DEFAULT_FLAG LV_THEME_MATERIAL_FLAG_DARK
#endif

#endif

/* Mono-color theme */
#ifdef CONFIG_LVGL_THEME_MONO
#define LV_USE_THEME_MONO 1
#else
#define LV_USE_THEME_MONO 0
#endif

#if LV_USE_THEME_MONO
#define LV_THEME_DEFAULT_INIT lv_theme_mono_init
#define LV_THEME_DEFAULT_FLAG 0
#endif

/* Custom theme */
#if CONFIG_LVGL_THEME_CUSTOM

lv_theme_t *LVGL_THEME_CUSTOM_INIT_FUNCTION(
	lv_color_t color_primary, lv_color_t color_secondary, uint32_t flags,
	const lv_font_t *font_small, const lv_font_t *font_normal,
	const lv_font_t *font_subtitle, const lv_font_t *font_title);

#define LV_THEME_DEFAULT_INIT LVGL_THEME_CUSTOM_INIT_FUNCTION

#endif

/* Theme primary color */
#if defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_WHITE)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_WHITE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_SILVER)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_SILVER
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_GRAY)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_GRAY
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_BLACK)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_BLACK
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_RED)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_RED
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_MAROON)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_MAROON
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_YELLOW)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_YELLOW
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_OLIVE)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_OLIVE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_LIME)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_LIME
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_GREEN)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_GREEN
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_CYAN)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_CYAN
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_AQUA)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_AQUA
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_TEAL)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_TEAL
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_BLUE)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_BLUE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_NAVY)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_NAVY
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_MAGENTA)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_MAGENTA
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_PURPLE)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_PURPLE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_ORANGE)
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_ORANGE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_CUSTOM)
#define LV_THEME_DEFAULT_COLOR_PRIMARY \
	LV_COLOR_MAKE(CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_CUSTOM_RED, \
		      CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_CUSTOM_GREEN, \
		      CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_CUSTOM_BLUE)
#endif

/* Theme secondary color */
#if defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_WHITE)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_WHITE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_SILVER)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_SILVER
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_GRAY)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_GRAY
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_BLACK)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_BLACK
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_RED)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_RED
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_MAROON)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_MAROON
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_YELLOW)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_YELLOW
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_OLIVE)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_OLIVE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_LIME)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_LIME
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_GREEN)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_GREEN
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_CYAN)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_CYAN
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_AQUA)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_AQUA
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_TEAL)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_TEAL
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_BLUE)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_BLUE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_NAVY)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_NAVY
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_MAGENTA)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_MAGENTA
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_PURPLE)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_PURPLE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_ORANGE)
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_ORANGE
#elif defined(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_CUSTOM)
#define LV_THEME_DEFAULT_COLOR_SECONDARY \
	LV_COLOR_MAKE(CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_CUSTOM_RED, \
		      CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_CUSTOM_GREEN, \
		      CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_CUSTOM_BLUE)
#endif

/* Theme small font */
#if defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_12)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_12)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_14)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_14)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_16)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_16)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_18)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_18)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_20)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_20)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_22)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_22)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_24)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_24)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_26)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_26)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_28)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_28)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_30)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_30)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_32)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_32)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_34)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_34)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_36)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_36)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_38)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_38)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_40)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_40)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_42)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_42)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_44)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_44)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_46)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_46)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_48)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_48)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_12_SUBPX)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_12_subpx)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_MONTSERRAT_28_COMPRESSED)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_montserrat_28_compressed)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_DEJAVU_16_PERSIAN_HEBREW)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_dejavu_16_persian_hebrew)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_SIMSUN_16_CJK)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_simsun_16_cjk)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_UNSCII_8)
#define LV_THEME_DEFAULT_FONT_SMALL (&lv_font_unscii_8)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SMALL_CUSTOM)
extern void *lv_theme_default_font_small_custom_ptr;
#define LV_THEME_DEFAULT_FONT_SMALL \
	((lv_font_t *)lv_theme_default_font_small_custom_ptr)
#endif

/* Theme normal font */
#if defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_12)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_12)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_14)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_14)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_16)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_16)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_18)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_18)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_20)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_20)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_22)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_22)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_24)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_24)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_26)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_26)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_28)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_28)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_30)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_30)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_32)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_32)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_34)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_34)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_36)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_36)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_38)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_38)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_40)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_40)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_42)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_42)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_44)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_44)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_46)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_46)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_48)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_48)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_12_SUBPX)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_12_subpx)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_MONTSERRAT_28_COMPRESSED)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_montserrat_28_compressed)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_DEJAVU_16_PERSIAN_HEBREW)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_dejavu_16_persian_hebrew)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_SIMSUN_16_CJK)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_simsun_16_cjk)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_UNSCII_8)
#define LV_THEME_DEFAULT_FONT_NORMAL (&lv_font_unscii_8)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_NORMAL_CUSTOM)
extern void *lv_theme_default_font_normal_custom_ptr;
#define LV_THEME_DEFAULT_FONT_NORMAL \
	((lv_font_t *)lv_theme_default_font_normal_custom_ptr)
#endif

/* Theme subtitle font */
#if defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_12)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_12)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_14)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_14)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_16)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_16)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_18)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_18)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_20)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_20)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_22)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_22)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_24)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_24)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_26)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_26)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_28)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_28)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_30)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_30)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_32)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_32)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_34)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_34)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_36)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_36)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_38)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_38)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_40)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_40)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_42)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_42)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_44)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_44)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_46)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_46)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_48)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_48)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_12_SUBPX)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_12_subpx)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_MONTSERRAT_28_COMPRESSED)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_montserrat_28_compressed)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_DEJAVU_16_PERSIAN_HEBREW)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_dejavu_16_persian_hebrew)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_SIMSUN_16_CJK)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_simsun_16_cjk)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_UNSCII_8)
#define LV_THEME_DEFAULT_FONT_SUBTITLE (&lv_font_unscii_8)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_SUBTITLE_CUSTOM)
extern void *lv_theme_default_font_subtitle_custom_ptr;
#define LV_THEME_DEFAULT_FONT_SUBTITLE \
	((lv_font_t *)lv_theme_default_font_subtitle_custom_ptr)
#endif

/* Theme title font */
#if defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_12)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_12)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_14)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_14)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_16)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_16)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_18)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_18)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_20)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_20)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_22)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_22)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_24)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_24)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_26)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_26)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_28)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_28)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_30)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_30)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_32)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_32)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_34)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_34)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_36)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_36)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_38)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_38)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_40)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_40)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_42)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_42)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_44)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_44)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_46)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_46)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_48)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_48)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_12_SUBPX)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_12_subpx)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_MONTSERRAT_28_COMPRESSED)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_montserrat_28_compressed)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_DEJAVU_16_PERSIAN_HEBREW)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_dejavu_16_persian_hebrew)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_SIMSUN_16_CJK)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_simsun_16_cjk)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_UNSCII_8)
#define LV_THEME_DEFAULT_FONT_TITLE (&lv_font_unscii_8)
#elif defined(CONFIG_LVGL_THEME_DEFAULT_FONT_TITLE_CUSTOM)
extern void *lv_theme_default_font_title_custom_ptr;
#define LV_THEME_DEFAULT_FONT_TITLE \
	((lv_font_t *)lv_theme_default_font_title_custom_ptr)
#endif

/* FONT USAGE */

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_12
#define LV_FONT_MONTSERRAT_12 1
#else
#define LV_FONT_MONTSERRAT_12 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_14
#define LV_FONT_MONTSERRAT_14 1
#else
#define LV_FONT_MONTSERRAT_14 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_16
#define LV_FONT_MONTSERRAT_16 1
#else
#define LV_FONT_MONTSERRAT_16 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_18
#define LV_FONT_MONTSERRAT_18 1
#else
#define LV_FONT_MONTSERRAT_18 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_20
#define LV_FONT_MONTSERRAT_20 1
#else
#define LV_FONT_MONTSERRAT_20 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_22
#define LV_FONT_MONTSERRAT_22 1
#else
#define LV_FONT_MONTSERRAT_22 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_24
#define LV_FONT_MONTSERRAT_24 1
#else
#define LV_FONT_MONTSERRAT_24 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_26
#define LV_FONT_MONTSERRAT_26 1
#else
#define LV_FONT_MONTSERRAT_26 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_28
#define LV_FONT_MONTSERRAT_28 1
#else
#define LV_FONT_MONTSERRAT_28 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_30
#define LV_FONT_MONTSERRAT_30 1
#else
#define LV_FONT_MONTSERRAT_30 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_32
#define LV_FONT_MONTSERRAT_32 1
#else
#define LV_FONT_MONTSERRAT_32 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_34
#define LV_FONT_MONTSERRAT_34 1
#else
#define LV_FONT_MONTSERRAT_34 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_36
#define LV_FONT_MONTSERRAT_36 1
#else
#define LV_FONT_MONTSERRAT_36 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_38
#define LV_FONT_MONTSERRAT_38 1
#else
#define LV_FONT_MONTSERRAT_38 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_40
#define LV_FONT_MONTSERRAT_40 1
#else
#define LV_FONT_MONTSERRAT_40 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_42
#define LV_FONT_MONTSERRAT_42 1
#else
#define LV_FONT_MONTSERRAT_42 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_44
#define LV_FONT_MONTSERRAT_44 1
#else
#define LV_FONT_MONTSERRAT_44 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_46
#define LV_FONT_MONTSERRAT_46 1
#else
#define LV_FONT_MONTSERRAT_46 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_48
#define LV_FONT_MONTSERRAT_48 1
#else
#define LV_FONT_MONTSERRAT_48 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_12_SUBPX
#define LV_FONT_MONTSERRAT_12_SUBPX 1
#else
#define LV_FONT_MONTSERRAT_12_SUBPX 0
#endif

#ifdef CONFIG_LVGL_FONT_MONTSERRAT_28_COMPRESSED
#define LV_FONT_MONTSERRAT_28_COMPRESSED 1
#else
#define LV_FONT_MONTSERRAT_28_COMPRESSED 0
#endif

#ifdef CONFIG_LVGL_FONT_DEJAVU_16_PERSIAN_HEBREW
#define LV_FONT_DEJAVU_16_PERSIAN_HEBREW 1
#else
#define LV_FONT_DEJAVU_16_PERSIAN_HEBREW 0
#endif

#ifdef CONFIG_LVGL_FONT_SIMSUN_16_CJK
#define LV_FONT_SIMSUN_16_CJK 1
#else
#define LV_FONT_SIMSUN_16_CJK 0
#endif

#ifdef CONFIG_LVGL_FONT_UNSCII_8
#define LV_FONT_UNSCII_8 1
#else
#define LV_FONT_UNSCII_8 0
#endif

#ifdef CONFIG_LVGL_FONT_SUBPX_BGR
#define LV_FONT_SUBPX_BGR 1
#else
#define LV_FONT_SUBPX_BGR 0
#endif

#define LV_FONT_CUSTOM_DECLARE

typedef void *lv_font_user_data_t;

/* Text settings */

#ifdef CONFIG_LVGL_TXT_ENC_ASCII
#define LV_TXT_ENC LV_TXT_ENC_ASCII
#elif defined(CONFIG_LVGL_TXT_ENC_UTF8)
#define LV_TXT_ENC LV_TXT_ENC_UTF8
#endif

#define LV_TXT_BREAK_CHARS CONFIG_LVGL_TEXT_BREAK_CHARACTERS

#define LV_TXT_LINE_BREAK_LONG_LEN CONFIG_LVGL_TEXT_LINE_BREAK_LONG_LEN

#define LV_TXT_LINE_BREAK_LONG_PRE_MIN_LEN  \
	CONFIG_LVGL_TEXT_LINE_BREAK_LONG_PRE_MIN_LEN

#define LV_TXT_LINE_BREAK_LONG_POST_MIN_LEN \
	CONFIG_LVGL_TEXT_LINE_BREAK_LONG_POST_MIN_LEN

#define LV_TXT_COLOR_CMD CONFIG_LVGL_TEXT_COLOR_CMD

#ifdef CONFIG_LVGL_TEXT_USE_BIDI
#define LV_USE_BIDI 1
#else
#define LV_USE_BIDI 0
#endif

#if LV_USE_BIDI

#ifdef CONFIG_LVGL_TEXT_BIDI_DIR_LTR
#define LV_BIDI_BASE_DIR_DEF LV_BIDI_DIR_LTR
#elif defined(CONFIG_LVGL_TEXT_BIDI_DIR_RTL)
#define LV_BIDI_BASE_DIR_DEF LV_BIDI_DIR_RTL
#else
#define LV_BIDI_BASE_DIR_DEF LV_BIDI_DIR_AUTO
#endif

#endif

#if CONFIG_LVGL_TEXT_ARABIC_PERSIAN_CHARS
#define LV_USE_ARABIC_PERSIAN_CHARS 1
#else
#define LV_USE_ARABIC_PERSIAN_CHARS 0
#endif

#define LV_SPRINTF_CUSTOM 1

#if LV_SPRINTF_CUSTOM
#define LV_SPRINTF_INCLUDE "stdio.h"
#define lv_snprintf snprintf
#define lv_vsnprintf vsnprintf
#endif

/* LV_OBJ SETTINGS */

typedef void *lv_obj_user_data_t;

#ifdef CONFIG_LVGL_OBJ_REALIGN
#define LV_USE_OBJ_REALIGN 1
#else
#define LV_USE_OBJ_REALIGN 0
#endif

#if defined(CONFIG_LVGL_EXT_CLICK_AREA_OFF)
#define LV_USE_EXT_CLICK_AREA  LV_EXT_CLICK_AREA_OFF
#elif defined(CONFIG_LVGL_EXT_CLICK_AREA_TINY)
#define LV_USE_EXT_CLICK_AREA  LV_EXT_CLICK_AREA_TINY
#elif defined(CONFIG_LVGL_EXT_CLICK_AREA_FULL)
#define LV_USE_EXT_CLICK_AREA  LV_EXT_CLICK_AREA_FULL
#endif

/* LV OBJ X USAGE */

#ifdef CONFIG_LVGL_OBJ_ARC
#define LV_USE_ARC 1
#else
#define LV_USE_ARC 0
#endif

#ifdef CONFIG_LVGL_OBJ_BAR
#define LV_USE_BAR 1
#else
#define LV_USE_BAR 0
#endif

#ifdef CONFIG_LVGL_OBJ_BUTTON
#define LV_USE_BTN 1
#else
#define LV_USE_BTN 0
#endif

#ifdef CONFIG_LVGL_OBJ_BUTTON_MATRIX
#define LV_USE_BTNMATRIX 1
#else
#define LV_USE_BTNMATRIX 0
#endif

#ifdef CONFIG_LVGL_OBJ_CALENDAR
#define LV_USE_CALENDAR 1
#else
#define LV_USE_CALENDAR 0
#endif

#ifdef CONFIG_LVGL_OBJ_CANVAS
#define LV_USE_CANVAS 1
#else
#define LV_USE_CANVAS 0
#endif

#ifdef CONFIG_LVGL_OBJ_CHECK_BOX
#define LV_USE_CHECKBOX 1
#else
#define LV_USE_CHECKBOX 0
#endif

#ifdef CONFIG_LVGL_OBJ_CHART
#define LV_USE_CHART 1
#else
#define LV_USE_CHART 0
#endif
#if LV_USE_CHART
#define LV_CHART_AXIS_TICK_LABEL_MAX_LEN \
	CONFIG_LVGL_OBJ_CHART_AXIS_TICK_LABEL_MAX_LEN
#endif

#ifdef CONFIG_LVGL_OBJ_CONTAINER
#define LV_USE_CONT 1
#else
#define LV_USE_CONT 0
#endif

#ifdef CONFIG_LVGL_OBJ_COLOR_PICKER
#define LV_USE_CPICKER 1
#else
#define LV_USE_CPICKER 0
#endif

#ifdef CONFIG_LVGL_OBJ_DROP_DOWN_LIST
#define LV_USE_DROPDOWN 1
#else
#define LV_USE_DROPDOWN 0
#endif

#if LV_USE_DROPDOWN != 0
#define LV_DDLIST_DEF_ANIM_TIME	CONFIG_LVGL_OBJ_DROP_DOWN_LIST_ANIM_TIME
#endif

#ifdef CONFIG_LVGL_OBJ_GAUGE
#define LV_USE_GAUGE 1
#else
#define LV_USE_GAUGE 0
#endif

#ifdef CONFIG_LVGL_OBJ_IMAGE
#define LV_USE_IMG 1
#else
#define LV_USE_IMG 0
#endif

#ifdef CONFIG_LVGL_OBJ_IMG_BUTTON
#define LV_USE_IMGBTN 1
#else
#define LV_USE_IMGBTN 0
#endif

#if LV_USE_IMGBTN
#ifdef CONFIG_LVGL_OBJ_IMG_BUTTON_TILED
#define LV_IMGBTN_TILED 1
#else
#define LV_IMGBTN_TILED 0
#endif
#endif

#ifdef CONFIG_LVGL_OBJ_KEYBOARD
#define LV_USE_KEYBOARD 1
#else
#define LV_USE_KEYBOARD 0
#endif

#ifdef CONFIG_LVGL_OBJ_LABEL
#define LV_USE_LABEL 1
#else
#define LV_USE_LABEL 0
#endif

#if LV_USE_LABEL != 0
#define LV_LABEL_DEF_SCROLL_SPEED CONFIG_LVGL_OBJ_LABEL_SCROLL_SPEED
#define LV_LABEL_WAIT_CHAR_COUNT \
	CONFIG_LVGL_OBJ_LABEL_WAIT_CHAR_COUNT

#ifdef CONFIG_LVGL_OBJ_LABEL_TEXT_SEL
#define LV_LABEL_TEXT_SEL 1
#else
#define LV_LABEL_TEXT_SEL 0
#endif

#ifdef CONFIG_LVGL_OBJ_LABEL_LONG_TXT_HINT
#define LV_LABEL_LONG_TXT_HINT 1
#else
#define LV_LABEL_LONG_TXT_HINT 0
#endif

#endif

#ifdef CONFIG_LVGL_OBJ_LED
#define LV_USE_LED 1
#else
#define LV_USE_LED 0
#endif

#if LV_USE_LED != 0
#define LV_LED_BRIGHT_MIN CONFIG_LVGL_OBJ_LED_BRIGHT_MIN
#define LV_LED_BRIGHT_MAX CONFIG_LVGL_OBJ_LED_BRIGHT_MAX
#endif

#ifdef CONFIG_LVGL_OBJ_LINE
#define LV_USE_LINE 1
#else
#define LV_USE_LINE 0
#endif

#ifdef CONFIG_LVGL_OBJ_LIST
#define LV_USE_LIST 1
#else
#define LV_USE_LIST 0
#endif

#if LV_USE_LIST != 0
#define LV_LIST_DEF_ANIM_TIME CONFIG_LVGL_OBJ_LIST_DEF_ANIM_TIME
#endif

#ifdef CONFIG_LVGL_OBJ_LINE_METER
#define LV_USE_LINEMETER 1
#else
#define LV_USE_LINEMETER 0
#endif

#if LV_USE_LINEMETER != 0

#if defined(CONFIG_LVGL_OBJ_LINE_METER_PRECISE_NO_EXTRA)
#define LV_LINEMETER_PRECISE 0
#elif defined(CONFIG_LVGL_OBJ_LINE_METER_PRECISE_SOME_EXTRA)
#define LV_LINEMETER_PRECISE 1
#elif defined(CONFIG_LVGL_OBJ_LINE_METER_PRECISE_BEST)
#define LV_LINEMETER_PRECISE 2
#endif

#endif

#ifdef CONFIG_LVGL_OBJ_OBJMASK
#define LV_USE_OBJMASK 1
#else
#define LV_USE_OBJMASK 0
#endif

#ifdef CONFIG_LVGL_OBJ_MSG_BOX
#define LV_USE_MSGBOX 1
#else
#define LV_USE_MSGBOX 0
#endif

#ifdef CONFIG_LVGL_OBJ_PAGE
#define LV_USE_PAGE 1
#else
#define LV_USE_PAGE 0
#endif

#if LV_USE_PAGE != 0
#define LV_PAGE_DEF_ANIM_TIME CONFIG_LVGL_OBJ_PAGE_DEF_ANIM_TIME
#endif

#ifdef CONFIG_LVGL_OBJ_SPINNER
#define LV_USE_SPINNER 1
#else
#define LV_USE_SPINNER 0
#endif

#if LV_USE_SPINNER != 0

#define LV_SPINNER_DEF_ARC_LENGTH CONFIG_LVGL_OBJ_SPINNER_DEF_ARC_LENGTH
#define LV_SPINNER_DEF_SPIN_TIME CONFIG_LVGL_OBJ_SPINNER_DEF_SPIN_TIME

#if defined(CONFIG_LVGL_OBJ_SPINNER_DEF_ANIM_SPINNING_ARC)
#define LV_SPINNER_DEF_ANIM LV_SPINNER_TYPE_SPINNING_ARC
#elif defined(CONFIG_LVGL_OBJ_SPINNER_DEF_ANIM_FILLSPIN_ARC)
#define LV_SPINNER_DEF_ANIM LV_SPINNER_TYPE_FILLSPIN_ARC
#elif defined(CONFIG_LVGL_OBJ_SPINNER_DEF_ANIM_CONSTANT_ARC)
#define LV_SPINNER_DEF_ANIM LV_SPINNER_TYPE_CONSTANT_ARC
#endif

#endif

#ifdef CONFIG_LVGL_OBJ_ROLLER
#define LV_USE_ROLLER 1
#else
#define LV_USE_ROLLER 0
#endif

#if LV_USE_ROLLER != 0
#define LV_ROLLER_DEF_ANIM_TIME	CONFIG_LVGL_OBJ_ROLLER_ANIM_TIME
#define LV_ROLLER_INF_PAGES	CONFIG_LVGL_OBJ_ROLLER_INF_PAGES
#endif

#ifdef CONFIG_LVGL_OBJ_SLIDER
#define LV_USE_SLIDER 1
#else
#define LV_USE_SLIDER 0
#endif

#ifdef CONFIG_LVGL_OBJ_SPINBOX
#define LV_USE_SPINBOX 1
#else
#define LV_USE_SPINBOX 0
#endif

#ifdef CONFIG_LVGL_OBJ_SWITCH
#define LV_USE_SWITCH 1
#else
#define LV_USE_SWITCH 0
#endif

#ifdef CONFIG_LVGL_OBJ_TEXT_AREA
#define LV_USE_TEXTAREA 1
#else
#define LV_USE_TEXTAREA 0
#endif

#if LV_USE_TEXTAREA != 0
#define LV_TA_DEF_CURSOR_BLINK_TIME \
	CONFIG_LVGL_OBJ_TEXT_AREA_CURSOR_BLINK_TIME
#define LV_TA_DEF_PWD_SHOW_TIME \
	CONFIG_LVGL_OBJ_TEXT_AREA_PWD_SHOW_TIME
#endif

#ifdef CONFIG_LVGL_OBJ_TABLE
#define LV_USE_TABLE 1
#else
#define LV_USE_TABLE 0
#endif

#if LV_USE_TABLE
#define LV_TABLE_COL_MAX CONFIG_LVGL_OBJ_TABLE_COLUMN_MAX
#endif

#ifdef CONFIG_LVGL_OBJ_TAB_VIEW
#define LV_USE_TABVIEW 1
#else
#define LV_USE_TABVIEW 0
#endif

#if LV_USE_TABVIEW != 0
#define LV_TABVIEW_DEF_ANIM_TIME CONFIG_LVGL_OBJ_TAB_VIEW_ANIMATION_TIME
#endif

#ifdef CONFIG_LVGL_OBJ_TILE_VIEW
#define LV_USE_TILEVIEW 1
#else
#define LV_USE_TILEVIEW 0
#endif

#if LV_USE_TILEVIEW
#define LV_TILEVIEW_DEF_ANIM_TIME CONFIG_LVGL_OBJ_TILE_VIEW_ANIMATION_TIME
#endif

#ifdef CONFIG_LVGL_OBJ_WINDOW
#define LV_USE_WIN 1
#else
#define LV_USE_WIN 0
#endif

#endif /* ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_ */
