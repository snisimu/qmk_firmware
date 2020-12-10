/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define NUMB 1 // number layer
#define CURS 2 // cursol layer
#define FNUM 3 // function layer

// Combos
enum combos {
 RST
};

const uint16_t PROGMEM rst_combo[] = {KC_QUOT, KC_SCLN, KC_L, KC_Z, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [RST] = COMBO(rst_combo, RESET)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_gergoplex(
  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, /* */ KC_F, KC_G, KC_C, KC_R, RGUI_T(KC_L), 
  LCTL_T(KC_A), KC_O, KC_E, KC_U, KC_I, /* */ KC_D, KC_H, KC_T, KC_N, RCTL_T(KC_S),
  LALT_T(KC_SCLN),KC_Q, KC_J, KC_K, KC_X, /* */ KC_B, KC_M, KC_W, KC_V, RSFT_T(KC_Z),
  RGUI_T(KC_ESCAPE), LT(CURS, KC_SPC), RSFT_T(KC_TAB), // Left
  RALT_T(KC_BSPACE), LT(NUMB, KC_ENT), LCTL(KC_7) // Right
),

[NUMB] = LAYOUT_gergoplex(
  LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), /* */ LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), RGUI_T(KC_NO), 
  LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5, /* */ KC_6, KC_7, KC_8, KC_9, RCTL_T(KC_0),
  KC_EXCLAIM /* ALT does not work */, RSFT(KC_2), RSFT(KC_3), RSFT(KC_4), RSFT(KC_5), /* */ RSFT(KC_6), RSFT(KC_7), RSFT(KC_8), RSFT(KC_9), RSFT(KC_0),
  RGUI_T(KC_ESCAPE), LT(FNUM, KC_SPC), RSFT_T(KC_TAB), // Left
  RALT_T(KC_BSPACE), LT(NUMB, KC_ENT), LCTL(KC_7) // Right
),

[CURS] = LAYOUT_gergoplex(
  KC_GRAVE, RSFT(KC_EQUAL), KC_EQUAL, RSFT(KC_MINUS), RSFT(KC_LBRACKET), /* */ LSFT(KC_RBRACKET), KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,
  LCTL_T(KC_SLASH), KC_MINUS, KC_MS_BTN1, KC_MS_BTN2, KC_APPLICATION, /* */ KC_DELETE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
  LALT_T(KC_TILDE), RSFT(KC_BSLASH), KC_BSLASH, RSFT(KC_SLASH), KC_LBRACKET, /* */ KC_RBRACKET, KC_HOME, KC_PGDOWN, KC_PGUP, RSFT_T(KC_END),
  RGUI_T(KC_ESCAPE), LT(CURS, KC_SPC), RSFT_T(KC_TAB), // Left
  RALT_T(KC_BSPACE), LT(FNUM, KC_ENT), LCTL(KC_7) // Right
),

[FNUM] = LAYOUT_gergoplex(
  KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5, /* */ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /* */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  RGUI_T(KC_ESCAPE), LT(CURS, KC_SPC), RSFT_T(KC_TAB), // Left
  RALT_T(KC_BSPACE), LT(NUMB, KC_ENT), LCTL(KC_7) // Right
)
};

// > qmk compile
