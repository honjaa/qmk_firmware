#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"


//#define _BASE 0
//#define _LM_NUM 1
//#define _RM_SYM 2
//#define _NAV 3
//#define _MOUSE 4

//layer declarations
enum layers {
  _BASE = 0,
  _LM_NUM,
  _RM_SYM,
  _NAV,
  _MOUSE,
};

//layer names and macros
enum custom_keycodes {
    MACRO_QUIT = SAFE_RANGE,
    MACRO_SAVE,
    MACRO_LINE,
    MACRO_TIME,
    MACRO_UNDO,
};

//tap dance declarations
enum tap_dance_codes {
  DANCE_0 ,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_PARENS_START,
  DANCE_PARENS_END,
  DANCE_BRK_START,
  DANCE_BRK_END, 
};




//combo declarations
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
//const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
//const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
//const uint16_t PROGMEM ap_combo[] = {KC_A,KC_P, COMBO_END};
//const uint16_t PROGMEM aoe_combo[] = {KC_A,NO_OSTR, COMBO_END};
const uint16_t PROGMEM flash_combo[] = {KC_Q,KC_P, COMBO_END};
const uint16_t PROGMEM reboot1_combo[] = {KC_C,NO_MINS, COMBO_END};
const uint16_t PROGMEM reboot2_combo[] = {KC_C,NO_PLUS, COMBO_END};
const uint16_t PROGMEM reboot3_combo[] = {NO_LCBR,NO_MINS, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_F,KC_G, COMBO_END};
//const uint16_t PROGMEM lalt1_combo[] = {KC_A,KC_Q, COMBO_END};
//const uint16_t PROGMEM win1_combo[] = {KC_S,KC_W, COMBO_END};
//const uint16_t PROGMEM lctl1_combo[] = {KC_D,KC_E, COMBO_END};
//const uint16_t PROGMEM lsft1_combo[] = {KC_F,KC_R, COMBO_END};
//const uint16_t PROGMEM lsft2_combo[] = {KC_J,KC_U, COMBO_END};
//const uint16_t PROGMEM lctl2_combo[] = {KC_K,KC_I, COMBO_END};
//const uint16_t PROGMEM win2_combo[] = {KC_L,KC_O, COMBO_END};
//const uint16_t PROGMEM lalt2_combo[] = {NO_OSTR,KC_P, COMBO_END};
const uint16_t PROGMEM zdash_combo[] = {KC_Z,NO_MINS, COMBO_END};
const uint16_t PROGMEM ty_combo[] = {KC_T,KC_Y, COMBO_END};


//combo definitions
combo_t key_combos[COMBO_COUNT] = {
    COMBO(df_combo, KC_DEL),
    //    COMBO(hj_combo, KC_ENT),
    //    COMBO(sd_combo, KC_DEL),
    //    COMBO(ap_combo, NO_ARNG),
    //    COMBO(aoe_combo, NO_AE),
    COMBO(flash_combo, QK_BOOT),
    COMBO(reboot1_combo,QK_REBOOT),
    COMBO(reboot2_combo,QK_REBOOT),
    COMBO(reboot3_combo,QK_REBOOT),
    //    COMBO(del_combo,KC_DEL),
    //    COMBO(lalt1_combo,KC_LALT),
    //    COMBO(win1_combo,KC_LGUI),
    //    COMBO(lctl1_combo,KC_LCTL),
    //    COMBO(lsft1_combo,KC_LSFT),
    //    COMBO(lsft2_combo,KC_LSFT),
    //    COMBO(lctl2_combo,KC_LCTL),
    //    COMBO(win2_combo,KC_LGUI),
    //    COMBO(lalt2_combo,KC_LALT),
    COMBO(zdash_combo,QK_CAPS_WORD_TOGGLE),
    COMBO(ty_combo,LCTL(LALT(KC_L))),
};

// define tapdance hold
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

// tapdance tap hold finish function
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
    #ifndef PERMISSIVE_HOLD
            && !state->interrupted
    #endif
        ){
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}
// tap dance tap hold function reset
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, LGUI(KC_0)),
    [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_1, LGUI(KC_1)),
    [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(KC_2, LGUI(KC_2)),
    [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(KC_3, LGUI(KC_3)),
    [DANCE_4] = ACTION_TAP_DANCE_TAP_HOLD(KC_4, LGUI(KC_4)),
    [DANCE_5] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, LGUI(KC_5)),
    [DANCE_6] = ACTION_TAP_DANCE_TAP_HOLD(KC_6, LGUI(KC_6)),
    [DANCE_7] = ACTION_TAP_DANCE_TAP_HOLD(KC_7, LGUI(KC_7)),
    [DANCE_8] = ACTION_TAP_DANCE_TAP_HOLD(KC_8, LGUI(KC_8)),
    [DANCE_9] = ACTION_TAP_DANCE_TAP_HOLD(KC_9, LGUI(KC_9)),
    [DANCE_PARENS_START] = ACTION_TAP_DANCE_DOUBLE(NO_LPRN, NO_LABK), // ( on hold < on double tap
    [DANCE_PARENS_END] = ACTION_TAP_DANCE_DOUBLE(NO_RPRN, NO_RABK), // ) on hold > on double tap
    [DANCE_BRK_START] = ACTION_TAP_DANCE_DOUBLE(NO_LBRC, NO_LCBR), // [ on hold { on double tap
    [DANCE_BRK_END] = ACTION_TAP_DANCE_DOUBLE(NO_RBRC, NO_RCBR), // ] on hold } on double tap
};


