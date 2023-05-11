#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

#define _BASE 0
#define _LM_NUM 1
#define _RM_SYM 2
#define _NAV 3
#define _MOUSE 4

//layer names and macros
enum custom_keycodes {
    BASE = SAFE_RANGE,
    LM_NUM,
    RM_SYM,
    NAV,
    MOUSE,
    MACRO_QUIT,
    MACRO_SAVE,
    MACRO_LINE,
    MACRO_TIME,
<<<<<<< HEAD
    MACRO_UNDO,
=======
>>>>>>> d05b8260ff (Works with simple tap dance, macros and combos)
    
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,  
};



<<<<<<< HEAD
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_BASE] = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T,                                             KC_Y, KC_U, KC_I, KC_O, KC_P,
		  KC_A, KC_S, KC_D, KC_F, KC_G,                                             KC_H, KC_J, KC_K, KC_L, NO_OSTR,
		  KC_Z, KC_X, KC_C, KC_V, KC_B,                                             KC_N, KC_M, KC_COMM, KC_DOT, NO_MINS,
		           OSL(1), KC_BACKSPACE,                                            KC_SPC, OSL(2)),

 [_LM_NUM] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                      NO_QUOT , TD(DANCE_7), TD(DANCE_8), TD(DANCE_9), NO_EQL,
		    OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_TAB,     NO_SLSH , TD(DANCE_4), TD(DANCE_5), TD(DANCE_6), NO_ASTR,
		    KC_F11, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ESC,         TD(DANCE_0), TD(DANCE_1),TD(DANCE_2), TD(DANCE_3), NO_PLUS,
		                                   KC_TRANSPARENT,  KC_TRANSPARENT,         KC_TRANSPARENT,TT(3)),

 [_RM_SYM] = LAYOUT(NO_EXLM, NO_HASH, NO_LBRC, NO_RBRC, NO_PIPE,                            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		    NO_AT, NO_DLR,TD(DANCE_10) , TD(DANCE_11), NO_BSLS,                     OSM(MOD_RALT), OSM(MOD_LSFT), OSM(MOD_LCTL),  OSM(MOD_LGUI), OSM(MOD_LALT),
		    NO_PERC, NO_CIRC, NO_LCBR,NO_RCBR ,NO_TILD ,                            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
		                                   TT(4), KC_TRANSPARENT,                   KC_TRANSPARENT, KC_TRANSPARENT),

 [_NAV] = LAYOUT(MACRO_QUIT, LCTL(KC_W), KC_TRANSPARENT, LCTL(KC_R), LCTL(KC_T),            KC_TRANSPARENT, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
		KC_ESC, MACRO_SAVE, MACRO_LINE, MACRO_TIME, KC_TRANSPARENT,         KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
		MACRO_UNDO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		                                   TO(0), KC_TRANSPARENT,                   KC_TRANSPARENT, KC_TRANSPARENT),

 [_MOUSE] = LAYOUT(KC_ESC, LCTL(KC_W), KC_MS_UP, LCTL(KC_R), LCTL(KC_T),                         KC_MEDIA_NEXT_TRACK, KC_UP, KC_MS_WH_UP, KC_PGUP,NO_ARNG,
		  KC_ESC, KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT, KC_TRANSPARENT,     KC_MEDIA_PLAY_PAUSE, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, NO_AE,
		  KC_TRANSPARENT, KC_MS_WH_LEFT, KC_TRANSPARENT, KC_MS_WH_RIGHT, KC_TRANSPARENT,    KC_MEDIA_PREV_TRACK, KC_DOWN, KC_MS_WH_DOWN, KC_PGDN, KC_TRANSPARENT,
		                                   KC_TRANSPARENT, KC_TRANSPARENT,          KC_TRANSPARENT, TO(0)) 
=======



 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_BASE] = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, NO_OSTR, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, NO_MINS, OSL(1), KC_BACKSPACE, KC_SPC, OSL(2)),

 [_LM_NUM] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, NO_QUOT , TD(DANCE_7), TD(DANCE_8), TD(DANCE_9), NO_EQL, OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_TAB, NO_SLSH , TD(DANCE_4), TD(DANCE_5), TD(DANCE_6), NO_ASTR, KC_F11, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ESC, TD(DANCE_0), TD(DANCE_1),TD(DANCE_2), TD(DANCE_3), NO_PLUS, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,TT(3)),

 [_RM_SYM] = LAYOUT(NO_EXLM, NO_HASH, NO_LBRC, NO_RBRC, NO_PIPE, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, NO_AT, NO_DLR,TD(DANCE_10) , TD(DANCE_11), NO_BSLS, OSM(MOD_RALT), OSM(MOD_LSFT), OSM(MOD_LCTL),  OSM(MOD_LGUI), OSM(MOD_LALT), NO_PERC, NO_CIRC, NO_LCBR,NO_RCBR ,KC_TILDE , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12, TT(4), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

 [_NAV] = LAYOUT(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MACRO_QUIT, MACRO_SAVE, MACRO_LINE, MACRO_TIME, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_PGDN, KC_PGUP, KC_END, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

[_MOUSE] = LAYOUT(KC_ESC, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, KC_TAB, KC_MEDIA_NEXT_TRACK, KC_UP, KC_MS_WH_UP, KC_NO,NO_ARNG, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, NO_AE, KC_ESC, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_DOWN, KC_MS_WH_DOWN, KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0)) 
>>>>>>> d05b8260ff (Works with simple tap dance, macros and combos)

};

//combo declarations
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
<<<<<<< HEAD
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM ap_combo[] = {KC_A,KC_P, COMBO_END};
const uint16_t PROGMEM aoe_combo[] = {KC_A,NO_OSTR, COMBO_END};
const uint16_t PROGMEM qp_combo[] = {KC_Q,KC_P, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(df_combo, KC_ESC),
    COMBO(jl_combo, KC_ENT),
    COMBO(sd_combo, KC_DEL),
    COMBO(ap_combo, NO_ARNG),
    COMBO(aoe_combo, NO_AE),
    COMBO(qp_combo, QK_BOOT),
=======
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM zdash_combo[] = {KC_Z, NO_MINS, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(df_combo, KC_ESC),
    COMBO(jk_combo, KC_ENT),
    COMBO(sd_combo, KC_DEL),
    COMBO(zdash_combo,TO(_BASE)),
>>>>>>> d05b8260ff (Works with simple tap dance, macros and combos)
};



//tap dance declarations
// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // simple tap dance
    [DANCE_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, LGUI(KC_0)), // replace with your keycodes. BASIC codes only, no custom codes.
    [DANCE_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, LGUI(KC_1)),
    [DANCE_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, LGUI(KC_2)),
    [DANCE_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, LGUI(KC_3)),
    [DANCE_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, LGUI(KC_4)),
    [DANCE_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, LGUI(KC_5)),
    [DANCE_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, LGUI(KC_6)),
    [DANCE_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, LGUI(KC_7)),
    [DANCE_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, LGUI(KC_8)),
    [DANCE_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, LGUI(KC_9)),
    [DANCE_10] = ACTION_TAP_DANCE_DOUBLE(NO_LPRN, NO_LABK),
    [DANCE_11] = ACTION_TAP_DANCE_DOUBLE(NO_RPRN, NO_RABK),
};


// Macro Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
<<<<<<< HEAD
     case MACRO_UNDO:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_TAP(X_X)) SS_DELAY(100) SS_TAP(X_U));
        }
        break;
=======
>>>>>>> d05b8260ff (Works with simple tap dance, macros and combos)

  }
  return true;
};
