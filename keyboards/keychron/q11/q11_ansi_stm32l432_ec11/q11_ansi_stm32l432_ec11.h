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
    K00, K01, K02, K03, K04, K05, K06, K07, K60, K61, K62, K63, K64, K65, K66, K67, K68, \
    K10, K11, K12, K13, K14, K15, K16, K17, K70, K71, K72, K73, K74, K75, K76,      K78, \
    K20, K21, K22, K23, K24, K26, K27, K80, K81, K82, K83, K84, K85, K86, K87,      K88, \
    K30, K31, K32, K33, K34, K35, K36, K90, K91, K92, K93, K94, K95,      K97,      K98, \
    K40, K42,      K43, K44, K45, K46, K47, KA0, KA1, KA2, KA3, KA4,      KA5, KA7,      \
    K50, K51, K52, K53, K54,      K56,           KB1,      KB2, KB3, KB4, KB6, KB7, KB8  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, XXX }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, XXX }, \
    { K20, K21, K22, K23, K24, XXX, K26, K27, XXX }, \
    { K30, K31, K32, K33, K34, K35, K36, XXX, XXX }, \
    { K40, XXX, K42, K43, K44, K45, K46, K47, XXX }, \
    { K50, K51, K52, K53, K54, XXX, K56, XXX, XXX }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68 }, \
    { K70, K71, K72, K73, K74, K75, K76, XXX, K78 }, \
    { K80, K81, K82, K83, K84, K85, K86, K87, K88 }, \
    { K90, K91, K92, K93, K94, K95, XXX, K97, K98 }, \
    { KA0, KA1, KA2, KA3, KA4, KA5, XXX, KA7, XXX }, \
    { XXX, KB1, KB2, KB3, KB4, XXX, KB6, KB7, KB8 }  \
}
