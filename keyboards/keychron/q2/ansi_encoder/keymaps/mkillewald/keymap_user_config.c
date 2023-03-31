/* Copyright 2023 @ Mike Killewald (https://github.com/mkillewald)
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

uint8_t user_config;

void eeconfig_init_user(void) {
    user_config = 255;
    eeconfig_update_user_datablock(&user_config);
}

void user_config_read(void) {
    eeconfig_read_user_datablock(&user_config);
}

void user_config_write(void) {
    eeconfig_update_user_datablock(&user_config);
}

uint8_t user_config_get_data(void) { return user_config; }
void user_config_set_data(uint8_t data) {
    user_config = data;
    user_config_write();
}