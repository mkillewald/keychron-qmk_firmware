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
#include "keymap_user_config.h"

user_config_t user_config;

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.caps_lock_light_tab = false;
    user_config.caps_lock_light_alphas = false;
    user_config.fn_layer_transparent_keys_off = true;
    user_config.fn_layer_color_enable = false;
    eeconfig_update_user(user_config.raw);
}

void user_config_read(void) {
    user_config.raw = eeconfig_read_user();
}

bool user_config_get_caps_lock_light_tab(void) {
    return user_config.caps_lock_light_tab;
}

bool user_config_get_caps_lock_light_alphas(void) {
    return user_config.caps_lock_light_alphas;
}

bool user_config_get_fn_layer_transparent_keys_off(void) {
    return user_config.fn_layer_transparent_keys_off;
}

bool user_config_get_fn_layer_color_enable(void) {
    return user_config.fn_layer_color_enable;
}