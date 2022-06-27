<<<<<<<< HEAD:keyboards/handwired/uthol/rev1/config.h
/*
 * Copyright 2022 Uthol
========
/* Copyright 2021 Stefan Kerkmann
>>>>>>>> playground_new:tests/secure/config.h
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

<<<<<<<< HEAD:keyboards/handwired/uthol/rev1/config.h
#include "config_common.h"

#define DEVICE_VER 0x0001
#define PRODUCT_ID 0x67F3
#define PRODUCT UtholOne

/* Uthol PCB default pin-out */
#define MATRIX_ROW_PINS { D1, D0, D4, C6, D7 }
#define MATRIX_COL_PINS { D3, B6, B2, B3, B1, F7, F6, F5, F4, B5, B4, D2 }
#define UNUSED_PINS
========
#include "test_common.h"

// clang-format off
#define SECURE_UNLOCK_SEQUENCE \
    {                          \
        {0, 1},                \
        {0, 2},                \
        {0, 3},                \
        {0, 4}                 \
    }
// clang-format on

#define SECURE_UNLOCK_TIMEOUT 20
#define SECURE_IDLE_TIMEOUT 50
>>>>>>>> playground_new:tests/secure/config.h
