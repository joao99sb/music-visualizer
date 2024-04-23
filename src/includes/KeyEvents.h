#pragma once
#include <raylib.h>
#include "./utils/hashTable.h"
#include "./utils/utils.h"

enum KeyCodeEnum
{
  CONTINUE,
  CLOSE_WINDOW,
  SWITCH_STATE
};

class KeyEvents
{
public:
  KeyEvents();
  KeyCodeEnum musicEvents();
  hashTable::List<KeyCodeEnum> *message_lookup;
  KeyCodeEnum getLookupValue(const char *key);
};