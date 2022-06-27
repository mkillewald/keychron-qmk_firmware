/* Copyright 2021 s-ol
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
#include "0xc_pad.h"

#ifdef RGB_MATRIX_ENABLE
<<<<<<< HEAD
#    define Q(...) __VA_ARGS__

led_config_t g_led_config = {
    // indices
    LAYOUT(0, 6, 1, 5, 7, 2, 4, 8, 11, 3, 9, 10),
    // phys position
    LED_LAYOUT(Q({96, 110}), Q({128, 110}), Q({80, 83}), Q({112, 83}), Q({144, 83}), Q({64, 55}), Q({96, 55}), Q({128, 55}), Q({160, 55}), Q({80, 28}), Q({112, 28}), Q({144, 28})),
    // flags
    LED_LAYOUT(4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4),
};
#    undef Q
=======
led_config_t g_led_config = { {
    // indices
    {     0,    6, KC_NO, KC_NO },
    {     1,    5,     7, KC_NO },
    {     2,    4,     8,    11 },
    { KC_NO,    3,     9,    10 }
}, {
    // phys position
    { 96, 110}, { 80, 83}, { 64,  55}, { 80, 28},
    { 96,  55}, {112, 83}, {128, 110}, {144, 83},
    {128,  55}, {112, 28}, {144,  28}, {160, 55}
}, {
    // flags
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };
>>>>>>> playground_new
#endif
