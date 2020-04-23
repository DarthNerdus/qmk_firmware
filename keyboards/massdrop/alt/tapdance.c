// Struct for tapdance state
typedef struct {
  bool is_press_action;
  int state;
} tap;

//Define a type for as many tap dance states as you need
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3
};

//Declare the functions to be used with your tap dance key(s)

//Function associated with all tap dances
int cur_dance (qk_tap_dance_state_t *state);

//Functions associated with individual tap dances
void ql_finished (qk_tap_dance_state_t *state, void *user_data);
void ql_reset (qk_tap_dance_state_t *state, void *user_data);

// Define my personal tapdance names
enum {
    MAGIC = 0,
    TAPEND,
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
    return DOUBLE_TAP;
  }
  else return 8;
}

//Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
  .is_press_action = true,
  .state = 0
};

//Functions that control what our tap dance key does
void ql_finished (qk_tap_dance_state_t *state, void *user_data) {
  ql_tap_state.state = cur_dance(state);
  switch (ql_tap_state.state) {
    case SINGLE_TAP:
      layer_move(_BASE);  
      break;
    case SINGLE_HOLD:
      layer_on(_FUNCTIONS);
      break;
    case DOUBLE_TAP: 
      //check to see if the layer is already set
      if (layer_state_is(_WOW)) {
        //if already set, then switch it off
        layer_off(_WOW);
      } else { 
        //if not already set, then switch the layer on
        layer_on(_WOW);
      }
      break;
  }
}

void ql_reset (qk_tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (ql_tap_state.state==SINGLE_HOLD) {
    layer_off(_FUNCTIONS);
  }
  ql_tap_state.state = 0;
}

// Define my personal tapdance actions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TAPEND] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
    [MAGIC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275)
};