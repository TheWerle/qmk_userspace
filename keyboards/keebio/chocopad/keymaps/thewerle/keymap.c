// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   2


enum kp_layers {
    /* _M_XYZ = Mac Os, _W_XYZ S= Win/Linux */
    _NUM,
	_DPAD,
	_ALTIUM
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
}
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_NUM] = LAYOUT_ortho_4x4(
    KC_P7,   KC_P8,   KC_P9,   KC_BSPC,
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_P1,   KC_P2,   KC_P3,   KC_PMNS,
    KC_P0,   TO(1),   KC_PDOT, KC_PENT
  ),
  [_DPAD] = LAYOUT_ortho_4x4(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,
    KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
    XXXXXXX, TO(2),   XXXXXXX, XXXXXXX
  ),
  [_ALTIUM] = LAYOUT_ortho_4x4(
	RGB_MOD, RGB_TOG, RGB_HUI, RGB_HUD, 
	XXXXXXX, XXXXXXX, RGB_SAI, RGB_SAD, 
	XXXXXXX, XXXXXXX, RGB_VAI, RGB_VAD, 
	XXXXXXX, TO(0),   RGB_SPI, RGB_SPD
  )
};

/* 
LED_FLAG_MODIFIER	0x01	If the LED is on a modifier key
LED_FLAG_UNDERGLOW	0x02	If the LED is for underglow
LED_FLAG_KEYLIGHT	0x04	If the LED is for key backlight
LED_FLAG_INDICATOR	0x08	If the LED is for keyboard state indication
 */
 

 bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	 

		switch(get_highest_layer(layer_state|default_layer_state)) {
			case _ALTIUM:

				for (uint8_t i = led_min; i < led_max; i++) {

					if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { //underglow
						rgb_matrix_set_color(i, RGB_BLUE);
					}
				}					
                break;
				
            case _DPAD:
                //rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
				for (uint8_t i = led_min; i < led_max; i++) {
					if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { //underglow
						rgb_matrix_set_color(i, RGB_GREEN);
					}
				}	
					rgb_matrix_set_color(8, RGB_PINK);
					rgb_matrix_set_color(10, RGB_PINK);
					rgb_matrix_set_color(11, RGB_PINK);		
					rgb_matrix_set_color(12, RGB_PINK);										
				
                break;

			case _NUM:
				
                //rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
				for (uint8_t i = led_min; i < led_max; i++) {
					if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { //underglow
						rgb_matrix_set_color(i, RGB_RED);
					}
				}	
                break;
					
            default:
				//rgb_matrix_set_color(i, RGB_RED);
                break;
        }
    return false;
}