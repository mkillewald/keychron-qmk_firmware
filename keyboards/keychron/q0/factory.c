/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

#include "keychron_ft_common.h"

bool process_record_keychron_ft(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#if defined(FN_KEY1) || defined(FN_KEY2) || defined(FN_KEY3)
#    ifdef FN_KEY1
        case FN_KEY1: /* fall through */
#    endif
#    ifdef FN_KEY2
        case FN_KEY2:
#    endif
#    ifdef FN_KEY3
        case FN_KEY3:
#    endif
#endif
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_0;
            } else {
                key_press_status &= ~KEY_PRESS_STEP_0;
                timer_3s_buffer = 0;
            }
            return true;
        case RGB_SAD:
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_1;
                if (key_press_status == KEY_PRESS_FACTORY_RESET) {
                    timer_3s_buffer = sync_timer_read32() == 0 ? 1 : sync_timer_read32();
                } else {
                }
            } else {
                rgb_matrix_decrease_sat_noeeprom();
                key_press_status &= ~KEY_PRESS_STEP_1;
                timer_3s_buffer = 0;
            }
            return false; // Skip all further processing of this key
        case RGB_HUD:
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_2;
                if (key_press_status == KEY_PRESS_FACTORY_RESET) {
                    timer_3s_buffer = sync_timer_read32() == 0 ? 1 : sync_timer_read32();
                } else {
                }
            } else {
                rgb_matrix_decrease_hue_noeeprom();
                key_press_status &= ~KEY_PRESS_STEP_2;
                timer_3s_buffer = 0;
            }
            return false; // Skip all further processing of this key
        case KC_MPLY:
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_3;
                if (led_test_mode) {
                    if (++led_test_mode >= LED_TEST_MODE_MAX) {
                        led_test_mode = LED_TEST_MODE_WHITE;
                    }
                } else if (key_press_status == KEY_PRESS_LED_TEST) {
                    timer_3s_buffer = sync_timer_read32() == 0 ? 1 : sync_timer_read32();
                }
            } else {
                key_press_status &= ~KEY_PRESS_STEP_3;
                timer_3s_buffer = 0;
            }
            return true;
        case KC_DEL:
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_4;
                if (led_test_mode) {
                    led_test_mode = LED_TEST_MODE_OFF;
                } else if (key_press_status == KEY_PRESS_LED_TEST) {
                    timer_3s_buffer = sync_timer_read32() == 0 ? 1 : sync_timer_read32();
                }
            } else {
                key_press_status &= ~KEY_PRESS_STEP_4;
                timer_3s_buffer = 0;
            }
            return true;
        default:
            return true;
    }
}
