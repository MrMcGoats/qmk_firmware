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
    _GAME2
};




enum custom_keycodes
{
    COLEMAK = SAFE_RANGE,
    RAISE,
    LOWER,
    ADJUST
};





// increase readability 
#define KC________ KC_TRNS
#define KC_XXXXXXX KC_NO
#define KC_SPC_CTRL MT(KC_LCTL,KC_SPC)
#define KC_TAB_FN LT(_RAISE,KC_TAB)
#define KC_ESCP F(0) //Mimic Pok3r escape key (Shitf+Esc is ~, Fn+Esc is `)
#define KC_LSFTC F(1) //Press both shifts to toggle caps lock
#define KC_RSFTC F(2)
#define GRAVE_MODS (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))
#define CAPS_MODS (MOD_BIT(KC_LSFT)&MOD_BIT(KC_RSFT))

#define ACT_ESC 0
#define ACT_LCAPS 1
#define ACT_RCAPS 2

//Moving to different layers
#define KC_LOWER MO(_LOWER)
#define KC_LOWER_PERM TO(_LOWER)
#define KC_ADJUST TO(_ADJUST)
#define KC_DEFAULT TO(_DEFAULT)
#define KC_GAME1 TO(_GAME1)
#define KC_GAME2 TO(_GAME2)
#define KC_GRAISE MO(_GRAISE)

//Macro to toggle caps lock
#define TOGGLE_CAPS do { add_key(KC_CAPS); send_keyboard_report(); del_key(KC_CAPS); send_keyboard_report(); } while(0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default (Colmak)
     * ¸---------------------------------------------------------------------------¸
     * |ESP|  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  |  '  |  \  |
     * |---------------------------------------------------------------------------|
     * |TABFN |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  |  /  | Shift |
     * |---------------------------------------------------------------------------|
     * | LOWER| Meh | Super |  Alt  |SPC_CTRL|BckSpace|       | Super |     |      |
     * ´---------------------------------------------------------------------------´
     */
    [_DEFAULT] = KEYMAP(
            ESCP, Q, W, F, P, G, J, L, U, Y, SCLN, QUOT, BSLS,
            TAB_FN, A, R, S, T, D, H, N, E, I, O, ENT,
            LSFT, Z, X, C, V, B, K, M, COMM, DOT, SLSH, RSFT,
            LOWER, MEH, LGUI, LALT, SPC_CTRL, BSPC, XXXXXXX, RGUI, XXXXXXX, XXXXXXX
            ),

    /* Raise
     * ¸---------------------------------------------------------------------------¸
     * | ` |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |  -  |  =  |
     * |---------------------------------------------------------------------------|
     * |      |Prev |Play |Next |     |     |  ←  |  Dn |  Up |  →  |     |        |
     * |---------------------------------------------------------------------------|
     * |       |Menu |     |     |     |     | End | PgDn| PgUp|Home |PntSc| Pause |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        | Delete |       |       |     |ADJUST|
     * ´---------------------------------------------------------------------------´
     */
    [_RAISE] = KEYMAP(
            GRV, EXLM, AT, HASH, DLR, PERC, CIRC, AMPR, ASTR, LPRN, RPRN, MINS, EQL,
            _______, MEDIA_PREV_TRACK, MEDIA_PLAY_PAUSE, MEDIA_NEXT_TRACK, _______, _______, LEFT, DOWN, UP, RGHT, _______, _______,
            _______, APP, _______, _______, _______, _______, END, PGDN, PGUP, HOME, PSCR, PAUS,
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
     * |   |Defau|Game1|Game2|Lower|     |     |     |     |     |     |     |     |
     * |---------------------------------------------------------------------------|
     * |      |     |     |     |     |     |     |     |     |     |     |        |
     * |---------------------------------------------------------------------------|
     * |       |     |     |     |     |     |     |     |     |     |     |       |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        |        |       |       |     |      |
     * ´---------------------------------------------------------------------------´
     */
    [_ADJUST] = KEYMAP(
            XXXXXXX, DEFAULT, GAME1, GAME2, LOWER_PERM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
            ),
    /* Gaming (Colmak)
     * ¸---------------------------------------------------------------------------¸
     * |ESP|  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  |  '  | End |
     * |---------------------------------------------------------------------------|
     * | TAB  |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  | Up  | Shift |
     * |---------------------------------------------------------------------------|
     * | Ctrl |  \  |GRaise |  Alt  | Space  |BckSpace|   /   |   ←   |  Dn |  →   |
     * ´---------------------------------------------------------------------------´
     */
    [_GAME1] = KEYMAP(
            ESCP, Q, W, F, P, G, J, L, U, Y, SCLN, QUOT, END,
            TAB, A, R, S, T, D, H, N, E, I, O, ENT,
            LSFT, Z, X, C, V, B, K, M, COMM, DOT, UP, RSFT,
            LCTRL, BSLS, GRAISE, LALT, SPC, BSPC, SLSH, LEFT, DOWN, RGHT
            ),
    /* Gaming (QWERTY)
     * ¸---------------------------------------------------------------------------¸
     * |ESP|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  '  | End |
     * |---------------------------------------------------------------------------|
     * | TAB  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  | Up  | Shift |
     * |---------------------------------------------------------------------------|
     * | Ctrl |  \  |GRaise |  Alt  | Space  |BckSpace|   /   |   ←   |  Dn |  →   |
     * ´---------------------------------------------------------------------------´
     */
    [_GAME2] = KEYMAP(
            ESCP, Q, W, E, R, T, Y, U, I, O, P, QUOT, END,
            TAB, A, S, D, F, G, H, J, K, L, SCLN, ENT,
            LSFT, Z, X, C, V, B, N, M, COMM, DOT, UP, RSFT,
            LCTRL, BSLS, GRAISE, LALT, SPC, BSPC, SLSH, LEFT, DOWN, RGHT
            ),
    /* GRaise
     * ¸---------------------------------------------------------------------------¸
     * | ` |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |
     * |---------------------------------------------------------------------------|
     * |      |  F1 |  F2 | F3  | F4  |  F5 |  ←  |  Dn |  Up |  →  |     |        |
     * |---------------------------------------------------------------------------|
     * |       | F6  | F7  |  F8 |  F9 | F10 | F11 | F12 | Menu|     |PntSc| Pause |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        | Delete |       |       |     |ADJUST|
     * ´---------------------------------------------------------------------------´
     */
    [_GRAISE] = KEYMAP(
            GRV, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL,
            _______, F1, F2, F3, F4, F5, LEFT, DOWN, UP, RGHT, _______, _______,
            _______, F6, F7, F8, F9, F10, F11, F12, APP, _______, PSCR, PAUS,
            _______, _______, _______, _______, _______, DEL, _______, _______, _______, ADJUST
            )
};


