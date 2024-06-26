// Copyright 2023 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later
//TheWerle-Remap		


#include QMK_KEYBOARD_H

#define POINTER_SPEED 700
#define POINTER_SNIPE_SPEED 200
#define SLAVE_SYNC_TIME_MS 60

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ S= Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST//,
	//_MOUSE
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
	SNIPE,
    EXIT_MOUSE,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

	const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*
	 * QWERTY
	 * ,-----------------------------------------.                    ,-----------------------------------------.
	 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | TAB |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | caps  |   A  |   S  |   D  |   F  |   G -------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
	 * |------+------+------+------+------+------|  GESC |    |       |------+------+------+------+------+------|
	 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
	 * --------------------+++-------------------/       /     \      \-----------------------------------------'
	 *            | LGUI | LAlt | LCTR |Space | / LOWER /       \RAISE \  |Enter | [ | ] | RGUI |		|
	 *            |      |      |      |      |/       /         \      \ |      |       |      |      	|
	 */

	[_QWERTY] = LAYOUT(
	  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
	  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
	  KC_CAPS,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
	  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, QK_GESC,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
			KC_LGUI,KC_LALT,KC_LCTL,  MO(_LOWER), KC_SPC,      		   KC_ENT, MO(_RAISE), KC_LBRC, KC_RBRC, KC_RGUI
	),
	/* LOWER  
	 * ,-----------------------------------------.                    ,-----------------------------------------.
	 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
	 * |------+------+------+------+------+------|RGB_TOG|    |       |------+------+------+------+------+------|
	 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
	 * `-----------------------------------------/       /     \      \-----------------------------------------'
	 *            | LGUI | LAlt | LCTR |Space | / LOWER /       \RAISE \  |Enter | RCTR | RAlt | RGUI |
	 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
	 */
	[_LOWER] = LAYOUT(
	  QK_GESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
	  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
	  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
	  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, RGB_TOG,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
						   _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
	),
	/* RAISE
	 * ,----------------------------------------.                    ,-----------------------------------------.
	 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | Esc  | Ins  | Pscr | Menu |      |DB_TOGG|                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
	 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
	 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
	 * `-----------------------------------------/       /     \      \-----------------------------------------'
	 *            | LGUI | LAlt | LCTR |Space | / LOWER /       \RAISE \  |Enter | RCTR | RAlt | RGUI |
	 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
	 */
	[_RAISE] = LAYOUT(
	  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
	  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, DB_TOGG,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC,
	  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
	  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
							 _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
	),
	/* ADJUST
	 * ,-----------------------------------------.                    ,-----------------------------------------.
	 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * |QK_BOOT|      |QWERTY|    |      |      |                    |      |      |      |      |      |      |
	 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
	 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
	 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
	 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
	 * `-----------------------------------------/       /     \      \-----------------------------------------'
	 *            | LGUI | LAlt | LCTR |Space | / LOWER /       \RAISE \  |Enter | RCTR | RAlt | RGUI |
	 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
	 */
	  [_ADJUST] = LAYOUT(
	  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	  QK_BOOT  , XXXXXXX, KC_QWERTY, XXXXXXX, CG_TOGG, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
	  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
					   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
	  )
	};
	#ifdef ENCODER_MAP_ENABLE
		const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
		   [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
		   [1] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
		   [2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)},
		   [3] = { ENCODER_CCW_CW(_______, _______) }//,
		   //[4] = { ENCODER_CCW_CW(_______, _______) }
		  };
	#endif
	
	void keyboard_post_init_user(void) {
	  // Customise these values to desired behaviour
	  debug_enable=true;
	  debug_matrix=true;
	  //debug_keyboard=true;
	  //debug_mouse=true;
	}

    // Default timeout for displaying logo on boot.
    #ifndef OLED_LOGO_TIMEOUT
        // 10 second timeout.
        #define OLED_LOGO_TIMEOUT 10000
    #endif

    #ifdef OLED_ENABLE

    uint16_t startup_timer; 

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        startup_timer = timer_read();

        if (is_keyboard_master()) {
            if(is_keyboard_left()){
            return OLED_ROTATION_90;
            }
            else {
                return OLED_ROTATION_90;
            }
            } else {
                return OLED_ROTATION_90;
            }
    }
    static void render_qmk_logo(void) {
        static const char PROGMEM qmk_logo[] = {
            // 'qmk_via_OLED_128x64', 64x128px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0xf0, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0xf8, 
            0xf8, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 
            0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 
            0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 
            0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x01, 
            0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xc3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x71, 0x71, 0x71, 0x71, 0x71, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
            0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0x71, 0x71, 0x71, 0x71, 0x71, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xf1, 0xf1, 0xe3, 0xe3, 0xe3, 0x00, 0x00, 
            0x00, 0xe3, 0xe3, 0xf3, 0xf1, 0xf1, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x7f, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 
            0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0x7f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 
            0x03, 0x03, 0x7f, 0xff, 0x7f, 0x03, 0x03, 0x03, 0x7f, 0xff, 0x7f, 0x03, 0x03, 0x03, 0x7f, 0xff, 
            0x7f, 0x03, 0x03, 0x03, 0x7f, 0xff, 0x7f, 0x03, 0x03, 0x03, 0x7f, 0xff, 0x7f, 0x03, 0x03, 0x03, 
            0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x38, 
            0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0x78, 0xf0, 0xc0, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0x38, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 
            0xf8, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0x38, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x03, 0x0f, 0x7e, 0xf8, 0xc0, 
            0x00, 0x80, 0xe0, 0xfc, 0x1f, 0x07, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
            0xff, 0x0c, 0x1e, 0x7f, 0xf3, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x0e, 0x0c, 0x1c, 0x1c, 0x1c, 0x0c, 0x0c, 0x0e, 
            0x0f, 0x1f, 0x38, 0x30, 0x70, 0x20, 0x00, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 
            0x0f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
            0x0f, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x0c, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x18, 0x7c, 0xfe, 0xfe, 0xfc, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xfc, 0xfe, 0xfe, 0xfe, 0x3c, 0x00, 0x00, 0x00, 0x00, 
            0xe0, 0xf8, 0xfc, 0xfc, 0xfc, 0xf8, 0x10, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 
            0xfe, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x80, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x80, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0x01, 0x00, 0x00, 0xe0, 0xf8, 0xff, 
            0xff, 0xff, 0xff, 0x1f, 0x03, 0x00, 0x00, 0xc0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x07, 0x03, 
            0x1f, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0xc0, 
            0xf0, 0xfe, 0xff, 0xff, 0xff, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0x7f, 
            0x1f, 0x03, 0x00, 0x00, 0xc0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xf8, 
            0xf8, 0xf8, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x3f, 0x7f, 0x7f, 0x7f, 
            0x7f, 0x7f, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x38, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x03, 0x00, 
            0x00, 0x00, 0x18, 0x7e, 0x7f, 0x7f, 0x7f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x3f, 0x7f, 0x7f, 0x7f, 0x3c, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1e, 0x3e, 
            0x1c, 0x08, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
            0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x3e, 0x3e, 
            0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
        // oled_write_P(qmk_logo, false);
    }
    static void render_logo(void) {
        // @todo - should we split this into a seperate file? kb16 has a good example.
        static const char PROGMEM sofle_pico_logo[] = { 
            // 'sofle-pico-vector-logo-v5 OLED chopped', 64x128px
            0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0x70, 0xf0, 0xf0, 0xe0, 0x20, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0xe0, 0xf0, 0xf8, 0xfc, 0x3c, 0x3c, 0x3c, 0x7c, 0xf8, 0xf8, 0xf0, 0x80, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x7c, 0x78, 0xf8, 0xf8, 0xf0, 0xe0, 0x00, 
            0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0x3c, 0x1c, 0x1e, 0x1e, 0x3c, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x1c, 
            0x1c, 0xff, 0xff, 0xff, 0xff, 0x1c, 0x1c, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xc0, 
            0xf0, 0xf8, 0xfc, 0xfc, 0xce, 0xce, 0xce, 0xdc, 0xfc, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x08, 0x1e, 0x1e, 0x1e, 0x3c, 0x3c, 0x3c, 0x3e, 0x1f, 0x1f, 0x0f, 0x07, 0x01, 
            0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1e, 0x3c, 0x3c, 0x3c, 0x1e, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 
            0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x01, 
            0x07, 0x0f, 0x1f, 0x1f, 0x3c, 0x38, 0x38, 0x3c, 0x1c, 0x1c, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x06, 0x06, 0x06, 0x0e, 0x9e, 0xfc, 0xf8, 0x00, 0x00, 0x8e, 
            0x8e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0xff, 
            0xff, 0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0x83, 0x01, 0x01, 0x01, 0x83, 0x83, 0x00, 0x00, 0x7e, 
            0xff, 0xc7, 0x83, 0x01, 0x01, 0x01, 0x83, 0xff, 0xff, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x80, 0xc0, 0xc3, 0xe3, 0xe0, 0xe0, 0xe0, 0xf0, 0x70, 0x70, 0x70, 0x70, 0x30, 0x33, 
            0x73, 0xe0, 0x60, 0xe0, 0xe0, 0xc0, 0xc1, 0x83, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 
            0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x70, 
            0x30, 0x70, 0x70, 0x70, 0x70, 0x70, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x03, 0x1f, 0xff, 0xf8, 0xd0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x20, 
            0x20, 0x40, 0xc0, 0x80, 0x00, 0x01, 0x87, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xff, 0xff, 0x03, 0x01, 0x00, 0x80, 0xc0, 0x40, 0x20, 
            0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf8, 0x7f, 0x0f, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1c, 0x1c, 0x38, 0x78, 0x60, 0x60, 0x60, 0x60, 
            0x60, 0x70, 0x38, 0x39, 0xdf, 0xef, 0xf7, 0x7b, 0x39, 0x1c, 0x1c, 0x0e, 0x0e, 0x06, 0x06, 0x06, 
            0x06, 0x06, 0x0e, 0x0e, 0x1e, 0x1c, 0x3c, 0x79, 0xfb, 0xf7, 0xef, 0x9f, 0x38, 0x30, 0x70, 0x60, 
            0x60, 0x60, 0x60, 0x70, 0x38, 0x3c, 0x1c, 0x0f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 
            0xf8, 0xfc, 0x7e, 0x7f, 0xff, 0xff, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0xff, 0x7f, 0x7f, 0x3f, 0x7c, 0xf8, 0xf0, 
            0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 
            0x81, 0x00, 0x00, 0x00, 0x00, 0x01, 0xcf, 0xff, 0xfe, 0x7c, 0x78, 0x78, 0x38, 0x30, 0x30, 0x30, 
            0x30, 0x30, 0x38, 0x78, 0x78, 0x7c, 0xfe, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 
            0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
            0x03, 0x07, 0x0f, 0x0e, 0x1e, 0x3f, 0x7f, 0xf1, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe1, 0xf3, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x07, 0x01, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 
            0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw_P(sofle_pico_logo, sizeof(sofle_pico_logo));
    }


    static void render_status(void) {
        oled_write_P(PSTR("Sofle Pico\nv3.04\n~~~~~~~~~\n"), false);
        uint8_t n = get_current_wpm();
        char    wpm_counter[4];
        wpm_counter[3] = '\0';
        wpm_counter[2] = '0' + n % 10;
        wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
        wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
        oled_write_P(PSTR("WPM:"), false);
        oled_write(wpm_counter, false);
        led_t led_state = host_keyboard_led_state();
        oled_write_P(PSTR("\nCAPS: "), false);
        oled_write_P(led_state.caps_lock ? PSTR("ON ") : PSTR("OFF"), false);
        oled_write_P(PSTR("\n"), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY "), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("NUM&SYM"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("NAVI	  "), false);
                break;
            default:
                oled_write_P(PSTR("UNK    "), false);
                break;
        }
    }
		
	
	
    // static void render_rgbstatus(void) {
		// oled_clear();
		// uint8_t rgb_mode = rgb_matrix_get_mode();
		
		// char rgb_disp[3];
		
        // rgb_disp[2] = rgb_mode % 10;
        // rgb_disp[1] = (rgb_mode/= 10) % 10 ? '0' + (rgb_mode) % 10 : (rgb_mode / 10) % 10 ? '0' : ' ';
        // rgb_disp[0] =  rgb_mode / 10 ? '0' + rgb_mode / 10 : ' ';
		// oled_write_P(PSTR("RGB:\n"), false);
        // oled_write(rgb_disp, false);
		
        // }
    // }
	
     bool oled_task_user(void) {
        static bool finished_logo = false;
        if ((timer_elapsed(startup_timer) < OLED_LOGO_TIMEOUT) && !finished_logo) {
            // Display the logo for 5 seconds on boot.
            if (is_keyboard_master()) {
                render_logo();
                // 10 Chars per line. Set cursor used to simplify line wraps.
                oled_set_cursor(0, 12);
                oled_write_P(PSTR("v3.51"), false);
                oled_set_cursor(0, 13);
                oled_write_P(PSTR("12-5-2023"), false);
                oled_set_cursor(0, 14);
                oled_write_P(PSTR("by:github/"), false);
                oled_set_cursor(0, 15);
                oled_write_P(PSTR("JellyTitan"), false);
            } else {
                render_qmk_logo();
            }
        } else {
            // Display the current keyboard state.
            if (!finished_logo) {
                finished_logo = true;
                // Clears the OLED.
                oled_clear();  
            } 
            if (is_keyboard_master()) {
                render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
            } else {
                render_logo();
            }
        }
        return false;
    }


    #endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    	  // If console is enabled, it will print the matrix position and status of each key pressed
	#ifdef CONSOLE_ENABLE
		uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
	#endif 

	switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

// #ifdef POINTING_DEVICE_ENABLE
// #    ifdef DILEMMA_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // if (abs(mouse_report.x) > DILEMMA_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > DILEMMA_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        // if (auto_pointer_layer_timer == 0) {
            // layer_on(LAYER_POINTER);
        // }
        // auto_pointer_layer_timer = timer_read();
    // }
    // return mouse_report;
// }

// void matrix_scan_user(void) {
    // if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= DILEMMA_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        // auto_pointer_layer_timer = 0;
        // layer_off(LAYER_POINTER);
    // }
// }
// #    endif // DILEMMA_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// #    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
// layer_state_t layer_state_set_user(layer_state_t state) {
    // dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    // return state;
// }
// #    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
// #endif     // POINTING_DEVICE_ENABLE
