/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

#include "c2.h"

const matrix_row_t matrix_mask[] = {
    0b11111111111111111111,
    0b11111111111111111111,
    0b11111111111111111111,
    0b11111111111111111111,
    0b11111111111111111111,
    0b11111111111111101111,
};

#ifdef DIP_SWITCH_ENABLE

bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) {
        return false;
    }
    if (index == 0) {
        default_layer_set(1UL << (active ? 2 : 0));
    }
    return true;
}

#endif // DIP_SWITCH_ENABLE

#if defined(RGB_MATRIX_ENABLE) && (defined(NUM_LOCK_LED_INDEX) || defined(CAPS_LOCK_LED_INDEX) || defined(MAC_OS_LED_INDEX) || defined(WIN_OS_LED_INDEX))

void rgb_matrix_indicators_kb(void) {
#    if defined(CAPS_LOCK_LED_INDEX)
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, 255, 255, 255);
    } else {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, 0, 0, 0);
    }
#    endif // CAPS_LOCK_LED_INDEX
#    if defined(NUM_LOCK_LED_INDEX)
    if (host_keyboard_led_state().num_lock) {
        rgb_matrix_set_color(NUM_LOCK_LED_INDEX, 255, 255, 255);
    } else {
        rgb_matrix_set_color(NUM_LOCK_LED_INDEX, 0, 0, 0);
    }
#    endif // NUM_LOCK_LED_INDEX
#    if defined(MAC_OS_LED_INDEX)
    if (default_layer_state == (1 << 0)) {
        rgb_matrix_set_color(MAC_OS_LED_INDEX, 255, 255, 255);
    } else {
        rgb_matrix_set_color(MAC_OS_LED_INDEX, 0, 0, 0);
    }
#    endif // MAC_OS_LED_INDEX
#    if defined(WIN_OS_LED_INDEX)
    if (default_layer_state == (1 << 2)) {
        rgb_matrix_set_color(WIN_OS_LED_INDEX, 255, 255, 255);
    } else {
        rgb_matrix_set_color(WIN_OS_LED_INDEX, 0, 0, 0);
    }
#    endif // WIN_OS_LED_INDEX
}

#endif // RGB_MATRIX_ENABLE && CAPS_LOCK_LED_INDEX...
