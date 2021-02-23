/* Copyright 2019 e3w2q
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  SEND_00 = SAFE_RANGE,
  SEND_000
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,-------------------------------
   *  |  Esc   F1   F2   F3   F4   F5 
   *  | Hank    1    2    3    4    5 
   *  |  Tab    Q    W    E    R    T 
   *  | Caps    A    S    D    F    G 
   *  | Shft    Z    W    C    V    B 
   *  | Ctrl  GUI  Alt MHEN Spce Spce 
   *  `-------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,-------------------------------
   *  |   F6   F7   F8   F9  F10  Del 
   *  |    6    7    8    9    0   BS 
   *  |    Y    U    I    O    P    \ 
   *  |    H    J    K    L    ; Entr 
   *  |    N    M    , Shft   Up MO(1)
   *  | Spce  HEN  Alt Left Down Rght 
   *  `-------------------------------
   */

  [0] = LAYOUT( /* Base */ 
    RGB_TOG,  KC_A,     KC_B
  ),
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case SEND_00:
//      if (record->event.pressed) {
//        // when keycode SEND_00 is pressed
//        SEND_STRING("00");
//      } else {
//        // when keycode SEND_00 is released
//      }
//      break;
//    case SEND_000:
//      if (record->event.pressed) {
//        // when keycode SEND_000 is pressed
//        //SEND_STRING("000" SS_TAP(X_ENTER));
//        SEND_STRING("000");
//      } else {
//        // when keycode SEND_000 is released
//      }
//      break;
//  }
//  return true;
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_A:
      if (record->event.pressed) {
        for ( ; ; )
        {
//          iota_gfx_task();
          // 60秒間隔でマウスカーソルを上下に動かす。
          register_code(KC_MS_UP);
          unregister_code(KC_MS_UP);
          wait_ms(6000);
          //wait_ms(60000);
          register_code(KC_MS_DOWN);
          unregister_code(KC_MS_DOWN);
        }
      } else {
        // when keycode QMKBEST is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
