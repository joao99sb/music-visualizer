#include "includes/KeyEvents.h"
KeyEvents::KeyEvents()
{
  this->message_lookup = hashTable::createList<KeyCodeEnum>(10);
  hashTable::insertElement(this->message_lookup, "close window", CLOSE_WINDOW);
  hashTable::insertElement(this->message_lookup, "continue", CONTINUE);
  hashTable::insertElement(this->message_lookup, "switch state", SWITCH_STATE);
}

KeyCodeEnum KeyEvents::getLookupValue(const char *key)
{
  std::optional<KeyCodeEnum> result = hashTable::getValueInList(this->message_lookup, key);
  if (!result.has_value())
  {

    char text[100];
    sprintf(text, "Value:%s not found in lookup", key);
    logger(ERROR, text);
    exit(1);
  }
  return result.value();
}

KeyCodeEnum KeyEvents::musicEvents()
{
  if (IsKeyPressed(KEY_SPACE))
  {

    KeyCodeEnum result = this->getLookupValue("switch state");
    return result;
  }

  // if (IsKeyPressed(KEY_ESCAPE))
  // {
  //   KeyCodeEnum result = this->getLookupValue("close window");
  //   return result;
  // }
  KeyCodeEnum result = this->getLookupValue("continue");
  return result;
}
