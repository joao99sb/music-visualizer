#include <string.h>
#include "includes/KeyEvents.h"

List *createLookup()
{
  return createList(10);
}

void configLookup(List *message_lookup)
{
  insertElement(message_lookup, "continue", ME_CONTINUE);
  insertElement(message_lookup, "switch state", ME_SWITCH_STATE);
}

int getLookupValue(List *message_lookup, char key[])
{
  int result = getValueInList(message_lookup, key);

  if (result == NULL)
  {

    char text[100];
    sprintf(text, "Value:%s not found in lookup", key);
    logger(ERROR, text);
    exit(1);
  }

  return result;
}

int musicEvents(List *message_lookup)
{

  int result;
  if (IsKeyPressed(KEY_SPACE))
  {

    result = getLookupValue(message_lookup, "switch state");
    return result;
  }

  result = getLookupValue(message_lookup, "continue");

  return result;
}
