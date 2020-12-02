/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Combos
enum combos {
  N1, N2, N3, N4, N5, N6, N7, N8, N9, N10,
  NS1
};

const uint16_t PROGMEM n1_combo[] = {KC_U, KC_G, COMBO_END};
const uint16_t PROGMEM n2_combo[] = {KC_U, KC_C, COMBO_END};
const uint16_t PROGMEM n3_combo[] = {KC_U, KC_R, COMBO_END};
const uint16_t PROGMEM n4_combo[] = {KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM n5_combo[] = {KC_U, KC_T, COMBO_END};
const uint16_t PROGMEM n6_combo[] = {KC_U, KC_N, COMBO_END};
const uint16_t PROGMEM n7_combo[] = {KC_U, KC_M, COMBO_END};
const uint16_t PROGMEM n8_combo[] = {KC_U, KC_W, COMBO_END};
const uint16_t PROGMEM n9_combo[] = {KC_U, KC_V, COMBO_END};
const uint16_t PROGMEM n10_combo[] = {KC_U, KC_Z, COMBO_END};

const uint16_t PROGMEM ns1_combo[] = {KC_E, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [N1] = COMBO(n1_combo, KC_1),
  [N2] = COMBO(n2_combo, KC_2),
  [N3] = COMBO(n3_combo, KC_3),
  [N4] = COMBO(n4_combo, KC_4),
  [N5] = COMBO(n5_combo, KC_5),
  [N6] = COMBO(n6_combo, KC_6),
  [N7] = COMBO(n7_combo, KC_7),
  [N8] = COMBO(n8_combo, KC_8),
  [N9] = COMBO(n9_combo, KC_9),
  [N10] = COMBO(n10_combo, KC_0),
  [NS1] = COMBO(ns1_combo, KC_EXCLAIM),
};

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    ' |  ,  |  .  |  P  |  Y  |      |  F  |  G  |  C  |  R  |    L   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |CTRL/A|  O  |  E  |  U  |  I  |      |  D  |  H  |  T  |  N  | CTRL/S | 
 * |-----+-----+-----+-----+------+      |--------------------------------|
 * |SHFT/;|  Q  |  J  |  K  |  X  |      |  B  |  M  |  W  |  V  | SHFT/Z |
 * `------+-----+-----+------+----'      `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |ESC/META|ENT/ALT|SPC(SYM)|           |SPC(NUM)|BSPC|TAB|
 *  '-------------------------'           '-----------------' 
 */
[BASE] = LAYOUT_gergoplex(
    KC_QUOT,              KC_COMM, KC_DOT, KC_P, KC_Y,   KC_F, KC_G, KC_C, KC_R, KC_L, 
    MT(MOD_LCTL, KC_A),   KC_O,    KC_E,   KC_U, KC_I,   KC_D, KC_H, KC_T, KC_N, MT(MOD_LCTL, KC_S),
    MT(MOD_RSFT, KC_SCLN),KC_Q,    KC_J,   KC_K, KC_X,   KC_B, KC_M, KC_W, KC_V, KC_Z,

    MT(MOD_LGUI, KC_ESC), MT(MOD_LALT, KC_ENT), LT(SYMB, KC_SPC),         // Left
    LT(NUMB, KC_SPC), KC_LSFT, MT(MOD_RSFT, KC_TAB)                // Right
    ),
/* Keymap 1: Symbols layer
 * ,-----------------------------.       ,--------------------------------.
 * |  "   |  <  |  >  |  }  |     |      |  `  |  ~  |     |     |    \   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |  #   |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |    '■ |  ?!<{%■
 * |-----+-----+-----+-----+------+      |--------------------------------|
 * |  :   |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,■  |  .■  |   -    |
 * `------+-----+-----+------+----'      `--------------------------------'
 *      .-----------------.              .------------------.   
 *      |MMB |  ;   |  =  |              |  =  |  ;  |  DEL |
 *      '-----------------'              '------------------' 
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_LT,   KC_GT, KC_RCBR, KC_PIPE,   KC_GRV,  KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
    KC_COLN, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,   KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_MINS,
                      KC_BTN3, KC_SCLN, KC_EQL,    KC_EQL,  KC_SCLN, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |-----+-----+-----+-----+------|      |-------------------------------|
 * |  F1  | F2  | F3  | F4  |  F5 |      | LFT | DWN | UP  | RGT | VOLUP | 
 * |-----+-----+-----+-----+------+      |-------------------------------|
 * |  F6  | F7  | F8  | F9  | F10 |      |MLFT | MDWN| MUP | MRGT| VOLDN |
 * `------+-----+-----+------+----'      `-------------------------------'
 *      .-----------------.              .-----------------.   
 *      | F11 | F12|      |              |     | PLY | SKP |
 *      '-----------------'              '-----------------' 
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
             KC_F11,KC_F12,KC_TRNS,   KC_TRNS,KC_MPLY,KC_MNXT
    )
};
// > qmk compile
