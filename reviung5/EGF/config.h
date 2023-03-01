#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS  1
#define MATRIX_COLS  5

#define MATRIX_ROW_PINS \
    { F4 }
#define MATRIX_COL_PINS \
    { D4, C6, D7, E6, B4 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Encoder */
#define ENCODERS_PAD_A \
    { D0 }
#define ENCODERS_PAD_B \
    { D1 }

#define RGB_DI_PIN D3

#define RGBLED_NUM         4
#define RGBLIGHT_HUE_STEP  16
#define RGBLIGHT_SAT_STEP  16
#define RGBLIGHT_VAL_STEP  16
#define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#define RGBLIGHT_SLEEP         /* If defined, the RGB lighting will be switched off when the host goes to sleep */
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_PLAIN
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define RGBLIGHT_MAX_LAYERS 6
#define ENCODER_RESOLUTION 4

