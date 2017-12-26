//MrMcGoat's custom layout

#include "jd45.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layers
{
    _DEFAULT,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME1,
    _GRAISE,
    _GAME2,
    _LABEL,
    _LABEL_FN
};




enum custom_keycodes
{
    COLEMAK = SAFE_RANGE,
    RAISE,
    LOWER,
    ADJUST
};

enum actions
{
    ACT_LCAPS,
    ACT_RCAPS
};



// increase readability 
#define KC________ KC_TRNS
#define KC_XXXXXXX KC_NO
#define KC_SPC_CTRL MT(MOD_LCTL,KC_SPC)
#define KC_TAB_FN LT(_RAISE,KC_TAB)
#define KC_LSFTC F(ACT_LCAPS) //Press both shifts to toggle caps lock
#define KC_RSFTC F(ACT_RCAPS)

//Moving to different layers
#define KC_LOWER MO(_LOWER)
#define KC_LOWER_PERM TO(_LOWER)
#define KC_ADJUST TO(_ADJUST)
#define KC_DEFAULT TO(_DEFAULT)
#define KC_GAME1 TO(_GAME1)
#define KC_GAME2 TO(_GAME2)
#define KC_GRAISE MO(_GRAISE)
#define KC_LABEL_DEFAULT TO(_LABEL)
#define KC_LABEL_FN MO(_LABEL_FN)

//Macro to toggle caps lock
#define TOGGLE_CAPS do { add_key(KC_CAPS); send_keyboard_report(); del_key(KC_CAPS); send_keyboard_report(); } while(0)

