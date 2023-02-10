#include QMK_KEYBOARD_H

enum unicode_names {
    PIZZA,
    MOON
};

enum custom_keycodes {
    HELLO
};

const uint32_t unicode_map[] PROGMEM = {
    [PIZZA]  = 0x1F355, 
    [MOON] = 0x1F315
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HELLO:
            if (record->event.pressed) {
                SEND_STRING("Hello, world!\n");
            }
            return false;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * ├───┼───┼───┤
     * │ G │ H │ I │
     * └───┴───┴───┘
     * │ M │   │ N │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x3(
        X(PIZZA),    HELLO,    KC_C,
        KC_D,    KC_E,    KC_F,
        KC_G,    KC_H,    KC_I,
        KC_N,    KC_O
    )
};

//#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { 
        ENCODER_CCW_CW(KC_J, KC_K), 
        ENCODER_CCW_CW(KC_L, KC_M)  
    }
};
//#endif