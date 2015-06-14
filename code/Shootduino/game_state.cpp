#include <Arduino.h>
#include "game_state.h"
#include "game.h"

extern Game shootduino;

void change_state(GameState new_state) {
  shootduino.state = new_state;
  shootduino.state_changed = shootduino.ticks;
}

