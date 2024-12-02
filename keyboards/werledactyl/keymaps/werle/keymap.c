#include QMK_KEYBOARD_H


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define SH_ESC SFT_T(KC_ESC)
#define ____ KC_TRNS


enum layers {
    /* _M_XYZ = Mac Os, _W_XYZ S= Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

/* Tap Dance declarations */
enum tapdances {
    _TD_C_COPY,
	_TD_X_CUT,
	_TD_V_PASTE,
	_TD_Q_ESC,
	_TD_P_BKSP
};

/* Tapdance */
#define TDCCPY TD(_TD_C_COPY)
#define TDXCUT TD(_TD_X_CUT)
#define TDVPST TD(_TD_V_PASTE)
#define TDQESQ 	TD(_TD_Q_ESC)
#define TDPBSPC TD(_TD_P_BKSP)


/**
 * Tap Dance definitions
 *
 * To use this in the configurator, enter the name 'TD5ENT' in the "Any" key.
 */
tap_dance_action_t tap_dance_actions[] = {
    [_TD_X_CUT] = ACTION_TAP_DANCE_DOUBLE(KC_X, LCTL_T(KC_X)),
	[_TD_C_COPY] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL_T(KC_C)),
	[_TD_V_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL_T(KC_V)),
	[_TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
	[_TD_P_BKSP] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC)
};
 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( 
		KC_Q,        KC_W,    KC_E,    KC_R,    KC_T,   	KC_Y,   KC_U,    KC_I,    KC_O,   KC_P , 
		LSFT_T(KC_A),KC_S,    KC_D,    KC_F,    KC_G,   	KC_H,   KC_J,    KC_K,    KC_L,   RSFT_T(KC_SCLN), 
		KC_Z,        TDXCUT,  TDCCPY,  TDVPST,  KC_B,   	KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, 
					 KC_LBRC, KC_RBRC, KC_LCTL, KC_SPC, 	KC_ENT,  KC_BSPC, KC_QUOT, KC_BSLS,
								 RAISE, KC_LSFT,			KC_RSFT, LOWER,
                                 KC_TAB,QK_GESC,       	    KC_MENU, KC_DEL				
									
//		KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, KC_ENT, KC_RCTL, KC_LBRC, KC_RBRC, 
//		KC_CAPS, KC_TAB,  KC_LSFT, LOWER,  RAISE,  KC_BSPC, KC_MENU, KC_DEL	 
	),
    [_LOWER] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, 	KC_F6,   KC_F7,  KC_F8,  KC_F9,  KC_F10, 
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  	KC_6,    KC_7, 	KC_8, 	KC_9, 	KC_0,
    KC_EXLM,   KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST,
    KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_LBRC, KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS,
      _______, _______, _______,KC_KP_0, KC_DOT,  KC_PPLS

	),
	[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______,_______, _______,DB_TOGG, _______,_______,
    KC_INS, KC_PSCR, KC_APP , _______, _______, KC_PGUP, _______,   KC_UP, _______, _______,
    KC_LALT, KC_LCTL, KC_LSFT, _______, KC_CAPS, KC_PGDN,  KC_LEFT,KC_DOWN, KC_RGHT,  KC_DEL,
    KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,_______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______
    ),

	[_ADJUST] = LAYOUT(
        QK_CLEAR_EEPROM,  XXXXXXX, _______, _______, _______, _______, XXXXXXX, _______, _______, _______,  
        QK_BOOT,  XXXXXXX, _______, _______, _______, _______, XXXXXXX, _______, _______, _______,  
        DB_TOGG ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,
        QK_REBOOT,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
	     _______, _______, _______, _______, _______, _______
	)
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, row: %2u, col: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.row, record->event.key.col, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}