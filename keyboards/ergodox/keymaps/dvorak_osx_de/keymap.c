#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

#define EMAIL_1 1
#define EMAIL_2 2
#define EMAIL_3 3
#define UMLAUT_UE 4
#define UMLAUT_UPPER_UE 5
#define UMLAUT_AE 6
#define UMLAUT_UPPER_AE 7
#define UMLAUT_OE 8
#define UMLAUT_UPPER_OE 9
#define UMLAUT_SZ 10

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD,
    RGB_0000FF,
    RGB_008000,
    RGB_FFA500,
    RGB_800080,
    RGB_FF0000
};

// NOTE: Cells marked with ACCESS must remain transparent, they're the keys that actually get to that layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  =   |           |  -   |   6  |   7  |   8  |   9  |   0  |  ESC   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | DEL    |   '  |   ,  |   .  |   P  |   Y  |  Ü   |           |  ß   |   F  |   G  |   C  |   R  |   L  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | TAB    | A/LT1| O/ALT| E/CTL| U/CMD| I/SFT|------|           |------| I/SFT| H/CMD| T/CTL| N/ALT| S/LT1|  TAB   |
 * |--------+------+------+------+------+------|  Ä   |           |  Ö   |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TG 2 |  `   |   /  |  MEH | MO 2 |                                       | MO 2 |  MEH |   [  |   ]  | TG 2 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,---------------.
 *                                        |LT4/APP| CMD  |       | CMD  | INS/LT4|
 *                                 ,------|-------|------|       |------+--------+------.
 *                                 | LT 3 |       | HOME |       | PgDn |        |      |
 *                                 |  /   | BSPC  |------|       |------|  Enter |Space |
 *                                 | TAB  |       | END  |       | RCtrl|        |      |
 *                                 `---------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[0] = KEYMAP(  // layer 0 : default
        // left hand
                KC_ESCAPE,     KC_1,         KC_2,        KC_3,         KC_4,        KC_5,       KC_EQUAL,
                KC_DELETE,     KC_QUOTE,     KC_COMMA,    KC_E,         KC_R,        KC_T,       M(UMLAUT_UE),
                              ALL_T(KC_TAB), LT(1,KC_A),   ALT_T(KC_O), CTL_T(KC_E),  GUI_T(KC_U), SFT_T(KC_I),
                KC_LSHIFT,     KC_SCOLON,    KC_Q,        KC_J,         KC_K,        KC_X,       M(UMLAUT_AE),
                TG(2),         KC_GRAVE,     KC_SLASH,    MEH_T(KC_NO), MO(2),
                                                                              LT(4,KC_APPLICATION),KC_LGUI,
                                                                                        KC_HOME,
                                                                              LT(3,KC_TAB),KC_BSPACE,KC_END,
        // right hand
                KC_MINUS,     KC_6,        KC_7,         KC_8,         KC_9,         KC_0,               KC_ESCAPE,
                M(UMLAUT_SZ), KC_F,        KC_G,         KC_C,         KC_R,         KC_L,               KC_BSLASH,
                              SFT_T(KC_D), RGUI_T(KC_H), RCTL_T(KC_T), ALGR_T(KC_N), LT(1,KC_S),         ALL_T(KC_TAB),
                M(UMLAUT_OE), KC_B,        KC_M,         KC_W,         KC_V,         KC_Z,               KC_RSHIFT,
                                           MO(2),        MEH_T(KC_NO), KC_LBRACKET,  KC_RBRACKET,        TG(2),
                KC_RGUI, LT(4,KC_INSERT),
                KC_PGUP,
                KC_PGDOWN, KC_ENTER, KC_SPACE
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  | F5   |  `   |           |ACCESS|  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  |   |   <  |   >  |   '  |  =   |   ü  |           |   ß  |   +  |   "  |   [  |  ]   |  @   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |ACCESS|   [  |   ]  |   _  |  ,   |------|           |------|   .  |  ;   |   (  |   )  |ACCESS|        |
 * |--------+------+------+------+------+------|   ä  |           |  ö   |------+------+------+------+------+--------|
 * |        |  #/~ |   $  |   ?  |   *  |  \   |      |           |      |  /   |   -  |   !  |  ~   |  ^   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | F12  |GoToIm|  FAR |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[1] = KEYMAP(  // layer 1 : Symbol Layer
        // left hand
        KC_TRNS, KC_F1,         KC_F2,       KC_F3,       KC_F4,    KC_F5,     KC_GRAVE,
        KC_TRNS, KC_PIPE,       KC_LABK,     KC_RABK,     KC_QUOTE, KC_EQUAL,  M(UMLAUT_UPPER_UE),
        KC_TRNS, KC_TRNS,       KC_LBRACKET, KC_RBRACKET, KC_UNDS,  KC_COMMA,
        KC_TRNS, KC_NONUS_HASH, KC_DLR,      KC_QUES,     KC_ASTR,  KC_BSLASH, M(UMLAUT_UPPER_AE),
        KC_TRNS, KC_TRNS,       KC_TRNS,     KC_TRNS,     KC_TRNS,
                                                                             KC_TRNS, KC_TRNS,
                                                                                      KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand

            KC_PERC,            KC_F6,       KC_F7,       KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
            M(UMLAUT_SZ),       KC_KP_PLUS,  KC_DQUO,     KC_LCBR, KC_RCBR, KC_AT,   KC_TRNS,
                                KC_KP_DOT,   KC_SCOLON,   KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS,
            M(UMLAUT_UPPER_OE), KC_KP_SLASH, KC_KP_MINUS, KC_EXLM, KC_TILD, KC_CIRC, KC_TRNS,
                                             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Mouse Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F11 |  F12 |  F13 |  F14 |  F15 |      |           |      |  F16 |  F17 |  F18 |  F19 |  F20 |   F21  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | WH_UP| B_LFT| M_UP | B_RGT|      |   F22  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  MEH |  ALT |  CTL |  CMD |  SFT |------|           |------|WH_DWN| M_LFT|M_DOWN| M_RGT|      |   F23  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | ACC0 | ACC1 | ACC2 |      |      |           |      |      |  B_4 | B_MID|  B_5 |      |   F24  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |ACCESS|                                       |ACCESS|      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Mouse Layer
//
[2] = KEYMAP(
        // left hand
                KC_TRNS, KC_F11,        KC_F12,       KC_F13,       KC_F14,       KC_F15,       KC_TRNS,
                KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                KC_TRNS, MEH_T(KC_NO),  ALT_T(KC_NO), CTL_T(KC_NO), GUI_T(KC_NO), SFT_T(KC_NO),
                KC_TRNS, KC_TRNS,       KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS,      KC_TRNS,
                KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                                             KC_TRNS, KC_TRNS,
                                                                                      KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
                KC_TRNS, KC_F16,        KC_F17,      KC_F18,     KC_F19,      KC_F20,  KC_F21,
                KC_TRNS, KC_MS_WH_UP,   KC_MS_BTN1,  KC_MS_UP,   KC_MS_BTN2,  KC_TRNS, KC_F22,
                         KC_MS_WH_DOWN, KC_MS_LEFT,  KC_MS_DOWN,   KC_MS_RIGHT, KC_TRNS, KC_F23,
                KC_TRNS, KC_TRNS,       KC_MS_BTN4,  KC_MS_BTN3, KC_MS_BTN5,  KC_TRNS, KC_F24,
                                        KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS,
                KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Light and Cursor Movement
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  Light |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgUp |  Up  | Home |      | Bright+|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  MEH |  ALT |  CTL |  CMD |  SFT |------|           |------| Ctl-A| Left | Down | Right| Ctl-E| Bright-|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgDn | Down | End  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |ACCESS|      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Cursor and Light
//
[3] = KEYMAP(
        // left hand
             KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
             KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
             KC_TRNS, MEH_T(KC_NO),  ALT_T(KC_NO), CTL_T(KC_NO), GUI_T(KC_NO), SFT_T(KC_NO),
             KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
             KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                                             KC_TRNS, KC_TRNS,
                                                                                      KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_TRNS, KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    RGB_TOG,
             KC_TRNS, KC_TRNS,       KC_PGUP,     KC_UP,      KC_HOME,     KC_TRNS,    RGB_VAD,
                      LCTL(KC_A),    KC_LEFT,     KC_DOWN,    KC_RIGHT,    LCTL(KC_E), KC_TRNS,
             KC_TRNS, KC_TRNS,       KC_PGDOWN,   KC_DOWN,    KC_END,      KC_TRNS,    KC_TRNS,
                                     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Media and Shortcuts
 *
 * ,-------------------------------------------------------.            ,--------------------------------------------------.
 * | Rewind | Play  |  FFwd | Prev  | Stop  | Next  | Mute |           | Eject| Mail | Calc | FileM|Search|      | Favs   |
 * |--------+-------+-------+-------+-------+-------+------|           |------+------+------+------+------+------+--------|
 * |        |       |Hyper+1|Hyper+2|Hyper+3|Hyper++| Vol+ |           |      |      |      |Refrsh|      |      | EMail1 |
 * |--------+-------+-------+-------+-------+-------|      |           |      |------+------+------+------+------+--------|
 * |        |       |Hyper+4|Hyper+5|Hyper+6|Hyper+-|------|           |------|      | Back | Home | Fwrd |      | Email2 |
 * |--------+-------+-------+-------+-------+-------| Vol- |           |      |------+------+------+------+------+--------|
 * |        |       |Hyper+7|Hyper+8|Hyper+9|Hyper+=|      |           |      |      |      |      |      |      | Email3 |
 * `--------+-------+-------+-------+-------+--------------'           `-------------+------+------+------+------+--------'
 *   |      |       |       |       |       |                                        |      |      |      |      |      |
 *   `-------------------------------------'                                         `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |ACCESS|       |ACCESS|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
//
[4] = KEYMAP(
        // left hand
  KC_MEDIA_REWIND, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD,           KC_MEDIA_PREV_TRACK,             KC_MEDIA_STOP,                   KC_MEDIA_NEXT_TRACK,                KC_AUDIO_MUTE,
  KC_TRNS,         KC_TRNS,             LALT(LCTL(LGUI(LSFT(KC_KP_1)))), LALT(LCTL(LGUI(LSFT(KC_KP_2)))), LALT(LCTL(LGUI(LSFT(KC_KP_3)))), LALT(LCTL(LGUI(LSFT(KC_KP_PLUS)))), KC_AUDIO_VOL_UP,
  KC_TRNS,         KC_TRNS,             LALT(LCTL(LGUI(LSFT(KC_KP_4)))), LALT(LCTL(LGUI(LSFT(KC_KP_5)))), LALT(LCTL(LGUI(LSFT(KC_KP_6)))), LALT(LCTL(LGUI(LSFT(KC_KP_MINUS)))),
  KC_TRNS,         KC_TRNS,             LALT(LCTL(LGUI(LSFT(KC_KP_7)))), LALT(LCTL(LGUI(LSFT(KC_KP_8)))), LALT(LCTL(LGUI(LSFT(KC_KP_9)))), LALT(LCTL(LGUI(LSFT(KC_EQUAL)))), KC_AUDIO_VOL_DOWN,
  KC_TRNS,         KC_TRNS,             KC_TRNS,                         KC_TRNS,                         KC_TRNS,
                                                                             KC_TRNS, KC_TRNS,
                                                                                      KC_TRNS,
                                                                    KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_MEDIA_EJECT, KC_MAIL, KC_CALCULATOR, KC_MY_COMPUTER, KC_WWW_SEARCH,  KC_TRNS, KC_WWW_FAVORITES,
                      KC_TRNS,        KC_TRNS, KC_TRNS,       KC_WWW_REFRESH, KC_TRNS,        KC_TRNS, M(EMAIL_1),
                                      KC_TRNS, KC_WWW_BACK,   KC_WWW_HOME,    KC_WWW_FORWARD, KC_TRNS, M(EMAIL_2),
                      KC_TRNS,        KC_TRNS, KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS, M(EMAIL_3),
                                      KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
    case 0:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
    case EMAIL_1:
        //Macro: EMAIL_1: andreas@sahlbach.com
        if (record->event.pressed) {
            return MACRO(T(A),T(N),T(D),T(R),T(E),T(A),T(S),D(LSFT),T(2),U(LSFT),T(S),T(A),T(H),T(L),T(B),T(A),T(C),T(H),T(DOT),T(C),T(O),T(M),END);
        }
        break;
    case EMAIL_2:
        //Macro: EMAIL_2: andreas.sahlbach@gmail.com
        if (record->event.pressed) {
            return MACRO(T(A),T(N),T(D),T(R),T(E),T(A),T(S),T(DOT),T(S),T(A),T(H),T(L),T(B),T(A),T(C),T(H),D(LSFT),T(2),U(LSFT),T(G),T(M),T(A),T(I),T(L),T(DOT),T(C),T(O),T(M),END);
        }
        break;
    case EMAIL_3:
        //Macro: EMAIL_3: andreas@vw-dilab.com
        if (record->event.pressed) {
            return MACRO(T(A),T(N),T(D),T(R),T(E),T(A),T(S),D(LSFT),T(2),U(LSFT),T(V),T(W),T(MINUS),T(D),T(I),T(L),T(A),T(B),T(DOT),T(C),T(O),T(M),END);
        }
        break;
    case UMLAUT_UE:
        //Macro: UMLAUT_UE: ALTGR_U+U
        if (record->event.pressed) {
            return MACRO(D(RALT),T(U),U(RALT),T(U),END);
        }
        break;
    case UMLAUT_UPPER_UE:
        //Macro: UMLAUT_UPPER_UE: ALTGR_U+SHIFT_U
        if (record->event.pressed) {
            return MACRO(D(RALT),T(U),U(RALT),D(LSFT),T(U),U(LSFT),END);
        }
        break;
    case UMLAUT_OE:
        //Macro: UMLAUT_OE: ALTGR_U+O
        if (record->event.pressed) {
            return MACRO(D(RALT),T(U),U(RALT),T(O),END);
        }
        break;
    case UMLAUT_UPPER_OE:
        //Macro: UMLAUT_UPPER_OE: ALTGR_U+SHIFT_O
        if (record->event.pressed) {
            return MACRO(D(RALT),T(U),U(RALT),D(LSFT),T(O),U(LSFT),END);
        }
        break;
    case UMLAUT_AE:
        //Macro: UMLAUT_UE: ALTGR_U+A
        if (record->event.pressed) {
            return MACRO(D(RALT),T(U),U(RALT),T(A),END);
        }
        break;
    case UMLAUT_UPPER_AE:
        //Macro: UMLAUT_UPPER_UE: ALTGR_U+SHIFT_A
        if (record->event.pressed) {
            return MACRO(D(RALT),T(U),U(RALT),D(LSFT),T(A),U(LSFT),END);
        }
        break;
    case UMLAUT_SZ:
        //Macro: UMLAUT_SZ
        if (record->event.pressed) {
            return MACRO(D(RALT),T(S),U(RALT),END);
        }
        break;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        // dynamically generate these.
    case EPRM:
        if (record->event.pressed) {
            eeconfig_init();
        }
        return false;
        break;
    case VRSN:
        if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        return false;
        break;
    case RGB_SLD:
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
        break;
    
    case RGB_0000FF:
        if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
            rgblight_enable();
            rgblight_mode(1);
            rgblight_setrgb(0x00,0x00,0xff);
#endif
        }
        return false;
        break;
    
    case RGB_008000:
        if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
            rgblight_enable();
            rgblight_mode(1);
            rgblight_setrgb(0x00,0x80,0x00);
#endif
        }
        return false;
        break;
    
    case RGB_FFA500:
        if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
            rgblight_enable();
            rgblight_mode(1);
            rgblight_setrgb(0xff,0xa5,0x00);
