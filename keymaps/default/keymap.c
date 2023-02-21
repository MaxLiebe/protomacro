#include QMK_KEYBOARD_H

#define BASE_LAYER 0 //Default (base) layer
#define NUMPAD_LAYER 1 //Specially defined numpad layer
//#define THIRD_LAYER 2 //Etc...

//Used for unicode characters, can be removed if you don't have any.
enum unicode_names {
    PIZZA,
    MOON
};

//Used for unicode characters, can be removed if you don't have any.
const uint32_t unicode_map[] PROGMEM = {
    [PIZZA]  = 0x1F355, //These are hexadecimal unicode codes, you can find them on https://symbl.cc/en/
    [MOON] = 0x1F315
};

//Enum list of all the macros. If you want to create a macro, add it here and in process_record_user add its functionality.
enum custom_keycodes {
    HELLO,
    SWITCH_TO_NUMPAD
};

//Basically where you define macros. Check the QMK documentation to learn more.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HELLO:
            if (record->event.pressed) {
                //When the key is pressed, type out the string "Hello, world!".
                SEND_STRING("Hello, world!");
            }else {
                //Do something when the key is released.
            }
            break;
        case SWITCH_TO_NUMPAD:
            if (record->event.pressed) {
                //When the key is pressed, tap the numlock button (press + release) and toggle the numpad layer
                tap_code(KC_NUM);  //Tap the numlock key
                layer_invert(NUMPAD_LAYER); //Toggle the numpad layer
            }
            break;
    }

    return true;
}

//The keymap for every layer. This is where the magic happens :)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┐ ___
     * │ A │ B │C  │ K │ 
     * ├───┼───┼───┤ ───
     * │ D │ E │ F │
     * ├───┼───┼───┤ ___
     * │ G │ H │ I │ J │ Yes, the rotary encoders can act as buttons too!
     * └───┴───┴───┘ ───
     */
    [BASE_LAYER] = LAYOUT_proto(
        //Keys A to I:
        KC_A,    KC_B,    KC_C,
        KC_D,    KC_E,    KC_F,
        KC_G,    KC_H,    KC_I,

        //Keys J & K, aka the keys that get pressed when you press in the rotary knobs.
        KC_J,    KC_K
    ),
    //The second, numpad layer
    [NUMPAD_LAYER] = LAYOUT_proto(
        KC_KP_1, KC_KP_2, KC_KP_3,
        KC_KP_4, KC_KP_5, KC_KP_6,
        KC_KP_7, KC_KP_8, KC_KP_9,

        KC_KP_0, KC_TRANSPARENT
    )/*,
    [THIRD_LAYER] = LAYOUT_proto(
        KC_A, KC_A, KC_A, 
        KC_A, KC_A, KC_A, 
        KC_A, KC_A, KC_A, 

        KC_A, KC_A, 
    ) //etc...
    */
};

//#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE_LAYER] =   { 
        ENCODER_CCW_CW(KC_L, KC_M),  //Top encoder. (Clockwise, Counter clockwise)
        ENCODER_CCW_CW(KC_N, KC_O)   //Bottom encoder. (Clockwise, Counter clockwise)
    },
    [NUMPAD_LAYER] =   {
        ENCODER_CCW_CW(KC_TRANSPARENT, KC_TRANSPARENT),
        ENCODER_CCW_CW(KC_TRANSPARENT, KC_TRANSPARENT)  
    },
};
//#endif