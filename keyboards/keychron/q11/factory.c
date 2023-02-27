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
#include "split_util.h"

bool process_record_ft(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(1):
        case MO(2):
        case MO(3):
        case MO(4):
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_FN;
            } else {
                key_press_status &= ~KEY_PRESS_FN;
                timer_3s_buffer = 0;
            }
            return true;
        case KC_STEP_1:
#if defined(KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11)
            if (is_transport_connected() || !is_keyboard_left()) {
                return true;
            } else {
                skip_next_step = true;
            }
        case KC_STEP_5:
            if ((is_transport_connected() || is_keyboard_left()) && !skip_next_step) {
                return true;
            } else {
                skip_next_step = true;
            }
        case KC_STEP_9:
            if (!is_transport_connected() && !skip_next_step) {
                return true;
            }
            skip_next_step = false;
#endif // KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_1;
                if (key_press_status == KEY_PRESS_FACTORY_RESET) {
                    timer_3s_buffer = sync_timer_read32();
                }
            } else {
                key_press_status &= ~KEY_PRESS_STEP_1;
                timer_3s_buffer = 0;
            }
            return true;
        case KC_STEP_2:
#if defined(KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11)
            if (is_transport_connected() || !is_keyboard_left()) {
                return true;
            } else {
                skip_next_step = true;
            }
        case KC_STEP_6:
            if ((is_transport_connected() || is_keyboard_left()) && !skip_next_step) {
                return true;
            } else {
                skip_next_step = true;
            }
        case KC_STEP_A:
            if (!is_transport_connected() && !skip_next_step) {
                return true;
            }
            skip_next_step = false;
#endif // KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_2;
                if (key_press_status == KEY_PRESS_FACTORY_RESET) {
                    timer_3s_buffer = sync_timer_read32();
                }
            } else {
                key_press_status &= ~KEY_PRESS_STEP_2;
                timer_3s_buffer = 0;
            }
            return true;
        case KC_STEP_3:
#if defined(KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11)
        case KC_STEP_7:
#endif // KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_3;
                if (led_test_mode) {
                    if (++led_test_mode >= LED_TEST_MODE_MAX) {
                        led_test_mode = LED_TEST_MODE_WHITE;
                    }
                } else if (key_press_status == KEY_PRESS_LED_TEST) {
                    timer_3s_buffer = sync_timer_read32();
                }
            } else {
                key_press_status &= ~KEY_PRESS_STEP_3;
                timer_3s_buffer = 0;
            }
            return true;
        case KC_STEP_4:
#if defined(KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11)
        case KC_STEP_8:
#endif // KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_4;
                if (led_test_mode) {
                    led_test_mode = LED_TEST_MODE_OFF;
#if defined(KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11) && defined(RGB_MATRIX_ENABLE)
                    rgb_matrix_mode_noeeprom(led_state);
                    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
#endif
                } else if (key_press_status == KEY_PRESS_LED_TEST) {
#if defined(KEYBOARD_keychron_q11_q11_ansi_stm32l432_ec11) && defined(RGB_MATRIX_ENABLE)
                    led_state = rgb_matrix_get_mode();
                    hsv       = rgb_matrix_get_hsv();
#endif
                    timer_3s_buffer = sync_timer_read32();
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
