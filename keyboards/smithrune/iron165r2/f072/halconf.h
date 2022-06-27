<<<<<<<< HEAD:keyboards/acheron/shark/beta/halconf.h
/* Copyright 2020 QMK
========
/* Copyright 2022 QMK
>>>>>>>> playground_new:keyboards/smithrune/iron165r2/f072/halconf.h
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

#define HAL_USE_PWM TRUE
#define HAL_USE_PAL TRUE

<<<<<<<< HEAD:keyboards/acheron/shark/beta/halconf.h
#define HAL_USE_I2C TRUE
========
#define HAL_USE_SPI TRUE
>>>>>>>> playground_new:keyboards/smithrune/iron165r2/f072/halconf.h

#include_next <halconf.h>
