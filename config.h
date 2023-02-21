// explanation:
// https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md

#pragma once

//Here we define two encoders. They both share one pin on the Arduino Pro Micro, which is okay for two rotary encoders according to the QMK documentation
#define ENCODERS_PAD_A {F4, F4}
#define ENCODERS_PAD_B {F5, F6}
#define ENCODER_DIRECTION_FLIP

//Uncomment this line if you are on Windows and want to use emojis
//Make sure you have WinCompose installed

//#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
