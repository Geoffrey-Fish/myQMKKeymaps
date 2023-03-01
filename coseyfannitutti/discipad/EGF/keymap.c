#include QMK_KEYBOARD_H

#define _BL 0

/*
_CALC layer
 *----------------------------------------*
  |Rotary   |Divide    |Multi     |CALC   |
 *----------------------------------------*
  |    7    |     8    |     9    |  BSPC |
 *----------------------------------------*
  |    4    |     5    |     6    |Minus  |
 *----------------------------------------*
  |    1    |     2    |     3    |Plus   |
 *----------------------------------------*
  |    0    |     00   |     ,    |Enter  |
 *----------------------------------------*
 
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_numpad_5x4_full(
      KC_NUM,  KC_PSLS, KC_PAST, KC_CALC, 
      KC_P7,   KC_P8,   KC_P9,   KC_BSPC,      
      KC_P4,   KC_P5,   KC_P6,   KC_PMNS, 
      KC_P1,   KC_P2,   KC_P3,   KC_PPLS,      
      KC_P0,   KC_P00,  KC_PDOT, KC_PENT  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_P00:
      if (record->event.pressed) {
        register_code(KC_P0);
        unregister_code(KC_P0);
        register_code(KC_P0);
        return false;
      } else {
        unregister_code(KC_P0);
      }
      break;
  }
  return true;
}