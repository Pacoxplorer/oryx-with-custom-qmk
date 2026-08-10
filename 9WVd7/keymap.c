#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#include "keymap_french.h"

#define MOON_LED_LEVEL LED_LEVEL

#ifndef ZSA_SAFE_RANGE
#    define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
    RGB_SLD = ZSA_SAFE_RANGE,

    // Trivium Shift pairs
    TV_1,
    TV_2,
    TV_3,
    TV_4,
    TV_5,
    TV_6,
    TV_7,
    TV_8,
    TV_9,
    TV_0,

    TV_COMM,
    TV_DOT,
    TV_QUES,
    TV_QUOT,
};


/*
 * Send one of two French keycodes depending on whether Shift is held.
 *
 * Shift is temporarily removed because several French characters themselves
 * require Shift internally (FR_1, FR_DOT, FR_QUES, etc.).
 */
static void trivium_pair(uint16_t normal_kc, uint16_t shifted_kc) {
    uint8_t mods = get_mods();
    uint8_t osm  = get_oneshot_mods();

    bool shifted = ((mods | osm) & MOD_MASK_SHIFT);

    del_mods(MOD_MASK_SHIFT);
    del_oneshot_mods(MOD_MASK_SHIFT);
    send_keyboard_report();

    tap_code16(shifted ? shifted_kc : normal_kc);

    set_mods(mods);
    set_oneshot_mods(osm & ~MOD_MASK_SHIFT);

    send_keyboard_report();
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* =========================
     * BASE
     * ========================= */
    [0] = LAYOUT_voyager(
        FR_Q,     FR_W,     FR_F,     FR_P,     FR_B,     KC_RIGHT_ALT,       KC_LEFT_ALT, FR_L,     FR_U,     FR_Y,     FR_UNDS,  KC_ESCAPE,
        FR_A,     FR_R,     FR_S,     FR_T,     FR_G,     TV_COMM,            TV_DOT,      FR_N,     FR_E,     FR_I,     FR_O,     TV_QUOT,
        FR_Z,     FR_X,     FR_C,     FR_D,     FR_V,     TV_QUES,            FR_BSLS,     FR_H,     FR_M,     FR_K,     FR_J,     FR_EQL,
        TV_1,     TV_2,     TV_3,     TV_4,     TV_5,     KC_DELETE,          KC_BSPC,     TV_6,     TV_7,     TV_8,     TV_9,     TV_0,

                                      LT(2, KC_TAB),
                                      MT(MOD_LCTL, KC_SPACE),
                                                                        MT(MOD_RSFT, KC_ENTER),
                                                                        TT(1)
    ),


    /* =========================
     * SCI
     * ========================= */
    [1] = LAYOUT_voyager(
        FR_TILD,  KC_NO,          FR_X,          FR_Y,          FR_Z,          KC_RIGHT_ALT,       KC_LEFT_ALT,    FR_LBRC,        FR_RBRC,        FR_LABK,        FR_RABK,        KC_ESCAPE,
        TV_QUOT,  FR_HASH,        FR_AT,         FR_UNDS,       FR_CIRC,       TV_COMM,            TV_DOT,         FR_LPRN,        FR_RPRN,        FR_PLUS,        FR_MINS,        TV_QUOT,
        FR_PIPE,  FR_GRV,         FR_DLR,        FR_PERC,       FR_AMPR,       TV_QUES,            FR_BSLS,        FR_LCBR,        FR_RCBR,        FR_ASTR,        FR_SLSH,        FR_EQL,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE, KC_BSPC, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                     KC_TRANSPARENT,
                                                     KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT,
                                                                                                  KC_TRANSPARENT
    ),


    /* =========================
     * NAV
     * ========================= */
    [2] = LAYOUT_voyager(
        KC_LEFT_GUI,  LCTL(FR_Z),     LCTL(FR_Y),     LCTL(FR_X),     LCTL(FR_C),     KC_RIGHT_ALT,      KC_TRANSPARENT, KC_HOME,        KC_END,         KC_PAGE_UP,      KC_PGDN,        KC_ESCAPE,
        KC_LEFT_CTRL, KC_LEFT_ALT,    KC_LEFT_SHIFT,  LCTL(FR_V),     KC_NO,           KC_TRANSPARENT,    TV_DOT,         KC_LEFT,        KC_DOWN,        KC_UP,           KC_RIGHT,       KC_TRANSPARENT,
        KC_NO,        KC_NO,          KC_NO,           KC_NO,          KC_NO,           KC_TRANSPARENT,    FR_BSLS,        LCTL(KC_LEFT),  LCTL(KC_RIGHT), KC_INSERT,       KC_APPLICATION, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

                                                        KC_TRANSPARENT,
                                                        KC_TRANSPARENT,
                                                                                                         KC_TRANSPARENT,
                                                                                                         KC_TRANSPARENT
    ),


    /* =========================
     * FN
     * ========================= */
    [3] = LAYOUT_voyager(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_ALT,     KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TV_COMM,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F11,         KC_F12,         KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,   KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,

                                                        KC_TRANSPARENT,
                                                        KC_TRANSPARENT,
                                                                                                         KC_TRANSPARENT,
                                                                                                         KC_TRANSPARENT
    ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed) {
        switch (keycode) {
            case TV_1:
            case TV_2:
            case TV_3:
            case TV_4:
            case TV_5:
            case TV_6:
            case TV_7:
            case TV_8:
            case TV_9:
            case TV_0:
            case TV_COMM:
            case TV_DOT:
            case TV_QUES:
            case TV_QUOT:
                return false;
        }
    }

    switch (keycode) {

        /*
         * Trivium numeric row
         *
         * normal       Shift
         * 1            &
         * 2            é
         * 3            "
         * 4            '
         * 5            5
         * 6            -
         * 7            è
         * 8            _
         * 9            ç
         * 0            à
         */

        case TV_1:
            trivium_pair(FR_1, FR_AMPR);
            return false;

        case TV_2:
            trivium_pair(FR_2, FR_EACU);
            return false;

        case TV_3:
            trivium_pair(FR_3, FR_DQUO);
            return false;

        case TV_4:
            trivium_pair(FR_4, FR_QUOT);
            return false;

        case TV_5:
            /*
             * We deliberately keep 5 for both states for now.
             * This is the "free" Shift+5 position in the Trivium design.
             */
            trivium_pair(FR_5, FR_5);
            return false;

        case TV_6:
            trivium_pair(FR_6, FR_MINS);
            return false;

        case TV_7:
            trivium_pair(FR_7, FR_EGRV);
            return false;

        case TV_8:
            trivium_pair(FR_8, FR_UNDS);
            return false;

        case TV_9:
            trivium_pair(FR_9, FR_CCED);
            return false;

        case TV_0:
            trivium_pair(FR_0, FR_AGRV);
            return false;


        /*
         * Trivium punctuation pairs
         */

        case TV_COMM:
            trivium_pair(FR_COMM, FR_SCLN);
            return false;

        case TV_DOT:
            trivium_pair(FR_DOT, FR_COLN);
            return false;

        case TV_QUES:
            trivium_pair(FR_QUES, FR_EXLM);
            return false;

        case TV_QUOT:
            trivium_pair(FR_QUOT, FR_DQUO);
            return false;


        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }

    return true;
}
