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
        case MO(1):
        case MO(2):
        case MO(3):
        case MO(4):
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_0;
            } else {
                key_press_status &= ~KEY_PRESS_STEP_0;
                timer_3s_buffer = 0;
            }
            return true;
        case KC_J:
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_1;
                if (key_press_status == KEY_PRESS_FACTORY_RESET) {
                    timer_3s_buffer = sync_timer_read32() == 0 ? 1 : sync_timer_read32();
                }
            } else {
                key_press_status &= ~KEY_PRESS_STEP_1;
                timer_3s_buffer = 0;
            }
            return true;
        case KC_Z:
            if (record->event.pressed) {
                key_press_status |= KEY_PRESS_STEP_2;
                if (key_press_status == KEY_PRESS_FACTORY_RESET) {
                    timer_3s_buffer = sync_timer_read32() == 0 ? 1 : sync_timer_read32();
                }
            } else {
                key_press_status &= ~KEY_PRESS_STEP_2;
                timer_3s_buffer = 0;
            }
            return true;
        case KC_B:
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
        case KC_L:
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