#endif
        }
        return false;
        break;
    
    case RGB_800080:
        if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
            rgblight_enable();
            rgblight_mode(1);
            rgblight_setrgb(0x80,0x00,0x80);
#endif
        }
        return false;
        break;
    
    case RGB_FF0000:
        if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
            rgblight_enable();
            rgblight_mode(1);
            rgblight_setrgb(0xff,0x00,0x00);
#endif
        }
        return false;
        break;
    
    }
    return true;
}

static uint8_t prev_layer = 0;

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

#ifdef RGBLIGHT_ENABLE
    if (layer != prev_layer) {
        if(layer != 0) {
            rgblight_enable();
        }
        rgblight_mode(1);
        switch (layer) {
        case 0:
            rgblight_setrgb(0x00,0x00,0x00);//dark
            break;
        case 1:
            rgblight_setrgb(0xff,0x00,0x00);//red
            break;
        case 2:
            rgblight_setrgb(0x00,0x80,0x00);//dark green
            break;
        case 3:
            rgblight_setrgb(0x00,0x00,0xff);//blue
            break;
        case 4:
            rgblight_setrgb(0xff,0xa5,0x00);//orange
            break;
        case 5:
            rgblight_setrgb(0x80,0x00,0x80);//purple
            break;
        case 6:
            rgblight_setrgb(0x00,0xFF,0x00);//green
            break;
        case 7:
            rgblight_setrgb(0xFF,0xFF,0x00);//yellow
            break;
        default:
            break;
        }
        prev_layer = layer;
    }
#endif

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
    case 1:
        ergodox_right_led_1_on();
        break;
    case 2:
        ergodox_right_led_2_on();
        break;
    case 3:
        ergodox_right_led_3_on();
        break;
    case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
    case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
    case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
    case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
    default:
        break;
    }

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    prev_layer = 0;
    rgblight_enable();
    rgblight_mode(1);
    rgblight_setrgb(0x00,0x00,0x00);//dark
};