//Some keycodes don't have the KC_ suffix, so I have to add it so they work with the JD45 KEYMAP macro
#define KC_RESET RESET


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default (Colmak)
     * ¸---------------------------------------------------------------------------¸
     * |   |  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  |  '  |  \  |
     * |---------------------------------------------------------------------------|
     * |TABFN |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  |  /  | Shift |
     * |---------------------------------------------------------------------------|
     * | LOWER| Meh | Super |  Alt  |SPC_CTRL|BckSpace|       | Super |     |      |
     * ´---------------------------------------------------------------------------´
     */
    [_DEFAULT] = KEYMAP(
            XXXXXXX, Q, W, F, P, G, J, L, U, Y, SCLN, QUOT, BSLS,
            TAB_FN, A, R, S, T, D, H, N, E, I, O, ENT,
            LSFTC, Z, X, C, V, B, K, M, COMM, DOT, SLSH, RSFTC,
            LOWER, MEH, LGUI, LALT, SPC_CTRL, BSPC, XXXXXXX, RGUI, XXXXXXX, XXXXXXX
            ),

    /* Raise
     * ¸---------------------------------------------------------------------------¸
     * |   |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |  -  |  =  |
     * |---------------------------------------------------------------------------|
     * |      |Prev |Play |Next |     |     |  ←  |  Dn |  Up |  →  |     |        |
     * |---------------------------------------------------------------------------|
     * |       |Menu |     |     |     |     | End | PgDn| PgUp|Home |PntSc| Pause |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        | Delete |       |       |     |ADJUST|
     * ´---------------------------------------------------------------------------´
     */
    [_RAISE] = KEYMAP(
            _______, EXLM, AT, HASH, DLR, PERC, CIRC, AMPR, ASTR, LPRN, RPRN, MINS, EQL,
            _______, MEDIA_PREV_TRACK, MEDIA_PLAY_PAUSE, MEDIA_NEXT_TRACK, _______, _______, LEFT, DOWN, UP, RGHT, _______, _______,
            ESC, APP, GRV, _______, _______, _______, END, PGDN, PGUP, HOME, PSCR, PAUS,
            _______, _______, _______, _______, _______, DEL, _______, _______, _______, ADJUST
            ),

    /* Lower
     * ¸---------------------------------------------------------------------------¸
     * |   | F1  | F2  | F3  | F4  | Num7| Num8| Num9| Num0|  [  |  ]  |     |NumLk|
     * |---------------------------------------------------------------------------|
     * |      | F5  | F6  | F7  | F8  | Num4| Num5| Num6|     |     |     |        |
     * |---------------------------------------------------------------------------|
     * |       | F9  | F10 | F11 | F12 | Num1| Num2| Num3|     |     |     |       |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        |  Num0  |       |       |     |ADJUST|
     * ´---------------------------------------------------------------------------´
     */
    [_LOWER] = KEYMAP(
            _______, F1, F2, F3, F4, P7, P8, P9, P0, LBRC, RBRC, _______, NLCK,
            _______, F5, F6, F7, F8, P4, P5, P6, _______, _______, _______, _______,
            _______, F9, F10, F11, F12, P1, P2, P3, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, P0, _______, _______, _______, ADJUST
            ),
    /* Adjust
     * ¸---------------------------------------------------------------------------¸
     * |   |Defau|Game1|Game2|Lower|     |     |     |     |     |     |     |RESET|
     * |---------------------------------------------------------------------------|
     * |      |Label|     |     |     |     |     |     |     |     |     |        |
     * |---------------------------------------------------------------------------|
     * |       |     |     |     |     |     |     |     |     |     |     |       |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        |        |       |       |     |      |
     * ´---------------------------------------------------------------------------´
     */
    [_ADJUST] = KEYMAP(
            XXXXXXX, DEFAULT, GAME1, GAME2, LOWER_PERM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
            XXXXXXX, LABEL_DEFAULT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
            ),
    /* Gaming (Colmak)
     * ¸---------------------------------------------------------------------------¸
     * |   |  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  |  '  | End |
     * |---------------------------------------------------------------------------|
     * | TAB  |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  | Up  | Shift |
     * |---------------------------------------------------------------------------|
     * | Ctrl |  \  |GRaise |  Alt  | Space  |BckSpace|   /   |   ←   |  Dn |  →   |
     * ´---------------------------------------------------------------------------´
     */
    [_GAME1] = KEYMAP(
            XXXXXXX, Q, W, F, P, G, J, L, U, Y, SCLN, QUOT, END,
            TAB, A, R, S, T, D, H, N, E, I, O, ENT,
            LSFT, Z, X, C, V, B, K, M, COMM, DOT, UP, RSFT,
            LCTRL, BSLS, GRAISE, LALT, SPC, BSPC, SLSH, LEFT, DOWN, RGHT
            ),
    /* Gaming (QWERTY)
     * ¸---------------------------------------------------------------------------¸
     * |   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  '  | End |
     * |---------------------------------------------------------------------------|
     * | TAB  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  | Up  | Shift |
     * |---------------------------------------------------------------------------|
     * | Ctrl |  \  |GRaise |  Alt  | Space  |BckSpace|   /   |   ←   |  Dn |  →   |
     * ´---------------------------------------------------------------------------´
     */
    [_GAME2] = KEYMAP(
            XXXXXXX, Q, W, E, R, T, Y, U, I, O, P, QUOT, END,
            TAB, A, S, D, F, G, H, J, K, L, SCLN, ENT,
            LSFT, Z, X, C, V, B, N, M, COMM, DOT, UP, RSFT,
            LCTRL, BSLS, GRAISE, LALT, SPC, BSPC, SLSH, LEFT, DOWN, RGHT
            ),
    /* GRaise
     * ¸---------------------------------------------------------------------------¸
     * |   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |
     * |---------------------------------------------------------------------------|
     * |      |  F1 |  F2 | F3  | F4  |  F5 |  ←  |  Dn |  Up |  →  |     |        |
     * |---------------------------------------------------------------------------|
     * |       | F6  | F7  |  F8 |  F9 | F10 | F11 | F12 | Menu|     |PntSc| Pause |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        | Delete |       |       |     |ADJUST|
     * ´---------------------------------------------------------------------------´
     */
    [_GRAISE] = KEYMAP(
            _______, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL,
            ESC, F1, F2, F3, F4, F5, LEFT, DOWN, UP, RGHT, _______, _______,
            _______, F6, F7, F8, F9, F10, F11, F12, APP, _______, PSCR, PAUS,
            _______, GRV, _______, _______, _______, DEL, _______, _______, _______, ADJUST
            ),
    /* Label — Layout to match how the stock keycaps are labeled
     * ¸---------------------------------------------------------------------------¸
     * |ESC|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  | Bs  |
     * |---------------------------------------------------------------------------|
     * | TAB  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  '  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift |
     * |---------------------------------------------------------------------------|
     * | Ctrl | Fn  |  Win  |  Alt  | Back   |  Space |  Alt  | Menu  |  Fn | Ctrl |
     * ´---------------------------------------------------------------------------´
     */
    [_LABEL] = KEYMAP(
            ESC, Q, W, E, R, T, Y, U, I, O, P, RBRC, BSPC,
            TAB, A, S, D, F, G, H, J, K, L, QUOT, ENT,
            LSFT, Z, X, C, V, B, N, M, COMM, DOT, SLSH, RSFT,
            LCTRL, LABEL_FN, LGUI, LALT, BSPC, SPC, RALT, APP, LABEL_FN, RCTRL
            ),
    /* Label-Fn — Layout to match how the stock keycaps are labeled (Function layer), with the adition of the ADJUST key.
     * ¸---------------------------------------------------------------------------¸
     * | ` |     | Up  |     |  7  |  8  |  9  |  0  |  -  |  =  |     |  ]  |  \  |
     * |---------------------------------------------------------------------------|
     * | Caps |  ←  |  Dn |  →  |  4  |  5  |  6  | Ins | Home| PgUp|  ;  |        |
     * |---------------------------------------------------------------------------|
     * |       |     |     |     |  1  |  2  |  3  | Del | End | PgDn|     |       |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        |        |       |       |     |ADJUST|
     * ´---------------------------------------------------------------------------´
     */
    [_LABEL_FN] = KEYMAP(
            GRV, _______, UP, _______, 7, 8, 9, 0, MINS, EQL, _______, LBRC, BSLS,
            CAPS, LEFT, DOWN, RGHT, 4, 5, 6, INS, HOME, PGUP, SCLN, _______,
            _______, _______, _______, _______, 1, 2, 3, DEL, END, PGDN, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, ADJUST
            )
    
};


