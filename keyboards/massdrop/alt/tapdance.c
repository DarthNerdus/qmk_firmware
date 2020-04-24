// Struct for tapdance state
typedef struct {
  bool is_press_action;
  int state;
} tap;

// Stages of key presses
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5
};

// Define my personal tapdance names
enum {
    FN = 0,
    HME,
    MUT,
    GA,
    ESC,
    SES,
    ALT
};

//Determine the current tap dance state
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    if (!state->pressed) {
      return DOUBLE_TAP;
    } else {
      return DOUBLE_HOLD;
    }
  } else if (state->count == 3) {
    return TRIPLE_TAP;
  }
  else return 8;
}

//////
// FN TAP DANCING
//////
//Initialize tap structure associated with example tap dance key
static tap fn_tap_state = {
  .is_press_action = true,
  .state = 0
};

void move_to_current_base (void) {
  if (layer_state_is(_MAC)) {
    layer_move(_MAC);
  } else {
    layer_move(_BASE);
  }
}

//Functions that control what our tap dance key does
void fn_finished (qk_tap_dance_state_t *state, void *user_data) {
  fn_tap_state.state = cur_dance(state);
  switch (fn_tap_state.state) {
    case SINGLE_TAP:
      move_to_current_base();
      break;
    case SINGLE_HOLD:
      layer_on(_FUNCTIONS);
      break;
    case DOUBLE_TAP: 
      if (layer_state_is(_WOW)) {
        move_to_current_base();
      } else { 
        //if not already set, then switch the layer on
        layer_on(_WOW);
      }
      break;
  }
}

void fn_reset (qk_tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (fn_tap_state.state==SINGLE_HOLD) {
    layer_off(_FUNCTIONS);
  }
  fn_tap_state.state = 0;
}

//////
// G Assists
//////
//Initialize tap structure associated with example tap dance key
static tap ga_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void ga_finished (qk_tap_dance_state_t *state, void *user_data) {
  ga_tap_state.state = cur_dance(state);
  switch (ga_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_G);
      break;
    case SINGLE_HOLD:
      register_code(KC_LSFT);
      tap_code(KC_G);
      unregister_code(KC_LSFT);
      break;
    default:
      break;
  }
}

void ga_reset (qk_tap_dance_state_t *state, void *user_data) {
  ga_tap_state.state = 0;
}

//////
// Up-case forwards
//////
//Initialize tap structure associated with example tap dance key
static tap uc_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void uc_finished (qk_tap_dance_state_t *state, void *user_data) {
  uc_tap_state.state = cur_dance(state);
  switch (uc_tap_state.state) {
    case SINGLE_TAP:
      register_code(KC_W);
      break;
    case DOUBLE_TAP:
      register_code(KC_W);
      break;
    case SINGLE_HOLD:
      register_code(KC_W);
      break;
    case DOUBLE_HOLD:
      unregister_code(KC_W);
      register_code(KC_LALT);
      register_code(KC_W);
  }
}

void uc_start (qk_tap_dance_state_t *state, void *user_data) {
  // register_code(KC_W);
}

void uc_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_W);
  switch (uc_tap_state.state) {
    case DOUBLE_HOLD:
      unregister_code(KC_LALT);
      break;
    }
  uc_tap_state.state = 0;
}

//////
// SES Slack Escape
//////
//Initialize tap structure associated with example tap dance key
static tap ses_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void ses_finished (qk_tap_dance_state_t *state, void *user_data) {
  ses_tap_state.state = cur_dance(state);
  switch (ses_tap_state.state) {
    case TRIPLE_TAP: 
      register_code(KC_LSFT);
      tap_code(KC_ESC);
      unregister_code(KC_LSFT);
      break;
  }
}

void ses_start (qk_tap_dance_state_t *state, void *user_data) {
  tap_code(KC_DEL);
}

void ses_reset (qk_tap_dance_state_t *state, void *user_data) {
  ses_tap_state.state = 0;
}

//////
// Alt Lead Override
//////
//Initialize tap structure associated with example tap dance key
static tap alt_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void alt_finished (qk_tap_dance_state_t *state, void *user_data) {
  alt_tap_state.state = cur_dance(state);
  switch (alt_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_RALT);
      break;
    case SINGLE_HOLD:
      register_code(KC_RALT);
      break;
    case DOUBLE_HOLD: 
      qk_leader_start();
      break;
  }
}

void alt_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_RALT);
  alt_tap_state.state = 0;
}

// Define my personal tapdance actions
qk_tap_dance_action_t tap_dance_actions[] = {
    [HME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
    [FN] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, fn_finished, fn_reset, 200),
    [MUT] = ACTION_TAP_DANCE_DOUBLE(KC_VOLD, KC_MUTE),
    [GA] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ga_finished, ga_reset, 200),
    [ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
    [SES] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(ses_start, ses_finished, ses_reset, 200),
    [ALT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, alt_finished, alt_reset, 200),
};