enum function_id {
    LAUNCH,
    RGBLED_TOGGLE,
};

const uint16_t PROGMEM fn_actions[] = {
    [ACT_ESC]   = ACTION_FUNCTION(ACT_ESC),
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
    static uint8_t mods_pressed;

    switch(id)
    {
        case ACT_ESC:
            mods_pressed=get_mods()&GRAVE_MODS; //Check to see what mods are pressed
            if(record->event.pressed) //If the key is being pressed
            {
                if(!mods_pressed)
                {
                    add_key(KC_GRV);
                    send_keyboard_report();
                } else
                {
                    add_key(KC_ESC);
                    send_keyboard_report();
                }
            } else //If the key is being released
            {
                if(mods_pressed)
                {
                    del_key(KC_GRV);
                    send_keyboard_report();
                } else
                {
                    del_key(KC_ESC);
                    send_keyboard_report();
                }
            }
            break;

        case ACT_LCAPS:
            mods_pressed=get_mods()&CAPS_MODS; //Check to see what mods are pressed
            if(record->event.pressed) //If the key is being pressed
            {
                if(!mods_pressed)
                {
                    add_key(KC_LSFT);
                    send_keyboard_report();
                } else
                {
                    //toggle caps lock
                    add_key(KC_CAPS);
                    send_keyboard_report();
                    del_key(KC_CAPS);
                    send_keyboard_report();
                }
            } else //if key is being released
            {
                if(mods_pressed)
                {
                    del_key(KC_LSFT);
                    send_keyboard_report();
                }
            }
        case ACT_RCAPS:
            mods_pressed=get_mods()&CAPS_MODS; //Check to see what mods are pressed
            if(record->event.pressed) //If the key is being pressed
            {
                if(!mods_pressed)
                {
                    add_key(KC_RSFT);
                    send_keyboard_report();
                } else
                {
                    TOGGLE_CAPS;
                }
            } else //if key is being released
            {
                if(mods_pressed)
                {
                    del_key(KC_RSFT);
                    send_keyboard_report();
                }
            }
    }
}

// vim: expandtab shiftwidth=4 softtabstop=4
