/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off
enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

enum custom_keycodes {
     CLR_RED = SAFE_RANGE,
     CLR_ORNG,
     CLR_YLW,
     CLR_LIME,
     CLR_TEAL,
     CLR_BLUE,
     CLR_PRPL,
     CLR_MGT,
     CLR_PINK,
     EFF_ONE,
     EFF_TWO,
     NUM_MODE
};

bool numpad;
bool mute;
bool deaf;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_tkl_ansi(
     KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,           KC_SNAP,   KC_SIRI,  RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_INS,    KC_HOME,  KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,    KC_END,   KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_tkl_ansi(
     KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_TRNS,  KC_TRNS,  RGB_TOG,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_BASE] = LAYOUT_tkl_ansi(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_PSCR,   RGB_TOG,  KC_F13,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,    KC_END,   KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(WIN_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_tkl_ansi(
     KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_BRID,  KC_BRIU,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_F14,
     KC_TRNS,  BT_HST1,  BT_HST2,  BT_HST3,  CLR_RED,  CLR_ORNG, CLR_YLW,  CLR_LIME, CLR_TEAL, CLR_BLUE, CLR_PRPL, CLR_MGT,  CLR_PINK, KC_TRNS,  RGB_HUI,  RGB_SAI,  RGB_VAI,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_HUD,  RGB_SAD,  RGB_VAD,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,            EFF_ONE,  EFF_TWO,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            NUM_MODE,           RGB_SPI,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                DB_TOGG,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_RMOD, RGB_SPD,  RGB_MOD)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch(keycode){
          case CLR_RED:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(0, 255, 255);} 
               return false;
          case CLR_ORNG:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(16, 255, 255);} 
               return false;  
          case CLR_YLW:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(40, 255, 255);} 
               return false;
          case CLR_LIME:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(80, 255, 255);} 
               return false;
          case CLR_TEAL:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(128, 255, 255);} 
               return false;
          case CLR_BLUE:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(168, 255, 255);} 
               return false;
          case CLR_PRPL:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(180, 255, 255);} 
               return false;
          case CLR_MGT:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(200, 255, 255);} 
               return false;
          case CLR_PINK:
               if(record->event.pressed){rgb_matrix_sethsv_noeeprom(216, 255, 255);} 
               return false;
          case KC_F13:
               if(record->event.pressed){mute = !mute;}
               return true;
          case KC_F14:
               if(record->event.pressed){deaf = !deaf;}
               return true;     
          case NUM_MODE:
               if(record->event.pressed){numpad = !numpad;}
               return false;
          case KC_UP:
               if(numpad){
                    if(record->event.pressed){register_code(KC_P8);}
                    else {unregister_code(KC_P8);}
                    return false;
               }
               else { return true; }
          case KC_DOWN:
               if(numpad){
                    if(record->event.pressed){register_code(KC_P5);}
                    else {unregister_code(KC_P5);}
                    return false;
               }
               else { return true; }
          case KC_LEFT:
               if(numpad){
                    if(record->event.pressed){register_code(KC_P4);}
                    else {unregister_code(KC_P4);}
                    return false;
               } else { return true; }
          case KC_RGHT:
               if(numpad){
                    if(record->event.pressed){register_code(KC_P6);}
                    else {unregister_code(KC_P6);}
                    return false;
               }
               else { return true; }
          // case EFF_ONE:
          //      if(record->event.pressed){
          //           rgb_matrix_mode(RGB_MATRIX_CUSTOM_blurple_gradient);
          //      }
          //      return false;
          // case EFF_TWO:
          //      if(record->event.pressed){
          //           rgb_matrix_mode(RGB_MATRIX_CUSTOM_half_gradient);
          //      }
          //      return false;
          default:
               return true;
     }
}