enum function_id {
    LAUNCH,
    RGBLED_TOGGLE,
};

const uint16_t PROGMEM fn_actions[] = {
    [ACT_LCAPS] = ACTION_FUNCTION(ACT_LCAPS),
    [ACT_RCAPS] = ACTION_FUNCTION(ACT_RCAPS)
};




const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function

    return MACRO_NONE;
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    static bool lshift=false;
    static bool rshift=false;

    switch(id)
    {
        case ACT_LCAPS:
            if(record->event.pressed) //If the key is being pressed
            {
                if(!rshift)
                {
                    add_key(KC_LSFT);
                    send_keyboard_report();
                    lshift=true;
                } else
                   TOGGLE_CAPS; 
            } else //if key is being released
            {
                if(!rshift)
                {
                    del_key(KC_LSFT);
                    send_keyboard_report();
                    lshift=false;
                }
            }
            break;
        case ACT_RCAPS:
            if(record->event.pressed) //If the key is being pressed
            {
                if(!lshift)
                {
                    add_key(KC_RSFT);
                    send_keyboard_report();
                    rshift=true;
                } else
                    TOGGLE_CAPS;
            } else //if key is being released
            {
                if(!lshift)
                {
                    del_key(KC_RSFT);
                    send_keyboard_report();
                    rshift=false;
                }
            }
            break;
    }
}

// vim: expandtab shiftwidth=4 softtabstop=4
