#include "highscores.h"

const char initials_letters[] PROGMEM = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,-?!";

void init_highscores() {
  uint16_t address = HIGHSCORE_ADDR;
  if (EEPROM.read(address) != HIGHSCORE_MARKER) {
    EEPROM.write(address, HIGHSCORE_MARKER);
    HighScoreEntry entry;
    address += 1;
    char initial = 'A';
    uint16_t score = 0;
    for (uint8_t i = 0; i < MAX_HIGHSCORES; i++) {
      for (uint8_t j = 0; j < LEN_INITIALS; j++) {
        entry.initials[j] = initial;
      }
      entry.score = score;
      EEPROM.put(address, entry);
      address += sizeof(entry);
      initial += 1;
    }
  }
}

static uint16_t entry_address(uint8_t index, const HighScoreEntry& entry) {
  return HIGHSCORE_ADDR + 1 + sizeof(entry) * index;
}

void get_entry(uint8_t index, HighScoreEntry& entry) {
  EEPROM.get(entry_address(index, entry), entry);
}

void set_entry(uint8_t index, const HighScoreEntry& entry) {
  EEPROM.put(entry_address(index, entry), entry);
}

void insert_entry(const HighScoreEntry& entry) {
  uint8_t index = get_highscore_index(entry.score);
  uint8_t current_index = MAX_HIGHSCORES - 1;
  while (current_index != index) {
    HighScoreEntry prev_entry;
    get_entry(current_index - 1, prev_entry);
    set_entry(current_index, prev_entry);
    current_index--;
  }
  set_entry(current_index, entry);
}

int8_t get_highscore_index(uint16_t score) {
  uint8_t index = -1;
  HighScoreEntry entry;
  for (uint8_t i = 0; i < MAX_HIGHSCORES; i++) {
    get_entry(i, entry);
    if (entry.score < score) {
      index = i;
      break;
    }
  }
  return index;
}

