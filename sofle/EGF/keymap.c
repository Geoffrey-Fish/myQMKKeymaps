#include <stdio.h>
#include QMK_KEYBOARD_H
#include "keymap_german.h"

#pragma region shortcuts
#define BOB 0x00B7    // ·
#define ENDASH 0x2013 // – en dash
#define SCRL 0x2113   // ℓ
#define LOW9 0x201E   // „
#define HIG6 0x201C   // “
#define HIG9 0x201D   // ”
#define EMDASH 0x2014 // — em dash
#define SSS 0x00DF    // ß
#define UHR 0x27F3    // ⟳
#define CUHR 0x27F2   // ⟲
#define LSQ 0x201A    // ‚
#define HSQ 0x2018    // ‘
#define RSQ 0x2019    // ’
#define QLA 0x203A    // ›
#define QRA 0x2039    // ‹
#define CENT 0x00A2   // ¢
#define YEN 0x00A5    // ¥
#define REQ 0x00BB    // »
#define LEQ 0x00AB    // «
#define HI1 0x00B9    // ¹
#define HI2 0x00B2    // ²
#define HI3 0x00B3    // ³
#pragma endregion
/*
#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations individual setting the first number is the first light to adress,
// and the second is the amount of leds to be lit
// Ich nehme hier an dass das die adressen der leds sind.trial and error 
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  11  |  12  |  21  |  22  |  31  |  32  |                    |  47  |  48  |  57  |  58  |  67  |  68  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  10  |  13  |  20  |  23  |  30  |  33  |                    |  46  |  49  |  56  |  59  |  66  |  69  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   9  |  14  |  19  |  24  |  29  |  34  |-------.    ,-------|  45  |  50  |  55  |  60  |  65  |  70  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |   8  |  15  |  18  |  25  |   28 |  35  |-------|    |-------|  44  |  51  |  54  |  61  |  64  |  71  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *             | 7   |  16  |  17  |  26  | /  27   /       \  43  \  |  52  |  53  |  62  |  63  |
     *             |     |      |      |      |/       /         \      \ |      |      |      |      |
     *             `----------------------------------'           '------''---------------------------'
    {
        {  11,  12,  21,  22,  31,  32 },      {  47,  48,  57,  58,  67,  68},
        {  10,  13,  20,  23,  30,  33 },      {  46,  49,  56,  59,  66,  69},
        {  9,   14,  19,  24,  29,  34},       {  45,  50,  55,  60,  65,  70},
        {  8,   15,  18,  25,  28,  35},       {  44,  51,  54,  61,  64,  71},
        {  7,   16,  17,  26,  27,  NO_LED },  {  43,  52,  53,  62,  63,  NO_LED }
    },
     
#define SET_LV3_BUTTON(hsv) \
    {9,1,hsv}, \
    {70, 1, hsv}

#define SET_LV2_BUTTON(hsv) \
    {71, 1,hsv}

#define SET_LV4_BUTTON(hsv) \
    {62,1,hsv}

#define SET_FKEY_BUTTON(hsv) \
    {10,1,hsv}

#define SET_QUERZ_BUTTON(hsv) \
    {68,1,hsv}

#define SET_NUMPAD(hsv)     \
	{49, 3, hsv},\
	{50, 3, hsv},\
	{51, 3, hsv}

#define SET_FKEY_ROW(hsv) \
	{11, 6, hsv}, \
	{47, 6, hsv}

#define SET_LOREM_ROW(hsv) \
    {11,4,hsv},\
    {10,1,hsv}

#define SET_ARROW_BUTTON(hsv)\
    {13,1,hsv},\
    {9,3,hsv}

#define SET_THUMB_CLUSTER(hsv) 	\
	{7, 5, hsv}, \
	  {43, 5, hsv}

#define SET_LAYER_ID(hsv) 	\
    {11,29,hsv},\
    {47,29, hsv}
*/
enum rgb_matrix_effects {
    RGB_MATRIX_NONE = 0,
    RGB_MATRIX_SOLID_COLOR = 1,     // Static single hue, no speed support
    RGB_MATRIX_ALPHAS_MODS,         // Static dual hue, speed is hue for secondary hue
    RGB_MATRIX_GRADIENT_UP_DOWN,    // Static gradient top to bottom, speed controls how much gradient changes
    RGB_MATRIX_GRADIENT_LEFT_RIGHT,    // Static gradient left to right, speed controls how much gradient changes
    RGB_MATRIX_BREATHING,           // Single hue brightness cycling animation
    RGB_MATRIX_BAND_SAT,        // Single hue band fading saturation scrolling left to right
    RGB_MATRIX_BAND_VAL,        // Single hue band fading brightness scrolling left to right
    RGB_MATRIX_BAND_PINWHEEL_SAT,   // Single hue 3 blade spinning pinwheel fades saturation
    RGB_MATRIX_BAND_PINWHEEL_VAL,   // Single hue 3 blade spinning pinwheel fades brightness
    RGB_MATRIX_BAND_SPIRAL_SAT,     // Single hue spinning spiral fades saturation
    RGB_MATRIX_BAND_SPIRAL_VAL,     // Single hue spinning spiral fades brightness
    RGB_MATRIX_CYCLE_ALL,           // Full keyboard solid hue cycling through full gradient
    RGB_MATRIX_CYCLE_LEFT_RIGHT,    // Full gradient scrolling left to right
    RGB_MATRIX_CYCLE_UP_DOWN,       // Full gradient scrolling top to bottom
    RGB_MATRIX_CYCLE_OUT_IN,        // Full gradient scrolling out to in
    RGB_MATRIX_CYCLE_OUT_IN_DUAL,   // Full dual gradients scrolling out to in
    RGB_MATRIX_RAINBOW_MOVING_CHEVRON,  // Full gradient Chevron shapped scrolling left to right
    RGB_MATRIX_CYCLE_PINWHEEL,      // Full gradient spinning pinwheel around center of keyboard
    RGB_MATRIX_CYCLE_SPIRAL,        // Full gradient spinning spiral around center of keyboard
    RGB_MATRIX_DUAL_BEACON,         // Full gradient spinning around center of keyboard
    RGB_MATRIX_RAINBOW_BEACON,      // Full tighter gradient spinning around center of keyboard
    RGB_MATRIX_RAINBOW_PINWHEELS,   // Full dual gradients spinning two halfs of keyboard
    RGB_MATRIX_RAINDROPS,           // Randomly changes a single key's hue
    RGB_MATRIX_JELLYBEAN_RAINDROPS, // Randomly changes a single key's hue and saturation
    RGB_MATRIX_HUE_BREATHING,       // Hue shifts up a slight ammount at the same time, then shifts back
    RGB_MATRIX_HUE_PENDULUM,        // Hue shifts up a slight ammount in a wave to the right, then back to the left
    RGB_MATRIX_HUE_WAVE,            // Hue shifts up a slight ammount and then back down in a wave to the right
    RGB_MATRIX_PIXEL_FRACTAL,       // Single hue fractal filled keys pulsing horizontally out to edges
    RGB_MATRIX_PIXEL_FLOW,          // Pulsing RGB flow along LED wiring with random hues
    RGB_MATRIX_PIXEL_RAIN,          // Randomly light keys with random hues
#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
    RGB_MATRIX_TYPING_HEATMAP,      // How hot is your WPM!
    RGB_MATRIX_DIGITAL_RAIN,        // That famous computer simulation
#endif
#if defined(RGB_MATRIX_KEYPRESSES) || defined(RGB_MATRIX_KEYRELEASES)
    RGB_MATRIX_SOLID_REACTIVE_SIMPLE,   // Pulses keys hit to hue & value then fades value out
    RGB_MATRIX_SOLID_REACTIVE,      // Static single hue, pulses keys hit to shifted hue then fades to current hue
    RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
    RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
    RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
    RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
    RGB_MATRIX_SPLASH,              // Full gradient & value pulse away from a single key hit then fades value out
    RGB_MATRIX_MULTISPLASH,         // Full gradient & value pulse away from multiple key hits then fades value out
    RGB_MATRIX_SOLID_SPLASH,        // Hue & value pulse away from a single key hit then fades value out
    RGB_MATRIX_SOLID_MULTISPLASH,   // Hue & value pulse away from multiple key hits then fades value out
#endif
    RGB_MATRIX_EFFECT_MAX
};
// Naming aliases for layers
enum sofle_layers {
    _vou =0,
    _VOU,
    _LEVEL3,
    _LEVEL4,
    _QWERTZ,
    _FKEY
};
// naming aliases for special keycodes
enum custom_keycodes {
    P_LOREM = SAFE_RANGE, 
    LENNYF, 
    FLIP,
    SHRUG,
    DCOM,
    SHOT 
};
// Tap Dance declarations
enum tap_dance_actions{
     TD_ENT_SPC = 0,
     TD_TIC_ESC 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ^/ESC|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |QWERTZ|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |TB/FKY|   v  |   .  |   o  |   u  |   ä  |                    |   q  |   g  |   l  |   h  |   f  |  j   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |   c  |   a  |   e  |   i  |   y  |-------.    ,-------|   b  |   t  |   r  |   n  |   s  | ß/LV3|
     * |------+------+------+------+------+------|   flayer    |    | SHOT  |------+------+------+------+------+------|
     * |SHIFT |   z  |   x  |   ,  |   ö  |   ü  |-------|    |-------|   p  |   d  |   w  |   m  |   k  | LV2  |                                  
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *           | PGDOWN| LAlt | LGUI |LCTRL | /Space  /       \Enter \  |BSPC  |DEL   | LV4  | PGUP  |
     *           |       |      |      |      |/       /         \      \ |      |      |      |       |
     *           ------------------------------------'           '------''----------------------------'
     */

