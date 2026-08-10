#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};


// Trivium custom Shift pairs
const key_override_t trivium_comma_semicolon =
    ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCLN);

const key_override_t *key_overrides[] = {
    &trivium_comma_semicolon
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_RIGHT_ALT,                                   KC_LEFT_ALT,    KC_L,           KC_U,           KC_Y,           KC_UNDS,        KC_ESCAPE,      
    KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_COMMA,                                       KC_DOT,         KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,       
    KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_QUES,                                        KC_BSLS,        KC_H,           KC_M,           KC_K,           KC_J,           KC_EQUAL,       
    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_DELETE,                                      KC_BSPC,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           
                                                    LT(2, KC_TAB),  MT(MOD_LCTL, KC_SPACE),                                MT(MOD_RSFT, KC_ENTER),TT(1)
  ),
  [1] = LAYOUT_voyager(
    KC_TILD,        KC_NO,          KC_X,           KC_Y,           KC_Z,           KC_RIGHT_ALT,                                   KC_LEFT_ALT,    KC_LBRC,        KC_RBRC,        KC_LABK,        KC_RABK,        KC_ESCAPE,      
    KC_QUOTE,       KC_HASH,        KC_AT,          KC_UNDS,        KC_CIRC,        KC_COMMA,                                       KC_DOT,         KC_LPRN,        KC_RPRN,        KC_KP_PLUS,     KC_KP_MINUS,    KC_QUOTE,       
    KC_PIPE,        KC_GRAVE,       KC_DLR,         KC_PERC,        KC_AMPR,        KC_QUES,                                        KC_BSLS,        KC_LCBR,        KC_RCBR,        KC_KP_ASTERISK, KC_KP_SLASH,    KC_EQUAL,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,                                      KC_BSPC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_LEFT_GUI,    KC_PC_UNDO,     LCTL(KC_Y),     KC_PC_CUT,      KC_PC_COPY,     KC_RIGHT_ALT,                                   KC_TRANSPARENT, KC_HOME,        KC_END,         KC_PAGE_UP,     KC_PGDN,        KC_ESCAPE,      
    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_PC_PASTE,    KC_NO,          KC_TRANSPARENT,                                 KC_DOT,         KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, 
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_BSLS,        LCTL(KC_LEFT),  LCTL(KC_RIGHT), KC_INSERT,      KC_APPLICATION, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_ALT,                                   KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA,                                       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F11,         KC_F12,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};









bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
