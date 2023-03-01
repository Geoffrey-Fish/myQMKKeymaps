
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum custom_kc{
    LAYER_DEC = SAFE_RANGE,
    LAYER_INC,
    MUTEC,
    MUTEM,
    MUTEB,
    SEAC,
    SHOT
};

enum layer_names {
   _One,
   _Two,
   _Three,
   _Four,
   _Five,
   _Six
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Shortcuts--C(KC_F8) is deepl translator shortcut*/
    [_One] = LAYOUT(
        RGB_TOG,       SEAC,     C(KC_F8),     KC_CALC,    KC_ESC
    ),
    /*Arrow key*/
    [_Two] = LAYOUT(
        RGB_TOG,       KC_LEFT,    KC_UP,    KC_DOWN,    KC_RIGHT
    ),
    /*Teams controll*/
    [_Three] = LAYOUT(
        RGB_TOG,       MUTEM,    MUTEC,    MUTEB,    SHOT
    ),
    /*Lights*/
    [_Four] = LAYOUT(
        RGB_TOG,       RGB_M_P,    RGB_M_R,    RGB_M_K,    RGB_M_B
    ),
    /*Valheim Plus config*/
    [_Five] = LAYOUT(
        RGB_TOG,       KC_F1,    KC_F5,    KC_F6,    KC_F7
        ),
    /*Undef layer play-pause,controllpanel,assistant,execute*/
    [_Six] = LAYOUT(
        RGB_TOG,       KC_MPLY,  /*  KC_CPNL,    KC_ASST,    KC_EXEC  doas nothing*/
        )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_One] =    { ENCODER_CCW_CW(LAYER_INC,LAYER_DEC) },
    [_Two] =    { ENCODER_CCW_CW(LAYER_INC,LAYER_DEC) },
    [_Three] =  { ENCODER_CCW_CW(LAYER_INC,LAYER_DEC) },
    [_Four] =   { ENCODER_CCW_CW(LAYER_INC,LAYER_DEC) },
    [_Five] =   { ENCODER_CCW_CW(LAYER_INC,LAYER_DEC) },
    [_Six] =    { ENCODER_CCW_CW(LAYER_INC,LAYER_DEC) }
};

#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record){
    uint8_t current_layer = get_highest_layer(layer_state);
    if (record->event.pressed){
        switch (keycode) {
            case LAYER_DEC: //one layer down
                layer_off(current_layer);
                return false;
                break;
            case LAYER_INC: // one layer up
                layer_on(current_layer+1);
                return false;
                break;
            case MUTEM: // micro mute teams powertoys
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_A) SS_UP(X_LGUI) SS_UP(X_LSFT));
                return false;
                break;
            case MUTEC: // cam mute teams powertoys
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_O) SS_UP(X_LGUI) SS_UP(X_LSFT));
                return false;
                break;
            case MUTEB: // both mute teams powertoys
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_Q) SS_UP(X_LGUI) SS_UP(X_LSFT));
                return false;
                break;
            case SEAC: // start quicksearch powortoys
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_SPACE) SS_UP(X_LALT));
                return false;
                break;
            case SHOT: // screenshot powertoys
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_S) SS_UP(X_LGUI) SS_UP(X_LSFT));
                return false;
                break;
            default:
                return true;
                break;

        }
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if (IS_LAYER_ON(_One)) {
                return true;
            } else {
                tap_code16(LAYER_DEC);
                return false;
            };
        } else {
            if(IS_LAYER_ON(_Six)) {
                return true;
            } else {
                tap_code16(LAYER_INC);
                return false;
            }
        }
    }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _One:/*shortcuts*/
        rgblight_setrgb(RGB_BLUE);
        break;
    case _Two:/*arrows*/
        rgblight_setrgb(RGB_ORANGE);
        break;
    case _Three:/*teams*/
        rgblight_setrgb(RGB_PURPLE);
        break;
    case _Four:/*lights*/
        rgblight_setrgb(RGB_YELLOW);
        break;
    case _Five:/*valheim*/
        rgblight_setrgb(RGB_GREEN);
        break;
    case _Six:/*misc*/
        rgblight_setrgb(RGB_RED);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb(RGB_WHITE);
        break;
    }
  return state;
}