bool rgb_matrix_indicators_user(void) {
    uint8_t current_layer = get_highest_layer(layer_state|default_layer_state);
    switch (current_layer) {
        case WIN_BASE:
            // fix never getting here
            if (numpad) { //color arrows white when in numpad mode
                rgb_matrix_set_color(75, 0xff, 0xff, 0xff);
                rgb_matrix_set_color(84, 0xff, 0xff, 0xff);
                rgb_matrix_set_color(85, 0xff, 0xff, 0xff);
                rgb_matrix_set_color(86, 0xff, 0xff, 0xff);
            }
            if(deaf){rgb_matrix_set_color(15, 0x00, 0x00, 0x00);} // white for deaf
            else if(mute) {rgb_matrix_set_color(15, 0xff, 0x00, 0x00);} // red for mute
            break;
        case WIN_FN:
            rgb_matrix_set_color_all(0, 0, 0);
            //F row
            rgb_matrix_set_color(1, 0xff, 0x00, 0xff); // for prev
            rgb_matrix_set_color(2, 0xff, 0x00, 0xff); // for pause
            rgb_matrix_set_color(3, 0xff, 0x00, 0xff); // for next
            rgb_matrix_set_color(4, 0xff, 0x00, 0x00); // for mute
            rgb_matrix_set_color(5, 0x00, 0xff, 0x00); // for sound up
            rgb_matrix_set_color(6, 0x00, 0xff, 0x00); // for sound down
            rgb_matrix_set_color(7, 0xff, 0xff, 0x00); // for brightness up
            rgb_matrix_set_color(8, 0xff, 0xff, 0x00); // for brightness down
            rgb_matrix_set_color(15, 0x58, 0x65, 0xf2); // for discord mute
            // color picker
            rgb_matrix_set_color(17, 0x00, 0x00, 0xff); // for blt1
            rgb_matrix_set_color(18, 0x00, 0x00, 0xff); // for blt2
            rgb_matrix_set_color(19, 0x00, 0x00, 0xff); // for blt3
            rgb_matrix_set_color(20, 0xff, 0x00, 0x00); // for RED
            rgb_matrix_set_color(21, 0xff, 0x60, 0x00); // for ORANGE
            rgb_matrix_set_color(22, 0xff, 0xef, 0x00); // for YELLOW
            rgb_matrix_set_color(23, 0x1f, 0xff, 0x00); // for LIME
            rgb_matrix_set_color(24, 0x00, 0xff, 0xef); // for TEAL
            rgb_matrix_set_color(25, 0x00, 0x0f, 0xff); // for BLUE
            rgb_matrix_set_color(26, 0x39, 0x00, 0xff); // for PURPLE
            rgb_matrix_set_color(27, 0xb0, 0x00, 0xff); // for MAGENTA
            rgb_matrix_set_color(28, 0xff, 0x00, 0xee); // for PINK
            // keyboard settings
            HSV hsv = rgb_matrix_get_hsv();

            hsv.h = hsv.h + RGB_MATRIX_HUE_STEP;
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b); // H up

            hsv.h = hsv.h - (RGB_MATRIX_HUE_STEP * 2);
            rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(47, rgb.r, rgb.g, rgb.b); // H down
            hsv.h = hsv.h + RGB_MATRIX_HUE_STEP;
            
            // saturation up
            if(hsv.s < 239){
                hsv.s = hsv.s + RGB_MATRIX_SAT_STEP;
                rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b); // S up
                hsv.s = hsv.s - RGB_MATRIX_SAT_STEP;
            } else {
                rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b); // S up      
            }
            // saturation down
            hsv.s = hsv.s - RGB_MATRIX_SAT_STEP;
            rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(48, rgb.r, rgb.g, rgb.b); // S down
            hsv.s = hsv.s + RGB_MATRIX_SAT_STEP;
            // value up
            if(hsv.v < 239) {
               hsv.v = hsv.v + RGB_MATRIX_VAL_STEP;
               rgb = hsv_to_rgb(hsv);
               rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b); // V up
               hsv.v = hsv.v - RGB_MATRIX_VAL_STEP;
            } else {
               rgb = hsv_to_rgb(hsv);
               rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b); // V up
            }
            // value down
            hsv.v = hsv.v - RGB_MATRIX_VAL_STEP;
            rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(49, rgb.r, rgb.g, rgb.b); // V down

            rgb_matrix_set_color(74, 0xff, 0xff, 0xff); // num_mode button
            rgb_matrix_set_color(79, 0x0f, 0x55, 0x0f); // for debug

            break;
        default:
            break;
    }
//     if (led_state.caps_lock) {
//         rgb_matrix_set_color(50, 0xff, 0xff, 0xff); // indicate if caps is on
//     }
    return false;
}

void keyboard_post_init_user(void) {
     numpad = false;
     mute = false;
     deaf = false;
}

// void matrix_init_user(void) {
//     #ifdef RGB_MATRIX_CUSTOM_USER
//         rgb_matrix_mode(blurple_grad);
//     #endif
// }