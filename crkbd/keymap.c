#include QMK_KEYBOARD_H
#include <stdio.h>

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

enum layers { BASE, NAV };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(

//  |-----------------+-----------------+-----------------+-----------------+-----------------+----------------|   |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------|
      U_NP,             KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,                KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             U_NP,
//  |-----------------+-----------------+-----------------+-----------------+-----------------+----------------|   |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------|
      U_NP,             LGUI_T(KC_A),     LALT_T(KC_S),     LCTL_T(KC_D),     LSFT_T(KC_F),     KC_G,                KC_H,             LSFT_T(KC_J),     LCTL_T(KC_K),     LALT_T(KC_L),     LGUI_T(KC_QUOT),  U_NP,
//  |-----------------+-----------------+-----------------+-----------------+-----------------+----------------|   |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------|
      U_NP,             KC_Z,             KC_X,            KC_C,             KC_V,             KC_B,                 KC_N,             KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          U_NP,
//  |-----------------+-----------------+-----------------+-----------------+-----------------+----------------|   |-----------------+-----------------+-----------------+-----------------+-----------------+-----------------|
                                                            KC_ESC,           LT(NAV,KC_SPC),   KC_TAB,              KC_ENT,           KC_BSPC,          KC_DEL
//                                                        |-----------------+-----------------+----------------|   |-----------------+-----------------+-----------------|
  ),
  [NAV] = LAYOUT_split_3x6_3(
//  |                 |                 |                 |                 |                 |                 |                 |                 |                 |                 |                 |
    U_NP,             U_NA,             U_NA,             U_NA,             U_NA,             U_NA,             U_RDO,            U_PST,            U_CPY,            U_CUT,            U_UND,            U_NP,
    U_NP,             KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,          U_NA,             CW_TOGG,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          U_NP,
    U_NP,             U_NA,             U_NA,             U_NA,             U_NA,             U_NA,             KC_INS,           KC_HOME,          KC_PGDN,          KC_PGUP,          KC_END,           U_NP,
                                                          U_NA,             U_NA,             U_NA,             KC_ENT,           KC_BSPC,          KC_DEL
  ),
};
