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
  LSFT_T(KC_SCLN),KC_Q, KC_J, KC_K, KC_X,  KC_B, KC_M, KC_W, KC_V, RALT_T(KC_Z),

  RGUI_T(KC_APPLICATION), LT(CURS, KC_ENT), RALT_T(KC_BSPACE), // Left
  LT(SYMB, KC_SPC), RCTL_T(KC_ESCAPE), RSFT_T(KC_TAB) // Right
    ),

[SYMB] = LAYOUT_gergoplex(
  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,     KC_6, KC_7, KC_8, KC_9, KC_0,
  KC_TILDE, KC_GRAVE, KC_BSLASH, KC_SLASH, KC_0,  KC_0, KC_MINUS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET,
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
             KC_0, KC_0, KC_0,  KC_0, KC_0, KC_0
			  ),

[CURS] = LAYOUT_gergoplex(
  KC_0, KC_0,  KC_0,  KC_0,  KC_0,  KC_0, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,
  KC_0, KC_0, KC_0, KC_0, KC_0,  KC_0, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
  KC_0, KC_0, KC_0, KC_0, KC_0,  KC_0, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
             KC_0, KC_0, KC_0,  KC_0, KC_0, KC_0
    )
};

// > qmk compile
