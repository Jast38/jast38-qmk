// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #define DEBUG_MATRIX_SCAN_RATE

#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_HID_SYNC, RPC_ID_USER_CAPS_WORD_SYNC, RPC_ID_USER_LAYER_SYNC

#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#define MOUSE_EXTENDED_REPORT

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 0

#define TAP_CODE_DELAY 10

#define CAPS_WORD_IDLE_TIMEOUT 2500
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_TIMEOUT 300000
#    define RGB_TRIGGER_ON_KEYDOWN
#endif
