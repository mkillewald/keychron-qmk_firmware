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

#include "quantum.h"

// Mask out handedness diode to prevent it
// from keeping the keyboard awake
// - just mirroring `KC_NO` in the `LAYOUT`
//   macro to keep it simple
const matrix_row_t matrix_mask[] = {
    0b011111111,
    0b011111111,
    0b011111111,
    0b001111111,
    0b011111101,
    0b001011111,
    0b111111111,
    0b101111111,
    0b111111111,
    0b110111111,
    0b010111111,
    0b111011110,
};

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) {
        return false;
    }
    if (index == 0) {
        default_layer_set(1UL << (active ? 0 : 2));
    }
    return true;
}
#endif

void restart_usb_driver(USBDriver *usbp) {
    (void)usbp;
}
