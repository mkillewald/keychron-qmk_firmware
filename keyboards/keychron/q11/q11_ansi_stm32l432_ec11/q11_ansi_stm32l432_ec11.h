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

#pragma once

#include "quantum.h"

#define XXX KC_NO

// clang-format off

#define LAYOUT_ansi_91( \
    L00, L01, L02, L03, L04, L05, L06, L07, R00, R01, R02, R03, R04, R05, R06, R07, R08, \
    L10, L11, L12, L13, L14, L15, L16, L17, R10, R11, R12, R13, R14, R15, R16,      R18, \
    L20, L21, L22, L23, L24, L26, L27, R20, R21, R22, R23, R24, R25, R26, R27,      R28, \
    L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35,      R37,      R38, \
    L40, L42,      L43, L44, L45, L46, L47, R40, R41, R42, R43, R44,      R45, R47,      \
    L50, L51, L52, L53, L54,      L56,           R51,      R52, R53, R54, R56, R57, R58  \
) { \
    { L00, L01, L02, L03, L04, L05, L06, L07, XXX }, \
    { L10, L11, L12, L13, L14, L15, L16, L17, XXX }, \
    { L20, L21, L22, L23, L24, XXX, L26, L27, XXX }, \
    { L30, L31, L32, L33, L34, L35, L36, XXX, XXX }, \
    { L40, XXX, L42, L43, L44, L45, L46, L47, XXX }, \
    { L50, L51, L52, L53, L54, XXX, L56, XXX, XXX }, \
    { R00, R01, R02, R03, R04, R05, R06, R07, R08 }, \
    { R10, R11, R12, R13, R14, R15, R16, XXX, R18 }, \
    { R20, R21, R22, R23, R24, R25, R26, R27, R28 }, \
    { R30, R31, R32, R33, R34, R35, XXX, R37, R38 }, \
    { R40, R41, R42, R43, R44, R45, XXX, R47, XXX }, \
    { XXX, R51, R52, R53, R54, XXX, R56, R57, R58 }  \
}
