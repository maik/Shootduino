#ifndef __SHOOTER_JOYSTICK__
#define __SHOOTER_JOYSTICK__
#include <Arduino.h>

const uint8_t JOY_BUTTON = 2;
const uint8_t RIGHT_BUTTON = 3;
const uint8_t TOP_BUTTON = 4;
const uint8_t BOTTOM_BUTTON = 5;
const uint8_t LEFT_BUTTON = 6;

struct JoystickState {
  bool left : 1;
  bool right : 1;
  bool up : 1;
  bool down : 1;
  bool joy_button : 1;
  bool top_button : 1;
  bool bottom_button : 1;
  bool left_button : 1;
  bool right_button : 1;
};

extern JoystickState joystick;

static uint16_t resting_pos_x;
static uint16_t resting_pos_y;

void init_joystick_shield();
void update_joystick();
static void init_joystick_shield_button(const uint8_t pin);
#endif

