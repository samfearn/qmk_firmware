/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCT,
  _OBSSTUDIO
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  EXT_PLV
};

//Tap Dance Declarations
enum {
  TD_1P_KEY = 0,
  TD_CMDALT,
  TD_ALTSFT,
  TD_OBSESC,
  TD_DANCECMD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SPLOWER LT(_LOWER,KC_SPC)
#define SPRAISE LT(_RAISE,KC_SPC)
#define FUNCT TT(_FUNCT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | GrEsc|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |HypTab|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   '  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SCSft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |SCSft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FUNCT| Ctrl | Alt  | CMD  |Lower |    Space    | Raise|CMD/At| Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    TD(TD_OBSESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    HYPR_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_RSPC ,
    FUNCT, TD(TD_ALTSFT), KC_LALT, KC_LCMD, LOWER, KC_SPC, KC_SPC, RAISE,   TD(TD_DANCECMD), KC_LEFT, KC_DOWN,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |   #  |      |      |      |   -  |   _  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SCLSB|      |      |      |      |      |      |  1P  |  ;   |   \  | Vol+ | SCRSB|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Play | Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, _______,
    _______,  _______,   _______,   LALT(KC_3),   _______,   _______,   _______, KC_MINS,   KC_UNDS,    KC_LCBR, KC_RCBR, _______,
    LSFT_T(KC_LBRC), _______,   _______,   _______,   _______,  _______,  _______, TD(TD_1P_KEY) , KC_SCLN, KC_BSLS, KC_VOLU,  RSFT_T(KC_RBRC),
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MRWD, KC_VOLD, KC_MFFD
),

/* Raise
	
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   +  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SCLCB|      |      |      |      |      |      |  ?   |   :  |  /   | Vol+ | SCRCB|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Play | Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______,  _______,   _______,   _______,   _______,   _______,   _______,   KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    LSFT_T(KC_LBRC), _______,   _______,   _______,   _______,  _______,  _______,  KC_QUES, KC_COLN, KC_SLSH, KC_VOLU, RSFT_T(KC_RBRC),
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MRWD, KC_VOLD, KC_MFFD
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  <   |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |   >  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET, _______,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, _______ ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______,  _______,  _______,  _______,
    KC_LABK, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, KC_RABK,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
	
/* FUNCT (ToggleTap layer)
* ,-----------------------------------------------------------------------------------.
* |      |  F1  |  F2  |  F3  |  F4  |  7   |  8   |  9   |  *   |  /   |WheelU| Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |  F5  |  F6  |  F7  |  F8  |  4   |  5   |  6   |  +   |  -   |WheelD| Ent  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |  F9  |  F10 |  F11 |  F12 |  1   |  2   |  3   |  ,   |  .   |  MSU | Click|
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      0      |  Ent |  =   |  MSL |  MSD |  MSR |
* `-----------------------------------------------------------------------------------'
*/
[_FUNCT] = LAYOUT_planck_grid(
   _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_P7, KC_P8, KC_P9, KC_PAST,  KC_PSLS, KC_MS_WH_UP, KC_DEL ,
   _______, KC_F5, KC_F6, KC_F7, KC_F8, KC_P4, KC_P5, KC_P6, KC_PPLS,  KC_PMNS, KC_MS_WH_DOWN, KC_PENT ,
   _______, KC_F9, KC_F10, KC_F11, KC_F12, KC_P1, KC_P2, KC_P3, KC_PCMM,  KC_PDOT, KC_MS_U, KC_MS_BTN1 ,
   _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_P0, KC_P0, KC_PENT, KC_PEQL,  KC_MS_L, KC_MS_D, KC_MS_R
),

/* OBSSTUDIO (TapDancing Toggle)
* ,-----------------------------------------------------------------------------------.
* |      |  S1  |  S2  |  S3  |  S4  |  S5  |  S6  |  S7  |  S8  |  S9  |      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      | Fade |      |      |      |      |      |   ;  |S/S Rec.|
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |Nav U |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |  Play/Pause |      |      |Nav L |Nav D |Nav R |
* `-----------------------------------------------------------------------------------'
*/
[_OBSSTUDIO] = LAYOUT_planck_grid(
   _______, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5), HYPR(KC_6), HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), _______, _______,
   _______, _______, _______, _______, LCAG(KC_F), _______, _______, _______, _______, _______, KC_SCLN, HYPR(KC_ENT),
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, HYPR(KC_UP), _______,
   _______, _______, _______, _______, _______, HYPR(KC_SPC), HYPR(KC_SPC), _______, _______, HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RGHT)
)
	   
};

#define ONE_DOWN_SOUND \
	Q__NOTE(_G7  ),  \
	Q__NOTE(_D7  ),  \
	Q__NOTE(_C7  ),  \
	Q__NOTE(_E7  ),  \
	Q__NOTE(_G6  ),  \
	Q__NOTE(_E6  ),

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float one_up[][2]     = SONG(ONE_UP_SOUND);
  float one_down[][2]     = SONG(ONE_DOWN_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

//Tap Dance Definitions
void dance_1p_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LCMD);
    register_code (KC_BSLS);
  } else {
    register_code (KC_LCMD);
    register_code (KC_LALT);
    register_code (KC_BSLS);
  }
}

void dance_1p_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LCMD);
    unregister_code (KC_BSLS);
  } else {
    unregister_code (KC_LCMD);
    unregister_code (KC_LALT);
    unregister_code (KC_BSLS);
  }
}

void obs_esc_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
	if (!IS_LAYER_ON(_OBSSTUDIO)) {
	    layer_on(_OBSSTUDIO);
		#ifdef AUDIO_ENABLE
		    PLAY_SONG(one_up);
		#endif
	}
    else {
	    layer_off(_OBSSTUDIO);
		#ifdef AUDIO_ENABLE
		    PLAY_SONG(one_down);
		#endif 
    }
  } else {
    register_code (KC_ESC);
  }
}

void obs_esc_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
  } else {
    unregister_code (KC_ESC);
  }
}

void dance_command_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code (KC_RALT);
  } else if (state->count == 3) {
    register_code (KC_RCMD);
	register_code (KC_RALT);
  }
  else {
  	register_code (KC_RCMD);
  }
}

void dance_command_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
      unregister_code (KC_RALT);
    } else if (state->count == 3) {
      unregister_code (KC_RCMD);
  	  unregister_code (KC_RALT);
    }
    else {
      unregister_code (KC_RCMD);
    }
}

//All tap dance functions should go here.
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_1P_KEY] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_1p_finished, dance_1p_reset),
 [TD_CMDALT] = ACTION_TAP_DANCE_DOUBLE(KC_RCMD, KC_RALT),
 [TD_ALTSFT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LSFT),
 [TD_DANCECMD] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_command_finished, dance_command_reset),
 [TD_OBSESC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, obs_esc_finished, obs_esc_reset)
};
