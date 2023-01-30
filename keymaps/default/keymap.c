#include QMK_KEYBOARD_H

enum unicode_names {
    PIZZA,
    MOON
};

const uint32_t unicode_map[] PROGMEM = {
    [PIZZA]  = 0x1F355,  // ‽
    [MOON] = 0x1F315
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐
     * │ A │ B │ C │
     * ├───┼───┼───┤
     * │ D │ E │ F │
     * ├───┼───┼───┤
     * │ G │ H │ I │
     * └───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x3(
        KC_A,    KC_B,    KC_C,
        KC_D,    KC_E,    KC_F,
        KC_G,    KC_H,    KC_I
    )
};

//#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { 
        ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), 
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  
    }
};
//#endif