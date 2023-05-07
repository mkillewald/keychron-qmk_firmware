/* Copyright 2022 @ Mike Killewald (https://github.com/mkillewald)
 * Forked from keychron/common/keychron_ft_common.c
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

#include "quantum.h"

#define KEY_PRESS_STEP_0 (0x1 << 0)
#define KEY_PRESS_STEP_1 (0x1 << 1)
#define KEY_PRESS_STEP_2 (0x1 << 2)
#define KEY_PRESS_STEP_3 (0x1 << 3)
#define KEY_PRESS_STEP_4 (0x1 << 4)
#define KEY_PRESS_FACTORY_RESET (KEY_PRESS_STEP_0 | KEY_PRESS_STEP_1 | KEY_PRESS_STEP_2)
#define KEY_PRESS_LED_TEST (KEY_PRESS_STEP_0 | KEY_PRESS_STEP_3 | KEY_PRESS_STEP_4)
// clang-format off
enum {
    LED_TEST_MODE_OFF,
    LED_TEST_MODE_WHITE,
    LED_TEST_MODE_RED,
    LED_TEST_MODE_GREEN,
    LED_TEST_MODE_BLUE,
    LED_TEST_MODE_MAX
} led_test_mode;
// clang-format on

extern uint16_t key_press_status;
extern uint32_t timer_3s_buffer;
#ifdef SPLIT_KEYBOARD
#    ifdef RGB_MATRIX_ENABLE
extern uint8_t led_state;
extern uint8_t light_test_state;
extern HSV     hsv;
#    endif
#endif

void housekeeping_task_keychron_ft(void);
bool process_record_keychron_ft(uint16_t keycode, keyrecord_t *record);
bool rgb_matrix_indicators_advanced_keychron(uint8_t led_min, uint8_t led_max);
