#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Linux map (3 layers)
#define _BASE_LNX 0
#define _LOW_LNX 1
#define _HI_LNX 2

// MacOS map (3 layers)
#define _BASE_MOS 3
#define _LOW_MOS 4
#define _HI_MOS 5

enum custom_keycodes {
  BASE_LNX = SAFE_RANGE,
  LOW_LNX,
  HI_LNX,
  BASE_MOS,
  LOW_MOS,
  HI_MOS,
};

# define KC_CALT RALT_T(KC_SCLN)

// Linux-specific keys
# define KC_CCTL LCTL_T(KC_ESC) // Ctrl + ESC

// MacOS-specific keys
# define KC_CGUI LGUI_T(KC_ESC)  // Command + ESC
# define KC_CEND LGUI(KC_RGHT) // Command ->
# define KC_CHOM LGUI(KC_LEFT) // Command <-

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE_LNX] = LAYOUT(
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
  //                                KC_LALT, LOW_LNX, KC_SPC,                    KC_ENT,  KC_LGUI, HI_LNX
                                    HI_LNX,  KC_LGUI, KC_ENT,                    KC_SPC,  LOW_LNX, KC_LALT
                        //         └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOW_LNX] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_PIPE, KC_RPRN, KC_LPRN, KC_ASTR, KC_AMPR, KC_CIRC,                            KC_PERC, KC_DLR,  KC_HASH, KC_AT,   KC_EXLM, KC_TILD,
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_NO,   KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_GRV,
     _______, KC_NO,   KC_LPRN, KC_RPRN, KC_PGDN, KC_PGUP,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_NO,   KC_RGHT, KC_UP,   KC_DOWN, KC_LEFT,                            KC_END,  KC_HOME, KC_PGUP, KC_NO,   KC_NO,   _______,
     _______, KC_NO,   KC_LCBR, KC_RCBR, KC_HOME, KC_END,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,          _______, KC_NO,   KC_NO,   KC_PGDN, KC_NO,   KC_NO,   _______,
     _______, KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   BASE_MOS,         _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                                _______, _______,  _______,                  KC_LALT, _______,  KC_NO
                                    KC_NO,   _______,  KC_LALT,                  _______, _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_HI_LNX] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,                              KC_F6,   KC_F5,   KC_F4,   KC_F3,   KC_F2,   KC_F1,
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_DLR,  KC_HASH, KC_ASTR, KC_AMPR, KC_CIRC,                            KC_PERC, KC_RPRN, KC_LPRN, KC_AT,   KC_EXLM, _______,
     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_UNDS, KC_PMNS, KC_PPLS, KC_PEQL, KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_MRWD, KC_MFFD, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_PEQL, KC_RCBR, KC_LCBR, KC_HOME, KC_NO,   _______,
     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_VOLD, KC_VOLU, KC_NO,   KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_NO,            KC_NO,   KC_PPLS, KC_RBRC, KC_LBRC, KC_END,  KC_NO,   _______,
     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_MRWD, KC_MSTP, KC_MPLY, KC_MFFD, KC_NO,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                                _______, KC_NO,   KC_NO,                     KC_NO,   KC_NO,   _______
                                    _______, KC_NO,   KC_NO,                     _______, KC_NO,   _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_BASE_MOS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_BSLS, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_GRV,
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_QUOT, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                               KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_TAB,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_BSPC, KC_CALT, KC_L,    KC_K,    KC_J,    KC_H,                               KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    KC_CCTL,
     KC_CGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_CALT, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // KC_RSFT, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_DEL,           KC_DEL,  KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    KC_LSFT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,           KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                                KC_LALT, LOW_LNX, KC_SPC,                    KC_ENT,  KC_LGUI, HI_LNX
                                    HI_MOS,  KC_LCTL, KC_ENT,                    KC_SPC,  LOW_MOS, KC_LALT
                        //         └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOW_MOS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_PIPE, KC_RPRN, KC_LPRN, KC_ASTR, KC_AMPR, KC_CIRC,                            KC_PERC, KC_DLR,  KC_HASH, KC_AT,   KC_EXLM, KC_TILD,
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    _______,
     _______, KC_NO,   KC_LPRN, KC_RPRN, KC_PGDN, KC_PGUP,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_NO,   KC_RGHT, KC_UP,   KC_DOWN, KC_LEFT,                            KC_END,  KC_HOME, KC_PGUP, KC_NO,   KC_NO,   _______,
     _______, KC_NO,   KC_LCBR, KC_RCBR, KC_CHOM, KC_CEND,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,          _______, KC_NO,   KC_NO,   KC_PGDN, KC_NO,   KC_NO,   _______,
     _______, KC_NO,   KC_LBRC, KC_RBRC, KC_NO,   KC_NO,   BASE_LNX,         _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                                _______, _______,  _______,                  KC_LALT, _______,  KC_NO
                                    KC_NO,   _______,  KC_LALT,                  _______, _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_HI_MOS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  // KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,                              KC_F6,   KC_F5,   KC_F4,   KC_F3,   KC_F2,   KC_F1,
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_DLR,  KC_HASH, KC_ASTR, KC_AMPR, KC_CIRC,                            KC_PERC, KC_RPRN, KC_LPRN, KC_AT,   KC_EXLM, _______,
     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_UNDS, KC_PMNS, KC_PPLS, KC_PEQL, KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_MRWD, KC_MFFD, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_PEQL, KC_RCBR, KC_LCBR, KC_HOME, KC_NO,   _______,
     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_VOLD, KC_VOLU, KC_NO,   KC_NO,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  // _______, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_NO,            KC_NO,   KC_PPLS, KC_RBRC, KC_LBRC, KC_END,  KC_NO,   _______,
     _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_MRWD, KC_MSTP, KC_MPLY, KC_MFFD, KC_NO,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                                _______, KC_NO,   KC_NO,                     KC_NO,   KC_NO,   _______
                                    _______, KC_NO,   KC_NO,                     _______, KC_NO,   _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE_LNX:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE_LNX);
      }
      return false;
    case LOW_LNX:
      if (record->event.pressed) {
        layer_on(_LOW_LNX);
      } else {
        layer_off(_LOW_LNX);
      }
      return false;
    case HI_LNX:
      if (record->event.pressed) {
        layer_on(_HI_LNX);
      } else {
        layer_off(_HI_LNX);
      }
      return false;
    case BASE_MOS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE_MOS);
      }
      return false;
    case LOW_MOS:
      if (record->event.pressed) {
        layer_on(_LOW_MOS);
      } else {
        layer_off(_LOW_MOS);
      }
      return false;
    case HI_MOS:
      if (record->event.pressed) {
        layer_on(_HI_MOS);
      } else {
        layer_off(_HI_MOS);
      }
      return false;
  }
  return true;
}
