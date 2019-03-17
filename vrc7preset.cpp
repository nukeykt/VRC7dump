//
// Copyright (C) 2018-2019 Nuke.YKT
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
//
//  Konami VRC7 / Yamaha DS1001 instrument ROM dump.
//  Thanks:
//      siliconpr0n.org(digshadow, John McMaster):
//          VRC VII decap and die shot.
//

#include <stdint.h>

typedef uintptr_t       Bitu;
typedef intptr_t        Bits;
typedef uint64_t        Bit64u;
typedef int64_t         Bit64s;
typedef uint32_t        Bit32u;
typedef int32_t         Bit32s;
typedef uint16_t        Bit16u;
typedef int16_t         Bit16s;
typedef uint8_t         Bit8u;
typedef int8_t          Bit8s;

enum {
    opll_patch_1 = 0x00,
    opll_patch_2,
    opll_patch_3,
    opll_patch_4,
    opll_patch_5,
    opll_patch_6,
    opll_patch_7,
    opll_patch_8,
    opll_patch_9,
    opll_patch_10,
    opll_patch_11,
    opll_patch_12,
    opll_patch_13,
    opll_patch_14,
    opll_patch_15,
    opll_patch_drum_0,
    opll_patch_drum_1,
    opll_patch_drum_2,
    opll_patch_drum_3,
    opll_patch_drum_4,
    opll_patch_drum_5,
    opll_patch_max
};

typedef struct {
    Bit8u tl; // Modulator TL
    Bit8u dc; // Carrier waveform
    Bit8u dm; // Modulator waveform
    Bit8u fb; // Feedback
    Bit8u am[2]; // Tremolo (mod, car)
    Bit8u vib[2]; // Vibrato (mod, car)
    Bit8u et[2]; // Envelope type (mod, car)
    Bit8u ksr[2]; // Key scale rate (mod, car)
    Bit8u multi[2]; // Freq multiplier (mod, car)
    Bit8u ksl[2]; // Key scale level (mod, car)
    Bit8u ar[2]; // Attack rate (mod, car)
    Bit8u dr[2]; // Decay rate (mod, car)
    Bit8u sl[2]; // Sustain level (mod, car)
    Bit8u rr[2]; // Release rate (mod, car)
} opll_patch_t;

static const opll_patch_t patch_ds1001[opll_patch_max] = {
    { 0x05, 0x00, 0x00, 0x06,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x01 },{ 0x00, 0x00 },{ 0x03, 0x01 },{ 0x00, 0x00 },{ 0x0e, 0x08 },{ 0x08, 0x01 },{ 0x04, 0x02 },{ 0x02, 0x07 } },
    { 0x14, 0x00, 0x01, 0x05,{ 0x00, 0x00 },{ 0x00, 0x01 },{ 0x00, 0x00 },{ 0x01, 0x00 },{ 0x03, 0x01 },{ 0x00, 0x00 },{ 0x0d, 0x0f },{ 0x08, 0x06 },{ 0x02, 0x01 },{ 0x03, 0x02 } },
    { 0x08, 0x00, 0x01, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x01, 0x01 },{ 0x01, 0x01 },{ 0x00, 0x00 },{ 0x0f, 0x0b },{ 0x0a, 0x02 },{ 0x02, 0x01 },{ 0x00, 0x02 } },
    { 0x0c, 0x00, 0x00, 0x07,{ 0x00, 0x00 },{ 0x00, 0x01 },{ 0x01, 0x01 },{ 0x01, 0x00 },{ 0x01, 0x01 },{ 0x00, 0x00 },{ 0x0a, 0x06 },{ 0x08, 0x04 },{ 0x06, 0x02 },{ 0x01, 0x07 } },
    { 0x1e, 0x00, 0x00, 0x06,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x01, 0x01 },{ 0x01, 0x00 },{ 0x02, 0x01 },{ 0x00, 0x00 },{ 0x0e, 0x07 },{ 0x01, 0x06 },{ 0x00, 0x02 },{ 0x01, 0x08 } },
    { 0x06, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x02, 0x01 },{ 0x00, 0x00 },{ 0x0a, 0x0e },{ 0x03, 0x02 },{ 0x0f, 0x0f },{ 0x04, 0x04 } },
    { 0x1d, 0x00, 0x00, 0x07,{ 0x00, 0x00 },{ 0x00, 0x01 },{ 0x01, 0x01 },{ 0x00, 0x00 },{ 0x01, 0x01 },{ 0x00, 0x00 },{ 0x08, 0x08 },{ 0x02, 0x01 },{ 0x01, 0x00 },{ 0x01, 0x07 } },
    { 0x22, 0x01, 0x00, 0x07,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x01, 0x01 },{ 0x00, 0x00 },{ 0x03, 0x01 },{ 0x00, 0x00 },{ 0x0a, 0x07 },{ 0x02, 0x02 },{ 0x00, 0x01 },{ 0x01, 0x07 } },
    { 0x25, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x01, 0x00 },{ 0x01, 0x01 },{ 0x05, 0x01 },{ 0x00, 0x00 },{ 0x04, 0x07 },{ 0x00, 0x03 },{ 0x07, 0x00 },{ 0x02, 0x01 } },
    { 0x0f, 0x00, 0x01, 0x07,{ 0x01, 0x00 },{ 0x00, 0x00 },{ 0x01, 0x00 },{ 0x01, 0x00 },{ 0x05, 0x01 },{ 0x00, 0x00 },{ 0x0a, 0x0a },{ 0x08, 0x05 },{ 0x05, 0x00 },{ 0x01, 0x02 } },
    { 0x24, 0x00, 0x00, 0x07,{ 0x00, 0x01 },{ 0x00, 0x01 },{ 0x00, 0x00 },{ 0x01, 0x00 },{ 0x07, 0x01 },{ 0x00, 0x00 },{ 0x0f, 0x0f },{ 0x08, 0x08 },{ 0x02, 0x01 },{ 0x02, 0x02 } },
    { 0x11, 0x00, 0x00, 0x06,{ 0x00, 0x00 },{ 0x01, 0x00 },{ 0x01, 0x01 },{ 0x01, 0x00 },{ 0x01, 0x03 },{ 0x00, 0x00 },{ 0x06, 0x07 },{ 0x05, 0x04 },{ 0x01, 0x01 },{ 0x08, 0x06 } },
    { 0x13, 0x00, 0x00, 0x05,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x01, 0x02 },{ 0x03, 0x00 },{ 0x0c, 0x09 },{ 0x09, 0x05 },{ 0x00, 0x00 },{ 0x03, 0x02 } },
    { 0x0c, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x01, 0x01 },{ 0x01, 0x01 },{ 0x00, 0x00 },{ 0x01, 0x03 },{ 0x00, 0x00 },{ 0x09, 0x0c },{ 0x04, 0x00 },{ 0x03, 0x0f },{ 0x03, 0x06 } },
    { 0x0d, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x01 },{ 0x01, 0x01 },{ 0x00, 0x01 },{ 0x01, 0x02 },{ 0x00, 0x00 },{ 0x0c, 0x0d },{ 0x01, 0x05 },{ 0x05, 0x00 },{ 0x06, 0x06 } },
    /* TODO: rhythm preset */
    { 0x00, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 } },
    { 0x00, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 } },
    { 0x00, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 } },
    { 0x00, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 } },
    { 0x00, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 } },
    { 0x00, 0x00, 0x00, 0x00,{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 },{ 0x00, 0x00 } }
};
