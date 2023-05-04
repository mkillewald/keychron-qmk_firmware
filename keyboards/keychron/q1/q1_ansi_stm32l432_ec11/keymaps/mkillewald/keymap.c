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
#include "keymap_user.h"
#include "keymap_user_config.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif

// clang-format off

enum my_bootloader_state {
    BOOTLOADER_INACTIVE,
    BOOTLOADER_PRESSED,
    BOOTLOADER_WAIT,
    BOOTLOADER_DO
} bootloader_state;

enum my_keycodes {
    KC_LIGHT_TAB_TOGGLE = QK_USER_0,
    KC_LIGHT_ALPHAS_TOGGLE,
    KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE,
    KC_FN_LAYER_COLOR_TOGGLE,
    KC_LOCK_BLANK_MAC
};

#define KC_LTTOG KC_LIGHT_TAB_TOGGLE
#define KC_LATOG KC_LIGHT_ALPHAS_TOGGLE
#define KC_TKTOG KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE
#define KC_FCTOG KC_FN_LAYER_COLOR_TOGGLE
#define KC_LBMAC KC_LOCK_BLANK_MAC

static bool win_mode;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        KC_LBMAC, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,     KC_F11,   KC_F12,   _______,            RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  QK_BOOT,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,    _______,    _______,            _______,            _______,
        AC_TOGG,            KC_LTTOG,  KC_LATOG, KC_TKTOG, KC_FCTOG, _______,  NK_TOGG,  _______, LCAG(KC_W), LCAG(KC_D), _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                  _______,    _______,  _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  QK_BOOT,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        AC_TOGG,            KC_LTTOG, KC_LATOG, KC_TKTOG, KC_FCTOG, _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
};

// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE

void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

void keyboard_post_init_user(void) {
    user_config_read_eeprom();

#ifdef AUTOCORRECT_OFF_AT_STARTUP
    // toggle autocorrect off at startup
    if (autocorrect_is_enabled()) { autocorrect_toggle(); }
#endif
}

void housekeeping_task_user(void) {
    switch(bootloader_state) {
        case BOOTLOADER_DO:
            // bootloader was pressed two frames ago. RGB should now be off,
            // so we can call the bootloader.
            reset_keyboard();
            break;
        case BOOTLOADER_WAIT:
            // bootloader was pressed on previous frame, we wait this frame and
            // set flag to do bootloader at end of next frame. For some reason, my
            // Q2 needed this extra wait frame.
            bootloader_state = BOOTLOADER_DO;
            break;
        case BOOTLOADER_PRESSED:
            // User pressed bootloader keycode and RGB was disabled earlier in this
            // frame. However RGB changes wont take place immediately, so we set a
            // flag here which will be caught at end of the next frame.
            bootloader_state = BOOTLOADER_WAIT;
            break;
        default:
            break;
    }

    housekeeping_task_keychron();
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (!dip_switch_update_keychron(index, active)) {
        return false;
    }
    
    win_mode = (index == 0 && active ? true : false);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case MAC_BASE:
            // load mac base settings
            rgb_matrix_enable_noeeprom();
            rgb_matrix_reload_from_eeprom();

            // check disable
            if (!user_config_get_enable_mac_base()) {
                rgb_matrix_disable_noeeprom();
            }
            break;
        case WIN_BASE:
            // load win base settings
            rgb_matrix_enable_noeeprom();
            rgb_matrix_mode_noeeprom(user_config_get_mode_win_base());
            rgb_matrix_set_speed_noeeprom(user_config_get_spd_win_base());
            rgb_matrix_sethsv_noeeprom(user_config_get_hsv_win_base().h,
                                       user_config_get_hsv_win_base().s,
                                       user_config_get_hsv_win_base().v);

            // check disable
            if (!user_config_get_enable_win_base()) {
                rgb_matrix_disable_noeeprom();
            }
            break;
        default:
            break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (process_record_keychron(keycode, record)) {
        switch (keycode) {
            case QK_BOOT:
                // We want to turn off LEDs before calling bootloader, so here
                // we call rgb_matrix_disable_noeeprom() and set a flag because
                // the LEDs won't be updated until the next frame.
                if (record->event.pressed) {
                    rgb_matrix_disable_noeeprom();
                    bootloader_state = BOOTLOADER_PRESSED;
                }
                return false;  // Skip all further processing of this key
            case RGB_TOG:
                if (record->event.pressed) {
                    rgb_matrix_toggle_noeeprom();
                    if (win_mode) {
                        user_config_toggle_enable_win_base();
                    } else {
                        user_config_toggle_enable_mac_base();
                    }
                }
                return false;  // Skip all further processing of this key
            case RGB_MOD:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_step_noeeprom();
                        user_config_set_mode_win_base(rgb_matrix_get_mode());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_RMOD:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_step_reverse_noeeprom();
                        user_config_set_mode_win_base(rgb_matrix_get_mode());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_HUI:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_increase_hue_noeeprom();
                        user_config_set_hsv_win_base(rgb_matrix_get_hsv());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_HUD:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_decrease_hue_noeeprom();
                        user_config_set_hsv_win_base(rgb_matrix_get_hsv());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_SAI:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_increase_sat_noeeprom();
                        user_config_set_hsv_win_base(rgb_matrix_get_hsv());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_SAD:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_decrease_sat_noeeprom();
                        user_config_set_hsv_win_base(rgb_matrix_get_hsv());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_VAI:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_increase_val_noeeprom();
                        user_config_set_hsv_win_base(rgb_matrix_get_hsv());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_VAD:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_decrease_val_noeeprom();
                        user_config_set_hsv_win_base(rgb_matrix_get_hsv());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_SPI:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_increase_speed_noeeprom();
                        user_config_set_spd_win_base(rgb_matrix_get_speed());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case RGB_SPD:
                if (win_mode) {
                    if (record->event.pressed) {
                        rgb_matrix_decrease_speed_noeeprom();
                        user_config_set_spd_win_base(rgb_matrix_get_speed());
                    }
                    return false;  // Skip all further processing of this key
                } else {
                    return true; // Allow further processing of this key
                }
            case KC_LIGHT_TAB_TOGGLE:
                if (record->event.pressed) {
                    user_config_toggle_caps_lock_light_tab();
                }
                return false;  // Skip all further processing of this key
            case KC_LIGHT_ALPHAS_TOGGLE:
                if (record->event.pressed) {
                    user_config_toggle_caps_lock_light_alphas();
                }
                return false;  // Skip all further processing of this key
            case KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE:
                if (record->event.pressed) {
                    user_config_toggle_fn_layer_transparent_keys_off();
                }
                return false;  // Skip all further processing of this key
            case KC_FN_LAYER_COLOR_TOGGLE:
                if (record->event.pressed) {
                    user_config_toggle_fn_layer_color_enable();
                }
                return false;  // Skip all further processing of this key
            case KC_LOCK_BLANK_MAC:
                if (record->event.pressed) {
                    send_string(SS_LCTL(SS_LGUI("q")) SS_DELAY(225) SS_TAP(X_ESC));
                }
                return false;  // Skip all further processing of this key
            default:
                return true;  // Process all other keycodes normally
        }
    }
    return true;
}