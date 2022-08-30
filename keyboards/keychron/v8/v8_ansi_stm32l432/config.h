/*
 * @Author: lalalademaxiya1 66767061+lalalademaxiya1@users.noreply.github.com
 * @Date: 2022-08-23 23:29:21
 * @LastEditors: lalalademaxiya1 66767061+lalalademaxiya1@users.noreply.github.com
 * @LastEditTime: 2022-08-29 16:39:09
 * @FilePath: /qmk_firmware/keyboards/keychron/v8/v8_ansi_stm32l432/config.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* USB Device descriptor parameter */
#define PRODUCT_ID 0x0380
#define DEVICE_VER 0x0100

/* RGB Matrix Configuration */
#define DRIVER_1_LED_TOTAL 35
#define DRIVER_2_LED_TOTAL 34
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 30

// #define OLED_TIMEOUT 0
// #define OLED_DISPLAY_128X64
