/**
 * In my case, my hashtable needs tobe fast in write
 */

#ifndef H_HASH_TABLE__
#define H_HASH_TABLE__
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int data;
} Node;

typedef struct
{
  Node **data;
  unsigned int len;
  int count;
} List;

// my table will be a list off pointers to nodes
// every insert will recreate the list with one more block
List *createList(int cappacity);

int createHash(const char *chave, unsigned int limit);

Node *createNode(const char *data);

void insertElement(List *list, const char *key, const char *value);
int getValueInList(List *l, const char *key);

#endif