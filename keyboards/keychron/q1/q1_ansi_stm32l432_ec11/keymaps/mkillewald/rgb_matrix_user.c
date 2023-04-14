/* Copyright 2023 @ Mike Killewald
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

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "rgb_matrix_user.h"
#include "keymap_user.h"
#include "keymap_user_config.h"

extern uint8_t factory_reset_count;
extern enum {
    LED_TEST_MODE_OFF,
    LED_TEST_MODE_WHITE,
    LED_TEST_MODE_RED,
    LED_TEST_MODE_GREEN,
    LED_TEST_MODE_BLUE,
    LED_TEST_MODE_MAX
}led_test_mode;

static bool is_suspended = false;
extern bool win_mode;

keypos_t led_index_key_position[RGB_MATRIX_LED_COUNT];


void suspend_power_down_user(void) {
    // code will run multiple times while keyboard is suspended
    is_suspended = true;
}

void suspend_wakeup_init_user(void) {
    // code will run on keyboard wakeup
    is_suspended = false;
}

void rgb_matrix_init_user(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index != NO_LED) {
                led_index_key_position[led_index] = (keypos_t){.row = row, .col = col};
            }
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (is_suspended || led_test_mode || factory_reset_count
        || (!win_mode && !user_config_get_enable_mac_base())
        || (win_mode && !user_config_get_enable_win_base())) {
        return false;
    }

    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case MAC_BASE:
        case WIN_BASE:
            rgb_matrix_set_cyber_colors();
            break;
    }
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if(!rgb_matrix_indicators_advanced_keychron(led_min, led_max)) {
        return false;
    }

    if (led_test_mode || factory_reset_count) { return false; }

    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case MAC_BASE:
        case WIN_BASE:
#ifdef CAPS_LOCK_INDICATOR_COLOR
            if (host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_caps_lock_indicator, CAPS_LOCK_INDICATOR_COLOR);
            }
#endif
#ifdef CAPS_WORD_INDICATOR_COLOR
            if (is_caps_word_on()) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_caps_word_indicator, CAPS_WORD_INDICATOR_COLOR);
            }
#endif
            break;
        case MAC_FN:
        case WIN_FN:
#ifdef FN1_LAYER_COLOR
            if (user_config_get_fn_layer_color_enable()) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_not_transparent, FN1_LAYER_COLOR);
            }
#endif
            if (user_config_get_fn_layer_transparent_keys_off()) {
                rgb_matrix_set_color_by_keycode(led_min, led_max, current_layer, is_transparent, RGB_OFF);
            }
            break;
    }
    return false;
}

void rgb_matrix_set_cyber_colors(void) {
    // modifier keys: keys at outside edge of board
    //uint8_t modkeys[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 28, 29, 30, 43, 44, 45, 57, 58, 59, 70, 72, 73, 74, 76, 77, 78};

    //modifier keys: keys at top and right side of board
    uint8_t modkeys[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 29, 44, 58};
    for (uint8_t i = 0; i < sizeof(modkeys)/sizeof(modkeys[0]); i++) {
        rgb_matrix_set_color(modkeys[i], RGB_CYBERDARK);
    }

    // accent keys: Esc, arrow keys
    uint8_t accentkeys[] = {0, 71, 79, 80, 81};
    for (uint8_t i = 0; i < sizeof(accentkeys)/sizeof(accentkeys[0]); i++) {
        rgb_matrix_set_color(accentkeys[i], RGB_CYBERPINK);
    }

    // WASD
    /*uint8_t wasdkeys[] = {32, 46, 47 ,48};
    for (uint8_t i = 0; i < sizeof(wasdkeys)/sizeof(wasdkeys[0]); i++) {
        rgb_matrix_set_color(wasdkeys[i], RGB_CYBERPINK);
    }*/
}

void rgb_matrix_set_color_by_keycode(uint8_t led_min, uint8_t led_max, uint8_t layer, bool (*is_keycode)(uint16_t), uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = led_min; i < led_max; i++) {
        uint16_t keycode = keymap_key_to_keycode(layer, led_index_key_position[i]);
        if ((*is_keycode)(keycode)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

bool is_caps_lock_indicator(uint16_t keycode) {
    bool indicator = keycode == KC_CAPS;

    if (user_config_get_caps_lock_light_tab()) {
        indicator = keycode == KC_TAB || keycode == KC_CAPS;
    }

    if (user_config_get_caps_lock_light_alphas()) {
        return (KC_A <= keycode && keycode <= KC_Z) || indicator;
    } else {
        return indicator;
    }
}

bool is_caps_word_indicator(uint16_t keycode) {
    bool indicator = keycode == KC_LSFT;
#ifdef CAPS_WORD_LIGHT_LOWER_LEFT_CORNER
    indicator = keycode == KC_LSFT || keycode == KC_LCTL || keycode == KC_LOPT;
#endif
    return indicator;
}

bool is_transparent(uint16_t keycode) { return keycode == KC_TRNS; }
bool is_not_transparent(uint16_t keycode) { return keycode != KC_TRNS; }
