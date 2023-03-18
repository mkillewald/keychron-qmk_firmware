<<<<<<< HEAD
/* Copyright 2022 @ Keychron (https://www.keychron.com)
=======
/* Copyright 2023 @ Keychron (https://www.keychron.com)
>>>>>>> temp
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

#include "quantum.h"

<<<<<<< HEAD
=======
// clang-format off
>>>>>>> temp
const matrix_row_t matrix_mask[] = {
    0b111111111111111111,
    0b111111111111111111,
    0b111111111111111111,
    0b111111111111111111,
    0b111111111111111111,
    0b111111111111101111,
};
<<<<<<< HEAD

#ifdef DIP_SWITCH_ENABLE

=======
// clang-format on
#ifdef DIP_SWITCH_ENABLE
>>>>>>> temp
bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) {
        return false;
    }
    if (index == 0) {
        default_layer_set(1UL << (active ? 2 : 0));
    }
    return true;
}
<<<<<<< HEAD

#endif  // DIP_SWITCH_ENABLE

#if defined(RGB_MATRIX_ENABLE) && (defined(CAPS_LOCK_LED_INDEX) || defined(NUM_LOCK_LED_INDEX))

#    define CAPS_NUM_LOCK_MAX_BRIGHTNESS 0xFF
#    ifdef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#        undef CAPS_NUM_LOCK_MAX_BRIGHTNESS
#        define CAPS_NUM_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    endif

#    define CAPS_NUM_LOCK_VAL_STEP 8
#    ifdef RGB_MATRIX_VAL_STEP
#        undef CAPS_NUM_LOCK_VAL_STEP
#        define CAPS_NUM_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#    endif

extern void rgb_matrix_update_pwm_buffers(void);

static uint8_t light_brightness_get(void) {
    uint8_t value = rgb_matrix_get_val();
    if (value < CAPS_NUM_LOCK_VAL_STEP) {
        value = CAPS_NUM_LOCK_VAL_STEP;
    } else if (value < (CAPS_NUM_LOCK_MAX_BRIGHTNESS - CAPS_NUM_LOCK_VAL_STEP)) {
        value += CAPS_NUM_LOCK_VAL_STEP; // one step more than current brightness
    } else {
        value = CAPS_NUM_LOCK_MAX_BRIGHTNESS;
    }

    return value;
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
#    if defined(CAPS_LOCK_LED_INDEX)
    if (host_keyboard_led_state().caps_lock) {
        uint8_t v = light_brightness_get();
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, v, v, v); // white, with the adjusted brightness
    }
#    endif
#    if defined(NUM_LOCK_LED_INDEX)
    if (host_keyboard_led_state().num_lock) {
        uint8_t v = light_brightness_get();
        rgb_matrix_set_color(NUM_LOCK_LED_INDEX, v, v, v); // white, with the adjusted brightness
    }
#    endif
    return true;
}

void rgb_matrix_indicators_none_kb(void) {
    rgb_matrix_indicators_kb();
    rgb_matrix_update_pwm_buffers();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    if (rgb_matrix_is_enabled()
#    if defined(ENABLE_RGB_MATRIX_RAINDROPS)
        && (rgb_matrix_get_mode() != RGB_MATRIX_RAINDROPS)
#    endif
#    if defined(ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS)
        && (rgb_matrix_get_mode() != RGB_MATRIX_JELLYBEAN_RAINDROPS)
#    endif
#    if defined(ENABLE_RGB_MATRIX_PIXEL_RAIN)
        && (rgb_matrix_get_mode() != RGB_MATRIX_PIXEL_RAIN)
#    endif
    ) {
        return res;
    }

    if (res) {
#    if defined(CAPS_LOCK_LED_INDEX)
        if (led_state.caps_lock) {
            uint8_t v = light_brightness_get();
            rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, v, v, v);
        } else {
            rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, 0, 0, 0);
        }
#    endif // CAPS_LOCK_LED_INDEX
#    if defined(NUM_LOCK_LED_INDEX)
        if (led_state.num_lock) {
            uint8_t v = light_brightness_get();
            rgb_matrix_set_color(NUM_LOCK_LED_INDEX, v, v, v);
        } else {
            rgb_matrix_set_color(NUM_LOCK_LED_INDEX, 0, 0, 0);
        }
#    endif // NUM_LOCK_LED_INDEX
        rgb_matrix_update_pwm_buffers();
    }

    return res;
}

#endif // CAPS_LOCK_LED_INDEX
=======
#endif

#if defined(RGB_MATRIX_ENABLE) && (defined(CAPS_LOCK_LED_INDEX) || defined(NUM_LOCK_LED_INDEX))
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);
#    if defined(CAPS_LOCK_LED_INDEX)
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
        }
    }
#    endif // CAPS_LOCK_LED_INDEX
#    if defined(NUM_LOCK_LED_INDEX)
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(NUM_LOCK_LED_INDEX, 0, 0, 0);
        }
    }
#    endif // NUM_LOCK_LED_INDEX
    return true;
}
#endif
>>>>>>> temp
