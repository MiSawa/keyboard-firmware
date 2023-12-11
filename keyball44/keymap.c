#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
    LAYER_WORKMAN,
    LAYER_QWERTY,
    LAYER_BROWSE,
    LAYER_LOWER,
    LAYER_UPPER,
    LAYER_ADJUST,
};
enum user_keycodes {
    MO_PREC = QK_USER_0, // Momentarily enter precision mode
};

#define OOOOOOO KC_TRNS
#define XXXXXXX KC_NO

#define KC_HENK KC_INT4
#define KC_MHEN KC_INT5

#define MO_LOWER MO(LAYER_LOWER)
#define MO_RAISE MO(LAYER_UPPER)
#define MO_ADJ MO(LAYER_ADJUST)
#define MO_BRWS MO(LAYER_BROWSE)
#define TG_BRWS TG(LAYER_BROWSE)
#define DF_QWERT DF(LAYER_QWERTY)
#define DF_WORK DF(LAYER_WORKMAN)

#define LALTMHEN ALT_T(KC_MHEN)
#define RALTHENK RALT_T(KC_HENK)
#define LCTLHENK LCTL_T(KC_HENK)

#define LCTLDEL LCTL_T(KC_DEL)
#define RCTLBSPC RCTL_T(KC_BSPC)

#define LOWERSPC LT(LAYER_LOWER, KC_SPC)
#define RAISEENT LT(LAYER_UPPER, KC_ENT)
#define BRWSHNK LT(LAYER_BROWSE, KC_HENK)

// clang-format off
const uint16_t PROGMEM keymaps[DYNAMIC_KEYMAP_LAYER_COUNT][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_WORKMAN] = LAYOUT_right_ball(
    KC_TAB   , KC_Q     , KC_D     , KC_R     , KC_W     , KC_B     ,                                        KC_J     , KC_F     , KC_U     , KC_P     , KC_SCLN  , KC_BSLS  ,
    KC_LCTL  , KC_A     , KC_S     , KC_H     , KC_T     , KC_G     ,                                        KC_Y     , KC_N     , KC_E     , KC_O     , KC_I     , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_M     , KC_C     , KC_V     ,                                        KC_K     , KC_L     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
                          LALTMHEN , LCTLHENK      , KC_DEL   , LOWERSPC , KC_SPC   ,                   KC_BSPC  , RAISEENT ,                            BRWSHNK
  ),

  [LAYER_QWERTY] = LAYOUT_right_ball(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSLS  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
                          LALTMHEN , LCTLHENK      , KC_DEL   , LOWERSPC , KC_SPC   ,                   KC_BSPC  , RAISEENT ,                            BRWSHNK
  ),

  [LAYER_BROWSE] = LAYOUT_right_ball(
    OOOOOOO  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_WFWD  , XXXXXXX  , SCRL_MO  , MO_PREC  , KC_VOLD  , KC_VOLU  ,
    OOOOOOO  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_WBAK  , KC_BTN1  , KC_BTN3  , KC_BTN2  , KC_MUTE  , TG_BRWS  ,
    OOOOOOO  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_WREF  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , OOOOOOO  ,
                          XXXXXXX  , XXXXXXX       , XXXXXXX  , OOOOOOO  , XXXXXXX  ,                   XXXXXXX  , OOOOOOO  ,                            XXXXXXX
  ),

  [LAYER_LOWER] = LAYOUT_right_ball(
    KC_ESC   , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  ,                                        KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  , KC_DEL   ,
    OOOOOOO  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_GRV   , KC_MINUS , KC_EQL   , KC_LCBR  , KC_RCBR  , KC_GRV   ,
    OOOOOOO  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_TILD  , KC_UNDS  , KC_PLUS  , KC_LBRC  , KC_RBRC  , KC_TILD  ,
                          OOOOOOO  , OOOOOOO       , OOOOOOO  , OOOOOOO  , OOOOOOO  ,                   OOOOOOO  , OOOOOOO  ,                            OOOOOOO
  ),

  [LAYER_UPPER] = LAYOUT_right_ball(
    OOOOOOO  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                        KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    OOOOOOO  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                        KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_F12   ,
    OOOOOOO  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT , XXXXXXX  , OOOOOOO  ,
                          OOOOOOO  , OOOOOOO       , OOOOOOO  , OOOOOOO  , OOOOOOO  ,                   OOOOOOO  , OOOOOOO  ,                            OOOOOOO
  ),

  [LAYER_ADJUST] = LAYOUT_right_ball(
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        DF_WORK  , DF_QWERT , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX  , SCRL_DVI , SCRL_DVD , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , XXXXXXX  , KBC_SAVE ,
                          QK_BOOT  , KBC_RST       , XXXXXXX  , OOOOOOO  , XXXXXXX  ,                   XXXXXXX  , OOOOOOO  ,                            XXXXXXX
  ),
};
// clang-format on

layer_state_t layer_state_set_user(const layer_state_t state) {
    return update_tri_layer_state(state, LAYER_LOWER, LAYER_UPPER, LAYER_ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t* const record) {
    // strip QK_MODS part.
    if (keycode >= QK_MODS && keycode <= QK_MODS_MAX) {
        keycode &= 0xff;
    }

    switch (keycode) {
        case MO_PREC: {
            static uint8_t cpi_saved        = 0;
            static uint8_t scroll_div_saved = 0;
            if (record->event.pressed) {
                if (cpi_saved == 0) {
                    cpi_saved        = keyball_get_cpi();
                    scroll_div_saved = keyball_get_scroll_div();
                    keyball_set_cpi(PRECISION_MODE_CPI / 100);
                    keyball_set_scroll_div(PRECISION_MODE_SCROLL_DIV);
                }
            } else {
                if (cpi_saved != 0) {
                    keyball_set_cpi(cpi_saved);
                    keyball_set_scroll_div(scroll_div_saved);
                    cpi_saved             = 0;
                    scroll_div_saved      = 0;
                    keyball.this_motion.x = 0;
                    keyball.this_motion.y = 0;
                    keyball.that_motion.x = 0;
                    keyball.that_motion.y = 0;
                }
            }
            return false;
        }
    }
    return true;
}
