#include <stdio.h>
#include QMK_KEYBOARD_H
#include "keymap_german.h"

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

// custom_keycodes for strings
enum custom_keycodes { P_LOREM = SAFE_RANGE, LENNYF, FLIP, SHRUG, DCOM,SHOT };
// Tap Dance declarations
enum { TD_ENT_SPC = 0, TD_TIC_ESC };

enum layer_number { _vou = 0, _VOU, _LEVEL3, _LEVEL4, _QWERTZ, _FKEY };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* vou  IDEA: I could really use a dotcom tap macro on the dot and a lorem ipsum boilerplate on another level!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ^/ESC|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |QWERTZ|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |TB/FKY|   v  |   .  |   o  |   u  |   ä  |                    |   q  |   g  |   l  |   h  |   f  |  j   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |   c  |   a  |   e  |   i  |   y  |-------.    ,-------|   b  |   t  |   r  |   n  |   s  | ß/LV3|
     * |------+------+------+------+------+------| mode  |    | SHOT  |------+------+------+------+------+------|
     * |SHIFT |   z  |   x  |   ,  |   ö  |   ü  |-------|    |-------|   p  |   d  |   w  |   m  |   k  | LV2  |                                  
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |BSPC  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_vou] = LAYOUT(
          TD(TD_TIC_ESC),    DE_1, DE_2,   DE_3,    DE_4,    DE_5,                  DE_6, DE_7, DE_8, DE_9, DE_0, TG(_QWERTZ),
          LT(_FKEY, KC_TAB), DE_V, DE_DOT, DE_O,    DE_U,    DE_ADIA,               DE_Q, DE_G, DE_L, DE_H, DE_F, DE_J,
          MO(_LEVEL3),       DE_C, DE_A,   DE_E,    DE_I,    DE_Y,                  DE_B, DE_T, DE_R, DE_N, DE_S, MO(_LEVEL3),
          KC_LSFT,           DE_Z, DE_X,   DE_COMM, DE_ODIA, DE_UDIA, UC_NEXT, SHOT, DE_P, DE_D, DE_W, DE_M, DE_K, TT(_VOU),
                                        KC_LALT, KC_LGUI, KC_LCTL, KC_SPC,      TD(TD_ENT_SPC), KC_BSPC, KC_DEL, TT(_LEVEL4)
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
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_VOU] = LAYOUT(
         UC(CUHR), DE_DEG,  DE_SECT, UC(SCRL),   UC(REQ),    UC(LEQ),                  DE_DLR,  DE_EURO, UC(LOW9), UC(HIG6), UC(HIG9), UC(SSS),
         KC_TAB,   S(DE_V), UC(BOB), S(DE_O),    S(DE_U),    S(DE_ADIA),               S(DE_Q), S(DE_G), S(DE_L),  S(DE_H),  S(DE_F),  S(DE_J),
         KC_TRNS,  S(DE_C), S(DE_A), S(DE_E),    S(DE_I),    S(DE_Y),                  S(DE_B), S(DE_T), S(DE_R),  S(DE_N),  S(DE_S),  KC_TRNS,
         KC_TRNS,  S(DE_Z), S(DE_X), UC(ENDASH), S(DE_ODIA), S(DE_UDIA), KC_NO, KC_TRNS, S(DE_P), S(DE_D), S(DE_W),  S(DE_M),  S(DE_K),  KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_LEVEL3] = LAYOUT(
          UC(UHR), UC(HI1), UC(HI2), UC(HI3), UC(QLA), UC(QRA),              UC(CENT), UC(YEN), UC(LSQ), UC(HSQ), UC(RSQ), DE_MINS,
          KC_TAB,  DE_CIRC, DE_UNDS, DE_LCBR, DE_RCBR, DE_AT,                DE_EXLM,  DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_PERC,
          KC_TRNS, DE_BSLS, DE_SLSH, DE_LPRN, DE_RPRN, DE_ASTR,              DE_QUES,  DE_COLN, DE_SCLN, DE_MINS, DE_COLN, KC_TRNS,
          KC_TRNS, DE_HASH, DE_TILD, DE_LBRC, DE_RBRC, DE_DLR, KC_NO, KC_TRNS, DE_PLUS,  DE_DQUO, DE_QUOT, DE_PIPE, DE_PLUS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* LEVEL4
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Lorem|lenny |FLIP  |SHRUG | sleep|power |                    |breath|mood  | swirl|      |      |velocikey|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | .com | pgup |  up  | pgdn | pos1 |      |                    |snek  |knight| Alter|      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |  lft |  dwn |  rgt |  ende|Mute  |-------.    ,-------|Twinkl|ON/OFF| HUE+ | SAT+ | VAL+ |  LV3 |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | SHIFT|      |      |      |      |      |-------|    |-------|  MUTE| MODE | HUE- | SAT- | VAL- |  LV2 |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LEVEL4] = LAYOUT(
              P_LOREM, LENNYF,  FLIP,    SHRUG,    KC_SLEP, KC_PWR,                   RGB_M_B, RGBLIGHT_MODE_RAINBOW_MOOD, RGB_M_SW,  XXXXXXX, XXXXXXX, VK_TOGG,
              DCOM,    KC_PGUP, KC_UP,   KC_PGDN,  KC_HOME, XXXXXXX,                  RGB_M_SN, RGB_M_K, RGBLIGHT_MODE_ALTERNATING, XXXXXXX, XXXXXXX, XXXXXXX,
              KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  KC_KB_MUTE,               RGB_MODE_TWINKLE,    RGB_TOG,  RGB_HUI,  RGB_SAI, RGB_VAI, KC_TRNS, 
              KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_NO,    KC_TRNS,XXXXXXX , RGB_MOD,  RGB_HUD,  RGB_SAD, RGB_VAD, KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | RALT |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_QWERTZ] = LAYOUT(
         KC_ESC, DE_1, DE_2, DE_3, DE_4, DE_5,                  DE_6, DE_7, DE_8, DE_9, DE_0, KC_TRNS,
         KC_TAB, DE_Q, DE_W, DE_E, DE_R, DE_T,                  DE_Z, DE_U, DE_I, DE_O, DE_P, DE_UDIA,
         KC_CAPS, DE_A, DE_S, DE_D, DE_F, DE_G,                 DE_H, DE_J, DE_K, DE_L, DE_ODIA, DE_ADIA,
         KC_LSFT, DE_Y, DE_X, DE_C, DE_V, DE_B, UC_NEXT,   SHOT, DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS, KC_RSFT,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT
    ),
    /* FKEY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trns | .com |      |      |      |      |                    |   *  |   7  |   8  |   9  |   -  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|   /  |   4  |   5  |   6  |   +  |   -  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |   =  |   .  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_FKEY] = LAYOUT(
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
         _______, DCOM,    _______, _______, _______, _______,                      KC_PAST, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, KC_NO,
         _______, _______, _______, _______, _______, _______,                      KC_PSLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_TILD,
         _______, _______, _______, _______, _______, _______, _______,    KC_TRNS, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_KP_DOT,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

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




oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
            return OLED_ROTATION_180;
    }
    return  OLED_ROTATION_270;// that fucking did it
    
}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {// 'logo', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 
0x80, 0x80, 0x00, 0x00, 0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 
0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0xc0, 
0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 
0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83, 
0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc,
0x80, 0xb6, 0xb6, 0x80, 0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0xf0, 0xf0, 0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 
0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x3f, 
0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 
0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x06, 
0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 
0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 
0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00, 
0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 
0xff, 0x7f, 0x3f, 0x00, 0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 
0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 
0x04, 0x04, 0x04, 0x06, 0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 
0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06, 0x06, 0x06, 0x03, 
0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 
0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00};
    
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}

// When you add source files to SRC in rules.mk, you can use functions.

char layer_state_str[24];

static void print_status_narrow(void){

    oled_write_ln_P(PSTR("Lily"),false);
    oled_write_ln_P(PSTR(" 58 "),false);
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Your"), false);
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _vou:
            oled_write_ln_P(PSTR("vou"), false);
            break;
        case _VOU:
            oled_write_ln_P(PSTR("CAPS"), false);
            break;
        case _LEVEL3:
            oled_write_ln_P(PSTR("Nerd"), false);
            break;
        case _LEVEL4:
            oled_write_ln_P(PSTR("Light"), false);
            break;
        case _QWERTZ:
            oled_write_ln_P(PSTR("Normi"), false);
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

bool oled_task_user(void) {
    if (is_keyboard_master()) {
      print_status_narrow(); 
    } else {
        render_lily58_logo();
    }
    return false;
}

// Rotary encoder related code

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {            // Encoder on master side
        if (IS_LAYER_ON(_LEVEL3)){ 
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        }
        else {
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        }
    }
    else if (index == 1){        // Encoder on slave side
        if (IS_LAYER_ON(_LEVEL3)){    
            if (clockwise)
            {
                tap_code(KC_BSPC);
            }
            else
            {
                tap_code(KC_DEL);
            }
        } else {
            if(clockwise) {
                tap_code(KC_LEFT);
            } else{
                tap_code(KC_RIGHT);
            }
        }
    }
    return true;
}

