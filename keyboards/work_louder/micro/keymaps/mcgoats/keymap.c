// Copyright 2022 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

# define KEY_HOLD_TIMEOUT 100

enum custom_keycodes {
	LED_LEVEL = SAFE_RANGE,
	KC_FN,
	BACK_DEL, // Press for KC_BSPC, hold for KC_DEL
	MUL_DIV, // Press for KC_PAST, hold for KC_PSLS
	PLUS_MINUS, // Press for KC_PPLS, hold for KC_PMNS
	VIM_TOP_BOT, // Press for gg, hold for G
	COPY, // Press for y, hold for "+y, use with KC_FN for Ctrl+C
	PASTE, // Press for p, hold for "+p, use with KC_FN for Ctrl+V
	CUT, // Press for x, hold for "+x, use with KC_FN for Ctrl+X
	VIM_MACRO, // Press for qq, hold for @q
	VIM_MODES, // Press for esc,v hold for esc,t (insert mode), use with KC_FN for esc
	UNDO, // Press for u, hold for Ctrl+Z
	REDO, // Press for Ctrl+R, hold for Ctrl+Y
	SCROLL_TAB_LEFT, // Esc,N
	SCROLL_TAB_RIGHT, // Esc,E
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	LAYOUT( // Numpad Layout
			KC_PENT, KC_P0,    MUL_DIV,    KC_NUM,
			PLUS_MINUS,    KC_P7,    KC_P8,  KC_P9,
			KC_P3,    KC_P4,    KC_P5,    KC_P6,
			TO(1),   KC_P1,  KC_P2, KC_PDOT
		  ),
	LAYOUT( // Vim Layout
			VIM_TOP_BOT,    BACK_DEL,    VIM_MACRO,    KC_NO,
			KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,
			CUT,    COPY,    PASTE,   VIM_MODES,
			TO(2),   UNDO,    REDO,    KC_FN
		  ),
	LAYOUT(
			KC_1,    KC_2,    KC_3,    KC_4,
			KC_5,    KC_6,    KC_7,    KC_8,
			KC_9,    KC_0,    KC_A,    KC_B,
			TO(3),   KC_C,    KC_D,    KC_E
		  ),
	LAYOUT(
			KC_1,    KC_2,    KC_3,    KC_4,
			KC_5,    KC_6,    KC_7,    KC_8,
			KC_9,    KC_0,    KC_A,    KC_B,
			TO(0),   KC_C,    LED_LEVEL,KC_E
		  ),

};

typedef union {
	uint32_t raw;
	struct {
		uint8_t led_level : 3;
	};
} work_louder_config_t;

