/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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
#include <stdint.h>

//#include "qp.h"
//#include "generated/totoro-jumping.qgf.h"

#include QMK_KEYBOARD_H


//static painter_device_t display;
//static painter_image_handle_t my_image;
//static deferred_token my_anim;


enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
    LAYER_RGB,
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)
#define MRGB MO(LAYER_RGB)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

//macros

enum custom_keycodes {
    M0=SAFE_RANGE,
    M1,
    M2,
    M3,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M0:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            tap_code(KC_W);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
        } else {
            // When released
            //
        }
        break;

    case M1:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            tap_code(KC_E);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
        } else {
            // When released
            //
        }
        break;

    case M2:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            tap_code(KC_F12);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
        } else {
            // When released
            //
        }
        break;

    case M3:
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            tap_code(KC_F11);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
        } else {
            // When released
            //
        }
        break;
    }
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        QK_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SC_LCPO,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH, SC_RAPC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_LALT, KC_SPC,  KC_LGUI,   LOWER,      RAISE,  SC_SENT, KC_SPC,  KC_MUTE
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,        KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
  // ├────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, TO(LAYER_RGB), RGB_MOD,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, KC_NUM,
  // ├────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,       RGB_TOG,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, M0,      M1,      M2,      M3,            RGB_RMOD,   KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, KC_WWW_REFRESH, KC_P0,  KC_TRNS,    TG(LAYER_RAISE),    KC_DEL,  KC_BSPC, XXXXXXX
  //                    ╰─────────────────────────────────────────╯ ╰──────────────────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, KC_BSPC, KC_TRNS, TG(LAYER_LOWER),    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX
//                  ╰──────────────────────────────────────────────╯ ╰────────────────────────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1, KC_BTN2, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_RGB] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_MOD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, RGB_TOG,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_RMOD,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                   XXXXXXX, _______, _______, TG(LAYER_RGB),    _______, XXXXXXX, XXXXXXX, XXXXXXX
//                ╰─────────────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_POINTER); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLEE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);

// Layer state indicator
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (int i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }

    uint8_t layer = get_highest_layer(layer_state);
    if (layer > LAYER_BASE) {
        HSV hsv = rgb_matrix_get_hsv();
        switch (get_highest_layer(layer_state)) {
            case LAYER_LOWER:
                hsv = (HSV){HSV_BLUE};
                break;
            case LAYER_RAISE:
                hsv = (HSV){HSV_CORAL};
                break;
            case LAYER_POINTER:
                hsv = (HSV){HSV_YELLOW};
                break;
            default:
                hsv = (HSV){HSV_RED};
                break;
        };

        if (hsv.v > rgb_matrix_get_val()) {
            hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
        }
        RGB rgb = hsv_to_rgb(hsv);

        for (int i = led_min; i <= led_max; i++) {
            if ( g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        };

// use below lines instead of the above for-loop to use the cutout as layer indicator
//        rgb_matrix_set_color(19, rgb.r, rgb.g, rgb.b);
//        rgb_matrix_set_color(20, rgb.r, rgb.g, rgb.b);
//        rgb_matrix_set_color(71, rgb.r, rgb.g, rgb.b);
//        rgb_matrix_set_color(72, rgb.r, rgb.g, rgb.b);
    }
    return false;
};
#endif

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [LAYER_LOWER]      = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_RAISE]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [LAYER_RGB]        = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
/*
void keyboard_post_init_kb(void) {
    display = qp_gc9a01_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 0);         // Create the display
    qp_init(display, QP_ROTATION_0);   // Initialise the display
    qp_clear(display);
    my_image = qp_load_image_mem(gfx_totoro_jumping);
    //    qp_drawimage(display, 0, 0, my_image);
    //my_anim = qp_animate(display, 0, 0, my_image);
}
*/
