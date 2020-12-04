/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbol layer
#define CURS 2 // cursol layer

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
  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, 
  LCTL_T(KC_A), KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, RGUI_T(KC_S),
  LALT_T(KC_SCLN),KC_Q, KC_J, KC_K, KC_X,  KC_B, KC_M, KC_W, KC_V, RSFT_T(KC_Z),

  RGUI_T(KC_APPLICATION), LT(CURS, KC_ENT), RSFT_T(KC_TAB), // Left
  RALT_T(KC_BSPACE), LT(SYMB, KC_SPC), RCTL_T(KC_ESCAPE) // Right
    ),

[SYMB] = LAYOUT_gergoplex(
  LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), KC_0, 
  LCTL_T(KC_1),  KC_2,  KC_3,  KC_4,  KC_5,     KC_6, KC_7, KC_8, KC_9, RGUI_T(KC_0),
  LALT_T(KC_0), KC_GRAVE, KC_BSLASH, KC_SLASH, KC_0,  KC_0, KC_MINUS, KC_EQUAL, KC_LBRACKET, RSFT_T(KC_RBRACKET),
  RGUI_T(KC_APPLICATION), KC_ENT, RSFT_T(KC_TAB), // Left
  RALT_T(KC_BSPACE), KC_SPC, RCTL_T(KC_ESCAPE) // Right
			  ),

[CURS] = LAYOUT_gergoplex(
  KC_0, KC_0,  KC_0,  KC_0,  KC_0,  KC_0, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,
  KC_0, KC_0, KC_0, KC_0, KC_0,  KC_0, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
  KC_0, KC_0, KC_0, KC_0, KC_0,  KC_0, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
  RGUI_T(KC_APPLICATION), KC_ENT, RSFT_T(KC_TAB), // Left
  RALT_T(KC_BSPACE), KC_SPC, RCTL_T(KC_ESCAPE) // Right
    )
};

// > qmk compile
