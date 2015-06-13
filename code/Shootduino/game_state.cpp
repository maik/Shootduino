#include <Arduino.h>
#include "game_state.h"

extern uint32_t ticks;
extern uint32_t state_changed;
extern GameState state;

void change_state(GameState new_state) {
  state = new_state;
  state_changed = ticks;
}

