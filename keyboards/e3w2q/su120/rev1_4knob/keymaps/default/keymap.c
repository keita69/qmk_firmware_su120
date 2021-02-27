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
   *  ,-------------------------------
   *  |  RGB_TOG,  KC_A,  RGB_MOD
   *  `-------------------------------
   */

  [0] = LAYOUT( /* Base */ 
    RGB_TOG,  KC_A, RGB_MOD
  ),
};

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
