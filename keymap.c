#include QMK_KEYBOARD_H

enum my_layers {
  BASE_LAYER,
  LSYM_LAYER,
  RSYM_LAYER,
  NUM_LAYER,
  NAV_LAYER,
  FUNC_LAYER,
  CTRL_LAYER,
  SCUT_LAYER
};

enum my_keycodes {
    M_ESCQ = SAFE_RANGE,
    M_ESCW,
    M_ESCV,
    M_DDS,
    M_ALTT,
    M_SCM1,
    M_ETCTLZ
};

enum {
  TD_SPC_TAB
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB)
};

// Stores state of M_ALTT macro - true if we are currently tabbing between
// windows.
static bool m_altt_pressed = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE_LAYER] = LAYOUT_split_3x5_2(
    LSFT_T(KC_Q),   LCTL_T(KC_W),         LALT_T(KC_F),        LGUI_T(KC_P),         KC_B,   KC_J, LGUI_T(KC_L),         LALT_T(KC_U),           LCTL_T(KC_Y),           LSFT_T(KC_BSPC),
    KC_A,           LT(CTRL_LAYER, KC_R), LT(NAV_LAYER, KC_S), LT(RSYM_LAYER, KC_T), KC_G,   KC_M, LT(LSYM_LAYER, KC_N), LT(NUM_LAYER, KC_E),    LT(FUNC_LAYER, KC_I),   KC_O,
    KC_Z,           KC_X,                 KC_C,                KC_D,                 KC_V,   KC_K, KC_H,                 KC_COMM,                KC_DOT,                 OSL(SCUT_LAYER),
    OSM(MOD_LSFT),  TD(TD_SPC_TAB),       KC_ENT,              KC_ESC
  ),

  [LSYM_LAYER] = LAYOUT_split_3x5_2(
    KC_EXLM,        LSFT(KC_2),     LSFT(KC_3),  KC_DLR,   KC_PERC,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    LSFT(KC_SLSH),  LSFT(KC_NUBS),  KC_LBRC,     KC_LCBR,  KC_LPRN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_SLSH,        KC_NUBS,        KC_RBRC,     KC_RCBR,  KC_RPRN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS,     KC_TRNS
  ),

  [RSYM_LAYER] = LAYOUT_split_3x5_2(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_CIRC,  KC_AMPR,        KC_ASTR,        KC_UNDS,  KC_PLUS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_COLN,  LSFT(KC_QUOT),  LSFT(KC_BSLS),  KC_MINS,  KC_EQL,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_SCLN,  KC_QUOT,        KC_BSLS,        KC_GRV,   KC_NO,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [NUM_LAYER] = LAYOUT_split_3x5_2(
    KC_PAST,  KC_1,    KC_2,     KC_3,    KC_PPLS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_PSLS,  KC_4,    KC_5,     KC_6,    KC_PMNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_DOT,   KC_7,    KC_8,     KC_9,    KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_0,     KC_EQL,  KC_TRNS,  KC_TRNS
  ),

  [NAV_LAYER] = LAYOUT_split_3x5_2(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    LCTL(LGUI(KC_LEFT)),  LCTL(KC_TAB),  M_ALTT,   LCTL(LGUI(KC_RGHT)),
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_U,  KC_LEFT,              KC_DOWN,       KC_UP,    KC_RGHT,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_D,  KC_HOME,              KC_PGDN,       KC_PGUP,  KC_END,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [FUNC_LAYER] = LAYOUT_split_3x5_2(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_NO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_F5,    KC_F6,    KC_F7,    KC_F8,   KC_NO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_NO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [CTRL_LAYER] = LAYOUT_split_3x5_2(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSCR,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BRIU,  KC_VOLU,  KC_MNXT,  KC_MPLY,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BRID,  KC_VOLD,  KC_MPRV,  KC_MUTE,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [SCUT_LAYER] = LAYOUT_split_3x5_2(
    M_ESCQ,      M_ESCW,      LCTL(KC_F),  KC_NO,               LCTL(KC_B),  HYPR(KC_J),  KC_NO,             KC_NO,          KC_NO,     KC_DEL,
    HYPR(KC_1),  HYPR(KC_2),  HYPR(KC_3),  LSFT(LCTL(KC_SPC)),  HYPR(KC_4),  HYPR(KC_M),  LSFT(LCTL(KC_1)),  LGUI(KC_SCLN),  M_ETCTLZ,  KC_INS,
    KC_CAPS,     LCTL(KC_X),  LCTL(KC_C),  LSFT(LCTL(KC_C)),    LCTL(KC_V),  HYPR(KC_K),  KC_NO,             KC_NO,          M_DDS,     KC_SLSH,
    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // Stop pressing the alt key once a key other than the alt-tab macro has been
  // pressed.
  if (keycode != M_ALTT && m_altt_pressed) {
    unregister_code(KC_LALT);
    m_altt_pressed = false;
  }

  // Ensure shift is not pressed when the symbol layer is active.
  if (IS_LAYER_ON(LSYM_LAYER) || IS_LAYER_ON(RSYM_LAYER)) {
    del_mods(MOD_MASK_SHIFT);
    del_oneshot_mods(MOD_MASK_SHIFT);
  }

  switch (keycode) {
    case M_ALTT:
      if (record->event.pressed) {
        if (!m_altt_pressed) {
          register_code(KC_LALT);
          m_altt_pressed = true;
        }
        tap_code(KC_TAB);
      }
      break;
    case M_SCM1:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL));
        SEND_STRING(SS_DELAY(100)SS_TAP(X_BTN1));
        SEND_STRING(SS_UP(X_LCTL)SS_UP(X_LSFT));
      }
      break;
    case M_ESCQ:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC)":q!"SS_TAP(X_ENT));
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_ESCW:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC)":wq"SS_TAP(X_ENT));
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_DDS:
      if (record->event.pressed) {
        SEND_STRING("../");
      } else {
        layer_move(BASE_LAYER);
      }
      break;
    case M_ESCV:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESC));
        SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_V)SS_UP(X_LSFT));
      }
      break;
    case M_ETCTLZ:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENT));
        SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_BSLS)SS_UP(X_LSFT));
        SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_Z)SS_UP(X_LCTL));
      }
      break;
  }

  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Return to the base layer if space, enter, home/end or a function key is
    // pressed.
    case TD(TD_SPC_TAB):
    case KC_ENT:
    case KC_PSCR:
    case KC_F1 ... KC_F12:
      if (!record->event.pressed) { layer_move(BASE_LAYER); }
      break;
    // Cancel caps lock if escape is pressed.
    case KC_ESC:
      if (host_keyboard_led_state().caps_lock) { tap_code(KC_CAPS); }
      if (!record->event.pressed) { layer_move(BASE_LAYER); }
      break;
    // Return to the nav layer if symbols in the func layer have been pressed.
    case KC_ASTR:
    case KC_PLUS:
    case KC_MINS:
    case KC_EQL:
    case KC_DOT:
    case KC_SLSH:
      if (!record->event.pressed) {
        if (IS_LAYER_ON(FUNC_LAYER)) {
          layer_move(NAV_LAYER);
        }
      }
      break;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Set the tapping term for the homerow mods.
    case LSFT_T(KC_Q):
    case LCTL_T(KC_W):
    case LALT_T(KC_F):
    case LGUI_T(KC_P):
    case LGUI_T(KC_L):
    case LALT_T(KC_U):
    case LCTL_T(KC_Y):
    case LSFT_T(KC_BSPC):
      return TAPPING_TERM_MODS;
    // Set the tapping term for the homerow layer toggle keys.
    case LT(CTRL_LAYER, KC_R):
    case LT(NAV_LAYER, KC_S):
    case LT(RSYM_LAYER, KC_T):
    case LT(LSYM_LAYER, KC_N):
    case LT(NUM_LAYER, KC_E):
    case LT(FUNC_LAYER, KC_I):
      return TAPPING_TERM_LAYER;
    // Set the tapping term for tap dance keys.
    case TD(TD_SPC_TAB):
      return TAPPING_TERM_TAPDANCE;
    default:
      return TAPPING_TERM;
  }
}
