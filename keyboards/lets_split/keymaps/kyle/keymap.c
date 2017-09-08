#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NUMPAD 1
#define _NAV 2
#define _SYMBOLS 3
#define _FN 4

#define M_BSDEL M(0)	// macro for backspace with del when shift is held


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD,
  NAV,
  SYMBOLS,
  FN,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  OS  | Nav  |Symbol|Space |Enter |Symbol|  Fn  |      |      |Numpad|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,   KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_LCTL, KC_LALT, KC_LGUI, MO(_NAV), MO(_SYMBOLS), SFT_T(KC_SPC), SFT_T(KC_ENT), MO(_SYMBOLS), MO(_FN), _______, _______, TG(_NUMPAD) \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  7   |  8   |  9   |  /   |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |  *   |      |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |  -   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Enter|  0   |  .   |  +   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, KC_P7,  KC_P8, KC_P9,   KC_PSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_P4,  KC_P5, KC_P6,   KC_PAST, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_P1,  KC_P2, KC_P3,   KC_PMNS, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_ENT, KC_P0, KC_PDOT, KC_PPLS, _______ \
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | PgUp | Home |  Up  | End  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | PgDn | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  +   |  =   |  _   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  `   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  {   |  [   |  (   |      |      |  )   |  ]   |  }   |  \   |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] =  KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_UNDS, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, _______, _______, KC_RPRN, KC_RBRC, KC_RCBR, KC_BSLS, KC_PIPE, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] =  KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
//    case NUMPAD:
//      if (record->event.pressed) {
//        layer_on(_NUMPAD);
//      } else {
//        layer_off(_NUMPAD);
//      }
//      return false;
//      break;
//    case NAV:
//      if (record->event.pressed) {
//        layer_on(_NAV);
//      } else {
//        layer_off(_NAV);
//      }
//      return false;
//      break;
//    case SYMBOLS:
//      if (record->event.pressed) {
//        layer_on(_SYMBOLS);
//      } else {
//        layer_off(_SYMBOLS);
//      }
//      return false;
//      break;
//    case FN:
//      if (record->event.pressed) {
//        layer_on(_FN);
//      } else {
//        layer_off(_FN);
//      }
//      return false;
//      break;
  }
  return true;
}


//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//  switch(id) {
//    case 0: {
//      uint8_t kc = KC_BSPC;
//      if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)) {
//        kc = KC_DEL;
//      }
//      if (record->event.pressed)
//        register_code(kc);
//      else
//        unregister_code(kc);
//    }
//  }
//  return MACRO_NONE;
//};
