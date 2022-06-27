<<<<<<< HEAD
<<<<<<<< HEAD:keyboards/keychron/v4/v4_ansi_stm32l432/config.h
/* Copyright 2021 @ Keychron (https://www.keychron.com)
========
/*
 * Copyright 2022 Uthol
>>>>>>>> playground_new:keyboards/handwired/uthol/rev1/config.h
=======
/* Copyright 2021 @ Keychron (https://www.keychron.com)
>>>>>>> playground_new
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

<<<<<<< HEAD
<<<<<<<< HEAD:keyboards/keychron/v4/v4_ansi_stm32l432/config.h
/* USB Device descriptor parameter */
#define PRODUCT_ID 0x0340
#define DEVICE_VER 0x0101
=======
<<<<<<<< HEAD:keyboards/keychron/q8/q8.h
#include "quantum.h"

#if defined(KEYBOARD_keychron_q8_q8_ansi_stm32l432)
#    include "q8_ansi_stm32l432.h"
#elif defined(KEYBOARD_keychron_q8_q8_ansi_stm32l432_ec11)
#    include "q8_ansi_stm32l432_ec11.h"
#endif
========
/* USB Device descriptor parameter */
#define PRODUCT_ID 0x0340
#define DEVICE_VER 0x0102
>>>>>>> playground_new

/* RGB Matrix Configuration */
#define DRIVER_1_LED_TOTAL 61
#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL

/* Enable CapsLcok LED*/
#define CAPS_LOCK_LED_INDEX 28
<<<<<<< HEAD
========
#include "config_common.h"

#define DEVICE_VER 0x0001
#define PRODUCT_ID 0x67F3
#define PRODUCT UtholOne

/* Uthol PCB default pin-out */
#define MATRIX_ROW_PINS { D1, D0, D4, C6, D7 }
#define MATRIX_COL_PINS { D3, B6, B2, B3, B1, F7, F6, F5, F4, B5, B4, D2 }
#define UNUSED_PINS
>>>>>>>> playground_new:keyboards/handwired/uthol/rev1/config.h
=======
>>>>>>>> playground_new:keyboards/keychron/v4/v4_ansi_stm32l432/config.h
>>>>>>> playground_new
