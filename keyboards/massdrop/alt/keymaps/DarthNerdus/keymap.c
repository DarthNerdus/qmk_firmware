#include QMK_KEYBOARD_H
#include "values.h"

// Pull in my tapdance definitions
#include "tapdance.c"

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    JR_1PWD,               //1Password muscle memory
    WOW_C,                 //Tap for Alt+Space, Shift will sends Shift+C
    MB_BRD,                //Toggle broadcasting for MB
    MB_KEY,                //Toggle keymaps for MB
};

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_65_ansi_blocker(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TD(SES),  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, TD(HME), \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_VOLU, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   TD(MUT), \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             TD(ALT), TD(FN),  KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_MAC] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, KC_LALT, KC_LGUI,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [_WOW] = LAYOUT_65_ansi_blocker(
        TD(ESC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [_WOWMB] = LAYOUT_65_ansi_blocker(
        TD(ESC), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, MB_BRD,  \
        _______, _______, _______, _______, KC_F,    KC_T,    _______, _______, _______, _______, _______, _______, _______, _______, MB_KEY,  \
        _______, _______, _______, _______, TD(GA),  _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, WOW_C,   _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [_FUNCTIONS] = LAYOUT_65_ansi_blocker(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, \
        XXXXXXX, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, XXXXXXX, U_T_AUTO,U_T_AGCR,XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, JR_1PWD, XXXXXXX, \
        XXXXXXX, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, MD_BOOT, NK_TOGG, DBG_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_PGUP, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_END   \
    )
};

// Enables color layer passthrough below

#ifdef _______
#undef _______
#define _______ {0, 0, 0}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_BASE] = {
        JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, \
        JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, \
        JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR,          JR_AZUR, JR_AZUR, \
        JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR,          JR_AZUR, JR_AZUR, \
        JR_AZUR, JR_AZUR, JR_AZUR,                            JR_AZUR,                            JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, JR_AZUR, \
        JR_AZUN\
    },
    [_MAC] = {
        TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    \
        TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    \
        TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,             TEAL,    TEAL,    \
        TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    TEAL,             TEAL,    TEAL,    \
        TEAL,    TEAL,    TEAL,                               TEAL,                               TEAL,    TEAL,    TEAL,    TEAL,    TEAL,    \
        TEAL\
    },
    [_WOW] = {
        RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     \
        RED,     RED,     BRED,    RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     \
        RED,     BRED,    BRED,    BRED,    RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,              RED,     RED,     \
        RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,              RED,     RED,     \
        RED,     RED,     RED,                                RED,                                RED,     RED,     RED,     RED,     RED,     \
        _______\
    },
    [_WOWMB] = {
        RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     GOLD,    \
        RED,     RED,     BRED,    RED,     GREEN,   RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,     GOLD,    \
        RED,     BRED,    BRED,    BRED,    GREEN,   RED,     RED,     RED,     RED,     RED,     RED,     RED,              RED,     RED,     \
        RED,     RED,     RED,     GREEN,   RED,     RED,     RED,     RED,     RED,     RED,     RED,     RED,              RED,     RED,     \
        RED,     RED,     RED,                                RED,                                RED,     RED,     RED,     RED,     RED,     \
        _______\
    },
    // Note the above extra line is the underglow coloring.
    [_FUNCTIONS] = {
        _______, CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    _______, _______, \
        _______, CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    _______, CYAN,    CYAN,    _______, CYAN,    CYAN,    CYAN,    GREEN,   _______, \
        _______, CYAN,    CYAN,    CYAN,    CYAN,    CYAN,    _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, CYAN,    _______, _______, _______, BRED,    CYAN,    CYAN,    _______, _______, _______, _______,          CYAN,    _______, \
        _______, _______, _______,                            _______,                            _______, _______, CYAN,    CYAN,    CYAN,    \
        _______\
    }
    /* TEMPLATE
    [_MAC] = {
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, \
        _______\
    },
    */
};

// Reset again
#undef _______
#define _______ KC_TRNS
#endif

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    #ifdef CONSOLE_ENABLE
        debug_enable=true;
        debug_matrix=true;
        debug_keyboard=true;
        debug_mouse=true;
    #endif
};


// Call in Leader Key foundation
LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    
    SEQ_ONE_KEY(KC_LEFT) {
        if (layer_state_is(_MAC)) {
            layer_move(_BASE);
        } else {
            layer_move(_MAC);
        }
    }

    SEQ_ONE_KEY(KC_RGHT) {
      layer_move(_BASE);
    }    
  }
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        int led = i;
        if (led >= 67) {
            led = 67;
        }
        HSV hsv = { 
            .h = pgm_read_byte(&ledmap[layer][led][0]), 
            .s = pgm_read_byte(&ledmap[layer][led][1]), 
            .v = pgm_read_byte(&ledmap[layer][led][2])
        };
        if (hsv.h || hsv.s || hsv.v) {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        } else if (layer != 0) {
            // Only deactivate non-defined key LEDs at layers other than Base.
            // If the values are all false then it's a transparent key and deactivate LED at this layer
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    set_layer_color(get_highest_layer(layer_state));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    #endif 

    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        // Maintain usual muscle member for 1Password
        case JR_1PWD:
            register_code(KC_RCTRL);
            tap_code(KC_BSLS);
            unregister_code(KC_RCTRL);
            return false;
        case WOW_C:
            if (record->event.pressed){
                if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
                    register_code(KC_C);
                } else {
                    register_code(KC_LALT);
                    register_code(KC_SPC);
                }
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_SPC);
                unregister_code(KC_C);
            }
            return false;
        case MB_BRD:
            if (record->event.pressed) {
                register_code(KC_LSHIFT);
                register_code(KC_LALT);
                register_code(KC_R);
            } else {
                unregister_code(KC_LSHIFT);
                unregister_code(KC_LALT);
                unregister_code(KC_R);
            }
            return false;
        case MB_KEY:
            if (record->event.pressed) {
                register_code(KC_LSHIFT);
                register_code(KC_LALT);
                register_code(KC_M);
            } else {
                unregister_code(KC_LSHIFT);
                unregister_code(KC_LALT);
                unregister_code(KC_M);
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