    [_vou] = LAYOUT(
        TD(TD_TIC_ESC),    DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                             DE_6,    DE_7,   DE_8,        DE_9,    DE_0, TG(_QWERTZ),
        LT(_FKEY, KC_TAB), DE_V,    DE_DOT,  DE_O,    DE_U,    DE_ADIA,                          DE_Q,    DE_G,   DE_L,        DE_H,    DE_F, DE_J,
        MO(_LEVEL3),       DE_C,    DE_A,    DE_E,    DE_I,    DE_Y,                             DE_B,    DE_T,   DE_R,        DE_N,    DE_S, MO(_LEVEL3),
        KC_LSFT,           DE_Z,    DE_X,    DE_COMM, DE_ODIA, DE_UDIA, TG(_FKEY),          SHOT,  DE_P,    DE_D,   DE_W,        DE_M,    DE_K, TT(_VOU),
                                    KC_PGDN, KC_LALT, KC_LGUI, KC_LCTL, KC_SPC,  TD(TD_ENT_SPC), KC_BSPC, KC_DEL, TT(_LEVEL4), KC_PGUP
    ),
    /* VOU
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |   ̌Uhr|   °  |   §  |   ℓ  |   »  |  «   |                    |   $  |   €  |   „  |   ”  |  “   |  ß   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  TAB |   V  |   •  |   O  |   U  |   Ä  |                    |   Q  |   G  |   L  |   H  |  F   |  J   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |   C  |   A  |   E  |   I  |   Y  |-------.    ,-------|   B  |   T  |   R  |   N  |  S   |  LV3 |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | SHIFT|   Z  |   X  |   –  |  Ö   |   Ü  |-------|    |-------|   P  |   D  |   W  |   M  |  K   |  LV2 |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *             | nr5 | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  | nr5  |
     *             |     |      |      |      |/       /         \      \ |      |      |      |      |
     *             `----------------------------------'           '------''---------------------------'
     */
    [_VOU] = LAYOUT(
        UC(CUHR), DE_DEG,  DE_SECT, UC(SCRL),   UC(REQ),    UC(LEQ),                          DE_DLR,  DE_EURO, UC(LOW9), UC(HIG6), UC(HIG9), UC(SSS),
        KC_TAB,   S(DE_V), UC(BOB), S(DE_O),    S(DE_U),    S(DE_ADIA),                       S(DE_Q), S(DE_G), S(DE_L),  S(DE_H),  S(DE_F),  S(DE_J),
        KC_TRNS,  S(DE_C), S(DE_A), S(DE_E),    S(DE_I),    S(DE_Y),                          S(DE_B), S(DE_T), S(DE_R),  S(DE_N),  S(DE_S),  KC_TRNS,
        KC_TRNS,  S(DE_Z), S(DE_X), UC(ENDASH), S(DE_ODIA), S(DE_UDIA), KC_TRNS,     KC_TRNS, S(DE_P), S(DE_D), S(DE_W),  S(DE_M),  S(DE_K),  KC_TRNS,
                           KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
    ),
    /* LEVEL3
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ⟳   |   ¹  |   ²  |  ³   |  ›   |   ‹  |                    |   ¢  |   ¥  |   ‚  |  ‘   |  ’   |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  TAB |   ^  |   _  |  {   |   }  |   @  |                    |   !  |   <  |   >  |   =  |   &  |  %   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |   \  |   /  |  (   |   )  |   *  |-------.    ,-------|   ?  |   :  |   ;  |   -  |   :  |  LV3 |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | SHIFT|   #  |   ~  |  [   |   ]  |   $  |-------|    |-------|   +  |   "  |   '  |   |  |   +  |  LV2 |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *             | nr5 | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  | nr5  |
     *             |     |      |      |      |/       /         \      \ |      |      |      |      |
     *             `----------------------------------'           '------''---------------------------'
     */

