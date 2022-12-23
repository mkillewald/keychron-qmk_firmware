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

#include QMK_KEYBOARD_H
#include "keychron_common.h"

// clang-format off

enum layers {
    _BASE,
    _FN1,
    _RESERVED1,
    _RESERVED2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_numpad_6x5(
        KC_MUTE,   MO(_FN1), KC_ESC,  KC_BSPC,  KC_TAB,
        MACRO01,   KC_NUM,   KC_PSLS, KC_PAST,  KC_PMNS,
        MACRO02,   KC_P7,    KC_P8,   KC_P9,    KC_PPLS,
        MACRO03,   KC_P4,    KC_P5,   KC_P6,
        MACRO04,   KC_P1,    KC_P2,   KC_P3,    KC_PENT,
        MACRO05,   KC_P0,             KC_PDOT),

    [_FN1] = LAYOUT_numpad_6x5(
        RGB_TOG,   _______,  KC_MUTE, KC_VOLD,  KC_VOLU,
        MACRO01,   RGB_MOD,  RGB_VAI, RGB_HUI,  KC_DEL,
        MACRO02,   RGB_RMOD, RGB_VAD, RGB_HUD,  _______,
        MACRO03,   RGB_SAI,  RGB_SPI, KC_MPRV,
        MACRO04,   RGB_SAD,  RGB_SPD, KC_MPLY,  _______,
        MACRO05,   RGB_TOG,           KC_MNXT),

    [_RESERVED1] = LAYOUT_numpad_6x5(
        _______, _______,  _______, _______,  _______,
        _______, _______,  _______, _______,  _______,
        _______, _______,  _______, _______,  _______,
        _______, _______,  _______, _______,
        _______, _______,  _______, _______,  _______,
        _______, _______,           _______),

    [_RESERVED2] = LAYOUT_numpad_6x5(
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,  _______, _______,
        _______, _______,  _______, _______,   _______,
        _______, _______,           _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN1]       = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_RESERVED1] = { ENCODER_CCW_CW(_______, _______) },
    [_RESERVED2] = { ENCODER_CCW_CW(_______, _______) }
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if(!rgb_matrix_indicators_advanced_keychron(led_min, led_max)) {
        return false;
    }
    return true;
}
#endif
