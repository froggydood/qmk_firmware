/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "print.h"
#include "color.h"
#include "../../util/rgb.c"

#include QMK_KEYBOARD_H


enum CUSTOM {
    FN = SAFE_RANGE,
    CUSTOM_RESET,
    CUSTOM_FORWARDS_LOCK,
    CUSTOM_MINE_LOCK
};

/*
//EMPTY LAYOUT
LAYOUT(
    //ESC        F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      KC_PSCR           ROTARY_BUTTON
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //GRAVE      1        2        3        4        5        6        7        8        9        0        -        =,       BACKSPACE,        DELETE/HOME
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //TAB        Q        W        E        R,       T,       Y,       U,       I,       O,       P,       [,       ],                         PAGE_UP
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    //CAPS_LOCK, A        S        D        F,       G,       H,       J,       K,       L,       ;,       ',       #,      ENTER,             PAGE_DOWN,
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //SHIT       \        Z        X        C,       V,       B,       N,       M,       ,,       .,       /,                RSHIFT,  UP,      END,
    _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    //LCTRL      LGUI,    LALT                                SPACE,                              RALT,    FN,      RCTRL,   LEFT,    DOWN,    RIGHT
    _______,     _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MEDIA_PLAY_PAUSE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_DEL,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(9),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    //FN LAYER
    [9] = LAYOUT(
        RGB_TOG,          DM_PLY1, DM_PLY2,              _______, _______, _______, _______, _______, _______, _______, _______, DM_REC1, DM_REC2, DM_RSTP,    _______,
        RGB_M_P,          TO(0),   TO(1),                TO(2),   TO(3),   _______, _______, _______, _______, _______, _______, _______, _______, RESET,                  _______,
        RGB_MODE_FORWARD, _______, CUSTOM_FORWARDS_LOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                         _______,
        _______,          _______, CUSTOM_MINE_LOCK,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN1,             _______,
        _______,          _______, _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,    KC_MS_UP,   _______,
        _______,          _______, _______,                                         _______,                            _______, _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
    ),
};

uint8_t layer_hsv_codes[][3] = {
    [0] = {170, 255, 128},//{255, 0  , 0  },
    [1] = {0  , 255, 128},//{0  , 255, 0  },
    [2] = {128, 255, 128},//{0  , 0  , 255},
    [3] = {85 , 255, 128},//{0  , 255, 255},
    [9] = {213, 255, 128}//{255, 0  , 255},
};

int layer_rgb_modes[] = {
    [0] = RGB_MATRIX_SOLID_COLOR,//{255, 0  , 0  },
    [1] = RGB_MODE_PLAIN,//{0  , 255, 0  },
    [2] = RGB_MODE_PLAIN,//{0  , 0  , 255},
    [3] = RGB_MODE_PLAIN,//{0  , 255, 255},
    [9] = RGB_MODE_PLAIN//{255, 0  , 255},
};

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    dprintf("Debug active");
    // rgb_matrix_config.h = 120;
    // rgb_matrix_config.s = 100;
    // rgb_matrix_config.v = 70;

    HSV hsv = {
        .h = layer_hsv_codes[0][0],
        .s = layer_hsv_codes[0][1],
        .v = layer_hsv_codes[0][2],
    };
    rgb_matrix_config.hsv = hsv;
    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

int rgb_position = 0;
bool forward_locked = false;
bool mine_locked = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_BSPC) {
        if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
            if (record->event.pressed) register_code(KC_DEL);
            else unregister_code(KC_DEL);
            return false;
        }
    }
    if (keycode == CUSTOM_FORWARDS_LOCK) {
        if (!forward_locked) {
            forward_locked = true;
            register_code16(KC_LCTL);
            register_code(KC_W);
        } else {
            forward_locked = false;
            unregister_code16(KC_LCTL);
            unregister_code(KC_W);
        }
    }

    if (keycode == CUSTOM_MINE_LOCK) {
        if (!mine_locked) {
            mine_locked = true;
            unregister_code16(KC_LSFT);
            unregister_code(KC_W);
            unregister_code(KC_MS_BTN1);
        } else {
            mine_locked = false;
            unregister_code16(KC_LSFT);
            unregister_code(KC_W);
            unregister_code(KC_MS_BTN1);
        }
    }

    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    int layer = get_highest_layer(state);

    set_matrix_col_hsv_arr(layer_hsv_codes[layer]);
    rgb_matrix_mode_noeeprom(layer_rgb_modes[layer]);

    return state;
}

bool is_mod_pressed(uint16_t keycode) {
    return (get_mods() & MOD_BIT(keycode)) == MOD_BIT(keycode);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    // LEFT ALT = PREV + NEXT TRACK
    if (is_mod_pressed(KC_LALT)) {
        if (clockwise) tap_code(KC_MEDIA_NEXT_TRACK);
        else tap_code(KC_MEDIA_PREV_TRACK);
    // LEFT CTRL = UNDO + REDO
    } else if (is_mod_pressed(KC_L)) {
        if (clockwise) tap_code16(LCTL(KC_Y));
        else tap_code16(LCTL(KC_Z));
    // SHIFT KEY = (AUTO HOTKEY) CHANGE ACTIVE PROGRAM VOLUME
    } else if (is_mod_pressed(KC_LSFT)) {
        unregister_code16(KC_LSFT);
        if (clockwise) tap_code16(LCTL(KC_F3));
        else tap_code16(LCTL(KC_F4));
        register_code16(KC_LSFT);
    // RIGHT SHIFT KEY = (AUTO HOTKEY) CHANGE DISCORD VOLUME
    } else if (is_mod_pressed(KC_RSFT)) {
        unregister_code16(KC_RSFT);
        if (clockwise) tap_code16(LCTL(KC_F5));
        else tap_code16(LCTL(KC_F6));
        register_code16(KC_RSFT);
    // NORMAL = (AUTO HOTKEY) CHANGE SPOTIFY VOLUME
    } else {
        if (clockwise) tap_code16(LCTL(KC_F1));
        else tap_code16(LCTL(KC_F2));
    }
    return true;
}