    [_LEVEL3] = LAYOUT(
        UC(UHR), UC(HI1), UC(HI2), UC(HI3), UC(QLA), UC(QRA),                     UC(CENT), UC(YEN), UC(LSQ), UC(HSQ), UC(RSQ), DE_MINS,
        KC_TAB,  DE_CIRC, DE_UNDS, DE_LCBR, DE_RCBR, DE_AT,                       DE_EXLM,  DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_PERC,
        KC_TRNS, DE_BSLS, DE_SLSH, DE_LPRN, DE_RPRN, DE_ASTR,                     DE_QUES,  DE_COLN, DE_SCLN, DE_MINS, DE_COLN, KC_TRNS,
        KC_TRNS, DE_HASH, DE_TILD, DE_LBRC, DE_RBRC, DE_DLR, KC_TRNS,    KC_TRNS, DE_PLUS,  DE_DQUO, DE_QUOT, DE_PIPE, DE_PLUS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* LEVEL4
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Lorem|lenny |FLIP  |SHRUG | sleep|power |                    |  rain    |  knight    |      |      |      |Velocikey|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | .com | pgup |  up  | pgdn | pos1 |      |                    |   spiral   |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |  lft |  dwn |  rgt |  ende|  Mute|-------.    ,-------|  HEAT|RGB ON| HUE+ | SAT+ | VAL+ |  LV3 |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | SHIFT|      |      |      |      |      |-------|    |-------|  MUTE| MODE | HUE- | SAT- | VAL- |  LV2 |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *             | nr5 | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  | nr5  |
     *             |     |      |      |      |/       /         \      \ |      |      |      |      |
     *             `----------------------------------'           '------''---------------------------'
     */
    [_LEVEL4] = LAYOUT(
        P_LOREM, LENNYF,  FLIP,    SHRUG,    KC_SLEP, KC_PWR,                    RGB_MATRIX_JELLYBEAN_RAINDROPS, RGB_M_K,  XXXXXXX,  XXXXXXX, XXXXXXX, VK_TOGG,
        DCOM,    KC_PGUP, KC_UP,   KC_PGDN,  KC_HOME, XXXXXXX,                   RGB_MATRIX_CYCLE_SPIRAL,        XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  KC_KB_MUTE,                RGB_MATRIX_PIXEL_FRACTAL, RGB_TOG,  RGB_HUI,  RGB_SAI, RGB_VAI, KC_TRNS, 
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_NO,   KC_TRNS, XXXXXXX,                   RGB_MOD,  RGB_HUD,  RGB_SAD, RGB_VAD, KC_TRNS,
                          KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /* QWERTZ
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  vou |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |  Ü   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |CAPS  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |SHIFT |   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *             | nr5 | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  | nr5  |
     *             |     |      |      |      |/       /         \      \ |      |      |      |      |
     *             `----------------------------------'           '------''---------------------------'
     */

    [_QWERTZ] = LAYOUT(
         KC_ESC,  DE_1, DE_2, DE_3, DE_4, DE_5,                  DE_6, DE_7, DE_8, DE_9, DE_0, KC_TRNS,
         KC_TAB,  DE_Q, DE_W, DE_E, DE_R, DE_T,                  DE_Z, DE_U, DE_I, DE_O, DE_P, DE_UDIA,
         KC_CAPS, DE_A, DE_S, DE_D, DE_F, DE_G,                  DE_H, DE_J, DE_K, DE_L, DE_ODIA, DE_ADIA,
         KC_LSFT, DE_Y, DE_X, DE_C, DE_V, DE_B, KC_TRNS,    SHOT, DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS, KC_RSFT,
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /* FKEY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | .com |      |      |      |      |                    |   *  |   7  |   8  |   9  |   -  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|   /  |   4  |   5  |   6  |   +  |   -  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |   =  |   .  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *             | nr5 | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  | nr5  |
     *             |     |      |      |      |/       /         \      \ |      |      |      |      |
     *             `----------------------------------'           '------''---------------------------'
     */
    [_FKEY] = LAYOUT(
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
         _______, DCOM,    _______, _______, _______, _______,                      KC_PAST, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, KC_NO,
         _______, _______, _______, _______, _______, _______,                      KC_PSLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_TILD,
         _______, _______, _______, _______, _______, _______, _______,    KC_TRNS, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_KP_DOT,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
/*
#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];// war mal 70

const rgblight_segment_t PROGMEM layer_vou_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_GREEN),
  SET_LV3_BUTTON(HSV_BLUE),
  SET_LV2_BUTTON(HSV_TEAL),
  SET_LV4_BUTTON(HSV_YELLOW),
  SET_FKEY_BUTTON(HSV_ORANGE),
  SET_QUERZ_BUTTON(HSV_PURPLE)
);
const rgblight_segment_t PROGMEM layer_VOU_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_TEAL)
);

// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_LEVEL3_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)
);

// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_LEVEL4_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_YELLOW),
    SET_ARROW_BUTTON(HSV_RED),
    SET_LOREM_ROW(HSV_PURPLE)
);

// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_QWERTZ_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD lights
const rgblight_segment_t PROGMEM layer_FKEY_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_FKEY_ROW(HSV_ORANGE),
	SET_NUMPAD(HSV_BLUE)
    );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_vou_lights,
	layer_VOU_lights,
	layer_LEVEL3_lights,
    layer_LEVEL4_lights,
	layer_QWERTZ_lights,
	layer_FKEY_lights  
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _vou));
	rgblight_set_layer_state(1, layer_state_cmp(state, _VOU));
	rgblight_set_layer_state(2, layer_state_cmp(state, _LEVEL3));
	rgblight_set_layer_state(3, layer_state_cmp(state, _LEVEL4));
	rgblight_set_layer_state(4, layer_state_cmp(state, _QWERTZ));
	rgblight_set_layer_state(5, layer_state_cmp(state, _FKEY));

    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way
}

#endif 
*/

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ENT_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_SPC), // Enter or space
    [TD_TIC_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CIRC) // ^^ or ESC
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case P_LOREM:
                SEND_STRING("Yombie ipsum reversus ab viral inferno, nam rick grimes malum cerebro.\n De carne lumbering animata corpora quaeritis.\n De apocalypsi gorger omero undead survivor dictum mauris.\nHi mindless mortuis soulless creaturas, imo evil stalking monstra adventus resi dentevil vultus comedat cerebella viventium.\n Qui animated corpse, cricket bat max brucks terribilem incessu Yombz.\n The voodoo sacerdos flesh eater,exe fiat Jeff becum suscitat mortuos comedere carnem virus.\n Yombi tattered for solum oculi eorum defunctis go lum cerebro.\n Nescio brains an Undead YOMBIES.Sicut malus putrid voodoo horror.\n Nigh tofth eliv ingdead.\n");
                return false;
                break;
            case LENNYF:  // ( ͡° ͜ʖ ͡°)
                SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_L) SS_TAP(X_F) SS_UP(X_RALT));
                return false;
                break;
            case FLIP:  // (ﾉಥ益ಥ）ﾉ彡┻━┻)
                SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_T) SS_TAP(X_F) SS_UP(X_RALT));
                return false;
                break;
            case SHRUG:  // ¯\_(ツ)_/¯
                SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_S) SS_TAP(X_F) SS_UP(X_RALT));
                return false;
                break;
                case DCOM:  // .COM
                SEND_STRING(SS_TAP(X_DOT) SS_TAP(X_C) SS_TAP(X_O) SS_TAP(X_M));
                return false;
                break;
                case SHOT:  // screenshot
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_S) SS_UP(X_LGUI) SS_UP(X_LSFT));
                return false;
                break;
        }
    }
    return true;
}  


