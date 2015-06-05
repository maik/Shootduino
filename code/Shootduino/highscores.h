#ifndef __HIGHSCORES__
#define __HIGHSCORES__
#include <Arduino.h>
#include <EEPROM.h>

extern const char initials_letters[] PROGMEM;

const uint16_t HIGHSCORE_ADDR = 0;
const uint8_t HIGHSCORE_MARKER = 42;
const uint8_t LEN_INITIALS = 3;
const uint8_t MAX_HIGHSCORES = 3;

struct HighScoreEntry {
  char initials[LEN_INITIALS];
  uint16_t score;
};

void init_highscores();
void get_entry(uint8_t index, HighScoreEntry& entry);
void set_entry(uint8_t index, const HighScoreEntry& entry);
void insert_entry(const HighScoreEntry& entry);
int8_t get_highscore_index(uint16_t score);
#endif

