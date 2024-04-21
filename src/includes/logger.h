#pragma once
#include <stdio.h>
#define DEBUG -1
#define ERROR 0
#define INFO 1

void logger(int prefix_code, const char *message);