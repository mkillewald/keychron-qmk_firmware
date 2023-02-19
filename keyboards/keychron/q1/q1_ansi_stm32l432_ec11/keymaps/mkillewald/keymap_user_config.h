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
 
 #pragma once
 
 typedef union {
  uint32_t raw;
  struct {
    bool caps_lock_light_tab :1;
    bool caps_lock_light_alphas :1;
    bool fn_layer_transparent_keys_off :1;
    bool fn_layer_color_enable :1;
  };
} user_config_t;

void user_config_read(void);
void user_config_write(void);
bool user_config_get_caps_lock_light_tab(void);
bool user_config_get_caps_lock_light_alphas(void);
bool user_config_get_fn_layer_transparent_keys_off(void);
bool user_config_get_fn_layer_color_enable(void);
void user_config_toggle_caps_lock_light_tab(void);
void user_config_toggle_caps_lock_light_alphas(void);
void user_config_toggle_fn_layer_transparent_keys_off(void);
void user_config_toggle_fn_layer_color_enable(void);