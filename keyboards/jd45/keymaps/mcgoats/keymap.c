//MrMcGoat's custom layout

#include QMK_KEYBOARD_H

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
    _GAME2,
    _GAME3, //For speedrunning Bioshock
    _GRAISE,
    _LABEL,
    _LABEL_FN,
};


enum actions
{
    ACT_LCAPS = SAFE_RANGE,
    ACT_RCAPS,
    ACT_ESC,
};



// increase readability
#define KC________ KC_TRNS
//#define KC_XXXXXXX KC_NO
#define KC_SPC_CTRL MT(MOD_LCTL,KC_SPC)
#define KC_TAB_FN LT(_RAISE,KC_TAB)
#define KC_LSFTC ACT_LCAPS //Press both shifts to toggle caps lock
#define KC_RSFTC ACT_RCAPS
#define KC_ESCP ACT_ESC

//Moving to different layers
#define KC_LOWER MO(_LOWER)
#define KC_LOWER_PERM TO(_LOWER)
#define KC_RAISE TO(_RAISE)
#define KC_ADJUST TO(_ADJUST)
#define KC_DEFAULT TO(_DEFAULT)
#define KC_GAME1 TO(_GAME1)
#define KC_GAME2 TO(_GAME2)
#define KC_GAME3 TO(_GAME3)
#define KC_GRAISE MO(_GRAISE)

//Macro to toggle caps lock
#define TOGGLE_CAPS do { add_key(KC_CAPS); send_keyboard_report(); del_key(KC_CAPS); send_keyboard_report(); } while(0)