// Macro Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;
    switch (keycode) {

    // for basic strings
    case MACRO_QUIT: 
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(100) SS_LCTL(SS_TAP(X_S)) SS_DELAY(100) SS_LCTL(SS_TAP(X_X)) SS_DELAY(100) SS_LCTL(SS_TAP(X_C)));
        }
	else{
	}
	break;
    case MACRO_SAVE: 
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(100) SS_LCTL(SS_TAP(X_S)));
        }
	else {
	}
	break;
    case MACRO_LINE: 
        if (record->event.pressed) {
	  SEND_STRING(SS_LCTL(SS_TAP(X_C)) SS_DELAY(100) SS_LCTL(SS_TAP(X_L)));            
        }
	else{
	}
	break;
     case MACRO_TIME:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_TAP(X_C)) SS_DELAY(100) SS_LCTL(SS_TAP(X_T)));            
        }
	else{
	}
	break;
     case MACRO_UNDO:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(100) SS_TAP(X_U));
        }
        break;
     case TD(DANCE_0):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
     case TD(DANCE_1):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
     case TD(DANCE_2):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
     case TD(DANCE_3):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
     case TD(DANCE_4):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
     case TD(DANCE_5):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
     case TD(DANCE_6):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
     case TD(DANCE_7):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
      case TD(DANCE_8):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
      case TD(DANCE_9):  // list all tap dance keycodes with tap-hold configurations
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
	  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
	  tap_code16(tap_hold->tap);
	}
	break;
    }
  return true;
}


 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_BASE] = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T,                                                 KC_Y, KC_U, KC_I, KC_O, KC_P,
		  KC_A, KC_S, KC_D, KC_F, KC_G,                                                  KC_H, KC_J, KC_K, KC_L, NO_OSTR,
		  KC_Z, KC_X, KC_C, KC_V, KC_B,                                                  KC_N, KC_M, KC_COMM, KC_DOT, NO_MINS,
		  LT(_LM_NUM,KC_ESC), LT(_NAV,KC_BACKSPACE),                                     LT(_MOUSE,KC_ENT), LT(_RM_SYM,KC_SPC)),

 [_LM_NUM] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                           NO_QUOT , TD(DANCE_7), TD(DANCE_8), TD(DANCE_9), NO_EQL,
		    OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_TAB,          NO_SLSH , TD(DANCE_4), TD(DANCE_5), TD(DANCE_6), NO_ASTR,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F11,      TD(DANCE_0), TD(DANCE_1),TD(DANCE_2), TD(DANCE_3), NO_PLUS,
		                    KC_TRANSPARENT,  KC_TRANSPARENT,                             TD(DANCE_0),KC_TRANSPARENT),

 [_RM_SYM] = LAYOUT(NO_EXLM, NO_HASH, TD(DANCE_BRK_START), TD(DANCE_BRK_END), NO_PIPE,                                 KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		    NO_AT, NO_DLR,TD(DANCE_PARENS_START) , TD(DANCE_PARENS_END), NO_BSLS,                          OSM(MOD_RALT), OSM(MOD_LSFT), OSM(MOD_LCTL),  OSM(MOD_LGUI), OSM(MOD_LALT),
		    NO_PERC, NO_CIRC, NO_LCBR,NO_RCBR ,NO_TILD ,                                 KC_F12, KC_TRANSPARENT, NO_DIAE, NO_COLN, KC_TRANSPARENT,
		                           NO_RABK,NO_LABK,                                      KC_TRANSPARENT, KC_TRANSPARENT),

 [_NAV] = LAYOUT(MACRO_QUIT, LCTL(KC_W), KC_TRANSPARENT, LCTL(KC_R), LCTL(KC_T),                 KC_TRANSPARENT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
		 KC_ESC, MACRO_SAVE, MACRO_LINE, MACRO_TIME, TG(_MOUSE),                         KC_MS_BTN1, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
		 MACRO_UNDO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(_NAV),         KC_TRANSPARENT, LCTL(LSFT(KC_TAB)), LALT(KC_LEFT), LALT(KC_RIGHT),LCTL(KC_TAB),
		                                         KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT),

 [_MOUSE] = LAYOUT(KC_TRANSPARENT, LCTL(KC_W), KC_MS_UP, LCTL(KC_R), LCTL(KC_T),                         KC_MEDIA_NEXT_TRACK, KC_UP, KC_MS_WH_UP, KC_PGUP,NO_ARNG,
		   KC_ESC, KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT, TG(_NAV),                  KC_MEDIA_PLAY_PAUSE, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, NO_AE,
		   KC_MS_BTN2, KC_MS_WH_LEFT, KC_TRANSPARENT, KC_MS_WH_RIGHT, TG(_MOUSE),          KC_MEDIA_PREV_TRACK, KC_DOWN, KC_MS_WH_DOWN, KC_PGDN, KC_TRANSPARENT,
		                        KC_MS_BTN3, KC_MS_BTN1,                                  KC_TRANSPARENT,KC_TRANSPARENT)};