work_louder_config_t work_louder_config;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static bool fn_mode = false;

	// Variables for tracking key holds
	static uint16_t key_hold_timer = 0;
	static uint16_t key_hold_keycode = 0;

	switch (keycode) {
		case LED_LEVEL:
			if (record->event.pressed) {
				work_louder_config.led_level++;
				if (work_louder_config.led_level > 4) {
					work_louder_config.led_level = 0;
				}
				work_louder_micro_led_all_set((uint8_t)(work_louder_config.led_level * 255 / 4));
				eeconfig_update_user(work_louder_config.raw);
				layer_state_set_kb(layer_state);
			}
			break;
		case KC_FN:
			fn_mode = !fn_mode;
			return false;
		case BACK_DEL:
			if (record->event.pressed) {
				key_hold_timer = timer_read();
				key_hold_keycode = keycode;
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING(SS_TAP(X_BSPC));
				} else if(key_hold_keycode == keycode) {
					SEND_STRING(SS_TAP(X_DEL));
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case MUL_DIV:
			if (record->event.pressed) {
				key_hold_timer = timer_read();
				key_hold_keycode = keycode;
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING(SS_TAP(X_PAST));
				} else if(key_hold_keycode == keycode) {
					SEND_STRING(SS_TAP(X_PSLS));
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case PLUS_MINUS:
			if (record->event.pressed) {
				key_hold_timer = timer_read();
				key_hold_keycode = keycode;
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING(SS_TAP(X_PPLS));
				} else if(key_hold_keycode == keycode) {
					SEND_STRING(SS_TAP(X_PMNS));
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case VIM_TOP_BOT:
			if (record->event.pressed) {
				key_hold_timer = timer_read();
				key_hold_keycode = keycode;
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING("gg");
				} else if(key_hold_keycode == keycode) {
					SEND_STRING("G");
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case COPY:
			if (record->event.pressed) {
				if (fn_mode) {
					SEND_STRING(SS_LCTL("c"));
				} else {
					key_hold_timer = timer_read();
					key_hold_keycode = keycode;
				}
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING("y");
				} else if(key_hold_keycode == keycode) {
					SEND_STRING("\"+y");
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case PASTE:
			if (record->event.pressed) {
				if (fn_mode) {
					SEND_STRING(SS_LCTL("v"));
				} else {
					key_hold_timer = timer_read();
					key_hold_keycode = keycode;
				}
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING("p");
				} else if(key_hold_keycode == keycode) {
					SEND_STRING("\"+p");
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case CUT:
			if (record->event.pressed) {
				if (fn_mode) {
					SEND_STRING(SS_LCTL("x"));
				} else {
					key_hold_timer = timer_read();
					key_hold_keycode = keycode;
				}
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING("x");
				} else if(key_hold_keycode == keycode) {
					SEND_STRING("\"+x");
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case VIM_MACRO:
			if (record->event.pressed) {
				key_hold_timer = timer_read();
				key_hold_keycode = keycode;
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING("qq");
				} else if(key_hold_keycode == keycode) {
					SEND_STRING("@q");
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case VIM_MODES:
			if (record->event.pressed) {
				key_hold_timer = timer_read();
				key_hold_keycode = keycode;
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING(SS_DOWN(X_ESC) SS_DELAY(1) SS_UP(X_ESC) "v");
				} else if(key_hold_keycode == keycode) {
					SEND_STRING(SS_DOWN(X_ESC) SS_DELAY(1) SS_UP(X_ESC) "t");
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case UNDO:
			if (record->event.pressed) {
				key_hold_timer = timer_read();
				key_hold_keycode = keycode;
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING("u");
				} else if(key_hold_keycode == keycode) {
					SEND_STRING(SS_LCTL("z"));
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case REDO:
			if (record->event.pressed) {
				key_hold_timer = timer_read();
				key_hold_keycode = keycode;
			} else {
				if (timer_elapsed(key_hold_timer) < KEY_HOLD_TIMEOUT || key_hold_keycode != keycode) {
					SEND_STRING(SS_LCTL("r"));
				} else if(key_hold_keycode == keycode) {
					SEND_STRING(SS_LCTL("y"));
				}

				if (key_hold_keycode == keycode) {
					key_hold_timer = 0;
					key_hold_keycode = 0;
				}
			}
			return false;
		case SCROLL_TAB_LEFT:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_ESC) SS_DELAY(1) SS_UP(X_ESC) "N");
			}
			return false;
		case SCROLL_TAB_RIGHT:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_ESC) SS_DELAY(1) SS_UP(X_ESC) "E");
			}
			return false;
	}
	return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	{ ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_DEL, KC_BSPC)  },
	{ ENCODER_CCW_CW(KC_DOWN, KC_UP),             ENCODER_CCW_CW(SCROLL_TAB_RIGHT, SCROLL_TAB_LEFT)  },
	{ ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(_______, _______)  },
	{ ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(_______, _______)  },
};
#endif


layer_state_t layer_state_set_user(layer_state_t state) {
	layer_state_cmp(state, 1) ? work_louder_micro_led_1_on(): work_louder_micro_led_1_off();
	layer_state_cmp(state, 2) ? work_louder_micro_led_2_on(): work_louder_micro_led_2_off();
	layer_state_cmp(state, 3) ? work_louder_micro_led_3_on(): work_louder_micro_led_3_off();

	return state;
}

void eeconfig_init_user(void) {
	work_louder_config.raw = 0;
	work_louder_config.led_level = 1;
	eeconfig_update_user(work_louder_config.raw);
}

void matrix_init_user(void) {
	work_louder_config.raw = eeconfig_read_user();
	work_louder_micro_led_all_set((uint8_t)(work_louder_config.led_level * 255 / 4));
}