//I couldn't find a right mod version of Meh, so here's my own
#define KC_RMEH RCTL(RSFT(KC_RALT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default (Colmak)
     * ¸---------------------------------------------------------------------------¸
     * |ESC|  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  |  '  |  \  |
     * |---------------------------------------------------------------------------|
     * |TABFN |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  |  /  | Shift |
     * |---------------------------------------------------------------------------|
     * | LOWER| Meh | Super |  Alt  |SPC_CTRL|BckSpace|  Alt  | Super | Meh | Ctrl |
     * ´---------------------------------------------------------------------------´
     */
    [_DEFAULT] = LAYOUT(
            KC_ESCP, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_QUOT, KC_BSLS,
            KC_TAB_FN, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
            KC_LSFTC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFTC,
            KC_LOWER, KC_MEH, KC_LGUI, KC_LALT, KC_SPC_CTRL, KC_BSPC, KC_RALT, KC_RGUI, KC_RMEH, KC_RCTL
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
    [_RAISE] = LAYOUT(
            KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,
            KC________, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC________, KC________, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC________, KC________,
            KC________, KC_APP, KC________, KC________, KC________, KC________, KC_END, KC_PGDN, KC_PGUP, KC_HOME, KC_PSCR, KC_PAUS,
            KC________, KC________, KC________, KC________, KC________, KC_DEL, KC________, KC________, KC________, KC_ADJUST
            ),

    /* Lower
     * ¸---------------------------------------------------------------------------¸
     * |   | F1  | F2  | F3  | F4  |     | Num7| Num8| Num9|  [  |  ]  |  -  |NumLk|
     * |---------------------------------------------------------------------------|
     * |      | F5  | F6  | F7  | F8  |     | Num4| Num5| Num6|     |     |        |
     * |---------------------------------------------------------------------------|
     * |       | F9  | F10 | F11 | F12 |     | Num1| Num2| Num3|     |     |       |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        |  Num0  |       |       |     |ADJUST|
     * ´---------------------------------------------------------------------------´
     */
    [_LOWER] = LAYOUT(
            KC________, KC_F1, KC_F2, KC_F3, KC_F4, KC________, KC_P7, KC_P8, KC_P9, KC_LBRC, KC_RBRC, KC_MINS, KC_NUM,
            KC________, KC_F5, KC_F6, KC_F7, KC_F8, KC________, KC_P4, KC_P5, KC_P6, KC________, KC________, KC________,
            KC________, KC_F9, KC_F10, KC_F11, KC_F12, KC________, KC_P1, KC_P2, KC_P3, KC________, KC________, KC________,
            KC________, KC________, KC________, KC________, KC________, KC_P0, KC________, KC________, KC________, KC_ADJUST
            ),
    /* Adjust
     * ¸---------------------------------------------------------------------------¸
     * |   |Defau|Game1|Game2|Game3|Lower|     |     |     |     |     |     |     |
     * |---------------------------------------------------------------------------|
     * |      |Label|     |     |     |     |     |     |     |     |     |        |
     * |---------------------------------------------------------------------------|
     * |       |     |     |     |     |     |     |     |     |     |     |       |
     * |---------------------------------------------------------------------------|
     * |      |     |       |       |        |        |       |       |     |      |
     * ´---------------------------------------------------------------------------´
     */
    [_ADJUST] = LAYOUT(
            XXXXXXX, KC_DEFAULT, KC_GAME1, KC_GAME2, KC_GAME3, KC_LOWER_PERM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
            ),
    /* Gaming (Colmak)
     * ¸---------------------------------------------------------------------------¸
     * |ESC|  Q  |  W  |  F  |  P  |  G  |  J  |  L  |  U  |  Y  |  ;  |  '  | End |
     * |---------------------------------------------------------------------------|
     * | TAB  |  A  |  R  |  S  |  T  |  D  |  H  |  N  |  E  |  I  |  O  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  K  |  M  |  ,  |  .  | Up  | Shift |
     * |---------------------------------------------------------------------------|
     * | Ctrl |  \  |GRaise |  Alt  | Space  |BckSpace|   /   |   ←   |  Dn |  →   |
     * ´---------------------------------------------------------------------------´
     */
    [_GAME1] = LAYOUT(
            KC_ESCP, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_QUOT, KC_END,
            KC_TAB, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_UP, KC_RSFT,
            KC_LCTL, KC_BSLS, KC_GRAISE, KC_LALT, KC_SPC, KC_BSPC, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
            ),
    /* Gaming (QWERTY)
     * ¸---------------------------------------------------------------------------¸
     * |ESC|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  '  | End |
     * |---------------------------------------------------------------------------|
     * | TAB  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  | Up  | Shift |
     * |---------------------------------------------------------------------------|
     * | Ctrl |  \  |GRaise |  Alt  | Space  |BckSpace|   /   |   ←   |  Dn |  →   |
     * ´---------------------------------------------------------------------------´
     */
    [_GAME2] = LAYOUT(
            KC_ESCP, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT, KC_END,
            KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_RSFT,
            KC_LCTL, KC_BSLS, KC_GRAISE, KC_LALT, KC_SPC, KC_BSPC, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
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
    [_GRAISE] = LAYOUT(
            KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
            KC________, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC________, KC________,
            KC________, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_APP, KC________, KC_PSCR, KC_PAUS,
            KC________, KC________, KC________, KC________, KC________, KC_DEL, KC________, KC________, KC________, KC_ADJUST
            ),
    /* Speedrunning
     * ¸---------------------------------------------------------------------------¸
     * |ESC|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  '  | End |
     * |---------------------------------------------------------------------------|
     * | TAB  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  Enter |
     * |---------------------------------------------------------------------------|
     * | Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift |
     * |---------------------------------------------------------------------------|
     * | Ctrl |  \  |GRaise |  Alt  | Space  |  Prev  |  Alt  | Super |Raise|Lower |
     * ´---------------------------------------------------------------------------´
     */
    [_GAME3] = LAYOUT(
            KC_ESCP, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT, KC_END,
            KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
            KC_LCTL, KC_BSLS, KC_GRAISE, KC_LALT, KC_SPC, KC_MEDIA_PREV_TRACK, KC_RALT, KC_LGUI, KC_RAISE, KC_LOWER
            )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool lshift=false;
    static bool rshift=false;

    static bool shift_esc=false;

    switch(keycode)
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
            return false;
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
            return false;
        case ACT_ESC:
            if(record->event.pressed) //If key is being pressed
            {
                if((lshift || rshift) && !(lshift && rshift))
                {
                    add_key(KC_GRV);
                    send_keyboard_report();
                    shift_esc=true;
                } else
                {
                    add_key(KC_ESC);
                    send_keyboard_report();
                }
            } else
            {
                if(((lshift || rshift) && !(lshift && rshift)) || shift_esc)
                {
                    del_key(KC_GRV);
                    send_keyboard_report();
                    shift_esc=false;
                } else
                {
                    del_key(KC_ESC);
                    send_keyboard_report();
                }
            }

            return false;
        default:
            return true;
    }
}

// vim: expandtab shiftwidth=4 softtabstop=4
