#include "joystick.h"

JoystickState joystick;

void init_joystick() {
#ifdef JOYSTICK_SHIELD
  init_joystick_button(TOP_BUTTON);
  init_joystick_button(BOTTOM_BUTTON);
#endif
  init_joystick_button(JOY_BUTTON);
  init_joystick_button(LEFT_BUTTON);
  init_joystick_button(RIGHT_BUTTON);
  for (uint8_t i = 0; i < 10; i++) {
    resting_pos_x = analogRead(A0);
    resting_pos_y = analogRead(A1);
  }
}

void update_joystick() {
  uint16_t x = analogRead(A0);
  uint16_t y = analogRead(A1);
  joystick.left = x < resting_pos_x - 1;
  joystick.right = x > resting_pos_x + 1;
#ifdef JOYSTICK_SHIELD
  joystick.up = y > resting_pos_y + 1;
  joystick.down = y < resting_pos_y - 1;
  joystick.top_button = digitalRead(TOP_BUTTON) == 0;
  joystick.bottom_button = digitalRead(BOTTOM_BUTTON) == 0;
#else
  joystick.up = y < resting_pos_y - 1;
  joystick.down = y > resting_pos_y + 1;
#endif
  joystick.joy_button = digitalRead(JOY_BUTTON) == 0;
  joystick.left_button = digitalRead(LEFT_BUTTON) == 0;
  joystick.right_button = digitalRead(RIGHT_BUTTON) == 0;
}

static void init_joystick_button(const uint8_t pin) {
  pinMode(pin, INPUT_PULLUP);
}

