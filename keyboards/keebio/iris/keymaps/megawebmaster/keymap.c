#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

# define KC_CALT RALT_T(KC_SCLN)
# define KC_CCTL LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_BSLS, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_GRV,
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_QUOT, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                               KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_TAB,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_BSPC, KC_CALT, KC_L,    KC_K,    KC_J,    KC_H,                               KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    KC_CCTL,
     KC_CCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_CALT, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_RSFT, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_DEL,           KC_DEL,  KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    KC_LSFT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,           KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                                KC_LALT, LOWER,   KC_SPC,                    KC_ENT,  KC_LGUI, RAISE
                                    RAISE,   KC_LGUI, KC_ENT,                    KC_SPC,  LOWER,   KC_LALT
                        //         └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_PIPE, KC_RPRN, KC_LPRN, KC_ASTR, KC_AMPR, KC_CIRC,                            KC_PERC, KC_DLR,  KC_HASH, KC_AT,   KC_EXLM, KC_TILD,
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_NO,   KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_GRV,
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_NO,   KC_RGHT, KC_UP,   KC_DOWN, KC_LEFT,                            KC_END,  KC_HOME, KC_PGUP, KC_NO,   KC_NO,   _______,
     _______, KC_NO,   KC_NO,   KC_PGUP, KC_HOME, KC_END,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,          _______, KC_NO,   KC_NO,   KC_PGDN, KC_NO,   KC_NO,   _______,
     _______, KC_NO,   KC_NO,   KC_PGDN, KC_NO,   KC_NO,   _______,          _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                                _______, _______,  _______,                  KC_LALT, _______,  KC_NO
                                    KC_NO,   _______,  KC_LALT,                  _______, _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,                              KC_F6,   KC_F5,   KC_F4,   KC_F3,   KC_F2,   KC_F1,
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_DLR,  KC_HASH, KC_ASTR, KC_AMPR, KC_CIRC,                            KC_PERC, KC_RPRN, KC_LPRN, KC_AT,   KC_EXLM, _______,
     _______, KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_NO,                              KC_UNDS, KC_PMNS, KC_PPLS, KC_NO,   KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_MRWD, KC_MFFD, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_PEQL, KC_RCBR, KC_LCBR, KC_HOME, KC_NO,   _______,
     _______, KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_NO,                              KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_NO,            KC_NO,   KC_PPLS, KC_RBRC, KC_LBRC, KC_END,  KC_NO,   _______,
     _______, KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_MSTP, KC_MPLY, KC_NO,   KC_NO,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                                _______, KC_NO,   KC_NO,                     KC_NO,   KC_NO,   _______
                                    _______, KC_NO,   KC_NO,                     _______, KC_NO,   _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
  }
  return true;
}
