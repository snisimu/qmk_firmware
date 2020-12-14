/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define NUMSYM 1 // number/symbol layer
#define CURSOR 2 // cursor layer

// Combos
enum combos {
  SPC, ESC, LTAB, RTAB
};

const uint16_t PROGMEM spc_combo[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM ltab_combo[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM rtab_combo[] = {KC_H, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SPC] = COMBO(spc_combo, KC_SPACE),
  [ESC] = COMBO(esc_combo, KC_ESCAPE),
  [LTAB] = COMBO(ltab_combo, KC_TAB),
  [RTAB] = COMBO(rtab_combo, KC_TAB)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_gergoplex(
  KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, /* */ KC_F, KC_G, KC_C, KC_R, KC_L, 
  KC_A, KC_O, KC_E, KC_U, KC_I, /* */ KC_D, KC_H, KC_T, KC_N, KC_S,
  KC_SCLN, KC_Q, KC_J, KC_K, KC_X, /* */ KC_B, KC_M, KC_W, KC_V, KC_Z,
  LALT_T(RCTL(KC_7)), LT(CURSOR, KC_SPACE), KC_LCTRL, // Left
  KC_RSHIFT, MO(NUMSYM), RGUI_T(KC_ENTER) // Right
),

[NUMSYM] = LAYOUT_gergoplex(
  KC_BSLASH, KC_SLASH, KC_EQUAL, KC_MINUS, KC_NO, /* */ KC_NO, KC_GRAVE, KC_TILDE, KC_LBRACKET, KC_RBRACKET,
  KC_1, KC_2, KC_3, KC_4, KC_5, /* */ KC_6, KC_7, KC_8, KC_9, KC_0,
  KC_F1, KC_F2,  KC_LALT,  KC_LCTRL,  KC_F5, /* */ KC_F6, KC_RCTRL, KC_RALT, KC_F9, KC_F10,
  KC_NO, KC_LGUI, KC_LSHIFT, // Left
  KC_NO, KC_TRANSPARENT, KC_NO // Right
),

[CURSOR] = LAYOUT_gergoplex(
  KC_LGUI, KC_LALT, KC_LCTRL, KC_TAB, KC_NO, /* */ KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
  KC_APPLICATION, KC_MS_BTN1, KC_BSPACE, KC_DELETE, KC_MS_BTN2, /* */ KC_NO, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  /* */ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
  KC_NO, KC_NO, KC_NO, // Left
  KC_NO, KC_RSHIFT, KC_ENTER // Right
),

};
