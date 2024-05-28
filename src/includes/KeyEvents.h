#pragma once
#include <raylib.h>
#include "./hashTable.h"
#include "./utils.h"

#define ME_CONTINUE 1
#define ME_SWITCH_STATE 2

List *createLookup();
int musicEvents(List *message_lookup);
void configLookup(List *message_lookup);
int getLookupValue(List *message_lookup, char key[]);