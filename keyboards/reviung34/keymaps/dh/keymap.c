/* Copyright 2019 gtips
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
#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

// Left-hand home row mods
#define ALT_A LALT_T(KC_A)
#define CTL_R LCTL_T(KC_R)
#define GUI_S LGUI_T(KC_S)
#define SHFT_T LSFT_T(KC_T)

// Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define GUI_E RGUI_T(KC_E)
#define CTL_I RCTL_T(KC_I)
#define ALT_O LALT_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung34(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
   ALT_A,   CTL_R,   GUI_S,  SHFT_T,    KC_G,          KC_M,   SFT_N,   GUI_E,   CTL_I,   ALT_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    KC_COMM,   KC_DOT,   KC_SLSH, 
                     XXXXXXX,  LOWER, KC_SPC,              RAISE
  ),

  [_LOWER] = LAYOUT_reviung34(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_COLN, KC_SCLN,  KC_TAB,  KC_ENT, XXXXXXX,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_ESC,       XXXXXXX, KC_BSPC,  XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______,            _______
  ),
  
  [_RAISE] = LAYOUT_reviung34(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,       KC_PIPE, KC_LCBR, KC_RCBR, KC_PLUS, KC_UNDS,
    KC_GRV, XXXXXXX,  KC_LPRN, KC_RPRN,  KC_ESC,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD,
                      _______, _______, _______,            _______
  ),
  
  [_ADJUST] = LAYOUT_reviung34(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,        KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______,            _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
