#include QMK_KEYBOARD_H


#define _DEFAULT 0
#define _NUMBER 1
#define _SYMBOL 2
#define _NAV 3
#define _SECRET 4
#define _PROG 5

#define MY_MACRO KC_MINS, KC_GT

enum custom_keycodes {
    DEFAULT = SAFE_RANGE,
    NUMBER,
    SYMBOL,
    NAV,
    SECRET,
    PROG
};

enum {
    ARROW = SAFE_RANGE,
    SQ_BKT,
    PRN,
    CBR,
    DBL_ARW
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case ARROW:
            SEND_STRING("->");
            break;
        case SQ_BKT:
            SEND_STRING("[]");
            register_code(KC_LEFT);  // Press the left arrow key
            unregister_code(KC_LEFT);
            break;
        case PRN:
            SEND_STRING("()");
            register_code(KC_LEFT);  // Press the left arrow key
            unregister_code(KC_LEFT);
            break;
        case CBR:
            SEND_STRING("{}");
            register_code(KC_LEFT);  // Press the left arrow key
            unregister_code(KC_LEFT);
            break;
        case DBL_ARW:
            SEND_STRING("=>");
            break;
    }
    return true;
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_DEFAULT] = LAYOUT(
    KC_TAB,            KC_Q,         KC_W,         KC_E,         KC_R,            KC_T,                            KC_Y,            KC_U,               KC_I,               KC_O,         KC_P,            KC_BSPC, 
    LT(PROG, KC_ESC),  LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F),    KC_G,                            KC_H,            RCTL_T(KC_J),       RSFT_T(KC_K),       LALT_T(KC_L), RGUI_T(KC_SCLN), MO(PROG), 
    KC_LSFT,           KC_Z,         KC_X,         KC_C,         KC_V,            KC_B,                            KC_N,            KC_M,               KC_COMM,            KC_DOT,       KC_SLSH,         _______, 
                                                   KC_LCTL,      KC_LGUI,         LT(NUMBER,KC_ENT),               LT(NAV, KC_SPC), LT(SYMBOL, KC_TAB), MT(MOD_RALT, KC_BSPC)
),

[_NUMBER] = LAYOUT(
    _______, KC_1,  KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8, KC_9, KC_0,    _______, 
    _______, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, _______,                        KC_PAST, KC_4,    KC_5, KC_6, KC_PLUS, KC_PEQL, 
    _______, KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, _______,                        KC_PSLS, KC_1,    KC_2, KC_3, KC_PMNS, _______, 
                             _______, _______, _______,                        _______, _______, KC_0
),

[_SYMBOL] = LAYOUT(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, 
    KC_TILD, KC_MINS, KC_EQL,  KC_QUOT, KC_DQUO, KC_BSLS,                       KC_SLSH, KC_UNDS, KC_PLUS, _______, KC_PIPE, _______, 
    _______, _______, KC_COMM, KC_DOT,  KC_QUES, _______,                      _______, _______, _______, _______, _______, _______, 
                               _______, _______, _______,                      _______, _______, KC_DEL
),

[_NAV] = LAYOUT(
    _______, KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_PSCR,                         KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, KC_DEL, 
    _______, KC_F5, KC_F6,  KC_F7,   KC_F8,   _______,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_VOLU, 
    _______, KC_F9, KC_F10, KC_F11,  KC_F12,  _______,                         _______, _______, _______, _______, _______, KC_VOLD, 
                            _______, _______, KC_MNXT,                         _______, KC_MPLY, KC_DEL
),

[_PROG] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, 
    _______, ARROW,   SQ_BKT,  PRN,     CBR,     DBL_ARW,                       _______, KC_F13,  KC_F14,  KC_F15, _______, _______, 
    _______, _______, _______, _______, _______, _______,                      _______, KC_F16,  KC_F17,  KC_F18, _______, _______, 
                               _______, _______, _______,                      _______, _______, _______) 

};
