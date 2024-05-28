#include <stdlib.h>
#include <stdio.h>
#include "../includes/hashTable.h"

List *createList(int capacity)
{
  List *list = (List *)malloc(sizeof(List));
  if (!list)
    return NULL;

  list->data = (Node **)calloc(capacity, sizeof(Node *));
  if (!list->data)
  {
    free(list);
    return NULL;
  }
  list->len = capacity;
  list->count = 0;

  return list;
}

int createHash(const char *key, unsigned int limit)
{
  unsigned long i = 0;
  for (int j = 0; key[j]; j++)
    i += key[j];
  return i % limit;
}

Node *createNode(const char *data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node)
    return NULL;
  node->data = data; // Note: This assumes the data is statically allocated or managed elsewhere
  return node;
}

void insertElement(List *list, const char *key, const char *value)
{
  if (list->count >= list->len)
  {
    printf("error in insert\n");
    return; // Changed from exit(1)
  }
  unsigned int id = createHash(key, list->len);

  Node *new_node = createNode(value);
  if (!new_node)
    return;

  // Handle collision (simple replacement for now)
  if (list->data[id] != NULL)
  {
    free(list->data[id]); // Free existing node if any
  }
  list->data[id] = new_node;
  list->count++;
}

int getValueInList(List *l, const char *key)
{

  int id = createHash(key, l->len);

  if (l->data[id] == NULL)
  {
    return NULL; // Changed from returning ""
  }
  Node *node = l->data[id];

  return node->data;
}