// This Oled stuff is a testrun.lets see how it works
#ifdef OLED_ENABLE

static void render_logo(void) {
  /*  static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };*/
    /*
    //Ein paar logos, vielleicht können die rotieren?
    // 32 * 14 os logos*/ 
    static const char PROGMEM windows_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe,0xbe, 0x00,
    0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 
    0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
/*
    const char PROGMEM docker[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70,
    0x70, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x80, 0xb0, 0xb0, 0xb0, 0x80, 0xb7, 0xb7, 0xb7, 0x80, 0xb7, 0xb7, 0xb7, 0x80, 0xb7,
    0xb7, 0xb7, 0x80, 0xb0, 0xb0, 0xb0, 0x80, 0x80, 0xfe, 0xfe, 0xfc, 0xf0, 0xf0, 0xf0, 0x70, 0x00,
    0x03, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
    0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
static const char PROGMEM python[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x7e, 0x66, 0x66, 0x67, 0x7f, 0x7f, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xf0, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x9f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf0,
    0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf9, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x0f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0xfe, 0xfe, 0xe6, 0x66, 0x66, 0x7e, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
static const char PROGMEM js[] = {
    0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0x78, 0x7c, 0x3c, 0x1e, 0x9f,
    0x9e, 0x1e, 0x3c, 0x3c, 0x78, 0xf8, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x03, 0x01, 0xf1, 0xf8, 0xfc, 0xfc, 0x06, 0x06, 0xff, 0x0f,
    0x0f, 0x67, 0x67, 0xe6, 0xcc, 0x8c, 0xf8, 0xf9, 0x01, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x1f, 0x3f, 0x3f, 0x3f, 0x00, 0x80, 0xff, 0xe3,
    0xe2, 0xce, 0xce, 0x4c, 0x64, 0x20, 0x11, 0x9f, 0x80, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0x1f, 0x3c, 0x3c, 0x78, 0x79,
    0xf9, 0x78, 0x3c, 0x3c, 0x1e, 0x1f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00,
};
static const char PROGMEM qmk[] = {
    0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf0, 0xf0, 0xf8, 0xf8, 0xf0, 0xf0, 0xf8,
    0xf8, 0xf0, 0xf0, 0xf8, 0xf8, 0xf0, 0xf0, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00,
    0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf1, 0xf3, 0xe3, 0xe7, 0x00,
    0x00, 0xe7, 0xe3, 0xf3, 0xf1, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f,
    0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00,
};
*/
    oled_write_P(windows_logo, false);
}

static void print_status_narrow(void) {

    oled_write_ln_P(PSTR("Sofle"),false);
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Your"), false); 
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _vou:
            oled_write_ln_P(PSTR("vou"), false);
            break;
        case _VOU:
            oled_write_ln_P(PSTR("VOU"), false);
            break;
        case _LEVEL3:
            oled_write_ln_P(PSTR("NERD"), false);
            break;
        case _LEVEL4:
            oled_write_ln_P(PSTR("Light"), false);
            break;
        case _QWERTZ:
            oled_write_ln_P(PSTR("Qwertz"), false);
            break;
        case _FKEY:
            oled_write_ln_P(PSTR("FKEY"), false);
            break;
        default:
          break;
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("WPM:  "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
           print_status_narrow();
    } else { 
        render_logo ();
    }
    return false;
}
#endif

// Rotary encoder related code
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // Encoder on master side
        if (IS_LAYER_ON(_LEVEL3)) {    
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        }
    } else if (index == 1) { // Encoder on slave side
        if (IS_LAYER_ON(_LEVEL3)) { 
            if (clockwise) {
                tap_code(KC_BSPC);
            } else {
                tap_code(KC_DEL);
            }
        } else {
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
                }
        }
    }
    return true;
}
