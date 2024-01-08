// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

//Tap Dance Declarations
enum {
  CT_GIRL = 0
};


/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GIRL:
        if (record->event.pressed) {
            // when keycode GIRL is pressed
            SEND_STRING("Jeg er en liten jente!");
	    SEND_STRING(SS_TAP(X_ENT));
        } else {
            // when keycode GIRL is released
        }
        break;
    }
    return true;
};
*/

void dance_girl_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_ENT);
    //    register_code (KC_B);
  } else {
    //register_code (KC_B);
    SEND_STRING("Jeg er en liten jente!");                                                                           
    SEND_STRING(SS_TAP(X_ENT)); 
  }
}

void dance_girl_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_ENT);
    //    unregister_code (KC_B);
  } else {
    //unregister_code (KC_B);
    //    SEND_STRING("Jeg er en liten jente!");                                                                           
    //SEND_STRING(SS_TAP(X_ENT));
  }
}


//All tap dance functions would go here. Only showing this one.
tap_dance_action_t tap_dance_actions[] = {
 [CT_GIRL] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_girl_finished, dance_girl_reset)
};

/*
//tap dance declarationsl
enum tap_dance_codes {
DANCE_0
};


// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [DANCE_0] = ACTION_TAP_DANCE_DOUBLE(GIRL,KC_ENT)
};

*/



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_ortho_1x1(
			   //LCTL(LALT(KC_L)) //CRTL+ALT+L lock 
			   // KC_MS_LEFT // mouse left button
			   //KC_ENT
			   //GIRL
			   TD(CT_GIRL)
			   
			   
    )
};
